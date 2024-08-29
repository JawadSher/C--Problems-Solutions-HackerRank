<h1 align='center'>Cpp - Exception - Handling</h1>

## Problem Statement

**Problem URL :** [Cpp Exception Handling](https://www.hackerrank.com/challenges/cpp-exception-handling/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/9f91b1dd-ca91-473f-a8b6-752c7c07b2da)
![image](https://github.com/user-attachments/assets/20a77168-58a3-4ee4-95d1-7844aca10791)


## Problem Explanation
In the "Cpp Exception Handling" problem on HackerRank, you are typically required to demonstrate how to use exception handling in C++ to deal with potential errors during program execution. The goal is to handle specific exceptions gracefully and ensure that the program provides meaningful error messages when something goes wrong. 

## Problem Solution
```py
#include <iostream>
#include <stdexcept>

using namespace std;

int largest_proper_divisor(int n) {
    if (n == 0) {
        throw invalid_argument("largest proper divisor is not defined for n=0");
    }
    if (n == 1) {
        throw invalid_argument("largest proper divisor is not defined for n=1");
    }
    for (int i = n/2; i >= 1; --i) {
        if (n % i == 0) {
            return i;
        }
    }
    return -1; // will never happen
}

void process_input(int n) {
    try{
        
        int d = largest_proper_divisor(n);
        cout << "result=" << d << endl;
        cout<<"returning control flow to caller"<<endl;
    }catch (const invalid_argument& e){
        cout<<e.what()<<endl;
        cout<<"returning control flow to caller"<<endl;
    }catch(...){
        cout<<"largest proper divisor is not defined for n=0"<<endl;
        cout<<"returning control flow to caller"<<endl;
    }
}


int main() {
    int n;
    cin >> n;
    process_input(n);
    return 0;
}
```

## Problem Solution Explanation

The code aims to handle exceptions related to finding the largest proper divisor of a number. Here’s a line-by-line breakdown of the code:

```cpp
#include <iostream>
#include <stdexcept>
```

- **`#include <iostream>`**: Includes the input-output stream library necessary for using `cin`, `cout`, and other I/O operations.
- **`#include <stdexcept>`**: Includes the standard library for exception classes like `invalid_argument`.

```cpp
using namespace std;
```

- **`using namespace std;`**: Allows you to use standard library names (like `cout`, `cin`, `invalid_argument`) without the `std::` prefix.

```cpp
int largest_proper_divisor(int n) {
    if (n == 0) {
        throw invalid_argument("largest proper divisor is not defined for n=0");
    }
    if (n == 1) {
        throw invalid_argument("largest proper divisor is not defined for n=1");
    }
    for (int i = n/2; i >= 1; --i) {
        if (n % i == 0) {
            return i;
        }
    }
    return -1; // will never happen
}
```

**`largest_proper_divisor` Function:**

1. **`int largest_proper_divisor(int n)`**: Defines a function that returns the largest proper divisor of `n`.

2. **`if (n == 0)`**: Checks if `n` is `0`. Throws an `invalid_argument` exception if true because a proper divisor is not defined for `0`.

   - **`throw invalid_argument("largest proper divisor is not defined for n=0");`**: Throws an exception with a specific error message if `n` is `0`.

3. **`if (n == 1)`**: Checks if `n` is `1`. Throws an `invalid_argument` exception if true because `1` does not have a proper divisor.

   - **`throw invalid_argument("largest proper divisor is not defined for n=1");`**: Throws an exception with a specific error message if `n` is `1`.

4. **`for (int i = n/2; i >= 1; --i)`**: Loops from `n/2` down to `1` to find the largest proper divisor. 

   - **`if (n % i == 0)`**: Checks if `i` is a divisor of `n`. If true, it returns `i` as the largest proper divisor.

5. **`return -1;`**: This line should never be reached if `n > 1` and is included for completeness. 

   - **`return -1;`**: Returns `-1` if no proper divisor is found (though this case should not occur for valid `n`).

```cpp
void process_input(int n) {
    try {
        int d = largest_proper_divisor(n);
        cout << "result=" << d << endl;
        cout << "returning control flow to caller" << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
        cout << "returning control flow to caller" << endl;
    } catch (...) {
        cout << "largest proper divisor is not defined for n=0" << endl;
        cout << "returning control flow to caller" << endl;
    }
}
```

**`process_input` Function:**

1. **`void process_input(int n)`**: Defines a function to process the input number `n`.

2. **`try { ... }`**: Starts a `try` block where code that might throw exceptions is executed.

   - **`int d = largest_proper_divisor(n);`**: Calls `largest_proper_divisor` to find the largest proper divisor of `n`.

   - **`cout << "result=" << d << endl;`**: Prints the result.

   - **`cout << "returning control flow to caller" << endl;`**: Prints a message indicating that control flow is returning to the caller.

3. **`catch (const invalid_argument& e)`**: Catches `invalid_argument` exceptions.

   - **`cout << e.what() << endl;`**: Prints the error message from the exception.

   - **`cout << "returning control flow to caller" << endl;`**: Prints a message indicating that control flow is returning to the caller.

4. **`catch (...)`**: Catches any other exceptions that were not caught by previous `catch` blocks.

   - **`cout << "largest proper divisor is not defined for n=0" << endl;`**: Prints a default error message. 

   - **`cout << "returning control flow to caller" << endl;`**: Prints a message indicating that control flow is returning to the caller.

```cpp
int main() {
    int n;
    cin >> n;
    process_input(n);
    return 0;
}
```

**`main` Function:**

1. **`int main()`**: The entry point of the program.

2. **`int n;`**: Declares an integer `n`.

3. **`cin >> n;`**: Reads an integer input from the user.

4. **`process_input(n);`**: Calls `process_input` with the user-provided integer `n`.

5. **`return 0;`**: Returns `0` to indicate successful execution.

### Summary

The provided code effectively handles exceptions related to invalid inputs by throwing and catching exceptions. The `largest_proper_divisor` function throws exceptions for invalid inputs (0 and 1), and the `process_input` function catches and handles these exceptions, providing appropriate feedback to the user. This approach ensures that the program handles errors gracefully and provides informative messages when issues arise.
