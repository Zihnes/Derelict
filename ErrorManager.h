#ifndef E_MANAGER_H
#define E_MANAGER_H

class ErrorManager {
public:
	ErrorManager(); // Do nothing, construction is handled by startUp()
	~ErrorManager(); // Do nothing, destruction is handled by shutDown()

	void startUp();
	void shutDown();
};

#endif;