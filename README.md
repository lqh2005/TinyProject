TinyProject

A C++ project implementing linear algebra operations and linear regression to predict computer performance using the UCI machine.data dataset. Developed with Visual Studio Code and MinGW on Windows, this project showcases skills in C++ programming, matrix computations, and machine learning.



Table of Contents





Project Overview



Features



Project Structure



Setup and Installation



Usage



Results



Troubleshooting



Lessons Learned



Future Improvements



Contributing



License



Project Overview

TinyProject focuses on building a robust C++ application to:





Implement linear algebra classes (Vector, Matrix, LinearSystem) for operations like matrix multiplication, determinant, and inverse.



Apply linear regression to predict the Performance Rating (PRP) of computers using the machine.data dataset.



Evaluate model accuracy with Root Mean Squared Error (RMSE).

Objectives





Develop efficient linear algebra classes for vector and matrix operations.



Perform linear regression using least squares method: x = (A^T A)^(-1) A^T b.



Achieve accurate predictions with a low RMSE.



Automate builds using a Makefile on Windows with MinGW.

Technologies





Language: C++ (C++11)



Tools: Visual Studio Code, MinGW (MSYS2), Makefile



Dataset: machine.data



Platform: Windows



Features





Linear Algebra Classes:





Vector: Supports addition, subtraction, scalar multiplication, and indexed access.



Matrix: Includes matrix operations, determinant (n×n via Gaussian elimination), inverse, and pseudo-inverse.



LinearSystem: Solves Ax = b using Gaussian elimination or conjugate gradient.



Linear Regression:





Processes machine.data to predict PRP based on features (MYCT, MMIN, MMAX, CACH, CHMIN, CHMAX).



Computes RMSE for model evaluation.



Build Automation:





Makefile for compilation and execution.



Project Structure

TinyProject/
├── include/                # Header files
│   ├── Vector.hpp
│   ├── Matrix.hpp
│   └── LinearSystem.hpp
├── src/                    # Source files
│   ├── Vector.cpp
│   ├── Matrix.cpp
│   ├── LinearSystem.cpp
│   └── main.cpp
├── data/                   # Dataset
│   └── machine.data
├── Makefile                # Build automation
└── README.md               # Project documentation







Directory/File



Description





include/



Class definitions for Vector, Matrix, etc.





src/



Implementations and main program.





data/



UCI machine.data dataset.





Makefile



Automates compilation and execution.





README.md



Project overview and instructions.



Setup and Installation

Prerequisites





Visual Studio Code: Download from code.visualstudio.com.



MinGW (MSYS2): Install from msys2.org. Add C:\msys64\ucrt64\bin to system Path.



Dataset: Download machine.data from UCI and place in data/.

Installation Steps





Clone the repository:

git clone https://github.com/lqh2005/TinyProject.git
cd TinyProject



Ensure machine.data is in data/.



Install MinGW packages:

pacman -S mingw-w64-x86_64-gcc



Usage





Compile the project:

mingw32-make



Run the program:

mingw32-make run





Output: Displays the RMSE of the linear regression model.



Clean build artifacts:

mingw32-make clean

Example Output

RMSE: 45.67

Note: Replace 45.67 with the actual RMSE after running the program.



Results





Functionality:





Successfully implemented Vector, Matrix, and LinearSystem classes.



Linear regression predicts PRP with reasonable accuracy.



Matrix::determinant() computes determinants for n×n matrices using Gaussian elimination with partial pivoting.



Performance:





RMSE: 45.67 (update with actual value after running mingw32-make run).



Efficient processing of machine.data on Windows with MinGW.



Build System:





Makefile ensures reliable compilation and execution.

Update RMSE:





Run mingw32-make run to get the RMSE.



Edit README.md, replace 45.67 with the actual value.



Commit and push:

git add README.md
git commit -m "Update RMSE"
git push origin main



Troubleshooting

Common Issues





Error: undefined reference to WinMain:





Cause: MinGW targets GUI subsystem instead of console.



Solution:





Ensure main.cpp has int main().



Verify Makefile includes -mconsole in CFLAGS and LFLAGS.



Run mingw32-make clean and rebuild.



Update MinGW: pacman -S mingw-w64-x86_64-gcc.



Error: src refspec master does not match any:





Cause: Attempting to push to master when branch is main.



Solution:





Check branch: git branch (likely main).



Push to main: git push origin main.



Create master if needed: git push origin main:master.



File Not Found (machine.data):





Solution:





Place machine.data in data/.



Use data\\machine.data in main.cpp for Windows.



Build Failures:





Solution:





Verify MinGW Path: C:\msys64\ucrt64\bin.



Check Makefile syntax (use tabs, not spaces).



Lessons Learned





MinGW Configuration: Use -mconsole for console applications.



File Paths: Use \\ for Windows compatibility.



Git Management: Default branch is often main, not master.



Debugging: VS Code debugger and error checks (e.g., file opening) are essential.



C++11: Enable with -std=c++11 for modern features like std::shuffle.



Future Improvements





Algorithms:





Optimize pseudoInverse() with Singular Value Decomposition (SVD).



Enhance determinant() with LU decomposition for efficiency.



Accuracy:





Normalize features to reduce RMSE.



Implement k-fold cross-validation.



Features:





Add a GUI or file output for results.



Support additional machine learning models.



Testing:





Write unit tests for classes.



Integrate GitHub Actions for CI/CD.



Contributing

Contributions are welcome! To contribute:





Fork the repository.



Create a feature branch: git checkout -b feature-name.



Commit changes: git commit -m "Add feature".



Push to branch: git push origin feature-name.



Open a Pull Request.



License

This project is licensed under the MIT License. See LICENSE for details.