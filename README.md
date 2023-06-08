### A simple "impossible game" clone made in C++ using the SDL2 library.

Press space to jump, try to not hit any of the obstacles.![Impossible game clone](https://user-images.githubusercontent.com/112474358/232331604-ec1cab35-8a66-4267-adcb-866e22550d64.png)


## Design Patterns used

### GameLoop Pattern
Used in 01_hello_SDL.cpp on row 72 to provide the basic logic structure of the game.
Since its a realtime game it makes a lot of sense to have a loop like this.

### EventQueue Pattern
Used in 01_hello_SDL.cpp on row 78 to handle user inputs and other window events.
Using this pattern is required since there can be multiple events per frame, so if we only checked one per frame we could miss important stuff.

## Advanced C++ Features used

### Shared pointer
Used in SpikeFactory.cpp on row 7 because it automates memory management


### mt19937 random number generation
Used in SpikeFactory.cpp on row 22 because its a good random number generation algorithm.

### Chrono
Used in Spike.cpp on row 8 to provide a DeltaTime value, so the game always runs at the same speed no matter what fps it runs at.
