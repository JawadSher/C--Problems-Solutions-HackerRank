<h1 align='center'>Structs</h1>

## Problem Statement

**Problem URL :** [Structs](https://www.hackerrank.com/challenges/c-tutorial-struct/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/b82f88c7-c33f-422d-8deb-2b01b2391bb3)
![image](https://github.com/user-attachments/assets/02b906a2-1181-4853-83ef-bc946d25a2e3)

## Problem Solution
```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Student{
    int age;
    string first_name;
    string last_name;
    int standard;
};

int main() {
    Student st;
    
    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;
    
    return 0;
}
```

## Problem Solution Explanation

1. **Include Statements:**
   ```cpp
   #include <cmath>
   #include <cstdio>
   #include <vector>
   #include <iostream>
   #include <algorithm>
   ```
   These `#include` directives are bringing in standard C++ libraries. Although some of them are not used in this specific program (`<cmath>`, `<cstdio>`, `<vector>`, `<algorithm>`), they are often included in C++ programs to perform various tasks like mathematical operations, input/output functions, working with vectors, and performing algorithms. The most relevant here is `<iostream>`, which allows the program to handle input and output operations.

2. **Struct Definition:**
   ```cpp
   struct Student{
       int age;
       string first_name;
       string last_name;
       int standard;
   };
   ```
   Here, a `struct` named `Student` is defined. It contains four members:
   - `int age;` - to store the student's age.
   - `string first_name;` - to store the student's first name.
   - `string last_name;` - to store the student's last name.
   - `int standard;` - to store the student's grade or standard in school.

3. **Main Function:**
   ```cpp
   int main() {
       Student st;
       
       cin >> st.age >> st.first_name >> st.last_name >> st.standard;
       cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;
       
       return 0;
   }
   ```
   - `Student st;` declares a variable `st` of type `Student`. This variable will hold the information about one student.
   - `cin >> st.age >> st.first_name >> st.last_name >> st.standard;` reads four inputs from the user and assigns them to the corresponding members of the `st` struct. The user is expected to enter these details one after another, separated by spaces.
   - `cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;` outputs the information stored in the `st` struct, displaying the student's age, first name, last name, and standard separated by spaces.
   - `return 0;` ends the main function, indicating that the program has successfully executed.

### Example

Let's say the user provides the following input:

```
15 John Doe 10
```

- `cin >> st.age` reads `15` and assigns it to `st.age`.
- `cin >> st.first_name` reads `John` and assigns it to `st.first_name`.
- `cin >> st.last_name` reads `Doe` and assigns it to `st.last_name`.
- `cin >> st.standard` reads `10` and assigns it to `st.standard`.

Then, the program will output:

```
15 John Doe 10
```

### Summary

This program is a simple example of how to use a `struct` to group related data together in C++. It reads student information from the user, stores it in a `Student` struct, and then outputs that information back to the user.
