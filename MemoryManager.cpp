/**
* MemoryManager allocates memory used in a level and organizes
*/
#include <iostream>
#include "MemoryManager.h"

using namespace std;

MemoryManager::MemoryManager() {
	// does nothing
}

MemoryManager::~MemoryManager() {
	// does nothing
}

void MemoryManager::startUp() {
	// start the manager
#ifdef _DEBUG
	cout << "Starting up MemoryManager\n";
#endif
}

void MemoryManager::shutDown() {
	// shut down the manager
#ifdef _DEBUG
	cout << "Shutting down MemoryManager\n";
#endif
}