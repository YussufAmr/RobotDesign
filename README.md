# Link Stress Analysis & Dimension Optimization 📊🔧💭

## Overview 📈💡🔄

This project aims to analyze the mechanical behavior of links under loading conditions. It calculates various properties such as mass, bending moment, moment of inertia, and maximum stress based on user inputs. In addition, the project employs an iterative optimization routine to adjust the dimensions of the link (either rectangular or circular cross-section) so that the stress does not exceed the material yield strength. This project is a work in progress and will be continuously updated.

## Project Structure 📁📚🔹

The repository is structured as follows: 🔍🔠🔃

- **main.cpp**  
  The entry point of the program. It instantiates objects and calls methods to collect user inputs, perform calculations, and optimize the link dimensions.

- **links.h / links.cpp**  
  These files contain the `links` class which encapsulates the functions to:
  - Read and validate the cross-section type (rectangle or circle).
  - Collect geometric data and payload information.
  - Calculate the mass of the link, bending moment, moment of inertia, and maximum stress.
  - Optimize the cross-sectional dimensions to meet stress requirements.

- **materials.h / materials.cpp**  
  These files implement the `materials` class. The class includes a preset list of materials (with associated yield strength and density) and allows the user to either select an existing material or add a new one. The chosen material properties are then used in the stress analysis calculations.

## How It Works 💡📅🔢

1. **Input Collection:** 📏🔍🔄  
   The program starts by prompting the user to select the cross-sectional type and to enter corresponding dimensions:
   - For a *rectangular section*, it asks for the base and height.
   - For a *circular section*, it asks for the radius.

   Additional inputs such as the length of the link, payload mass, and maximum angular acceleration are also requested.

2. **Material Selection:** 🔬💡📈  
   A list of materials is displayed with their corresponding yield strength and density values. The user selects the desired material or adds a new one, which is then used in subsequent calculations.

3. **Calculation and Optimization:** 🔢📈🔄  
   The program calculates:
   - The mass of the link based on the provided dimensions and material density.
   - The bending moment considering both the link's weight and the payload.
   - The moment of inertia depending on the cross-sectional shape.
   - The maximum stress exerted on the link.

   The `comparison` method is then used to iteratively adjust the dimensions (increasing or decreasing by a small percentage) until the calculated stress aligns with the material’s yield strength within a predefined tolerance.

4. **Output:** 📝🔄📊  
   The program prints the calculated data before and after the optimization process, showing the adjusted dimensions and mechanical properties.

## Build & Run Instructions 🚷🔧📂

### Prerequisites 📊📅🚷

- Code::Blocks IDE installed (with a working C++ compiler, e.g., `g++` bundled)

### Setting Up and Running the Project in Code::Blocks 📚🔨🔍

1. Open **Code::Blocks**.
2. Click **File** -> **New** -> **Project** -> **Console Application** -> **Follow the on-screen prompts** -> **Go**.
3. After the project is created, click on the **Project** tab.
4. Choose **Add files...** and add the following files:
   - `main.cpp`
   - `links.h`
   - `links.cpp`
   - `materials.h`
   - `materials.cpp`
5. After adding the files, click **Build** (gear icon) to compile the project.
6. Click **Run** (green play icon) to execute the program.
7. Follow the on-screen prompts to input your desired cross-sectional dimensions, link parameters, and select the appropriate material.

## Dependencies 🛠️🔄📊

- **Standard C++ Libraries:**  
  The project solely relies on standard C++ libraries and does not require external third-party dependencies.

## Contribution 📚💍🔗

Feel free to fork this repository and submit pull requests for improvements, new features, or bug fixes. Feedback and contributions are highly welcome as this project is part of an ongoing learning process. 📊🔄💌

## Acknowledgments 🎓👩‍🏫👨‍🏫

This project is developed as part of the *Introduction to Computer Programming* course in the Mechanical Engineering program. 💡 Special thanks to the course instructors and peers who contributed ideas and feedback during development. 📚🔄🚀
