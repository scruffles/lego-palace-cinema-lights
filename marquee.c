//
// define inputs/outputs for each light
// 16 leds controlled by 4 digital pins requires accessing them as a grid (see readme.md)
// 

int lights[][2] = {
  {2, 6}, {2, 7}, {2, 8}, {2, 9}, 
  {3, 6}, {3, 7}, {3, 8}, {3, 9},
  {4, 6}, {4, 7}, {4, 8}, {4, 9},
  {5, 6}, {5, 7}, {5, 8}, {5, 9}
};

void allOff() {
  for (int i = 2; i <= 9; i++) {
    pinMode(i, INPUT);
  }
}

int REFRESH = 1;

void showLights(int toShow[], int arraySize, int time, int refresh) {
  for (int i = 0; i<time/refresh/arraySize; i = i + refresh) { // todo this should be time based
    for (int i = 0; i<arraySize; i = i + 1) {
      allOff();
      int input = lights[toShow[i]][0];
      int output = lights[toShow[i]][1];
      // Serial.println(input);
      // Serial.println(output);
      pinMode(input, OUTPUT);
      digitalWrite(input, HIGH);
      pinMode(output, OUTPUT);
      digitalWrite(output, LOW);
      delay(refresh);
    }
  }
}

//
// flash all
//

int all[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12, 14, 15};
void flashAll() {
  for (int i=0; i<3; i++) {
    showLights(all, 16, 500, 1);
    allOff();
    delay(500);   
  }
}

//
// race
//

int raceSequence[][5] = {
  {0},{1},{2},{3},{4},{5},{6},{7},{8},{9},{10},{11},{12},{13},{14},{15},
  {15},{14},{13},{12},{11},{10},{9},{8},{7},{6},{5},{4},{3},{2},{1},{0},
};
void race() {
  for (int i=0; i<32; i++) {
    showLights(raceSequence[i], 1, 500, 5);
  }
  allOff();
}

//
// jog
//

int jogSequence[][6] = {
  {0, 3, 6, 9, 12, 15},
  {1, 4, 7, 10, 13, 16},
  {2, 5, 8, 11, 14}
};
void jog() {
  for (int i=0; i<3; i++) {
    showLights(jogSequence[i], i < 1 ? 6 : 5, 500, 3);
  }
  allOff();
}


//
// fill
//
void fillSequence() {
  for (int end=15; end>=0; end--) { // end starts at 16 and counts down to 0
    for (int start=0; start<end; start++) { // start starts as 0 and counts up to end
      int length = 16-end+1;
      int lights[length];
      for (int filled=16, i=0; filled>end; filled--, i++) {
        lights[i] = filled;
      }
      lights[length-1]= start;
      showLights(lights, length, 50, 1);
    }
  }
  flashAll();
}


// 
// init and main loop
// 

void setup() {
  Serial.begin(9600); // allow debugging to monitor (Serial.println)
  allOff();
}

void loop() {
  for (int i=0; i<15; i++) {
    jog();
  }
  delay(500);   
  flashAll();
  delay(500);   
  for (int i=0; i<4; i++) {
    race();
  }
  flashAll();
  fillSequence();
}

