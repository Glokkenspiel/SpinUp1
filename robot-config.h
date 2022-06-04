using namespace vex;

extern brain Brain;

using signature = vision::signature;

// VEXcode devices
extern motor baseBL;
extern motor baseFL;
extern motor baseBR;
extern motor baseFR;
extern controller Controller1;
extern signature vRoller__RD;
extern signature vRoller__BLU;
extern signature vRoller__SIG_3;
extern signature vRoller__SIG_4;
extern signature vRoller__SIG_5;
extern signature vRoller__SIG_6;
extern signature vRoller__SIG_7;
extern vision vRoller;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );