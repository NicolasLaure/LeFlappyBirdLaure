# Le Flappy Bird


Le Flappy Bird is a game where you control a vampire CheeseCake, it's made with raylib


## Controls:
Pause with Escape or middle mouse Button.

### Single Player: 

Jump with either "Spacebar", left click or tap (on web from a mobile device).



### Multiplayer:

Player 1 jumps with "Spacebar" in pc or by tapping on the left side of the screen in mobile.

Player 2 jumps with Left click in pc or by tapping on the right side of the screen in mobile.



## Credits:
### Programmers:
[Nicolás Laure](https://www.linkedin.com/in/nicolas-laure/).

[Maximiliano Feldman](https://www.linkedin.com/in/maximiliano-alejo-feldman-27b256160/).

### Audio:
Music by Nicolás Laure.

Interface Sounds by Kenney: [Kenney's Website](https://kenney.nl/assets/impact-sounds).

Impact Sounds by Kenney: [Kenney's Website](https://kenney.nl/assets/impact-sounds).

### Art:

Mountains BackGround by Ansimuz.

Cheescake by Thurraya.


## How To Play:

### Web:
You only need to click the "Run Game" upper in this page! 

### Web from Android:
 If you are on web from a mobile device, please click the "Fullscreen button" to be able to see the whole game

### Desktop:
1. Download the file below.

2. Unzip the .zip file.

3. Play by executing .exe file.



## Web Version Development:

To accomplish the web build it was necessary to follow the steps as seen in  [Raylib documentation](https://github.com/raysan5/raylib/wiki/Working-for-Web-(HTML5)). After configuring the Makefile, everything was set to compile raylib using the following command.

```

emcc -c rcore.c -Os -Wall -DPLATFORM_WEB -DGRAPHICS_API_OPENGL_ES2

emcc -c rshapes.c -Os -Wall -DPLATFORM_WEB -DGRAPHICS_API_OPENGL_ES2

emcc -c rtextures.c -Os -Wall -DPLATFORM_WEB -DGRAPHICS_API_OPENGL_ES2

emcc -c rtext.c -Os -Wall -DPLATFORM_WEB -DGRAPHICS_API_OPENGL_ES2

emcc -c rmodels.c -Os -Wall -DPLATFORM_WEB -DGRAPHICS_API_OPENGL_ES2

emcc -c utils.c -Os -Wall -DPLATFORM_WEB

emcc -c raudio.c -Os -Wall -DPLATFORM_WEB

emar rcs libraylib.a rcore.o rshapes.o rtextures.o rtext.o rmodels.o utils.o raudio.o

```

Once Raylib is compiled with Web Configuration, project is ready to be compiled into an .html file using the following command from the location of the solution.

```
emcc -o bin/Release/web/LeFlappyBird.html src/main.cpp src/game.cpp src/utils/screen.cpp src/utils/math.cpp src/utils/timer.cpp src/uiComponents/button.cpp src/screens/credits.cpp src/screens/gameplay.cpp src/screens/menu.cpp src/screens/rules.cpp src/managers/backgroundManager.cpp src/managers/pauseManager.cpp src/managers/screenManager.cpp src/managers/uiManager.cpp src/managers/wallsManager.cpp src/entities/bird.cpp src/entities/wall.cpp src/constants/dimensions.cpp src/assets/assetManager.cpp src/assets/fontManager.cpp -Wall -std=c++14 -D_DEFAULT_SOURCE -Wno-missing-braces -Wunused-result -Os -I. -I D:/Software/raylib-master/src -I D:/Software/raylib-master/src/external -I "D:/Software/IMAGE/Desarrollo I/LeFlappyBirdLaure/src" -L. -L D:/Software/raylib-master/src -s USE_GLFW=3 -s ASYNCIFY -s TOTAL_MEMORY=67108864 -s FORCE_FILESYSTEM=1 --preload-file res/images --preload-file res/audio --shell-file D:/Software/raylib-master/src/shell.html D:/Software/raylib-master/src/web/libraylib.a -DPLATFORM_WEB -s 'EXPORTED_FUNCTIONS=["_free","_malloc","_main"]'-s EXPORTED_RUNTIME_METHODS=ccall
```

After the process is finished, all there is left is to change .hmtl file name to "index.html" to then zip it and upload it to Itch.io

