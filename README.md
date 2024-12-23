# Array Modifier App Using C

## Description

**The Array Modifier Console App** is a modular C project, which involves **manipulate** and **analyze** Arrays that dynamically
allocated on the Heap and **scaling the performance** of each manipulation. Users can interact with the program
through a
terminal; where they can perform various operations like **core, search, sorting, statistical and transformation** method analyzes on arrays.

## What is Used

* **C Language:** Functionality and manipulation methods. Modularity, data-structures, pointers, macros and much more. 
* **CMake:** Cross-platform build automation.
* **Git:** Version control and collaboration.

## App Preview

// image

## How to Build and Run

* **Build Systems**: While this guide uses Ninja as an example, you can choose any build system (e.g. Makefiles or
  Visual
  Studio). CMake makes it easy to adapt.
* **IDEs**: If you are using an IDE like CLion, you can open the project directly in the IDE, and it will handle these
  steps automatically.

1. **Prerequisites for Project**

   Install necessary build tools and compilers on your syste:
    * C compiler: GCC, Clang, or MSVC, depending on your operating system.
    * Cmake: Build automation tool. Download from [cmake/download](https://cmake.org/download/)

2. **Clone the Repository**
   ```
   git clone https://github.com/your-username/array-modifier-app.git
   cd array-modifier-app
   ```

3. **Create and go to Build directory where CMakeLists.txt is located**

   ```
   mkdir build
   cd build
   ```

4. **Generate Build Files**

   Generate build files inside build directory using **CMake**. You can use the
   command line or an IDE such as CLion.

   **For command line** (choose generator like Ninja, Makefile, or others):

   ```
   cmake -G "Ninja" ..  # For Ninja
   cmake -G "Unix Makefiles" ..  # For Makefile
   ```

   Step assumes you have **CMake** and generator (Ninja, makefile etc.) installed. The ".." points to the parent directory
   where the _CMakeLists.txt_ file is
   located.

   For **IDE**: If you're using an IDE like **CLion**, simply open the project in the IDE. It will automatically detect
   the
   _CMakeLists.txt_ and set up build directory and the project for you.

5. **Build the Project**

   After generating the build system, now you can build the application
   ```
   ninja
   ``` 
   if you have Makefiles then:
   ```
   make
   ``` 

6. **Run the Application**

   After building the project, **.exe** file will be created inside of **build** directory.

   **NOTE:** The project include _ASCII_ and _ANSI_ standards on terminal text. Because of that to get result as on app
   preview image abow make sure that your terminal supports that standards.

   Run it from the terminal:

   ```
   ./array-modifier-console-app
   ```

   ### Clean the Build Directory

   To delete the build files, navigate to build directory and run this command:

      ```
      cmake --build . --target clean_all
      ```

## Addable Features

* Expand functionality with more advanced Algorithms
* Supporting for file-based input and output
* Adding unit tests for core functions
