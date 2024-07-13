#include "Internode.h"

Internode::Internode() {
	next = nullptr;
	previous = nullptr;
	data = 0;
}

Internode::Internode(int info) {
	next = nullptr;
	previous = nullptr;
	data = info;
}