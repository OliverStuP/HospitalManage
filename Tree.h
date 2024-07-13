#pragma once
#include <string>
#include "Hashtable.h"
#include "Treenode.h"
#include <vector>
#include <stdio.h>

class Tree
{
private:
	std::vector <int> vect;
public:
	Tree();
	void addPatient(std::string name, std::string sex, std::string condition, std::string doctor, int patientNumber, int height, int weight, int day, int month, int year);
	void addDoctor(std::string name, std::string sex, std::string role, int doctorNumber, int day, int month, int year);
	void findMax(Treenode* root);
	void loadServer(std::string status);
	void updateServer(Treenode* root, bool reset, std::string status);
	void printInfo(Treenode* root, std::string status);
	Treenode* deletePatient(Treenode* root, int patientNumber);
	Treenode* deleteDoctor(Treenode* root, int doctorNumber);
	Treenode* numberSearch(Treenode* root, int patientNumber, std::string status);
	Hashtable hash;
	Treenode* Root;
};

