<h1 align='center'>Sets - STL</h1>

## Problem Statement

**Problem URL :** [Sets-STL](https://www.hackerrank.com/challenges/cpp-sets/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/1a8d8c0d-3065-4e1b-8e4a-fc2e69d26827)
![image](https://github.com/user-attachments/assets/89b12eaf-f1c4-46a5-94af-42ac4b320cd4)


## Problem Solution
```cpp
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    
    set<int> s;
    for(int i = 0; i < n; i++){
        int query_type, query_value;
        
        cin >> query_type >> query_value;
        
        if(query_type == 1){
            s.insert(query_value);
        }else if(query_type == 2){
            s.erase(query_value);
        }else if(query_type == 3){
            set<int>:: iterator it = s.find(query_value);
            
            if(it != s.end()){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}
```

## Problem Solution Explanation
Here’s a detailed line-by-line explanation of the code with an example to illustrate its functionality:

```cpp
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
```

1. **Include Headers**:
   - `#include <iostream>`: Provides input and output functionality, including `cin` and `cout`.
   - `#include <set>`: Provides the `set` container, which stores unique elements in a sorted order.
   - `#include <algorithm>`: Provides algorithms for operations such as sorting, but it’s not used in this code.
   - `using namespace std;`: Allows you to use standard library functions and classes without prefixing them with `std::`.

```cpp
int main() {
    int n;
    cin >> n;
```

2. **Start `main` Function**:
   - `int main() {`: Defines the `main` function, the entry point of the program.
   - `int n;`: Declares an integer variable `n` to store the number of queries.
   - `cin >> n;`: Reads an integer from the standard input and stores it in `n`.

```cpp
    set<int> s;
    for(int i = 0; i < n; i++){
        int query_type, query_value;
        
        cin >> query_type >> query_value;
```

3. **Initialize Set and Process Queries**:
   - `set<int> s;`: Declares a set of integers named `s`. This set will be used to store unique integers and support efficient insertion, deletion, and lookup operations.
   - `for(int i = 0; i < n; i++){`: Starts a loop that will run `n` times to process each query.
   - `int query_type, query_value;`: Declares two integer variables `query_type` and `query_value` to store the type and value of each query.
   - `cin >> query_type >> query_value;`: Reads the query type and value from the standard input.

```cpp
        if(query_type == 1){
            s.insert(query_value);
        }else if(query_type == 2){
            s.erase(query_value);
        }else if(query_type == 3){
            set<int>::iterator it = s.find(query_value);
            
            if(it != s.end()){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
```

4. **Handle Queries**:
   - `if(query_type == 1){ s.insert(query_value); }`: If the `query_type` is 1, the code inserts `query_value` into the set `s`. Sets automatically handle duplicates, so this operation only adds the value if it is not already present.
   - `else if(query_type == 2){ s.erase(query_value); }`: If the `query_type` is 2, the code removes `query_value` from the set `s`. If the value is not in the set, this operation has no effect.
   - `else if(query_type == 3){`: If the `query_type` is 3, the code checks if `query_value` is present in the set.
     - `set<int>::iterator it = s.find(query_value);`: Uses the `find` method to search for `query_value` in the set. `it` will be an iterator pointing to the element if found, or `s.end()` if not found.
     - `if(it != s.end()){ cout << "Yes" << endl; }`: If `it` is not equal to `s.end()`, it means `query_value` is in the set, so it prints "Yes".
     - `else{ cout << "No" << endl; }`: If `it` equals `s.end()`, it means `query_value` is not in the set, so it prints "No".

5. **End of Program**:
   - `return 0;`: Ends the `main` function and returns `0` to indicate successful execution.

### Example

Let's walk through an example to understand how the code works:

#### Input:
```
5
1 10
1 20
3 10
2 10
3 10
```

#### Explanation:

1. `5`: Number of queries.
2. `1 10`: Insert `10` into the set. Set now contains `{10}`.
3. `1 20`: Insert `20` into the set. Set now contains `{10, 20}`.
4. `3 10`: Check if `10` is in the set. It is, so output "Yes".
5. `2 10`: Remove `10` from the set. Set now contains `{20}`.
6. `3 10`: Check if `10` is in the set. It is not, so output "No".

#### Output:
```
Yes
No
```

This output matches the expected results for the given queries.
