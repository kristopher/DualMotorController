#ifndef DualMotorController_h
#define DualMotorController_h
#include <../AFMotor/AFMotor.h>

class DualMotorController
{
  private:
    AF_DCMotor *_left_motor;
    AF_DCMotor *_right_motor;
    int speed;
    int _forward;
    void (DualMotorController::*current_direction)();
  public:
    DualMotorController(AF_DCMotor*, AF_DCMotor*);
    void left();
    void right();
    void straight();
    void stop();
    void forward();
    void reverse();
    void increaseSpeed();
    void decreaseSpeed();
    void setSpeed(int);
    int isReversing();
    void reset();
};

#endif

