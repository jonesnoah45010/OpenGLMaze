// #include <GL/glew.h>
// #include <GLFW/glfw3.h>

// int main() {
//     if (!glfwInit()) {
//         return -1;
//     }
//     GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Maze Game", NULL, NULL);
//     if (!window) {
//         glfwTerminate();
//         return -1;
//     }
//     glfwMakeContextCurrent(window);
//     glewInit();

//     // Main loop
//     while (!glfwWindowShouldClose(window)) {
//         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//         // Render the scene
//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }
//     glfwDestroyWindow(window);
//     glfwTerminate();
//     return 0;
// }








// #include <GL/glew.h>
// #include <GLFW/glfw3.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

// // Maze dimensions
// #define MAZE_ROWS 5
// #define MAZE_COLS 5

// // Maze data
// int maze[MAZE_ROWS][MAZE_COLS] = {
//     {1, 0, 1, 1, 1},
//     {1, 0, 1, 0, 1},
//     {1, 0, 0, 0, 1},
//     {1, 1, 1, 0, 1},
//     {1, 1, 1, 0, 0},
// };

// // Camera position
// float cameraX = 0.0f, cameraY = 5.0f, cameraZ = 10.0f;
// float lookAtX = 2.0f, lookAtY = 0.0f, lookAtZ = 2.0f;

// // Vertex data for a cube
// GLfloat cubeVertices[] = {
//     // Positions          // Texture Coords
//     -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//      0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//     -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//     // Other faces...
// };

// // Function to draw a cube
// void drawCube() {
//     glEnableClientState(GL_VERTEX_ARRAY);
//     glVertexPointer(3, GL_FLOAT, 5 * sizeof(GLfloat), cubeVertices);
//     glDrawArrays(GL_QUADS, 0, 24);  // Draw 24 vertices (6 faces * 4 vertices each)
//     glDisableClientState(GL_VERTEX_ARRAY);
// }

// // Render the maze
// void renderMaze() {
//     for (int i = 0; i < MAZE_ROWS; i++) {
//         for (int j = 0; j < MAZE_COLS; j++) {
//             if (maze[i][j] == 1) {  // Wall
//                 glPushMatrix();
//                 glTranslatef((float)j, 0.0f, (float)i);
//                 drawCube();
//                 glPopMatrix();
//             }
//         }
//     }
// }

// // Handle input
// void processInput(GLFWwindow* window) {
//     if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) cameraZ -= 0.1f;
//     if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) cameraZ += 0.1f;
//     if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) cameraX -= 0.1f;
//     if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) cameraX += 0.1f;
//     if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) cameraY += 0.1f;
//     if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) cameraY -= 0.1f;
// }

// int main() {
//     // Initialize GLFW
//     if (!glfwInit()) {
//         fprintf(stderr, "Failed to initialize GLFW\n");
//         return -1;
//     }

//     GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Maze Game", NULL, NULL);
//     if (!window) {
//         fprintf(stderr, "Failed to create GLFW window\n");
//         glfwTerminate();
//         return -1;
//     }

//     glfwMakeContextCurrent(window);
//     glewInit();

//     glEnable(GL_DEPTH_TEST);

//     // Main loop
//     while (!glfwWindowShouldClose(window)) {
//         processInput(window);

//         // Clear the screen
//         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//         // Set the camera
//         glMatrixMode(GL_PROJECTION);
//         glLoadIdentity();
//         gluPerspective(45.0, 800.0 / 600.0, 0.1, 100.0);

//         glMatrixMode(GL_MODELVIEW);
//         glLoadIdentity();
//         gluLookAt(cameraX, cameraY, cameraZ, lookAtX, lookAtY, lookAtZ, 0.0, 1.0, 0.0);

//         // Render the maze
//         renderMaze();

//         // Swap buffers and poll events
//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }

//     glfwDestroyWindow(window);
//     glfwTerminate();
//     return 0;
// }






// #include <GL/glew.h>
// #include <GLFW/glfw3.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

// // Maze dimensions
// #define MAZE_ROWS 5
// #define MAZE_COLS 5

// // Maze data
// int maze[MAZE_ROWS][MAZE_COLS] = {
//     {1, 0, 1, 1, 1},
//     {1, 0, 1, 0, 1},
//     {1, 0, 0, 0, 1},
//     {1, 1, 1, 0, 1},
//     {1, 1, 1, 0, 0},
// };

// // Camera position
// float cameraX = 2.0f, cameraY = 5.0f, cameraZ = 10.0f;
// float lookAtX = 2.0f, lookAtY = 0.0f, lookAtZ = 2.0f;

// // Vertex data for a cube
// GLfloat cubeVertices[] = {
//     // Front face
//     -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//      0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//     -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,

//     // Back face
//     -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//      0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//     -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,

//     // Left face
//     -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//     -0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//     -0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//     -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,

//     // Right face
//      0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//      0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//      0.5f,  0.5f, -0.5f,  0.0f, 1.0f,

//     // Top face
//     -0.5f,  0.5f, -0.5f,  0.0f, 0.0f,
//      0.5f,  0.5f, -0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//     -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,

//     // Bottom face
//     -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//      0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//      0.5f, -0.5f,  0.5f,  1.0f, 1.0f,
//     -0.5f, -0.5f,  0.5f,  0.0f, 1.0f,
// };

// // Function to draw a cube
// void drawCube() {
//     glEnableClientState(GL_VERTEX_ARRAY);
//     glVertexPointer(3, GL_FLOAT, 5 * sizeof(GLfloat), cubeVertices);
//     glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//     glTexCoordPointer(2, GL_FLOAT, 5 * sizeof(GLfloat), &cubeVertices[3]);

//     // Draw cube faces
//     for (int i = 0; i < 6; i++) {
//         glDrawArrays(GL_QUADS, i * 4, 4); // Each face has 4 vertices
//     }

//     glDisableClientState(GL_TEXTURE_COORD_ARRAY);
//     glDisableClientState(GL_VERTEX_ARRAY);
// }

// // Render the maze
// void renderMaze() {
//     for (int i = 0; i < MAZE_ROWS; i++) {
//         for (int j = 0; j < MAZE_COLS; j++) {
//             if (maze[i][j] == 1) {  // Wall
//                 glPushMatrix();
//                 glTranslatef((float)j, 0.0f, (float)i);
//                 drawCube();
//                 glPopMatrix();
//             }
//         }
//     }
// }

