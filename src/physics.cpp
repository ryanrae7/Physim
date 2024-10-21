#ifndef PHYSICS_H
#define PHYSICS_H

#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <numbers>
#include <time.h>

/*
    Can defenitely incorpoate delta time instead of 1.0f/60.0f ***
*/

class Physics {
    const double pi = 2 * acos(0.0);
    sf::Vector2f velocity;
    sf::Vector2f position;
    float gravity;
    float angle;
    float time;

    public:
        Physics(float g, sf::Vector2f initialVelocity, sf::Vector2f initialPosition, float theta, float timestep){
            // Initialize gravity and initial velocity
            gravity = g;
            velocity = initialVelocity;
            position = initialPosition;
            angle = theta;
            time = timestep;
        }

        void applyVelocity() {
            // Apply gravity to vertical velocity
            velocity.y += gravity * time;
            
            // Update position based on velocity
            position.x += velocity.x * time;
            position.y += velocity.y * time;
        }

        sf::Vector2f getVelocity() const {
            return velocity;
        }

        sf::Vector2f getPosition() {
            float radianAngle = angle * pi / 180.0;
            float x = velocity.x * std::cos(radianAngle) * time;
            float y = velocity.y * std::sin(radianAngle) * time - 0.5 * gravity * time * time;
            return sf::Vector2f(x, y);
        }

        void applyToObject(sf::CircleShape& circle) {
            applyVelocity();
            circle.setPosition(position);
        }
};

#endif