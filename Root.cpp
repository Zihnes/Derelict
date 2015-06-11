/**
* Root file, launches managers and game loop	
*/
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include "ErrorManager.h"
#include "MemoryManager.h"
#include "WindowManager.h"

using namespace std;

ErrorManager gErrorManager;
MemoryManager gMemoryManager;
WindowManager gWindowManager;

bool gameRunning;

// Main game loop
void run() {
	gameRunning = true;
	while (gameRunning) {
		// Windows message pump
		MSG Msg;
		while (GetMessage(&Msg, NULL, 0, 0) > 0) {
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}
	}
	return;
}

void stop() {
	gameRunning = false;
}

// main function
int main(int argc, char* argv[]) {
	// Start up managers
	gErrorManager.startUp();
	gMemoryManager.startUp();
	gWindowManager.startUp();
	// Start game and wait for messages
	run();
	// Shut down managers
	gMemoryManager.shutDown();
	gWindowManager.shutDown();
	gErrorManager.shutDown();
	system("PAUSE");
	return 0;
}