# NAO C++ SDK Setup Ubuntu

## Install CMake

Note: The SDK requires CMake version `2.8.3` or higher

1. Run `sudo apt-get install cmake`
1. Check your Python version `python --version` should be 2.7
1. Install python 3 (this will be necessary for running pip3)
1. Install qiBuild using `pip3 install qibuild --user`
1. Add qiBuild to your **$PATH**, add the following line `PATH=$PATH:$HOME/.local/bin` to your `~/.bashrc` file
1. Run `qibuild config --wizard`
    You will be prompted for:
    * CMake path (if not automatically found)
    * CMake generator (choose **UNIX MAKEFILES**)
    * IDE dont specify, completely unecessary\
    Result: `~/.config/qi/qibuild.xml` shared by all worktrees you create

## Initializing Worktree
1. Create an empty directory `ex: /path/to/myWorktree`
1. `cd` into your new directory
1. Run `qibuild init`
1. Note: The directory should remain empty 

## NAOqi SDK setup
*the following requires you to have created a worktree folder if not see above step*
1. Download the naoqi-sdk from https://www.aldebaran.com/en/support/nao-6/downloads-softwares 
1. extract the folder and rename to **naoqi-sdk** \
   ***Location of this folder does not matter*** 
1. execute `qitoolchain create mytoolchain /path/to/naoqi-sdk/toolchain.xml` to create a toolchain from the C++ SDK
1. cd into your worktree `/path/to/myWorktree`
1. execute `qibuild add-config myconfig -t mytoolchain --default`

## Confirm Setup
Follow this tutorial to make sure everything was configured correctly: \
https://developer.softbankrobotics.com/nao6/naoqi-developer-guide/sdks/c-sdk/c-sdk-hello-world-step-step

## Robot Settings Setup
Download Robot Settings for Linux here: https://community-static.aldebaran.com/resources/2.8.6/robot-settings-2.8.6.23-linux64-setup.run











    
