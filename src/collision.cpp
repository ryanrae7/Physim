#ifndef COLLISION_H
#define COLLISION_H

#include <iostream>
#include "physics.cpp"

/*

    Collision(Physics physics (9.8f, sf::Vector2f(100.0f, -150.0f), sf::Vector2f(0.0f, 1080.0f)));

*/

class Collision{
    float position_x;
    float position_y;
    // radius of each circle that we want collision physics on
    float radius;


    public:
        Collision(Physics positional, float rad){
            // Assign positional data from physics here
            position_x = positional.getPosition().x;
            position_y = positional.getPosition().y;
            radius = rad;
        }

        bool is_colliding(Collision& etc){
            float dx = position_x - etc.position_x;
            float dy = position_y - etc.position_y;

            float distance = std::sqrt(dx * dx + dy * dy);

            return distance < (radius + etc.radius);
        }
        
        
};


#endif