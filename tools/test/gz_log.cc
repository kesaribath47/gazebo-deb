/*
 * Copyright 2012 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#include <gtest/gtest.h>
#include <stdio.h>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string/trim.hpp>

#include "test_config.h"

static std::string pr2StateLog =
"  <model name='pr2'>\n"
"    <pose>0 0 -8e-06 0 0 0</pose>\n"
"    <link name='base_footprint'>\n"
"      <pose>0 0 0 0 0 0</pose>\n"
"      <velocity>0.000124 4.5e-05 -0.007966 0.000178 -0.000477 "
"-6.8e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='bl_caster_rotation_link'>\n"
"      <pose>0 0 0 0 0 0</pose>\n"
"      <velocity>0.000166 6.7e-05 -0.008024 0.000173 -0.000487 "
"-7e-06</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='bl_caster_l_wheel_link'>\n"
"      <pose>0 0 0 0 0 0</pose>\n"
"      <velocity>0.000199 7.9e-05 -0.008031 0.000174 8e-06 "
"-7e-06</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='bl_caster_r_wheel_link'>\n"
"      <pose>0 0 0 0 0 0</pose>\n"
"      <velocity>0.000198 8.1e-05 -0.008046 0.000182 -9e-06 "
"-7e-06</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='br_caster_rotation_link'>\n"
"      <pose>0 0 0 0 0 0</pose>\n"
"      <velocity>0.000135 6.7e-05 -0.008105 0.00016 -0.000508 "
"-7e-06</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='br_caster_l_wheel_link'>\n"
"      <pose>0 0 0 0 0 0</pose>\n"
"      <velocity>0.000171 7.8e-05 -0.008099 0.000177 8e-06 "
"-4e-06</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='br_caster_r_wheel_link'>\n"
"      <pose>0 0 0 0 0 0</pose>\n"
"      <velocity>0.000169 7.6e-05 -0.008117 0.000168 8e-06 "
"-7e-06</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='fl_caster_rotation_link'>\n"
"      <pose>0 0 0 0 0 0</pose>\n"
"      <velocity>0.000164 3.4e-05 -0.007804 0.000177 -0.000499 "
"-7e-06</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='fl_caster_l_wheel_link'>\n"
"      <pose>0 0 0 0 0 0</pose>\n"
"      <velocity>0.0002 4.7e-05 -0.007798 0.000171 8e-06 "
"-7e-06</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='fl_caster_r_wheel_link'>\n"
"      <pose>0 0 0 0 0 0</pose>\n"
"      <velocity>0.000199 4.7e-05 -0.007812 0.000185 9e-06 "
"-8e-06</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='fr_caster_rotation_link'>\n"
"      <pose>0 0 0 0 0 0</pose>\n"
"      <velocity>0.000135 3.3e-05 -0.00788 0.000163 -0.000504 "
"-4e-06</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='fr_caster_l_wheel_link'>\n"
"      <pose>0 0 0 0 0 0</pose>\n"
"      <velocity>0.000172 4.7e-05 -0.00788 0.000147 7e-06 "
"-8e-06</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='fr_caster_r_wheel_link'>\n"
"      <pose>0 0 0 0 0 0</pose>\n"
"      <velocity>0.00017 4.8e-05 -0.007893 0.000165 8e-06 "
"-6e-06</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='torso_lift_link'>\n"
"      <pose>0 0 1e-06 0 0 0</pose>\n"
"      <velocity>-0.000125 -3.9e-05 -0.006598 0.000257 -0.000557 "
"-5e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='head_pan_link'>\n"
"      <pose>0 0 1e-06 0 0 0</pose>\n"
"      <velocity>-0.000408 -0.000142 -0.006521 0.000269 -0.000537 "
"-2.7e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='head_tilt_link'>\n"
"      <pose>0 0 1e-06 0 1e-06 0</pose>\n"
"      <velocity>-0.000355 -0.000141 -0.006499 0.000235 0.000285 "
"-6e-06</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_shoulder_pan_link'>\n"
"      <pose>0 0 1e-06 0 0 0</pose>\n"
"      <velocity>-0.000105 -4.3e-05 -0.006514 0.000204 -0.000547 "
"2.1e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_shoulder_lift_link'>\n"
"      <pose>0 0 1e-06 0 -1.3e-05 0</pose>\n"
"      <velocity>0.000232 -5.5e-05 -0.006142 0.000164 -0.012994 "
"-1.1e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_upper_arm_roll_link'>\n"
"      <pose>0 0 1e-06 1e-05 -1.3e-05 0</pose>\n"
"      <velocity>-0.000166 -4.7e-05 -0.003496 0.010584 -0.01302 "
"2.1e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_elbow_flex_link'>\n"
"      <pose>0 0 6e-06 1e-05 -1e-05 0</pose>\n"
"      <velocity>-4.1e-05 7.3e-05 -0.001117 0.010487 -0.010393 "
"0.000104</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_forearm_roll_link'>\n"
"      <pose>0 0 6e-06 0 -1e-05 0</pose>\n"
"      <velocity>-5.6e-05 -3.5e-05 0.000636 0.000103 -0.010853 "
"0.000103</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_wrist_flex_link'>\n"
"      <pose>0 0 1e-05 0 -1.6e-05 0</pose>\n"
"      <velocity>-0.000188 -2.1e-05 0.002071 0.000102 -0.016789 "
"9.5e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_wrist_roll_link'>\n"
"      <pose>0 0 1e-05 0 4e-06 0</pose>\n"
"      <velocity>-0.000207 -1.2e-05 0.00189 -6e-06 0.003301 "
"0.000134</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_gripper_l_finger_link'>\n"
"      <pose>0 0 9e-06 0 4e-06 0</pose>\n"
"      <velocity>-0.000211 -4e-06 0.001672 0.000112 0.003367 "
"0.000391</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_gripper_l_finger_tip_link'>\n"
"      <pose>0 0 9e-06 -1e-06 3e-06 1e-06</pose>\n"
"      <velocity>-0.000205 4e-06 0.001475 -0.000525 0.002883 "
"0.000777</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_gripper_motor_slider_link'>\n"
"      <pose>0 0 9e-06 0 4e-06 0</pose>\n"
"      <velocity>-0.000217 2e-06 0.001502 -2.7e-05 0.003252 "
"0.000126</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_gripper_motor_screw_link'>\n"
"      <pose>0 0 9e-06 0 1e-06 0</pose>\n"
"      <velocity>-0.000198 3e-06 0.00153 -1.9e-05 0.000446 "
"0.000102</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_gripper_r_finger_link'>\n"
"      <pose>0 0 9e-06 0 5e-06 0</pose>\n"
"      <velocity>-0.000195 -5e-06 0.001689 0.000528 0.004075 "
"0.000231</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_gripper_r_finger_tip_link'>\n"
"      <pose>0 0 9e-06 -0 3e-06 1e-06</pose>\n"
"      <velocity>-0.000196 -7e-06 0.001461 -0.000277 0.002914 "
"0.000838</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='laser_tilt_mount_link'>\n"
"      <pose>0 0 1e-06 0 -3e-06 0</pose>\n"
"      <velocity>-0.000251 -9.7e-05 -0.00647 0.000167 -0.003028 "
"-2.6e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_shoulder_pan_link'>\n"
"      <pose>0 0 1e-06 0 0 0</pose>\n"
"      <velocity>-0.000131 -4.2e-05 -0.006546 0.000175 -0.000491 "
"0.000113</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_shoulder_lift_link'>\n"
"      <pose>0 0 1e-06 0 -1.3e-05 0</pose>\n"
"      <velocity>0.000247 -4e-05 -0.006179 0.000157 -0.013296 "
"0.000132</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_upper_arm_roll_link'>\n"
"      <pose>0 0 1e-06 -1e-05 -1.3e-05 0</pose>\n"
"      <velocity>-0.000172 -2.8e-05 -0.003538 -0.010076 -0.013338 "
"9.7e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_elbow_flex_link'>\n"
"      <pose>0 0 7e-06 -1e-05 -9e-06 -0</pose>\n"
"      <velocity>-1e-05 -0.000128 -0.001074 -0.01015 -0.009811 "
"6.8e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_forearm_roll_link'>\n"
"      <pose>0 0 6e-06 0 -1e-05 0</pose>\n"
"      <velocity>-7.7e-05 1e-05 0.000654 3.7e-05 -0.010973 "
"0.000103</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_wrist_flex_link'>\n"
"      <pose>0 0 1e-05 0 1.1e-05 0</pose>\n"
"      <velocity>-0.000161 2.1e-05 0.002104 3.6e-05 0.010048 "
"-1.4e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_wrist_roll_link'>\n"
"      <pose>0 0 1e-05 0 4e-06 0</pose>\n"
"      <velocity>-0.000155 2.4e-05 0.001899 -7e-06 0.00391 "
"1.9e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_gripper_l_finger_link'>\n"
"      <pose>0 0 9e-06 -1e-06 5e-06 0</pose>\n"
"      <velocity>-0.000157 2.3e-05 0.001601 -0.000388 0.004576 "
"-1.2e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_gripper_l_finger_tip_link'>\n"
"      <pose>0 0 9e-06 0 5e-06 0</pose>\n"
"      <velocity>-0.000144 3.2e-05 0.001325 0.00028 0.004739 "
"4.4e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_gripper_motor_slider_link'>\n"
"      <pose>0 0 9e-06 0 5e-06 0</pose>\n"
"      <velocity>-0.000146 2.1e-05 0.001405 -2.7e-05 0.004035 "
"2e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_gripper_motor_screw_link'>\n"
"      <pose>0 0 9e-06 0 1e-06 0</pose>\n"
"      <velocity>-0.000141 2.2e-05 0.00134 -3e-06 0.000509 "
"5.5e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_gripper_r_finger_link'>\n"
"      <pose>0 0 9e-06 1e-06 6e-06 0</pose>\n"
"      <velocity>-0.000144 2.4e-05 0.001637 0.001538 0.005243 "
"7.6e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_gripper_r_finger_tip_link'>\n"
"      <pose>0 0 9e-06 0 6e-06 0</pose>\n"
"      <velocity>-0.000142 2.5e-05 0.001314 0.000541 0.005139 "
"-3e-06</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='torso_lift_motor_screw_link'>\n"
"      <pose>0 0 -1e-06 -1e-06 0 7.9e-05</pose>\n"
"      <velocity>-0.000153 -6.4e-05 -0.008583 -0.000379 -0.00048 "
"0.079281</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_gripper_l_parallel_link'>\n"
"      <pose>0 0 9e-06 -1e-06 5e-06 0</pose>\n"
"      <velocity>-0.000164 2.8e-05 0.001671 -0.000599 0.004494 "
"-0.000162</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_gripper_r_parallel_link'>\n"
"      <pose>0 0 9e-06 0 5e-06 0</pose>\n"
"      <velocity>-0.000143 2e-05 0.00167 0.00048 0.004431 "
"-3.3e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_gripper_l_parallel_link'>\n"
"      <pose>0 0 9e-06 0 4e-06 1e-06</pose>\n"
"      <velocity>-0.000211 -7e-06 0.001734 -0.000121 0.003723 "
"0.0005</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_gripper_r_parallel_link'>\n"
"      <pose>0 0 9e-06 1e-06 5e-06 0</pose>\n"
"      <velocity>-0.000186 -3e-06 0.001741 0.0007 0.004127 "
"-0.000169</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <joint name='torso_lift_joint'>\n"
"      <angle axis='0'>1.41007e-06</angle>\n"
"    </joint>\n"
"    <joint name='l_shoulder_lift_joint'>\n"
"      <angle axis='0'>-1.24472e-05</angle>\n"
"    </joint>\n"
"    <joint name='l_upper_arm_roll_joint'>\n"
"      <angle axis='0'>1.04205e-05</angle>\n"
"    </joint>\n"
"    <joint name='l_elbow_flex_joint'>\n"
"      <angle axis='0'>2.63091e-06</angle>\n"
"    </joint>\n"
"    <joint name='l_forearm_roll_joint'>\n"
"      <angle axis='0'>-1.03937e-05</angle>\n"
"    </joint>\n"
"    <joint name='l_wrist_flex_joint'>\n"
"      <angle axis='0'>-5.93599e-06</angle>\n"
"    </joint>\n"
"    <joint name='l_wrist_roll_joint'>\n"
"      <angle axis='0'>-2.00905e-05</angle>\n"
"    </joint>\n"
"    <joint name='l_gripper_motor_screw_joint'>\n"
"      <angle axis='0'>-2.80641e-06</angle>\n"
"    </joint>\n"
"    <joint name='l_gripper_r_finger_tip_joint'>\n"
"      <angle axis='0'>1.53825e-06</angle>\n"
"    </joint>\n"
"    <joint name='laser_tilt_mount_joint'>\n"
"      <angle axis='0'>-2.47273e-06</angle>\n"
"    </joint>\n"
"    <joint name='r_shoulder_lift_joint'>\n"
"      <angle axis='0'>-1.28046e-05</angle>\n"
"    </joint>\n"
"    <joint name='r_upper_arm_roll_joint'>\n"
"      <angle axis='0'>-1.0234e-05</angle>\n"
"    </joint>\n"
"    <joint name='r_elbow_flex_joint'>\n"
"      <angle axis='0'>3.52763e-06</angle>\n"
"    </joint>\n"
"    <joint name='r_forearm_roll_joint'>\n"
"      <angle axis='0'>1.0253e-05</angle>\n"
"    </joint>\n"
"    <joint name='r_wrist_flex_joint'>\n"
"      <angle axis='0'>2.10212e-05</angle>\n"
"    </joint>\n"
"    <joint name='r_wrist_roll_joint'>\n"
"      <angle axis='0'>-6.13793e-06</angle>\n"
"    </joint>\n"
"    <joint name='r_gripper_motor_screw_joint'>\n"
"      <angle axis='0'>-3.52607e-06</angle>\n"
"    </joint>\n"
"    <joint name='r_gripper_r_finger_joint'>\n"
"      <angle axis='0'>-2.04123e-06</angle>\n"
"    </joint>\n"
"    <joint name='r_gripper_r_finger_tip_joint'>\n"
"      <angle axis='0'>-1.00512e-06</angle>\n"
"    </joint>\n"
"    <joint name='torso_lift_motor_screw_joint'>\n"
"      <angle axis='0'>7.9351e-05</angle>\n"
"    </joint>\n"
"    <joint name='torso_lift_screw_torso_lift_joint'>\n"
"      <angle axis='0'>-1.98549e-06</angle>\n"
"    </joint>\n"
"    <joint name='l_gripper_r_parallel_root_joint'>\n"
"      <angle axis='0'>-1.12785e-06</angle>\n"
"    </joint>\n"
"    <joint name='l_gripper_r_parallel_tip_joint'>\n"
"      <angle axis='0'>1.85524e-06</angle>\n"
"    </joint>\n"
"  </model>\n"
"\n"
"  <model name='pr2'>\n"
"    <pose>0 0 -1.5e-05 0 -1e-06 0</pose>\n"
"    <link name='base_footprint'>\n"
"      <pose>0 0 0 0 0 0</pose>\n"
"      <velocity>0.000116 4.6e-05 -0.007403 0.000204 -0.000505 "
"-5.5e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='bl_caster_rotation_link'>\n"
"      <pose>0 0 0 0 0 0</pose>\n"
"      <velocity>0.000153 6.9e-05 -0.007439 0.000138 -0.000505 "
"-6e-06</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='bl_caster_l_wheel_link'>\n"
"      <pose>0 0 0 0 1e-06 0</pose>\n"
"      <velocity>0.000197 8.3e-05 -0.007405 0.000194 9e-06 "
"-2e-06</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='bl_caster_r_wheel_link'>\n"
"      <pose>0 0 0 0 1e-06 0</pose>\n"
"      <velocity>0.000195 8.1e-05 -0.007462 0.000167 -8e-06 "
"-1e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='br_caster_rotation_link'>\n"
"      <pose>0 0 0 0 0 0</pose>\n"
"      <velocity>0.000126 6.7e-05 -0.007533 0.000261 -0.000482 "
"-1e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='br_caster_l_wheel_link'>\n"
"      <pose>0 0 0 0 1e-06 0</pose>\n"
"      <velocity>0.000165 8.8e-05 -0.007513 0.000227 1.1e-05 "
"-1.3e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='br_caster_r_wheel_link'>\n"
"      <pose>0 0 0 0 1e-06 0</pose>\n"
"      <velocity>0.000166 8.6e-05 -0.007535 0.000192 9e-06 "
"-8e-06</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='fl_caster_rotation_link'>\n"
"      <pose>0 0 0 0 0 0</pose>\n"
"      <velocity>0.000156 4.5e-05 -0.007216 0.000239 -0.000482 "
"-9e-06</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='fl_caster_l_wheel_link'>\n"
"      <pose>0 0 0 0 1e-06 0</pose>\n"
"      <velocity>0.000196 6e-05 -0.00722 0.000163 8e-06 -7e-06</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='fl_caster_r_wheel_link'>\n"
"      <pose>0 0 0 0 1e-06 0</pose>\n"
"      <velocity>0.000195 5.5e-05 -0.007239 0.000141 7e-06 "
"-6e-06</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='fr_caster_rotation_link'>\n"
"      <pose>0 0 0 0 0 0</pose>\n"
"      <velocity>0.000127 4.7e-05 -0.007314 0.000149 -0.000489 "
"-9e-06</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='fr_caster_l_wheel_link'>\n"
"      <pose>0 0 0 0 1e-06 0</pose>\n"
"      <velocity>0.000165 5.7e-05 -0.00729 0.000235 1.1e-05 "
"-6e-06</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='fr_caster_r_wheel_link'>\n"
"      <pose>0 0 0 0 1e-06 0</pose>\n"
"      <velocity>0.000165 5.7e-05 -0.007331 0.000186 9e-06 "
"-1e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='torso_lift_link'>\n"
"      <pose>0 0 2e-06 0 0 0</pose>\n"
"      <velocity>-0.000126 -4.4e-05 -0.00724 0.000118 -0.000415 "
"-7.5e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='head_pan_link'>\n"
"      <pose>0 0 2e-06 0 0 0</pose>\n"
"      <velocity>-0.000412 -0.000157 -0.00723 3.7e-05 -0.00051 "
"4.8e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='head_tilt_link'>\n"
"      <pose>0 0 2e-06 0 2e-06 0</pose>\n"
"      <velocity>-0.000316 -0.000148 -0.007178 5.4e-05 0.000261 "
"-1.7e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_shoulder_pan_link'>\n"
"      <pose>0 0 2e-06 0 0 0</pose>\n"
"      <velocity>-0.000112 -4.9e-05 -0.007149 0.000173 -0.000543 "
"1.5e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_shoulder_lift_link'>\n"
"      <pose>0 0 2e-06 0 -2.5e-05 0</pose>\n"
"      <velocity>0.000195 -5.7e-05 -0.006877 0.000177 -0.01348 "
"8e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_upper_arm_roll_link'>\n"
"      <pose>0 0 2e-06 2.3e-05 -2.6e-05 0</pose>\n"
"      <velocity>-0.000182 -9.5e-05 -0.004053 0.012333 -0.013693 "
"0.00018</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_elbow_flex_link'>\n"
"      <pose>0 0 1.2e-05 2.3e-05 -2.3e-05 0</pose>\n"
"      <velocity>1.5e-05 9e-05 -0.001495 0.012455 -0.013886 "
"0.00023</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_forearm_roll_link'>\n"
"      <pose>0 0 1.2e-05 0 -2.4e-05 0</pose>\n"
"      <velocity>-4.1e-05 -3.6e-05 0.000995 0.000195 -0.013748 "
"4.9e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_wrist_flex_link'>\n"
"      <pose>0 0 2e-05 0 2.3e-05 0</pose>\n"
"      <velocity>-8.6e-05 -3.3e-05 0.003007 0.000194 0.038352 "
"1.3e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_wrist_roll_link'>\n"
"      <pose>0 0 2e-05 0 1.8e-05 0</pose>\n"
"      <velocity>-0.000126 -2.8e-05 0.002169 2e-06 0.014212 "
"9.8e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_gripper_l_finger_link'>\n"
"      <pose>0 0 1.8e-05 -1e-06 1.9e-05 0</pose>\n"
"      <velocity>-0.000137 -2.2e-05 0.001392 -0.000618 0.014293 "
"-0.000139</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_gripper_l_finger_tip_link'>\n"
"      <pose>0 0 1.6e-05 0 1.8e-05 0</pose>\n"
"      <velocity>-0.000109 -1.3e-05 0.000532 0.000646 0.014604 "
"-0.000656</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_gripper_motor_slider_link'>\n"
"      <pose>0 0 1.6e-05 0 1.8e-05 0</pose>\n"
"      <velocity>-9.2e-05 -6e-06 0.000625 4.5e-05 0.014263 "
"0.00011</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_gripper_r_finger_link'>\n"
"      <pose>0 0 1.8e-05 -1e-06 1.8e-05 -0</pose>\n"
"      <velocity>-0.000132 -2.4e-05 0.001376 -0.000792 0.01321 "
"-0.000136</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_gripper_r_finger_tip_link'>\n"
"      <pose>0 0 1.6e-05 0 1.9e-05 0</pose>\n"
"      <velocity>-0.000111 -6e-06 0.00056 0.000694 0.015 "
"-0.000728</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='laser_tilt_mount_link'>\n"
"      <pose>0 0 2e-06 0 -5e-06 0</pose>\n"
"      <velocity>-0.000297 -0.000116 -0.007252 0.000219 -0.002617 "
"-7.9e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_shoulder_pan_link'>\n"
"      <pose>0 0 2e-06 0 0 0</pose>\n"
"      <velocity>-0.000142 -4.5e-05 -0.007275 0.000228 -0.00059 "
"9.7e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_shoulder_lift_link'>\n"
"      <pose>0 0 2e-06 0 -2.6e-05 0</pose>\n"
"      <velocity>0.000168 -5.5e-05 -0.006943 1e-05 -0.013582 "
"2.8e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_upper_arm_roll_link'>\n"
"      <pose>0 0 2e-06 -2.2e-05 -2.6e-05 0</pose>\n"
"      <velocity>-0.000213 1.2e-05 -0.004147 -0.01202 "
"-0.01348 -2e-06</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_elbow_flex_link'>\n"
"      <pose>0 0 1.2e-05 -2.3e-05 -2.1e-05 0</pose>\n"
"      <velocity>-8.9e-05 -0.000137 -0.001615 -0.012091 "
"-0.012612 1.5e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_forearm_roll_link'>\n"
"      <pose>0 0 1.2e-05 0 -2.3e-05 0</pose>\n"
"      <velocity>-6.9e-05 1.5e-05 0.000538 -3.3e-05 -0.01299 "
"7.8e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_wrist_flex_link'>\n"
"      <pose>0 0 1.9e-05 0 -3.7e-05 0</pose>\n"
"      <velocity>-0.000213 2.9e-05 0.002283 -3.4e-05 -0.048363 "
"0.000245</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_wrist_roll_link'>\n"
"      <pose>0 0 1.9e-05 0 1e-06 0</pose>\n"
"      <velocity>-0.000241 3.3e-05 0.002408 -3.3e-05 -0.004285 "
"0.000125</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_gripper_l_finger_link'>\n"
"      <pose>0 0 1.9e-05 0 2e-06 1e-06</pose>\n"
"      <velocity>-0.00024 4.2e-05 0.002724 0.000605 -0.00393 "
"0.000412</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_gripper_l_finger_tip_link'>\n"
"      <pose>0 0 1.9e-05 0 3e-06 0</pose>\n"
"      <velocity>-0.000248 2.9e-05 0.00298 -7.1e-05 -0.003186 "
"6.7e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_gripper_motor_slider_link'>\n"
"      <pose>0 0 1.9e-05 0 1e-06 0</pose>\n"
"      <velocity>-0.000244 5.5e-05 0.002912 -5e-06 -0.003571 "
"0.000126</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_gripper_motor_screw_link'>\n"
"      <pose>0 0 1.9e-05 0 2e-06 0</pose>\n"
"      <velocity>-0.000238 4.6e-05 0.002944 -4.3e-05 0.000804 "
"0.000132</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_gripper_r_finger_link'>\n"
"      <pose>0 0 1.9e-05 0 2e-06 0</pose>\n"
"      <velocity>-0.000247 3.7e-05 0.002672 -0.000894 -0.004483 "
"-0.000188</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_gripper_r_finger_tip_link'>\n"
"      <pose>0 0 1.9e-05 -2e-06 2e-06 -0</pose>\n"
"      <velocity>-0.000249 3e-05 0.002969 -0.001725 -0.004043 "
"0.000137</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='torso_lift_motor_screw_link'>\n"
"      <pose>0 0 -1e-06 0 0 0.000183</pose>\n"
"      <velocity>-0.000151 -1.3e-05 -0.007513 0.000745 -0.000663 "
"0.103921</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_gripper_l_parallel_link'>\n"
"      <pose>0 0 1.9e-05 0 1e-06 0</pose>\n"
"      <velocity>-0.000238 3.1e-05 0.002651 0.000555 -0.004326 "
"2.8e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='r_gripper_r_parallel_link'>\n"
"      <pose>0 0 1.9e-05 -1e-06 1e-06 0</pose>\n"
"      <velocity>-0.000242 4e-05 0.002661 -0.001241 -0.004413 "
"-7.8e-05</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_gripper_l_parallel_link'>\n"
"      <pose>0 0 1.8e-05 -1e-06 1.8e-05 -0</pose>\n"
"      <velocity>-0.000146 -2.1e-05 0.001652 -0.000197 0.013567 "
"-0.000258</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <link name='l_gripper_r_parallel_link'>\n"
"      <pose>0 0 1.8e-05 -1e-06 1.9e-05 0</pose>\n"
"      <velocity>-0.000135 -2.9e-05 0.001649 -0.000872 0.013488 "
"0.000434</velocity>\n"
"      <acceleration>0 0 0 0 0 0</acceleration>\n"
"      <wrench>0 0 0 0 0 0</wrench>\n"
"    </link>\n"
"    <joint name='bl_caster_l_wheel_joint'>\n"
"      <angle axis='0'>1.01079e-06</angle>\n"
"    </joint>\n"
"    <joint name='br_caster_l_wheel_joint'>\n"
"      <angle axis='0'>1.00809e-06</angle>\n"
"    </joint>\n"
"    <joint name='br_caster_r_wheel_joint'>\n"
"      <angle axis='0'>1.00718e-06</angle>\n"
"    </joint>\n"
"    <joint name='fr_caster_l_wheel_joint'>\n"
"      <angle axis='0'>1.01174e-06</angle>\n"
"    </joint>\n"
"    <joint name='fr_caster_r_wheel_joint'>\n"
"      <angle axis='0'>1.0102e-06</angle>\n"
"    </joint>\n"
"    <joint name='torso_lift_joint'>\n"
"      <angle axis='0'>1.61697e-06</angle>\n"
"    </joint>\n"
"    <joint name='head_tilt_joint'>\n"
"      <angle axis='0'>1.59176e-06</angle>\n"
"    </joint>\n"
"    <joint name='l_shoulder_lift_joint'>\n"
"      <angle axis='0'>-2.5384e-05</angle>\n"
"    </joint>\n"
"    <joint name='l_upper_arm_roll_joint'>\n"
"      <angle axis='0'>2.25789e-05</angle>\n"
"    </joint>\n"
"    <joint name='l_elbow_flex_joint'>\n"
"      <angle axis='0'>2.4368e-06</angle>\n"
"    </joint>\n"
"    <joint name='l_forearm_roll_joint'>\n"
"      <angle axis='0'>-2.26431e-05</angle>\n"
"    </joint>\n"
"    <joint name='l_wrist_flex_joint'>\n"
"      <angle axis='0'>4.61642e-05</angle>\n"
"    </joint>\n"
"    <joint name='l_wrist_roll_joint'>\n"
"      <angle axis='0'>4.04443e-06</angle>\n"
"    </joint>\n"
"    <joint name='l_gripper_motor_screw_joint'>\n"
"      <angle axis='0'>-1.66172e-05</angle>\n"
"    </joint>\n"
"    <joint name='l_gripper_r_finger_joint'>\n"
"      <angle axis='0'>1.55625e-06</angle>\n"
"    </joint>\n"
"    <joint name='laser_tilt_mount_joint'>\n"
"      <angle axis='0'>-4.67204e-06</angle>\n"
"    </joint>\n"
"    <joint name='r_shoulder_lift_joint'>\n"
"      <angle axis='0'>-2.57981e-05</angle>\n"
"    </joint>\n"
"    <joint name='r_upper_arm_roll_joint'>\n"
"      <angle axis='0'>-2.22655e-05</angle>\n"
"    </joint>\n"
"    <joint name='r_elbow_flex_joint'>\n"
"      <angle axis='0'>4.39678e-06</angle>\n"
"    </joint>\n"
"    <joint name='r_forearm_roll_joint'>\n"
"      <angle axis='0'>2.22922e-05</angle>\n"
"    </joint>\n"
"    <joint name='r_wrist_flex_joint'>\n"
"      <angle axis='0'>-1.43521e-05</angle>\n"
"    </joint>\n"
"    <joint name='r_wrist_roll_joint'>\n"
"      <angle axis='0'>-2.56647e-05</angle>\n"
"    </joint>\n"
"    <joint name='r_gripper_l_finger_joint'>\n"
"      <angle axis='0'>2.47396e-06</angle>\n"
"    </joint>\n"
"    <joint name='r_gripper_l_finger_tip_joint'>\n"
"      <angle axis='0'>1.96603e-06</angle>\n"
"    </joint>\n"
"    <joint name='r_gripper_r_finger_joint'>\n"
"      <angle axis='0'>5.37142e-06</angle>\n"
"    </joint>\n"
"    <joint name='r_gripper_r_finger_tip_joint'>\n"
"      <angle axis='0'>3.84165e-06</angle>\n"
"    </joint>\n"
"    <joint name='torso_lift_motor_screw_joint'>\n"
"      <angle axis='0'>0.000183324</angle>\n"
"    </joint>\n"
"    <joint name='torso_lift_screw_torso_lift_joint'>\n"
"      <angle axis='0'>-2.25856e-06</angle>\n"
"    </joint>\n"
"    <joint name='r_gripper_r_parallel_tip_joint'>\n"
"      <angle axis='0'>1.13052e-06</angle>\n"
"    </joint>\n"
"    <joint name='r_gripper_l_parallel_tip_joint'>\n"
"      <angle axis='0'>1.09768e-06</angle>\n"
"    </joint>\n"
"  </model>";


std::string custom_exec(std::string _cmd)
{
  _cmd += " 2>/dev/null";
  FILE* pipe = popen(_cmd.c_str(), "r");

  if (!pipe)
    return "ERROR";

  char buffer[128];
  std::string result = "";

  while (!feof(pipe))
  {
    if (fgets(buffer, 128, pipe) != NULL)
      result += buffer;
  }

  pclose(pipe);
  return result;
}

/////////////////////////////////////////////////
/// Check to make sure that 'gzlog info' returns correct information
TEST(gz_log, Info)
{
  std::string info = custom_exec(std::string("gzlog info ") +
      PROJECT_SOURCE_PATH + "/tools/test/data/pr2_state.log");
  boost::trim_right(info);

  std::string validInfo =
    "Log Version:    1.0\n"
    "Gazebo Version: 1.4.6\n"
    "Random Seed:    32606\n"
    "Start:          Feb 08 13 05:35:55.667456998\n"
    "End:            Feb 08 13 05:35:58.947304437\n"
    "Duration:       00:00:03.279847439\n"
    "Steps:          3\n"
    "Size:           12.377 KB\n"
    "Encoding:       bz2\n"
    "Model Count:    2";

  EXPECT_EQ(validInfo, info);
}

/////////////////////////////////////////////////
/// Check to make sure that 'gzlog echo' returns correct information
TEST(gz_log, Echo)
{
  std::string echo = custom_exec(std::string("gzlog echo ") +
      PROJECT_SOURCE_PATH + "/tools/test/data/empty_state.log");
  boost::trim_right(echo);

  std::string validEcho =
    "<sdf version ='1.3'>\n"
    "<world name='default'>\n"
    "  <light name='sun' type='directional'>\n"
    "    <cast_shadows>1</cast_shadows>\n"
    "    <pose>0.000000 0.000000 10.000000 0.000000 0.000000 0.000000</pose>\n"
    "    <diffuse>0.800000 0.800000 0.800000 1.000000</diffuse>\n"
    "    <specular>0.100000 0.100000 0.100000 1.000000</specular>\n"
    "    <attenuation>\n"
    "      <range>1000.000000</range>\n"
    "      <constant>0.900000</constant>\n"
    "      <linear>0.010000</linear>\n"
    "      <quadratic>0.001000</quadratic>\n"
    "    </attenuation>\n"
    "    <direction>-0.500000 0.500000 -1.000000</direction>\n"
    "  </light>\n"
    "  <model name='ground_plane'>\n"
    "    <static>1</static>\n"
    "    <link name='link'>\n"
    "      <collision name='collision'>\n"
    "        <geometry>\n"
    "          <plane>\n"
    "            <normal>0.000000 0.000000 1.000000</normal>\n"
    "            <size>100.000000 100.000000</size>\n"
    "          </plane>\n"
    "        </geometry>\n"
    "        <surface>\n"
    "          <friction>\n"
    "            <ode>\n"
    "              <mu>100.000000</mu>\n"
    "              <mu2>50.000000</mu2>\n"
    "            </ode>\n"
    "          </friction>\n"
    "          <bounce/>\n"
    "          <contact>\n"
    "            <ode/>\n"
    "          </contact>\n"
    "        </surface>\n"
    "      </collision>\n"
    "      <visual name='visual'>\n"
    "        <cast_shadows>0</cast_shadows>\n"
    "        <geometry>\n"
    "          <plane>\n"
    "            <normal>0.000000 0.000000 1.000000</normal>\n"
    "            <size>100.000000 100.000000</size>\n"
    "          </plane>\n"
    "        </geometry>\n"
    "        <material>\n"
    "          <script>\n"
    "            <uri>file://media/materials/scripts/gazebo.material</uri>\n"
    "            <name>Gazebo/Grey</name>\n"
    "          </script>\n"
    "        </material>\n"
    "      </visual>\n"
    "      <velocity_decay>\n"
    "        <linear>0.000000</linear>\n"
    "        <angular>0.000000</angular>\n"
    "      </velocity_decay>\n"
    "      <self_collide>0</self_collide>\n"
    "      <kinematic>0</kinematic>\n"
    "      <gravity>1</gravity>\n"
    "    </link>\n"
    "  </model>\n"
    "  <physics type='ode'>\n"
    "    <update_rate>1000.000000</update_rate>\n"
    "    <gravity>0.000000 0.000000 -9.800000</gravity>\n"
    "  </physics>\n"
    "  <scene>\n"
    "    <ambient>0.200000 0.200000 0.200000 1.000000</ambient>\n"
    "    <background>0.700000 0.700000 0.700000 1.000000</background>\n"
    "    <shadows>1</shadows>\n"
    "  </scene>\n"
    "  <state world_name='default'>\n"
    "    <sim_time>0 0</sim_time>\n"
    "    <real_time>0 0</real_time>\n"
    "    <wall_time>1360300141 918692496</wall_time>\n"
    "  </state>\n"
    "</world>\n"
    "</sdf>";

  EXPECT_EQ(validEcho, echo);
}

/////////////////////////////////////////////////
/// Check to make sure that 'gzlog echo --filter' returns correct information
TEST(gz_log, EchoFilter)
{
  // Test model filter
  std::string echo = custom_exec(
      std::string("gzlog echo --filter pr2 ") +
      PROJECT_SOURCE_PATH + "/tools/test/data/pr2_state.log");
  boost::trim_right(echo);

  EXPECT_EQ(pr2StateLog, echo);

  // Test joint filter with angle
  echo = custom_exec(
      std::string("gzlog echo --filter pr2::r_upper_arm_roll_joint::0 ") +
      PROJECT_SOURCE_PATH + "/tools/test/data/pr2_state.log");
  boost::trim_right(echo);

  std::string validEcho =
    "-1.0234e-05\n"
    "-2.22655e-05";

  EXPECT_EQ(validEcho, echo);
}

/////////////////////////////////////////////////
/// Main
int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}