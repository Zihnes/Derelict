/**
* WindowManager controls the window frame, resolution or if should be full screen
*/
#include <iostream>
#include <windows.h>
#include "WindowManager.h"
#include "ErrorMessages.h"
#include "Root.h"

using namespace std;

// declare window class name
const char WindowManager::g_szClassName[] = "GAME_WINDOW";

WindowManager::WindowManager() {
	// does nothing
}

WindowManager::~WindowManager() {
	// does nothing
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	// standard window procedure
	switch (msg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		stop();
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

int WindowManager::initWindow() {
#ifdef _DEBUG
	cout << "Initializing window parameters\n";
#endif
	// fill out default parameters
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WindowProcedure;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = GetModuleHandle(0); // retreive handle
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = g_szClassName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
#ifdef _DEBUG
	cout << "Attempting to register window\n";
#endif
	// register
	if (!RegisterClassEx(&wc)) {
		MessageBox(NULL, WRG_ERR, SU_ERR, 
			MB_ICONEXCLAMATION | MB_OK);
		return 1;
	}
	return 0;
}

int WindowManager::createWindow() {
	// call create function
#ifdef _DEBUG
	cout << "Attempting to create window\n";
#endif
	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		g_szClassName,
		"DERELICT",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		500, 500, NULL, NULL, GetModuleHandle(0), NULL);
	// note that first two params on final line indicate width/height
	// confirm
	if (hwnd == NULL) {
		MessageBox(NULL, WCR_ERR, SU_ERR, 
			MB_ICONEXCLAMATION | MB_OK);
		return 1;
	}
	return 0;
}

void WindowManager::showWindow() {
	// show window
	ShowWindow(hwnd, 1);
	UpdateWindow(hwnd);
	return;
}

void WindowManager::startUp() {
	// start the manager
#ifdef _DEBUG
	cout << "Starting up WindowManager\n";
#endif
	// call window initilization function
	if (initWindow()) {
#ifdef _DEBUG
		cout << "Window init failed\n";
#endif
		exit(1);
	}
	// call window creation function
	if (createWindow()) {
#ifdef _DEBUG
		cout << "Window create failed\n";
#endif
		exit(1);
	}
	// call window show function
	showWindow();
	return;
}

void WindowManager::shutDown() {
	// shut down the manager
#ifdef _DEBUG
	cout << "Shutting down WindowManager\n";
#endif
}