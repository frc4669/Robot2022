// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Intake.h"

#include <frc/smartdashboard/SmartDashboard.h>

Intake::Intake() {
  // Start robot with intake retracted
  m_intakeArm.Set(frc::DoubleSolenoid::kForward);
  m_intakeMotor.SetInverted(true);
}

// This method will be called once per scheduler run
void Intake::Periodic() {
  frc::SmartDashboard::PutBoolean("Intake Arm Deployed", IsArmExtended());
  frc::SmartDashboard::PutNumber("Intake Active Motor Velocity", GetIntakeVelocity());
  frc::SmartDashboard::PutNumber("Feeder Active Motor Velocity", GetFeederVelocity());

  frc::SmartDashboard::PutNumber("feeder ticks", GetFeederTicks());
}

void Intake::ManipulateArm() {
  if (IsArmExtended())
    m_intakeArm.Set(frc::DoubleSolenoid::kForward);
  else
    m_intakeArm.Set(frc::DoubleSolenoid::kReverse);

  kIntakeArmExtended = !kIntakeArmExtended;
}

bool Intake::IsArmExtended() {
  return kIntakeArmExtended;
}

void Intake::RunIntake(bool runReverse) {
  if(runReverse)
    m_intakeMotor.Set(ControlMode::PercentOutput, -kIntakeSpeedPercentage);
  else
    m_intakeMotor.Set(ControlMode::PercentOutput, kIntakeSpeedPercentage);
}

void Intake::StopIntake() {
  m_intakeMotor.Set(ControlMode::PercentOutput, 0);
}

void Intake::RunFeeder(bool runReverse) {
  if(runReverse)
    m_feederMotor.Set(ControlMode::PercentOutput, -kFeederSpeedPercentage);
  else
    m_feederMotor.Set(ControlMode::PercentOutput, kFeederSpeedPercentage);
}

void Intake::StopFeeder() {
  m_feederMotor.Set(ControlMode::PercentOutput, 0);
}

double Intake::GetIntakeVelocity() {
  return m_intakeMotor.GetSensorCollection().GetQuadratureVelocity();
}

double Intake::GetFeederVelocity() {
  return m_feederMotor.GetSensorCollection().GetQuadratureVelocity();
}

double Intake::GetFeederTicks() {
  return m_feederMotor.GetSensorCollection().GetQuadraturePosition();
}

void Intake::ResetFeederTicks() {
  m_feederMotor.GetSensorCollection().SetQuadraturePosition(0);
}
