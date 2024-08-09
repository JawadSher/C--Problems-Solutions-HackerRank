<h1 align='center'>Conditional - Statements</h1>

## Problem Statement

![image](https://github.com/user-attachments/assets/18e2c513-e2eb-4d6c-899d-0298f3ee1c79)
![image](https://github.com/user-attachments/assets/47c56aed-a729-4038-bdba-eb36dfca2bc9)
![image](https://github.com/user-attachments/assets/40f0da00-d557-4c29-8f6c-39130012c221)
![image](https://github.com/user-attachments/assets/102695a7-3694-4630-ad54-3a256cbc60d3)


## Problem Solution
```cpp
#include<iostream>
using namespace std;
int main(){
    
    int n;
    cin>>n;
    
    if (n<=9) {
        
        switch (n) {
            case 1:
                cout<<"one";
                break;
            case 2:
                cout<<"two";
                 break;
            case 3:
                cout<<"three";
                 break;
            case 4:
                cout<<"four";
                 break;
            case 5:
                cout<<"five";
                 break;
            case 6:
                cout<<"six";
                 break;
            case 7:
                cout<<"seven";
                 break;
            case 8:
                cout<<"eight";
                 break;
            case 9:
                cout<<"nine";
                 break;
        }
    }
    else {
        cout<<"Greater than 9";
    }
   
    return 0;
}
```

## Problem Solution Explanation

This C++ code reads an integer from the user and prints its English word representation if the number is between 1 and 9 (inclusive). If the number is greater than 9, it prints "Greater than 9". Here's a detailed explanation of each part of the code:

```cpp
#include<iostream>
using namespace std;
```
- **`#include<iostream>`**: This preprocessor directive includes the standard input-output stream library, which is used for input and output operations (e.g., `cin` for input and `cout` for output).
- **`using namespace std;`**: This line allows you to use standard library functions and objects (like `cin`, `cout`, etc.) without needing to prefix them with `std::`.

```cpp
int main(){
```
- **`int main()`**: This is the main function where the execution of the program begins. It returns an integer value to the operating system upon completion.

```cpp
    int n;
    cin >> n;
```
- **`int n;`**: Declares an integer variable `n` to store the user's input.
- **`cin >> n;`**: Reads an integer value from the standard input (keyboard) and stores it in variable `n`.

```cpp
    if (n <= 9) {
```
- **`if (n <= 9)`**: Checks if the value of `n` is less than or equal to 9.

```cpp
        switch (n) {
```
- **`switch (n)`**: Starts a switch statement to execute different blocks of code based on the value of `n`.

```cpp
            case 1:
                cout << "one";
                break;
            case 2:
                cout << "two";
                break;
            case 3:
                cout << "three";
                break;
            case 4:
                cout << "four";
                break;
            case 5:
                cout << "five";
                break;
            case 6:
                cout << "six";
                break;
            case 7:
                cout << "seven";
                break;
            case 8:
                cout << "eight";
                break;
            case 9:
                cout << "nine";
                break;
```
- **`case 1:`** through **`case 9:`**: These are different cases in the switch statement. Each case corresponds to a specific value of `n` (from 1 to 9). For each case, it prints the English word for the number.
- **`break;`**: Ends the current case block. Without `break`, the program would continue to execute the subsequent cases until it finds a `break` or the end of the switch statement.

```cpp
    }
    else {
        cout << "Greater than 9";
    }
```
- **`else`**: If `n` is not less than or equal to 9 (i.e., `n` is greater than 9), this block of code is executed.
- **`cout << "Greater than 9";`**: Prints "Greater than 9" to indicate that the number is outside the range of 1 to 9.

```cpp
    return 0;
}
```
- **`return 0;`**: Returns 0 to the operating system to indicate that the program executed successfully.

### Summary
- The program reads an integer `n` from the user.
- If `n` is between 1 and 9, it prints the corresponding English word for that number using a switch statement.
- If `n` is greater than 9, it prints "Greater than 9".
- The program uses basic control flow constructs like `if` and `switch` to handle the different conditions.
