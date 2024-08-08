<h1 align='center'>Say - Hello World - With - C++</h1>

## Problem Statement

**Problem URL :** [Say Hello World with C++](https://www.hackerrank.com/challenges/cpp-hello-world/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/4940f08a-7e64-4c8d-a279-a86600749066)

## Problem Solution
```cpp
#include<iostream>
using namespace std;
int main(){

    cout<<("Hello, World!");

    return 0;
}

```

## Problem Solution Explanation

Let's break down the C++ program line by line:

```cpp
#include<iostream>
```
- **`#include<iostream>`**: This line is a preprocessor directive. It tells the compiler to include the standard input-output stream library before compiling the program. This library allows you to use input and output features like `cout` for outputting text to the console.

```cpp
using namespace std;
```
- **`using namespace std;`**: This line tells the compiler to use the standard namespace. The standard namespace contains common C++ standard library features, including input and output objects like `cout` and `cin`. This line allows you to use these features without needing to prefix them with `std::`.

```cpp
int main() {
```
- **`int main()`**: This is the main function where the execution of the program begins. The `int` before `main` signifies that the function will return an integer value. By convention, returning `0` indicates that the program executed successfully.

```cpp
{
```
- **`{`**: This curly brace marks the beginning of the block of code that belongs to the `main` function.

```cpp
    cout << "Hello, World!";
```
- **`cout << "Hello, World!";`**: This line uses the `cout` object from the `iostream` library to print the string "Hello, World!" to the console. The `<<` operator is used to send the string to the output stream.

```cpp
    return 0;
```
- **`return 0;`**: This line ends the `main` function and returns `0` to the operating system. This return value indicates that the program has completed successfully.

```cpp
}
```
- **`}`**: This curly brace marks the end of the block of code for the `main` function.

In summary, this program includes the necessary library, sets up the standard namespace, defines the `main` function, prints "Hello, World!" to the console, and returns `0` to indicate successful execution.
