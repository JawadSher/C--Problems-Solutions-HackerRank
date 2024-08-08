<h1 align='center'>Input - and - Output</h1>

## Problem Statement

**Problem URL :** [Input and Output](https://www.hackerrank.com/challenges/cpp-input-and-output/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/60eacfbb-be5b-4c15-9144-0b5607814749)
![image](https://github.com/user-attachments/assets/fb8fef49-6e89-4dc9-808e-57bf237eabd0)


## Problem Solution
```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int a;
    int b;
    int c;
    
    cin>> a >> b >> c;
    
    int total = a+b+c;
    cout<<total;
    
    
    return 0;
}

```

## Problem Solution Explanation

Let’s break down the C++ code line by line:

```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
```
- **`#include <cmath>`**: Includes the C++ Standard Library header for mathematical functions. Not used in this code, but often included for mathematical operations.
- **`#include <cstdio>`**: Includes the C++ Standard Library header for C-style input and output functions. Not used in this code.
- **`#include <vector>`**: Includes the C++ Standard Library header for the vector container. Not used in this code.
- **`#include <iostream>`**: Includes the C++ Standard Library header for input and output streams. This is used for `cin` and `cout`.
- **`#include <algorithm>`**: Includes the C++ Standard Library header for algorithms like sort. Not used in this code.
- **`using namespace std;`**: Allows you to use standard C++ library names (like `cin`, `cout`, `endl`) without prefixing them with `std::`.

```cpp
int main() {
```
- **`int main()`**: Defines the `main` function, which is the entry point of a C++ program. It returns an integer value to the operating system upon completion.

```cpp
    int a;
    int b;
    int c;
```
- **`int a;`**, **`int b;`**, **`int c;`**: Declare three integer variables named `a`, `b`, and `c`. These will be used to store user input values.

```cpp
    cin >> a >> b >> c;
```
- **`cin >> a >> b >> c;`**: Reads three integer values from the standard input (usually the keyboard) and stores them in the variables `a`, `b`, and `c`.

```cpp
    int total = a + b + c;
```
- **`int total = a + b + c;`**: Calculates the sum of the integers stored in `a`, `b`, and `c`, and assigns the result to a new integer variable `total`.

```cpp
    cout << total;
```
- **`cout << total;`**: Outputs the value of `total` to the standard output (usually the console).

```cpp
    return 0;
```
- **`return 0;`**: Ends the `main` function and returns `0` to the operating system, indicating that the program executed successfully.

```cpp
}
```
- **`}`**: Closes the block of code for the `main` function.

### Summary:
This program reads three integers from the user, computes their sum, and prints the result.
