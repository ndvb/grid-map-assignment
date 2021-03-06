#pragma once
#include "Observer.h"
#include <list>
using namespace std;

class Subject {
public:
	~Subject();
	virtual void Attach(Observer* addObserver);
	virtual void Detach(Observer* removeObserver);
	virtual void Notify();
	Subject();
	int getNbObservers() {
        return _observers->size();
	}
private:
	list<Observer*> *_observers;



};
