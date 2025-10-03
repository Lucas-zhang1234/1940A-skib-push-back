#include "auton.h"
#include "lemlib/asset.hpp"
#include "pros/rtos.hpp"
#include "robot.hpp"
#include "skills_auton.h"

ASSET(path1_txt);
ASSET(path3_txt);
ASSET(testpath_txt);

int x_modifier = 1;
int y_modifier = 1;
int heading_modifier = 1;

// TODO: Fix math
int get_heading(int base)
{
    if (heading_modifier == 1) return base;
    else if (heading_modifier == -1) return (180 - base) % 360;
    else if (heading_modifier == 2) return (360 - base) % 360;
    else return (180 - ((360 - base) % 360)) % 360;
}

void auton(int autonToRun) {
    switch (autonToRun) {
        // skills
        case 0:
            skills_auton();
            break;
        // top left
        case 1:
            init(1, 1, 1);
            break;
        // bottom left
        case 2:
            init(1, -1, -1);
            break;
        // top right
        case 3:
            init(-1, 1, 0);
            break;
        // bottom right
        case 4:
            init(-1, -1, 2);
            break;
    }

    if (autonToRun != 0) run();
};

void init(int x, int y, int h)
{
    x_modifier = 1;
    y_modifier = 1;
    heading_modifier = 1;
}

void run()
{
    // Initialise
    chassis.setPose(-50.425 * x_modifier, 16.29 * y_modifier, get_heading(0));
    Bottom_Roller.move(-12000);
    Top_Roller.move(12000);
    Switcheroo.retract();

    // Move to matchloader
    chassis.moveToPose(-47 * x_modifier, 48 * y_modifier, get_heading(0), 1000);
    chassis.turnToHeading(get_heading(270), 1000);
    chassis.waitUntilDone();

    // Collect blocks from matchloader
    Matchloader.extend();
    chassis.moveToPose(-64 * x_modifier, 44 * y_modifier, get_heading(270), 1500);
    for (int i = 0; i < 3; i++) {
        chassis.moveToPoint(-67.5 * x_modifier, 44 * y_modifier, 450);
        chassis.moveToPoint(-64 * x_modifier, 44 * y_modifier, 450);
    }
 
    // Move to long goal
    chassis.moveToPoint(-58 * x_modifier, 45 * y_modifier, 1000);
    chassis.waitUntilDone();
    Matchloader.retract();
    pros::delay(100);
    chassis.turnToHeading(90, 1000, {.minSpeed = 70});
    chassis.moveToPose(-31.5 * x_modifier, 45 * y_modifier, get_heading(90), 1000, {.maxSpeed = 80});
    chassis.waitUntilDone();

    // Score all 4 blocks in the long goal
    Switcheroo.extend();
    Bottom_Roller.move(-12000);
    Top_Roller.move(12000);
    Inside_Roller.move(-12000);
    pros::delay(2800);

    // Move back slightly
    chassis.moveToPoint(-60 * x_modifier, 44 * y_modifier, 1000, {.forwards=false});
    chassis.turnToHeading(get_heading(135), 500);
    Top_Roller.move_velocity(-50);
    Switcheroo.toggle();
    chassis.moveToPoint(-25 * x_modifier, 9 * y_modifier,2000, {.maxSpeed = 100});
    

    //  chassis.moveToPose(-22.73, 23.44, 64, 2000);
    //  chassis.turnToHeading(135, 2000);
    //  Matchloader.extend();
    //  chassis.moveToPose(-13, 13, 135,  1000);
    //  Top_Roller.move(-12000);
    //  Inside_Roller.move(-12000);
    
}