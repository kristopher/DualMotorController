#include "WConstants.h"
#include "DualMotorController.h"

DualMotorController::DualMotorController(AF_DCMotor *left_motor, AF_DCMotor *right_motor) {
  _left_motor = left_motor;
  _right_motor = right_motor;
  speed = 0;
  _forward = 1;
  current_direction = &DualMotorController::straight;
}

void DualMotorController::left() {
  if (_forward) {
    _left_motor->run(FORWARD);
    _right_motor->run(BACKWARD);
  } else {
    _left_motor->run(BACKWARD);
    _right_motor->run(FORWARD);
  }
  current_direction = &DualMotorController::left;
}

void DualMotorController::right() {
  if (_forward) {
    _left_motor->run(BACKWARD);
    _right_motor->run(FORWARD);
  } else {
    _left_motor->run(FORWARD);
    _right_motor->run(BACKWARD);
  }
  current_direction = &DualMotorController::right;
}

void DualMotorController::straight() {
  if (_forward) {
    _left_motor->run(FORWARD);
    _right_motor->run(FORWARD);
  } else {
    _left_motor->run(BACKWARD);
    _right_motor->run(BACKWARD);
  }
  current_direction = &DualMotorController::straight;
}

void DualMotorController::stop() {
  _left_motor->run(RELEASE);
  _right_motor->run(RELEASE);
  speed = 0;  
  current_direction = &DualMotorController::stop;
}

void DualMotorController::forward() {
  _forward = 1;
  (this->*current_direction)();
}

void DualMotorController::reverse() {
  _forward = 0;
  (this->*current_direction)();
}

void DualMotorController::setSpeed(int new_speed) {
  speed = new_speed;
  _left_motor->setSpeed(speed);
  _right_motor->setSpeed(speed);
}

int DualMotorController::isReversing() {
  return (_forward == 0);
}

void DualMotorController::reset() {
  current_direction = &DualMotorController::straight;
  _forward = 1;
  speed = 0;
}
