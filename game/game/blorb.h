#pragma once
#include <vector>
#include <stdlib.h>
#include "observer.h"


class Blorb {
public:
	//std::vector<Node> inputNodes;
	//std::vector<Action> outputNodes;
	std::vector<Blorb*> subscribers;



	int sendMsg(int blorbIP,int specialIP,std::vector<char> stuff);

	int calcAction()
	{
		//do something with 
	}
};