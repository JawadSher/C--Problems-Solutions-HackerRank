<h1 align='center'>Other - Concepts</h1>

## Problem Statement

**Problem URL :** [Other Concepts](https://www.hackerrank.com/challenges/c-class-templates/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/6a1c3b55-c7a0-452d-bda7-094c1ed4279f)
![image](https://github.com/user-attachments/assets/2d945f58-acf3-415b-ac15-0467ddb923ea)

## Problem Solution
```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

template <class T>
class AddElements{
    private :
        T element;
    public:
        AddElements(const T& other): element(other){}
        T add(const T& other){return other + element;}
        T concatenate(const T& other){return element+other;}
};

int main () {
  int n,i;
  cin >> n;
  for(i=0;i<n;i++) {
    string type;
    cin >> type;
    if(type=="float") {
        double element1,element2;
        cin >> element1 >> element2;
        AddElements<double> myfloat (element1);
        cout << myfloat.add(element2) << endl;
    }
    else if(type == "int") {
        int element1, element2;
        cin >> element1 >> element2;
        AddElements<int> myint (element1);
        cout << myint.add(element2) << endl;
    }
    else if(type == "string") {
        string element1, element2;
        cin >> element1 >> element2;
        AddElements<string> mystring (element1);
        cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}

```

## Problem Solution Explanation
Let's break down the provided C++ code line by line, explaining each part in detail with examples.

### Includes and Namespace

```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
```

- **`#include` Directives**: These lines include various standard libraries. In this code:
  - `<cmath>`: Provides mathematical functions.
  - `<cstdio>`: Provides input and output functions.
  - `<vector>`: Provides the vector container.
  - `<iostream>`: Provides input and output stream objects.
  - `<algorithm>`: Provides algorithms like sort, etc.
  - `<cassert>`: Provides assert functionality for debugging.

- **`using namespace std;`**: This allows the use of standard library names without the `std::` prefix. For example, you can use `cout` instead of `std::cout`.

### Template Class Definition

```cpp
template <class T>
class AddElements {
private:
    T element;

public:
    AddElements(const T& other) : element(other) {}
    T add(const T& other) { return other + element; }
    T concatenate(const T& other) { return element + other; }
};
```

- **Template Declaration**: `template <class T>` declares a class template. `T` is a placeholder for any data type.

- **Class Definition**:
  - **Private Member**: `T element;` — A member variable `element` of type `T`.
  - **Constructor**: `AddElements(const T& other) : element(other) {}` — Initializes `element` with the value of `other` passed to the constructor.
  - **Member Function `add`**: Takes a parameter `other` of type `T` and returns `other + element`.
  - **Member Function `concatenate`**: Takes a parameter `other` of type `T` and returns `element + other`.

### `main` Function

```cpp
int main() {
    int n, i;
    cin >> n;
```

- **`int n, i;`**: Declares two integer variables, `n` and `i`.
- **`cin >> n;`**: Reads an integer from the input and stores it in `n`. This is the number of test cases.

```cpp
    for (i = 0; i < n; i++) {
        string type;
        cin >> type;
```

- **`for (i = 0; i < n; i++)`**: Loop runs `n` times, once for each test case.
- **`string type;`**: Declares a string variable `type` to store the type of data.
- **`cin >> type;`**: Reads a string from the input and stores it in `type`. This determines which type of `AddElements` to use.

```cpp
        if (type == "float") {
            double element1, element2;
            cin >> element1 >> element2;
            AddElements<double> myfloat(element1);
            cout << myfloat.add(element2) << endl;
        }
```

- **`if (type == "float")`**: Checks if the type is `"float"`.
  - **`double element1, element2;`**: Declares two `double` variables.
  - **`cin >> element1 >> element2;`**: Reads two `double` values from the input.
  - **`AddElements<double> myfloat(element1);`**: Creates an `AddElements` object for `double` with `element1` as the initial value.
  - **`cout << myfloat.add(element2) << endl;`**: Outputs the result of adding `element2` to `element1`.

```cpp
        else if (type == "int") {
            int element1, element2;
            cin >> element1 >> element2;
            AddElements<int> myint(element1);
            cout << myint.add(element2) << endl;
        }
```

- **`else if (type == "int")`**: Checks if the type is `"int"`.
  - **`int element1, element2;`**: Declares two `int` variables.
  - **`cin >> element1 >> element2;`**: Reads two `int` values from the input.
  - **`AddElements<int> myint(element1);`**: Creates an `AddElements` object for `int` with `element1` as the initial value.
  - **`cout << myint.add(element2) << endl;`**: Outputs the result of adding `element2` to `element1`.

```cpp
        else if (type == "string") {
            string element1, element2;
            cin >> element1 >> element2;
            AddElements<string> mystring(element1);
            cout << mystring.concatenate(element2) << endl;
        }
    }
    return 0;
}
```

- **`else if (type == "string")`**: Checks if the type is `"string"`.
  - **`string element1, element2;`**: Declares two `string` variables.
  - **`cin >> element1 >> element2;`**: Reads two `string` values from the input.
  - **`AddElements<string> mystring(element1);`**: Creates an `AddElements` object for `string` with `element1` as the initial value.
  - **`cout << mystring.concatenate(element2) << endl;`**: Outputs the result of concatenating `element2` to `element1`.

- **`return 0;`**: Ends the program successfully.

### Summary

- The code reads a number of test cases.
- For each test case, it reads a type and then performs operations based on the type.
  - For `float` and `int`, it performs addition.
  - For `string`, it performs concatenation.
- It uses a class template to handle different data types (int, float, string) and performs operations accordingly.

### Example

If the input is:
```
3
int
5 10
float
2.5 3.5
string
Hello World
```

The output will be:
```
15
6.0
HelloWorld
```

This example illustrates how the program handles integer addition, floating-point addition, and string concatenation.
