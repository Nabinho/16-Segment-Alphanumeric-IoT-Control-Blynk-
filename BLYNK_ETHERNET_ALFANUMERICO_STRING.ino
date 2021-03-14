//Blynk serial monitor function
#define BLYNK_PRINT Serial

//Libraries
#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>

//Authentication code (app)
char auth[] = "WfxpB9JbaTvuhJupEUHDLb0vKdFq9EAP";

//Pins connected to the 16 segment display
const int A_1_2 = 2;
const int B = A1;
const int C = A4;
const int D_1_2 = A5;
const int E = 9;
const int F = 5;
const int G_1_2 = 6;
const int H = 4;
const int J = 3;
const int K = A2;
const int L = A0;
const int M = 7;
const int N = 8;

//Array do configure the pins as an outuput
const int pinos[14] = {A_1_2, B, C, D_1_2, E, F, G_1_2, H, J, K, L, M, N};

//-------------------------------------------------------------------------------------
//Function to control the display with the correct character
void digit (int S1, int S2, int S3, int S4, int S5, int S6, int S7, int S8, int S9, int S10, int S11, int S12, int S13) {
 
  digitalWrite(A_1_2, S1);
  digitalWrite(B, S2);
  digitalWrite(C, S3);
  digitalWrite(D_1_2, S4);
  digitalWrite(E, S5);
  digitalWrite(F, S6);
  digitalWrite(G_1_2, S7);
  digitalWrite(H, S8);
  digitalWrite(J, S9);
  digitalWrite(K, S10);
  digitalWrite(L, S11);
  digitalWrite(M, S12);
  digitalWrite(N, S13);

}

//Variables to call the display controll
#define ON digit(0,0,0,0,0,0,0,0,0,0,0,0,0)
#define OFF digit(1,1,1,1,1,1,1,1,1,1,1,1,1)
#define L_A digit(1,0,0,0,0,0,0,1,1,1,1,1,1)
#define L_B digit(0,1,1,0,0,0,0,1,0,1,1,0,1)
#define L_C digit(0,0,0,0,1,1,1,1,1,1,1,1,1)
#define L_D digit(0,1,1,0,0,0,1,1,0,1,1,0,1)
#define L_E digit(0,0,0,0,1,1,0,1,1,1,1,1,1)
#define L_F digit(1,0,0,0,1,1,0,1,1,1,1,1,1)
#define L_G digit(0,0,0,0,1,0,0,0,1,1,1,1,1)
#define L_H digit(1,0,0,1,0,0,0,1,1,1,1,1,1)
#define L_I digit(0,1,1,0,1,1,1,1,0,1,1,0,1)
#define L_J digit(0,1,1,1,0,0,1,1,1,1,1,1,1)
#define L_K digit(1,0,0,1,1,1,1,0,1,1,1,1,0)
#define L_L digit(0,0,0,1,1,1,1,1,1,1,1,1,1)
#define L_M digit(1,0,0,1,0,0,1,1,1,1,0,1,0)
#define L_N digit(1,0,0,1,0,0,1,0,1,1,0,1,1)
#define L_O digit(0,0,0,0,0,0,1,1,1,1,1,1,1)
#define L_P digit(1,0,0,0,0,1,0,1,1,1,1,1,1)
#define L_Q digit(0,0,0,0,0,0,1,0,1,1,1,1,1)
#define L_R digit(1,0,0,0,0,1,0,0,1,1,1,1,1)
#define L_S digit(0,1,0,0,1,0,0,1,1,1,1,1,1)
#define L_T digit(1,1,1,0,1,1,1,1,0,1,1,0,1)
#define L_U digit(0,0,0,1,0,0,1,1,1,1,1,1,1)
#define L_V digit(1,0,0,1,1,1,1,1,1,0,1,1,0)
#define L_W digit(1,0,0,1,0,0,1,0,1,0,1,1,1)
#define L_X digit(1,1,1,1,1,1,1,0,1,0,0,1,0)
#define L_Y digit(1,1,1,1,1,1,1,1,0,1,0,1,0)
#define L_Z digit(0,1,1,0,1,1,1,1,1,0,1,1,0)
#define N_1 digit(1,1,1,1,0,0,1,1,1,1,1,1,0)
#define N_2 digit(0,0,1,0,0,1,0,1,1,1,1,1,1)
#define N_3 digit(0,1,1,0,0,0,0,1,1,1,1,1,1)
#define N_4 digit(1,1,0,1,0,0,0,1,1,1,1,1,1)
#define N_5 digit(0,1,0,0,1,0,0,1,1,1,1,1,1)
#define N_6 digit(0,0,0,1,1,0,0,1,1,1,1,1,1)
#define N_7 digit(1,1,1,0,1,1,0,1,1,0,1,1,0)
#define N_8 digit(0,0,0,0,0,0,0,1,1,1,1,1,1)
#define N_9 digit(1,1,0,0,0,0,0,1,1,1,1,1,1)
#define N_0 digit(0,0,0,0,0,0,1,1,1,0,1,1,0)

