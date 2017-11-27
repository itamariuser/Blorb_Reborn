#pragma once


class Observer
{
	virtual void update() = 0;
};

class Observable
{
	std::vector<Observer*> observers;
	bool changed = false;
	virtual void setChanged()
	{
		changed = true;
	}
protected: 
	virtual void notifyObservers(void* data) = 0;
	virtual void addObserver(Observer* o)
	{
		observers.push_back(o);
	}
};