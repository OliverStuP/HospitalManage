#pragma once
void admin() {
	Tree tree; 
	Hashtable hash;
	int condition = 0;
	while (condition != 7) {
		std::cout << "\nWelcome\n" << std::endl;
		std::cout << "Choosing the following:\n" << std::endl;
		std::cout << "1 - Add a patient.\n" << std::endl;
		std::cout << "2 - Delete a patient.\n" << std::endl;
		std::cout << "3 - View all patients.\n" << std::endl;
		std::cout << "4 - Add a doctor.\n" << std::endl;
		std::cout << "5 - Delete a doctor.\n" << std::endl;
		std::cout << "6 - View all doctors.\n" << std::endl;
		std::cout << "7 - Exit.\n" << std::endl;
		std::cin >> condition;
		if (condition == 1) {
			std::string name = "";
			std::string sex = "";
			std::string condition = "";
			std::string doctor = "";
			int patientNumber;
			int height;
			int weight;
			int day;
			int month;
			int year;
			std::cout << "\nEnter name\n" << std::endl;
			std::cin >> name;
			std::cout << "\nEnter gender\n" << std::endl;
			std::cin >> sex;
			std::cout << "\nEnter condition\n" << std::endl;
			std::cin >> condition;
			std::cout << "\nEnter doctor\n" << std::endl;
			std::cin >> doctor;
			std::cout << "\nEnter patient number\n" << std::endl;
			std::cin >> patientNumber;
			std::cout << "\nEnter height (in cm)\n" << std::endl;
			std::cin >> height;
			std::cout << "\nEnter weight (in k.g)\n" << std::endl;
			std::cin >> weight;
			std::cout << "\nEnter date of birth (day/month/year)\n" << std::endl;
			std::cin >> day;
			std::cin >> month;
			std::cin >> year;
			tree.addPatient(name, sex, condition, doctor, patientNumber, height, weight, day, month, year);
		}
		if (condition == 2) {
			int del = 0;
			while (del != 3) {
				std::cout << "\nWARNING! This action is irreversable. Do you wish to continue?\n" << std::endl;
				std::cout << "1 - Yes.\n" << std::endl;
				std::cout << "2 - No.\n" << std::endl;
				std::cin >> del;
				if (del == 1) {
					int patientNumber = 0;
					std::cout << "\nEnter the patient number\n" << std::endl;
					std::cin >> patientNumber;
					tree.loadServer("patient");
					tree.Root = tree.deletePatient(tree.Root, patientNumber);
					std::cout << "\nPatient deleted.\n" << std::endl;
					tree.updateServer(tree.Root, true, "patient");
					std::cout << "\nServer updated.\n" << std::endl;
					break;
				}
				if (del == 2) {
					break;
				}
				if (del == 3) {
					del = 3;
				}
			}
		}
		if (condition == 3) {
			tree.loadServer("patient");
			tree.printInfo(tree.Root, "patient");
		}
		if (condition == 4) {
			std::string name = "";
			std::string sex = "";
			std::string role = "";
			int doctorNumber;
			int day;
			int month;
			int year;
			std::cout << "\nEnter name\n" << std::endl;
			std::cin >> name;
			std::cout << "\nEnter gender\n" << std::endl;
			std::cin >> sex;
			std::cout << "\nEnter role\n" << std::endl;
			std::cin >> role;
			std::cout << "\nEnter doctor number\n" << std::endl;
			std::cin >> doctorNumber;
			std::cout << "\nEnter date of birth (day/month/year)\n" << std::endl;
			std::cin >> day;
			std::cin >> month;
			std::cin >> year;
			tree.addDoctor(name, sex, role, doctorNumber, day, month, year);
		}
		if (condition == 5) {
			int del = 0;
			while (del != 3) {
				std::cout << "\nWARNING! This action is irreversable. Do you wish to continue?\n" << std::endl;
				std::cout << "1 - Yes.\n" << std::endl;
				std::cout << "2 - No.\n" << std::endl;
				std::cin >> del;
				if (del == 1) {
					int doctorNumber = 0;
					std::cout << "\nEnter the doctor number\n" << std::endl;
					std::cin >> doctorNumber;
					tree.loadServer("doctor");
					tree.Root = tree.deleteDoctor(tree.Root, doctorNumber);
					std::cout << "\nDoctor deleted.\n" << std::endl;
					tree.updateServer(tree.Root, true, "doctor");
					std::cout << "\nServer updated.\n" << std::endl;
					break;
				}
				if (del == 2) {
					break;
				}
				if (del == 3) {
					del = 3;
				}
			}
		}
		if (condition == 6) {
			tree.loadServer("doctor");
			tree.printInfo(tree.Root, "doctor");
		}
		if (condition == 7) {
			condition = 7;
		}
	}
}