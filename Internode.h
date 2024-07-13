#pragma once
#include "Patientnode.h"

class Internode
{
public:
	Internode();
	Internode(int info);
	Internode* next;
	Patientnode* previous;
	int data;
};

