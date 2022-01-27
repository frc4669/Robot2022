// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Shift.h"

Shift::Shift(Drivetrain* drivetrain) {
  // Use AddRequirements() here to declare subsystem dependencies.
  AddRequirements({ drivetrain });
  drive = drivetrain;
}

// Called when the command is initially scheduled.
void Shift::Initialize() {
  drive->ShiftGear();
}

// Called repeatedly when this Command is scheduled to run
void Shift::Execute() {
}

// Called once the command ends or is interrupted.
void Shift::End(bool interrupted) {}

// Returns true when the command should end.
bool Shift::IsFinished() {
  return true;
}
