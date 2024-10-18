#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <time.h>



class Physics {
    sf::Vector2f velocity;
    float gravity;
    sf::Vector2f position;

public:
    Physics(float g, sf::Vector2f initialVelocity, sf::Vector2f initialPosition) : 
        gravity(g), velocity(initialVelocity), position(initialPosition) {
        // Initialize gravity and initial velocity
    }

    void applyVelocity(float timeStep) {
        // Apply gravity to vertical velocity
        velocity.y += gravity * timeStep;
        
        // Update position based on velocity
        position.x += velocity.x * timeStep;
        position.y += velocity.y * timeStep;
    }

    sf::Vector2f getVelocity() const {
        return velocity;
    }

    sf::Vector2f getPosition() const {
        return position;
    }

    void applyToObject(sf::CircleShape& circle, float timeStep) {
        applyVelocity(timeStep);
        circle.setPosition(position);
    }
};