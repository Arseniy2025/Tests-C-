using WebApplication3.Models;

namespace WebApplication3.Services
{
    public class MockActivityService : IActivityService
    {
        public Task<List<UserActivity>> GetRecentActivitiesAsync(int userId, int count = 5)
        {
            var data = new List<UserActivity>
        {
            new("Login", DateTime.UtcNow.AddMinutes(-10), "IP: 192.168.1.1"),
            new("Document Edited", DateTime.UtcNow.AddHours(-1), "File: report.docx"),
            new("Settings Updated", DateTime.UtcNow.AddHours(-2), "Theme: Dark"),
            new("Password Changed", DateTime.UtcNow.AddHours(-5), "From profile page"),
            new("Logout", DateTime.UtcNow.AddHours(-6), "Session ended")
        };

            return Task.FromResult(data.Take(count).ToList());
        }
    }
}
