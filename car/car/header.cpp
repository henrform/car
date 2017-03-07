#include "header.hpp"

Auto::Auto() {
	//Set default Values for Sector 2
	*sector = 1;
	*curr_edge = 1;
	*edge[0] = 1;
	*edge[1] = 2;
	*edge[2] = 4;
	*edge[3] = NULL;
}
void Auto::get_sector() {
	//Where am I?

}

void Auto::drive() {
	//drive somewhere
}

//Chooses the next edge
void Auto::choose_edge() {
	int randint;
	do {
		if (*edge[3] == NULL) {
			if (*edge[2] == NULL)
				randint = rand() % 2;
			else
				randint = rand() % 3;
		}
		else
			randint = rand() % 4;
	} while (map.Sectors[*sector][randint] == *curr_edge);
	drive_to_edge = &map.Sectors[*sector][randint];
	drive();
	curr_edge = drive_to_edge;
}