//Initiate the Blynk terminal
WidgetTerminal terminal(V1);

//Function to read the app terminal
BLYNK_WRITE(V1){

  //Convert the String sent from the app to single characters
  String str = param.asStr(); 
  int str_len = str.length() + 1; 
  char char_array[str_len];
  str.toCharArray(char_array, str_len);
  terminal.println("Exibindo mensagem no display!");
  
  //Show the characters with the display
  for(int i = 0; i < str_len; i++){
    if (65 == char_array[i] || 97 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      L_A;
    }
    if (66 == char_array[i] || 98 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      L_B;
    }
    if (67 == char_array[i] || 99 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      L_C;
    }
    if (68 == char_array[i] || 100 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      L_D;
    }
    if (69 == char_array[i] || 101 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      L_E;
    }
    if (70 == char_array[i] || 102 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      L_F;
    }
    if (71 == char_array[i] || 103 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      L_G;
    }
    if (72== char_array[i] || 104 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      L_H;
    }
    if (73 == char_array[i] || 105 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      L_I;
    }
    if (74 == char_array[i] || 106 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      L_J;
    }
    if (75 == char_array[i] || 107 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      L_K;
    }
    if (76 == char_array[i] || 108 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      L_L;
    }
    if (77 == char_array[i] || 109 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      L_M;
    }
    if (78 == char_array[i] || 110 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      L_N;
    }
    if (79 == char_array[i] || 111 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      L_O;
    }
    if (80 == char_array[i] || 112 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      L_P;
    }
    if (81 == char_array[i] || 113 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      L_Q;
    }
    if (82 == char_array[i] || 114 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      L_R;
    }
    if (83 == char_array[i] || 115 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      L_S;
    }
    if (84 == char_array[i] || 116 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      L_T;
    }
    if (85 == char_array[i] || 117 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      L_U;
    }
    if (86== char_array[i] || 118 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      L_V;
    }
    if (87 == char_array[i] || 119 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      L_W;
    }
    if (88 == char_array[i] || 120 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      L_X;
    }
    if (89 == char_array[i] || 121 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      L_Y;
    }
    if (90 == char_array[i] || 122 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      L_Z;
    }
    if (48 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      N_0;
    }
    if (49 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      N_1;
    }
    if (50 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      N_2;
    }
    if (51 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      N_3;
    }
    if (52 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      N_4;
    }
    if (53 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      N_5;
    }
    if (54 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      N_6;
    }
    if (55 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      N_7;
    }
    if (56 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      N_8;
    }
    if (57 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      N_9;
    }
    if (32 == char_array[i]) {
      //terminal.println("Display Atualizado!");
      OFF;
    }
    delay(200);
  }

  //Reset the display and handle the terminal
  OFF;
  terminal.flush();
  
}

//-------------------------------------------------------------------------------------
void setup() {

  //Initiate the terminal
  Serial.begin(9600);

  //Configure the pins as outputs
  for (int i = 0; i <= 14; i++) {
    pinMode(pinos[i], OUTPUT);
  }

  //Initialization message
  L_I;
  delay(200);
  L_N;
  delay(200);
  L_I;
  delay(200);
  L_C;
  delay(200);
  L_I;
  delay(200);
  L_A;
  delay(200);
  L_L;
  delay(200);
  L_I;
  delay(200);
  L_Z;
  delay(200);
  L_A;
  delay(200);
  L_N;
  delay(200);
  L_D;
  delay(200);
  L_O;
  delay(200);
  OFF;

  //Star the Blynk library
  Blynk.begin(auth);

  //Confirm initialization
  L_O;
  delay(200);
  L_K;
  delay(200);
  OFF;
  
}

//-------------------------------------------------------------------------------------
void loop() {

  //Keep connection active and handle library commands
  Blynk.run();

}
//-------------------------------------------------------------------------------------