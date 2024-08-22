<h1 align='center'>Virtual - Functions</h1>

## Problem Statement

**Problem URL :** [Virtual Functions](https://www.hackerrank.com/challenges/virtual-functions/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/42f24a1f-c211-4120-ab21-15f015ccf2f0)
![image](https://github.com/user-attachments/assets/66317b96-f8c9-4d3e-a2fa-1de553f5265d)

## Problem Solution
```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person{
    protected:
        string name;
        int age;
    public:
        virtual void getdata(){};
        virtual void putdata(){};
};

class Professor : public Person{
    private:
        int publications;
        int cur_id;
        static int id;
        
    public:
        Professor(){
            cur_id = ++id;
        }
        void getdata(){  
            cin >> this->name >> this->age >> this->publications;   
        }
        void putdata(){
            cout<<name<<" "<<age<< " "<<publications<< " "<<cur_id<<endl;
        }
};

int Professor :: id = 0;

class Student : public Person{
    private:
        int marks[6];
        int cur_id;
        static int id;
        int sum;
    public:
        Student(){
            cur_id = ++id;
            sum = 0;
        }
        void getdata(){
            cin>>this->name >> this->age;
            for(int i = 0; i < 6; i++){
                 cin >> this->marks[i];
            }
        }
        void putdata(){
            for(int i = 0; i < 6; i++){
                sum += marks[i];
            }
            
            cout<<name<< " " <<age <<" "<<sum<< " "<<cur_id<<endl;
        }
};

int Student :: id = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}

```

## Problem Solution Explanation
Let's go through the code line by line to understand its functionality and purpose.

### Header Files

```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
```
- **`#include <cmath>`**: Includes the math library, though it's not used in this program.
- **`#include <cstdio>`**: Includes the C standard I/O functions, though it's also not used directly in this code.
- **`#include <vector>`**: Includes the vector library, which allows the use of dynamic arrays.
- **`#include <iostream>`**: Includes the standard input-output stream library, enabling the use of `cin` and `cout`.
- **`#include <algorithm>`**: Includes algorithms library, though it’s not used directly in this program.

- **`using namespace std;`**: Allows us to use standard library classes and functions (like `cin`, `cout`, `vector`, etc.) without needing to prefix them with `std::`.

### Base Class: `Person`

```cpp
class Person {
    protected:
        string name;
        int age;
    public:
        virtual void getdata() {};
        virtual void putdata() {};
};
```
- **`class Person`**: Defines a base class named `Person`.
- **`protected:`**: Members under this access specifier are accessible within the class and its derived classes.
- **`string name; int age;`**: The `Person` class has two protected data members: `name` (a string) and `age` (an integer).
- **`public:`**: Members under this access specifier are accessible from outside the class.
- **`virtual void getdata() {}`**: Declares a virtual function `getdata()` that is meant to be overridden by derived classes. The function is empty in the base class.
- **`virtual void putdata() {}`**: Declares a virtual function `putdata()` that is also meant to be overridden by derived classes. It is also empty in the base class.

### Derived Class: `Professor`

```cpp
class Professor : public Person {
    private:
        int publications;
        int cur_id;
        static int id;
        
    public:
        Professor(){
            cur_id = ++id;
        }
        void getdata() {  
            cin >> this->name >> this->age >> this->publications;   
        }
        void putdata() {
            cout << name << " " << age << " " << publications << " " << cur_id << endl;
        }
};
```
- **`class Professor : public Person`**: Defines a class `Professor` that inherits publicly from `Person`.
- **`private:`**: Members under this access specifier are accessible only within the class.
- **`int publications; int cur_id; static int id;`**: The class has three data members: `publications` (an integer representing the number of publications), `cur_id` (a unique ID for each professor), and `id` (a static integer that tracks the next ID to assign).
- **`Professor() { cur_id = ++id; }`**: Constructor that increments the static `id` and assigns it to `cur_id`, ensuring each professor has a unique ID.
- **`void getdata() { cin >> this->name >> this->age >> this->publications; }`**: Overrides the `getdata()` function to input the `name`, `age`, and `publications` for a professor.
- **`void putdata() { cout << name << " " << age << " " << publications << " " << cur_id << endl; }`**: Overrides the `putdata()` function to output the `name`, `age`, `publications`, and `cur_id` of a professor.

```cpp
int Professor::id = 0;
```
- **`int Professor::id = 0;`**: Initializes the static `id` variable to `0` for the `Professor` class.

### Derived Class: `Student`

```cpp
class Student : public Person {
    private:
        int marks[6];
        int cur_id;
        static int id;
        int sum;
    public:
        Student(){
            cur_id = ++id;
            sum = 0;
        }
        void getdata() {
            cin >> this->name >> this->age;
            for (int i = 0; i < 6; i++) {
                cin >> this->marks[i];
            }
        }
        void putdata() {
            for (int i = 0; i < 6; i++) {
                sum += marks[i];
            }
            cout << name << " " << age << " " << sum << " " << cur_id << endl;
        }
};
```
- **`class Student : public Person`**: Defines a class `Student` that inherits publicly from `Person`.
- **`private:`**: Members under this access specifier are accessible only within the class.
- **`int marks[6]; int cur_id; static int id; int sum;`**: The class has four data members: `marks` (an array of six integers representing marks in six subjects), `cur_id` (a unique ID for each student), `id` (a static integer that tracks the next ID to assign), and `sum` (an integer to store the total marks).
- **`Student() { cur_id = ++id; sum = 0; }`**: Constructor that increments the static `id` and assigns it to `cur_id`, ensuring each student has a unique ID, and initializes `sum` to `0`.
- **`void getdata() { cin >> this->name >> this->age; for (int i = 0; i < 6; i++) { cin >> this->marks[i]; } }`**: Overrides the `getdata()` function to input the `name`, `age`, and `marks` for a student.
- **`void putdata() { for (int i = 0; i < 6; i++) { sum += marks[i]; } cout << name << " " << age << " " << sum << " " << cur_id << endl; }`**: Overrides the `putdata()` function to output the `name`, `age`, `sum` (total marks), and `cur_id` of a student.

```cpp
int Student::id = 0;
```
- **`int Student::id = 0;`**: Initializes the static `id` variable to `0` for the `Student` class.

### Main Function

```cpp
int main() {

    int n, val;
    cin >> n; // The number of objects that are going to be created.
    Person *per[n];
```
- **`int main()`**: The main function where the program execution begins.
- **`int n, val; cin >> n;`**: Reads an integer `n` from the user, which represents the number of objects (either `Professor` or `Student`) that will be created.
- **`Person *per[n];`**: Creates an array of `Person` pointers of size `n`.

```cpp
    for (int i = 0; i < n; i++) {

        cin >> val;
        if (val == 1) {
            // If val is 1, the current object is of type Professor
            per[i] = new Professor;
        } else {
            // Else the current object is of type Student
            per[i] = new Student;
        }

        per[i]->getdata(); // Get the data from the user.
    }
```
- **`for (int i = 0; i < n; i++) { cin >> val; if (val == 1) { per[i] = new Professor; } else { per[i] = new Student; } per[i]->getdata(); }`**:
  - Loops `n` times to create `n` objects.
  - **`cin >> val;`**: Reads an integer `val` from the user.
  - **`if (val == 1) { per[i] = new Professor; } else { per[i] = new Student; }`**: If `val` is `1`, the program creates a `Professor` object and assigns it to `per[i]`. Otherwise, it creates a `Student` object.
  - **`per[i]->getdata();`**: Calls the `getdata()` method on the created object to input its data.

```cpp
    for (int i = 0; i < n; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;
}
```
- **`for (int i = 0; i < n; i++) per[i]->putdata();`**: Loops `n` times to call the `putdata()` method on each object to output its data.
- **`return 0;`**: Returns `0` from the `main` function, indicating successful execution of the program.

### Summary
- This program demonstrates the use of inheritance and polymorphism in C++.
- The `Person` class serves as a base class with virtual functions `getdata()` and `putdata()` which are overridden in the derived classes `Professor` and `Student`.
- The program creates either `Professor` or `Student` objects based on user input, stores them in an array of `Person` pointers, and then uses polymorphism to call the appropriate `getdata()` and `putdata()`
