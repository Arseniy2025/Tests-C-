using Microsoft.AspNetCore.Mvc.ModelBinding;
using Microsoft.AspNetCore.Mvc.Rendering;
using Microsoft.AspNetCore.Mvc.ViewFeatures;
using Microsoft.AspNetCore.Razor.TagHelpers;

namespace WebApplication2.TagHelpers
{
    [HtmlTargetElement("my-input", Attributes = "asp-for")]
    public class InputTagHelper : TagHelper
    {
        [HtmlAttributeName("asp-for")]
        public ModelExpression For { get; set; } = default!;

        [ViewContext]
        [HtmlAttributeNotBound]
        public ViewContext ViewContext { get; set; } = default!;

        public override void Process(TagHelperContext context, TagHelperOutput output)
        {
            output.TagName = null;

            var name = For.Name;
            var value = For.Model?.ToString() ?? "";
            var label = For.Metadata.DisplayName ?? name;

            var entry = ViewContext.ModelState[name];
            var error = entry?.Errors.FirstOrDefault()?.ErrorMessage;

            var css = "form-control";
            if (error != null) css += " is-invalid";
            else if (entry?.ValidationState == ModelValidationState.Valid) css += " is-valid";

            var html = $@"
<div class=""mb-3"">
    <label for=""{name}"" class=""form-label"">{label}</label>
    <input type=""text"" id=""{name}"" name=""{name}"" value=""{value}"" class=""{css}"" />
    {(error != null ? $"<div class=\"invalid-feedback\">{error}</div>" : "")}
</div>";

            output.Content.SetHtmlContent(html);
        }
    }
}

