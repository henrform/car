#include "header.hpp"

Auto::Auto() {
	*sector = 2;
	*curr_edge = 1;
	*edge1 = 1;
	*edge2 = 2;
	*edge3 = 4;
	*edge4 = NULL;
}
void Auto::get_sector() {

}

void Auto::choose_edge() {
	if (*edge4 == NULL) {
		if (*edge3 == NULL) {
			int randint = rand() % 2;
		}
		else {
			int randint = rand() % 3;
		}
	}
	else {
		int randint = rand() % 4;
	}
}