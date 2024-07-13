#include "Tree.h"

Tree::Tree() {
}

void Tree::addPatient(std::string name, std::string sex, std::string condition, std::string doctor, int patientNumber, int height, int weight, int day, int month, int year) {
	hash.add(patientNumber);
	std::ofstream write;
	write.open("patients.csv", std::ios::app);
	write << name << "," << std::flush;
	write << sex << "," << std::flush;
	write << condition << "," << std::flush;
	write << doctor << "," << std::flush;
	write << patientNumber << "," << std::flush;
	write << height << "," << std::flush;
	write << weight << "," << std::flush;
	write << day << "," << std::flush;
	write << month << "," << std::flush;
	write << year << std::endl;
	write.close();
	Treenode* temp = new Treenode(name, sex, condition, doctor, patientNumber, height, weight, day, month, year);
	Treenode* current = Root;
	if (Root == nullptr) {
		Root = temp;
	}
	else {
		while (true) {
			if (patientNumber < current->patientNumber) {
				if (current->left == nullptr) {
					current->left = temp;
					break;
				}
				current = current->left;
			}
			if (patientNumber > current->patientNumber) {
				if (current->right == nullptr) {
					current->right = temp;
					break;
				}
				current = current->right;
			}
		}
	}
}

void Tree::addDoctor(std::string name, std::string sex, std::string role, int doctorNumber, int day, int month, int year) {
	hash.add(doctorNumber);
	std::ofstream write;
	write.open("doctors.csv", std::ios::app);
	write << name << "," << std::flush;
	write << sex <<  "," << std::flush;
	write << role << "," << std::flush;
	write << doctorNumber << "," << std::flush;
	write << day << "," << std::flush;
	write << month << "," << std::flush;
	write << year << std::endl;
	write.close();
	Treenode* temp = new Treenode(name, sex, role, doctorNumber, day, month, year);
	Treenode* current = Root;
	if (Root == nullptr) {
		Root = temp;
	}
	else {
		while (true) {
			if (doctorNumber < current->doctorNumber) {
				if (current->left == nullptr) {
					current->left = temp;
					break;
				}
				current = current->left;
			}
			if (doctorNumber > current->doctorNumber) {
				if (current->right == nullptr) {
					current->right = temp;
					break;
				}
				current = current->right;
			}
		}
	}
}

Treenode* Tree::deletePatient(Treenode* root, int patientNumber) {
	if (root == nullptr) {
		std::cout << "Error: The Tree is empty or incorrect data has been entered." << std::endl;
	}
	else if (patientNumber < root->patientNumber) {
		root->left = deletePatient(root->left, patientNumber);
	}
	else if (patientNumber > root->patientNumber) {
		root->right = deletePatient(root->right, patientNumber);
	}
	else {
		if (root->left && root->right) {
			findMax(root->left);
			root->patientNumber = vect.back();
			root->left = deletePatient(root->left, root->patientNumber);
		}
		else {
			Treenode* temp = root;
			if (root->left == nullptr) {
				root = root->right;
			}
			else if (root->right == nullptr) {
				root = root->left;
			}
			delete temp;
		}
	}
	return(root);
}

Treenode* Tree::deleteDoctor(Treenode* root, int doctorNumber) {
	if (root == nullptr) {
		std::cout << "Error: The Tree is empty or incorrect data has been entered." << std::endl;
	}
	else if (doctorNumber < root->doctorNumber) {
		root->left = deleteDoctor(root->left, doctorNumber);
	}
	else if (doctorNumber > root->doctorNumber) {
		root->right = deletePatient(root->right, doctorNumber);
	}
	else {
		if (root->left && root->right) {
			findMax(root->left);
			root->doctorNumber = vect.back();
			root->left = deleteDoctor(root->left, root->doctorNumber);
		}
		else {
			Treenode* temp = root;
			if (root->left == nullptr) {
				root = root->right;
			}
			else if (root->right == nullptr) {
				root = root->left;
			}
			delete temp;
		}
	}
	return(root);
}

void Tree::findMax(Treenode* root) {
	if (root) {
		findMax(root->left);
		vect.push_back(root->patientNumber);
		findMax(root->right);
	}
}

