/*
 *FILE          : assignment_1_first_attempt_().ino
 *PROJECT       : PROG8125 - Assignment #1
 *PROGRAMMER    : Kunal Malhotra
 *FIRST VERSION : 2016-05-27
 *DESCRIPTION   : Initially pin numbers are allotted to the switch buttons and led's. Inbuilt LED at pin number 13 is used for this assignment. void setup() consists of declaration of output
 *                and input pins. The function LedTimeCondition() checks if the time specified is under control limits by using if conditional statement, and toggles the LED depending on the 
 *                time specified in the question.LedTimeCondition uses millis() function for toggling of the LED, which ensure that other processes can also take place when the LED is 
 *                blinking, if we use Delay() we cant really perform any other function because the program pauses our Arduiono .
 *                voidloop() consists of another conditional statement related to the attached switch, if the switch is LOW the on and off times are 100ms and 
 *                2s.And similarly if the switch is HIGH, on and off times are 100 ms and 200ms. These times are called as parameters of  the function , which is called inside the 
 *                conditional statements in voidloop()
 *                The fucntion in this file is usued to check if the time condition is satisfied, and blinking the LED accordingly using millis() function without pausing the Arduino.
 */


const int ledPinNumber = 13 ;                                                //Led pin number is declared as an constant because we are not going to change it

const int PushButtonPinNumber = 6;                                           // Switch/Push Button is attached to one of the several input pins and its is set as an constant

uint64_t previousmillis = 0 ;                                                // This stores the updated time for LED , due to which the millis() keeps on running.



void setup()
{
  pinMode (ledPinNumber, OUTPUT);                                             // ledPinNumber is declared as an output.
                                                                              //
  pinMode (PushButtonPinNumber, INPUT_PULLUP);                                // Push button pin number is declared as an INPUT_PULLUP as we want to use the resistor present 
                                                                              //  inside the teensey board.
                                                                              //
}

//
//FUNCTION    : LedTimeCondition
//DESCRIPTION : 
//              This function uses conditional statement to check if the specified On and Off time are between thes specified  time limits. If the condition is true, the flow of the code
//              moves to the next line. A variable currentmillis is used to store the value of the millis timer.Another conditional statemet is declared so that the LED keeps on blinking
//              without stopping the Arduino. The first if statement checks if the LED is HIGH and if the difference of millis timer is equal to or greater than the specified ON time, if 
//              the answer is 'YES' it turns the LED off  and updates the value of Previousmillis varialble to the currentmillis.This way a constant note on difference of time can be tracked
//              and LED can be turned on or off respectively.The 'elseif statements checks if the LED is off and if the time condition is satisfied, it turns the LED on and updates the value
//              of previousmillis variable.The blinking if LED is carried out with the help of millis             
//               The blinking if LED is carried out with the help of millis() function, which delays the LED to its ON and OFF time depending on the time specified and without
//               stopping the Arduino(which happens if we use delay() function) while calling te fuction in void loop().
//              while calling te fuction in void loop().
//PARAMETERS  : 
//             int16_t OnTime : Specified time during which the LED should remain ON
//             int16_t OffTime: Specified time during which the LED should remain OFF
//RETURNS     : This Function is not returning any value.


int32_t LedTimeCondition(int16_t OnTime, int16_t OffTime)
{

  if (OnTime >= 100 && OnTime <= 2000 && OffTime >= 100 && OffTime <= 2000)
  {

    uint64_t currentmillis = millis();

    if ( digitalRead(ledPinNumber) == HIGH && currentmillis - previousmillis >= OnTime) // high
    {
      digitalWrite (ledPinNumber, LOW);
      previousmillis = currentmillis ; //

    }


    else if (digitalRead(ledPinNumber) == LOW && currentmillis - previousmillis >= OffTime)
    {
      digitalWrite(ledPinNumber, HIGH);
      previousmillis=currentmillis ;
    }
  }

}

void loop()
{
  if (digitalRead (PushButtonPinNumber) == LOW) 
  {

    LedTimeCondition(100, 200);


  }
  else
  {
    LedTimeCondition(100, 2000);

  }
}
