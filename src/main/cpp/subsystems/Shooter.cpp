// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Shooter.h"
#include <frc/smartdashboard/SmartDashboard.h> // for debugging

Shooter::Shooter() {
  // Invert motors if needed
  m_leftShooterMotor.SetInverted(true);

  // Set slave motor to follow master motor
  m_rightShooterMotor.Follow(m_leftShooterMotor, true);

  m_masterPIDController.SetP(0.00);     // kP
  m_masterPIDController.SetD(0.00);     // kD
  m_masterPIDController.SetFF(0.0002);  // kFF

  // Setup hood motors
}

// This method will be called once per scheduler run
void Shooter::Periodic() {
  frc::SmartDashboard::PutNumber("Master Shooter Active Velocity", GetMasterShooterVelocity());
  frc::SmartDashboard::PutNumber("Slave Shooter Active Velocity", GetSlaveShooterVelocity());
  frc::SmartDashboard::PutNumber("Shooter Set Velocity", GetShooterSetSpeed());
}

void Shooter::RunShooter() {
  m_masterPIDController.SetReference(kShooterVelocity, rev::ControlType::kVelocity);
  //?: Slave shooter motor not set because it's already following the master motor
}

void Shooter::StopShooter() {
  m_masterPIDController.SetReference(0.0, rev::ControlType::kVelocity);
}

double Shooter::GetMasterShooterVelocity() {
  return m_masterEncoder.GetVelocity();
}

double Shooter::GetSlaveShooterVelocity() {
  return m_slaveEncoder.GetVelocity();
}


double Shooter::GetShooterSetSpeed() {
  return kShooterVelocity;
}

void Shooter::IncrementShooterSetSpeed(double increment) {
  kShooterVelocity += increment;
}