void Tree::loadServer(std::string status) {
	std::ifstream read;
	if (status == "patient") {
		read.open("patients.csv", std::ios::app);
		Root = nullptr;
	}
	if (status == "doctor") {
		read.open("doctors.csv", std::ios::app);
		Root = nullptr;
	}
	std::string name = "";
	std::string sex = "";
	std::string condition = "";
	std::string role = "";
	std::string doctor = "";
	int patientNumber = 0;
	int doctorNumber = 0;
	int height = 0;
	int weight = 0;
	int day = 0;
	int month = 0;
	int year = 0;
	while (!read.eof()) {
		if (status == "patient") {
			int pos = read.tellg();
			if (pos > 0) {
				read.seekg(pos - 1);
			}
			std::string temp = "";
			getline(read, name, ',');
			getline(read, sex, ',');
			getline(read, condition, ',');
			getline(read, doctor, ',');
			getline(read, temp, ',');
			patientNumber = stoi(temp);
			getline(read, temp, ',');
			height = stoi(temp);
			getline(read, temp, ',');
			weight = stoi(temp);
			getline(read, temp, ',');
			day = stoi(temp);
			getline(read, temp, ',');
			month = stoi(temp);
			getline(read, temp);
			year = stoi(temp);
			read.ignore();
			if (patientNumber != 0) {
				Treenode* temp = new Treenode(name, sex, condition, doctor, patientNumber, height, weight, day, month, year);
				Treenode* current = Root;
				if (Root == nullptr) {
					Root = temp;
				}
				else {
					while (true) {
						if (patientNumber < current->patientNumber) {
							if (current->left == nullptr) {
								current->left = temp;
								break;
							}
							current = current->left;
						}
						if (patientNumber > current->patientNumber) {
							if (current->right == nullptr) {
								current->right = temp;
								break;
							}
							current = current->right;
						}
						if (patientNumber == current->patientNumber) {
							break;
						}
					}
				}
			}
		}
		if (status == "doctor") {
			int pos = read.tellg();
			if (pos > 0) {
				read.seekg(pos - 1);
			}
			std::string temp = "";
			getline(read, name, ',');
			getline(read, sex, ',');
			getline(read, role, ',');
			getline(read, temp, ',');
			doctorNumber = stoi(temp);
			getline(read, temp, ',');
			day = stoi(temp);
			getline(read, temp, ',');
			month = stoi(temp);
			getline(read, temp);
			year = stoi(temp);
			read.ignore();
			if (doctorNumber != 0) {
				Treenode* temp = new Treenode(name, sex, role, doctorNumber, day, month, year);
				Treenode* current = Root;
				if (Root == nullptr) {
					Root = temp;
				}
				else {
					while (true) {
						if (doctorNumber < current->doctorNumber) {
							if (current->left == nullptr) {
								current->left = temp;
								break;
							}
							current = current->left;
						}
						if (doctorNumber > current->doctorNumber) {
							if (current->right == nullptr) {
								current->right = temp;
								break;
							}
							current = current->right;
						}
						if (doctorNumber == current->doctorNumber) {
							break;
						}
					}
				}
			}
		}
		
	}
	read.close();
}

Treenode* Tree::numberSearch(Treenode* root, int number, std::string status) {
	if (root == nullptr) {
		return (nullptr);
	}
	else {
		if (status == "patient") {
			if (number < root->patientNumber) {
				return (numberSearch(root->left, number, "patient"));
			}
			else if (number > root->patientNumber) {
				return (numberSearch(root->right, number, "patient"));
			}
		}
		if (status == "doctor") {
			if (number < root->doctorNumber) {
				return (numberSearch(root->left, number, "doctor"));
			}
			else if (number > root->doctorNumber) {
				return (numberSearch(root->right, number, "doctor"));
			}
		}
	}
	return (root);
}

void Tree::updateServer(Treenode* root, bool reset, std::string status) {
	if (reset) {
		if (status == "patient") {
			remove("patients.csv");
		}
		if (status == "doctor") {
			remove("doctors.csv");
		}
	}
	std::ofstream write;
	if (status == "patient") {
		write.open("patients.csv", std::fstream::app);
		if (root) {
			updateServer(root->left, false, status);
			write << root->name << "," << std::flush;
			write << root->sex << "," << std::flush;
			write << root->condition<< "," << std::flush;
			write << root->doctor << "," << std::flush;
			write << root->patientNumber << "," << std::flush;
			write << root->height << "," << std::flush;
			write << root->weight << "," << std::flush;
			write << root->day << "," << std::flush;
			write << root->month << "," << std::flush;
			write << root->year << std::endl;
			updateServer(root->right, false, status);
		}
		write.close();
	}
	if (status == "doctor") {
		write.open("doctors.csv", std::fstream::app);
		if (root) {
			updateServer(root->left, false, status);
			write << root->name << "," << std::flush;
			write << root->sex << "," << std::flush;
			write << root->role << "," << std::flush;
			write << root->doctorNumber << "," << std::flush;
			write << root->day << "," << std::flush;
			write << root->month << "," << std::flush;
			write << root->year << std::endl;
			updateServer(root->right, false, status);
		}
		write.close();
	}
}

void Tree::printInfo(Treenode* root, std::string status) {
	if (root) {
		printInfo(root->left, status);
		if (status == "patient") {
			std::cout << "Name: " << root->name << std::endl;
			std::cout << "Gender: " << root->sex << std::endl;
			std::cout << "Condition: " << root->condition << std::endl;
			std::cout << "Doctor: " << root->doctor << std::endl;
			std::cout << "Patient number: " << root->patientNumber << std::endl;
			std::cout << "Height (cm): " << root->height << std::endl;
			std::cout << "Weight (k.g): " << root->weight << std::endl;
			std::cout << "Date of birth: " << root->day << "/" << root->month << "/" << root->year << std::endl;
			printInfo(root->right, status);
		}
		if (status == "doctor") {
			std::cout << "Name: " << root->name << std::endl;
			std::cout << "Gender: " << root->sex << std::endl;
			std::cout << "Role: " << root->role << std::endl;
			std::cout << "Doctor number: " << root->doctorNumber << std::endl;
			std::cout << "Date of birth: " << root->day << "/" << root->month << "/" << root->year << std::endl;
			printInfo(root->right, status);
		}
	}
}