// // Handle input
// void processInput(GLFWwindow* window) {
//     if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) cameraZ -= 0.1f;
//     if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) cameraZ += 0.1f;
//     if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) cameraX -= 0.1f;
//     if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) cameraX += 0.1f;
//     if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) cameraY += 0.1f;
//     if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) cameraY -= 0.1f;
// }

// int main() {
//     // Initialize GLFW
//     if (!glfwInit()) {
//         fprintf(stderr, "Failed to initialize GLFW\n");
//         return -1;
//     }

//     GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Maze Game", NULL, NULL);
//     if (!window) {
//         fprintf(stderr, "Failed to create GLFW window\n");
//         glfwTerminate();
//         return -1;
//     }

//     glfwMakeContextCurrent(window);
//     glewInit();

//     glEnable(GL_DEPTH_TEST);

//     // Main loop
//     while (!glfwWindowShouldClose(window)) {
//         processInput(window);

//         // Clear the screen
//         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//         // Set the camera
//         glMatrixMode(GL_PROJECTION);
//         glLoadIdentity();
//         gluPerspective(45.0, 800.0 / 600.0, 0.1, 100.0);

//         glMatrixMode(GL_MODELVIEW);
//         glLoadIdentity();
//         gluLookAt(cameraX, cameraY, cameraZ, lookAtX, lookAtY, lookAtZ, 0.0, 1.0, 0.0);

//         // Render the maze
//         renderMaze();

//         // Swap buffers and poll events
//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }

//     glfwDestroyWindow(window);
//     glfwTerminate();
//     return 0;
// }












// #include <GL/glew.h>
// #include <GLFW/glfw3.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #define STB_IMAGE_IMPLEMENTATION
// #include "stb_image.h"

// // Maze dimensions
// #define MAZE_ROWS 5
// #define MAZE_COLS 5

// // Maze data
// int maze[MAZE_ROWS][MAZE_COLS] = {
//     {1, 0, 1, 1, 1},
//     {1, 0, 1, 0, 1},
//     {1, 0, 0, 0, 1},
//     {1, 1, 1, 0, 1},
//     {1, 1, 1, 0, 0},
// };

// // Camera position
// float cameraX = 2.0f, cameraY = 5.0f, cameraZ = 10.0f;
// float lookAtX = 2.0f, lookAtY = 0.0f, lookAtZ = 2.0f;

// GLuint texture;

// // Vertex data for a cube
// GLfloat cubeVertices[] = {
//     // Front face
//     -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//      0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//     -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,

//     // Back face
//     -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//      0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//     -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,

//     // Left face
//     -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//     -0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//     -0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//     -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,

//     // Right face
//      0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//      0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//      0.5f,  0.5f, -0.5f,  0.0f, 1.0f,

//     // Top face
//     -0.5f,  0.5f, -0.5f,  0.0f, 0.0f,
//      0.5f,  0.5f, -0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//     -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,

//     // Bottom face
//     -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//      0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//      0.5f, -0.5f,  0.5f,  1.0f, 1.0f,
//     -0.5f, -0.5f,  0.5f,  0.0f, 1.0f,
// };

// // Function to draw a cube
// void drawCube() {
//     glBindTexture(GL_TEXTURE_2D, texture);

//     glEnableClientState(GL_VERTEX_ARRAY);
//     glVertexPointer(3, GL_FLOAT, 5 * sizeof(GLfloat), cubeVertices);
//     glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//     glTexCoordPointer(2, GL_FLOAT, 5 * sizeof(GLfloat), &cubeVertices[3]);

//     for (int i = 0; i < 6; i++) {
//         glDrawArrays(GL_QUADS, i * 4, 4);
//     }

//     glDisableClientState(GL_TEXTURE_COORD_ARRAY);
//     glDisableClientState(GL_VERTEX_ARRAY);
// }

// // Render the maze
// void renderMaze() {
//     for (int i = 0; i < MAZE_ROWS; i++) {
//         for (int j = 0; j < MAZE_COLS; j++) {
//             if (maze[i][j] == 1) {  // Wall
//                 glPushMatrix();
//                 glTranslatef((float)j, 0.0f, (float)i);
//                 drawCube();
//                 glPopMatrix();
//             }
//         }
//     }
// }

// // Handle input
// void processInput(GLFWwindow* window) {
//     if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) cameraZ -= 0.1f;
//     if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) cameraZ += 0.1f;
//     if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) cameraX -= 0.1f;
//     if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) cameraX += 0.1f;
//     if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) cameraY += 0.1f;
//     if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) cameraY -= 0.1f;
// }

// void setupLighting() {
//     glEnable(GL_LIGHTING);
//     glEnable(GL_LIGHT0);

//     GLfloat lightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
//     GLfloat lightDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
//     GLfloat lightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//     GLfloat lightPosition[] = { 2.0f, 5.0f, 5.0f, 1.0f };

//     glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
//     glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
//     glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
//     glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
// }

// void loadTexture() {
//     glGenTextures(1, &texture);
//     glBindTexture(GL_TEXTURE_2D, texture);

//     int width, height, channels;
//     unsigned char* data = stbi_load("dirt.png", &width, &height, &channels, 0);
//     if (data) {
//         glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//         glGenerateMipmap(GL_TEXTURE_2D);
//     } else {
//         printf("Failed to load texture\n");
//     }
//     stbi_image_free(data);

//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
// }

// int main() {
//     // Initialize GLFW
//     if (!glfwInit()) {
//         fprintf(stderr, "Failed to initialize GLFW\n");
//         return -1;
//     }

//     GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Maze Game", NULL, NULL);
//     if (!window) {
//         fprintf(stderr, "Failed to create GLFW window\n");
//         glfwTerminate();
//         return -1;
//     }

//     glfwMakeContextCurrent(window);
//     glewInit();

//     glEnable(GL_DEPTH_TEST);
//     loadTexture();
//     setupLighting();

//     // Main loop
//     while (!glfwWindowShouldClose(window)) {
//         processInput(window);

//         // Clear the screen
//         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//         // Set the camera
//         glMatrixMode(GL_PROJECTION);
//         glLoadIdentity();
//         gluPerspective(45.0, 800.0 / 600.0, 0.1, 100.0);

//         glMatrixMode(GL_MODELVIEW);
//         glLoadIdentity();
//         gluLookAt(cameraX, cameraY, cameraZ, lookAtX, lookAtY, lookAtZ, 0.0, 1.0, 0.0);

//         // Render the maze
//         renderMaze();

//         // Swap buffers and poll events
//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }

