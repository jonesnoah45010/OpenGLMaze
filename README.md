# OpenGL Maze Game

This project is very basic OpenGL-based rendering program written in C. The program involves rendering a 3D randomly generated maze with cubes, textures and basic lighting using GLFW, GLEW and GLM. The camera has basic movement for viewing the maze at different angles.  It a good template if you wish to build a 3d game from scratch using C and OpenGL.

## Prerequisites

To compile and run this program, ensure the following tools and libraries are installed on your system:

### macOS

1. **Clang** (comes pre-installed with Xcode Command Line Tools):
   ```bash
   xcode-select --install
   ```
2. **Homebrew** (if not already installed):
   ```bash
   /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
   ```
3. **Required libraries**:
   Install GLFW, GLEW and GLM using Homebrew:
   ```bash
   brew install glfw glew glm
   ```

### Other Tools
- A terminal or command line interface.

## Files

- `main.c`: The source code for the project.
- `Makefile`: The makefile to compile and link the project.

## How to Compile and Run

### Step 1: Clone or Copy the Project
Place the `main.c` and `Makefile` into a folder named `OpenGLMaze`.

### Step 2: Navigate to the Project Directory
```bash
cd OpenGLMaze
```

### Step 3: Compile the Program
Run the `make` command to compile the program:
```bash
make
```
This will generate an executable file named `OpenGLMaze` in the same directory.

### Step 4: Run the Program
Execute the program with:
```bash
./OpenGLMaze
```

## Troubleshooting

1. **Error: `library 'GL' not found`**:
   - On macOS, OpenGL is part of the system frameworks. Ensure the Makefile uses `-framework OpenGL` instead of `-lGL`.

2. **Library Not Found (GLFW/GLEW)**:
   - Ensure Homebrew-installed libraries are correctly referenced. Add the following to the `Makefile` if necessary:
     ```makefile
     CFLAGS = -Wall -Wextra -std=c99 -O2 -I/opt/homebrew/include
     LIBS = -L/opt/homebrew/lib -lglfw -lGLEW -framework OpenGL -lm
     ```

3. **Permissions Issue**:
   - If the executable doesn’t have permission to run, use:
     ```bash
     chmod +x OpenGLMaze
     ```

## Next Steps

- Extend the code to render 3D cubes and apply textures.
- Add user input for navigation.
- Implement lighting and animations.

Feel free to reach out if you encounter issues or need additional help!
