// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/ExtendArms.h"

ExtendArms::ExtendArms(Climber* climber, bool isRaising) {
  AddRequirements( {climber} );
  this->climber = climber;
  this->isRaising = isRaising;
}

// Called when the command is initially scheduled.
void ExtendArms::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ExtendArms::Execute() {
  if(isRaising)
    climber->RaiseExtendingArms();
  else
    climber->LowerExtendingArms();
}

// Called once the command ends or is interrupted.
void ExtendArms::End(bool interrupted) {
  climber->StopExtendingArms();
}

// Returns true when the command should end.
bool ExtendArms::IsFinished() {
  return false;
}