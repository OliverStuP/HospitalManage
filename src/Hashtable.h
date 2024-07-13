#pragma once
#include "Internode.h"
#include "Patientnode.h"
#include <fstream>
#include <iostream>
#include <vector>

class Hashtable
{
public:
	Hashtable();
	void startHash();
	void loadTable();
	bool match(int patient);
	void add(int number);
	void display();
	Internode* start;
};

