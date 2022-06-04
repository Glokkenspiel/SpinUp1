/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// baseBL               motor         1               
// baseFL               motor         2               
// baseBR               motor         3               
// baseFR               motor         4               
// Controller1          controller                    
// vRoller              vision        5               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

bool driveMode = 0;
bool buttonAPressing = 0;

int bluMiddle;
int rdMiddle;

competition Competition;

//Drive the base forward
void baseFWD(float speed){
  baseBL.spin(fwd, speed, percent);
  baseFL.spin(fwd, speed, percent);
  baseBR.spin(fwd, speed, percent);
  baseFR.spin(fwd, speed, percent);
}

//Drive the base backwards
void baseREV(float speed){
  baseBL.spin(reverse, speed, percent);
  baseFL.spin(reverse, speed, percent);
  baseBR.spin(reverse, speed, percent);
  baseFR.spin(reverse, speed, percent);
}

//Strafes the base left
void baseSRFl(float speed){
  baseBL.spin(fwd, speed, percent);
  baseFL.spin(reverse, speed, percent);
  baseBR.spin(fwd, speed, percent);
  baseFR.spin(reverse, speed, percent);
}

//Strafes the base right
void baseSRFr(float speed){
  baseBL.spin(reverse, speed, percent);
  baseFL.spin(fwd, speed, percent);
  baseBR.spin(reverse, speed, percent);
  baseFR.spin(fwd, speed, percent);
}

//Turns the base left
void baseTRNl(float speed){
  baseBL.spin(reverse, speed, percent);
  baseFL.spin(reverse, speed, percent);
  baseBR.spin(fwd, speed, percent);
  baseFR.spin(fwd, speed, percent);
}

//Turns the base right
void baseTRNr(float speed){
  baseBL.spin(fwd, speed, percent);
  baseFL.spin(fwd, speed, percent);
  baseBR.spin(reverse, speed, percent);
  baseFR.spin(reverse, speed, percent);
}

void fixRoller(){
  vRoller.takeSnapshot(vRoller__BLU);
  bluMiddle = vRoller.objects[0].centerY;
  vRoller.takeSnapshot(vRoller__RD);
  rdMiddle = vRoller.objects[0].centerY;
}

void pre_auton(void) {
  vexcodeInit();
}

void autonomous(void) {
}

void usercontrol(void) {
  while (1) {

    if(Controller1.ButtonA.pressing()){
      if(buttonAPressing == 0){
        buttonAPressing = 1;
        if(driveMode == 0){
          driveMode = 1;
        }else{
          driveMode = 0;
        }
      }
    }else{
      buttonAPressing = 0;
    }
    Controller1.Screen.clearScreen();
    Controller1.Screen.setCursor(1, 1);

    //Drives the base 
    if(driveMode == 1){
      baseBL.spin(fwd, Controller1.Axis3.position(percent)-Controller1.Axis4.position(percent)+(.75*Controller1.Axis1.position(percent)), percent);
      baseFL.spin(fwd, Controller1.Axis3.position(percent)+Controller1.Axis4.position(percent)+(.75*Controller1.Axis1.position(percent)), percent);
      baseBR.spin(fwd, Controller1.Axis3.position(percent)+Controller1.Axis4.position(percent)-(.75*Controller1.Axis1.position(percent)), percent);
      baseFR.spin(fwd, Controller1.Axis3.position(percent)-Controller1.Axis4.position(percent)-(.75*Controller1.Axis1.position(percent)), percent);
      Controller1.Screen.print("HOLONOMIC");
    }else{
      baseBL.spin(fwd, Controller1.Axis3.position(percent)+(.75*Controller1.Axis1.position(percent)), percent);
      baseFL.spin(fwd, Controller1.Axis3.position(percent)+(.75*Controller1.Axis1.position(percent)), percent);
      baseBR.spin(fwd, Controller1.Axis3.position(percent)-(.75*Controller1.Axis1.position(percent)), percent);
      baseFR.spin(fwd, Controller1.Axis3.position(percent)-(.75*Controller1.Axis1.position(percent)), percent);
      Controller1.Screen.print("H-BASE");
    }
    wait(20, msec);
  }
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}
