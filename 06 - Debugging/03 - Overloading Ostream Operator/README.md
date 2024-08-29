<h1 align='center'>Overloading - Ostream - Operator</h1>

## Problem Statement

**Problem URL :** [Overloading Ostream Operator](https://www.hackerrank.com/challenges/overloading-ostream-operator/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/a7d7beef-79e4-45be-9567-b09521d048df)
![image](https://github.com/user-attachments/assets/f9de6896-b3b7-478f-ab35-543d98c31a62)

## Problem Explanation

In C++, the `<<` operator is commonly used for outputting data to streams, such as printing to the console using `std::cout`. By default, the `<<` operator works with built-in types like `int`, `double`, and `string`. However, when you create your own classes, the `<<` operator doesn't know how to output objects of those types. To make it possible to use the `<<` operator with objects of a custom class, you need to overload this operator.

The problem statement typically asks you to implement this operator overloading so that when you print an object of your class, it outputs the object's data in a formatted manner.

### Example Scenario

Suppose you have a class `Person` that stores a person's first and last names. If you create an object of this class and try to print it using `std::cout`, it won't work unless you've defined how the `<<` operator should handle objects of the `Person` class. The task is to define this behavior.


## Problem Solution
```cpp
#include <iostream>
using namespace std;

class Person {
public:
    Person(const string& first_name, const string& last_name) : first_name_(first_name), last_name_(last_name) {}
    const string& get_first_name() const {
      return first_name_;
    }
    const string& get_last_name() const {
      return last_name_;
    }
private:
    string first_name_;
    string last_name_;
};

ostream& operator<<(ostream& os, const Person& p){
    os << "first_name=" <<p.get_first_name() << ",last_name="<<p.get_last_name();
    return os;
}


int main() {
    string first_name, last_name, event;
    cin >> first_name >> last_name >> event;
    auto p = Person(first_name, last_name);
    cout << p << " " << event << endl;
    return 0;
}

```

## Problem Solution Explanation

Now, let's go through the code you've provided line by line to understand how it works.

#### Includes and Namespace
```cpp
#include <iostream>
using namespace std;
```
- **`#include <iostream>`**: This includes the standard input/output stream library, which allows you to use `std::cin` and `std::cout`.
- **`using namespace std;`**: This brings all the names in the `std` namespace into the global namespace, so you don't need to prefix standard library names with `std::`.

#### The `Person` Class

```cpp
class Person {
public:
    Person(const string& first_name, const string& last_name) : first_name_(first_name), last_name_(last_name) {}
    const string& get_first_name() const {
      return first_name_;
    }
    const string& get_last_name() const {
      return last_name_;
    }
private:
    string first_name_;
    string last_name_;
};
```

- **`class Person { ... };`**: Defines a class `Person` with private data members and public methods.

- **Constructor**: 
    ```cpp
    Person(const string& first_name, const string& last_name) : first_name_(first_name), last_name_(last_name) {}
    ```
    - **`Person(const string& first_name, const string& last_name)`**: This is a constructor that initializes a `Person` object with the given `first_name` and `last_name`.
    - **`: first_name_(first_name), last_name_(last_name)`**: This is an initializer list that sets the private members `first_name_` and `last_name_` to the values passed as arguments.

- **Getter Methods**:
    ```cpp
    const string& get_first_name() const {
      return first_name_;
    }
    const string& get_last_name() const {
      return last_name_;
    }
    ```
    - These methods return the first name and last name of the `Person` object. They are marked as `const`, meaning they do not modify the object.

- **Private Data Members**:
    ```cpp
    private:
        string first_name_;
        string last_name_;
    ```
    - These are private members that store the first and last names of the `Person`.

#### Overloading the `<<` Operator

```cpp
ostream& operator<<(ostream& os, const Person& p){
    os << "first_name=" << p.get_first_name() << ",last_name=" << p.get_last_name();
    return os;
}
```

- **`ostream& operator<<(ostream& os, const Person& p)`**:
    - This function overloads the `<<` operator to allow objects of the `Person` class to be output using `std::cout` or any other `ostream`.
    - **`ostream& os`**: The output stream object (like `cout`).
    - **`const Person& p`**: A constant reference to a `Person` object that you want to print.

- **Function Body**:
    - **`os << "first_name=" << p.get_first_name() << ",last_name=" << p.get_last_name();`**:
        - This line formats the output by first printing `"first_name="`, then the actual first name from the `Person` object, followed by `",last_name="`, and finally the last name.
    - **`return os;`**:
        - The function returns the output stream so that additional data can be output in a chained manner (e.g., `cout << p << " event"`).

#### The `main` Function

```cpp
int main() {
    string first_name, last_name, event;
    cin >> first_name >> last_name >> event;
    auto p = Person(first_name, last_name);
    cout << p << " " << event << endl;
    return 0;
}
```

- **Input**:
    ```cpp
    cin >> first_name >> last_name >> event;
    ```
    - The program reads three inputs: `first_name`, `last_name`, and `event` (e.g., "John", "Doe", "graduation").
  
- **Creating a `Person` Object**:
    ```cpp
    auto p = Person(first_name, last_name);
    ```
    - A `Person` object `p` is created using the `first_name` and `last_name` input values.

- **Output**:
    ```cpp
    cout << p << " " << event << endl;
    ```
    - This line prints the `Person` object using the overloaded `<<` operator, followed by the `event`.

#### Example

Suppose the input is:
```
John Doe graduation
```

- The program creates a `Person` object `p` with `first_name` "John" and `last_name` "Doe".
- It then outputs: 
  ```
  first_name=John,last_name=Doe graduation
  ```
  The `first_name` and `last_name` are formatted as `"first_name=John,last_name=Doe"`, and the event `"graduation"` is printed afterward.

### Summary

This code demonstrates how to overload the `<<` operator for a custom class (`Person`) to allow easy and consistent output of its data members. The overloaded operator enables the use of the `<<` operator to print the `Person` object with the desired format directly through `std::cout`.
