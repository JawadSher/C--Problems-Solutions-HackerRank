<h1 align='center'>Operator - Overloading</h1>

## Problem Statement

**Problem URL :** [Operator Overloading](https://www.hackerrank.com/challenges/operator-overloading/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/62320d59-a5c4-431c-b7e7-926c54ee73b5)
![image](https://github.com/user-attachments/assets/56b1c1ae-4b44-46e3-a6df-9d4a2f45ebd8)

## Problem Solution
```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Fix the member variable references
#define a matrix

class Matrix {
public:
    vector<vector<int>> matrix;

    Matrix operator+(const Matrix& other) {
        Matrix result;

        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            vector<int> row;

            for (int j = 0; j < m; j++) {
                row.push_back(matrix[i][j] + other.matrix[i][j]);
            }
            result.matrix.push_back(row);
        }

        return result;
    }
};

int main() {
    int cases, k;
    cin >> cases;
    for (k = 0; k < cases; k++) {
        Matrix x;
        Matrix y;
        Matrix result;
        int n, m, i, j;
        cin >> n >> m;
        for (i = 0; i < n; i++) {
            vector<int> b;
            int num;
            for (j = 0; j < m; j++) {
                cin >> num;
                b.push_back(num);
            }
            x.a.push_back(b);  // Now 'a' refers to 'matrix'
        }
        for (i = 0; i < n; i++) {
            vector<int> b;
            int num;
            for (j = 0; j < m; j++) {
                cin >> num;
                b.push_back(num);
            }
            y.a.push_back(b);  // Now 'a' refers to 'matrix'
        }
        result = x + y;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cout << result.a[i][j] << " ";  // Now 'a' refers to 'matrix'
            }
            cout << endl;
        }
    }
    return 0;
}

```

## Problem Solution Explanation
Let's go through the code line by line and understand what each part does, including how the `#define` directive works and the overall flow of the program.

### Header Files
```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
```
- **#include <cmath>**: Includes the math library, providing functions like `sqrt()`, `sin()`, etc. This isn’t used in this code but is included as part of the template.
- **#include <cstdio>**: Includes the C standard input/output library.
- **#include <vector>**: Includes the vector library, which allows us to use the `std::vector` container.
- **#include <iostream>**: Includes the standard input/output stream library (`cin`, `cout`).
- **#include <algorithm>**: Includes the standard algorithms library, providing functions like `sort`, `max`, etc.
- **using namespace std;**: Brings all the standard library names (e.g., `std::vector`, `std::cout`) into the global namespace, so you don’t need to prefix them with `std::`.

### Preprocessor Directive
```cpp
#define a matrix
```
- This is a **macro** that replaces all instances of `a` with `matrix` in the code before compilation.
- It's used here to make the code simpler by allowing us to refer to `matrix` using a shorter alias `a`.

### Class Definition
```cpp
class Matrix {
public:
    vector<vector<int>> matrix;

    Matrix operator+(const Matrix& other) {
        Matrix result;

        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            vector<int> row;

            for (int j = 0; j < m; j++) {
                row.push_back(matrix[i][j] + other.matrix[i][j]);
            }
            result.matrix.push_back(row);
        }

        return result;
    }
};
```

#### Breaking Down the Class:
1. **Class Declaration:**
    - `class Matrix { ... };`: This defines a class named `Matrix`.
  
2. **Member Variables:**
    - `vector<vector<int>> matrix;`: This is a 2D vector that will hold the matrix data (a vector of vectors of integers).

3. **Operator Overloading:**
    - `Matrix operator+(const Matrix& other)`: This function overloads the `+` operator to allow adding two `Matrix` objects together.
    - `other`: A constant reference to another `Matrix` object that we are adding to the current object.

#### Inside the `operator+` Function:
1. **Matrix result;**:
    - A new `Matrix` object is created to hold the result of the addition.

2. **int n = matrix.size();**:
    - The number of rows in the matrix is stored in `n`.

3. **int m = matrix[0].size();**:
    - The number of columns in the matrix is stored in `m`.

4. **for (int i = 0; i < n; i++) { ... }**:
    - This loop iterates over each row of the matrix.

5. **vector<int> row;**:
    - A temporary vector `row` is created to hold the sum of each row's elements.

6. **for (int j = 0; j < m; j++) { ... }**:
    - This nested loop iterates over each column in the current row.

7. **row.push_back(matrix[i][j] + other.matrix[i][j]);**:
    - The corresponding elements of the two matrices are added together and stored in the `row` vector.

8. **result.matrix.push_back(row);**:
    - The completed `row` is added to the `result` matrix.

9. **return result;**:
    - The function returns the resulting `Matrix` object after adding the two matrices.

### Main Function
```cpp
int main() {
    int cases, k;
    cin >> cases;
    for (k = 0; k < cases; k++) {
        Matrix x;
        Matrix y;
        Matrix result;
        int n, m, i, j;
        cin >> n >> m;
        for (i = 0; i < n; i++) {
            vector<int> b;
            int num;
            for (j = 0; j < m; j++) {
                cin >> num;
                b.push_back(num);
            }
            x.a.push_back(b);  // Now 'a' refers to 'matrix'
        }
        for (i = 0; i < n; i++) {
            vector<int> b;
            int num;
            for (j = 0; j < m; j++) {
                cin >> num;
                b.push_back(num);
            }
            y.a.push_back(b);  // Now 'a' refers to 'matrix'
        }
        result = x + y;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cout << result.a[i][j] << " ";  // Now 'a' refers to 'matrix'
            }
            cout << endl;
        }
    }
    return 0;
}
```

#### Breaking Down the `main` Function:
1. **int cases, k; cin >> cases;**:
    - The number of test cases is read into `cases`.

2. **for (k = 0; k < cases; k++) { ... }**:
    - This loop iterates over each test case.

3. **Matrix x, y, result;**:
    - Three `Matrix` objects are declared: `x`, `y`, and `result`.
    - `x` and `y` will hold the matrices to be added, and `result` will hold the sum.

4. **int n, m, i, j; cin >> n >> m;**:
    - The number of rows `n` and columns `m` of the matrices are read.

5. **for (i = 0; i < n; i++) { ... }**:
    - This loop reads the elements of the first matrix, row by row.

6. **vector<int> b;**:
    - A temporary vector `b` is created to hold a row of the matrix.

7. **for (j = 0; j < m; j++) { ... }**:
    - This nested loop reads each element in the row.

8. **cin >> num; b.push_back(num);**:
    - Each element is read from the input and added to the `b` vector.

9. **x.a.push_back(b);**:
    - The completed row `b` is added to the `x` matrix.
    - `a` refers to `matrix` due to the `#define` directive.

10. **Repeat Steps 5-9**:
    - The process is repeated to read the elements of the second matrix `y`.

11. **result = x + y;**:
    - The two matrices are added using the overloaded `+` operator, and the result is stored in the `result` matrix.

12. **for (i = 0; i < n; i++) { ... }**:
    - This loop prints the elements of the `result` matrix.

13. **cout << result.a[i][j] << " ";**:
    - Each element of the `result` matrix is printed with a space in between.

14. **cout << endl;**:
    - A newline is printed at the end of each row.

15. **return 0;**:
    - The program returns 0, indicating successful execution.

### Summary:
- The program reads multiple test cases, each consisting of two matrices.
- It adds corresponding elements of the matrices and stores the result in a new matrix.
- The result is printed for each test case, row by row.
- The use of macros (`#define`) helps simplify code and improves readability.
