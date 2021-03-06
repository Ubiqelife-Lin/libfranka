// Copyright (c) 2017 Franka Emika GmbH
// Use of this source code is governed by the Apache-2.0 license, see LICENSE
#include "helpers.h"

#include <cstdlib>

#include <gtest/gtest.h>

bool stringContains(const std::string& actual, const std::string& expected) {
  return actual.find(expected) != std::string::npos;
}

void testRobotStateIsZero(const franka::RobotState& actual) {
  for (size_t i = 0; i < actual.O_T_EE.size(); i++) {
    EXPECT_EQ(0.0, actual.O_T_EE[i]);
  }
  for (size_t i = 0; i < actual.O_T_EE_d.size(); i++) {
    EXPECT_EQ(0.0, actual.O_T_EE_d[i]);
  }
  for (size_t i = 0; i < actual.EE_T_K.size(); i++) {
    EXPECT_EQ(0.0, actual.EE_T_K[i]);
  }
  for (size_t i = 0; i < actual.F_T_EE.size(); i++) {
    EXPECT_EQ(0.0, actual.F_T_EE[i]);
  }
  EXPECT_EQ(0.0, actual.m_load);
  for (size_t i = 0; i < actual.F_x_Cload.size(); i++) {
    EXPECT_EQ(0.0, actual.F_x_Cload[i]);
  }
  for (size_t i = 0; i < actual.I_load.size(); i++) {
    EXPECT_EQ(0.0, actual.I_load[i]);
  }
  for (size_t i = 0; i < actual.elbow.size(); i++) {
    EXPECT_EQ(0.0, actual.elbow[i]);
  }
  for (size_t i = 0; i < actual.elbow_d.size(); i++) {
    EXPECT_EQ(0.0, actual.elbow_d[i]);
  }
  for (size_t i = 0; i < actual.tau_J.size(); i++) {
    EXPECT_EQ(0.0, actual.tau_J[i]);
  }
  for (size_t i = 0; i < actual.dtau_J.size(); i++) {
    EXPECT_EQ(0.0, actual.dtau_J[i]);
  }
  for (size_t i = 0; i < actual.q.size(); i++) {
    EXPECT_EQ(0.0, actual.q[i]);
  }
  for (size_t i = 0; i < actual.dq.size(); i++) {
    EXPECT_EQ(0.0, actual.dq[i]);
  }
  for (size_t i = 0; i < actual.q_d.size(); i++) {
    EXPECT_EQ(0.0, actual.q_d[i]);
  }
  for (size_t i = 0; i < actual.dq_d.size(); i++) {
    EXPECT_EQ(0.0, actual.dq_d[i]);
  }
  for (size_t i = 0; i < actual.joint_contact.size(); i++) {
    EXPECT_EQ(0.0, actual.joint_contact[i]);
  }
  for (size_t i = 0; i < actual.cartesian_contact.size(); i++) {
    EXPECT_EQ(0.0, actual.cartesian_contact[i]);
  }
  for (size_t i = 0; i < actual.joint_collision.size(); i++) {
    EXPECT_EQ(0.0, actual.joint_collision[i]);
  }
  for (size_t i = 0; i < actual.cartesian_collision.size(); i++) {
    EXPECT_EQ(0.0, actual.cartesian_collision[i]);
  }
  for (size_t i = 0; i < actual.tau_ext_hat_filtered.size(); i++) {
    EXPECT_EQ(0.0, actual.tau_ext_hat_filtered[i]);
  }
  for (size_t i = 0; i < actual.O_F_ext_hat_K.size(); i++) {
    EXPECT_EQ(0.0, actual.O_F_ext_hat_K[i]);
  }
  for (size_t i = 0; i < actual.K_F_ext_hat_K.size(); i++) {
    EXPECT_EQ(0.0, actual.K_F_ext_hat_K[i]);
  }
  EXPECT_FALSE(actual.current_errors);
  EXPECT_FALSE(actual.last_motion_errors);
  EXPECT_EQ(0u, actual.time.toMSec());
  EXPECT_EQ(0.0, actual.control_command_success_rate);
}

