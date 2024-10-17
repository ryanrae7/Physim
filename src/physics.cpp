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
            if(velocity.y < 9.8f){
                velocity.y += gravity;
                velocity.x += gravity;
            }
        }

        // Return velocity
        sf::Vector2f getVelocity() const{
            return velocity;
        }

        void applyToObject(sf::CircleShape& circle){
            circle.move(velocity);
        }
    
};