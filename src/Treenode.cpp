#include "Treenode.h"

Treenode::Treenode() {
	left = nullptr;
	right = nullptr;
	name = "";
	sex = "";
	condition = "";
	doctor = "";
	role = "";
	patientNumber = 0;
	height = 0;
	weight = 0;
	day = 0;
	month = 0;
	year = 0;
	doctorNumber = 0;
}

Treenode::Treenode(std::string name, std::string sex, std::string condition, std::string doctor, int patientNumber, int height, int weight, int day, int month, int year) {
	left = nullptr;
	right = nullptr;
	this->name = name;
	this->sex = sex;
	this->condition = condition;
	this->doctor = doctor;
	this->patientNumber = patientNumber;
	this->height = height;
	this->weight = weight;
	this->day = day;
	this->month = month;
	this->year = year;
}

Treenode::Treenode(std::string name, std::string sex, std::string role, int doctorNumber, int day, int month, int year) {
	left = nullptr;
	right = nullptr;
	this->name = name;
	this->sex = sex;
	this->role = role;
	this->doctorNumber = doctorNumber;
	this->day = day;
	this->month = month;
	this->year = year;
}