void testRobotStatesAreEqual(const franka::RobotState& expected, const franka::RobotState& actual) {
  EXPECT_EQ(expected.O_T_EE, actual.O_T_EE);
  EXPECT_EQ(expected.O_T_EE_d, actual.O_T_EE_d);
  EXPECT_EQ(expected.F_T_EE, actual.F_T_EE);
  EXPECT_EQ(expected.EE_T_K, actual.EE_T_K);
  EXPECT_EQ(expected.m_load, actual.m_load);
  EXPECT_EQ(expected.F_x_Cload, actual.F_x_Cload);
  EXPECT_EQ(expected.I_load, actual.I_load);
  EXPECT_EQ(expected.elbow, actual.elbow);
  EXPECT_EQ(expected.elbow_d, actual.elbow_d);
  EXPECT_EQ(expected.tau_J, actual.tau_J);
  EXPECT_EQ(expected.dtau_J, actual.dtau_J);
  EXPECT_EQ(expected.q, actual.q);
  EXPECT_EQ(expected.dq, actual.dq);
  EXPECT_EQ(expected.q_d, actual.q_d);
  EXPECT_EQ(expected.dq_d, actual.dq_d);
  EXPECT_EQ(expected.joint_contact, actual.joint_contact);
  EXPECT_EQ(expected.cartesian_contact, actual.cartesian_contact);
  EXPECT_EQ(expected.joint_collision, actual.joint_collision);
  EXPECT_EQ(expected.cartesian_collision, actual.cartesian_collision);
  EXPECT_EQ(expected.tau_ext_hat_filtered, actual.tau_ext_hat_filtered);
  EXPECT_EQ(expected.O_F_ext_hat_K, actual.O_F_ext_hat_K);
  EXPECT_EQ(expected.K_F_ext_hat_K, actual.K_F_ext_hat_K);
  EXPECT_EQ(expected.current_errors, actual.current_errors);
  EXPECT_EQ(expected.last_motion_errors, actual.last_motion_errors);
  EXPECT_EQ(expected.control_command_success_rate, actual.control_command_success_rate);
  EXPECT_EQ(expected.robot_mode, actual.robot_mode);
  EXPECT_EQ(expected.time, actual.time);
}

void testRobotStatesAreEqual(const research_interface::robot::RobotState& expected,
                             const franka::RobotState& actual) {
  EXPECT_EQ(expected.O_T_EE, actual.O_T_EE);
  EXPECT_EQ(expected.O_T_EE_d, actual.O_T_EE_d);
  EXPECT_EQ(expected.F_T_EE, actual.F_T_EE);
  EXPECT_EQ(expected.EE_T_K, actual.EE_T_K);
  EXPECT_EQ(expected.m_load, actual.m_load);
  EXPECT_EQ(expected.F_x_Cload, actual.F_x_Cload);
  EXPECT_EQ(expected.I_load, actual.I_load);
  EXPECT_EQ(expected.elbow, actual.elbow);
  EXPECT_EQ(expected.elbow_d, actual.elbow_d);
  EXPECT_EQ(expected.tau_J, actual.tau_J);
  EXPECT_EQ(expected.dtau_J, actual.dtau_J);
  EXPECT_EQ(expected.q, actual.q);
  EXPECT_EQ(expected.dq, actual.dq);
  EXPECT_EQ(expected.q_d, actual.q_d);
  EXPECT_EQ(expected.dq_d, actual.dq_d);
  EXPECT_EQ(expected.joint_contact, actual.joint_contact);
  EXPECT_EQ(expected.cartesian_contact, actual.cartesian_contact);
  EXPECT_EQ(expected.joint_collision, actual.joint_collision);
  EXPECT_EQ(expected.cartesian_collision, actual.cartesian_collision);
  EXPECT_EQ(expected.tau_ext_hat_filtered, actual.tau_ext_hat_filtered);
  EXPECT_EQ(expected.O_F_ext_hat_K, actual.O_F_ext_hat_K);
  EXPECT_EQ(expected.K_F_ext_hat_K, actual.K_F_ext_hat_K);
  EXPECT_EQ(franka::Errors(expected.errors), actual.current_errors);
  EXPECT_EQ(franka::Errors(expected.reflex_reason), actual.last_motion_errors);
  EXPECT_EQ(expected.message_id, actual.time.toMSec());
  EXPECT_EQ(expected.control_command_success_rate, actual.control_command_success_rate);

  franka::RobotMode expected_robot_mode;
  switch (expected.robot_mode) {
    case research_interface::robot::RobotMode::kOther:
      expected_robot_mode = franka::RobotMode::kOther;
      break;
    case research_interface::robot::RobotMode::kIdle:
      expected_robot_mode = franka::RobotMode::kIdle;
      break;
    case research_interface::robot::RobotMode::kMove:
      expected_robot_mode = franka::RobotMode::kMove;
      break;
    case research_interface::robot::RobotMode::kGuiding:
      expected_robot_mode = franka::RobotMode::kGuiding;
      break;
    case research_interface::robot::RobotMode::kReflex:
      expected_robot_mode = franka::RobotMode::kReflex;
      break;
    case research_interface::robot::RobotMode::kUserStopped:
      expected_robot_mode = franka::RobotMode::kUserStopped;
      break;
    case research_interface::robot::RobotMode::kAutomaticErrorRecovery:
      expected_robot_mode = franka::RobotMode::kAutomaticErrorRecovery;
      break;
  }
  EXPECT_EQ(expected_robot_mode, actual.robot_mode);
}

