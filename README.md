# CrazyTown 
 ##### Crazytown is a game in which cars are guided by the player to houses of the same color as the cars. There is minimum one car and maximum ten.  
 ##### The cars can turn right or left. If the car receives no mouse input (a mouse click) before an intersection, it continues going straight.  
 ##### The directions are seen from the player's angle (not the driver's).  
 ##### The mouse input is as follows (I am left-handed):
> - Horizontal drive: turn up - press the left button
> - Horizotal drive: turn down - press the right button
> - Vertical drive: turn left - press the left button
> - Vertical drive: turn right - press the right button
##### There are 10 levels. The player chooses a level and enters the number at the console. 
##### The game starts when the play button is pressed.
##### Cars will stop, and so will the game, after a frontal collision.

### Instructions for building/running the project:
##### cd CrazyTown
##### cd build
##### cmake ..
##### make
##### ./CrazyTown

### File and class structure:
##### The 42 pngs must be in a build folder.
##### There are 8 *.cpp files declared in CMakeLists.txt
##### All classes except cTexture, are declared in main.cpp
##### Class cTexture is the base class to all classes that require rendering that is: cCar[i], cHouse[i], cStreet, cButton.
