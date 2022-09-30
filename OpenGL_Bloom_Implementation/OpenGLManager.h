#pragma once
#include "include/glad/glad.h"
#include "stb_image.h"
#include "GLFW/glfw3.h"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
#include "glm/mat4x4.hpp"
#include "glm/common.hpp"
#include "glm/gtx/string_cast.hpp"
#include "glm/ext.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Shader.h"
#include <iostream>

#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <array>
/*
* This class maintains all OpenGL related content. 
*/
class OpenGLManager {
public:
	OpenGLManager();
	void Start();
	void processInput(GLFWwindow* window);
	unsigned int loadTexture(const char* path, bool gammaCorrection);
	void renderQuad();
	void renderCube();
};

