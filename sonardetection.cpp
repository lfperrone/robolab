/*
 * Copyright (c) 2012-2021 SoftBank Robotics. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the COPYING file.
 */
#include <iostream>
#include <unistd.h>
#include <alerror/alerror.h>
#include <alproxies/alrobotpostureproxy.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alsonarproxy.h>
#include <alproxies/almemoryproxy.h>


int main(int argc, char* argv[])
{
  // Robot IP will be needed for all API calls
  std::string robotIP = "134.82.159.168";

  if(argc != 1)
  {
    std::cerr << "Wrong number of arguments!" << std::endl;
    std::cerr << "Usage: say NAO_IP" << std::endl;
    exit(2);
  }

  try
  {
    
    AL::ALMotionProxy motionProxy(robotIP);
    AL::ALRobotPostureProxy robotPosture(robotIP);
    AL::ALSonarProxy sonarProxy(robotIP);
    AL::ALMemoryProxy memoryProxy(robotIP);
    
    //Gets the robot to stand up
    robotPosture.goToPosture("StandInit", 0.5f);

    sonarProxy.subscribe("myApplication");
    float leftSonar = memoryProxy.getData("Device/SubDeviceList/US/Left/Sensor/Value");
    float rightSonar = memoryProxy.getData("Device/SubDeviceList/US/Right/Sensor/Value");

    // Robot will walk forward until there is something within 0.3 meters in front of it
    // Once that object is gone, it will continue to walk
    float x = 2.0f;
    float y = 0.0f;
    float theta = 0.0f;
    motionProxy.post.moveTo(x, y, theta);
    while (true) {
      leftSonar = memoryProxy.getData("Device/SubDeviceList/US/Left/Sensor/Value");
      if (leftSonar < 0.3) {
         motionProxy.stopMove();
      }
      else {
        motionProxy.post.moveTo(x, y, theta);
      }
    }

    sonarProxy.unsubscribe("myApplication");
  }
  catch (const AL::ALError& e)
  {
    std::cerr << "Caught exception: " << e.what() << std::endl;
    exit(1);
  }
  exit(0);



}