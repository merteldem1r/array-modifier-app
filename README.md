![Array Modifier App Using](https://github.com/user-attachments/assets/3741912a-0d4e-48c8-aaec-36d66f843654)

## Description

**The Array Modifier Console App** is a modular C project, which involves **manipulate** and **analyze** Arrays that
dynamically
allocated on the Heap and **scaling the performance** of each manipulation. Users can interact with the program
through a
terminal; where they can perform various operations like **core, search, sorting, statistical and transformation**
method analyzes on arrays.

## What is Used

* **C Language:** Functionality and manipulation methods. Modularity, data-structures, pointers, macros, error handling and much more.
* **CMake:** Cross-platform build automation.
* **Git:** Version control and collaboration.

## Key Features

* **Dynamic Memory Management**: Allocate and manage arrays efficiently on the heap.
* **Performance Tracking**:  Display CPU time and memory usage for each operation, compare methods.
* **Core Operations**: Display, append, insert, delete, and update array elements.
* **Statistical Analyse**: Compute sum, mean, median, mode, variance, and standard deviation.
* **Transformation Tools**: Reverse, rotate, scale, and normalize arrays.
* **Search & Sorting**: Includes linear, binary, and k-nearest searches, alongside multiple sorting algorithms
  like Quick Sort and Heap Sort.

## App Preview

### Initialize 

![initialize_array](https://github.com/user-attachments/assets/172b406c-ac15-4010-95cf-31368ce035ce)

### Operations

![choose_option](https://github.com/user-attachments/assets/1b4f9d91-71c7-47d8-b5b3-7e34b998887a)

### Examples

// Foo

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

   Step assumes you have **CMake** and generator (Ninja, makefile etc.) installed. The ".." points to the parent
   directory
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

* Statistical graphs to compare methods using Python (coming soon)
* Expand functionality with more advanced Algorithms
* Supporting for file-based input and output
* Adding unit tests for core functions
