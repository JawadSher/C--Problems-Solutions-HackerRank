<h1 align='center'>Inheritance - Introduction</h1>

## Problem Statement

**Problem URL :** [Inheritance Introduction](https://www.hackerrank.com/challenges/inheritance-introduction/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/e6eea415-bce8-4957-ac19-b6cfbf160f90)
![image](https://github.com/user-attachments/assets/4e366dd6-d00f-40d8-8366-f5defe74ace0)

## Problem Solution
```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Triangle{
    public:
    	void triangle(){
     		cout<<"I am a triangle\n";
    	}
};

class Isosceles : public Triangle{
    public:
    	void isosceles(){
    		cout<<"I am an isosceles triangle\n";
    	}
  		void description(){
            cout<<"In an isosceles triangle two sides are equal\n";
        }
};

int main(){
    Isosceles isc;
    isc.isosceles();
  	isc.description();
    isc.triangle();
    return 0;
}
```

## Problem Solution Explanation
Let's break down the code line by line:

### Code Overview:
This C++ code demonstrates inheritance, where a derived class (`Isosceles`) inherits from a base class (`Triangle`). It highlights basic concepts of object-oriented programming, including class methods and inheritance.

```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
```
- **Libraries Included**:
  - `#include <cmath>`: Provides mathematical functions like `sqrt`, `pow`, etc.
  - `#include <cstdio>`: Includes standard input-output functions like `printf` and `scanf`.
  - `#include <vector>`: Includes the `vector` container from the Standard Template Library (STL).
  - `#include <iostream>`: Includes the standard input-output stream objects like `cin` and `cout`.
  - `#include <algorithm>`: Provides a collection of algorithms (like `sort`, `max`, etc.).

- **using namespace std;**: This line allows you to use all the names in the `std` namespace without needing to prefix them with `std::`.

### Class `Triangle`
```cpp
class Triangle{
    public:
    	void triangle(){
     		cout<<"I am a triangle\n";
    	}
};
```
- **class Triangle**: This defines a class named `Triangle`.
- **public**: The `public` keyword means that everything following it will be accessible from outside the class.
- **void triangle()**: This is a public member function of the `Triangle` class that prints "I am a triangle" when called.
  - **cout<<"I am a triangle\n";**: Outputs the string `"I am a triangle"` followed by a newline (`\n`).

### Class `Isosceles` (Derived from `Triangle`)
```cpp
class Isosceles : public Triangle{
    public:
    	void isosceles(){
    		cout<<"I am an isosceles triangle\n";
    	}
  		void description(){
            cout<<"In an isosceles triangle two sides are equal\n";
        }
};
```
- **class Isosceles : public Triangle**: This defines a new class named `Isosceles` that inherits publicly from the `Triangle` class. Inheritance means `Isosceles` will have access to all the public and protected members of `Triangle`.
- **void isosceles()**: A public member function of the `Isosceles` class that prints `"I am an isosceles triangle"`.
- **void description()**: Another public member function that prints `"In an isosceles triangle two sides are equal"`.
  
### `main` Function
```cpp
int main(){
    Isosceles isc;
    isc.isosceles();
  	isc.description();
    isc.triangle();
    return 0;
}
```
- **int main()**: The starting point of the program execution.
- **Isosceles isc;**: This line creates an object `isc` of the `Isosceles` class.
  - Since `Isosceles` inherits from `Triangle`, `isc` can call functions from both `Isosceles` and `Triangle`.
- **isc.isosceles();**: Calls the `isosceles` function of the `Isosceles` class, which outputs `"I am an isosceles triangle"`.
- **isc.description();**: Calls the `description` function of the `Isosceles` class, which outputs `"In an isosceles triangle two sides are equal"`.
- **isc.triangle();**: Calls the `triangle` function inherited from the `Triangle` class, which outputs `"I am a triangle"`.
- **return 0;**: Ends the `main` function, returning `0` to indicate successful execution.

### Example Execution:

When the `main` function runs, the output will be:

```
I am an isosceles triangle
In an isosceles triangle two sides are equal
I am a triangle
```

### Explanation:
- **Inheritance**: The `Isosceles` class inherits from the `Triangle` class, so the `isc` object can call the `triangle()` method from `Triangle`.
- **Method Calling**: The order in which methods are called in `main()` determines the order of the printed output.

This code illustrates how inheritance works in C++, allowing a derived class to use the properties and methods of its base class, along with its own unique methods.
