# Physics Simulation Project

## Overview
This project is a simple physics simulation created using SFML in C++. For now, it displays projectile motion (w/out) object collision which will be added along the way. Other plans include brownian motion simulation, rigid body physics, and more.

## Features
- **Circle Spawning**: Circles are continuously spawned at random positions and velocities.
- **Gravity Effect**: Circles fall under the influence of gravity.
- **Collision Detection**: Basic collision detection between circles.
- **Rigid Borders**: Circles bounce off the window edges.

## Installation
1. **Clone the Repository**:
    ```sh
    git clone https://github.com/yourusername/PhysicsSimulation.git
    ```
2. **Navigate to the Project Directory**:
    ```sh
    cd src
    ```
3. **Compile the Project**:
    ```sh
    g++ main.cpp -o project -lsfml-graphics -lsfml-system -lsfml-window
    ```
4. **Run the Executable**:
    ```sh
    ./project
    ```

## Usage
- The simulation runs automatically once you start the program.
- Circles will spawn and bounce off the window borders.
- The position of the first circle will be displayed on the screen.
