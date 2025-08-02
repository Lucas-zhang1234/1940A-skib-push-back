#include "main.h"
#include "lemlib/api.hpp" // IWYU pragma: keep
#include "pros/misc.h"
#include "robot.hpp"


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	int isHighGoal = 127;
	while (true) {
		double forwards = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		double turn = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

		chassis.arcade(forwards, turn);

		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
			Bottom_Skibidi_Roller.move_voltage(12000);
		} else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
			Bottom_Skibidi_Roller.move_voltage(-12000);
		} else {
			Bottom_Skibidi_Roller.move(0);
		}	
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
			Top_Skibidi_Roller.move(isHighGoal);
		} else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
			Top_Skibidi_Roller.move(isHighGoal);
		} else {
			Top_Skibidi_Roller.move(0);
		}
		if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
			Inside_Skibidi_Roller.move(isHighGoal);
		} else if (master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
			Inside_Skibidi_Roller.move(isHighGoal);
		} else {
			Top_Skibidi_Roller.move(0);
		}

		if (partner.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)){
			isHighGoal *= -1;
		}
		if (partner.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)){
			SkiBidi_Bucket.toggle();
		}

		pros::delay(20);                               // Run for 20 ms then update
	}
}
