<h1 align='center'>Class</h1>

## Problem Statement

**Problem URL :** [Class](https://www.hackerrank.com/challenges/c-tutorial-class/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/9777124b-3cc7-41e0-8a76-52edc86f78d3)
![image](https://github.com/user-attachments/assets/a883adbf-3536-4212-aa48-a1f6a616b6d6)
![image](https://github.com/user-attachments/assets/ffc8d11d-13a3-472c-bbf6-0da2aea8b482)

## Problem Solution 
```cpp
#include <iostream>
#include <sstream>
using namespace std;

class Student{
    private:
        int age;
        string first_name;
        string last_name;
        int standard;
    public:
        void set_age(int AGE){   
            age = AGE;
        }
        void set_standard(int STANDARD){   
            standard = STANDARD;
        }
        void set_first_name(string FIRST_NAME){
            first_name = FIRST_NAME;
        }
        void set_last_name(string LAST_NAME){
            last_name = LAST_NAME;
        }
        
        
        int get_age(){
            return age;
        }
        string get_first_name(){
            return first_name;
        }
        string get_last_name(){
            return last_name;
        }
        int get_standard(){
            return standard;
        }
        string to_string(){
            stringstream ss;
            ss << age << "," << first_name << "," << last_name << "," << standard;
            
            return ss.str();
        }
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}
```


## Problem Solution Explanation

This C++ program demonstrates the use of classes, encapsulation, and string manipulation. It models a `Student` class with private attributes and provides public methods to set and get the values of these attributes. Let's break down the code step by step.

### Key Concepts

1. **Classes and Objects:**
   - A class in C++ is a blueprint for creating objects. It can contain variables (known as attributes) and functions (known as methods) to manipulate those variables.

2. **Encapsulation:**
   - Encapsulation is the concept of bundling data (attributes) and methods that operate on the data into a single unit (class). Access to the data is restricted by making the attributes private and providing public methods to interact with them.

3. **StringStream:**
   - The `stringstream` class in C++ is used to manipulate strings like streams. It's useful for converting between strings and other data types.


1. **Include Statements:**
   ```cpp
   #include <iostream>
   #include <sstream>
   ```
   - `#include <iostream>` allows for input and output operations (e.g., `cin` and `cout`).
   - `#include <sstream>` allows the use of `stringstream`, which helps in converting and manipulating strings.

2. **Class Definition:**
   ```cpp
   class Student {
   ```
   - The `Student` class is defined here. It will hold information about a student, such as age, first name, last name, and standard (grade level).

3. **Private Attributes:**
   ```cpp
   private:
       int age;
       string first_name;
       string last_name;
       int standard;
   ```
   - These are the attributes of the `Student` class. They are declared as `private`, meaning they cannot be accessed directly from outside the class.

4. **Public Methods:**
   ```cpp
   public:
   ```
   - The following methods are public, meaning they can be accessed from outside the class.

   **Setters:**
   ```cpp
   void set_age(int AGE) {   
       age = AGE;
   }
   void set_standard(int STANDARD) {   
       standard = STANDARD;
   }
   void set_first_name(string FIRST_NAME) {
       first_name = FIRST_NAME;
   }
   void set_last_name(string LAST_NAME) {
       last_name = LAST_NAME;
   }
   ```
   - These are "setter" methods that allow setting the values of the private attributes from outside the class.
   - For example, `set_age(int AGE)` sets the value of the `age` attribute to `AGE`.

   **Getters:**
   ```cpp
   int get_age() {
       return age;
   }
   string get_first_name() {
       return first_name;
   }
   string get_last_name() {
       return last_name;
   }
   int get_standard() {
       return standard;
   }
   ```
   - These are "getter" methods that return the values of the private attributes.

   **to_string Method:**
   ```cpp
   string to_string() {
       stringstream ss;
       ss << age << "," << first_name << "," << last_name << "," << standard;
       return ss.str();
   }
   ```
   - This method combines all the attributes into a single string separated by commas and returns it. It uses a `stringstream` to concatenate the values.

5. **Main Function:**
   ```cpp
   int main() {
       int age, standard;
       string first_name, last_name;
       
       cin >> age >> first_name >> last_name >> standard;
       
       Student st;
       st.set_age(age);
       st.set_standard(standard);
       st.set_first_name(first_name);
       st.set_last_name(last_name);
       
       cout << st.get_age() << "\n";
       cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
       cout << st.get_standard() << "\n";
       cout << "\n";
       cout << st.to_string();
       
       return 0;
   }
   ```
   - The `main()` function is where the program starts executing.

   **Input Section:**
   ```cpp
   cin >> age >> first_name >> last_name >> standard;
   ```
   - The program reads the student's age, first name, last name, and standard from the user.

   **Creating and Using a Student Object:**
   ```cpp
   Student st;
   st.set_age(age);
   st.set_standard(standard);
   st.set_first_name(first_name);
   st.set_last_name(last_name);
   ```
   - A `Student` object named `st` is created.
   - The input values are then assigned to the `st` object using the setter methods.

   **Output Section:**
   ```cpp
   cout << st.get_age() << "\n";
   cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
   cout << st.get_standard() << "\n";
   cout << "\n";
   cout << st.to_string();
   ```
   - The student's age, last name, first name, and standard are printed using the getter methods.
   - Finally, the `to_string()` method is used to display all the information in a single comma-separated string.

### Example

Let's say the user provides the following input:

```
16 Alice Johnson 11
```

1. **Input:**
   - `age = 16`
   - `first_name = "Alice"`
   - `last_name = "Johnson"`
   - `standard = 11`

2. **Object Creation and Setting Values:**
   - A `Student` object `st` is created.
   - `st.set_age(16)` sets the age to 16.
   - `st.set_first_name("Alice")` sets the first name to "Alice".
   - `st.set_last_name("Johnson")` sets the last name to "Johnson".
   - `st.set_standard(11)` sets the standard to 11.

3. **Output:**
   ```cpp
   cout << st.get_age() << "\n";
   ```
   - Prints: `16`
   
   ```cpp
   cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
   ```
   - Prints: `Johnson, Alice`
   
   ```cpp
   cout << st.get_standard() << "\n";
   ```
   - Prints: `11`
   
   ```cpp
   cout << st.to_string();
   ```
   - Prints: `16,Alice,Johnson,11`

### Summary

This program illustrates the basic principles of object-oriented programming in C++, focusing on encapsulation. It shows how to use classes to model real-world entities, how to set and get the values of private attributes using public methods, and how to format and output data as a string using the `stringstream` class.
