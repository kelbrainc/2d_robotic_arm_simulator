#include "../include/RoboticArm.h"
#include <iostream>
#include <cmath>

// Define PI for trigonometric calculations. M_PI is not standard in all compilers.
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Utility function to convert degrees to radians
static double degreesToRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

// --- Link Class Implementation ---
Link::Link(double len) : length(len), angleDegrees(0.0) {}

// --- RoboticArm Class Implementation ---

/**
 * @brief Construct a new Robotic Arm object.
 */
RoboticArm::RoboticArm(double baseX, double baseY) {
    basePosition.x = baseX;
    basePosition.y = baseY;
}

/**
 * @brief Adds a new link to the end of the arm.
 */
void RoboticArm::addLink(double length) {
    links.emplace_back(length);
    std::cout << "Added Link " << links.size() << " with length " << length << "." << std::endl;
}

/**
 * @brief Sets the angle of a specific joint.
 */
void RoboticArm::setJointAngle(int jointIndex, double angle) {
    if (jointIndex > 0 && jointIndex <= links.size()) {
        links[jointIndex - 1].angleDegrees = angle;
    } else {
        std::cout << "Error: Invalid joint index." << std::endl;
    }
}

/**
 * @brief Calculates the position of the end effector.
 */
Point RoboticArm::getEndEffectorPosition() {
    Point currentPosition = basePosition;
    double cumulativeAngleRad = 0.0;

    for (const auto& link : links) {
        cumulativeAngleRad += degreesToRadians(link.angleDegrees);
        currentPosition.x += link.length * cos(cumulativeAngleRad);
        currentPosition.y += link.length * sin(cumulativeAngleRad);
    }
    return currentPosition;
}

/**
 * @brief Displays the current status of all joints and the end effector.
 */
void RoboticArm::displayStatus() {
    std::cout << "\n------------------ ARM STATUS ------------------" << std::endl;
    if (links.empty()) {
        std::cout << "The arm has no links." << std::endl;
        return;
    }

    for (size_t i = 0; i < links.size(); ++i) {
        std::cout << "Joint " << (i + 1) << ": Length = " << links[i].length
                  << ", Angle = " << links[i].angleDegrees << " degrees" << std::endl;
    }

    Point endEffectorPos = getEndEffectorPosition();
    std::cout << "\nEnd Effector Position: (" << endEffectorPos.x
              << ", " << endEffectorPos.y << ")" << std::endl;
    std::cout << "----------------------------------------------\n" << std::endl;
}

/**
 * @brief Returns the number of joints (and links) in the arm.
 */
int RoboticArm::getNumberOfJoints() const {
    return links.size();
}
