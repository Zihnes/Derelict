/**
* ErrorManager handles noted errors from other components
*/
#include <iostream>
#include "ErrorManager.h"

using namespace std;

ErrorManager::ErrorManager() {
	// does nothing
}

ErrorManager::~ErrorManager() {
	// does nothing
}

void ErrorManager::startUp() {
	// start the manager
#ifdef _DEBUG
	cout << "Starting up ErrorManager\n";
#endif
}

void ErrorManager::shutDown() {
	// shut down the manager
#ifdef _DEBUG
	cout << "Shutting down ErrorManager\n";
#endif
}