double randomDouble() {
  return 10.0 * static_cast<double>(std::rand()) / RAND_MAX;
}

bool randomBool() {
  return static_cast<bool>(std::rand() % 2);
}

void randomRobotState(franka::RobotState& robot_state) {
  for (double& element : robot_state.O_T_EE) {
    element = randomDouble();
  }
  for (double& element : robot_state.O_T_EE_d) {
    element = randomDouble();
  }
  for (double& element : robot_state.EE_T_K) {
    element = randomDouble();
  }
  for (double& element : robot_state.F_T_EE) {
    element = randomDouble();
  }
  robot_state.m_load = randomDouble();
  for (double& element : robot_state.F_x_Cload) {
    element = randomDouble();
  }
  for (double& element : robot_state.I_load) {
    element = randomDouble();
  }
  for (double& element : robot_state.elbow) {
    element = randomDouble();
  }
  for (double& element : robot_state.elbow_d) {
    element = randomDouble();
  }
  for (double& element : robot_state.tau_J) {
    element = randomDouble();
  }
  for (double& element : robot_state.dtau_J) {
    element = randomDouble();
  }
  for (double& element : robot_state.q) {
    element = randomDouble();
  }
  for (double& element : robot_state.dq) {
    element = randomDouble();
  }
  for (double& element : robot_state.q_d) {
    element = randomDouble();
  }
  for (double& element : robot_state.dq_d) {
    element = randomDouble();
  }
  for (double& element : robot_state.joint_contact) {
    element = randomDouble();
  }
  for (double& element : robot_state.cartesian_contact) {
    element = randomDouble();
  }
  for (double& element : robot_state.joint_collision) {
    element = randomDouble();
  }
  for (double& element : robot_state.cartesian_collision) {
    element = randomDouble();
  }
  for (double& element : robot_state.tau_ext_hat_filtered) {
    element = randomDouble();
  }
  for (double& element : robot_state.O_F_ext_hat_K) {
    element = randomDouble();
  }
  for (double& element : robot_state.K_F_ext_hat_K) {
    element = randomDouble();
  }
  std::array<bool, sizeof(research_interface::robot::RobotState::errors)> errors{};
  for (bool& error : errors) {
    error = randomBool();
  }
  robot_state.current_errors = franka::Errors(errors);
  for (bool& error : errors) {
    error = randomBool();
  }
  robot_state.last_motion_errors = franka::Errors(errors);
  robot_state.control_command_success_rate = randomDouble();
  robot_state.time = franka::Duration(static_cast<uint64_t>(std::rand()));
}

void randomRobotState(research_interface::robot::RobotState& robot_state) {
  // Reset to all-zeros first
  robot_state = research_interface::robot::RobotState();
  for (double& element : robot_state.O_T_EE) {
    element = randomDouble();
  }
  for (double& element : robot_state.O_T_EE_d) {
    element = randomDouble();
  }
  for (double& element : robot_state.EE_T_K) {
    element = randomDouble();
  }
  for (double& element : robot_state.F_T_EE) {
    element = randomDouble();
  }
  robot_state.m_load = randomDouble();
  for (double& element : robot_state.F_x_Cload) {
    element = randomDouble();
  }
  for (double& element : robot_state.I_load) {
    element = randomDouble();
  }
  for (double& element : robot_state.elbow) {
    element = randomDouble();
  }
  for (double& element : robot_state.elbow_d) {
    element = randomDouble();
  }
  for (double& element : robot_state.tau_J) {
    element = randomDouble();
  }
  for (double& element : robot_state.dtau_J) {
    element = randomDouble();
  }
  for (double& element : robot_state.q) {
    element = randomDouble();
  }
  for (double& element : robot_state.dq) {
    element = randomDouble();
  }
  for (double& element : robot_state.q_d) {
    element = randomDouble();
  }
  for (double& element : robot_state.dq_d) {
    element = randomDouble();
  }
  for (double& element : robot_state.joint_contact) {
    element = randomDouble();
  }
  for (double& element : robot_state.cartesian_contact) {
    element = randomDouble();
  }
  for (double& element : robot_state.joint_collision) {
    element = randomDouble();
  }
  for (double& element : robot_state.cartesian_collision) {
    element = randomDouble();
  }
  for (double& element : robot_state.tau_ext_hat_filtered) {
    element = randomDouble();
  }
  for (double& element : robot_state.O_F_ext_hat_K) {
    element = randomDouble();
  }
  for (double& element : robot_state.K_F_ext_hat_K) {
    element = randomDouble();
  }
  for (bool& error : robot_state.errors) {
    error = randomBool();
  }
  for (bool& element : robot_state.reflex_reason) {
    element = randomBool();
  }
  robot_state.message_id = static_cast<uint32_t>(std::rand());
  robot_state.control_command_success_rate = randomDouble();
  robot_state.motion_generator_mode = research_interface::robot::MotionGeneratorMode::kIdle;
  robot_state.controller_mode = research_interface::robot::ControllerMode::kJointImpedance;
}

