#include <iostream>
#include <memory>
#include <vector>

 #include "mobile_robot.h"
 #include "aerial_robot.h"
 #include "aquatic_robot.h"
 #include "legged_robot.h"
 #include "wheeled_robot.h"

// Move robot is called to move the robot.
void move_robot(RWA2::MobileRobot& robot){
  // Calling the move method specfic to the robot.
  robot.move(0.2, 20);
} //  end of move method.

int main() {

  std::vector<std::reference_wrapper<RWA2::MobileRobot>> mobile_robots;

  RWA2::AerialRobot aerial_robot1(0.0, 0.0, 0.0, "Erle-plane",
        "LiFePO4", 20, "multiScan100", true);
  RWA2::MobileRobot& aerial_robot_ref1{aerial_robot1};

  RWA2::AerialRobot aerial_robot2(0.0, 0.0, 0.0, "Crazyflie",
        "Li-ion", 20, "multiScan100", false);
  RWA2::MobileRobot& aerial_robot_ref2{aerial_robot2};

  RWA2::AquaticRobot aquatic_robot1(0.0, 0.0, 0.0, "SoFi",
        "LiFePO4", 20, "multiScan100", true);
  RWA2::MobileRobot& aquatic_robot_ref1{aquatic_robot1};

  RWA2::AquaticRobot aquatic_robot2(0.0, 0.0, 0.0, "HoloOcean",
        "Li-ion", 20, "multiScan100", false);
  RWA2::MobileRobot& aquatic_robot_ref2{aquatic_robot2};

  RWA2::LeggedRobot legged_robot1(0.0, 0.0, 0.0, "Atlas",
        "LiFePO4", 20, "OSDome", 1.0, 1);
  RWA2::MobileRobot& legged_robot_ref1{legged_robot1};

  RWA2::LeggedRobot legged_robot2(0.0, 0.0, 0.0, "Spot",
        "Li-ion", 20, "OS1",  2.0, 5, 4);
  RWA2::MobileRobot& legged_robot_ref2{legged_robot2};

  RWA2::WheeledRobot wheeled_robot1(0.0, 0.0, 0.0, "Turtlebot",
        "LiFePO4", 20, "OS2",  2.5, 2.0);
  RWA2::MobileRobot& wheeled_robot_ref1{wheeled_robot1};

  RWA2::WheeledRobot wheeled_robot2(0.0, 0.0, 0.0, "Hiwonder",
        "Li-ion", 20, "OS1",  2.5, 4.0, 4);
  RWA2::MobileRobot& wheeled_robot_ref2{wheeled_robot2};

  mobile_robots.push_back(aerial_robot_ref1);
  mobile_robots.push_back(aquatic_robot_ref1);
  mobile_robots.push_back(legged_robot_ref1);
  mobile_robots.push_back(wheeled_robot_ref1);
  mobile_robots.push_back(aerial_robot_ref2);
  mobile_robots.push_back(aquatic_robot_ref2);
  mobile_robots.push_back(legged_robot_ref2);
  mobile_robots.push_back(wheeled_robot_ref2);
  for(const auto& robot : mobile_robots){
    // Calling the move_robot method
    move_robot(robot);
  }// end of for loop.
} // end of main.