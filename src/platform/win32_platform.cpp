#include <iostream>
#include <windows.h>
#include "renderer/vk_renderer.cpp"

static bool running = true;

LRESULT CALLBACK platformWindowCallback(HWND window, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CLOSE:
		running = false;
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
		
	}

	return DefWindowProcA(window, message, wParam, lParam);

	return 0;
}

bool platform_createWindow(HWND window)
{
	HINSTANCE hInstance = GetModuleHandleA(NULL);

	WNDCLASS wc = {};
	wc.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = platformWindowCallback;
	wc.hInstance = hInstance;
	wc.lpszClassName = "vulkan_engine_class";
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	if (!RegisterClassA(&wc))
	{
		std::cout << "Failed to register window class!" << std::endl;
		MessageBox(NULL, "Failed to register window class!", "Error", MB_OK | MB_ICONERROR);
		return false;
	}


    window = CreateWindowExA(
        WS_EX_APPWINDOW,
        "vulkan_engine_class",
        "Laky's Vk Pong",
        WS_THICKFRAME | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_OVERLAPPED,
        100, 100, 1600, 720, 0, 0, hInstance, 0);

	if (!window)
	{
		std::cout << "Failed to create window!" << std::endl;
		MessageBox(NULL, "Failed to create window!", "Error", MB_OK | MB_ICONERROR);
		return false;
	}

	ShowWindow(window, SW_SHOW);

	return true;
}

void platform_updateWindow(HWND window)
{
	MSG msg;

	while (PeekMessageA(&msg, window, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}

}

int main()
{
	VkContext context = {};

	HWND window = 0;
	if(!platform_createWindow(window))
	{
		return -1;
	}

	if(!vk_initRenderer(&context))
	{
		return 1;
	}

	while(running)
	{
		platform_updateWindow(window);
	}
	return 0;
}