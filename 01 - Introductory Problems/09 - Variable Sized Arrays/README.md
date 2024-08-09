<h1 align='center'>Variable - Sized - Arrays</h1>

## Problem Statement

**Problem URL :** [Variable Sized Arrays](https://www.hackerrank.com/challenges/variable-sized-arrays/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/58b3d0e7-9365-44db-a129-ffd6c4d0eb07)
![image](https://github.com/user-attachments/assets/4257f70e-5443-491d-bb72-014122d20aa2)
![image](https://github.com/user-attachments/assets/4ae711b5-a439-4794-8c40-dc713a576368)

## Problem Explanation
Imagine you have a list where each item is a separate list of numbers. 

1. **Main List**:
   - This main list contains several smaller lists (arrays). 
   - Each of these smaller lists can have a different number of elements.

2. **Queries**:
   - You will be given several questions (queries). 
   - Each question asks for a specific number from one of these smaller lists.

Your task is to respond to each query by providing the number from the smaller list as specified by the query.

### How to Solve the Problem for Beginners

1. **Understand the Input**:
   - First, you need to know how many smaller lists (arrays) you have and how many queries you will handle.
   - Next, for each smaller list, read how many numbers it contains and then read those numbers.

2. **Handle Queries**:
   - For each query, find the specific smaller list and the index in that list.
   - Output the number found at that index.

## Problem Solution
```cpp
#include<iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){

   int n, q;
   cin>> n >> q;
   
   vector<int> array[n];
   
   for(int i = 0; i < n; i++){
       int k;
       cin>>k;
       
       for(int j = 0; j < k; j++){
           int l;
           cin>>l;
           array[i].push_back(l);
       }
   }
   
   for(int i = 0; i < q; i++){
       int m, n;
       cin>> m >> n;
       
       cout<<array[m].at(n)<<endl;
   }
    return 0;
}
```

## Problem Solution Explanation

Let's go through the code line by line to understand how it solves the problem:

```cpp
#include<iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
```
- **`#include<iostream>`**: Includes the standard input-output stream library to use `cin` and `cout`.
- **`#include <cmath>`**: Includes mathematical functions; not used here.
- **`#include <cstdio>`**: Includes C-style input/output; not used here.
- **`#include <vector>`**: Includes the vector container from the Standard Template Library (STL).
- **`#include <algorithm>`**: Includes algorithms like `sort`; not used here.
- **`using namespace std;`**: Allows direct use of standard library names (e.g., `cout`, `cin`).

```cpp
    int n, q;
    cin >> n >> q;
```
- **`int n, q;`**: Declares two integer variables, `n` (number of inner lists) and `q` (number of queries).
- **`cin >> n >> q;`**: Reads values for `n` and `q` from the input.

```cpp
    vector<int> array[n];
```
- **`vector<int> array[n];`**: Creates an array of `n` vectors (each vector can store a dynamic number of integers). Each vector will represent an inner list.

```cpp
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        
        for(int j = 0; j < k; j++) {
            int l;
            cin >> l;
            array[i].push_back(l);
        }
    }
```
- **`for(int i = 0; i < n; i++)`**: Loops through each inner list.
  - **`int k;`**: Declares an integer `k` to store the number of elements in the current inner list.
  - **`cin >> k;`**: Reads the number of elements for the current inner list.
  - **`for(int j = 0; j < k; j++)`**: Loops through the elements of the current inner list.
    - **`int l;`**: Declares an integer `l` to store each element.
    - **`cin >> l;`**: Reads an element and stores it in `l`.
    - **`array[i].push_back(l);`**: Adds the element `l` to the `i`-th vector (inner list).

```cpp
    for(int i = 0; i < q; i++) {
        int m, n;
        cin >> m >> n;
        
        cout << array[m].at(n) << endl;
    }
```
- **`for(int i = 0; i < q; i++)`**: Loops through each query.
  - **`int m, n;`**: Declares two integers, `m` (index of the inner list) and `n` (index within that inner list).
  - **`cin >> m >> n;`**: Reads the indices for the current query.
  - **`cout << array[m].at(n) << endl;`**: Prints the value at index `n` from the `m`-th vector (inner list) followed by a newline.

```cpp
    return 0;
}
```
- **`return 0;`**: Returns `0` to indicate that the program has finished successfully.

### Summary

1. **Input Reading**:
   - Read the number of inner lists and the number of queries.
   - Read each inner list's size and its elements.
   
2. **Processing Queries**:
   - For each query, retrieve and print the value from the specified inner list and index.

This approach uses vectors to handle dynamic sizes and simplifies accessing elements by their indices.
