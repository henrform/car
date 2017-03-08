#include <math.h>

typedef struct Map {
  int Sectors[9][4] = { { 0,  2,  NULL, NULL },
              { 0,  1,  3,    NULL },
                { 1,  4,  NULL, NULL },
              { 2,  5,  7,    NULL },
              { 3,  5,  6,    8 },
              { 4,  6,  9,    NULL },
              { 7,  10, NULL, NULL },
              { 8,  10, 11,   NULL },
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
  if (abs(*curr_edge - *drive_to_edge) == 5 || abs(*curr_edge - *drive_to_edge) == 1){
    Serial.println("Driving a straight line to Edge ");
    Serial.println(*drive_to_edge);
  }
  else {
    if ((*curr_sector - *prev_sector == 1  && *next_sector - *curr_sector == 3)  ||
      (*curr_sector - *prev_sector == 3  && *next_sector - *curr_sector == -1) ||
      (*curr_sector - *prev_sector == -1 && *next_sector - *curr_sector == -3) ||
      (*curr_sector - *prev_sector == -3 && *next_sector - *curr_sector == 1)) {
      Serial.println("Driving a left curve to Edge ");
      Serial.println(*drive_to_edge);
    }
    else if ((*curr_sector - *prev_sector == -3 && *next_sector - *curr_sector == -1) ||
         (*curr_sector - *prev_sector == -1 && *next_sector - *curr_sector == 3 ) ||
         (*curr_sector - *prev_sector == 3  && *next_sector - *curr_sector == 1 ) ||
         (*curr_sector - *prev_sector == 1  && *next_sector - *curr_sector == -3)) {
      Serial.println("Driving a right curve to Edge ");
      Serial.println(*drive_to_edge);
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
        randint = random(2);
      else
        randint = random(3);
    }
    else
      randint = random(4);
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

Auto car;

void setup() {
  Serial.begin(9600);

  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(0));
}

void loop() {
  car.run();

}
