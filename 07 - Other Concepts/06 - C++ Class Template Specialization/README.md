<h1 align='center'>C++ - Class - Template - Specialization</h1>

## Problem Statement

**Problem URL :** [C++ Class Template Specialization](https://www.hackerrank.com/challenges/cpp-class-template-specialization/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/838053c4-2894-4ccb-94be-5f58c6a70568)
![image](https://github.com/user-attachments/assets/e6d29785-caad-46eb-8964-1c20b82f1e49)

## Problem Solution
```cpp
#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;
template<>
struct Traits<Fruit>{
    static string name(int index){
        switch(static_cast<Fruit>(index)){
            case Fruit::apple : return "apple";
            case Fruit:: orange: return "orange";
            case Fruit:: pear : return "pear";
            default: return "unknown";
        }
    }
};
template<>
struct Traits<Color>{
    static string name(int index){
        switch (static_cast<Color>(index)){
            case Color::red : return "red";
            case Color::green : return "green";
            case Color::orange : return "orange";
            default : return "unknown";
        }
    }
};

int main()
{
	int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}

```

## Problem Solution Explanation
This C++ program uses enums and template specialization to print the names of fruits and colors based on integer inputs. Let's break down the code line by line:

### Enum Declarations
```cpp
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };
```
- `enum class Fruit` and `enum class Color` define two scoped enumerations:
  - `Fruit`: It has three possible values—`apple`, `orange`, and `pear`.
  - `Color`: It has three possible values—`red`, `green`, and `orange`.
  
- Scoped enumerations (declared using `enum class`) are safer than unscoped enumerations because they don't implicitly convert to integers, preventing accidental misuse.

### Template Declaration
```cpp
template <typename T> struct Traits;
```
- A generic `Traits` template structure is declared but not defined here. This is a forward declaration. The actual specializations for `Fruit` and `Color` will be provided later.

### Specialization for `Fruit`
```cpp
template<>
struct Traits<Fruit>{
    static string name(int index){
        switch(static_cast<Fruit>(index)){
            case Fruit::apple : return "apple";
            case Fruit::orange : return "orange";
            case Fruit::pear : return "pear";
            default: return "unknown";
        }
    }
};
```
- This template specialization defines the `Traits` structure specifically for the `Fruit` enum.
- The `name` function:
  - Takes an integer `index` as an argument.
  - Uses `static_cast<Fruit>(index)` to cast the integer to the corresponding `Fruit` enum value.
  - The `switch` statement checks the cast value:
    - If the value corresponds to `Fruit::apple`, it returns the string `"apple"`.
    - Similarly, it returns `"orange"` or `"pear"` for the corresponding values.
    - If the `index` does not match any valid `Fruit` enum value, it returns `"unknown"`.

### Specialization for `Color`
```cpp
template<>
struct Traits<Color>{
    static string name(int index){
        switch (static_cast<Color>(index)){
            case Color::red : return "red";
            case Color::green : return "green";
            case Color::orange : return "orange";
            default : return "unknown";
        }
    }
};
```
- This is similar to the `Fruit` specialization, but it’s specialized for the `Color` enum.
- The `name` function works the same way:
  - It returns `"red"`, `"green"`, or `"orange"` based on the `index`.
  - If the `index` does not match a valid `Color` value, it returns `"unknown"`.

### Main Function
```cpp
int main()
{
    int t = 0; std::cin >> t;
    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
```
- **Input**:
  - The program reads an integer `t` from the user, representing the number of test cases.
  - For each test case, it reads two integers: `index1` and `index2`.
  
- **Output**:
  - `index1` is used to find the corresponding `Color` name by calling `Traits<Color>::name(index1)`.
  - `index2` is used to find the corresponding `Fruit` name by calling `Traits<Fruit>::name(index2)`.
  - Both names are printed with a space between them.
  
### Example Walkthrough

**Input**:
```
2
1 0
3 3
```

- `t = 2`: There are 2 test cases.
  
- **First Test Case**:
  - `index1 = 1` (corresponds to `Color::green`).
  - `index2 = 0` (corresponds to `Fruit::apple`).
  - Output: `"green apple"`

- **Second Test Case**:
  - `index1 = 3` (no corresponding `Color` value, so returns `"unknown"`).
  - `index2 = 3` (no corresponding `Fruit` value, so returns `"unknown"`).
  - Output: `"unknown unknown"`

**Output**:
```
green apple
unknown unknown
```

### Summary
- The program uses template specialization to handle different enum types (`Fruit` and `Color`) and map their integer indices to string names.
- It handles invalid indices by returning `"unknown"`.
- The program reads multiple test cases and outputs the corresponding names for `Color` and `Fruit` enums.
