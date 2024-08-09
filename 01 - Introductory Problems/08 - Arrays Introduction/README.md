<h1 align='center'>Arrays - Introduction</h1>

## Problem Statement

**Problem URL :** [Arrays Introduction](https://www.hackerrank.com/challenges/arrays-introduction/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/deee11af-91ea-4761-8de8-56d01e260a70)
![image](https://github.com/user-attachments/assets/f07b385b-796e-4df9-baab-99fde02316e3)

## Problem Solution
```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin>>N;
    
    int integers[N];

    for(int i = 0; i < N; i++){
        cin>>integers[i];
    }
    
    for(int i = N-1; i >= 0; i--){
        cout<<integers[i]<<' ';
    }    
    
    return 0;
}

```

## Problem Solution Explanation

Let’s break down the provided C++ code step by step:

1. **Header Inclusions**:
   ```cpp
   #include <cmath>
   #include <cstdio>
   #include <vector>
   #include <iostream>
   #include <algorithm>
   using namespace std;
   ```
   - **`#include <cmath>`**: Includes functions for mathematical operations (e.g., `sqrt`, `abs`). Not used in this code.
   - **`#include <cstdio>`**: Includes C-style input/output functions (e.g., `printf`, `scanf`). Not used in this code.
   - **`#include <vector>`**: Includes the `std::vector` container. Not used in this code.
   - **`#include <iostream>`**: Includes stream-based input/output (e.g., `cin`, `cout`). Used in this code for input and output.
   - **`#include <algorithm>`**: Includes algorithms (e.g., `sort`, `find`). Not used in this code.
   - **`using namespace std;`**: Allows the use of standard library names without the `std::` prefix (e.g., `cin` instead of `std::cin`).

2. **Main Function Declaration**:
   ```cpp
   int main() {
   ```
   - **`int main()`**: The entry point of the program. The execution starts here.

3. **Reading Input for Array Size**:
   ```cpp
   int N;
   cin >> N;
   ```
   - **`int N;`**: Declares an integer variable `N` to store the size of the array.
   - **`cin >> N;`**: Reads an integer from the standard input and stores it in `N`.

4. **Array Declaration**:
   ```cpp
   int integers[N];
   ```
   - **`int integers[N];`**: Declares an array named `integers` with `N` elements. This is a Variable Length Array (VLA), which is a feature supported in some compilers but not part of the standard C++ (C99 feature). It's safer and more portable to use `std::vector` in modern C++.

5. **Reading Array Elements**:
   ```cpp
   for(int i = 0; i < N; i++) {
       cin >> integers[i];
   }
   ```
   - **`for(int i = 0; i < N; i++)`**: A loop that iterates from `0` to `N-1`, inclusive.
   - **`cin >> integers[i];`**: Reads an integer from the standard input and stores it in the `i`-th element of the `integers` array.

6. **Printing Array Elements in Reverse Order**:
   ```cpp
   for(int i = N - 1; i >= 0; i--) {
       cout << integers[i] << ' ';
   }
   ```
   - **`for(int i = N - 1; i >= 0; i--)`**: A loop that starts from the last index (`N-1`) and decrements until it reaches `0`.
   - **`cout << integers[i] << ' ';`**: Prints each element of the `integers` array in reverse order followed by a space.

7. **Return Statement**:
   ```cpp
   return 0;
   ```
   - **`return 0;`**: Returns `0` to the operating system, indicating that the program executed successfully.

### Summary
1. **Header Files**: Include necessary libraries, though not all are used in this code.
2. **Main Function**:
   - Reads an integer `N` from the user, which determines the size of the array.
   - Declares an array `integers` with size `N`.
   - Reads `N` integers into the array.
   - Prints the array elements in reverse order, separated by spaces.
   - Ends with a successful return code.

### Important Notes
- **Variable Length Array (VLA)**: Using `int integers[N];` for dynamic size arrays is non-standard C++ and may not be supported by all compilers. For portability, consider using `std::vector<int>` instead.
- **Array Bounds**: The loop iterates safely within the bounds of the array, both for reading and printing.
