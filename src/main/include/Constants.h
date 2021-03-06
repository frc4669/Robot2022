// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

//!: Don't import all of <units>, it slows compile time
#include <units/acceleration.h>
#include <units/angle.h>
#include <units/angular_velocity.h>
#include <units/constants.h>
#include <units/length.h>
#include <units/time.h>
#include <units/velocity.h>
#include <units/voltage.h>

//?: If you're asking why we use constexpr, it's because constexpr computes at compile time instead of run time, making it faster.

namespace VisionContants {
  constexpr units::meter_t kCameraHeight = 0_in;
  constexpr units::meter_t kHubHeight = 0_in;

  constexpr units::radian_t kCameraAngle = 45_deg;
  //constexpr auto kInchesHubHeight 10_in;
}  // namespace VisionContants

namespace ShooterConstants {
  // Shooter motor CAN IDs (NEOs)
  constexpr int kLeftMotorCAN = 46;
  constexpr int kRightMotorCAN = 47;

  // Shooter hood motor CAN ID (775Pro connected to a Talon SRX)
  constexpr int kHoodMotorCAN = 7;

  // Speeds for hood
  constexpr double kHoodSpeed = 0.2;  // Percentage of movement speed, where 1.0 = 100% motor throttle
}  // namespace ShooterConstants

namespace ClimbConstants {
  // Static climbing motor CAN IDs (Falcon FXs)
  constexpr int kStaticLeftCAN = 20;
  constexpr int kStaticRightCAN = 21;

  // Pivot climbing motor CAN IDs (Talon FXs)
  constexpr int kPivotLeftCAN = 31;
  constexpr int kPivotRightCAN = 30;

  // Speeds for climber
  constexpr double kStaticUpSpeed = -0.8;    // Percentage of movement speed, where 1.0 = 100% motor throttle
  constexpr double kStaticDownSpeed = 0.8;  // Percentage of movement speed, where 1.0 = 100% motor throttle

  constexpr double kPivotForwardSpeed = 0.10;   // Percentage of movement speed, where 1.0 = 100% motor throttle
  constexpr double kPivotBackwardSpeed = -0.10;  // Percentage of movement speed, where 1.0 = 100% motor throttle
}  // namespace ClimbConstants

namespace IntakeConstants {
  // Intake Talon SRX CAN IDs
  constexpr int kIntakeCAN = 11;       // the primary intake
  constexpr int kFeederCAN = 10;       // vertical feeder

  constexpr int kArmFwdChannel = 2;   // channel for extending intake arm
  constexpr int kArmRevChannel = 3;   // channel for retracting intake arm
}  // namespace IntakeConstants

namespace DriveConstants {
  // Drivetrain Talon FX CAN IDs
  constexpr int kLeftFrontCAN = 50;    // Leading left motor
  constexpr int kLeftBackCAN = 51;     // Following left motor

  constexpr int kRightFrontCAN = 52;   // Leading right motor
  constexpr int kRightBackCAN = 53;    // Following right motor

  // Drivetrain solenoid shifter pneumatic channels
  constexpr int kGearFwdChannel = 1;     // striped blue channel
  constexpr int kGearRevChannel = 0;     // unstriped blue channel

  constexpr auto ks = 1_V;
  constexpr auto kv = 0.8_V * 1_s / 1_m;
  constexpr auto ka = 0.15_V * 1_s * 1_s / 1_m;

  constexpr double kp = 1;

  constexpr auto kMaxSpeed = 3_mps;
  constexpr auto kMaxAcceleration = 3_mps_sq;

  constexpr double kTrackWidth = 18.0;      // Distance between left and right wheels in inches
}  // namespace DriveConstants

namespace DriveGearingConstants {
  constexpr double kWheelDiameter = 6;                  // Wheel diameter in inches
  constexpr double kTicksPerRev = 2048;                 // Ticks per revolution //?: specific to Falcon 500s
  constexpr double kWheelCirc = kWheelDiameter * units::constants::pi;   // Wheel circumference

  // Gear ratios; formula is (driven gear teeth / driving gear teeth) = gear ratio
  constexpr double kPrimaryRatio = (double) 30/11;      // 30 teeth driven by 11
  constexpr double kSecondaryRatio = (double) 44/30;    // 44 teeth driven by 30
  constexpr double kPreShiftRatio = kPrimaryRatio * kSecondaryRatio;

  // Shifter Rations with previous ratios
  constexpr double kShifterLowRatio = (double) 50/14;     // 50 teeth driven by 14
  constexpr double kShifterHighRatio = (double) 44/20;    // 44 teeth driven by 20
  constexpr double kLastRatio = (double) 40/34;    // 40 teeth driven by 34

  // Full ratios
  constexpr double kLowGearRato = kPreShiftRatio * kShifterLowRatio * kLastRatio;     // 16.80
  constexpr double kHighGearRatio = kPreShiftRatio * kShifterHighRatio * kLastRatio;  // 10.35

  // Low gear values (higher torque, lower speed) //?: can tell low gear bc more ticks per rev
  constexpr double kInchesPerTick_LowGear = kWheelCirc / (kTicksPerRev * kLowGearRato);
  constexpr double kTicksPerInch_LowGear = (kTicksPerRev * kLowGearRato) / kWheelCirc;  // 1826.04
  constexpr double kTicksPerRev_LowGear = kTicksPerRev * kLowGearRato; // 34420.16

  // High gear values (lower torque, higher speed) //?: can tell high gear bc less ticks per rev
  constexpr double kInchesPerTick_HighGear = kWheelCirc / (kTicksPerRev * kHighGearRatio);
  constexpr double kTicksPerInch_HighGear = (kTicksPerRev * kHighGearRatio) / kWheelCirc; // 1124.84
  constexpr double kTicksPerRev_HighGear = kTicksPerRev * kHighGearRatio; // 21202.82
}  // namespace DriveGearingConstants
