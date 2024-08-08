<h1 align='center'>Basic - Data - Types</h1>

## Problem Statement

**Problem URL :** [Basic Data Types](https://www.hackerrank.com/challenges/c-tutorial-basic-data-types/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/52bcdef7-b60c-43b3-9cfe-2d6052bc54c6)
![image](https://github.com/user-attachments/assets/1b1e2e57-7074-4780-88df-67d1ccb07863)
![image](https://github.com/user-attachments/assets/cc14d9ea-c18b-4da7-9027-c9b98eb5d524)




## Problem Solution
```cpp
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int main() {
    int a;
    long b;
    char c;
    float d;
    double e;
    
    cin >> a >> b >> c >> d >> e;
    
    cout << a << "\n";          
    cout << b << "\n";            
    cout << c << "\n";             
    
    cout << fixed << setprecision(3) << d << "\n";
    cout << fixed << setprecision(9) << e << "\n";
    
    return 0;
}

```

## Problem Solution Explanation
Here’s a line-by-line explanation of the provided C++ code for beginners:

```cpp
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
```
- **`#include <iostream>`**: This line includes the Input/Output stream library, which is necessary for using `cin` (input) and `cout` (output) in the program.
- **`#include <iomanip>`**: This line includes the Input/Output Manipulation library, which provides facilities for formatting output (like setting the precision of floating-point numbers).
- **`#include <cstdio>`**: This line includes the C-style I/O functions. It's not used in this code but is often included for completeness.
- **`using namespace std;`**: This allows you to use standard C++ library names like `cin`, `cout`, and `endl` without prefixing them with `std::`.

```cpp
int main() {
```
- **`int main()`**: This defines the main function where the execution of the program starts. The `int` signifies that the function will return an integer value to the operating system upon completion.

```cpp
    int a;
    long b;
    char c;
    float d;
    double e;
```
- **`int a;`**: Declares a variable `a` of type `int` (integer) to store integer values.
- **`long b;`**: Declares a variable `b` of type `long` to store larger integer values.
- **`char c;`**: Declares a variable `c` of type `char` to store a single character.
- **`float d;`**: Declares a variable `d` of type `float` to store a floating-point number with single precision.
- **`double e;`**: Declares a variable `e` of type `double` to store a floating-point number with double precision.

```cpp
    cin >> a >> b >> c >> d >> e;
```
- **`cin >> a >> b >> c >> d >> e;`**: Reads input values from the user and stores them in the respective variables (`a`, `b`, `c`, `d`, `e`). The `cin` object is used to handle input.

```cpp
    cout << a << "\n";
```
- **`cout << a << "\n";`**: Outputs the value of `a` to the console, followed by a newline character (`\n`) to move to the next line.

```cpp
    cout << b << "\n";
```
- **`cout << b << "\n";`**: Outputs the value of `b` to the console, followed by a newline character.

```cpp
    cout << c << "\n";
```
- **`cout << c << "\n";`**: Outputs the value of `c` (a character) to the console, followed by a newline character.

```cpp
    cout << fixed << setprecision(3) << d << "\n";
```
- **`cout << fixed << setprecision(3) << d << "\n";`**: Outputs the value of `d` (a float) to the console with exactly 3 decimal places. The `fixed` manipulator ensures that the number is printed in fixed-point notation, and `setprecision(3)` sets the precision to 3 decimal places.

```cpp
    cout << fixed << setprecision(9) << e << "\n";
```
- **`cout << fixed << setprecision(9) << e << "\n";`**: Outputs the value of `e` (a double) to the console with exactly 9 decimal places. Similar to the previous line, `fixed` ensures fixed-point notation and `setprecision(9)` sets the precision to 9 decimal places.

```cpp
    return 0;
```
- **`return 0;`**: Ends the `main` function and returns `0` to the operating system. This indicates that the program executed successfully.

```cpp
}
```
- **`}`**: Closes the block of code for the `main` function.

### Summary:
This program reads an integer, a long integer, a character, a float, and a double from the user. It then prints each value, formatting the float and double with specified precision for better readability.
