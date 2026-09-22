using Microsoft.AspNetCore.Mvc;
using WebApplication3.Services;

namespace WebApplication3.ViewComponents
{
    public class RecentActivityViewComponent : ViewComponent
    {
        private readonly IActivityService _activityService;

        public RecentActivityViewComponent(IActivityService activityService)
        {
            _activityService = activityService;
        }

        public async Task<IViewComponentResult> InvokeAsync(int userId = 42, int count = 5)
        {
            var activities = await _activityService.GetRecentActivitiesAsync(userId, count);
            return View("Default", activities);
        }
    }
}
