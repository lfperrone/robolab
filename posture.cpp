/*
 * Copyright (c) 2012-2021 SoftBank Robotics. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the COPYING file.
 */
#include <iostream>
#include <unistd.h>
#include <alerror/alerror.h>
#include <alproxies/alrobotpostureproxy.h>


int main(int argc, char* argv[])
{
  // Robot IP will be needed for all API calls
  std::string robotIP = "134.82.159.168";

  if(argc != 2)
  {
    std::cerr << "Wrong number of arguments!" << std::endl;
    std::cerr << "Usage: say NAO_IP" << std::endl;
    exit(2);
  }

  try
  {
    /** Create an ALRobotPostureProxy so that we can call the goToPosture method
    * Arguments for the constructor are:
    *  - IP of the robot
    *  - port on which NAOqi is listening. Default is 9559
    */
    AL::ALRobotPostureProxy postureProxy(robotIP, 9559);

    // Gets the 2nd argument passed in when program is run
    std::string posture = argv[2];
    
    if (posture == "sit") {
      postureProxy.goToPosture("Sit", 1.0);
    }
    if (posture == "stand") {
      postureProxy.goToPosture("Stand", 1.0);
    }
    if (posture == "crouch") {
      postureProxy.goToPosture("Crouch", 1.0);
    }
    

  }
  catch (const AL::ALError& e)
  {
    std::cerr << "Caught exception: " << e.what() << std::endl;
    exit(1);
  }
  exit(0);



}