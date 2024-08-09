<h1 align='center'>Pointer</h1>

## Problem Statement

**Problem URL :** [Pointer](https://www.hackerrank.com/challenges/c-tutorial-pointer/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/d7dae0de-1980-48cf-8c00-c0a897c28cb8)
![image](https://github.com/user-attachments/assets/522bf144-eb2b-4224-9fa1-ced9e374ec1c)


## Problem Solution
```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
void  update(int *a , int *b){
    
    int q = *a;
    int w = *b;
    cout<<(q + w)<<endl;
    cout<<abs(q-w)<<endl;
}

int main() {
    
    int z , x;
    cin>>z>>x;
    update(&x,&z);     
  
    return 0;
}
```

## Problem Solution Explanation
Let’s go through this C++ code line by line, explaining each part in detail.

### Code

```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
```

#### Header Inclusions and Namespace
- **`#include <cmath>`**:
  - This header file includes mathematical functions and constants. In this code, it's used for the `abs` function, which computes the absolute value of an integer.

- **`#include <cstdio>`**:
  - This header file provides functionalities for C-style input and output. It’s not used in this code but often included for general purposes.

- **`#include <vector>`**:
  - This header provides support for the `std::vector` container, which is not used in this particular code.

- **`#include <iostream>`**:
  - This header file includes standard input and output stream objects, such as `cin` and `cout`.

- **`#include <algorithm>`**:
  - This header provides functions for algorithmic operations such as sorting, searching, etc. It's not used in this code.

- **`using namespace std;`**:
  - This line allows the use of standard library objects and functions without prefixing them with `std::`. For example, you can use `cin` and `cout` instead of `std::cin` and `std::cout`.

---

```cpp
void update(int *a, int *b) {
```

#### Function Definition
- **`void update(int *a, int *b)`**:
  - **`void`**: Specifies that the function does not return any value.
  - **`update`**: The name of the function.
  - **`int *a, int *b`**: The function takes two pointers to integers as parameters. These pointers will point to the integers whose values will be manipulated inside the function.

---

```cpp
    int q = *a;
    int w = *b;
```

#### Dereferencing and Variable Initialization
- **`int q = *a;`**:
  - **`*a`**: Dereferences the pointer `a`, accessing the value of the integer it points to. This value is assigned to the variable `q`.
- **`int w = *b;`**:
  - **`*b`**: Dereferences the pointer `b`, accessing the value of the integer it points to. This value is assigned to the variable `w`.

---

```cpp
    cout << (q + w) << endl;
    cout << abs(q - w) << endl;
```

#### Output Statements
- **`cout << (q + w) << endl;`**:
  - Computes the sum of `q` and `w` and prints it to the console, followed by a newline character (`endl`).

- **`cout << abs(q - w) << endl;`**:
  - Computes the absolute difference between `q` and `w` using the `abs` function and prints it to the console, followed by a newline character (`endl`).

---

```cpp
int main() {
```

#### Main Function
- **`int main()`**:
  - The entry point of the program. Execution starts here.

---

```cpp
    int z, x;
    cin >> z >> x;
```

#### Input Statements
- **`int z, x;`**:
  - Declares two integer variables, `z` and `x`.

- **`cin >> z >> x;`**:
  - Reads two integer values from the standard input and stores them in `z` and `x`, respectively.

---

```cpp
    update(&x, &z);
```

#### Function Call
- **`update(&x, &z);`**:
  - Calls the `update` function, passing the addresses of `x` and `z` as arguments. The `&` operator is used to get the address of a variable (i.e., pointer to the variable).

---

```cpp
    return 0;
}
```

#### Return Statement
- **`return 0;`**:
  - Returns 0 to the operating system, indicating that the program has executed successfully.

---

### Summary
1. **Header Files**: Includes libraries for mathematical operations, input/output, vectors, and algorithms, even though only a few are used.
2. **Function `update`**: Takes two integer pointers, dereferences them to access the values, computes their sum and absolute difference, and prints these values.
3. **`main` Function**:
   - Reads two integers from the user.
   - Calls the `update` function with the addresses of these integers.
   - The `update` function prints the sum and absolute difference of the two integers.

The purpose of the `update` function is to perform calculations on the values of the integers pointed to by its parameters and display the results.
