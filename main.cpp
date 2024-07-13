#include "main.h"
void boot() {
	Hashtable hash;
	Tree tree;
	hash.startHash();
	tree.loadServer("patient");
}

int main() {
	void boot();
	int condition = 0;
	while (condition != 4) {
		std::cout << "\nDo you want to log in as?\n" << std::endl;
		std::cout << "1 - ADMIN\n" << std::endl;
		std::cout << "2 - DOCTOR\n" << std::endl;
		std::cout << "3 - PATIENT\n" << std::endl;
		std::cin >> condition;
		if (condition == 1) {
			admin();
		}
		if (condition == 2) {
			doctor();
		}
		if (condition == 3) {
			patient();
		}
		if (condition == 4) {
			condition = 4;
		}
	}
	system("pause");
	return 0;
}