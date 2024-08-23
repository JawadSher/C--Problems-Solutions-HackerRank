<h1 align='center'>Vector - Sort</h1>

## Problem Statement

**Problem URL :** [Vector-Sort](https://www.hackerrank.com/challenges/vector-sort/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/6698eba2-5d0d-43f0-85a6-a272695c8911)
![image](https://github.com/user-attachments/assets/fb55ee8b-a548-4d5d-a44a-c4d0ebacdbfd)

## Problem Solution
```cpp
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    
    vector<int> integers(0);
    for(int i = 0; i < n; i++){
        int num;
        cin>> num;
        
        integers.push_back(num);
    }
    sort(integers.begin(), integers.end());
        
    for(int i = 0; i < integers.size(); i++){
        cout<<integers[i]<<" ";
    }
    return 0;
}

```

## Problem Solution Explanation
Here's a detailed line-by-line explanation of the given C++ code:

```cpp
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
```
- `#include <vector>`: Includes the `vector` library, which provides the `std::vector` container to store a dynamic array.
- `#include <iostream>`: Includes the `iostream` library, which provides functionalities for input and output operations (e.g., `cin` and `cout`).
- `#include <algorithm>`: Includes the `algorithm` library, which provides various algorithms like `sort` for use with containers such as `vector`.
- `using namespace std;`: Allows the use of names from the `std` namespace without needing to prefix them with `std::`. For example, you can use `cout` instead of `std::cout`.

```cpp
int main() {
```
- This is the main function where the execution of the program begins. The `int` before `main()` indicates that the function will return an integer.

```cpp
    int n;
    cin >> n;
```
- `int n;`: Declares an integer variable `n` to store the number of elements to be input.
- `cin >> n;`: Reads an integer from the standard input (usually the keyboard) and stores it in the variable `n`.

```cpp
    vector<int> integers(0);
```
- `vector<int> integers(0);`: Declares a vector of integers named `integers`. The `(0)` indicates that the vector is initially empty and has a size of 0.

```cpp
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        integers.push_back(num);
    }
```
- `for(int i = 0; i < n; i++)`: A `for` loop that iterates `n` times to input `n` integers.
  - `int num;`: Declares a temporary integer variable `num` to store each input integer.
  - `cin >> num;`: Reads an integer from the standard input and stores it in `num`.
  - `integers.push_back(num);`: Adds the integer `num` to the end of the `integers` vector.

```cpp
    sort(integers.begin(), integers.end());
```
- `sort(integers.begin(), integers.end());`: Sorts the elements of the `integers` vector in ascending order. `integers.begin()` and `integers.end()` are iterators that specify the range of elements to be sorted.

```cpp
    for(int i = 0; i < integers.size(); i++){
        cout << integers[i] << " ";
    }
```
- `for(int i = 0; i < integers.size(); i++)`: A `for` loop that iterates through each element of the `integers` vector.
  - `cout << integers[i] << " ";`: Outputs the current element of the vector followed by a space to the standard output.

```cpp
    return 0;
}
```
- `return 0;`: Returns 0 from the `main` function, indicating that the program has executed successfully.

In summary, this program reads `n` integers from the user, stores them in a vector, sorts the vector in ascending order, and then prints the sorted integers.
