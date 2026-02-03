# Space Shooter

A 2D space shooter game built in C++ using SFML. This project focuses on implementing low-level game architecture (State stacks, Resource Management, Entity handling) based on *SFML Game Development* by Moreira et al.

## Project Structure
* **Core Engine:** `Game.cpp`, `World.cpp`
* **Entities:** `Aircraft.cpp`, `Entity.cpp`
* **Scene Graph:** `SceneNode.cpp`, `SpriteNode.cpp`
* **Assets:** stored in `Media/`

## Dependencies (Debian/Ubuntu)
To build this project, you need a C++17 compliant compiler and SFML headers.

```bash
sudo apt update
sudo apt install build-essential libsfml-dev cmake
```

## How to Build
### Clone the repo
```bash
git clone https://github.com/lumpy72006/spaceShooter.git
cd spaceShooter
```

### Compile with CMake
```bash
mkdir -p build
cd build
cmake ..
make
```

### Run
```bash
cd ..
./build/game
```
