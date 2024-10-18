#include <SFML/Graphics.hpp>
#include <vector>
#include <stdio.h>
#include <iostream>
#include "physics.cpp"

/*

    1) Display circle or streams of circle
    2) Add Physics elements

*/

int main() {
    sf::RenderWindow window(sf::VideoMode(1980, 1080), "SFML Windows");
    sf::Text numberCircleText; 

    // Create vector for circles to store each object 
    std::vector<sf::CircleShape> circleVector;
    std::vector<Physics> physicsVector;

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
                // If space is pressed, display circle
                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::Space){
                        std::cout << "Space Bar has been pressed!" << std::endl;
                        
                        // Create new circle
                        sf::CircleShape circle(25.0f);  // radius 25
                        circle.setFillColor(sf::Color::Red);
                        //circle.setPosition(1980.0f, 1080.0f);

                        // With physics class
                        Physics physics (9.8f, sf::Vector2f(100.0f, -100.0f), sf::Vector2f(0.0f, 1080.0f));


                        // Add to the vector at the end
                        circleVector.push_back(circle);
                        physicsVector.push_back(physics);
                    }
            }
        }

        window.clear();
        
        
        // Display stored circle Vectors
        for(int i = 0; i < circleVector.size(); ++i){
            window.draw(circleVector[i]);
            physicsVector[i].applyToObject(circleVector[i], 1.0/60.0);
            
            // Update print statement
            numberCircleText.setString("# of Circles: %d" + std::to_string(i + 1));
            numberCircleText.setPosition(0,0); // Make position at the top
            numberCircleText.setFillColor(sf::Color::White);
            window.draw(numberCircleText);

            // Debug statements
            std::cout <<"Velocity in the x is: " << physicsVector[i].getVelocity().x << std::endl;
            std::cout <<"Velocity in the y is: " << physicsVector[i].getVelocity().y << std::endl;
        }

        window.display();
        
    }

    return 0;
}