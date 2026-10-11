namespace WebApplication2.Models
{
    public class Models
    {
        public record Product(int Id, string Name, decimal Price, string Category, string Image);
        public record CartItem(int ProductId, string Name, decimal Price, int Quantity);
    }
}
