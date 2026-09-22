using WebApplication3.Models;

namespace WebApplication3.Services
{
    public interface IActivityService
    {
        Task<List<UserActivity>> GetRecentActivitiesAsync(int userId, int count = 5);
    }
}
