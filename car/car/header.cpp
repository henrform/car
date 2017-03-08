#include "header.hpp"

Auto::Auto() {
	//Set default Values for Sector 2
	prev_sector = &map.Edges[0][0];
	curr_sector = &map.Edges[0][1];
	curr_edge = &map.Sectors[*curr_sector][0];
	for (int i = 0; i < 4; i++) {
		edge[i] = &map.Sectors[*curr_sector][i];
		//std::cout << "Edge[" << i << "]:" << *edge[i] << std::endl;
	}
}
void Auto::get_sector() {
	////Where am I?
	prev_sector = curr_sector;
	
	if (map.Edges[*curr_edge][0] == *curr_sector)
		curr_sector = &map.Edges[*curr_edge][1];
	else
		curr_sector = &map.Edges[*curr_edge][0];

	for (int i = 0; i < 4; i++) {
		edge[i] = &map.Sectors[*curr_sector][i];
	}
}

void Auto::drive() {
	//drive somewhere
	if (abs(*curr_edge - *drive_to_edge) == 5 || abs(*curr_edge - *drive_to_edge) == 1)
		std::cout << "Driving a straight line to Edge " << *drive_to_edge << std::endl;
	else {
		if ((*curr_sector - *prev_sector == 1  && *next_sector - *curr_sector == 3)  ||
			(*curr_sector - *prev_sector == 3  && *next_sector - *curr_sector == -1) ||
			(*curr_sector - *prev_sector == -1 && *next_sector - *curr_sector == -3) ||
			(*curr_sector - *prev_sector == -3 && *next_sector - *curr_sector == 1)) {
			std::cout << "Driving a left curve to Edge " << *drive_to_edge << std::endl;
		}
		else if ((*curr_sector - *prev_sector == -3 && *next_sector - *curr_sector == -1) ||
				 (*curr_sector - *prev_sector == -1 && *next_sector - *curr_sector == 3 ) ||
				 (*curr_sector - *prev_sector == 3  && *next_sector - *curr_sector == 1 ) ||
				 (*curr_sector - *prev_sector == 1  && *next_sector - *curr_sector == -3)) {
			std::cout << "Driving a right curve to Edge " << *drive_to_edge << std::endl;
		}
	}
}

void Auto::run() {
	////Runs in an endless loop
	int randint;
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
		//std::cout << "Random number: " << randint << std::endl;
	} while (map.Sectors[*curr_sector][randint] == *curr_edge);
	//Set next target edge
	drive_to_edge = &map.Sectors[*curr_sector][randint];
	if (map.Edges[*drive_to_edge][0] == *curr_sector)
		next_sector = &map.Edges[*drive_to_edge][1];
	else
		next_sector = &map.Edges[*drive_to_edge][0];
	//std::cout << "Next Edge: " << *drive_to_edge << std::endl;
	//std::cout << "Previous Sector: " << *prev_sector << std::endl << "Current Sector: " << *curr_sector << std::endl << "Next Sector: " << *next_sector << std::endl;
	//drive to this edge
	drive();
	//update the current edge
	curr_edge = drive_to_edge;
	//Where am I now?
	get_sector();
}

