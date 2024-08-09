<h1 align='center'>For - Loop</h1>

## Problem Statement
![image](https://github.com/user-attachments/assets/5f63bf7e-92bb-4a70-b671-ebe65c2f5b62)
![image](https://github.com/user-attachments/assets/555560f8-04a4-4551-b369-63f2b1efd6fb)


## Problem Solution
```cpp
#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a;
    cin>>b;
    for (int i=a; i <=b; i++)
    {
        if (i==1)
        cout<<"one"<<endl;
        else if(i==2)
        cout<<"two"<<endl;
        else if(i==3)
        cout<<"three"<<endl;
        else if(i==4)
        cout<<"four"<<endl;
        else if(i==5)
        cout<<"five"<<endl;
        else if(i==6)
        cout<<"six"<<endl;
        else if(i==7)
        cout<<"seven"<<endl;
        else if(i==8)
        cout<<"eight"<<endl;
        else if(i==9)
        cout<<"nine"<<endl;
        
        else if (i>9){
        if(i%2==0)
        cout<<"even"<<endl;
        else 
        cout<<"odd"<<endl;
        }
    }

    return 0;
}
```

## Problem Solution Explanation
This C++ code reads two integers from the user, `a` and `b`, and prints the English word for numbers between `a` and `b` (inclusive) if they are between 1 and 9. For numbers greater than 9, it prints whether the number is "even" or "odd". Here's a detailed breakdown of the code:

```cpp
#include<iostream>
using namespace std;
```
- **`#include<iostream>`**: Includes the standard input-output stream library for handling input and output operations.
- **`using namespace std;`**: Allows you to use names from the standard library (e.g., `cin`, `cout`) without prefixing them with `std::`.

```cpp
int main(){
```
- **`int main()`**: The main function where the execution of the program starts. It returns an integer value to the operating system upon completion.

```cpp
    int a, b;
    cin >> a;
    cin >> b;
```
- **`int a, b;`**: Declares two integer variables `a` and `b` to store the user's input.
- **`cin >> a;`** and **`cin >> b;`**: Reads two integer values from the standard input and stores them in `a` and `b`, respectively.

```cpp
    for (int i = a; i <= b; i++)
    {
```
- **`for (int i = a; i <= b; i++)`**: Starts a `for` loop that initializes `i` to `a` and increments it by 1 each iteration until it reaches `b` (inclusive). This loop will iterate through every integer from `a` to `b`.

```cpp
        if (i == 1)
            cout << "one" << endl;
        else if (i == 2)
            cout << "two" << endl;
        else if (i == 3)
            cout << "three" << endl;
        else if (i == 4)
            cout << "four" << endl;
        else if (i == 5)
            cout << "five" << endl;
        else if (i == 6)
            cout << "six" << endl;
        else if (i == 7)
            cout << "seven" << endl;
        else if (i == 8)
            cout << "eight" << endl;
        else if (i == 9)
            cout << "nine" << endl;
```
- **`if-else` statements**: Checks if `i` is between 1 and 9. For each value, it prints the corresponding English word using `cout` and moves to a new line (`endl`).

```cpp
        else if (i > 9){
            if (i % 2 == 0)
                cout << "even" << endl;
            else 
                cout << "odd" << endl;
        }
    }
```
- **`else if (i > 9)`**: If `i` is greater than 9, it checks whether `i` is even or odd.
  - **`if (i % 2 == 0)`**: Checks if `i` is divisible by 2 with no remainder (i.e., `i` is even). If true, it prints "even".
  - **`else`**: If `i` is not even (i.e., `i` is odd), it prints "odd".

```cpp
    return 0;
}
```
- **`return 0;`**: Returns 0 to the operating system to indicate that the program executed successfully.

### Summary
- The program reads two integers, `a` and `b`, from the user.
- It iterates through every integer from `a` to `b` (inclusive).
- For integers between 1 and 9, it prints the English word representation.
- For integers greater than 9, it prints whether the number is "even" or "odd".
- It uses a `for` loop for iteration and `if-else` statements for condition checks.
