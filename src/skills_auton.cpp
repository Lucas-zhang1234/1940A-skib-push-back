#include "skills_auton.h"
#include "lemlib/asset.hpp"
#include "robot.hpp"

void skills_auton() {
    Bucket_Base.extend();
    chassis.setPose(-62.87, 15.447, 180);
    pros::delay(200);
    chassis.moveToPoint(-62.87, -8.335, 3000);
}