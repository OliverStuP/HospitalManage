#include "Hashtable.h"

Hashtable::Hashtable() {
	start = nullptr;
}

void Hashtable::startHash() {
	for (int i = 0; i < 12; i++) {
		Internode* temp = new Internode(i);
		if (start == nullptr) {
			start = temp;
		}
		else {
			Internode* current = start;
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = temp;
		}
	}
	loadTable();
}

void Hashtable::loadTable() {
	int patient = 0;
	int patMod = 0;

	std::ifstream read;
	read.open("hashtable.txt");
	while (!read.eof()) {
		read >> patient;
		if (match(patient)) {
			continue;
		}
		if (patient != -858993460) {
			patMod = patient % 10;
			Internode* inode = start;
			while (inode->data != patMod) {
				inode = inode->next;
			}
			Patientnode* temp = new Patientnode(patient);
			if (inode->previous == nullptr) {
				inode->previous = temp;
			}
			else {
				Patientnode* root;
				root = inode->previous;
				while (root->next != nullptr) {
					root = root->next;
				}
				root->next = temp;
			}
		}
	}
	read.close();
}

bool Hashtable::match(int patient) {
	bool flag = false;
	int patMod = patient % 10;
	Internode* inode = start;
	while (inode->data != patMod) {
		inode = inode->next;
	}
	Patientnode* pnode = inode->previous;
	while (pnode != nullptr) {
		if (pnode->patientNumber == patient) {
			flag = true;
			break;
		}
		pnode = pnode->next;
	}
	return flag;
}

void Hashtable::add(int patient) {
	static int i = 0;
	std::ofstream write;
	write.open("hashtable.txt", std::ios::app);
	if (i != 0) {
		write << std::endl;
		write << patient << std::endl;
	}
	else {
		i++;
		write << patient << std::endl;
	}
	write.close();
	startHash();
}

void Hashtable::display() {
	Internode* current = start;
	while (current != nullptr) {
		std::cout << current->data << std::endl;
		current = current->next;
	}
}