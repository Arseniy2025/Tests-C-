public class Pizza
{
    public string Dough { get; set; }
    public string Sauce { get; set; }
    public List<string> Toppings { get; set; } = new List<string>();

    public void Display()
    {
        Console.WriteLine($"Пицца с тестом: {Dough}");
        Console.WriteLine($"Соус: {Sauce}");
        Console.WriteLine("Начинка: " + string.Join(", ", Toppings));
        Console.WriteLine();
    }
}

public interface IPizzaBuilder
{
    void SetDough(string type);
    void SetSauce(string type);
    void AddTopping(string topping);
    Pizza GetPizza();
}

public class PizzaBuilder : IPizzaBuilder
{
    private Pizza _pizza;

    public PizzaBuilder()
    {
        Reset();
    }

    public void Reset()
    {
        _pizza = new Pizza();
    }

    public void SetDough(string type)
    {
        _pizza.Dough = type;
    }

    public void SetSauce(string type)
    {
        _pizza.Sauce = type;
    }

    public void AddTopping(string topping)
    {
        _pizza.Toppings.Add(topping);
    }

    public Pizza GetPizza()
    {
        Pizza result = _pizza;
        Reset();
        return result;
    }
}

public class PizzaDirector
{
    private IPizzaBuilder _builder;

    public PizzaDirector(IPizzaBuilder builder)
    {
        _builder = builder;
    }

    public void MakeMargherita()
    {
        _builder.SetDough("тонкое");
        _builder.SetSauce("томатный");
        _builder.AddTopping("моцарелла");
        _builder.AddTopping("помидоры");
        _builder.AddTopping("базилик");
    }

    public void MakePepperoni()
    {
        _builder.SetDough("толстое");
        _builder.SetSauce("острый томатный");
        _builder.AddTopping("пепперони");
        _builder.AddTopping("моцарелла");
        _builder.AddTopping("перец чили");
    }
}

public interface ILegacyPizzaMaker
{
    void PrepareDough(string type);
    void AddSauce(string type);
    void AddIngredients(string[] ingredients);
    object GetPizza();
}

public class PizzaAdapter : IPizzaBuilder
{
    private readonly ILegacyPizzaMaker _legacyMaker;

    public PizzaAdapter(ILegacyPizzaMaker legacyMaker)
    {
        _legacyMaker = legacyMaker;
    }

    public void SetDough(string type)
    {
        _legacyMaker.PrepareDough(type);
    }

    public void SetSauce(string type)
    {
        _legacyMaker.AddSauce(type);
    }

    public void AddTopping(string topping)
    {
        _legacyMaker.AddIngredients(new[] { topping });
    }

    public Pizza GetPizza()
    {
       
        var legacyPizza = _legacyMaker.GetPizza();
        
        return new Pizza(); 
    }
}

public class PizzaOven : ILegacyPizzaMaker
{
    public void PrepareDough(string type)
    {
        Console.WriteLine($"Готовим тесто: {type}");
    }

    public void AddSauce(string type)
    {
        Console.WriteLine($"Добавляем соус: {type}");
    }

    public void AddIngredients(string[] ingredients)
    {
        Console.WriteLine($"Добавляем ингредиенты: {string.Join(", ", ingredients)}");
    }

    public object GetPizza()
    {
        Console.WriteLine("Достаем пиццу из печи");
        return new object(); 
    }
}

class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("Строитель напрямую:");
        var builder = new PizzaBuilder();
        builder.SetDough("тонкое");
        builder.SetSauce("сливочный");
        builder.AddTopping("грибы");
        builder.AddTopping("лук");
        var customPizza = builder.GetPizza();
        customPizza.Display();

        Console.WriteLine("Использование директора:");
        var director = new PizzaDirector(builder);
        director.MakeMargherita();
        var margherita = builder.GetPizza();
        margherita.Display();

        director.MakePepperoni();
        var pepperoni = builder.GetPizza();
        pepperoni.Display();

        Console.WriteLine("Использование адаптера:");
        var Oven = new PizzaOven();
        var adapter = new PizzaAdapter(Oven);
        adapter.SetDough("толстое");
        adapter.SetSauce("чесночный");
        adapter.AddTopping("бекон");
        var adaptedPizza = adapter.GetPizza();
        adaptedPizza.Display();
    }
}