//     glfwDestroyWindow(window);
//     glfwTerminate();
//     return 0;
// }













// #include <GL/glew.h>
// #include <GLFW/glfw3.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include <unistd.h>  // For getcwd()
// #define STB_IMAGE_IMPLEMENTATION
// #include "stb_image.h"





// // Maze dimensions
// #define MAZE_ROWS 5
// #define MAZE_COLS 5

// // Maze data
// int maze[MAZE_ROWS][MAZE_COLS] = {
//     {1, 0, 1, 1, 1},
//     {1, 0, 1, 0, 1},
//     {1, 0, 0, 0, 1},
//     {1, 1, 1, 0, 1},
//     {1, 1, 1, 0, 0},
// };

// // Camera position
// float cameraX = 2.0f, cameraY = 5.0f, cameraZ = 10.0f;
// float lookAtX = 2.0f, lookAtY = 0.0f, lookAtZ = 2.0f;

// GLuint texture;

// // Vertex data for a cube
// GLfloat cubeVertices[] = {
//     // Front face
//     -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//      0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//     -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,

//     // Back face
//     -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//      0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//     -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,

//     // Left face
//     -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//     -0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//     -0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//     -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,

//     // Right face
//      0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//      0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//      0.5f,  0.5f, -0.5f,  0.0f, 1.0f,

//     // Top face
//     -0.5f,  0.5f, -0.5f,  0.0f, 0.0f,
//      0.5f,  0.5f, -0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//     -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,

//     // Bottom face
//     -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//      0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//      0.5f, -0.5f,  0.5f,  1.0f, 1.0f,
//     -0.5f, -0.5f,  0.5f,  0.0f, 1.0f,
// };

// // Function to draw a cube
// void drawCube() {
//     glEnable(GL_TEXTURE_2D);  // Ensure texture is enabled
//     glBindTexture(GL_TEXTURE_2D, texture);

//     glEnableClientState(GL_VERTEX_ARRAY);
//     glVertexPointer(3, GL_FLOAT, 5 * sizeof(GLfloat), cubeVertices);
//     glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//     glTexCoordPointer(2, GL_FLOAT, 5 * sizeof(GLfloat), &cubeVertices[3]);

//     for (int i = 0; i < 6; i++) {
//         glDrawArrays(GL_QUADS, i * 4, 4);
//     }

//     glDisableClientState(GL_TEXTURE_COORD_ARRAY);
//     glDisableClientState(GL_VERTEX_ARRAY);
// }

// // Render the maze
// void renderMaze() {
//     for (int i = 0; i < MAZE_ROWS; i++) {
//         for (int j = 0; j < MAZE_COLS; j++) {
//             if (maze[i][j] == 1) {  // Wall
//                 glPushMatrix();
//                 glTranslatef((float)j, 0.0f, (float)i);
//                 drawCube();
//                 glPopMatrix();
//             }
//         }
//     }
// }

// // Handle input
// void processInput(GLFWwindow* window) {
//     if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) cameraZ -= 0.1f;
//     if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) cameraZ += 0.1f;
//     if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) cameraX -= 0.1f;
//     if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) cameraX += 0.1f;
//     if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) cameraY += 0.1f;
//     if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) cameraY -= 0.1f;
// }

// void setupLighting() {
//     glEnable(GL_LIGHTING);
//     glEnable(GL_LIGHT0);

//     GLfloat lightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
//     GLfloat lightDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
//     GLfloat lightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//     GLfloat lightPosition[] = { 2.0f, 5.0f, 5.0f, 1.0f };

//     glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
//     glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
//     glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
//     glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
// }

// void loadTexture() {
//     char cwd[1024];
//     if (getcwd(cwd, sizeof(cwd)) != NULL) {
//         printf("Current working directory: %s\n", cwd);
//     }

//     glGenTextures(1, &texture);
//     glBindTexture(GL_TEXTURE_2D, texture);

//     int width, height, channels;
//     unsigned char* data = stbi_load("dirt.png", &width, &height, &channels, 0);
//     if (!data) {
//         printf("Failed to load texture: %s\n", stbi_failure_reason());
//         exit(1);
//     }

//     GLenum format = (channels == 4) ? GL_RGBA : GL_RGB;
//     glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
//     glGenerateMipmap(GL_TEXTURE_2D);

//     stbi_image_free(data);

//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
// }

// int main() {
//     // Initialize GLFW
//     if (!glfwInit()) {
//         fprintf(stderr, "Failed to initialize GLFW\n");
//         return -1;
//     }

//     GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Maze Game", NULL, NULL);
//     if (!window) {
//         fprintf(stderr, "Failed to create GLFW window\n");
//         glfwTerminate();
//         return -1;
//     }

//     glfwMakeContextCurrent(window);
//     glewInit();

//     glEnable(GL_DEPTH_TEST);
//     loadTexture();
//     setupLighting();

//     // Main loop
//     while (!glfwWindowShouldClose(window)) {
//         processInput(window);

//         // Clear the screen
//         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//         // Set the camera
//         glMatrixMode(GL_PROJECTION);
//         glLoadIdentity();
//         gluPerspective(45.0, 800.0 / 600.0, 0.1, 100.0);

//         glMatrixMode(GL_MODELVIEW);
//         glLoadIdentity();
//         gluLookAt(cameraX, cameraY, cameraZ, lookAtX, lookAtY, lookAtZ, 0.0, 1.0, 0.0);

//         // Render the maze
//         renderMaze();

//         // Swap buffers and poll events
//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }

//     glfwDestroyWindow(window);
//     glfwTerminate();
//     return 0;
// }










// #include <GL/glew.h>
// #include <GLFW/glfw3.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include <unistd.h>  // For getcwd()
// #define STB_IMAGE_IMPLEMENTATION
// #include "stb_image.h"

// // Maze dimensions
// #define MAZE_ROWS 5
// #define MAZE_COLS 5

// // Maze data
// int maze[MAZE_ROWS][MAZE_COLS] = {
//     {1, 0, 1, 1, 1},
//     {1, 0, 1, 0, 1},
//     {1, 0, 0, 0, 1},
//     {1, 1, 1, 0, 1},
//     {1, 1, 1, 0, 0},
// };

// // Player movement and orientation
// float playerX = 2.0f, playerY = 1.0f, playerZ = 2.0f;  // Player's position
// float yaw = -90.0f;  // Initial direction facing down the Z-axis
// float pitch = 0.0f;  // Look straight ahead

