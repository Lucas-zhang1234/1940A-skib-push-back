#include "helpers.hpp"
#include "pros/rtos.hpp"
#include "robot.hpp"

void colourSort() {
    pros::Task sortTask([&]()->void {
        while (true) {
            if (SkIbIdI_oPtIcAl.get_hue() > 90 && SkIbIdI_oPtIcAl.get_proximity() > 128) {
                Switcheroo.retract();
                pros::delay(50);
                Switcheroo.extend();
            }

            pros::delay(10);
        }
    });
}