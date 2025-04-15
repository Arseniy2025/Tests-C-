public class Pizza
{
    public string Dough { get; set; }
    public string Sauce { get; set; }
    public List<string> Topping { get; set; } = new List<string>();

    public void Display()
    {
        Console.WriteLine($"Пицца с тестом: {Dough}");
        Console.WriteLine($"Соус: {Sauce}");
        Console.WriteLine("Начинка: " + string.Join(", ", Topping));
        Console.WriteLine();
    }
}

public interface IPizzaBuilder
{
    void SetDough();
    void SetSauce();
    void SetTopping();
    Pizza GetPizza();
}

public class MargheritaPizzaBuilder : IPizzaBuilder
{
    private Pizza pizza = new Pizza();

    public void SetDough()
    {
        pizza.Dough = "тонкое";
    }

    public void SetSauce()
    {
        pizza.Sauce = "томатный";
    }

    public void SetTopping()
    {
        pizza.Topping.Add("моцарелла");
        pizza.Topping.Add("помидоры");
        pizza.Topping.Add("базилик");
    }

    public Pizza GetPizza()
    {
        return pizza;
    }
}

public class PepperoniPizzaBuilder : IPizzaBuilder
{
    private Pizza pizza = new Pizza();

    public void SetDough()
    {
        pizza.Dough = "толстое";
    }

    public void SetSauce()
    {
        pizza.Sauce = "острый томатный";
    }

    public void SetTopping()
    {
        pizza.Topping.Add("пепперони");
        pizza.Topping.Add("моцарелла");
        pizza.Topping.Add("перец чили");
    }

    public Pizza GetPizza()
    {
        return pizza;
    }
}

public class PizzaDirector
{
    private IPizzaBuilder _pizzaBuilder;

    public PizzaDirector(IPizzaBuilder _pizzaBuilder)
    {
        this._pizzaBuilder = _pizzaBuilder;
    }

    public void MakePizza()
    {
        _pizzaBuilder.SetDough();
        _pizzaBuilder.SetSauce();
        _pizzaBuilder.SetTopping();
    }

    public Pizza GetPizza()
    {
        return _pizzaBuilder.GetPizza();
    }
}

class Program
{
    static void Main(string[] args)
    {
        MargheritaPizzaBuilder margheritaBuilder = new MargheritaPizzaBuilder();
        var director = new PizzaDirector(margheritaBuilder);

        director.MakePizza();
        var margherita = director.GetPizza();
        Console.WriteLine("Маргарита:");
        margherita.Display();

        PepperoniPizzaBuilder pepperoniBuilder = new PepperoniPizzaBuilder();
        director = new PizzaDirector(pepperoniBuilder);

        director.MakePizza();
        var pepperoni = director.GetPizza();
        Console.WriteLine("Пепперони:");
        pepperoni.Display();
    }
}
