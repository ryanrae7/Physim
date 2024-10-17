#include <SFML/Graphics.hpp>
#include <vector>
#include "physics.cpp"

/*

    1) Display circle or streams of circle
    2) Add Physics elements

*/

int main() {
    sf::RenderWindow window(sf::VideoMode(1980, 1080), "SFML Windows");

    // Create vector for circles to store each object 
    std::vector<sf::CircleShape> circleVector;

    // With physics class
    Physics physics (0.1f);

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
                        sf::CircleShape circle(50.f);  // Radius 50
                        circle.setFillColor(sf::Color::Red);
                        circle.setPosition(990.f, 0.f);

                        // Add to the vector at the end
                        circleVector.push_back(circle);
                    }
            }
        }

        window.clear();
        
        
        // Display stored circle Vectors
        for(sf::CircleShape& circle : circleVector){
            window.draw(circle);
            physics.updateGravity();
            physics.applyToObject(circle);
            
            // Debug statements
            std::cout <<"Velocity in the x is: " << physics.getVelocity().x << std::endl;
            std::cout <<"Velocity in the y is: " << physics.getVelocity().y << std::endl;
        }

        window.display();
        
    }

    return 0;
}