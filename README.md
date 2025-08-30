## 2D Robotic Arm Kinematics Simulator
This is a simple command-line C++ application that simulates the forward kinematics of a 2D robotic arm. It's designed to demonstrate object-oriented programming principles and fundamental robotics concepts.

### Description
The program defines a robotic arm as a series of connected links. Users can interactively set the angle of each joint, and the simulator will calculate and display the resulting (x, y) position of the arm's end effector.

### Project Structure
The project is organized into the following directories and files:

robotic-arm-simulator/
├── include/
│   └── RoboticArm.h      # Header file for the RoboticArm class and related structs
├── src/
│   ├── RoboticArm.cpp    # Implementation of the RoboticArm class methods
│   └── main.cpp          # The main entry point of the program
├── Makefile              # A build script to compile the project
└── README.md             

### How to Compile and Run
#### Using the Makefile (Recommended)
Compile: Open a terminal in the root directory of the project and run the make command:

make

This will create an executable file named robotic_arm_simulator in a new bin/ directory.

Run: Execute the program with:

./bin/robotic_arm_simulator

Clean Up: To remove the compiled files, run:

make clean

#### Compiling Manually
If you don't have make, you can compile the files manually using g++:

g++ -std=c++11 -I./include/ src/main.cpp src/RoboticArm.cpp -o bin/robotic_arm_simulator

(You may need to create the bin/ directory first: mkdir bin)
