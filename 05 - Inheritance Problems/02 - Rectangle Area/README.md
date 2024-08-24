<h1 align='center'>Rectangle - Area</h1>

## Problem Statement

**Problem URL :** [Rectangle Area](https://www.hackerrank.com/challenges/rectangle-area/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/5f632b9b-ea43-490a-b6e0-27c54978c3a3)


## Problem Solution
```cpp
#include <iostream>
using namespace std;

class Rectangle{
    protected:
        int width;
        int height;
    
    public:
        virtual void display(){
            cout<<width << " " <<height <<endl;
        }
        
        void read_input(){
            cin>> width >> height;
        }
    
};

class RectangleArea : public Rectangle{
    public:
        void display() override{
            cout<<width * height <<endl;
        }
};

int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}
```

## Problem Solution Explanation
Let's go through the code line by line to understand its functionality:

### 1. **Include Header and Use Namespace:**
```cpp
#include <iostream>
using namespace std;
```
- **`#include <iostream>`**: This line includes the input/output stream library in C++, which allows us to use `cin` and `cout`.
- **`using namespace std;`**: This line tells the compiler to use the standard namespace, so we don't need to prefix `std::` before `cin` and `cout`.

### 2. **Defining the `Rectangle` Class:**
```cpp
class Rectangle {
protected:
    int width;
    int height;

public:
    virtual void display() {
        cout << width << " " << height << endl;
    }
    
    void read_input() {
        cin >> width >> height;
    }
};
```
- **`class Rectangle { ... };`**: This defines a class named `Rectangle`.
- **`protected:`**: The `width` and `height` variables are declared as protected. This means they can be accessed directly in the derived class (`RectangleArea`), but not outside the class.
- **`int width; int height;`**: These two variables represent the dimensions of the rectangle.
  
- **`virtual void display() { ... }`**: 
  - This method displays the width and height of the rectangle. 
  - **`virtual`** means this method can be overridden in a derived class.
  - `cout << width << " " << height << endl;` prints the width and height separated by a space.

- **`void read_input() { ... }`**: 
  - This method reads the width and height from the user input using `cin`.
  - `cin >> width >> height;` reads two integers from input and assigns them to `width` and `height`.

### 3. **Defining the `RectangleArea` Class:**
```cpp
class RectangleArea : public Rectangle {
public:
    void display() override {
        cout << width * height << endl;
    }
};
```
- **`class RectangleArea : public Rectangle { ... };`**: This defines a class named `RectangleArea` that inherits from `Rectangle`.
  
- **`void display() override { ... }`**:
  - This method overrides the `display()` method in the `Rectangle` class.
  - **`override`** ensures that this method is correctly overriding a base class method.
  - `cout << width * height << endl;` prints the area of the rectangle, which is the product of `width` and `height`.

### 4. **Main Function:**
```cpp
int main() {
    RectangleArea r_area;
    
    r_area.read_input();
    
    r_area.Rectangle::display();
    
    r_area.display();
    
    return 0;
}
```
- **`int main() { ... }`**: The main function is the entry point of the program.
  
- **`RectangleArea r_area;`**: 
  - This line creates an object `r_area` of type `RectangleArea`.
  
- **`r_area.read_input();`**: 
  - Calls the `read_input()` method from the `Rectangle` class, allowing the user to input the width and height values for the rectangle.
  
- **`r_area.Rectangle::display();`**: 
  - This line explicitly calls the `display()` method from the `Rectangle` class. 
  - It prints the width and height of the rectangle.

- **`r_area.display();`**: 
  - Calls the overridden `display()` method from the `RectangleArea` class, which calculates and prints the area of the rectangle.
  
- **`return 0;`**: 
  - The program ends and returns 0, indicating successful execution.

### 5. **Example Execution:**

Suppose the user inputs:
```
5 4
```
The program will output:
```
5 4
20
```
- **`5 4`**: The dimensions of the rectangle (width and height).
- **`20`**: The area of the rectangle (5 * 4 = 20).

### Summary:
- **`Rectangle` class** handles basic attributes (`width`, `height`) and methods (`display`, `read_input`).
- **`RectangleArea` class** inherits these attributes and methods but overrides `display()` to show the area instead of just the dimensions.
- The main function demonstrates creating an object, reading input, and displaying both the dimensions and the calculated area.

