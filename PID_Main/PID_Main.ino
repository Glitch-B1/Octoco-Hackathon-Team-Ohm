// Josh addition top begin
#include <Servo.h>
#define ARRAY_LENGTH 150
#define INITIAL_ANGLE 25
#define SERVO_PIN 9
#define MAX_OUTPUT 90
#define MIN_OUTPUT 0

void output_to_servo(int output_angles[], int moving_up_or_down);
Servo arms;
int move_up = 1;
// Josh addition top end

void setup() {
  // put your setup code here, to run once:

// Hello From Ben

// Hello from josh begin
  arms.attach(SERVO_PIN);
  arms.write(INITIAL_ANGLE);
  // Josh end
}

void loop() {
  // put your main code here, to run repeatedly:

}

// Josh output function begin
void output_to_servo(int output_angle[], int moving_up_or_down) 
{
  int output = 0;

  if (moving_up_or_down == 1)
  {
    for (int i = 0; i <= ARRAY_LENGTH; i++)
    {
      output = output_angle[i];

      if (output >= MAX_OUTPUT)
      {
        output = MAX_OUTPUT;
      }

      arms.write(output);
      delay(15);
    }

    moving_up_or_down = 0;
  }
  else if (moving_up_or_down == 0)
  {
    for (int i = 0; i <= ARRAY_LENGTH; i++)
    {
      output = 90 - output_angle[i];

      if (output <= MIN_OUTPUT)
      {
        output = MIN_OUTPUT;
      }

      arms.write(output);
      delay(15);
    }

    moving_up_or_down = 1;
  }
  return;
}
// Josh output function end