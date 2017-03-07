#pragma once
#include <iostream>

class Auto {
private:
	int *curr_edge = NULL;
	int *edge1 = NULL;
	int *edge2 = NULL;
	int *edge3 = NULL;
	int *edge4 = NULL;
	int *sector = NULL;

public:
	Auto();
	void choose_edge();
	void get_sector();
};

typedef struct edge {
	int sector1;
	int sector2;
} edge;

typedef struct sector {
	int edge1;
	int edge2;
	int edge3;
	int edge4;
} sector;
