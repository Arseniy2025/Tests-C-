using System;
using System.Text.RegularExpressions;
using System.IO;
using System.Linq;

public class Program
{
    static void Main(string[] args)
    {
        string filePath = "C:\\Users\\Арсений\\Desktop\\Задание\\emails.txt";
        string fileContent = File.ReadAllText(filePath);
        Console.WriteLine("Содержимое файла:");
        Console.WriteLine(fileContent);

        string pattern = @"[^|]+mail\.ru";
        var matches = Regex.Matches(fileContent, pattern)
                          .Cast<Match>()
                          .Select(m => m.Value.Trim()) 
                          .ToList();

        Console.WriteLine("\nНайденные email адреса:");
        foreach (var match in matches)
        {
            Console.WriteLine(match);
        }
    }
}