void randomRobotCommand(research_interface::robot::RobotCommand& robot_command) {
  // Reset to all-zeros first
  robot_command = research_interface::robot::RobotCommand();
  for (double& element : robot_command.motion.q_d) {
    element = randomDouble();
  }
  for (double& element : robot_command.motion.dq_d) {
    element = randomDouble();
  }
  for (double& element : robot_command.motion.O_T_EE_d) {
    element = randomDouble();
  }
  for (double& element : robot_command.motion.O_dP_EE_d) {
    element = randomDouble();
  }
  for (double& element : robot_command.motion.elbow_d) {
    element = randomDouble();
  }
  robot_command.motion.valid_elbow = true;
  robot_command.motion.motion_generation_finished = true;
  for (double& element : robot_command.control.tau_J_d) {
    element = randomDouble();
  }
  robot_command.message_id = static_cast<uint32_t>(std::rand());
}

void testMotionGeneratorCommandsAreEqual(
    const research_interface::robot::MotionGeneratorCommand& expected,
    const research_interface::robot::MotionGeneratorCommand& actual) {
  EXPECT_EQ(expected.q_d, actual.q_d);
  EXPECT_EQ(expected.dq_d, actual.dq_d);
  EXPECT_EQ(expected.O_T_EE_d, actual.O_T_EE_d);
  EXPECT_EQ(expected.O_dP_EE_d, actual.O_dP_EE_d);
  EXPECT_EQ(expected.elbow_d, actual.elbow_d);
  EXPECT_EQ(expected.valid_elbow, actual.valid_elbow);
  EXPECT_EQ(expected.motion_generation_finished, actual.motion_generation_finished);
}

void testControllerCommandsAreEqual(const research_interface::robot::ControllerCommand& expected,
                                    const research_interface::robot::ControllerCommand& actual) {
  EXPECT_EQ(expected.tau_J_d, actual.tau_J_d);
}

void randomGripperState(franka::GripperState& gripper_state) {
  gripper_state.time = franka::Duration(static_cast<uint64_t>(std::rand()));
  gripper_state.temperature = static_cast<uint16_t>(std::rand());
  gripper_state.is_grasped = randomBool();
  gripper_state.max_width = randomDouble();
  gripper_state.width = randomDouble();
}

void randomGripperState(research_interface::gripper::GripperState& gripper_state) {
  // Reset to all-zeros first
  gripper_state = research_interface::gripper::GripperState();
  gripper_state.message_id = static_cast<uint32_t>(std::rand());
  gripper_state.temperature = static_cast<uint16_t>(std::rand());
  gripper_state.is_grasped = randomBool();
  gripper_state.max_width = randomDouble();
  gripper_state.width = randomDouble();
}

void testGripperStatesAreEqual(const franka::GripperState& expected,
                               const franka::GripperState& actual) {
  EXPECT_EQ(expected.time, actual.time);
  EXPECT_EQ(expected.width, actual.width);
  EXPECT_EQ(expected.max_width, actual.max_width);
  EXPECT_EQ(expected.is_grasped, actual.is_grasped);
  EXPECT_EQ(expected.temperature, actual.temperature);
}

