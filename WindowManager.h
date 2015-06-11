#ifndef W_MANAGER_H
#define W_MANAGER_H

#include <windows.h>

class WindowManager {
private:
	// Window class and handle
	WNDCLASSEX wc;
	HWND hwnd;
	// Window class name
	static const char g_szClassName[];
public:
	WindowManager(); // Do nothing, construction is handled by startUp()
	~WindowManager(); // Do nothing, destruction is handled by shutDown()
	int initWindow();
	int createWindow();
	void showWindow();
	void startUp();
	void shutDown();
};

#endif