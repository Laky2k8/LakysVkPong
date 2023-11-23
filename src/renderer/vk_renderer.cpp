#include <vulkan/vulkan.h>

struct VkContext
{
	VkInstance instance;
};

bool vk_initRenderer(VkContext* context)
{
	VkApplicationInfo appInfo = {};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Laky's Vulkan Pong";
	appInfo.pEngineName = "Laky's Vulkan Engine";

	VkInstanceCreateInfo createInfo = {};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;


	VkResult result = vkCreateInstance(&createInfo, nullptr, &context->instance);

	if(result != VK_SUCCESS)
	{
		std::cout << "Failed to create Vulkan instance!" << std::endl;
		return false;
	}
	else
	{
		std::cout << "Vulkan instance created!" << std::endl;
		return true;
	}
}