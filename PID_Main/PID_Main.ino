// Josh top begin
#include <Servo.h>
#define ARRAY_LENGTH 150
#define INITIAL_ANGLE 0
#define SERVO_PIN 9
#define MAX_OUTPUT 120
#define MIN_OUTPUT 0
#include "controller.h"

void output_to_servo();
Servo arms;
int moving_up_or_down = 1;

int output_angle[150];
// Josh top end

Controller ctrl;

//Ben Top Begin

int P_input;
int I_input;
int D_input;


double P_normal;
double I_normal;
double D_normal;

double start_angle = 25;
double stop_angle = 75;
//Ben End


void setup() {
  // put your setup code here, to run once:

// Hello From Ben
// Setup Josh begin
  arms.attach(SERVO_PIN);
  arms.write(INITIAL_ANGLE);
// Setup Josh end
}

void loop() {
  // put your main code here, to run repeatedly:

//Ben Start
P_input = analogRead(A0);
I_input = analogRead(A1);
D_input = analogRead(A2);

if(P_input > 1000){ P_input = 1000; }
if(I_input > 1000){ I_input = 1000; }
if(D_input > 1000){ D_input = 1000; }

P_normal = P_input / 1000.0;
I_normal = I_input / 1000.0;
D_normal = D_input / 1000.0;


ctrl.output(output_angle);

if (moving_up_or_down == 1){
  ctrl.simulateP(1, 0, 0, start_angle, stop_angle);
  moving_up_or_down = 0;
} else if (moving_up_or_down == 0){
  ctrl.simulateP(1, 0, 0, stop_angle, start_angle);
  moving_up_or_down = 1;
}

//Ben Stop



// Loop Josh begin
  // copy Ari's array to output_angle



 
  output_to_servo();
// Loop Josh end
}

// Josh output function begin
void output_to_servo() 
{
  int output = 0;
  
    for (int i = 0; i <= ARRAY_LENGTH; i++)
    {
      output = output_angle[i];

      if (output >= MAX_OUTPUT)
      {
        output = MAX_OUTPUT;
      }
      if (output <= MIN_OUTPUT)
      {
        output = MIN_OUTPUT;
      }

      arms.write(output);
      delay(10 );
    }
  return;
}
// Josh output function end

