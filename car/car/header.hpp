#pragma once
#include <iostream>

typedef struct Map {
	int Sectors[9][4] = { { 1,  2,  NULL, NULL },
						  { 1,  2,  4,    NULL },
					      { 2,  5,  NULL, NULL },
						  { 3,  6,  8,    NULL },
						  { 4,  6,  7,    9 },
						  { 5,  7,  10,   NULL },
						  { 8,  11, NULL, NULL },
						  { 9,  11, 12,	  NULL },
						  { 10, 12, NULL, NULL } };

	int Edges[12][2] = { { 1, 2 },
						 { 2, 3 },
						 { 1, 4 },
						 { 2, 5 },
						 { 3, 6 },
						 { 4, 5 },
						 { 5, 6 },
						 { 4, 7 },
						 { 5, 8 },
						 { 7, 8 },
						 { 8, 9 } };
} Map;

class Auto {
private:
	int *curr_edge;
	int *edge[4];
	int *sector;
	int *drive_to_edge;
	Map map;
public:
	Auto();
	void choose_edge();
	void get_sector();
	void drive();
};