// float movementSpeed = 0.1f;  // Player movement speed
// float mouseSensitivity = 0.1f;  // Mouse sensitivity

// float frontX = 0.0f, frontY = 0.0f, frontZ = -1.0f;  // Camera's forward vector

// GLuint texture;

// // Vertex data for a cube
// GLfloat cubeVertices[] = {
//     // Front face
//     -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//      0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//     -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,

//     // Back face
//     -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//      0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//     -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,

//     // Left face
//     -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//     -0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//     -0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//     -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,

//     // Right face
//      0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//      0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//      0.5f,  0.5f, -0.5f,  0.0f, 1.0f,

//     // Top face
//     -0.5f,  0.5f, -0.5f,  0.0f, 0.0f,
//      0.5f,  0.5f, -0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//     -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,

//     // Bottom face
//     -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//      0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//      0.5f, -0.5f,  0.5f,  1.0f, 1.0f,
//     -0.5f, -0.5f,  0.5f,  0.0f, 1.0f,
// };

// // Function to draw a cube
// void drawCube() {
//     glEnable(GL_TEXTURE_2D);
//     glBindTexture(GL_TEXTURE_2D, texture);

//     glEnableClientState(GL_VERTEX_ARRAY);
//     glVertexPointer(3, GL_FLOAT, 5 * sizeof(GLfloat), cubeVertices);
//     glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//     glTexCoordPointer(2, GL_FLOAT, 5 * sizeof(GLfloat), &cubeVertices[3]);

//     for (int i = 0; i < 6; i++) {
//         glDrawArrays(GL_QUADS, i * 4, 4);
//     }

//     glDisableClientState(GL_TEXTURE_COORD_ARRAY);
//     glDisableClientState(GL_VERTEX_ARRAY);
// }

// // Render the maze
// void renderMaze() {
//     for (int i = 0; i < MAZE_ROWS; i++) {
//         for (int j = 0; j < MAZE_COLS; j++) {
//             if (maze[i][j] == 1) {  // Wall
//                 glPushMatrix();
//                 glTranslatef((float)j, 0.0f, (float)i);
//                 drawCube();
//                 glPopMatrix();
//             }
//         }
//     }
// }

// // Update camera's forward direction
// void updateCameraDirection() {
//     frontX = cosf(glm_rad(yaw)) * cosf(glm_rad(pitch));
//     frontY = sinf(glm_rad(pitch));
//     frontZ = sinf(glm_rad(yaw)) * cosf(glm_rad(pitch));

//     // Normalize direction vector
//     float length = sqrtf(frontX * frontX + frontY * frontY + frontZ * frontZ);
//     frontX /= length;
//     frontY /= length;
//     frontZ /= length;
// }

// // Handle input
// void processInput(GLFWwindow* window) {
//     if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
//         playerX += frontX * movementSpeed;
//         playerZ += frontZ * movementSpeed;
//     }
//     if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
//         playerX -= frontX * movementSpeed;
//         playerZ -= frontZ * movementSpeed;
//     }
//     if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
//         playerX -= cosf(glm_rad(yaw + 90.0f)) * movementSpeed;
//         playerZ -= sinf(glm_rad(yaw + 90.0f)) * movementSpeed;
//     }
//     if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
//         playerX += cosf(glm_rad(yaw + 90.0f)) * movementSpeed;
//         playerZ += sinf(glm_rad(yaw + 90.0f)) * movementSpeed;
//     }

//     if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) yaw -= 1.0f;
//     if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) yaw += 1.0f;

//     updateCameraDirection();
// }

// // Update view based on player position
// void updateView() {
//     gluLookAt(
//         playerX, playerY, playerZ,                // Camera position
//         playerX + frontX, playerY + frontY, playerZ + frontZ,  // Look-at point
//         0.0f, 1.0f, 0.0f                         // Up vector
//     );
// }

// void loadTexture() {
//     glGenTextures(1, &texture);
//     glBindTexture(GL_TEXTURE_2D, texture);

//     int width, height, channels;
//     unsigned char* data = stbi_load("dirt.png", &width, &height, &channels, 0);
//     if (data) {
//         GLenum format = (channels == 4) ? GL_RGBA : GL_RGB;
//         glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
//         glGenerateMipmap(GL_TEXTURE_2D);
//     } else {
//         printf("Failed to load texture: %s\n", stbi_failure_reason());
//     }
//     stbi_image_free(data);

//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
// }

// int main() {
//     // Initialize GLFW
//     if (!glfwInit()) {
//         fprintf(stderr, "Failed to initialize GLFW\n");
//         return -1;
//     }

//     GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Maze Game", NULL, NULL);
//     if (!window) {
//         fprintf(stderr, "Failed to create GLFW window\n");
//         glfwTerminate();
//         return -1;
//     }

//     glfwMakeContextCurrent(window);
//     glewInit();

//     glEnable(GL_DEPTH_TEST);
//     loadTexture();

//     // Main loop
//     while (!glfwWindowShouldClose(window)) {
//         processInput(window);

//         // Clear the screen
//         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//         // Set the camera
//         glMatrixMode(GL_PROJECTION);
//         glLoadIdentity();
//         gluPerspective(45.0, 800.0 / 600.0, 0.1, 100.0);

//         glMatrixMode(GL_MODELVIEW);
//         glLoadIdentity();
//         updateView();

//         // Render the maze
//         renderMaze();

//         // Swap buffers and poll events
//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }

//     glfwDestroyWindow(window);
//     glfwTerminate();
//     return 0;
// }
























// #include <GL/glew.h>
// #include <GLFW/glfw3.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include <unistd.h>  // For getcwd()
// #define STB_IMAGE_IMPLEMENTATION
// #include "stb_image.h"

// // Maze dimensions
// #define MAZE_ROWS 5
// #define MAZE_COLS 5

// // Maze data
// int maze[MAZE_ROWS][MAZE_COLS] = {
//     {1, 0, 1, 1, 1},
//     {1, 0, 1, 0, 1},
//     {1, 0, 0, 0, 1},
//     {1, 1, 1, 0, 1},
//     {1, 1, 1, 0, 0},
// };

// // Player movement and orientation
// float playerX = 2.0f, playerY = 1.0f, playerZ = 2.0f;  // Player's position
// float yaw = -90.0f;  // Initial direction facing down the Z-axis
// float pitch = 0.0f;  // Look straight ahead

// float movementSpeed = 0.1f;  // Player movement speed
// float mouseSensitivity = 0.1f;  // Mouse sensitivity

