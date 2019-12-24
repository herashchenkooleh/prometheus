#include <Windows.h>

#include "Prometheus.Editor.Application.hpp"

namespace prometheus::editor
{
	LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	application::application() noexcept
	{
	}

	application::~application() noexcept
	{
	}

	bool application::init() noexcept
	{
		const char CLASS_NAME[] = "Sample Window Class";

		WNDCLASS wc = { };

		wc.lpfnWndProc = WindowProc;
		wc.hInstance = GetModuleHandle(NULL);
		wc.lpszClassName = CLASS_NAME;

		RegisterClass(&wc);

		// Create the window.

		HWND hwnd = CreateWindowEx(
			0,                              // Optional window styles.
			CLASS_NAME,                     // Window class
			"Learn to Program Windows",    // Window text
			WS_OVERLAPPEDWINDOW,            // Window style

			// Size and position
			CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

			NULL,       // Parent window    
			NULL,       // Menu
			GetModuleHandle(NULL),  // Instance handle
			NULL        // Additional application data
		);

		if (hwnd == NULL)
		{
			return false;
		}

		ShowWindow(hwnd, 1);

		return true;
	}

	bool application::deinit() noexcept
	{
		return false;
	}

	bool application::run() noexcept
	{
		MSG msg = { };
		while (GetMessage(&msg, NULL, 0, 0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return true;
	}

	void OnSize(HWND hwnd, UINT flag, int width, int height)
	{
	}

	LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_SIZE:
		{
			int width = LOWORD(lParam);  // Macro to get the low-order word.
			int height = HIWORD(lParam); // Macro to get the high-order word.

			// Respond to the message:
			OnSize(hwnd, (UINT)wParam, width, height);
		}
		break;
		case WM_CLOSE:
		{
			PostQuitMessage(0);
		}
		break;
		default:
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
		}

		return 0;
	}
}