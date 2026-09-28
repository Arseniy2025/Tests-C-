using WebApplication1.Models;

namespace WebApplication1.Services
{
    public static class DataStore
    {
        public static List<User> Users = new()
        {
            new User { Id = 1, Login = "user", Password = "123", Name = "Дима", Wallet = 1500 }
        };

        public static List<Product> Products = new()
        {
            new Product { Id = 1, Name = "Ноутбук", Price = 50000 },
            new Product { Id = 2, Name = "Мышь", Price = 1500 },
            new Product { Id = 3, Name = "Клавиатура", Price = 3000 },
            new Product { Id = 4, Name = "Монитор", Price = 20000 }
        };
    }
}

