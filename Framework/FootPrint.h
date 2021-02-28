#pragma once
#include "GameObject.h"
class FootPrint :
	public GameObject
{
public:
	int x, y;
	FootPrint(int x, int y);
	~FootPrint();
};

