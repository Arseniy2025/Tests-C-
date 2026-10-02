using Microsoft.AspNetCore.Mvc;
using System.Diagnostics;
using WebApplication1.Models;

namespace WebApplication1.Controllers
{
    public class HomeController : Controller
    {
        public IActionResult Index()
        {
            var input = new List<string>
            {
                "hello world",
                "  ",
                "2024-12-31 23:59",
                "apple",
                "ab",
                "orange",
                "water"
            };

            var processed = FilterAndFormat(input);
            return View(processed);
        }

        public IActionResult Privacy()
        {
            return View();
        }

        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        public IActionResult Error()
        {
            return View(new ErrorViewModel
            {
                RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier
            });
        }

        private List<string> FilterAndFormat(List<string> source, int minLength = 3)
        {
            if (source == null || source.Count == 0)
                return new List<string>();

            var result = new List<string>();

            foreach (var item in source)
            {
                if (string.IsNullOrWhiteSpace(item))
                    continue;

                var trimmed = item.Trim();

                if (DateTime.TryParse(trimmed, out var date))
                {
                    result.Add(date.ToString("dd.MM.yyyy HH:mm"));
                }
                else if (trimmed.Length >= minLength)
                {
                    result.Add(trimmed.ToUpperInvariant());
                }
            }

            return result;
        }
    }
}