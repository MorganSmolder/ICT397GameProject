BAM! Readme for our game.

Read it!

It explains stuff!

Basically I've set up the engine foundation. LUA integration, asset loading, and scenemanagment has been implemented.

I've also done some work on 3d audio, its working but still has a few kinks I need to sort out.

The upload features a few demo's I've created to show off the existing functionality. Run the demo scripts by changing this line in main:

ENG.Initalise("./Resources/Scripts/Demo3/startup.lua")

Switch between the directories Demo3, Demo2, and Demo1 to view the diffrent consifgurations.

Short summary of each:

Demo 1:
Illustrates asset loading and inter game object messaging features.

Demo 2:
Shows how scenes can be changed from script through messaging interface.

Demo 3 (wip):
Demonstrates current implementation of 3D sound.

All the requried linkages should be configured. Mat, I've already set up the project to include the GLFW libs and dll. Just add the libraries in the linker input for debug and release and you should be good to go!

Right now glut is still linked, as the texture manager depends on OpenGL a little bit. Once we've added your render code this can be removed.

Cheers,
Morgan