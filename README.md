# TinyProject: Linear Regression in C++

**TinyProject** is a C++ implementation of linear regression to predict hardware performance using the [Computer Hardware dataset](https://archive.ics.uci.edu/ml/datasets/Computer+Hardware). This `README.md` describes the steps taken to complete the project.

---

## Table of Contents

- [TinyProject: Linear Regression in C++](#tinyproject-linear-regression-in-c)
  - [Table of Contents](#table-of-contents)
  - [Project Description](#project-description)
  - [Steps Taken to Complete the Project](#steps-taken-to-complete-the-project)
  - [Running the Project](#running-the-project)
---

## Project Description

TinyProject develops a C++ program to perform linear regression on the `machine.data` dataset, which includes hardware specifications and estimated relative performance (ERP) values. The program processes data, solves linear systems using object-oriented classes, and evaluates predictions with Root Mean Squared Error (RMSE).

---

## Steps Taken to Complete the Project

To complete **TinyProject**, the following actions were performed:

1. **Set Up Development Environment**:
   - Installed MSYS2 on Windows to provide a MinGW environment.
   - Installed `g++` and `mingw32-make` via:
     ```bash
     pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-make
     ```
   - Added `C:\msys64\ucrt64\bin` to the system Path for access to tools.

2. **Prepared Dataset**:
   - Downloaded `machine.data` from the UCI Machine Learning Repository.
   - Placed it in the `data/` folder.
   - Preprocessed data to extract features (e.g., CPU cycle time, memory size) and normalize values.

3. **Implemented Core Classes**:
   - Developed the `Matrix` class (`include/Matrix.hpp`, `src/Matrix.cpp`) for matrix operations like multiplication and transposition.
   - Created the `Vector` class (`include/Vector.hpp`, `src/Vector.cpp`) for vector operations, including dot product and scalar multiplication.
   - Built the `LinearSystem` class (`include/LinearSystem.hpp`, `src/LinearSystem.cpp`) as a base for solving linear systems.
   - Implemented the `PosSymLinSystem` class, extending `LinearSystem`, to solve positive symmetric systems with the conjugate gradient method.

4. **Developed Main Program**:
   - Wrote `src/main.cpp` to load `machine.data`, construct feature matrices and target vectors, and execute linear regression.
   - Used `PosSymLinSystem` to compute regression coefficients via the normal equation.

5. **Configured Build System**:
   - Created a `Makefile` to automate compilation with `mingw32-make`.
   - Linked source files to produce `program.exe`.

6. **Evaluated Performance**:
   - Executed the program with `mingw32-make run` to generate predictions.
   - Achieved an RMSE of **47.89**, reflecting accurate ERP predictions.

7. **Managed Version Control**:
   - Installed Git using `pacman -S git` in MSYS2.
   - Initialized a Git repository and pushed to [https://github.com/lqh2005/TinyProject](https://github.com/lqh2005/TinyProject).
   - Committed source code, `Makefile`, and this `README.md`.

---


## Running the Project

1. Navigate to project folder:
   ```bash
   cd /c/Users/hungl/OneDrive/Documents/TinyProject
   ```

2. Clean build:
   ```bash
   mingw32-make clean
   ```

3. Compile:
   ```bash
   mingw32-make
   ```

4. Run:
   ```bash
   mingw32-make run
   ```
   - Displays RMSE 

---
