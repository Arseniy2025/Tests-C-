using Microsoft.Extensions.Caching.Memory;
using System.Text.Json;
using static WebApplication2.Models.Models;

namespace WebApplication2.Models
{
    public class ShopService
    {
        private readonly IMemoryCache _cache;
        private readonly ILogger<ShopService> _log;
        private readonly IHttpContextAccessor _ctx;
        private readonly List<Product> _products;

        public ShopService(IMemoryCache cache, ILogger<ShopService> log, IHttpContextAccessor ctx)
        {
            _cache = cache;
            _log = log;
            _ctx = ctx;


            _products = new List<Product>
            {
                new(1, "Наушники",   2990m, "Электроника", "/images/1.jpg"),
                new(2, "Батарейки", 4500m, "Электроника", "/images/2.jpg"),
                new(3, "Клавиатура", 890m, "Электроника", "/images/3.jpg"),
                new(4, "Монитор", 750m, "Электроника", "/images/4.jpg"),
                new(5, "Мышка", 1200m, "Электроника", "/images/5.jpg"),
                new(6, "Телефон", 3500m, "Электроника", "/images/6.jpg"),
            };
        }


        public IReadOnlyList<Product> GetProducts(string? category, decimal? minPrice, decimal? maxPrice) =>
     _cache.GetOrCreate($"p_{category ?? "all"}_{minPrice}_{maxPrice}", e =>
     {
         e.AbsoluteExpirationRelativeToNow = TimeSpan.FromMinutes(5);
         _log.LogInformation("Загрузка каталога: cat={Cat}, min={Min}, max={Max}",
             category ?? "all", minPrice, maxPrice);

         var query = _products.AsEnumerable();

         if (!string.IsNullOrEmpty(category))
             query = query.Where(p => p.Category == category);

         if (minPrice.HasValue)
             query = query.Where(p => p.Price >= minPrice.Value);

         if (maxPrice.HasValue)
             query = query.Where(p => p.Price <= maxPrice.Value);

         return query.ToList();
     })!;

        public Product? GetProduct(int id) => _products.FirstOrDefault(p => p.Id == id);

       
        private ISession Session => _ctx.HttpContext!.Session;

        public List<CartItem> GetCart()
        {
            var raw = Session.GetString("cart");
            return raw is null ? new() : JsonSerializer.Deserialize<List<CartItem>>(raw)!;
        }

        private void SaveCart(List<CartItem> cart) =>
            Session.SetString("cart", JsonSerializer.Serialize(cart));

        public List<CartItem> AddToCart(int productId)
        {
            var p = GetProduct(productId);
            if (p is null) return GetCart();

            var cart = GetCart();
            var item = cart.FirstOrDefault(c => c.ProductId == productId);
            if (item is null)
                cart.Add(new CartItem(p.Id, p.Name, p.Price, 1));
            else
                cart[cart.IndexOf(item)] = item with { Quantity = item.Quantity + 1 };

            SaveCart(cart);
            _log.LogInformation("В корзину: товар {Id} '{Name}'", productId, p.Name);
            return cart;
        }

        public List<CartItem> RemoveFromCart(int productId)
        {
            var cart = GetCart();
            cart.RemoveAll(c => c.ProductId == productId);
            SaveCart(cart);
            _log.LogInformation("Из корзины: товар {Id}", productId);
            return cart;
        }
    }
}
