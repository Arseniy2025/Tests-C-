public interface ITrafficLight
{
    void Handle(TrafficLight trafficLight);
    void Notify();
}

public class RedLight : ITrafficLight
{
    public void Handle(TrafficLight trafficLight)
    {
        Console.WriteLine("Красный свет - Стоять!");
        Thread.Sleep(5000); 
        trafficLight.SetState(new YellowLight());
    }

    public void Notify()
    {
        Console.WriteLine("Красный! Водители - стойте! Пешеходы - приготовьтесь!");
    }
}

public class YellowLight : ITrafficLight
{
    public void Handle(TrafficLight trafficLight)
    {
        Console.WriteLine("Жёлтый свет - Приготовиться!");
        Thread.Sleep(2000);
        trafficLight.SetState(new GreenLight());
    }

    public void Notify()
    {
        Console.WriteLine("Жёлтый! Водители - приготовьтесь! Пешеходы - ждите!");
    }
}

public class GreenLight : ITrafficLight
{
    public void Handle(TrafficLight trafficLight)
    {
        Console.WriteLine("Зелёный свет - Идти!");
        Thread.Sleep(10000); 
        trafficLight.SetState(new RedLight());
    }

    public void Notify()
    {
        Console.WriteLine("Зелёный! Водители - можно ехать! Пешеходы - переходите!");
    }
}


public class TrafficLight
{
    private ITrafficLight _state;

    public TrafficLight(ITrafficLight state)
    {
        this.SetState(state);
    }

    public void SetState(ITrafficLight state)
    {
        _state = state;
        _state.Notify();
    }

    public void Run()
    {
        while (true)
        {
            _state.Handle(this);
        }
    }
}

class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("Программа управления светофором");
        var trafficLight = new TrafficLight(new RedLight());
        trafficLight.Run();
    }
}

