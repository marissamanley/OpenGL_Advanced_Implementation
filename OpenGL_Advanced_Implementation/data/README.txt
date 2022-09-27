OpenGL Warmup README file - CAP4730 Assignment 2
---------------------------------------------

Compilation Instructions for Visual Studio 2019:

1. Install GLFW, GLEW, and GLM to a location on your computer.
2. Add OpenGLWarmup.cpp to an empty Visual Studio 2019 project.
3. Go into the project Properties -> C/C++ -> General; inside of the Additional Include Directories, add the directories at which your GLFW, GLEW, and GLM files are located and link to the equivalent /include files. 
4. Go into Linker -> General; inside of the Additional Library Directories, add the directories at which your GLFW, GLEW, and GLM and link to the equivalent /lib files. 
5. Go into Linker -> Input; inside of the Additional Dependencies, add the dependencies opengl32.lib, glfw3.lib, and glew32s.lib .
6. Put the glew32.dll and glfw3.dll files into the directory with your RayTracer file.
7. Within the Visual Studio 2019 Package manager, you can also run the following commands to include the appropriate glfw and glew packages:
	Install-Package glfw
	Install-Package glew
8. Download the "data" file with the .obj files and place it within the directory with OpenGLWarmup.cpp.
9. Download the VertexShader.vs and FragmentShader.fs text files and place them within the directory with OpenGLWarmup.cpp.
9. In order to change what object is being read and printed, locate the variable const char* fileName and type in the name of the .obj file within the quotes. You may have to alter the scaling numbers, which can be found in glm::mat4 matrix m located right above const char* fileName. The default object is the cube scaled down and rotated. Do not load in objects with more than 5-gon face data. 	