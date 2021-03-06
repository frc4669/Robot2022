// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Autonomous/RotateByAngle.h"

RotateByAngle::RotateByAngle(Drivetrain* drivetrain, double targetAngle) {
  AddRequirements( {drivetrain} );
  this->drivetrain = drivetrain;
  this->targetAngle = targetAngle;
}

// Called when the command is initially scheduled.
void RotateByAngle::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void RotateByAngle::Execute() {}

// Called once the command ends or is interrupted.
void RotateByAngle::End(bool interrupted) {}

// Returns true when the command should end.
bool RotateByAngle::IsFinished() {
  return false;
}
