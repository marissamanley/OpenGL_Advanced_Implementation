# OpenGL_Advanced_Implementation

## Features
1. Walking camera - functioning properly
Camera has the ability to move around in the 3D scene by pressing the WASD keys as
well as look around by moving the mouse cursor.

2. Textures - functioning properly
Texture images can be dynamically loaded in and mapped onto objects. Because the
faces of all loaded objects are triangles, the texture coordinates must be triangular. The
textures are loaded in using stb_image functions.

### TEXTURE PICTURES

3. Materials - functioning properly
Different material properties can be dynamically added on to objects and tweaked to
simulate different types of materials. The ambient, diffuse, specular, and shininess
values can be modified. Inside the main fragment shader, a Materials struct is used to
organize the four modifiable values.

### MATIERALS PICTURES

4. Bloom Effect - functioning properly
The bloom effect is applied to all light objects, and can be toggled on or off by pressing
the Spacebar. The amount of exposure in the scene can also be increased by holding
down Q or decreased by holding down E. The bloom effect is created by use of a
Gausian blur lighting shader where the lighting pixels are blurred horizontally and
vertically. The blurred shader buffer is additively blent into the normal scene buffer to
overlay the bloom effect on light-effected objects. The only bug involves the specular
lighting - the color of the specular reflections are white and do not reflect the color of the
light.

### BLOOM PICTURES

5. Halo Effect - functioning 95% correctly
The halo effect is applied to all light objects, and can be toggled on or off by pressing H,
given that bloom is enabled. The halo effect is created via use of an identical, pre-blur
bloom lighting shader. To generate the blur effect only around the edge of the lights to
make the halo, the identical lighting shader is subtracted from the blurred bloom shader
so that only the border blur remains. However, the only known error involves the method
by which the halo effect is created - when staring at two bloom lights head-on such that
one overlaps the other, the outputted color is incorrect due to the method by which the
identical shader buffer subtracts from the blurred bloom shader buffer.

### HALO PICTURES

### Responsibility Distribution
Marissa Manley:
- Halo lighting effect
- Bloom lighting effect
- Dynamic(Input) HDR modifications  
Katherine Teng:
- Walking Camera  

*The textures and materials were worked on equally.

### Learning Outcomes
We determined early on in our project partnership that we both were fascinated by bloom and
wanted to learn how to program the lighting effect, which led to our decision of implementing
bloom as a primary feature of our final project. It was rewarding for us to learn how to implement
bloom in OpenGL and overcome the challenges along the way, as well as to understand the
procedures to load in textures and manipulate object material status. However, the most
significant takeaway from this project was learning to implement the halo effect, which in turn let
us gain experience working with OpenGL without a direct tutorial. The previous assignments of
this course prepared us for understanding OpenGL foundationally and conceptually through the
guidance from LearnOpenGL and other online resources; with that preparation under our belts,
we took to learning the bloom implementation in such a way that the halo effect would be
implemented afterward. After much searching, we discovered that there does not exist an
OpenGL halo effect shader tutorial. We had to research and understand color buffers and
fragment shaders on our own thoroughly to figure out our own solution to create a halo effect,
which in turn resulted in a far more challenging yet rewarding experience. It allowed us to
provide our own personalized, custom touches to the otherwise already-known procedures and
strategies for common graphics features in our project like textures, materials, and bloom. It was
not in our original project proposal to implement the halo effect, but we are very glad to have
chosen to include the implementation partway through the completion of our project.

### Thoughts on Future Work
For future work on this project, we would first like to fix and complete the implementation of the
halo lighting effect, since the current state of our project has the halo effect at 95% correctness.
Implementing the halo effect has been a challenge for us, so completing the implementation
with full functionality would be very rewarding. Additionally, we would explore a solution to have
the specular reflections reflect the color of the light source correctly. With an entirely functional
and complete project, we would like to explore adding more advanced functionality to it as well,
such as environtment mapping for mirror reflections. Lastly, we would modify our current bloom
implementation such that different light sources could display different amounts of bloom applied
to them, similarly to how we can modify the exposure in the scene.

### Acknowledgements
https://learnopengl.com/Advanced-Lighting/Bloom  
https://learnopengl.com/Advanced-Lighting/HDR  
https://learnopengl.com/Lighting/Materials  
https://learnopengl.com/Getting-started/Textures  
https://learnopengl.com/Getting-started/Camera  
https://gamedev.stackexchange.com/questions/32797/creating-a-highlight-halo-around-a-selected-object  
https://stackoverflow.com/questions/56420822/how-to-add-a-neon-glow-effect-to-an-widget-border-shadow  