void testGripperStatesAreEqual(const research_interface::gripper::GripperState& expected,
                               const franka::GripperState& actual) {
  EXPECT_EQ(expected.message_id, actual.time.toMSec());
  EXPECT_EQ(expected.width, actual.width);
  EXPECT_EQ(expected.max_width, actual.max_width);
  EXPECT_EQ(expected.is_grasped, actual.is_grasped);
  EXPECT_EQ(expected.temperature, actual.temperature);
}

namespace research_interface {
namespace robot {

bool operator==(const Move::Deviation& left, const Move::Deviation& right) {
  return left.translation == right.translation && left.rotation == right.rotation &&
         left.elbow == right.elbow;
}

}  // namespace robot
}  // namespace research_interface

namespace franka {

bool operator==(const Errors& lhs, const Errors& rhs) {
  return lhs.joint_position_limits_violation == rhs.joint_position_limits_violation &&
         lhs.cartesian_position_limits_violation == rhs.cartesian_position_limits_violation &&
         lhs.self_collision_avoidance_violation == rhs.self_collision_avoidance_violation &&
         lhs.joint_velocity_violation == rhs.joint_velocity_violation &&
         lhs.cartesian_velocity_violation == rhs.cartesian_velocity_violation &&
         lhs.force_control_safety_violation == rhs.force_control_safety_violation &&
         lhs.joint_reflex == rhs.joint_reflex && lhs.cartesian_reflex == rhs.cartesian_reflex &&
         lhs.max_goal_pose_deviation_violation == rhs.max_goal_pose_deviation_violation &&
         lhs.max_path_pose_deviation_violation == rhs.max_path_pose_deviation_violation &&
         lhs.cartesian_velocity_profile_safety_violation ==
             rhs.cartesian_velocity_profile_safety_violation &&
         lhs.joint_position_motion_generator_start_pose_invalid ==
             rhs.joint_position_motion_generator_start_pose_invalid &&
         lhs.joint_motion_generator_position_limits_violation ==
             rhs.joint_motion_generator_position_limits_violation &&
         lhs.joint_motion_generator_velocity_limits_violation ==
             rhs.joint_motion_generator_velocity_limits_violation &&
         lhs.joint_motion_generator_velocity_discontinuity ==
             rhs.joint_motion_generator_velocity_discontinuity &&
         lhs.joint_motion_generator_acceleration_discontinuity ==
             rhs.joint_motion_generator_acceleration_discontinuity &&
         lhs.cartesian_position_motion_generator_start_pose_invalid ==
             rhs.cartesian_position_motion_generator_start_pose_invalid &&
         lhs.cartesian_motion_generator_elbow_limit_violation ==
             rhs.cartesian_motion_generator_elbow_limit_violation &&
         lhs.cartesian_motion_generator_velocity_limits_violation ==
             rhs.cartesian_motion_generator_velocity_limits_violation &&
         lhs.cartesian_motion_generator_velocity_discontinuity ==
             rhs.cartesian_motion_generator_velocity_discontinuity &&
         lhs.cartesian_motion_generator_acceleration_discontinuity ==
             rhs.cartesian_motion_generator_acceleration_discontinuity &&
         lhs.cartesian_motion_generator_elbow_sign_inconsistent ==
             rhs.cartesian_motion_generator_elbow_sign_inconsistent &&
         lhs.cartesian_motion_generator_start_elbow_invalid ==
             rhs.cartesian_motion_generator_start_elbow_invalid &&
         lhs.cartesian_motion_generator_joint_position_limits_violation ==
             rhs.cartesian_motion_generator_joint_position_limits_violation &&
         lhs.cartesian_motion_generator_joint_velocity_limits_violation ==
             rhs.cartesian_motion_generator_joint_velocity_limits_violation &&
         lhs.cartesian_motion_generator_joint_velocity_discontinuity ==
             rhs.cartesian_motion_generator_joint_velocity_discontinuity &&
         lhs.cartesian_motion_generator_joint_acceleration_discontinuity ==
             rhs.cartesian_motion_generator_joint_acceleration_discontinuity &&
         lhs.cartesian_position_motion_generator_invalid_frame ==
             rhs.cartesian_position_motion_generator_invalid_frame &&
         lhs.force_controller_desired_force_tolerance_violation ==
             rhs.force_controller_desired_force_tolerance_violation &&
         lhs.start_elbow_sign_inconsistent == rhs.start_elbow_sign_inconsistent &&
         lhs.communication_constraints_violation == rhs.communication_constraints_violation &&
         lhs.power_limit_violation == rhs.power_limit_violation;
}
}
