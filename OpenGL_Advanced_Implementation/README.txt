Bloom/Halo Project README file - CAP4730 Final Project
------------------------------------------------------

Compilation Instructions for Visual Studio 2019:

1. Install GLFW, GLM, and STB_Master to a location on your computer.
2. Add FinalProject.cpp and Shader.h to an empty Visual Studio 2019 project.
3. Go into the project Properties -> C/C++ -> General; inside of the Additional Include Directories, add the directories at which your GLFW, STB_Master, and GLM files are located and link to the equivalent /include files. 
4. Go into Linker -> General; inside of the Additional Library Directories, add the directories at which your GLFW, STB_Master and GLM and link to the equivalent /lib files. 
5. Go into Linker -> Input; inside of the Additional Dependencies, add the dependencies opengl32.lib and glfw3.lib.
6. Put the glfw3.dll files into the directory with your .cpp/.h file.
7. Within the Visual Studio 2019 Package manager, you can also run the following commands to include the appropriate glfw and glew packages:
	Install-Package glfw
8. Download the "data" file with the .obj files and place it within the directory with FinalProject.cpp. The default object is cube.obj.
9. Download the bloom.vs, bloom.fs, light_box.fs, blur.vs, blur.fs, final.vs, and final.fs files and place them within the directory with FinalProject.cpp.
10. In order to change what object is being read and printed, locate the variable const char* fileName within the function RenderCube() and type in the name of the .obj file within the quotes. Do not load in objects with more than 5-gon face data. 
11. Upon running the program, the terminal output displays the current Bloom, Halo, and exposure settings. The default settings display Bloom lighting with the halo effect at 1.0 exposure. To toggle the Bloom lighting, press Spacebar. To toggle the halo effect with Bloom lighting enabled, press H. To alter the exposure, use Q to decrease and E to increase. Walk around the sceen using WASD and mouse cursor to look around.