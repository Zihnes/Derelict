#ifndef M_MANAGER_H
#define M_MANAGER_H

class MemoryManager {
public:
	MemoryManager(); // Do nothing, construction is handled by startUp()
	~MemoryManager(); // Do nothing, destruction is handled by shutDown()
	
	void startUp();
	void shutDown();
};

#endif