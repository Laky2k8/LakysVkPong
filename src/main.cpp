#include <vulkan/vulkan.h>
#include <iostream>

int main() {
	VkApplicationInfo appInfo = {};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Laky's Vulkan Pong";
	appInfo.pEngineName = "Laky's Vulkan Engine";

	VkInstanceCreateInfo createInfo = {};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;

	VkInstance instance;

	VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
	if(result != VK_SUCCESS) {
		std::cout << "Failed to create Vulkan instance!" << std::endl;
		return 1;
	}
	else
	{
		std::cout << "Successfully created Vulkan instance! :]" << std::endl;
	}


	return 0;
}
