
public abstract class OrderProcessor
{
    public void ProcessOrder()
    {
        CheckProductAvailability();
        ApplyDiscount();
        CreateOrder();
        NotifyCustomer();
    }

    private void CheckProductAvailability()
    {
        Console.WriteLine("Проверка наличия товара на складе...");
        Console.WriteLine("Товар доступен.");
    }

    protected abstract void ApplyDiscount();
    protected abstract void CreateOrder();

    private void NotifyCustomer()
    {
        Console.WriteLine("Отправка уведомления клиенту по email...");
        Console.WriteLine("Клиент уведомлен.");
    }
}

public class RegularOrderProcessor : OrderProcessor
{
    protected override void ApplyDiscount() => Console.WriteLine("Применение стандартной скидки 5%...");
    protected override void CreateOrder() => Console.WriteLine("Создание обычного заказа...");
    
}

public class VipOrderProcessor : OrderProcessor
{
    protected override void ApplyDiscount() => Console.WriteLine("Применение VIP скидки 15%...");
        
    

    protected override void CreateOrder() => Console.WriteLine("Создание VIP заказа с приоритетной обработкой...");
       
    
}

public class WholesaleOrderProcessor : OrderProcessor
{
    protected override void ApplyDiscount() => Console.WriteLine("Применение оптовой скидки 25%...");
        
    

    protected override void CreateOrder() => Console.WriteLine("Создание оптового заказа с особыми условиями...");
       
    
}

internal class Program
{
    private static void Main(string[] args)
    {
        Console.WriteLine("Обработка обычного заказа:");
        OrderProcessor regularOrder = new RegularOrderProcessor();
        regularOrder.ProcessOrder();

        Console.WriteLine("\nОбработка VIP заказа:");
        OrderProcessor vipOrder = new VipOrderProcessor();
        vipOrder.ProcessOrder();

        Console.WriteLine("\nОбработка оптового заказа:");
        OrderProcessor wholesaleOrder = new WholesaleOrderProcessor();
        wholesaleOrder.ProcessOrder();
    }
}