// float frontX = 0.0f, frontY = 0.0f, frontZ = -1.0f;  // Camera's forward vector

// GLuint texture;

// // Vertex data for a cube
// GLfloat cubeVertices[] = {
//     // Front face
//     -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//      0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//     -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,

//     // Back face
//     -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//      0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//     -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,

//     // Left face
//     -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//     -0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//     -0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//     -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,

//     // Right face
//      0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//      0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//      0.5f,  0.5f, -0.5f,  0.0f, 1.0f,

//     // Top face
//     -0.5f,  0.5f, -0.5f,  0.0f, 0.0f,
//      0.5f,  0.5f, -0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//     -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,

//     // Bottom face
//     -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//      0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//      0.5f, -0.5f,  0.5f,  1.0f, 1.0f,
//     -0.5f, -0.5f,  0.5f,  0.0f, 1.0f,
// };

// // Helper to convert degrees to radians
// #define DEG_TO_RAD(deg) ((deg) * M_PI / 180.0f)

// // Function to draw a cube
// void drawCube() {
//     glEnable(GL_TEXTURE_2D);
//     glBindTexture(GL_TEXTURE_2D, texture);

//     glEnableClientState(GL_VERTEX_ARRAY);
//     glVertexPointer(3, GL_FLOAT, 5 * sizeof(GLfloat), cubeVertices);
//     glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//     glTexCoordPointer(2, GL_FLOAT, 5 * sizeof(GLfloat), &cubeVertices[3]);

//     for (int i = 0; i < 6; i++) {
//         glDrawArrays(GL_QUADS, i * 4, 4);
//     }

//     glDisableClientState(GL_TEXTURE_COORD_ARRAY);
//     glDisableClientState(GL_VERTEX_ARRAY);
// }

// // Render the maze
// void renderMaze() {
//     for (int i = 0; i < MAZE_ROWS; i++) {
//         for (int j = 0; j < MAZE_COLS; j++) {
//             if (maze[i][j] == 1) {  // Wall
//                 glPushMatrix();
//                 glTranslatef((float)j, 0.0f, (float)i);
//                 drawCube();
//                 glPopMatrix();
//             }
//         }
//     }
// }

// // Update camera's forward direction
// void updateCameraDirection() {
//     frontX = cosf(DEG_TO_RAD(yaw)) * cosf(DEG_TO_RAD(pitch));
//     frontY = sinf(DEG_TO_RAD(pitch));
//     frontZ = sinf(DEG_TO_RAD(yaw)) * cosf(DEG_TO_RAD(pitch));

//     // Normalize direction vector
//     float length = sqrtf(frontX * frontX + frontY * frontY + frontZ * frontZ);
//     frontX /= length;
//     frontY /= length;
//     frontZ /= length;
// }

// // Custom lookAt function (replaces gluLookAt)
// void lookAt(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ) {
//     float forwardX = centerX - eyeX;
//     float forwardY = centerY - eyeY;
//     float forwardZ = centerZ - eyeZ;
//     float forwardLen = sqrtf(forwardX * forwardX + forwardY * forwardY + forwardZ * forwardZ);

//     forwardX /= forwardLen;
//     forwardY /= forwardLen;
//     forwardZ /= forwardLen;

//     float sideX = forwardY * upZ - forwardZ * upY;
//     float sideY = forwardZ * upX - forwardX * upZ;
//     float sideZ = forwardX * upY - forwardY * upX;
//     float sideLen = sqrtf(sideX * sideX + sideY * sideY + sideZ * sideZ);

//     sideX /= sideLen;
//     sideY /= sideLen;
//     sideZ /= sideLen;

//     float upnX = sideY * forwardZ - sideZ * forwardY;
//     float upnY = sideZ * forwardX - sideX * forwardZ;
//     float upnZ = sideX * forwardY - sideY * forwardX;

//     GLfloat matrix[16] = {
//         sideX, upnX, -forwardX, 0.0f,
//         sideY, upnY, -forwardY, 0.0f,
//         sideZ, upnZ, -forwardZ, 0.0f,
//         0.0f,  0.0f,   0.0f,    1.0f
//     };

//     glMultMatrixf(matrix);
//     glTranslatef(-eyeX, -eyeY, -eyeZ);
// }

// // Custom perspective function (replaces gluPerspective)
// void perspective(float fovY, float aspect, float zNear, float zFar) {
//     float f = 1.0f / tanf(DEG_TO_RAD(fovY) / 2.0f);
//     float zRange = zNear - zFar;

//     GLfloat matrix[16] = {
//         f / aspect, 0.0f,  0.0f,                          0.0f,
//         0.0f,       f,     0.0f,                          0.0f,
//         0.0f,       0.0f,  (zFar + zNear) / zRange,      -1.0f,
//         0.0f,       0.0f,  2.0f * zFar * zNear / zRange,  0.0f
//     };

//     glMultMatrixf(matrix);
// }

// // Handle input
// void processInput(GLFWwindow* window) {
//     if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
//         playerX += frontX * movementSpeed;
//         playerZ += frontZ * movementSpeed;
//     }
//     if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
//         playerX -= frontX * movementSpeed;
//         playerZ -= frontZ * movementSpeed;
//     }
//     if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
//         playerX -= cosf(DEG_TO_RAD(yaw + 90.0f)) * movementSpeed;
//         playerZ -= sinf(DEG_TO_RAD(yaw + 90.0f)) * movementSpeed;
//     }
//     if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
//         playerX += cosf(DEG_TO_RAD(yaw + 90.0f)) * movementSpeed;
//         playerZ += sinf(DEG_TO_RAD(yaw + 90.0f)) * movementSpeed;
//     }

//     if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) yaw -= 1.0f;
//     if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) yaw += 1.0f;

//     updateCameraDirection();
// }

// void loadTexture() {
//     glGenTextures(1, &texture);
//     glBindTexture(GL_TEXTURE_2D, texture);

//     int width, height, channels;
//     unsigned char* data = stbi_load("dirt.png", &width, &height, &channels, 0);
//     if (data) {
//         GLenum format = (channels == 4) ? GL_RGBA : GL_RGB;
//         glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
//         glGenerateMipmap(GL_TEXTURE_2D);
//     } else {
//         printf("Failed to load texture: %s\n", stbi_failure_reason());
//     }
//     stbi_image_free(data);

//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
// }

// int main() {
//     // Initialize GLFW
//     if (!glfwInit()) {
//         fprintf(stderr, "Failed to initialize GLFW\n");
//         return -1;
//     }

