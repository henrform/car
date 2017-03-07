#include "header.hpp"

Auto::Auto() {
	//Set default Values for Sector 2
	sector = &map.Edges[0][1];
	curr_edge = &map.Sectors[*sector][0];
	for (int i = 0; i < 4; i++) {
		edge[i] = &map.Sectors[*sector][i];
		std::cout << "Edge[" << i << "]:" << *edge[i] << std::endl;
	}
}
void Auto::get_sector() {
	////Where am I?
	if (map.Edges[*curr_edge][0] == *sector)
		sector = &map.Edges[*curr_edge][1];
	else
		sector = &map.Edges[*curr_edge][0];

	for (int i = 0; i < 4; i++) {
		edge[i] = &map.Sectors[*sector][i];
		std::cout << "Edge[" << i << "]:" << *edge[i] << std::endl;
	}
}

void Auto::drive() {
	//drive somewhere
	if (abs(*curr_edge - *drive_to_edge) == 5 || abs(*curr_edge - *drive_to_edge) == 1)
		std::cout << "Driving a straight line to Edge " << *drive_to_edge << std::endl;
	else if (abs(*curr_edge - *drive_to_edge) == 2 || abs(*curr_edge - *drive_to_edge) == 3)
		if () //abs(prev_sec-curr_sec) == 1 && abs (
		std::cout << "Driving a curve to Edge " << *drive_to_edge << std::endl;
}

void Auto::run() {
	////Runs in an endless loop
	int randint;
	srand(time_t(NULL));
	//Chooses the next edge
	do {
		if (*edge[3] == NULL) {
			if (*edge[2] == NULL)
				randint = rand() % 2;
			else
				randint = rand() % 3;
		}
		else
			randint = rand() % 4;
		std::cout << "Random number: " << randint << std::endl;
	} while (map.Sectors[*sector][randint] == *curr_edge);
	//Set next target edge
	drive_to_edge = &map.Sectors[*sector][randint];
	std::cout << "Next Edge: " << *drive_to_edge << std::endl;
	//drive to this edge
	drive();
	//update the current edge
	curr_edge = drive_to_edge;
	//Where am I now?
	get_sector();
}

