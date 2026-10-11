using Microsoft.AspNetCore.Mvc;
using WebApplication2.Models;
using static WebApplication2.Models.Models;

namespace WebApplication2.Controllers
{
    [ApiController]
    [Route("api")]
    public class ApiController : ControllerBase
    {
        private readonly ShopService _shop;
        private readonly ILogger<ApiController> _log;

        public ApiController(ShopService shop, ILogger<ApiController> log)
        {
            _shop = shop;
            _log = log;
        }

        [HttpGet("products")]
        public IActionResult Products(
            [FromQuery] string? category,
            [FromQuery] decimal? min,
            [FromQuery] decimal? max)
            {
            return Ok(_shop.GetProducts(category, min, max));
         }

        [HttpGet("cart")]
        public IActionResult Cart() => Ok(Format(_shop.GetCart()));

        [HttpPost("cart/add/{id:int}")]
        [ValidateAntiForgeryToken]
        public IActionResult Add(int id) => Ok(Format(_shop.AddToCart(id)));

        [HttpDelete("cart/remove/{id:int}")]
        [ValidateAntiForgeryToken]
        public IActionResult Remove(int id) => Ok(Format(_shop.RemoveFromCart(id)));

        private static object Format(List<CartItem> items) => new
        {
            items,
            count = items.Sum(i => i.Quantity),
            total = items.Sum(i => i.Price * i.Quantity)
        };
    }
}
