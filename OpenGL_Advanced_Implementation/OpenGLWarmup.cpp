//// template based on material from learnopengl.com
//#define GLFW_INCLUDE_NONE
//#define GLEW_STATIC
//#define STB_IMAGE_IMPLEMENTATION
////#include "glad/glad.h"
//#include "stb_image.h"
//#include "GLFW/glfw3.h"
//#include "GL/glew.h"
//#include "glm/vec3.hpp"
//#include "glm/vec4.hpp"
//#include "glm/mat4x4.hpp"
//#include "glm/glm.hpp"
//#include "glm/common.hpp"
//#include "glm/gtx/string_cast.hpp"
//#include "glm/ext.hpp"
//#include "glm/gtc/matrix_transform.hpp"
//
////#include "Shader.h"
//
//#include <iostream>
//#include <string>
//#include <fstream>
//#include <sstream>
//#include <algorithm>
//#include <vector>
//#include <array>
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void renderQuad();
//float* loadObj(const char* fileName);
//
//
//// settings
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//bool bloom = true;
//bool bloomKeyPressed = false;
//float exposure = 1.0f;
//
//const char* vertexShaderSource = "";
//const char* fragmentShaderSource = "";
//const char* LCvertexShaderSource = "";
//const char* LCfragmentShaderSource = "";
//const char* BvertexShaderSource = "";
//const char* BfragmentShaderSource = "";
//const char* BLvertexShaderSource = "";
//const char* BLfragmentShaderSource = "";
//
//
//glm::mat4 mvp = { //default matrix
//   1,0,0,0,
//   0,1,0,0,
//   0,0,1,0,
//   0,0,0,1 };
//
//glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
//glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
//glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
//
//glm::vec3 lightPosition(1.0f, 1.0f, 2.0f);
//
//float deltaTime = 0.0f;	// Time between current frame and last frame
//float lastFrame = 0.0f; // Time of last frame
//
//bool firstMouse = true;
//float lastX = 400.0f;
//float lastY = 300.0f;
//float yaw = -90.0f;
//float pitch = 0.0f;
//
//void mouse_callback(GLFWwindow* window, double xpos, double ypos)
//{
//    if (firstMouse)
//    {
//        lastX = (float)xpos;
//        lastY = (float)ypos;
//        firstMouse = false;
//    }
//
//    float xoffset = xpos - lastX;
//    float yoffset = lastY - ypos;
//    lastX = xpos;
//    lastY = ypos;
//
//    float sensitivity = 0.1f;
//    xoffset *= sensitivity;
//    yoffset *= sensitivity;
//
//    yaw += xoffset;
//    pitch += yoffset;
//
//    if (pitch > 89.0f)
//        pitch = 89.0f;
//    if (pitch < -89.0f)
//        pitch = -89.0f;
//
//    glm::vec3 direction;
//    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
//    direction.y = sin(glm::radians(pitch));
//    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
//    cameraFront = glm::normalize(direction);
//}
//
//int main()
//{
//    glm::vec3 direction;
//
//    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
//    direction.y = sin(glm::radians(pitch));
//    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
//
//    //std::cout << glm::to_string(projection);
//    const char* shaderName = "phong.vs";
//    std::ifstream vfile(shaderName);
//    std::string line = "";
//    std::string text;
//    while (std::getline(vfile, line))
//        text += line + "\n";
//    vertexShaderSource = text.c_str();
//
//    const char* shaderName1 = "phong.fs";
//    std::ifstream vfile1(shaderName1);
//    std::string line1 = "";
//    std::string text1;
//    while (std::getline(vfile1, line1))
//        text1 += line1 + "\n";
//    fragmentShaderSource = text1.c_str();
//
//
//    //lightcube
//    const char* LCshaderName = "lightcube.vs";
//    std::ifstream LCvfile(LCshaderName);
//    std::string LCline = "";
//    std::string LCtext;
//    while (std::getline(LCvfile, LCline))
//        LCtext += LCline + "\n";
//    LCvertexShaderSource = LCtext.c_str();
//
//    const char* LCshaderName1 = "lightcube.fs";
//    std::ifstream LCvfile1(LCshaderName1);
//    std::string LCline1 = "";
//    std::string LCtext1;
//    while (std::getline(LCvfile1, LCline1))
//        LCtext1 += LCline1 + "\n";
//    LCfragmentShaderSource = LCtext1.c_str();
//
//    //blur
//    const char* BshaderName = "blur.vs";
//    std::ifstream Bvfile(BshaderName);
//    std::string Bline = "";
//    std::string Btext;
//    while (std::getline(Bvfile, Bline))
//        Btext += Bline + "\n";
//    BvertexShaderSource = Btext.c_str();
//
//    const char* BshaderName1 = "blur.fs";
//    std::ifstream Bvfile1(BshaderName1);
//    std::string Bline1 = "";
//    std::string Btext1;
//    while (std::getline(Bvfile1, Bline1))
//        Btext1 += Bline1 + "\n";
//    BfragmentShaderSource = Btext1.c_str();
//
//
//    //bloom
//    const char* BLshaderName = "bloom.vs";
//    std::ifstream BLvfile(BLshaderName);
//    std::string BLline = "";
//    std::string BLtext;
//    while (std::getline(BLvfile, BLline))
//        BLtext += BLline + "\n";
//    BLvertexShaderSource = BLtext.c_str();
//
//    const char* BLshaderName1 = "bloom.fs";
//    std::ifstream BLvfile1(BLshaderName1);
//    std::string BLline1 = "";
//    std::string BLtext1;
//    while (std::getline(BLvfile1, BLline1))
//        BLtext1 += BLline1 + "\n";
//    BLfragmentShaderSource = BLtext1.c_str();
//
//
//
//    // glfw: initialize and configure
//    // ------------------------------
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#ifdef __APPLE__
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif
//
//    // glfw window creation
//    // --------------------
//    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "viewGL", NULL, NULL);
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//
//    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//    glfwSetCursorPosCallback(window, mouse_callback);
//    // // glew: load all OpenGL function pointers
//    glewInit();
//
//
//    // build and compile our shader program #1
//    // ------------------------------------
//    // vertex shader
//    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//    glCompileShader(vertexShader);
//    // check for shader compile errors
//    int success;
//    char infoLog[512];
//    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//    // fragment shader
//    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//    glCompileShader(fragmentShader);
//    // check for shader compile errors
//    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//    // link shaders
//    unsigned int shaderProgram = glCreateProgram();
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram);
//    // check for linking errors
//    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//    if (!success) {
//        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//    }
//    glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader);
//
//
//    //LIGHT CUBEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
//    // build and compile our shader program #1
//    // ------------------------------------
//    // vertex shader
//    unsigned int LCvertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(LCvertexShader, 1, &LCvertexShaderSource, NULL);
//    glCompileShader(LCvertexShader);
//    // check for shader compile errors
//    int LCsuccess;
//    char LCinfoLog[512];
//    glGetShaderiv(LCvertexShader, GL_COMPILE_STATUS, &LCsuccess);
//    if (!LCsuccess)
//    {
//        glGetShaderInfoLog(LCvertexShader, 512, NULL, LCinfoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << LCinfoLog << std::endl;
//    }
//    // fragment shader
//    unsigned int LCfragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(LCfragmentShader, 1, &LCfragmentShaderSource, NULL);
//    glCompileShader(LCfragmentShader);
//    // check for shader compile errors
//    glGetShaderiv(LCfragmentShader, GL_COMPILE_STATUS, &LCsuccess);
//    if (!LCsuccess)
//    {
//        glGetShaderInfoLog(LCfragmentShader, 512, NULL, LCinfoLog);
//        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << LCinfoLog << std::endl;
//    }
//    // link shaders
//    unsigned int LCshaderProgram = glCreateProgram();
//    glAttachShader(LCshaderProgram, LCvertexShader);
//    glAttachShader(LCshaderProgram, LCfragmentShader);
//    glLinkProgram(LCshaderProgram);
//    // check for linking errors
//    glGetProgramiv(LCshaderProgram, GL_LINK_STATUS, &LCsuccess);
//    if (!LCsuccess) {
//        glGetProgramInfoLog(LCshaderProgram, 512, NULL, LCinfoLog);
//        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << LCinfoLog << std::endl;
//    }
//    glDeleteShader(LCvertexShader);
//    glDeleteShader(LCfragmentShader);
//    //END OF LIGHT CUBEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
//    //BEGINNIG OF BLURRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
//    unsigned int BvertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(BvertexShader, 1, &BvertexShaderSource, NULL);
//    glCompileShader(BvertexShader);
//    // check for shader compile errors
//    int Bsuccess;
//    char BinfoLog[512];
//    glGetShaderiv(BvertexShader, GL_COMPILE_STATUS, &Bsuccess);
//    if (!Bsuccess)
//    {
//        glGetShaderInfoLog(BvertexShader, 512, NULL, BinfoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << BinfoLog << std::endl;
//    }
//    // fragment shader
//    unsigned int BfragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(BfragmentShader, 1, &BfragmentShaderSource, NULL);
//    glCompileShader(BfragmentShader);
//    // check for shader compile errors
//    glGetShaderiv(BfragmentShader, GL_COMPILE_STATUS, &Bsuccess);
//    if (!Bsuccess)
//    {
//        glGetShaderInfoLog(BfragmentShader, 512, NULL, BinfoLog);
//        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << BinfoLog << std::endl;
//    }
//    // link shaders
//    unsigned int BshaderProgram = glCreateProgram();
//    glAttachShader(BshaderProgram, BvertexShader);
//    glAttachShader(BshaderProgram, BfragmentShader);
//    glLinkProgram(BshaderProgram);
//    // check for linking errors
//    glGetProgramiv(BshaderProgram, GL_LINK_STATUS, &Bsuccess);
//    if (!Bsuccess) {
//        glGetProgramInfoLog(BshaderProgram, 512, NULL, BinfoLog);
//        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << BinfoLog << std::endl;
//    }
//    glDeleteShader(BvertexShader);
//    glDeleteShader(BfragmentShader);
//    //END OF BLURRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR
//    //BEGINNIG OF BLOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOM
//    unsigned int BLvertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(BLvertexShader, 1, &BLvertexShaderSource, NULL);
//    glCompileShader(BLvertexShader);
//    // check for shader compile errors
//    int BLsuccess;
//    char BLinfoLog[512];
//    glGetShaderiv(BLvertexShader, GL_COMPILE_STATUS, &BLsuccess);
//    if (!BLsuccess)
//    {
//        glGetShaderInfoLog(BLvertexShader, 512, NULL, BLinfoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << BLinfoLog << std::endl;
//    }
//    // fragment shader
//    unsigned int BLfragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(BLfragmentShader, 1, &BLfragmentShaderSource, NULL);
//    glCompileShader(BLfragmentShader);
//    // check for shader compile errors
//    glGetShaderiv(BLfragmentShader, GL_COMPILE_STATUS, &BLsuccess);
//    if (!BLsuccess)
//    {
//        glGetShaderInfoLog(BLfragmentShader, 512, NULL, BLinfoLog);
//        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << BLinfoLog << std::endl;
//    }
//    // link shaders
//    unsigned int BLshaderProgram = glCreateProgram();
//    glAttachShader(BLshaderProgram, BLvertexShader);
//    glAttachShader(BLshaderProgram, BLfragmentShader);
//    glLinkProgram(BLshaderProgram);
//    // check for linking errors
//    glGetProgramiv(BLshaderProgram, GL_LINK_STATUS, &BLsuccess);
//    if (!BLsuccess) {
//        glGetProgramInfoLog(BLshaderProgram, 512, NULL, BLinfoLog);
//        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << BLinfoLog << std::endl;
//    }
//    glDeleteShader(BLvertexShader);
//    glDeleteShader(BLfragmentShader);
//    //end of gblommmOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOM
//    
//
//    // set up vertex data (and buffer(s)) and configure vertex attributes
//    // ------------------------------------------------------------------
//
//    //float* vertices = loadObj("data/cube.obj");
//    const char* fileName = "data/cube.obj";
//
//    std::vector<glm::vec3> vertPos;
//    std::vector<glm::vec3> vertNorms;
//    std::vector<glm::vec3> vertFaces;
//    std::stringstream s;
//    std::ifstream file(fileName);
//    std::string l = "";
//    std::string prefix = "";
//
//    while (std::getline(file, l))
//    {
//        s.clear();
//        s.str(l);
//        s >> prefix;
//
//        if (prefix == "v")
//        {
//            float pos[3] = { 0,0,0 };
//            s >> pos[0] >> pos[1] >> pos[2];
//            vertPos.push_back(glm::vec3(pos[0], pos[1], pos[2]));
//        }
//        else if (prefix == "vn")
//        {
//            float pos[3] = { 0,0,0 };
//            s >> pos[0] >> pos[1] >> pos[2];
//            vertNorms.push_back(glm::vec3(pos[0], pos[1], pos[2]));
//        }
//        else if (prefix == "f")
//        {
//            int vertNums[5] = { 0,0,0,0,0 };
//            s >> vertNums[0];
//            if (s.peek() == ' ')
//                s >> vertNums[1] >> vertNums[2];
//            else
//            {
//                s.ignore(30, ' ');
//                s >> vertNums[1];
//                s.ignore(30, ' ');
//                s >> vertNums[2];
//                s.ignore(30, ' ');
//            }
//            vertFaces.push_back(glm::vec3(vertNums[0], vertNums[2], vertNums[1]));
//            s >> vertNums[3];
//            if (vertNums[3] != 0)
//            {
//                vertFaces.push_back(glm::vec3(vertNums[0], vertNums[3], vertNums[2]));
//                s >> vertNums[4];
//                if (vertNums[4] != 0)
//                    vertFaces.push_back(glm::vec3(vertNums[0], vertNums[4], vertNums[3]));
//            }
//        }
//    }
//
//    float vertices[200000];
//    //std::vector<float> vertexes;
//    //unsigned int indices[10000]; //for EBO
//    int j = 0;
//    int k = 0;
//    for (unsigned int i = 0; i < vertFaces.size(); i++)
//    {
//        glm::vec3 vecA = vertPos[vertFaces[i].z - 1] - vertPos[vertFaces[i].x - 1];
//        glm::vec3 vecB = vertPos[vertFaces[i].y - 1] - vertPos[vertFaces[i].x - 1];
//        glm::vec3 result = cross(vecA, vecB);
//
//        vertices[j++] = vertPos[vertFaces[i].x - 1].x; //positions
//        vertices[j++] = vertPos[vertFaces[i].x - 1].y;
//        vertices[j++] = vertPos[vertFaces[i].x - 1].z;
//
//        vertices[j++] = result.x; //normals
//        vertices[j++] = result.y;
//        vertices[j++] = result.z;
//
//        //vertices[j++] = 0.0f; //textures
//        //vertices[j++] = 0.0f;
//        vertices[j++] = 0.0f; //textures
//        vertices[j++] = 1.0f;
//
//        vertices[j++] = vertPos[vertFaces[i].y - 1].x;
//        vertices[j++] = vertPos[vertFaces[i].y - 1].y;
//        vertices[j++] = vertPos[vertFaces[i].y - 1].z;
//
//        vertices[j++] = result.x;
//        vertices[j++] = result.y;
//        vertices[j++] = result.z;
//
//        /*vertices[j++] = 0.5f;
//        vertices[j++] = 1.0f;*/
//        vertices[j++] = 0.5f;
//        vertices[j++] = 0.0f;
//
//        vertices[j++] = vertPos[vertFaces[i].z - 1].x;
//        vertices[j++] = vertPos[vertFaces[i].z - 1].y;
//        vertices[j++] = vertPos[vertFaces[i].z - 1].z;
//
//        vertices[j++] = result.x;
//        vertices[j++] = result.y;
//        vertices[j++] = result.z;
//
//        /*vertices[j++] = 1.0f;
//        vertices[j++] = 0.0f;*/
//        vertices[j++] = 1.0f;
//        vertices[j++] = 1.0f;
//    }
//    unsigned int numVertices = sizeof(vertices) / 8;
//    std::cout << "num vertices rn is " << sizeof(vertices) / sizeof(vertices[0]) << std::endl;
//
//    unsigned int VBO, VAO, EBO;
//    glGenVertexArrays(1, &VAO);
//    glGenBuffers(1, &VBO);
//    //glGenBuffers(1, &EBO);
//    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//    glBindVertexArray(VAO);
//    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//    //glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
//
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//    glEnableVertexAttribArray(2);
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    glBindVertexArray(0);
//
//    unsigned int hdrFBO;
//    glGenFramebuffers(1, &hdrFBO);
//    glBindFramebuffer(GL_FRAMEBUFFER, hdrFBO);
//    // create 2 floating point color buffers (1 for normal rendering, other for brightness threshold values)
//    unsigned int colorBuffers[2];
//    glGenTextures(2, colorBuffers);
//    for (unsigned int i = 0; i < 2; i++)
//    {
//        glBindTexture(GL_TEXTURE_2D, colorBuffers[i]);
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, SCR_WIDTH, SCR_HEIGHT, 0, GL_RGBA, GL_FLOAT, NULL);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);  // we clamp to the edge as the blur filter would otherwise sample repeated texture values!
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//        // attach texture to framebuffer
//        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, GL_TEXTURE_2D, colorBuffers[i], 0);
//    }
//
//    unsigned int rboDepth;
//    glGenRenderbuffers(1, &rboDepth);
//    glBindRenderbuffer(GL_RENDERBUFFER, rboDepth);
//    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, SCR_WIDTH, SCR_HEIGHT);
//    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, rboDepth);
//    // tell OpenGL which color attachments we'll use (of this framebuffer) for rendering 
//
//    unsigned int attachments[2] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1 };
//    glDrawBuffers(2, attachments);
//    // finally check if framebuffer is complete
//    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
//        std::cout << "Framebuffer not complete!" << std::endl;
//    glBindFramebuffer(GL_FRAMEBUFFER, 0);
//
//    // ping-pong-framebuffer for blurring
//    unsigned int pingpongFBO[2];
//    unsigned int pingpongColorbuffers[2];
//    glGenFramebuffers(2, pingpongFBO);
//    glGenTextures(2, pingpongColorbuffers);
//    for (unsigned int i = 0; i < 2; i++)
//    {
//        glBindFramebuffer(GL_FRAMEBUFFER, pingpongFBO[i]);
//        glBindTexture(GL_TEXTURE_2D, pingpongColorbuffers[i]);
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, SCR_WIDTH, SCR_HEIGHT, 0, GL_RGBA, GL_FLOAT, NULL);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); // we clamp to the edge as the blur filter would otherwise sample repeated texture values!
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, pingpongColorbuffers[i], 0);
//        // also check if framebuffers are complete (no need for depth buffer)
//        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
//            std::cout << "Framebuffer not complete!" << std::endl;
//    }
//
//
//    unsigned int texture;
//    glGenTextures(1, &texture);
//    glActiveTexture(GL_TEXTURE0);
//    glBindTexture(GL_TEXTURE_2D, texture);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    int width, height, nrChannels;
//    unsigned char* data = stbi_load("white.png", &width, &height, &nrChannels, 0);
//    if (data)
//    {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    stbi_image_free(data);
//    
//
//    unsigned int lightCubeVAO;
//    glGenVertexArrays(1, &lightCubeVAO);
//    glBindVertexArray(lightCubeVAO);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1);
//    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//    glEnableVertexAttribArray(2);
//
//    // uncomment this call to draw in wireframe polygons.
//    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//
//    glUseProgram(shaderProgram);
//    /*glUseProgram(BshaderProgram);
//    glUniform1i(glGetUniformLocation(BshaderProgram, "image"), 0);
//    glUseProgram(BLshaderProgram);
//    glUniform1i(glGetUniformLocation(BLshaderProgram, "scene"), 0);
//    glUniform1i(glGetUniformLocation(BLshaderProgram, "bloomBlur"), 1);*/
//
//    // render loop
//    // -----------
//    while (!glfwWindowShouldClose(window))
//    {
//        glEnable(GL_DEPTH_TEST);
//        glDepthFunc(GL_LESS);
//        glEnable(GL_CULL_FACE);
//        glCullFace(GL_FRONT);
//        glFrontFace(GL_CCW);
//
//
//        // input
//        // -----
//        processInput(window);
//
//        // render
//        // ------
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        glUseProgram(shaderProgram);
//
//        glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
//        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//
//        //VertShader
//        int MatrixLocation = glGetUniformLocation(shaderProgram, "projection");
//        glUniformMatrix4fv(MatrixLocation, 1, GL_FALSE, &projection[0][0]);
//        int ViewLocation = glGetUniformLocation(shaderProgram, "view");
//        glUniformMatrix4fv(ViewLocation, 1, GL_FALSE, &view[0][0]);
//        int mvpLocation = glGetUniformLocation(shaderProgram, "mvp");
//        glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, &mvp[0][0]);
//        int lightLocation = glGetUniformLocation(shaderProgram, "lightPos");
//        glUniform3fv(lightLocation, 1, &lightPosition[0]);
//
//
//        //FragShader
//        glm::vec3 color(1.0, 0.1, 0.1);
//        int colorLocation = glGetUniformLocation(shaderProgram, "aColor");
//        glUniform3fv(colorLocation, 1, &color[0]);
//
//
//        //Chrome material
//
//        /*glm::vec3 matAmb(0.25f, 0.25f, 0.25f);
//        glm::vec3 matDif(0.4f);
//        glm::vec3 matSpe(0.774597f);
//        int MatAmbLocation = glGetUniformLocation(shaderProgram, "matAmbient");
//        glUniform3fv(MatAmbLocation, 1, &matAmb[0]);
//        int MatDifLocation = glGetUniformLocation(shaderProgram, "matDiffuse");
//        glUniform3fv(MatDifLocation, 1, &matDif[0]);
//        int MatSpecLocation = glGetUniformLocation(shaderProgram, "matSpecular");
//        glUniform3fv(MatSpecLocation, 1, &matSpe[0]);
//        int shineLocation = glGetUniformLocation(shaderProgram, "shininess");
//        glUniform1f(shineLocation, (128.0f * 0.6f));*/
//
//        //Plastic material
//
//        glm::vec3 matAmb(0.0f);
//        glm::vec3 matDif(0.5f, 0.0f, 0.0f);
//        glm::vec3 matSpe(0.7f, 0.6f, 0.6f);
//        int MatAmbLocation = glGetUniformLocation(shaderProgram, "matAmbient");
//        glUniform3fv(MatAmbLocation, 1, &matAmb[0]);
//        int MatDifLocation = glGetUniformLocation(shaderProgram, "matDiffuse");
//        glUniform3fv(MatDifLocation, 1, &matDif[0]);
//        int MatSpecLocation = glGetUniformLocation(shaderProgram, "matSpecular");
//        glUniform3fv(MatSpecLocation, 1, &matSpe[0]);
//        int shineLocation = glGetUniformLocation(shaderProgram, "shininess");
//        glUniform1f(shineLocation, (128.0f * 0.075f));
//
//
//
//
//
//
//        glm::vec3 diffuseColor = color * glm::vec3(0.9f); 
//        glm::vec3 ambientColor = diffuseColor * glm::vec3(0.6f);
//        glm::vec3 specularColor(1.0f, 1.0f, 1.0f);
//        int LightAmbLocation = glGetUniformLocation(shaderProgram, "lightAmbient");
//        glUniform3fv(LightAmbLocation, 1, &ambientColor[0]);
//        int LightDifLocation = glGetUniformLocation(shaderProgram, "lightDiffuse");
//        glUniform3fv(LightDifLocation, 1, &diffuseColor[0]);
//        int LightSpecLocation = glGetUniformLocation(shaderProgram, "lightSpecular");
//        glUniform3fv(LightSpecLocation, 1, &specularColor[0]);
//
//        int constantLocation = glGetUniformLocation(shaderProgram, "constant");
//        glUniform1f(constantLocation, 1.0f);
//        int linearLocation = glGetUniformLocation(shaderProgram, "linear");
//        glUniform1f(linearLocation, 0.0014f);
//        int quadLocation = glGetUniformLocation(shaderProgram, "quadratic");
//        glUniform1f(quadLocation, 0.000007f);
//
//        
//        int camPosLocation = glGetUniformLocation(shaderProgram, "viewPos");
//        glUniform3fv(camPosLocation, 1, &cameraPos[0]);
//
//        // draw our first triangle
//        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
//        glBindTexture(GL_TEXTURE_2D, texture);
//        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//        glDrawArrays(GL_TRIANGLES, 0, numVertices);
//        glBindVertexArray(0);
//
//        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//        //cube 2
//        glm::mat4 model2 = glm::translate(mvp, glm::vec3(3.0f));
//        glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, &model2[0][0]);
//        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
//        glBindTexture(GL_TEXTURE_2D, texture);
//        glBindVertexArray(VAO);
//        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//        glDrawArrays(GL_TRIANGLES, 0, numVertices);
//        glBindVertexArray(0);
//
//
//        ///LIGHT CUBEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
//        glUseProgram(LCshaderProgram);
//
//        glm::mat4 model = glm::mat4(1.0f);
//        model = glm::translate(model, lightPosition);
//        model = glm::scale(model, glm::vec3(0.2f)); // a smaller cube
//        int LCMatrixLocation = glGetUniformLocation(LCshaderProgram, "projection");
//        glUniformMatrix4fv(LCMatrixLocation, 1, GL_FALSE, &projection[0][0]);
//        int LCViewLocation = glGetUniformLocation(LCshaderProgram, "view");
//        glUniformMatrix4fv(LCViewLocation, 1, GL_FALSE, &view[0][0]);
//        int LCmvpLocation = glGetUniformLocation(LCshaderProgram, "model");
//        glUniformMatrix4fv(LCmvpLocation, 1, GL_FALSE, &model[0][0]);
//
//        glBindVertexArray(lightCubeVAO);
//        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//        glDrawArrays(GL_TRIANGLES, 0, 36);
//        glBindVertexArray(0);
//
//        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//        bool horizontal = true, first_iteration = true;
//        int amount = 10;
//        glUseProgram(BshaderProgram);
//        for (unsigned int i = 0; i < amount; i++)
//        {
//            glBindFramebuffer(GL_FRAMEBUFFER, pingpongFBO[horizontal]);
//            glUniform1i(glGetUniformLocation(BshaderProgram, "horizontal"), horizontal);
//            glBindTexture(GL_TEXTURE_2D, first_iteration ? texture : pingpongColorbuffers[!horizontal]);  // bind texture of other framebuffer (or scene if first iteration)
//            renderQuad();
//            horizontal = !horizontal;
//            if (first_iteration)
//                first_iteration = false;
//        }
//        glBindFramebuffer(GL_FRAMEBUFFER, 0);
//
//        /*glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        glUseProgram(BLshaderProgram);
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, colorBuffers[0]);
//        glActiveTexture(GL_TEXTURE1);
//        glBindTexture(GL_TEXTURE_2D, pingpongColorbuffers[!horizontal]);
//        glUniform1i(glGetUniformLocation(BLshaderProgram, "bloom"), bloom);
//        glUniform1i(glGetUniformLocation(BLshaderProgram, "exposure"), exposure);
//        renderQuad();
//
//        std::cout << "bloom: " << (bloom ? "on" : "off") << "| exposure: " << exposure << std::endl;*/
//
//
//        float currentFrame = glfwGetTime();
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//
//
//        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//        // -------------------------------------------------------------------------------
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    // optional: de-allocate all resources once they've outlived their purpose:
//    // ------------------------------------------------------------------------
//    glDeleteVertexArrays(1, &VAO);
//    glDeleteVertexArrays(1, &lightCubeVAO);
//    glDeleteBuffers(1, &VBO);
//    glDeleteBuffers(1, &EBO);
//    glDeleteProgram(shaderProgram);
//    glDeleteProgram(LCshaderProgram);
//    glDeleteProgram(BshaderProgram);
//    //glDeleteProgram(BLshaderProgram);
//
//
//    // glfw: terminate, clearing all previously allocated GLFW resources.
//    // ------------------------------------------------------------------
//    glfwTerminate();
//    return 0;
//}
//
//// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
//// ---------------------------------------------------------------------------------------------------------
//void processInput(GLFWwindow* window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//
//    if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
//    {
//        mvp = glm::scale(mvp, glm::vec3(0.999f, 0.999f, 0.999f));
//    }
//    else if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
//    {
//        mvp = glm::scale(mvp, glm::vec3(1.001f, 1.001f, 1.001f));
//    }
//
//    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//    {
//        mvp = glm::rotate(mvp, 0.001f, glm::vec3(0, 1, 0));
//    }
//
//    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//    {
//        mvp = glm::rotate(mvp, -0.001f, glm::vec3(0, 1, 0));
//    }
//
//    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//    {
//        mvp = glm::rotate(mvp, 0.001f, glm::vec3(1, 0, 0));
//    }
//
//    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//    {
//        mvp = glm::rotate(mvp, -0.001f, glm::vec3(1, 0, 0));
//    }
//
//    float cameraSpeed = 2.5f * deltaTime;
//    if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
//        cameraPos += cameraSpeed * cameraFront;
//    if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
//        cameraPos -= cameraSpeed * cameraFront;
//    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
//        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
//    if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
//        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
//
//
//    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && !bloomKeyPressed)
//    {
//        bloom = !bloom;
//        bloomKeyPressed = true;
//    }
//    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_RELEASE)
//    {
//        bloomKeyPressed = false;
//    }
//
//    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
//    {
//        if (exposure > 0.0f)
//            exposure -= 0.001f;
//        else
//            exposure = 0.0f;
//    }
//    else if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
//    {
//        exposure += 0.001f;
//    }
//
//}
//
//// glfw: whenever the window size changed (by OS or user resize) this callback function executes
//// ---------------------------------------------------------------------------------------------
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    // make sure the viewport matches the new window dimensions; note that width and 
//    // height will be significantly larger than specified on retina displays.
//    glViewport(0, 0, width, height);
//}
//
//unsigned int quadVAO = 0;
//unsigned int quadVBO;
//void renderQuad()
//{
//    if (quadVAO == 0)
//    {
//        float quadVertices[] = {
//            // positions        // texture Coords
//            -1.0f,  1.0f, 0.0f, 0.0f, 1.0f,
//            -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
//             1.0f,  1.0f, 0.0f, 1.0f, 1.0f,
//             1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
//        };
//        // setup plane VAO
//        glGenVertexArrays(1, &quadVAO);
//        glGenBuffers(1, &quadVBO);
//        glBindVertexArray(quadVAO);
//        glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
//        glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), &quadVertices, GL_STATIC_DRAW);
//        glEnableVertexAttribArray(0);
//        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
//        glEnableVertexAttribArray(1);
//        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
//    }
//    glBindVertexArray(quadVAO);
//    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
//    glBindVertexArray(0);
//}
//
//
//
///*float* loadObj(const char* fileName)
//{
//    std::vector<glm::vec3> vertPos;
//    std::vector<glm::vec3> vertNorms;
//    std::vector<glm::vec3> vertFaces;
//    std::stringstream s;
//    std::ifstream file(fileName);
//    std::string l = "";
//    std::string prefix = "";
//
//    while (std::getline(file, l))
//    {
//        s.clear();
//        s.str(l);
//        s >> prefix;
//
//        if (prefix == "v")
//        {
//            float pos[3] = { 0,0,0 };
//            s >> pos[0] >> pos[1] >> pos[2];
//            vertPos.push_back(glm::vec3(pos[0], pos[1], pos[2]));
//        }
//        else if (prefix == "vn")
//        {
//            float pos[3] = { 0,0,0 };
//            s >> pos[0] >> pos[1] >> pos[2];
//            vertNorms.push_back(glm::vec3(pos[0], pos[1], pos[2]));
//        }
//        else if (prefix == "f")
//        {
//            int vertNums[5] = { 0,0,0,0,0 };
//            s >> vertNums[0];
//            if (s.peek() == ' ')
//                s >> vertNums[1] >> vertNums[2];
//            else
//            {
//                s.ignore(30, ' ');
//                s >> vertNums[1];
//                s.ignore(30, ' ');
//                s >> vertNums[2];
//                s.ignore(30, ' ');
//            }
//            vertFaces.push_back(glm::vec3(vertNums[0], vertNums[2], vertNums[1]));
//            s >> vertNums[3];
//            if (vertNums[3] != 0)
//            {
//                vertFaces.push_back(glm::vec3(vertNums[0], vertNums[3], vertNums[2]));
//                s >> vertNums[4];
//                if (vertNums[4] != 0)
//                    vertFaces.push_back(glm::vec3(vertNums[0], vertNums[4], vertNums[3]));
//            }
//        }
//    }
//
//    static float vertices[200000];
//    int j = 0;
//    int k = 0;
//    std::cout << "vert faces rn size " << vertFaces.size() << std::endl;
//    for (unsigned int i = 0; i < vertFaces.size(); i++)
//    {
//        glm::vec3 vecA = vertPos[vertFaces[i].z - 1] - vertPos[vertFaces[i].x - 1];
//        glm::vec3 vecB = vertPos[vertFaces[i].y - 1] - vertPos[vertFaces[i].x - 1];
//        glm::vec3 result = cross(vecA, vecB);
//
//        vertices[j++] = vertPos[vertFaces[i].x - 1].x; //positions
//        vertices[j++] = vertPos[vertFaces[i].x - 1].y;
//        vertices[j++] = vertPos[vertFaces[i].x - 1].z;
//
//        vertices[j++] = result.x; //normals
//        vertices[j++] = result.y;
//        vertices[j++] = result.z;
//
//        //vertices[j++] = 0.0f; //textures
//        //vertices[j++] = 0.0f;
//        vertices[j++] = 0.0f; //textures
//        vertices[j++] = 1.0f;
//
//        vertices[j++] = vertPos[vertFaces[i].y - 1].x;
//        vertices[j++] = vertPos[vertFaces[i].y - 1].y;
//        vertices[j++] = vertPos[vertFaces[i].y - 1].z;
//
//        vertices[j++] = result.x;
//        vertices[j++] = result.y;
//        vertices[j++] = result.z;
//
//        /*vertices[j++] = 0.5f;
//        vertices[j++] = 1.0f;
//        vertices[j++] = 0.5f;
//        vertices[j++] = 0.0f;
//
//        vertices[j++] = vertPos[vertFaces[i].z - 1].x;
//        vertices[j++] = vertPos[vertFaces[i].z - 1].y;
//        vertices[j++] = vertPos[vertFaces[i].z - 1].z;
//
//        vertices[j++] = result.x;
//        vertices[j++] = result.y;
//        vertices[j++] = result.z;
//
//        /*vertices[j++] = 1.0f;
//        vertices[j++] = 0.0f;
//        vertices[j++] = 1.0f;
//        vertices[j++] = 1.0f;
//    }
//    std::cout << " in function the num vertices rn is " << sizeof(vertices) / sizeof(vertices[0]) << std::endl;
//    return vertices;
//}*/