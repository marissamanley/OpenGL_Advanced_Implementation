////GLFW Window creation and some load functions acquired from LearnOpenGL.com
////Read Project Report for detailed information about Acknowledgments
//#define GLFW_INCLUDE_NONE
//#define GLEW_STATIC
//#define STB_IMAGE_IMPLEMENTATION
//#include "include/glad/glad.h"
//#include "stb_image.h"
//#include "GLFW/glfw3.h"
//#include "glm/vec3.hpp"
//#include "glm/vec4.hpp"
//#include "glm/mat4x4.hpp"
//#include "glm/common.hpp"
//#include "glm/gtx/string_cast.hpp"
//#include "glm/ext.hpp"
//#include "glm/gtc/matrix_transform.hpp"
//
//#include "Shader.h"
//#include <iostream>
//
//#include <string>
//#include <fstream>
//#include <sstream>
//#include <algorithm>
//#include <vector>
//#include <array>
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void processInput(GLFWwindow* window);
//unsigned int loadTexture(const char* path, bool gammaCorrection);
//void renderQuad();
//void renderCube();
//
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//bool bloom = true;
//bool bloomKeyPressed = false;
//bool halo = true;
//bool haloKeyPressed = false;
//float exposure = 1.0f;
//
//bool changed = true;
//std::string matType = "Plastic";
//glm::vec3 amb(0.04f);
//glm::vec3 diff(0.4f);
//glm::vec3 spec(0.7f);
//float shin = 128.0f;
//
//std::string txtr = "container.png";
//
//glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
//glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
//glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
//float lastX = (float)SCR_WIDTH / 2.0;
//float lastY = (float)SCR_HEIGHT / 2.0;
//bool firstMouse = true;
//float deltaTime = 0.0f;
//float lastFrame = 0.0f;
//unsigned int containerTexture;
//
//int main()
//{
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#ifdef __APPLE__
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif
//
//    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//    glfwSetCursorPosCallback(window, mouse_callback);
//
//    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//    glEnable(GL_DEPTH_TEST);
//    Shader shader("bloom.vs", "bloom.fs");
//    Shader shaderLight("bloom.vs", "light_box.fs");
//    Shader shaderBlur("blur.vs", "blur.fs");
//    Shader shaderBloomFinal("final.vs", "final.fs");
//
//
//    unsigned int floorTexture = loadTexture("colorFloor.jpg", true); 
//    containerTexture = loadTexture(txtr.c_str(), true);
//
//    unsigned int hdrFBO;
//    glGenFramebuffers(1, &hdrFBO);
//    glBindFramebuffer(GL_FRAMEBUFFER, hdrFBO);
//    unsigned int colorBuffers[3];
//    glGenTextures(3, colorBuffers);
//    for (unsigned int i = 0; i < 3; i++)
//    {
//        glBindTexture(GL_TEXTURE_2D, colorBuffers[i]);
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, SCR_WIDTH, SCR_HEIGHT, 0, GL_RGBA, GL_FLOAT, NULL);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);  
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + i, GL_TEXTURE_2D, colorBuffers[i], 0);
//    }
//    unsigned int rboDepth;
//    glGenRenderbuffers(1, &rboDepth);
//    glBindRenderbuffer(GL_RENDERBUFFER, rboDepth);
//    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, SCR_WIDTH, SCR_HEIGHT);
//    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, rboDepth); 
//    unsigned int attachments[3] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1, GL_COLOR_ATTACHMENT2 };
//    glDrawBuffers(3, attachments);
//    
//    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
//        std::cout << "Framebuffer not complete!" << std::endl;
//    glBindFramebuffer(GL_FRAMEBUFFER, 0);
//
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
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE); 
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, pingpongColorbuffers[i], 0);
//        if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
//            std::cout << "Framebuffer not complete!" << std::endl;
//    }
//
//    std::vector<glm::vec3> lightPositions;
//    lightPositions.push_back(glm::vec3(0.0f, 1.5f, 1.5f));
//    lightPositions.push_back(glm::vec3(-4.0f, 0.5f, -3.0f));
//    lightPositions.push_back(glm::vec3(3.0f, 0.5f, 1.0f));
//    lightPositions.push_back(glm::vec3(-.8f, 2.4f, -1.0f));
//    std::vector<glm::vec3> lightColors;
//    lightColors.push_back(glm::vec3(5.0f, 5.0f, 5.0f));
//    lightColors.push_back(glm::vec3(10.0f, 0.0f, 0.0f));
//    lightColors.push_back(glm::vec3(3.0f, 0.0f, 10.0f));
//    lightColors.push_back(glm::vec3(5.0f, 5.0f, 0.0f));
//
//
//    shader.use();
//    shader.setInt("diffuseTexture", 0);
//    shaderLight.use();
//    shaderLight.setInt("diffuseTexture", 0);
//    shaderBlur.use();
//    shaderBlur.setInt("image", 0);
//    shaderBlur.setVec3("camPos", cameraPos);
//    shaderBloomFinal.use();
//    shaderBloomFinal.setInt("scene", 0);
//    shaderBloomFinal.setInt("bloomBlur", 1);
//    shaderBloomFinal.setInt("noBlur", 2);
//
//    while (!glfwWindowShouldClose(window))
//    {
//        float currentFrame = static_cast<float>(glfwGetTime());
//        deltaTime = currentFrame - lastFrame;
//        lastFrame = currentFrame;
//
//        processInput(window);
//
//        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//        glBindFramebuffer(GL_FRAMEBUFFER, hdrFBO);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
//        glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
//        glm::mat4 model = glm::mat4(1.0f);
//        shader.use();
//        shader.setMat4("projection", projection);
//        shader.setMat4("view", view);
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, floorTexture);
//        for (unsigned int i = 0; i < lightPositions.size(); i++)
//        {
//            shader.setVec3("lights[" + std::to_string(i) + "].Position", lightPositions[i]);
//            glm::vec3 diffuseColor = lightColors[i] * glm::vec3(0.8f);
//            glm::vec3 ambientColor = diffuseColor * glm::vec3(0.1f);
//            shader.setVec3("lights[" + std::to_string(i) + "].ambient", ambientColor);
//            shader.setVec3("lights[" + std::to_string(i) + "].diffuse", diffuseColor);
//            shader.setVec3("lights[" + std::to_string(i) + "].specular", glm::vec3(0.1f));
//        }
//        shader.setVec3("viewPos", cameraPos);
//        shader.setVec3("material.ambient", amb);
//        shader.setVec3("material.diffuse", diff);
//        shader.setVec3("material.specular", spec);
//        shader.setFloat("material.shininess", shin);
//
//
//        model = glm::mat4(1.0f);
//        model = glm::translate(model, glm::vec3(0.0f, -1.0f, 0.0));
//        model = glm::scale(model, glm::vec3(12.5f, 0.5f, 12.5f));
//        shader.setMat4("model", model);
//        renderCube();
//        glBindTexture(GL_TEXTURE_2D, containerTexture);
//        model = glm::mat4(1.0f);
//        model = glm::translate(model, glm::vec3(2.0f, 0.5f, 1.0));
//        model = glm::scale(model, glm::vec3(0.5f));
//        shader.setMat4("model", model);
//        renderCube();
//        model = glm::mat4(1.0f);
//        model = glm::translate(model, glm::vec3(-5.0f, 0.0f, 1.0));
//        model = glm::scale(model, glm::vec3(0.5f));
//        shader.setMat4("model", model);
//        renderCube();
//        model = glm::mat4(1.0f);
//        model = glm::translate(model, glm::vec3(-0.0f, 4.0f, 2.0));
//        model = glm::rotate(model, glm::radians(60.0f), glm::normalize(glm::vec3(1.0, 0.0, 1.0)));
//        shader.setMat4("model", model);
//        renderCube();
//        model = glm::mat4(1.0f);
//        model = glm::translate(model, glm::vec3(-5.5f, 3.0f, -1.0f));
//        model = glm::rotate(model, glm::radians(20.0f), glm::normalize(glm::vec3(1.0, 0.0, 1.0)));
//        model = glm::scale(model, glm::vec3(0.75f));
//        shader.setMat4("model", model);
//        renderCube();
//
//        shaderLight.use();
//        shaderLight.setMat4("projection", projection);
//        shaderLight.setMat4("view", view);
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, containerTexture);
//
//        for (unsigned int i = 0; i < lightPositions.size(); i++)
//        {
//            model = glm::mat4(1.0f);
//            model = glm::translate(model, glm::vec3(lightPositions[i]));
//            model = glm::scale(model, glm::vec3(0.25f));
//            shaderLight.setMat4("model", model);
//            shaderLight.setVec3("lightColor", lightColors[i]);
//            renderCube();
//        }
//        glBindFramebuffer(GL_FRAMEBUFFER, 0);
//
//        bool horizontal = true, first_iteration = true;
//        unsigned int amount = 10;
//        shaderBlur.use();
//        for (unsigned int i = 0; i < amount; i++)
//        {
//            glBindFramebuffer(GL_FRAMEBUFFER, pingpongFBO[horizontal]);
//            shaderBlur.setInt("horizontal", horizontal);
//            glBindTexture(GL_TEXTURE_2D, first_iteration ? colorBuffers[1] : pingpongColorbuffers[!horizontal]);
//            renderQuad();
//            horizontal = !horizontal;
//            if (first_iteration)
//                first_iteration = false;
//        }
//        glBindFramebuffer(GL_FRAMEBUFFER, 0);
//
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        shaderBloomFinal.use();
//        glActiveTexture(GL_TEXTURE0);
//        glBindTexture(GL_TEXTURE_2D, colorBuffers[0]);
//        glActiveTexture(GL_TEXTURE1);
//        glBindTexture(GL_TEXTURE_2D, pingpongColorbuffers[!horizontal]);
//        glActiveTexture(GL_TEXTURE2);
//        glBindTexture(GL_TEXTURE_2D, colorBuffers[2]);
//        shaderBloomFinal.setInt("bloom", bloom);
//        shaderBloomFinal.setInt("halo", halo);
//        shaderBloomFinal.setFloat("exposure", exposure);
//        renderQuad();
//
//        if (changed)
//        {
//            std::cout << "Scene Settings: " << std::endl;
//            std::cout << "--------------- " << std::endl;
//            std::cout << "Halo toggled (Press H): " << (halo ? "on" : "off") << " | Bloom toggled (Press Space): " << (bloom ? "on" : "off") << " | Exposure(Q and E): " << exposure << std::endl;
//            std::cout << "-------------------------------------\n";
//            std::cout << "Current material type: " << matType << std::endl;
//            std::cout << "To change objects material, press one of the following numbers: " << std::endl;
//            std::cout << "1. Chrome\n";
//            std::cout << "2. Plastic\n";
//            std::cout << "3. Rubber\n";
//            std::cout << "-------------------------------------\n";
//            std::cout << "To change object texture, press one of the following numbers: \n";
//            std::cout << "4. Wooden container\n";
//            std::cout << "5. Black and White Triangles\n";
//            std::cout << "6. Colorful Triangles\n\n\n";
//
//            changed = false;
//        }
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    glfwTerminate();
//    return 0;
//}
//
//unsigned int cubeVAO = 0;
//unsigned int cubeVBO = 0;
//float vertices[200000];
//void renderCube()
//{
//    if (cubeVAO == 0)
//    {
//        const char* fileName = "data/cube.obj";
//        
//        std::vector<glm::vec3> vertPos;
//        std::vector<glm::vec3> vertNorms;
//        std::vector<glm::vec3> vertFaces;
//        std::stringstream s;
//        std::ifstream file(fileName);
//        std::string l = "";
//        std::string prefix = "";
//        
//        while (std::getline(file, l))
//        {
//            s.clear();
//            s.str(l);
//            s >> prefix;
//        
//            if (prefix == "v")
//            {
//                float pos[3] = { 0,0,0 };
//                s >> pos[0] >> pos[1] >> pos[2];
//                vertPos.push_back(glm::vec3(pos[0], pos[1], pos[2]));
//            }
//            else if (prefix == "vn")
//            {
//                float pos[3] = { 0,0,0 };
//                s >> pos[0] >> pos[1] >> pos[2];
//                vertNorms.push_back(glm::vec3(pos[0], pos[1], pos[2]));
//            }
//            else if (prefix == "f")
//            {
//                int vertNums[5] = { 0,0,0,0,0 };
//                s >> vertNums[0];
//                if (s.peek() == ' ')
//                    s >> vertNums[1] >> vertNums[2];
//                else
//                {
//                    s.ignore(30, ' ');
//                    s >> vertNums[1];
//                    s.ignore(30, ' ');
//                    s >> vertNums[2];
//                    s.ignore(30, ' ');
//                }
//                vertFaces.push_back(glm::vec3(vertNums[0], vertNums[2], vertNums[1]));
//                s >> vertNums[3];
//                if (vertNums[3] != 0)
//                {
//                    vertFaces.push_back(glm::vec3(vertNums[0], vertNums[3], vertNums[2]));
//                    s >> vertNums[4];
//                    if (vertNums[4] != 0)
//                        vertFaces.push_back(glm::vec3(vertNums[0], vertNums[4], vertNums[3]));
//                }
//            }
//        }
//        
//        int j = 0;
//        int k = 0;
//        for (unsigned int i = 0; i < vertFaces.size(); i++)
//        {
//            glm::vec3 vecA = vertPos[vertFaces[i].z - 1] - vertPos[vertFaces[i].x - 1];
//            glm::vec3 vecB = vertPos[vertFaces[i].y - 1] - vertPos[vertFaces[i].x - 1];
//            glm::vec3 result = cross(vecA, vecB);
//        
//            vertices[j++] = vertPos[vertFaces[i].x - 1].x; //positions
//            vertices[j++] = vertPos[vertFaces[i].x - 1].y;
//            vertices[j++] = vertPos[vertFaces[i].x - 1].z;
//        
//            vertices[j++] = result.x; //normals
//            vertices[j++] = result.y;
//            vertices[j++] = result.z;
//
//            vertices[j++] = 0.0f; //textures
//            vertices[j++] = 1.0f;
//        
//            vertices[j++] = vertPos[vertFaces[i].y - 1].x;
//            vertices[j++] = vertPos[vertFaces[i].y - 1].y;
//            vertices[j++] = vertPos[vertFaces[i].y - 1].z;
//        
//            vertices[j++] = result.x;
//            vertices[j++] = result.y;
//            vertices[j++] = result.z;
//
//            vertices[j++] = 0.5f;
//            vertices[j++] = 0.0f;
//        
//            vertices[j++] = vertPos[vertFaces[i].z - 1].x;
//            vertices[j++] = vertPos[vertFaces[i].z - 1].y;
//            vertices[j++] = vertPos[vertFaces[i].z - 1].z;
//        
//            vertices[j++] = result.x;
//            vertices[j++] = result.y;
//            vertices[j++] = result.z;
//
//            vertices[j++] = 1.0f;
//            vertices[j++] = 1.0f;
//        }
//
//        glGenVertexArrays(1, &cubeVAO);
//        glGenBuffers(1, &cubeVBO);
//        glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
//        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//        glBindVertexArray(cubeVAO);
//        glEnableVertexAttribArray(0);
//        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
//        glEnableVertexAttribArray(1);
//        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
//        glEnableVertexAttribArray(2);
//        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
//        glBindBuffer(GL_ARRAY_BUFFER, 0);
//        glBindVertexArray(0);
//    }
//    unsigned int numVertices = sizeof(vertices) / 8;
//    glBindVertexArray(cubeVAO);
//    glDrawArrays(GL_TRIANGLES, 0, numVertices);
//    glBindVertexArray(0);
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
//void processInput(GLFWwindow* window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//
//
//    float cameraSpeed = 2.5f * deltaTime;
//    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//        cameraPos += cameraSpeed * cameraFront;
//    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//        cameraPos -= cameraSpeed * cameraFront;
//    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//        cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
//    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//        cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
//
//
//    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && !bloomKeyPressed)
//    {
//        bloom = !bloom;
//        bloomKeyPressed = true;
//        changed = true;
//    }
//    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_RELEASE)
//    {
//        bloomKeyPressed = false;
//    }
//
//    if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS && !haloKeyPressed)
//    {
//        halo = !halo;
//        haloKeyPressed = true;
//        changed = true;
//        
//    }
//    if (glfwGetKey(window, GLFW_KEY_H) == GLFW_RELEASE)
//    {
//        haloKeyPressed = false;
//    }
//
//    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
//    {
//        changed = true;
//        if (exposure > 0.0f)
//            exposure -= 0.001f;
//        else
//            exposure = 0.0f;
//    }
//    else if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
//    {
//        changed = true;
//        exposure += 0.001f;
//    }
//
//    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS && matType.compare("Chrome") != 0)
//    {
//        matType = "Chrome";
//        amb = glm::vec3(0.04f);
//        diff = glm::vec3(0.3f);
//        spec = glm::vec3(1.0f);
//        shin = 512.0f;
//        changed = true;
//    }
//    else if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS && matType.compare("Plastic") != 0)
//    {
//        changed = true;
//        matType = "Plastic";
//        amb = glm::vec3(0.04f);
//        diff= glm::vec3(0.4f);
//        spec=glm::vec3(0.7f);
//        shin = 128.0f;
//    }
//    else if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS && matType.compare("Rubber") != 0)
//    {
//        changed = true;
//        matType = "Rubber";
//        amb = glm::vec3(0.04f);
//        diff = glm::vec3(0.5f);
//        spec = glm::vec3(0.3f);
//        shin = 64.0f;
//    }
//    else if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS && txtr.compare("container.png") != 0)
//    {
//        changed = true;
//        txtr = "container.png";
//        containerTexture = loadTexture(txtr.c_str(), true);
//    }
//    else if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS && txtr.compare("triangle.jpg") != 0)
//    {
//        changed = true;
//        txtr = "triangle.jpg";
//        containerTexture = loadTexture(txtr.c_str(), true);
//    }
//    else if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS && txtr.compare("colorFloor.jpg") != 0)
//    {
//        changed = true;
//        txtr = "colorFloor.jpg";
//        containerTexture = loadTexture(txtr.c_str(), true);
//    }
//}
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    glViewport(0, 0, width, height);
//}
//
//float yaw = -90.0f;
//float pitch = 0.0f;
//void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
//{
//    float xpos = static_cast<float>(xposIn);
//    float ypos = static_cast<float>(yposIn);
//    if (firstMouse)
//    {
//        lastX = xpos;
//        lastY = ypos;
//        firstMouse = false;
//    }
//
//    float xoffset = xpos - lastX;
//    float yoffset = lastY - ypos; 
//
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
//unsigned int loadTexture(char const* path, bool gammaCorrection)
//{
//    unsigned int textureID;
//    glGenTextures(1, &textureID);
//
//    int width, height, nrComponents;
//    unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
//    if (data)
//    {
//        GLenum internalFormat;
//        GLenum dataFormat;
//        if (nrComponents == 1)
//        {
//            internalFormat = dataFormat = GL_RED;
//        }
//        else if (nrComponents == 3)
//        {
//            internalFormat = gammaCorrection ? GL_SRGB : GL_RGB;
//            dataFormat = GL_RGB;
//        }
//        else if (nrComponents == 4)
//        {
//            internalFormat = gammaCorrection ? GL_SRGB_ALPHA : GL_RGBA;
//            dataFormat = GL_RGBA;
//        }
//
//        glBindTexture(GL_TEXTURE_2D, textureID);
//        glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, dataFormat, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//        stbi_image_free(data);
//    }
//    else
//    {
//        std::cout << "Texture failed to load at path: " << path << std::endl;
//        stbi_image_free(data);
//    }
//
//    return textureID;
//}