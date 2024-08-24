<h1 align='center'>Multi - Level - Inheritance</h1>

## Problem Statement

**Problem URL :** [Multi Level Inheritance](https://www.hackerrank.com/challenges/multi-level-inheritance-cpp/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/ffb34f7c-761b-41a7-a09b-8195598e9ed7)

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
};

class Equilateral : public Isosceles{
    public:
        void equilateral(){
            cout<<"I am an equilateral triangle"<<endl;
        }
};

int main(){
  
    Equilateral eqr;
    eqr.equilateral();
    eqr.isosceles();
    eqr.triangle();
    return 0;
}

```

## Problem Solution Explanation
Let's go through the code line by line and explain each part with examples.

### 1. **Including Headers and Using Namespace**
```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
```
- **`#include <cmath>`, `#include <cstdio>`, `#include <vector>`, `#include <iostream>`, `#include <algorithm>`**:
  - These are standard library headers in C++.
  - `cmath`: Contains functions for mathematical operations.
  - `cstdio`: Provides input and output operations in C-style.
  - `vector`: Defines the `std::vector` container.
  - `iostream`: Allows for input and output operations using `cin`, `cout`.
  - `algorithm`: Provides functions for common algorithms like `sort`, `find`, etc.
  
- **`using namespace std;`**: This tells the compiler to use the standard namespace, so you don't have to prefix `std::` before `cin`, `cout`, and other standard library functions.

### 2. **Defining the `Triangle` Class**
```cpp
class Triangle{
	public:
		void triangle(){
			cout<<"I am a triangle\n";
		}
};
```
- **`class Triangle { ... };`**: This defines a class named `Triangle`.
- **`public:`**: Everything following this label is publicly accessible, meaning any function or class can access these members.
- **`void triangle() { ... }`**:
  - This method prints the message `"I am a triangle"` to the console.
  - Example: If you create an object of `Triangle` and call this method, it will output `"I am a triangle"`.

### 3. **Defining the `Isosceles` Class**
```cpp
class Isosceles : public Triangle{
  	public:
  		void isosceles(){
    		cout<<"I am an isosceles triangle\n";
  		}
};
```
- **`class Isosceles : public Triangle { ... };`**: This defines a class named `Isosceles` that **inherits** from the `Triangle` class. This means `Isosceles` has all the public and protected members of `Triangle`.
- **`void isosceles() { ... }`**:
  - This method prints `"I am an isosceles triangle"` to the console.
  - Example: If you create an object of `Isosceles` and call `isosceles()`, it will output `"I am an isosceles triangle"`.
  - Since `Isosceles` inherits from `Triangle`, it also has access to the `triangle()` method.

### 4. **Defining the `Equilateral` Class**
```cpp
class Equilateral : public Isosceles{
    public:
        void equilateral(){
            cout<<"I am an equilateral triangle"<<endl;
        }
};
```
- **`class Equilateral : public Isosceles { ... };`**: This defines a class named `Equilateral` that inherits from the `Isosceles` class.
- **`void equilateral() { ... }`**:
  - This method prints `"I am an equilateral triangle"` to the console.
  - Example: If you create an object of `Equilateral` and call `equilateral()`, it will output `"I am an equilateral triangle"`.
  - Since `Equilateral` inherits from `Isosceles`, it also inherits the `isosceles()` method and, through `Isosceles`, inherits the `triangle()` method from `Triangle`.

### 5. **Main Function**
```cpp
int main(){
  
    Equilateral eqr;
    eqr.equilateral();
    eqr.isosceles();
    eqr.triangle();
    return 0;
}
```
- **`int main() { ... }`**: This is the main function, which is the entry point of the program.
  
- **`Equilateral eqr;`**:
  - This line creates an object `eqr` of type `Equilateral`.
  - Since `Equilateral` inherits from both `Isosceles` and `Triangle`, `eqr` can call methods from both these classes.
  
- **`eqr.equilateral();`**:
  - Calls the `equilateral()` method, which outputs `"I am an equilateral triangle"`.
  
- **`eqr.isosceles();`**:
  - Calls the `isosceles()` method, which outputs `"I am an isosceles triangle"`.
  
- **`eqr.triangle();`**:
  - Calls the `triangle()` method, which outputs `"I am a triangle"`.
  
- **`return 0;`**:
  - The function ends, and the program returns 0, which typically indicates successful execution.

### Example Execution:

When you run this program, the output will be:
```
I am an equilateral triangle
I am an isosceles triangle
I am a triangle
```

### Summary:
- **`Equilateral` class** is the most specific type of triangle here, inheriting properties and methods from both `Isosceles` and `Triangle`.
- The **hierarchy** reflects how an equilateral triangle is a specific type of isosceles triangle, which in turn is a type of triangle.
- This demonstrates **inheritance** in C++ where a derived class can access methods and properties of its base classes.

