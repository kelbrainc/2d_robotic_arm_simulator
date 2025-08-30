#ifndef ROBOTIC_ARM_H
#define ROBOTIC_ARM_H

#include <vector>

/**
 * @struct Point
 * @brief Represents a point in 2D space.
 */
struct Point {
    double x = 0.0;
    double y = 0.0;
};

/**
 * @class Link
 * @brief Represents a single link or segment of the robotic arm.
 */
class Link {
public:
    double length;
    double angleDegrees; // Angle in degrees relative to the previous link's orientation

    Link(double len);
};

/**
 * @class RoboticArm
 * @brief Represents the entire robotic arm, composed of multiple links.
 * The declaration of the class (the interface) is in this header file.
 */
class RoboticArm {
private:
    std::vector<Link> links;
    Point basePosition;

public:
    // Constructor
    RoboticArm(double baseX = 0.0, double baseY = 0.0);

    // Modifiers
    void addLink(double length);
    void setJointAngle(int jointIndex, double angle);

    // Getters
    Point getEndEffectorPosition();
    int getNumberOfJoints() const;

    // Utility
    void displayStatus();
};

#endif // ROBOTIC_ARM_H