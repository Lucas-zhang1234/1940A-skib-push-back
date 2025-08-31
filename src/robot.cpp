#include "robot.hpp"

pros::Controller master(pros::E_CONTROLLER_MASTER);
pros::Controller partner(pros::E_CONTROLLER_PARTNER);

pros::MotorGroup left_mg({-3, -4, -5});    
pros::MotorGroup right_mg({9, 7, 6});

lemlib::Drivetrain drivetrain(&left_mg, &right_mg,
                              12.625, // track width in inches
                              lemlib:: Omniwheel:: NEW_325, // Wheel configuration
                              450, // RPM
                              2 // Drift was 2  0.5
);

pros::Imu imu(8); 

pros::Rotation horizontalRotation(20); 
pros::Rotation verticallRotation(11); 

lemlib::TrackingWheel horizontal_tracking_wheel(&horizontalRotation, lemlib::Omniwheel::NEW_2, 3.5);
lemlib::TrackingWheel vertical_tracking_wheel(&verticallRotation, lemlib::Omniwheel::NEW_2, 3);


lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            &horizontal_tracking_wheel, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);


// lateral PID controller
lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              25 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(6, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              45, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in degrees
                                              100, // small error range timeout, in milliseconds
                                              1, // large error range, in degrees
                                              500, // large error range timeout, in milliseconds
                                              0 // maximum acceleration (slew)
);

// create the chassis
lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        lateral_controller, // lateral PID settings
                        angular_controller, // angular PID settings
                        sensors // odometry sensors
);


pros::Motor Bottom_Skibidi_Roller(1, pros::v5::MotorGears::blue);
pros::Motor Top_Skibidi_Roller(12, pros::v5::MotorGears::green);
pros::Motor Inside_Skibidi_Roller(19, pros::v5::MotorGears::green);


pros::adi::Pneumatics SkiBidi_Bucket({22, 'h'}, false);            // Starts retracted, extends when the ADI port is high
pros::adi::Pneumatics SkiBidi_Switcheroo({22, 'g'}, false);
pros::adi::Pneumatics SkiBidi_Matchloader({22, 'f'}, false);
