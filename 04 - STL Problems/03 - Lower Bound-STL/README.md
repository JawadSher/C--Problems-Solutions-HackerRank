<h1 align='center'>Lower - Bound - STL</h1>

## Problem Statement

**Problem URL :** [Lower Bound-STL](https://www.hackerrank.com/challenges/cpp-lower-bound/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/f884a886-821d-4b60-ad27-3ab8a8ac59d7)
![image](https://github.com/user-attachments/assets/f8a4420f-088e-44fb-9ed5-8cee7d9a48d4)


## Problem Solution
```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    
    vector<int> sorted_nums(0);
    
    for(int i=0; i < n; i++){
        int num;
        cin >> num;
        sorted_nums.push_back(num);
    } 
    
    int num_queries;
    cin >> num_queries;
    
    for(int i=0; i < num_queries; i++){
        int num;
        cin>> num;
        vector<int>::iterator x;
        
        x = lower_bound(sorted_nums.begin(), sorted_nums.end(), num);
        int index = x - sorted_nums.begin();
        
        if(index < sorted_nums.size() && sorted_nums[index] == num){
            cout<<"Yes"<<" "<<index+1<<endl;
        }else{
            cout<<"No"<<" "<<index+1<<endl;
        }
        
    }
    return 0;
}

```

## Problem Solution Explanation

Here’s a detailed line-by-line explanation of the provided C++ code:

```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
```

1. `#include <cmath>`: Includes the C++ header for mathematical functions. It’s not used in this code but is included here, possibly for other purposes.
2. `#include <cstdio>`: Includes the C++ header for C-style input/output functions. It’s not used in this code.
3. `#include <vector>`: Includes the C++ header for the `vector` container, which is used to store dynamic arrays.
4. `#include <iostream>`: Includes the C++ header for input and output stream operations, such as `cin` and `cout`.
5. `#include <algorithm>`: Includes the C++ header for various algorithms, including `lower_bound`.
6. `using namespace std;`: Allows you to use standard library features without prefixing them with `std::`.

```cpp
int main() {
    int n;
    cin >> n;
```

7. `int main() {`: Begins the `main` function, the entry point of the program.
8. `int n;`: Declares an integer variable `n` to store the number of elements in the vector.
9. `cin >> n;`: Reads an integer from standard input and stores it in `n`.

```cpp
    vector<int> sorted_nums(0);
    
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        sorted_nums.push_back(num);
    } 
```

10. `vector<int> sorted_nums(0);`: Initializes an empty vector of integers named `sorted_nums`. The `0` indicates that the vector starts with zero elements.
11. `for(int i = 0; i < n; i++){`: Starts a loop that will run `n` times to read the elements into the vector.
12. `int num;`: Declares an integer variable `num` to store each input number.
13. `cin >> num;`: Reads an integer from standard input and stores it in `num`.
14. `sorted_nums.push_back(num);`: Adds the value of `num` to the end of the `sorted_nums` vector.

```cpp
    int num_queries;
    cin >> num_queries;
```

15. `int num_queries;`: Declares an integer variable `num_queries` to store the number of queries.
16. `cin >> num_queries;`: Reads an integer from standard input and stores it in `num_queries`.

```cpp
    for(int i = 0; i < num_queries; i++){
        int num;
        cin >> num;
        vector<int>::iterator x;
        
        x = lower_bound(sorted_nums.begin(), sorted_nums.end(), num);
        int index = x - sorted_nums.begin();
        
        if(index < sorted_nums.size() && sorted_nums[index] == num){
            cout << "Yes" << " " << index + 1 << endl;
        } else {
            cout << "No" << " " << index + 1 << endl;
        }
    }
```

17. `for(int i = 0; i < num_queries; i++){`: Starts a loop that will run `num_queries` times to process each query.
18. `int num;`: Declares an integer variable `num` to store the number for each query.
19. `cin >> num;`: Reads an integer from standard input and stores it in `num`.
20. `vector<int>::iterator x;`: Declares an iterator `x` for the `vector<int>`.
21. `x = lower_bound(sorted_nums.begin(), sorted_nums.end(), num);`: Uses `lower_bound` to find the first position in `sorted_nums` where `num` can be inserted while maintaining sorted order. `x` points to this position.
22. `int index = x - sorted_nums.begin();`: Calculates the index of the element pointed to by `x` by subtracting the beginning iterator from `x`.
23. `if(index < sorted_nums.size() && sorted_nums[index] == num){`: Checks if the index is within bounds and if the element at that index equals `num`.
24. `cout << "Yes" << " " << index + 1 << endl;`: If the condition is true, prints "Yes" followed by the 1-based index of the element, then moves to a new line.
25. `else { cout << "No" << " " << index + 1 << endl; }`: If the condition is false, prints "No" followed by the 1-based index of the element, then moves to a new line.

```cpp
    return 0;
}
```

26. `return 0;`: Ends the `main` function and returns `0` to indicate successful execution.

### Summary

1. **Reading Input**: The program reads a list of integers and stores them in a vector.
2. **Processing Queries**: For each query, it uses `lower_bound` to find the insertion point of the queried number in the sorted vector. It checks if the number exists and prints the result along with its 1-based index.
