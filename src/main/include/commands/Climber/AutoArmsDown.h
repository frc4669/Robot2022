// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <subsystems/Climber.h>

class AutoArmsDown : public frc2::CommandHelper<frc2::CommandBase, AutoArmsDown> {
 public:
  /**
   * Lower the telescopic arms all the way.
   *
   * @param climber a Climber object pointer
   */
  AutoArmsDown(Climber* climber);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  Climber* climber;
};
