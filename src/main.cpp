#include <SFML/Graphics.hpp>
#include <vector>
#include "physics.cpp"

/*

    1) Display circle or streams of circle
    2) Add Physics elements

*/

int main() {
    sf::RenderWindow window(sf::VideoMode(1980, 1080), "SFML Windows");
    //sf::CircleShape circle(50.f);  // Radius 50

    // With physics class
    Physics physics (0.1);

    // Set windows at this position
    window.setPosition(sf::Vector2i(0.f,0.f));
    // Opens windows
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
        physics.updateGravity();
        physics.applyToObject(circle);


        window.clear();
        for(int i = 0; i < 100; i++){
            sf::CircleShape circle(50.f);  // Radius 50
            circle.setFillColor(sf::Color::Red);
            circle.setPosition(990.f, 0.f);
            window.draw(circle);
        }
        window.display();
    }

    return 0;
}