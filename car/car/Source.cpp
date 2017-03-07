#include <iostream>
#include "header.hpp"

void setup() {
	int Sector[9][4] = { { 1,  2,  NULL, NULL },
	{ 1,  2,  4,    NULL },
	{ 2,  5,  NULL, NULL },
	{ 3,  6,  8,    NULL },
	{ 4,  6,  7,    9 },
	{ 5,  7,  10,	NULL },
	{ 8,  11, NULL, NULL },
	{ 9,  11, 12,	NULL },
	{ 10, 12, NULL, NULL } };

	int edge[12][2] = { { 1, 2 },
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

	/*sector Sector1{ 1,  2,  NULL, NULL };
	sector Sector2{ 1,  2,  4,    NULL };
	sector Sector3{ 2,  5,  NULL, NULL };
	sector Sector4{ 3,  6,  8,    NULL };
	sector Sector5{ 4,  6,  7,    9 };
	sector Sector6{ 5,  7,  10,	  NULL };
	sector Sector7{ 8,  11, NULL, NULL };
	sector Sector8{ 9,  11, 12,	  NULL };
	sector Sector9{ 10, 12, NULL, NULL };

	edge Edge1{ 1, 2 };
	edge Edge2{ 2, 3 };
	edge Edge3{ 1, 4 };
	edge Edge4{ 2, 5 };
	edge Edge5{ 3, 6 };
	edge Edge6{ 4, 5 };
	edge Edge7{ 5, 6 };
	edge Edge8{ 4, 7 };
	edge Edge9{ 5, 8 };
	edge Edge11{ 7, 8 };
	edge Edge12{ 8, 9 };*/
}

int main() {
	setup();
}