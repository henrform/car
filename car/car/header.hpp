#pragma once
#include <iostream>
#include <math.h>

typedef struct Map {
	int Sectors[9][4] = { { 0,  2,  NULL, NULL },
						  { 0,  1,  3,    NULL },
					      { 1,  4,  NULL, NULL },
						  { 2,  5,  7,    NULL },
						  { 3,  5,  6,    8 },
						  { 4,  6,  9,    NULL },
						  { 7,  10, NULL, NULL },
						  { 8,  10, 11,	  NULL },
						  { 9,  11, NULL, NULL } };

	int Edges[12][2] = { { 0, 1 }, /*1*/
						 { 1, 2 }, /*2*/
						 { 0, 3 }, /*3*/
						 { 1, 4 }, /*4*/
						 { 2, 5 }, /*5*/
						 { 3, 4 }, /*6*/
						 { 4, 5 }, /*7*/
						 { 3, 6 }, /*8*/
						 { 4, 7 }, /*9*/
						 { 5, 8 }, /*10*/
						 { 6, 7 }, /*11*/
						 { 7, 8 }  /*12*/};
} Map;

class Auto {
private:
	int *prev_sector;
	int *curr_sector;
	int *next_sector;
	int *curr_edge;
	int *edge[4];
	int *drive_to_edge;
	Map map;
public:
	Auto();
	void run();
	void get_sector();
	void drive();
};

