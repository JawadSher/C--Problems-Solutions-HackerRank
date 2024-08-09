<h1 align='center'>Functions</h1>

## Problem Statement

**Problem URL :** [Functions](https://www.hackerrank.com/challenges/c-tutorial-functions/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/37c88472-cc31-4103-ad26-2738c9ece969)
![image](https://github.com/user-attachments/assets/026e8747-c478-4831-a3e1-24ac786b9341)



## Problem Solution 
```cpp
#include<iostream>
using namespace std;

int four_nums(int a, int b, int c, int d){
    if (a > b && a > c && a > d ) {
        return a;
    }
    else if(b > c && b > a && b > d){
        return b;
    }
    else if(c > d && c > a && c > b){
        return c;
    }
    else if(d > a && d > b && d > c){
        return d;
    } 
    else {
        return a;
    }
}

int main(){
    int h1,h2,h3,h4;
    cin>> h1>> h2>> h3>> h4;
    cout<<four_nums(h1,h2,h3,h4);
    return 0;
}

```

## Problem Solution Explanation

Let's go through the code line by line and explain each part in detail.

### Code

```cpp
#include<iostream>
using namespace std;
```

#### Header and Namespace
- **`#include<iostream>`**:
  - This preprocessor directive tells the compiler to include the `iostream` library in the program. This library provides facilities for input and output operations, such as `cin` for input and `cout` for output.

- **`using namespace std;`**:
  - This line allows you to use names from the C++ Standard Library without the need to prefix them with `std::`. For example, `cin` and `cout` are used directly instead of `std::cin` and `std::cout`.

---

```cpp
int four_nums(int a, int b, int c, int d) {
```

#### Function Declaration
- **`int four_nums(int a, int b, int c, int d)`**:
  - **`int`**: Specifies that the function will return an integer value.
  - **`four_nums`**: The name of the function.
  - **`(int a, int b, int c, int d)`**: The function takes four integer parameters named `a`, `b`, `c`, and `d`. These parameters represent the four numbers among which we need to find the maximum.

---

```cpp
    if (a > b && a > c && a > d) {
        return a;
    }
```

#### First Condition
- **`if (a > b && a > c && a > d)`**:
  - This `if` statement checks if `a` is greater than all the other three numbers (`b`, `c`, and `d`).
  - **`a > b`**: Checks if `a` is greater than `b`.
  - **`a > c`**: Checks if `a` is greater than `c`.
  - **`a > d`**: Checks if `a` is greater than `d`.
  - **`&&`**: Logical AND operator. All conditions must be true for the whole condition to be true.
- **`return a;`**:
  - If the condition is true, this statement returns the value of `a`, which is the largest of the four numbers checked so far.

---

```cpp
    else if (b > c && b > a && b > d) {
        return b;
    }
```

#### Second Condition
- **`else if (b > c && b > a && b > d)`**:
  - If `a` is not the largest, this `else if` statement checks if `b` is greater than the other three numbers (`c`, `a`, and `d`).
  - **`b > c`**: Checks if `b` is greater than `c`.
  - **`b > a`**: Checks if `b` is greater than `a`.
  - **`b > d`**: Checks if `b` is greater than `d`.
- **`return b;`**:
  - If the condition is true, this statement returns the value of `b`, which is the largest of the four numbers checked so far.

---

```cpp
    else if (c > d && c > a && c > b) {
        return c;
    }
```

#### Third Condition
- **`else if (c > d && c > a && c > b)`**:
  - If neither `a` nor `b` is the largest, this `else if` statement checks if `c` is greater than the other three numbers (`d`, `a`, and `b`).
  - **`c > d`**: Checks if `c` is greater than `d`.
  - **`c > a`**: Checks if `c` is greater than `a`.
  - **`c > b`**: Checks if `c` is greater than `b`.
- **`return c;`**:
  - If the condition is true, this statement returns the value of `c`, which is the largest of the four numbers checked so far.

---

```cpp
    else if (d > a && d > b && d > c) {
        return d;
    }
```

#### Fourth Condition
- **`else if (d > a && d > b && d > c)`**:
  - If none of the previous conditions were true, this `else if` statement checks if `d` is greater than the other three numbers (`a`, `b`, and `c`).
  - **`d > a`**: Checks if `d` is greater than `a`.
  - **`d > b`**: Checks if `d` is greater than `b`.
  - **`d > c`**: Checks if `d` is greater than `c`.
- **`return d;`**:
  - If the condition is true, this statement returns the value of `d`, which is the largest of the four numbers checked so far.

---

```cpp
    else {
        return a;
    }
```

#### Fallback Case
- **`else`**:
  - This part is executed if none of the previous conditions (`if` and `else if`) are true. In theory, this should never happen because one of the previous conditions must be true if there are four distinct numbers.
- **`return a;`**:
  - Returns `a` as a fallback. This might handle cases where multiple numbers are equal, but in a correct implementation for distinct numbers, it ensures that the function always returns a value.

---

```cpp
int main() {
    int h1, h2, h3, h4;
    cin >> h1 >> h2 >> h3 >> h4;
    cout << four_nums(h1, h2, h3, h4);
    return 0;
}
```

#### Main Function
- **`int main()`**:
  - The entry point of the program where execution begins. It returns an integer value to the operating system upon completion.

- **`int h1, h2, h3, h4;`**:
  - Declares four integer variables to store the user input.

- **`cin >> h1 >> h2 >> h3 >> h4;`**:
  - Reads four integer values from the standard input and stores them in `h1`, `h2`, `h3`, and `h4`.

- **`cout << four_nums(h1, h2, h3, h4);`**:
  - Calls the `four_nums` function with `h1`, `h2`, `h3`, and `h4` as arguments.
  - Prints the result returned by `four_nums` (which is the maximum value among the four integers).

- **`return 0;`**:
  - Indicates successful execution of the program by returning 0 to the operating system.

### Summary
- The function `four_nums` takes four integers and returns the maximum among them.
- The `main` function handles user input and calls `four_nums` to display the maximum value.
- The program correctly identifies and prints the largest of four numbers entered by the user.
