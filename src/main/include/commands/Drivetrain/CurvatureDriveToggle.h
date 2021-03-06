// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <subsystems/Drivetrain.h>

class CurvatureDriveToggle : public frc2::CommandHelper<frc2::CommandBase, CurvatureDriveToggle> {
 public:
  /**
   * Switches behaviour of the robot on whether it should be able to turn in place or not.
   *
   * @param drivetrain a Drivetrain object pointer
   */
  CurvatureDriveToggle(Drivetrain* drivetrain);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  Drivetrain* drivetrain;
};
