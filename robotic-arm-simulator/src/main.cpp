#include <iostream>
#include <limits>
#include "RoboticArm.h"

/**
 * @brief Prints the main menu for the user.
 */
void printMenu() {
    std::cout << "Robotic Arm Control Menu:" << std::endl;
    std::cout << "  1. Set a joint angle" << std::endl;
    std::cout << "  2. View current arm status" << std::endl;
    std::cout << "  3. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    // --- ARM SETUP ---
    RoboticArm arm(0.0, 0.0);

    std::cout << "Initializing a 3-link robotic arm..." << std::endl;
    arm.addLink(10.0);
    arm.addLink(7.5);
    arm.addLink(5.0);
    std::cout << "Initialization complete.\n" << std::endl;

    // --- USER INTERACTION LOOP ---
    int choice = 0;
    while (choice != 3) {
        printMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: {
                int joint = 0;
                double angle = 0.0;
                std::cout << "Enter joint number to control (1-" << arm.getNumberOfJoints() << "): ";
                std::cin >> joint;
                std::cout << "Enter new angle in degrees: ";
                std::cin >> angle;

                if (std::cin.fail()) {
                    std::cout << "Invalid input for joint or angle." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }

                arm.setJointAngle(joint, angle);
                std::cout << "Joint " << joint << " angle set to " << angle << " degrees." << std::endl;
                arm.displayStatus();
                break;
            }
            case 2: {
                arm.displayStatus();
                break;
            }
            case 3: {
                std::cout << "Exiting simulator. Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
            }
        }
    }

    return 0;
}
