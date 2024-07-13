#pragma once
#include <string>

class Treenode
{
public:
	Treenode();
	Treenode(std::string name, std::string sex, std::string condition, std::string doctor, int patientNumber, int height, int weight, int day, int month, int year);
	Treenode(std::string name, std::string sex, std::string role, int doctorNumber, int day, int month, int year);
	Treenode* left;
	Treenode* right;
	std::string name;
	std::string sex;
	std::string condition;
	std::string doctor;
	std::string role;
	int patientNumber;
	int doctorNumber;
	int height;
	int weight;
	int day;
	int month;
	int year;
};

