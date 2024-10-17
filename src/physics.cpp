#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>



class Physics{
    sf::Vector2f velocity;
    float gravity;
    float rad;

    public:
        Physics(float x){
            // Set initial gravity
            gravity = x;
            velocity = sf::Vector2f(0.f, 0.f);
        }
        void updateGravity(){
            velocity.y += gravity;
        }

        // Return velocity
        sf::Vector2f getVelocity() const{
            return velocity;
        }

        void applyToObject(sf::CircleShape& circle){
            circle.move(velocity);
        }
    
};