//     GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Maze Game", NULL, NULL);
//     if (!window) {
//         fprintf(stderr, "Failed to create GLFW window\n");
//         glfwTerminate();
//         return -1;
//     }

//     glfwMakeContextCurrent(window);
//     glewInit();

//     glEnable(GL_DEPTH_TEST);
//     loadTexture();

//     // Main loop
//     while (!glfwWindowShouldClose(window)) {
//         processInput(window);

//         // Clear the screen
//         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//         // Set the camera
//         glMatrixMode(GL_PROJECTION);
//         glLoadIdentity();
//         perspective(45.0f, 800.0 / 600.0, 0.1f, 100.0f);

//         glMatrixMode(GL_MODELVIEW);
//         glLoadIdentity();
//         lookAt(playerX, playerY, playerZ, playerX + frontX, playerY + frontY, playerZ + frontZ, 0.0f, 1.0f, 0.0f);

//         // Render the maze
//         renderMaze();

//         // Swap buffers and poll events
//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }

//     glfwDestroyWindow(window);
//     glfwTerminate();
//     return 0;
// }








































// #include <GL/glew.h>
// #include <GLFW/glfw3.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include <unistd.h>  // For getcwd()
// #define STB_IMAGE_IMPLEMENTATION
// #include "stb_image.h"

// // Maze dimensions
// #define MAZE_ROWS 5
// #define MAZE_COLS 5

// // Maze data
// int maze[MAZE_ROWS][MAZE_COLS] = {
//     {1, 0, 1, 1, 1},
//     {1, 0, 1, 0, 1},
//     {1, 0, 0, 0, 1},
//     {1, 1, 1, 0, 1},
//     {1, 1, 1, 0, 0},
// };

// // Player movement and orientation
// float playerX = 2.0f, playerY = 1.0f, playerZ = 2.0f;  // Player's position
// float yaw = -90.0f;  // Initial direction facing down the Z-axis
// float pitch = 0.0f;  // Look straight ahead

// float movementSpeed = 0.1f;  // Player movement speed
// float mouseSensitivity = 0.1f;  // Mouse sensitivity

// float frontX = 0.0f, frontY = 0.0f, frontZ = -1.0f;  // Camera's forward vector

// GLuint dirtTexture, grassTexture;  // Textures for the maze

// // Vertex data for a cube
// GLfloat cubeVertices[] = {
//     // Front face
//     -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//      0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//     -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,

//     // Back face
//     -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//      0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//     -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,

//     // Left face
//     -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//     -0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//     -0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//     -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,

//     // Right face
//      0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//      0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//      0.5f,  0.5f, -0.5f,  0.0f, 1.0f,

//     // Top face
//     -0.5f,  0.5f, -0.5f,  0.0f, 0.0f,
//      0.5f,  0.5f, -0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//     -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,

//     // Bottom face
//     -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//      0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//      0.5f, -0.5f,  0.5f,  1.0f, 1.0f,
//     -0.5f, -0.5f,  0.5f,  0.0f, 1.0f,
// };

// // Helper to convert degrees to radians
// #define DEG_TO_RAD(deg) ((deg) * M_PI / 180.0f)

// // Function to load textures
// GLuint loadTexture(const char* filename) {
//     GLuint textureID;
//     glGenTextures(1, &textureID);
//     glBindTexture(GL_TEXTURE_2D, textureID);

//     int width, height, channels;
//     unsigned char* data = stbi_load(filename, &width, &height, &channels, 0);
//     if (data) {
//         GLenum format = (channels == 4) ? GL_RGBA : GL_RGB;
//         glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
//         glGenerateMipmap(GL_TEXTURE_2D);
//     } else {
//         printf("Failed to load texture: %s\n", stbi_failure_reason());
//     }
//     stbi_image_free(data);

//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

//     return textureID;
// }

// // Function to draw a cube with a specific texture
// void drawCube(GLuint textureID) {
//     glEnable(GL_TEXTURE_2D);
//     glBindTexture(GL_TEXTURE_2D, textureID);  // Bind the provided texture ID

//     glEnableClientState(GL_VERTEX_ARRAY);
//     glVertexPointer(3, GL_FLOAT, 5 * sizeof(GLfloat), cubeVertices);
//     glEnableClientState(GL_TEXTURE_COORD_ARRAY);
//     glTexCoordPointer(2, GL_FLOAT, 5 * sizeof(GLfloat), &cubeVertices[3]);

//     for (int i = 0; i < 6; i++) {
//         glDrawArrays(GL_QUADS, i * 4, 4);
//     }

//     glDisableClientState(GL_TEXTURE_COORD_ARRAY);
//     glDisableClientState(GL_VERTEX_ARRAY);
// }

// // Render the maze with textures
// void renderMaze() {
//     for (int i = 0; i < MAZE_ROWS; i++) {
//         for (int j = 0; j < MAZE_COLS; j++) {
//             glPushMatrix();
//             glTranslatef((float)j, 0.0f, (float)i);

//             if (maze[i][j] == 1) {
//                 drawCube(dirtTexture);  // Use dirt texture for walls
//             } else {
//                 drawCube(grassTexture);  // Use grass texture for floor
//             }

//             glPopMatrix();
//         }
//     }
// }

// // Update camera's forward direction
// void updateCameraDirection() {
//     frontX = cosf(DEG_TO_RAD(yaw)) * cosf(DEG_TO_RAD(pitch));
//     frontY = sinf(DEG_TO_RAD(pitch));
//     frontZ = sinf(DEG_TO_RAD(yaw)) * cosf(DEG_TO_RAD(pitch));

//     // Normalize direction vector
//     float length = sqrtf(frontX * frontX + frontY * frontY + frontZ * frontZ);
//     frontX /= length;
//     frontY /= length;
//     frontZ /= length;
// }

// // Custom lookAt function
// void lookAt(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ) {
//     float forwardX = centerX - eyeX;
//     float forwardY = centerY - eyeY;
//     float forwardZ = centerZ - eyeZ;
//     float forwardLen = sqrtf(forwardX * forwardX + forwardY * forwardY + forwardZ * forwardZ);

//     forwardX /= forwardLen;
//     forwardY /= forwardLen;
//     forwardZ /= forwardLen;

//     float sideX = forwardY * upZ - forwardZ * upY;
//     float sideY = forwardZ * upX - forwardX * upZ;
//     float sideZ = forwardX * upY - forwardY * upX;
//     float sideLen = sqrtf(sideX * sideX + sideY * sideY + sideZ * sideZ);

