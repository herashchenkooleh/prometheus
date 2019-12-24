#include <Windows.h>

#include "Prometheus.Editor.Application.hpp"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	prometheus::editor::application app;

	if (!app.init())
	{
		return EXIT_FAILURE;
	}

	if (!app.run())
	{
		return EXIT_FAILURE;
	}

	if (!app.deinit())
	{
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}