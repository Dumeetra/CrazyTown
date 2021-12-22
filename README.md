# CrazyTown 
 ##### Crazytown is a game in which cars are guided by the player to houses of the same color as the cars. There is minimum one car and maximum ten.  
 ##### The cars can turn right or left. If the car receives no mouse input (a mouse click ) before an intersection, it continues going straight.  
 ##### The directions are seen from the player's angle (not the driver's).  
 ##### The mouse input is as follows:
> - If the car is driving horizontally to turn up: press the left button
> - Horizotal drive: turn down - press the right button
> - Vertical drive: turn left - press the left button
> - Vertical drive: turn right - press the right button
##### There are 10 levels. The player chooses a level and enters the number at the console. 
##### The game starts when the play button is pressed.
##### Cars will stop, and so will the game, after a frontal collision.

### Instructions for building/running the project:
##### cd CrazyTown
##### cd build
##### sudo apt-get install libsdl2-image-dev
##### cmake ..
##### make
##### ./CrazyTown

### File and class structure:
##### The 42 pngs must be in a build folder.
##### There are 8 *.cpp files declared in CMakeLists.txt
##### All classes except cTexture, are declared in main.cpp
##### Class cTexture is the base class to all classes that require rendering that is: cCar[i], cHouse[i], cStreet, cButton.

### 5 Criteria
> - The project demonstrates an understanding of C++ functions and control structures.
> - The project accepts user input and processes the input. (main.cpp/line 43).
> - The project uses Object Oriented Programming techniques.
> - Classes use appropriate access specifiers for class members.
> - Class constructors utilize member initialization lists.