//     sideX /= sideLen;
//     sideY /= sideLen;
//     sideZ /= sideLen;

//     float upnX = sideY * forwardZ - sideZ * forwardY;
//     float upnY = sideZ * forwardX - sideX * forwardZ;
//     float upnZ = sideX * forwardY - sideY * forwardX;

//     GLfloat matrix[16] = {
//         sideX, upnX, -forwardX, 0.0f,
//         sideY, upnY, -forwardY, 0.0f,
//         sideZ, upnZ, -forwardZ, 0.0f,
//         0.0f,  0.0f,   0.0f,    1.0f
//     };

//     glMultMatrixf(matrix);
//     glTranslatef(-eyeX, -eyeY, -eyeZ);
// }

// // Custom perspective function
// void perspective(float fovY, float aspect, float zNear, float zFar) {
//     float f = 1.0f / tanf(DEG_TO_RAD(fovY) / 2.0f);
//     float zRange = zNear - zFar;

//     GLfloat matrix[16] = {
//         f / aspect, 0.0f,  0.0f,                          0.0f,
//         0.0f,       f,     0.0f,                          0.0f,
//         0.0f,       0.0f,  (zFar + zNear) / zRange,      -1.0f,
//         0.0f,       0.0f,  2.0f * zFar * zNear / zRange,  0.0f
//     };

//     glMultMatrixf(matrix);
// }

// // Handle input
// void processInput(GLFWwindow* window) {
//     if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
//         playerX += frontX * movementSpeed;
//         playerZ += frontZ * movementSpeed;
//     }
//     if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
//         playerX -= frontX * movementSpeed;
//         playerZ -= frontZ * movementSpeed;
//     }
//     if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
//         playerX -= cosf(DEG_TO_RAD(yaw + 90.0f)) * movementSpeed;
//         playerZ -= sinf(DEG_TO_RAD(yaw + 90.0f)) * movementSpeed;
//     }
//     if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
//         playerX += cosf(DEG_TO_RAD(yaw + 90.0f)) * movementSpeed;
//         playerZ += sinf(DEG_TO_RAD(yaw + 90.0f)) * movementSpeed;
//     }

//     if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) yaw -= 1.0f;
//     if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) yaw += 1.0f;

//     updateCameraDirection();
// }

// int main() {
//     // Initialize GLFW
//     if (!glfwInit()) {
//         fprintf(stderr, "Failed to initialize GLFW\n");
//         return -1;
//     }

//     GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Maze Game", NULL, NULL);
//     if (!window) {
//         fprintf(stderr, "Failed to create GLFW window\n");
//         glfwTerminate();
//         return -1;
//     }

//     glfwMakeContextCurrent(window);
//     glewInit();

//     glEnable(GL_DEPTH_TEST);

//     // Load textures
//     dirtTexture = loadTexture("dirt.png");
//     grassTexture = loadTexture("grass.png");

//     // Main loop
//     while (!glfwWindowShouldClose(window)) {
//         processInput(window);

//         // Clear the screen
//         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//         // Set the camera
//         glMatrixMode(GL_PROJECTION);
//         glLoadIdentity();
//         perspective(45.0f, 800.0 / 600.0, 0.1f, 100.0f);

//         glMatrixMode(GL_MODELVIEW);
//         glLoadIdentity();
//         lookAt(playerX, playerY, playerZ, playerX + frontX, playerY + frontY, playerZ + frontZ, 0.0f, 1.0f, 0.0f);

//         // Render the maze
//         renderMaze();

//         // Swap buffers and poll events
//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }

//     glfwDestroyWindow(window);
//     glfwTerminate();
//     return 0;
// }



















#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>   // For random number seeding
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// Maze dimensions
#define MAZE_ROWS 25
#define MAZE_COLS 25

// Cell states
#define WALL 1
#define PATH 0

void initializeMaze();
void generateMaze(int x, int y);
void renderMaze();
void drawCube(GLuint textureID);
void perspective(float fovY, float aspect, float zNear, float zFar);
void lookAt(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ);
GLuint loadTexture(const char* filename);
void updateCameraDirection();
void processInput(GLFWwindow* window);


// Maze data
int maze[MAZE_ROWS][MAZE_COLS];


// Camera initialization for starting above the maze
float playerX = MAZE_COLS / 2.0f;  // Middle of the maze in X
float playerY = 50.0f;             // Height above the maze
float playerZ = MAZE_ROWS / 2.0f;  // Middle of the maze in Z
float yaw = -90.0f;                // Facing directly down initially
float pitch = -90.0f;              // Pitch to look straight down




float movementSpeed = 0.1f;  // Player movement speed
float mouseSensitivity = 0.1f;  // Mouse sensitivity

float frontX = 0.0f, frontY = 0.0f, frontZ = -1.0f;  // Camera's forward vector





GLuint dirtTexture, grassTexture;  // Textures for the maze

// Vertex data for a cube
GLfloat cubeVertices[] = {
    // Front face
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,

    // Back face
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,

    // Left face
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,

    // Right face
     0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  0.0f, 1.0f,

    // Top face
    -0.5f,  0.5f, -0.5f,  0.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,

    // Bottom face
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 1.0f,
};

// Helper to convert degrees to radians
#define DEG_TO_RAD(deg) ((deg) * M_PI / 180.0f)


void perspective(float fovY, float aspect, float zNear, float zFar) {
    float f = 1.0f / tanf(DEG_TO_RAD(fovY) / 2.0f);
    float zRange = zNear - zFar;

    GLfloat matrix[16] = {
        f / aspect, 0.0f,  0.0f,                          0.0f,
        0.0f,       f,     0.0f,                          0.0f,
        0.0f,       0.0f,  (zFar + zNear) / zRange,      -1.0f,
        0.0f,       0.0f,  2.0f * zFar * zNear / zRange,  0.0f
    };

    glMultMatrixf(matrix);
}

