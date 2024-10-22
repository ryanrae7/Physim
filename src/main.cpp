#include <SFML/Graphics.hpp>
#include <vector>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include "physics.cpp"
#include "collision.cpp"

/*

    1) Display circle or streams of circle
    2) Add Physics elements

*/
const double pi = 2 * acos(0.0);
int main() {
    sf::RenderWindow window(sf::VideoMode(1980, 1080), "SFML Windows");

    // Create vector for circles to store each object 
    std::vector<sf::CircleShape> circleVector;
    std::vector<Physics> physicsVector;
    std::vector<Collision> collisionVector;

    // Initalize time
    sf::Clock clock;
    sf::Clock circleSpawnClock;
    float spawnInterval = 0.05f;

    // Set windows at this position
    window.setPosition(sf::Vector2i(0.f,0.f));
    // Opens windows
    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        
        if(circleSpawnClock.getElapsedTime().asSeconds() > spawnInterval){
            circleSpawnClock.restart(); // restart to get back into the if statement
            // Create new circle
            sf::CircleShape circle(5.0f);  // radius 25
            circle.setFillColor(sf::Color::Red);
            //circle.setPosition(1980.0f, 1080.0f);

            // With physics class
            float x_velocity_random = rand() % 200 + (101);
            float y_velocity_random = rand() % 200 + (-101);

            Physics physics (9.8f, sf::Vector2f(x_velocity_random, y_velocity_random), sf::Vector2f(5.0f, 5.0f), pi/2, 1.0/60.0);

            // Add to the vector at the end
            circleVector.push_back(circle);
            physicsVector.push_back(physics);
            collisionVector.push_back(Collision(physics, circle.getRadius()));
        }
        


        window.clear();
        
        
        // Display stored circle Vectors
        int i = 0;
        while (i < circleVector.size()) {
            if (i == 50) break; // change number of circles you want to "spawn" into your window
            window.draw(circleVector[i]);
            physicsVector[i].applyToObject(circleVector[i]);
            //std::cout << "Number of objects: " << i + 1 << std::endl;
            ++i;
        }



        /*
        
            CODE DOESN'T WORK!!!!
        
        */
        // Check for collisions
        int k = 0;
        while (k < collisionVector.size()) {
            int j = k + 1;
            while (j < collisionVector.size()) {
                if (collisionVector[k].IsPointInCircle(collisionVector[j])) {
                    std::cout << "Collision detected between circle " << k << " and circle " << j << std::endl;
                    sf::Vector2f tempVelocity = physicsVector[k].getVelocity();
                    physicsVector[k].set_velocity(physicsVector[j].getVelocity());
                    physicsVector[j].set_velocity(tempVelocity);
                }
                ++j;
            }
            ++k; // Corrected increment from `i` to `k`
        }



        if(!circleVector.empty()){
            sf::Vector2f position = circleVector[0].getPosition();
            //std::cout << "Circle 0 position: (" << std::to_string(position.x) << ", " << std::to_string(position.y) << ")" << std::endl;
        }

        window.display();
        
    }

    return 0;
}