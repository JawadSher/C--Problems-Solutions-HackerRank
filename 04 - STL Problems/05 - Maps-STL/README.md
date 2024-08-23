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

```cpp
#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    int Q;
    cin >> Q;
```

**Header Files:**

- `iostream`: Provides input and output stream functionality.
- `map`: Defines the `map` container for storing key-value pairs.
- `algorithm`: Offers generic algorithms for various data structures (not used in this code).
- `sstream`: Provides string stream classes for converting strings to other data types (not used in this code).

**Main Function:**

- `Q`: Stores the number of queries to be processed.

```cpp
map<string, int> Student_info;
cin.ignore();
```

- `Student_info`: A `map` to store student names and their corresponding total marks.
- `cin.ignore()`: Discards any newline character in the input stream.

```cpp
for(int i = 0; i < Q; i++){
    int query_type;
    string stdnt_name;
    int stdnt_marks;
    
    cin >> query_type;
```

- Iterates `Q` times to process each query.
- `query_type`: Stores the type of query (1, 2, or 3).
- `stdnt_name`: Stores the student's name.
- `stdnt_marks`: Stores the student's marks.

```cpp
if(query_type == 1){
    cin >> stdnt_name >> stdnt_marks;
    Student_info[stdnt_name] += stdnt_marks;
}
```

- **Query 1: Add marks to a student**
  - Reads the student's name and marks.
  - Updates the student's total marks in the `Student_info` map.

  **Example:**
  - Input: `1 Alice 85`
  - Adds 85 marks to Alice's total.

```cpp
else if(query_type == 2){
    cin >> stdnt_name;
    Student_info.erase(stdnt_name);
}
```

- **Query 2: Remove a student**
  - Reads the student's name.
  - Removes the student's entry from the `Student_info` map.

  **Example:**
  - Input: `2 Bob`
  - Removes Bob's record.

```cpp
else if(query_type == 3){
    cin >> stdnt_name;
    if(Student_info.find(stdnt_name) != Student_info.end()){
        cout << Student_info[stdnt_name] << endl;
    } else {
        cout << 0 << endl;
    }
}
```

- **Query 3: Get a student's total marks**
  - Reads the student's name.
  - Prints the student's total marks if they exist.
  - Prints 0 if the student is not found.

  **Example:**
  - Input: `3 Carol`
  - If Carol's total marks are 150, the output will be: `150`.
  - If Carol is not found, the output will be: `0`.

```cpp
return 0;
```

- Returns 0 to indicate successful execution.