void lookAt(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ) {
    float forwardX = centerX - eyeX;
    float forwardY = centerY - eyeY;
    float forwardZ = centerZ - eyeZ;
    float forwardLen = sqrtf(forwardX * forwardX + forwardY * forwardY + forwardZ * forwardZ);

    forwardX /= forwardLen;
    forwardY /= forwardLen;
    forwardZ /= forwardLen;

    float sideX = forwardY * upZ - forwardZ * upY;
    float sideY = forwardZ * upX - forwardX * upZ;
    float sideZ = forwardX * upY - forwardY * upX;
    float sideLen = sqrtf(sideX * sideX + sideY * sideY + sideZ * sideZ);

    sideX /= sideLen;
    sideY /= sideLen;
    sideZ /= sideLen;

    float upnX = sideY * forwardZ - sideZ * forwardY;
    float upnY = sideZ * forwardX - sideX * forwardZ;
    float upnZ = sideX * forwardY - sideY * forwardX;

    GLfloat matrix[16] = {
        sideX, upnX, -forwardX, 0.0f,
        sideY, upnY, -forwardY, 0.0f,
        sideZ, upnZ, -forwardZ, 0.0f,
        0.0f,  0.0f,   0.0f,    1.0f
    };

    glMultMatrixf(matrix);
    glTranslatef(-eyeX, -eyeY, -eyeZ);
}

// Recursive function to generate the maze
void generateMaze(int x, int y) {
    // Possible directions: {dx, dy}
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // Randomly shuffle directions
    for (int i = 0; i < 4; i++) {
        int r = rand() % 4;
        int tempX = directions[i][0], tempY = directions[i][1];
        directions[i][0] = directions[r][0];
        directions[i][1] = directions[r][1];
        directions[r][0] = tempX;
        directions[r][1] = tempY;
    }

    // Try each direction
    for (int i = 0; i < 4; i++) {
        int newX = x + directions[i][0] * 2;  // Move two cells in the direction
        int newY = y + directions[i][1] * 2;

        // Check bounds and if the cell is a wall
        if (newX >= 1 && newX < MAZE_ROWS - 1 && newY >= 1 && newY < MAZE_COLS - 1 && maze[newX][newY] == WALL) {
            // Carve the path
            maze[x + directions[i][0]][y + directions[i][1]] = PATH;  // Intermediate cell
            maze[newX][newY] = PATH;                                  // New cell

            // Recur from the new cell
            generateMaze(newX, newY);
        }
    }
}

// Initialize the maze
void initializeMaze() {
    // Fill maze with walls
    for (int i = 0; i < MAZE_ROWS; i++) {
        for (int j = 0; j < MAZE_COLS; j++) {
            maze[i][j] = WALL;
        }
    }

    // Set the starting point
    maze[1][1] = PATH;

    // Generate the maze
    generateMaze(1, 1);

    // Set the exit point
    maze[MAZE_ROWS - 2][MAZE_COLS - 2] = PATH;
}



// Render the maze with textures
void renderMaze() {
    for (int i = 0; i < MAZE_ROWS; i++) {
        for (int j = 0; j < MAZE_COLS; j++) {
            if (maze[i][j] == WALL) {
                // Draw 4 cubes stacked vertically for walls
                for (int k = 0; k < 4; k++) {
                    glPushMatrix();
                    glTranslatef((float)j, (float)k, (float)i);  // Offset in Y-axis for stacking
                    drawCube(dirtTexture);  // Use dirt texture for walls
                    glPopMatrix();
                }
            } else {
                // Draw a single cube for paths
                glPushMatrix();
                glTranslatef((float)j, 0.0f, (float)i);  // Single cube at ground level
                drawCube(grassTexture);  // Use grass texture for paths
                glPopMatrix();
            }
        }
    }
}


// Function to load textures
GLuint loadTexture(const char* filename) {
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    int width, height, channels;
    unsigned char* data = stbi_load(filename, &width, &height, &channels, 0);
    if (data) {
        GLenum format = (channels == 4) ? GL_RGBA : GL_RGB;
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        printf("Failed to load texture: %s\n", filename);
    }
    stbi_image_free(data);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    return textureID;
}

// Function to draw a cube with a specific texture
void drawCube(GLuint textureID) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 5 * sizeof(GLfloat), cubeVertices);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glTexCoordPointer(2, GL_FLOAT, 5 * sizeof(GLfloat), &cubeVertices[3]);

    for (int i = 0; i < 6; i++) {
        glDrawArrays(GL_QUADS, i * 4, 4);
    }

    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}

// Update the camera's forward direction based on yaw and pitch
void updateCameraDirection() {
    frontX = cosf(DEG_TO_RAD(yaw)) * cosf(DEG_TO_RAD(pitch));
    frontY = sinf(DEG_TO_RAD(pitch));
    frontZ = sinf(DEG_TO_RAD(yaw)) * cosf(DEG_TO_RAD(pitch));

    // Normalize the forward vector
    float length = sqrtf(frontX * frontX + frontY * frontY + frontZ * frontZ);
    frontX /= length;
    frontY /= length;
    frontZ /= length;
}

// Process input and update camera position
void processInput(GLFWwindow* window) {
    // Forward and backward movement
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        playerX += frontX * movementSpeed;
        playerY += frontY * movementSpeed;
        playerZ += frontZ * movementSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        playerX -= frontX * movementSpeed;
        playerY -= frontY * movementSpeed;
        playerZ -= frontZ * movementSpeed;
    }

    // Left and right strafing
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        playerX -= cosf(DEG_TO_RAD(yaw + 90.0f)) * movementSpeed;
        playerZ -= sinf(DEG_TO_RAD(yaw + 90.0f)) * movementSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        playerX += cosf(DEG_TO_RAD(yaw + 90.0f)) * movementSpeed;
        playerZ += sinf(DEG_TO_RAD(yaw + 90.0f)) * movementSpeed;
    }

    // Adjust yaw (left and right) with arrow keys
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) yaw -= 1.0f;
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) yaw += 1.0f;

    // Adjust pitch (up and down) with arrow keys (optional)
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) pitch += 1.0f;
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) pitch -= 1.0f;

    // Constrain pitch to prevent the camera from flipping
    if (pitch > 89.0f) pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;

    // Recalculate the forward vector based on yaw and pitch
    updateCameraDirection();
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Maze Game", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewInit();

    glEnable(GL_DEPTH_TEST);

    // Initialize the maze
    srand(time(NULL));  // Seed the random number generator
    initializeMaze();

    // Load textures
    dirtTexture = loadTexture("dirt.png");
    grassTexture = loadTexture("grass.png");

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Process input
        processInput(window);

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Set the camera
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        perspective(45.0f, 800.0 / 600.0, 0.1f, 100.0f);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        lookAt(playerX, playerY, playerZ, playerX + frontX, playerY + frontY, playerZ + frontZ, 0.0f, 1.0f, 0.0f);

        // Render the maze
        renderMaze();

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}































