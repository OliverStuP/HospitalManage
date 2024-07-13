#pragma once
void patient() {
	Tree tree; 
	Hashtable hash;
	int condition = 0;
	int patientNumber = 0;
	std::cout << "\nEnter your patient number\n" << std::endl;
	std::cin >> patientNumber;
	while (condition != 2) {
		std::cout << "\nWelcome!\n" << std::endl;
		std::cout << "\nSelect the following\n" << std::endl;
		std::cout << "1 - View account details.\n" << std::endl;
		std::cout << "2 - Exit.\n" << std::endl;
		std::cin >> condition;
		if (condition == 1) {
			tree.loadServer("patient");
			Treenode* temp = tree.numberSearch(tree.Root, patientNumber, "patient");
			std::cout << "\nPatient details:\n" << std::endl;
			std::cout << "Name: " << temp->name << "\n" << std::endl;
			std::cout << "Gender: " << temp->sex << "\n" << std::endl;
			std::cout << "Condition: " << temp->condition << "\n" << std::endl;
			std::cout << "Doctor: " << temp->doctor << "\n" << std::endl;
			std::cout << "Patient number: " << temp->patientNumber << "\n" << std::endl;
			std::cout << "Height (cm): " << temp->height << "\n" << std::endl;
			std::cout << "Weight (k.g): " << temp->weight << "\n" << std::endl;
			std::cout << "Date of birth: " << temp->day << "/" << temp->month << "/" << temp->year << "\n" << std::endl;
		}
		if (condition == 2) {
			condition = 2;
		}
	}
}