<h1 align='center'>Inherited Code</h1>

## Problem Statement

**Problem URL :** [Inherited Code](https://www.hackerrank.com/challenges/inherited-code/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/86cd02e1-8a83-411a-88f7-f018085579bf)
![image](https://github.com/user-attachments/assets/73d86a35-4f75-4867-aeec-0f6c67b481e3)


## Problem Solution
```cpp
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

class BadLengthException{
    private:
        int n;
    public:
        BadLengthException(int Error){
            n = Error;
        }
        int what() {return n;}
};


bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if(n < 5) {
		throw BadLengthException(n);
	}
	for(int i = 0; i < n-1; i++) {
		if(username[i] == 'w' && username[i+1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while(T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if(isValid) {
				cout << "Valid" << '\n';
			} else {
				cout << "Invalid" << '\n';
			}
		} catch (BadLengthException e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}
```

## Problem Solution Explanation

Let's go through the code line by line to understand how each part works.

```cpp
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
```
- **`#include <iostream>`**: This line includes the input-output stream library, which allows the program to perform input and output operations using `cin` and `cout`.
- **`#include <string>`**: This includes the string library, which provides support for string manipulations.
- **`#include <sstream>`**: This includes the stringstream library, which can be used to perform input and output operations on strings.
- **`#include <exception>`**: This includes the exception handling library, which provides the base classes for handling exceptions in C++.

```cpp
using namespace std;
```
- **`using namespace std;`**: This line allows the program to use all the standard library functions and classes (like `cout`, `cin`, `string`, etc.) without needing to prefix them with `std::`.

```cpp
class BadLengthException {
    private:
        int n;
```
- **`class BadLengthException`**: This defines a custom exception class named `BadLengthException`.
- **`private:`**: This access specifier means that the following members (`n`) are only accessible within the class itself.
- **`int n;`**: This declares an integer variable `n` that will store the length of the username that caused the exception.

```cpp
    public:
        BadLengthException(int Error) {
            n = Error;
        }
```
- **`public:`**: This access specifier means that the following members are accessible from outside the class.
- **`BadLengthException(int Error)`**: This is a constructor for the `BadLengthException` class that takes an integer `Error` as an argument.
- **`n = Error;`**: Inside the constructor, the integer `Error` is assigned to the class variable `n`. This means that `n` now holds the length of the username that caused the exception.

```cpp
        int what() { return n; }
};
```
- **`int what() { return n; }`**: This is a member function named `what()` that returns the value of `n`. This function provides access to the stored length when the exception is caught.
- **`};`**: This closes the class definition.

```cpp
bool checkUsername(string username) {
    bool isValid = true;
    int n = username.length();
```
- **`bool checkUsername(string username)`**: This is a function that takes a string `username` as input and returns a boolean value indicating whether the username is valid.
- **`bool isValid = true;`**: This initializes a boolean variable `isValid` to `true`. It will be used to track whether the username is valid or not.
- **`int n = username.length();`**: This stores the length of the `username` string in the integer variable `n`.

```cpp
    if(n < 5) {
        throw BadLengthException(n);
    }
```
- **`if(n < 5)`**: This checks if the length of the username (`n`) is less than 5.
- **`throw BadLengthException(n);`**: If the length is less than 5, the function throws a `BadLengthException` with the value of `n`. This triggers an exception that will be caught later in the program.

```cpp
    for(int i = 0; i < n-1; i++) {
        if(username[i] == 'w' && username[i+1] == 'w') {
            isValid = false;
        }
    }
```
- **`for(int i = 0; i < n-1; i++)`**: This loop iterates through the username string, checking each character up to the second-to-last character.
- **`if(username[i] == 'w' && username[i+1] == 'w')`**: This checks if the current character (`username[i]`) is 'w' and if the next character (`username[i+1]`) is also 'w'.
- **`isValid = false;`**: If the sequence "ww" is found, `isValid` is set to `false`, indicating that the username is invalid.

```cpp
    return isValid;
}
```
- **`return isValid;`**: This returns the value of `isValid`. If the username passed both the length check and the "ww" check, `isValid` remains `true`. Otherwise, it will return `false`.

```cpp
int main() {
    int T; cin >> T;
```
- **`int main()`**: This is the main function where the program execution begins.
- **`int T; cin >> T;`**: This reads an integer `T` from the user, which represents the number of test cases.

```cpp
    while(T--) {
        string username;
        cin >> username;
```
- **`while(T--)`**: This loop runs `T` times, decrementing `T` with each iteration. Each iteration processes one username.
- **`string username;`**: This declares a string variable `username` to store the input username.
- **`cin >> username;`**: This reads the username from the user.

```cpp
        try {
            bool isValid = checkUsername(username);
            if(isValid) {
                cout << "Valid" << '\n';
            } else {
                cout << "Invalid" << '\n';
            }
        }
```
- **`try {`**: This starts a `try` block, which is used to handle exceptions.
- **`bool isValid = checkUsername(username);`**: This calls the `checkUsername` function to validate the username and stores the result in `isValid`.
- **`if(isValid)`**: This checks if `isValid` is `true`.
- **`cout << "Valid" << '\n';`**: If `isValid` is `true`, the program prints "Valid" followed by a newline character.
- **`else`**: If `isValid` is `false`, the program executes the `else` block.
- **`cout << "Invalid" << '\n';`**: If the username is invalid, the program prints "Invalid" followed by a newline character.

```cpp
        catch (BadLengthException e) {
            cout << "Too short: " << e.what() << '\n';
        }
    }
```
- **`catch (BadLengthException e)`**: This block catches the `BadLengthException` if it is thrown in the `try` block.
- **`cout << "Too short: " << e.what() << '\n';`**: When the exception is caught, the program prints "Too short: " followed by the length of the username (`e.what()`) and a newline character.

```cpp
    return 0;
}
```
- **`return 0;`**: This line returns `0` from the `main` function, indicating that the program has finished successfully.
- **`}`**: This closes the `main` function.

### Summary

- The program checks whether each username meets certain criteria.
- If the username is shorter than 5 characters, it throws a custom `BadLengthException`.
- If the username contains "ww", it marks it as invalid.
- The program prints "Valid" for valid usernames, "Invalid" for usernames containing "ww", and "Too short: n" for usernames shorter than 5 characters.
