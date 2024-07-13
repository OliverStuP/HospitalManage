#include "Patientnode.h"

Patientnode::Patientnode() {
	next = nullptr;
	patientNumber = 0;
}

Patientnode::Patientnode(int patient) {
	next = nullptr;
	patientNumber = patient;
}