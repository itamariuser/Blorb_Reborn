#pragma once
#include <stdlib.h>
#include<vector>
#include "blorb.h"
#include "GameModel.h"
#define UNIT_NUMBER 3
class GameModel {
public:
	Blorb blorbNetwork[UNIT_NUMBER];
	GameModel(std::vector<Blorb> startingBlorbNetwork);
};