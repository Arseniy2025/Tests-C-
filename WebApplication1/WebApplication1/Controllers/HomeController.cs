using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;
using WebApplication1.Models;
using WebApplication1.Services;

namespace WebApplication1.Controllers
{
    public class HomeController : Controller
    {
        public IActionResult Index()
        {
            var userId = HttpContext.Session.GetInt32("UserId");
            ViewBag.IsAuth = userId != null;

            if (userId != null)
            {
                var user = DataStore.Users.First(u => u.Id == userId);
                ViewBag.UserName = user.Name;
                ViewBag.Wallet = user.Wallet;
                ViewBag.CartCount = GetCart().Sum(i => i.Quantity);
            }

            return View(DataStore.Products);
        }

        // Страница товаров (пример)
        [HttpGet]
        public IActionResult Login() => View();

        [HttpPost]
        public IActionResult Login(string login, string password)
        {
            var user = DataStore.Users.FirstOrDefault(u => u.Login == login && u.Password == password);
            if (user == null)
            {
                ViewBag.Error = "Неверный логин или пароль";
                return View();
            }

            HttpContext.Session.SetInt32("UserId", user.Id);
            return RedirectToAction("Index");
        }

        public IActionResult Logout()
        {
            HttpContext.Session.Clear();
            return RedirectToAction("Index");
        }

        // Корзина (страница)
        public IActionResult Cart()
        {
            if (HttpContext.Session.GetInt32("UserId") == null)
                return RedirectToAction("Login");

            var cart = GetCart();
            ViewBag.Total = cart.Sum(i => i.Price * i.Quantity);
            return View(cart);
        }

        // Добавить в корзину
        [HttpPost]
        public IActionResult AddToCart(int productId)
        {
            if (HttpContext.Session.GetInt32("UserId") == null)
                return RedirectToAction("Login");

            var product = DataStore.Products.First(p => p.Id == productId);
            var cart = GetCart();
            var item = cart.FirstOrDefault(i => i.ProductId == productId);

            if (item == null)
                cart.Add(new CartItem
                {
                    ProductId = product.Id,
                    Name = product.Name,
                    Price = product.Price,
                    Quantity = 1
                });
            else
                item.Quantity++;

            SaveCart(cart);
            return RedirectToAction("Index");
        }

        private List<CartItem> GetCart()
        {
            var json = HttpContext.Session.GetString("Cart");
            return json == null ? new List<CartItem>()
                : System.Text.Json.JsonSerializer.Deserialize<List<CartItem>>(json)!;
        }

        private void SaveCart(List<CartItem> cart)
        {
            HttpContext.Session.SetString("Cart",
                System.Text.Json.JsonSerializer.Serialize(cart));
        }
    }
}
