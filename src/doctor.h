#pragma once
void doctor() {
	Tree tree; 
	Hashtable hash;
	int condition = 0;
	int doctorNumber = 0;
	std::cout << "\nEnter your doctor number\n" << std::endl;
	std::cin >> doctorNumber;
	while (condition != 7) {
		std::cout << "\nWelcome\n" << std::endl;
		std::cout << "Choosing the following:\n" << std::endl;
		std::cout << "1 - View details.\n" << std::endl;
		std::cout << "2 - View patients.\n" << std::endl;
		std::cout << "3 - View patient condition.\n" << std::endl;
		std::cout << "4 - View patient gender.\n" << std::endl;
		std::cout << "5 - View patient height.\n" << std::endl;
		std::cout << "6 - View patient weight.\n" << std::endl;
		std::cout << "7 - Exit.\n" << std::endl;
		std::cin >> condition;
		if (condition == 1) {
			tree.loadServer("doctor");
			Treenode* temp = tree.numberSearch(tree.Root, doctorNumber, "doctor");
			std::cout << "\nDoctor details:\n" << std::endl;
			std::cout << "Name: " << temp->name << "\n" << std::endl;
			std::cout << "Gender: " << temp->sex << "\n" << std::endl;
			std::cout << "Role: " << temp->role << "\n" << std::endl;
			std::cout << "Doctor number: " << temp->doctorNumber << "\n" << std::endl;
			std::cout << "Date of birth: " << temp->day << "/" << temp->month << "/" << temp->year << "\n" << std::endl;
		}
		if (condition == 2) {
			tree.loadServer("patient");
			tree.printInfo(tree.Root, "patient");
		}
		if (condition == 3) {
			int patientNumber = 0;
			std::cout << "\nEnter patient number\n" << std::endl;
			std::cin >> patientNumber;
			tree.loadServer("patient");
			Treenode* temp = tree.numberSearch(tree.Root, patientNumber, "patient");
			std::cout << temp->condition << "\n" << std::endl;
		}
		if (condition == 4) {
			int patientNumber = 0;
			std::cout << "\nEnter patient number\n" << std::endl;
			std::cin >> patientNumber;
			tree.loadServer("patient");
			Treenode* temp = tree.numberSearch(tree.Root, patientNumber, "patient");
			std::cout << temp->sex << "\n" << std::endl;
		}
		if (condition == 5) {
			int patientNumber = 0;
			std::cout << "\nEnter patient number\n" << std::endl;
			std::cin >> patientNumber;
			tree.loadServer("patient");
			Treenode* temp = tree.numberSearch(tree.Root, patientNumber, "patient");
			std::cout << temp->height << "\n" << std::endl;
		}
		if (condition == 6) {
			int patientNumber = 0;
			std::cout << "\nEnter patient number\n" << std::endl;
			std::cin >> patientNumber;
			tree.loadServer("patient");
			Treenode* temp = tree.numberSearch(tree.Root, patientNumber, "patient");
			std::cout << temp->weight << "\n" << std::endl;
		}
		if (condition == 7) {
			condition = 7;
		}
	}
}