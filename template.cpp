#include <iostream>
#include <unistd.h>
#include <alerror/alerror.h>
// Add any include statements for desired API calls here

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
    // Add all code here

  }
  catch (const AL::ALError& e)
  {
    std::cerr << "Caught exception: " << e.what() << std::endl;
    exit(1);
  }
  exit(0);

}