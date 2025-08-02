#include "../include/main.h"
#include "lemlib/api.hpp"

extern pros::Controller master;
extern pros::Controller partner;

extern pros::MotorGroup left_mg;    
extern pros::MotorGroup right_mg;

extern lemlib::Drivetrain drivetrain;

extern pros::Imu imu;

extern pros:: Rotation horizontalRotation;
extern pros:: Rotation verticallRotation;

extern lemlib::TrackingWheel horizontalTrackingWheel;

extern lemlib::TrackingWheel verticalTrackingWheel;

extern lemlib::OdomSensors sensors;

extern lemlib::ControllerSettings lateral_controller;

extern lemlib::ControllerSettings angular_controller;

extern lemlib::Chassis chassis;

extern pros::Motor Bottom_Skibidi_Roller;
extern pros::Motor Top_Skibidi_Roller;
extern pros::Motor Inside_Skibidi_Roller;

extern pros::adi::Pneumatics SkiBidi_Bucket;
extern pros::adi::Pneumatics SkiBidi_Switcheroo;
extern pros::adi::Pneumatics SkiBidi_Matchloader;

