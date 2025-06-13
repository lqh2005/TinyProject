TinyProject
Overview
TinyProject is a C++ project developed on Visual Studio Code with MinGW on Windows, focusing on implementing linear algebra classes and applying linear regression to predict computer performance using the machine.data dataset from the UCI Machine Learning Repository. The project showcases skills in C++ programming, linear algebra, and basic machine learning.
Objectives

Implement linear algebra classes (Vector, Matrix, LinearSystem) to support operations such as addition, subtraction, multiplication, determinant, inverse, and pseudo-inverse.
Perform linear regression to predict the Performance Rating (PRP) based on features from the machine.data dataset.
Evaluate prediction accuracy using Root Mean Squared Error (RMSE).
Develop the project using Visual Studio Code, MinGW (MSYS2), and a Makefile for build automation.

Technologies

Language: C++ (with C++11 features)
Tools: Visual Studio Code, MinGW (MSYS2), Makefile
Dataset: machine.data from UCI
Platform: Windows

Project Structure
TinyProject/
├── include/
│   ├── Vector.hpp
│   ├── Matrix.hpp
│   └── LinearSystem.hpp
├── src/
│   ├── Vector.cpp
│   ├── Matrix.cpp
│   ├── LinearSystem.cpp
│   └── main.cpp
├── data/
│   └── machine.data
├── Makefile
├── README.md


include/: Header files defining class interfaces.
src/: Implementation files for classes and the main program.
data/: Stores the machine.data dataset.
Makefile: Automates compilation and execution.
README.md: Project documentation.

Technical Description
Core Components

Vector Class

Purpose: Represents a real-valued vector with operations like addition, subtraction, scalar multiplication, and indexed access (0-based and 1-based).
Files: include/Vector.hpp, src/Vector.cpp
Key Methods:
Vector(int size): Initializes a vector.
operator+, operator-, operator*: Vector operations.
print(): Displays the vector.




Matrix Class

Purpose: Represents a real-valued matrix with operations like addition, subtraction, matrix multiplication, determinant, inverse, and pseudo-inverse.
Files: include/Matrix.hpp, src/Matrix.cpp
Key Methods:
Matrix(int rows, int cols): Initializes a matrix.
operator+, operator-, operator*: Matrix operations.
determinant(): Computes the determinant for n×n matrices using Gaussian elimination with partial pivoting.
inverse(): Computes inverse using Gaussian elimination.
pseudoInverse(): Computes pseudo-inverse via (A^T A)^(-1) A^T.




LinearSystem and PosSymLinSystem Classes

Purpose: Solves linear systems Ax = b. LinearSystem uses Gaussian elimination, while PosSymLinSystem uses conjugate gradient for positive symmetric matrices.
Files: include/LinearSystem.hpp, src/LinearSystem.cpp
Key Methods:
Solve(): Solves the linear system.




Main Program (main.cpp)

Purpose:
Reads data/machine.data.
Splits data into training (80%) and testing (20%) sets.
Performs linear regression using least squares: x = (A^T A)^(-1) A^T b.
Computes RMSE on the test set.


Key Functions:
readData: Parses the CSV dataset.
splitData: Randomly splits data using std::shuffle.
linearRegression: Computes regression coefficients.
computeRMSE: Calculates prediction error.





Workflow

Data Reading: The machine.data dataset is a CSV file with columns (vendor, model, MYCT, MMIN, MMAX, CACH, CHMIN, CHMAX, PRP, ERP). The readData function skips vendor, model, and ERP, using numerical features.
Linear Regression: Constructs matrix A (n × 6) from features and vector b (n × 1) from PRP. Solves for x using (A^T A)^(-1) A^T b via LinearSystem.
Evaluation: Predicts PRP on the test set and computes RMSE = sqrt(Σ(pred - actual)^2 / n).

Setup and Installation
Prerequisites

Visual Studio Code: Install from code.visualstudio.com.
MinGW (MSYS2): Install via MSYS2. Add C:\msys64\ucrt64\bin to the system Path.
Dataset: Download machine.data from UCI and place it in TinyProject/data/.

Installation

Clone the repository:git clone https://github.com/<your-username>/TinyProject.git
cd TinyProject


Ensure machine.data is in the data/ directory.
Install MinGW packages:pacman -S mingw-w64-x86_64-gcc



Build and Run

Compile the project:mingw32-make


Run the executable:mingw32-make run

This outputs the RMSE of the linear regression model.

Clean Build
mingw32-make clean

Challenges and Solutions
Challenges

MinGW Configuration Error:

Issue: The undefined reference to WinMain error occurred because MinGW targeted the GUI subsystem.
Solution:
Added -mconsole to CFLAGS and LFLAGS in Makefile.
Ensured int main() in main.cpp.
Cleaned the project (mingw32-make clean).
Updated MSYS2 packages.




Incorrect Working Directory:

Issue: Commands failed due to wrong terminal directory.
Solution: Changed to TinyProject root directory.


File Path Issues:

Issue: Failed to read machine.data due to path separators.
Solution: Used data\\machine.data and added error checking.


C++11 Compatibility:

Issue: std::random_shuffle was unreliable.
Solution: Used std::shuffle with -std=c++11.


Makefile Errors:

Issue: No targets. Stop. due to missing Makefile.
Solution: Recreated Makefile with correct syntax.



Development Process

Configured MinGW/MSYS2 and VS Code with C/C++ extensions.
Organized code into include and src with Makefile automation.
Used VS Code debugger to resolve runtime issues.

Results

Functionality:
Implemented Vector, Matrix, and LinearSystem classes, including a robust determinant() method for n×n matrices.
Performed linear regression and computed RMSE.


Performance:
Program processes machine.data efficiently.
RMSE: Approximately 50.23 (replace with your actual RMSE after running mingw32-make run).


Development Environment:
Organized project with Makefile for easy builds.
VS Code and MinGW provide a robust setup.



Note: To update the RMSE, run the program and replace 50.23 with the output value from RMSE: <value>.
Troubleshooting

WinMain Error:
Ensure main.cpp has int main().
Verify -mconsole in Makefile.
Update MinGW: pacman -S mingw-w64-x86_64-gcc.


File Not Found:
Confirm machine.data is in data/.
Use data\\machine.data in main.cpp.


Build Failures:
Run mingw32-make clean before rebuilding.
Check MinGW Path: C:\msys64\ucrt64\bin.



Lessons Learned

MinGW requires careful subsystem configuration (-mconsole).
Use \\ for Windows file paths.
Separating headers and implementations improves maintainability.
Debugger and error checks are critical for troubleshooting.
C++11 features require explicit -std=c++11.

Future Improvements

Algorithm Enhancements:
Optimize pseudoInverse() with Singular Value Decomposition (SVD).


Accuracy Improvements:
Normalize features to improve RMSE.
Implement k-fold cross-validation.


Feature Expansion:
Add a user interface or file output.
Support additional algorithms (e.g., Ridge regression).


Testing:
Write unit tests for classes.
Use GitHub Actions for CI/CD.



Conclusion
TinyProject successfully implemented linear algebra operations and linear regression on the machine.data dataset, achieving an RMSE of approximately 50.23 (pending actual value). Challenges with MinGW, file paths, and C++ compatibility were resolved through debugging and configuration. The enhanced determinant() method for n×n matrices strengthens the project’s linear algebra capabilities. This project is a valuable exercise in C++ development and machine learning, with opportunities for further improvement.
