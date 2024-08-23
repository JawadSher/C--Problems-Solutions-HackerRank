<h1 align='center'>Maps - STL</h1>

## Problem Statement

**Problem URL :** [Maps-STL](https://www.hackerrank.com/challenges/cpp-maps/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/e8a89940-8f4d-433e-bd8c-de83554b8a18)
![image](https://github.com/user-attachments/assets/9c53109a-e1fe-48ac-a151-1a23bbf8cb57)
![image](https://github.com/user-attachments/assets/e0354364-33b4-45a7-a401-3f81569c6818)

## Problem Solution
```cpp
#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    map<string, int> Student_info;
    cin.ignore();

    for(int i = 0; i < Q; i++){
        int query_type;
        string stdnt_name;
        int stdnt_marks;
        
        cin >> query_type;
        
        if(query_type == 1){
            cin >> stdnt_name >> stdnt_marks;
            Student_info[stdnt_name] += stdnt_marks;
            
        }else if(query_type == 2){
            cin >> stdnt_name;
            Student_info.erase(stdnt_name);
            
        }else if(query_type == 3){
            cin >> stdnt_name;
            if(Student_info.find(stdnt_name) != Student_info.end()){
                cout<< Student_info[stdnt_name] <<endl;
            }else{
                cout<< 0 << endl;
            }

            
        }
    }

    return 0;
}
```

## Problem Solution Explanation

Let's go through the code step by step, explaining each part in detail:

```cpp
#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;
```

### Header Files:
- `#include <iostream>`: This header file is for input and output operations in C++ (e.g., `cin`, `cout`).
- `#include <map>`: This includes the `map` container from the C++ Standard Library, which allows you to store key-value pairs.
- `#include <algorithm>`: This header is included for standard algorithms, but it's not actually used in the code.
- `#include <sstream>`: This includes string stream functionality for manipulating strings, but it's not actually used in the code.

### The `main()` Function:

```cpp
int main() {
    int Q;
    cin >> Q;
```

- **`int Q;`**: Declares an integer `Q` which will store the number of queries.
- **`cin >> Q;`**: Reads the value of `Q` from standard input, representing the number of operations (or queries) that will be performed.

```cpp
    map<string, int> Student_info;
    cin.ignore();
```

- **`map<string, int> Student_info;`**: This creates a map called `Student_info` where the keys are `string` (student names) and the values are `int` (student marks).
- **`cin.ignore();`**: This ignores the newline character left in the input buffer after reading `Q` to ensure that the subsequent input operations are correctly read.

```cpp
    for(int i = 0; i < Q; i++){
        int query_type;
        string stdnt_name;
        int stdnt_marks;
        
        cin >> query_type;
```

- **`for(int i = 0; i < Q; i++)`**: This loop will iterate `Q` times, handling each query.
- **`int query_type;`**: Declares an integer `query_type` to store the type of query (1, 2, or 3).
- **`string stdnt_name; int stdnt_marks;`**: Declares variables to hold the student's name (`stdnt_name`) and marks (`stdnt_marks`).
- **`cin >> query_type;`**: Reads the `query_type` which dictates what operation to perform.

### Handling Each Query:

#### Query Type 1: Add Marks to a Student

```cpp
        if(query_type == 1){
            cin >> stdnt_name >> stdnt_marks;
            Student_info[stdnt_name] += stdnt_marks;
        }
```

- **`cin >> stdnt_name >> stdnt_marks;`**: Reads the student’s name and the marks to be added.
- **`Student_info[stdnt_name] += stdnt_marks;`**: 
  - `Student_info[stdnt_name]` accesses the current marks of the student in the map. 
  - `+= stdnt_marks` adds the given marks to the existing value. If the student is not already in the map, a new entry is created with the initial marks.

Example:
- **Input**: `1 John 30`
- **Action**: Adds 30 marks to "John". If "John" had no previous entry, it initializes "John" with 30 marks.

#### Query Type 2: Erase a Student’s Record

```cpp
        else if(query_type == 2){
            cin >> stdnt_name;
            Student_info.erase(stdnt_name);
        }
```

- **`cin >> stdnt_name;`**: Reads the student's name.
- **`Student_info.erase(stdnt_name);`**: Removes the entry for `stdnt_name` from the map.

Example:
- **Input**: `2 John`
- **Action**: Removes "John" from the map entirely.

#### Query Type 3: Print a Student’s Marks

```cpp
        else if(query_type == 3){
            cin >> stdnt_name;
            if(Student_info.find(stdnt_name) != Student_info.end()){
                cout<< Student_info[stdnt_name] <<endl;
            }else{
                cout<< 0 << endl;
            }
        }
```

- **`cin >> stdnt_name;`**: Reads the student’s name.
- **`Student_info.find(stdnt_name) != Student_info.end()`**: 
  - Checks if `stdnt_name` exists in the map.
  - `Student_info.find(stdnt_name)` returns an iterator to the element if found; otherwise, it returns `Student_info.end()`.
- **`cout << Student_info[stdnt_name] << endl;`**: If the student exists, print their marks.
- **`else { cout << 0 << endl; }`**: If the student doesn’t exist, print `0`.

Example:
- **Input**: `3 John`
- **Output**: Prints the marks of "John" if he exists, or `0` if he doesn’t.

### End of `main()` Function

```cpp
    return 0;
}
```

- **`return 0;`**: Ends the `main` function and returns `0`, indicating successful execution.

### Example Run:

Consider the following sequence of inputs:

```
5
1 John 30
1 Mary 20
3 John
2 Mary
3 Mary
```

- **Query 1**: Adds 30 marks to "John".
- **Query 2**: Adds 20 marks to "Mary".
- **Query 3**: Checks marks of "John" and prints `30`.
- **Query 4**: Erases "Mary".
- **Query 5**: Checks marks of "Mary" and prints `0` because "Mary" has been erased.

### Expected Output:

```
30
0
```

This output matches what you'd expect from the provided sequence of operations.
