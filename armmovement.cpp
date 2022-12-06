/*
 * Copyright (c) 2012-2021 SoftBank Robotics. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the COPYING file.
 */
#include <iostream>
#include <unistd.h>
#include <alerror/alerror.h>
#include <alproxies/almotionproxy.h>


int main(int argc, char* argv[])
{
  // Robot IP will be needed for all API calls
  std::string robotIP = "134.82.135.19";

  if(argc != 1)
  {
    std::cerr << "Wrong number of arguments!" << std::endl;
    std::cerr << "Usage: say NAO_IP" << std::endl;
    exit(2);
  }

  try
  {
    
    AL::ALMotionProxy motionProxy(robotIP);

    // Raises the left arm and then lowers it
    AL::ALValue names = AL::ALValue::array("LShoulderRoll", "LShoulderPitch");
    AL::ALValue angles = AL::ALValue::array(-0.31f, -2.0f);
    float fractionMaxSpeed = 0.1f;
    motionProxy.setStiffnesses(names, AL::ALValue::array(1.0f, 1.0f));
    qi::os::sleep(3.0f);
    motionProxy.setAngles(names, angles, fractionMaxSpeed);
    qi::os::sleep(3.0f);
    motionProxy.setStiffnesses(names, AL::ALValue::array(0.1f, 0.1f));
  }
  catch (const AL::ALError& e)
  {
    std::cerr << "Caught exception: " << e.what() << std::endl;
    exit(1);
  }
  exit(0);



}