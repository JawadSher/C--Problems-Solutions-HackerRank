<h1 align='center'>Strings</h1>

## Problem Statement

**Problem URL :** [Strings](https://www.hackerrank.com/challenges/c-tutorial-strings/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/3251fe6a-3db0-4b57-beeb-65d29f6991d1)
![image](https://github.com/user-attachments/assets/965bae93-8ea6-408c-8964-99d5cc7b5dbf)


## Problem Solution

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin>> a >> b;
    
    cout<<a.size()<<" "<<b.size()<<endl;
    cout<<(a+b)<<endl;
    cout<<b.substr(0, 1)<<a.substr(1, a.size())<<" "<<a.substr(0, 1)<<b.substr(1, b.size());
    
  
    return 0;
}
```

## Problem Solution Explanation

Let's break down the C++ code line by line:

### 1. Includes and Namespace

```cpp
#include <iostream>
#include <string>
using namespace std;
```

- `#include <iostream>`: This header file is included to use input/output stream objects like `cin` and `cout`.
- `#include <string>`: This header file is included to use the `std::string` class.
- `using namespace std;`: This statement allows us to use standard library features like `cout`, `cin`, and `string` without prefixing them with `std::`.

### 2. Main Function

```cpp
int main() {
```

- This is the main function where the execution of the program begins.

### 3. Variable Declarations

```cpp
    string a, b;
```

- Two `string` variables, `a` and `b`, are declared to hold the input strings.

### 4. Input

```cpp
    cin >> a >> b;
```

- This line reads two strings from the standard input (usually the keyboard) and stores them in variables `a` and `b`.

### 5. Output String Sizes

```cpp
    cout << a.size() << " " << b.size() << endl;
```

- `a.size()` returns the length of the string `a`.
- `b.size()` returns the length of the string `b`.
- The sizes of `a` and `b` are printed, separated by a space, followed by a newline.

### 6. Concatenate and Print

```cpp
    cout << (a + b) << endl;
```

- `a + b` concatenates the strings `a` and `b` and the result is printed followed by a newline.

### 7. Formatted String Output

```cpp
    cout << b.substr(0, 1) << a.substr(1, a.size()) << " " << a.substr(0, 1) << b.substr(1, b.size());
```

- `b.substr(0, 1)` extracts the first character of `b`.
- `a.substr(1, a.size())` extracts the substring of `a` starting from index 1 to the end.
- `a.substr(0, 1)` extracts the first character of `a`.
- `b.substr(1, b.size())` extracts the substring of `b` starting from index 1 to the end.
- These substrings are concatenated and printed, with a space between them.

### 8. Return Statement

```cpp
    return 0;
```

- This indicates that the program ended successfully. `0` is returned to the operating system.

### Example

Let's say the input is:

```
hello world
```

- `a` will be `"hello"` and `b` will be `"world"`.
- The output will be:
  1. `5 5` (lengths of `"hello"` and `"world"`)
  2. `helloworld` (concatenation of `"hello"` and `"world"`)
  3. `welloworld horld` (first character of `"world"` + `"ello"` + a space + first character of `"hello"` + `"orld"`)

This code demonstrates basic string operations such as size, concatenation, and substring extraction.
