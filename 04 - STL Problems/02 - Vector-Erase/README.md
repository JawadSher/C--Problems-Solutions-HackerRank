<h1 align='center'>Vector - Erase</h1>

## Problem Statement

**Problem URL :** [Vector-Erase](https://www.hackerrank.com/challenges/vector-erase/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/8350b7b8-1db5-4a94-8722-2a466e900456)
![image](https://github.com/user-attachments/assets/737ba82c-183d-4e20-b0a2-89f66645fa2f)


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
        cin >> num;
        
        integers.push_back(num);
    }
    
    int erase_index;
    cin >> erase_index;
    integers.erase(integers.begin() +erase_index -1);
    
    int erase_from, erase_to;
    cin >> erase_from >> erase_to;
    
    integers.erase(integers.begin() +erase_from -1, integers.begin() +erase_to -1);
    
    cout<<integers.size()<<endl;
    for(int i = 0; i < integers.size(); i++){
        cout<<integers[i]<<" ";
    }
    return 0;
}

```

## Problem Solution Explanation
Here's a detailed line-by-line explanation of the C++ code:

```cpp
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
```

1. `#include <vector>`: This line includes the header file for the `vector` container, which allows us to use the `vector` class for dynamic arrays.
2. `#include <iostream>`: This line includes the header file for input and output streams, allowing us to use `cin` for input and `cout` for output.
3. `#include <algorithm>`: This line includes the header file for various algorithms, although it's not used in this specific code.
4. `using namespace std;`: This line allows us to use the standard library's features without prefixing them with `std::`.

```cpp
int main() {
    int n;
    cin >> n;
```

5. `int main() {`: This line marks the beginning of the `main` function, the entry point of the program.
6. `int n;`: This line declares an integer variable `n` to store the number of elements that will be input.
7. `cin >> n;`: This line reads an integer value from standard input (keyboard) and stores it in `n`.

```cpp
    vector<int> integers(0);
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        
        integers.push_back(num);
    }
```

8. `vector<int> integers(0);`: This line initializes an empty `vector` of integers named `integers`. The `0` in the constructor indicates that the initial size of the vector is zero.
9. `for(int i = 0; i < n; i++){`: This line starts a `for` loop that iterates `n` times, where `i` is the loop variable.
10. `int num;`: Inside the loop, an integer variable `num` is declared to store each input number.
11. `cin >> num;`: This line reads an integer value from standard input and stores it in `num`.
12. `integers.push_back(num);`: This line adds the value of `num` to the end of the `integers` vector.

```cpp
    int erase_index;
    cin >> erase_index;
    integers.erase(integers.begin() + erase_index - 1);
```

13. `int erase_index;`: This line declares an integer variable `erase_index` to store the index of the element to be removed from the vector.
14. `cin >> erase_index;`: This line reads an integer value from standard input and stores it in `erase_index`.
15. `integers.erase(integers.begin() + erase_index - 1);`: This line removes the element at position `erase_index - 1` from the `integers` vector. The `erase` function takes an iterator pointing to the position to remove, and `integers.begin() + erase_index - 1` gives this iterator.

```cpp
    int erase_from, erase_to;
    cin >> erase_from >> erase_to;
    
    integers.erase(integers.begin() + erase_from - 1, integers.begin() + erase_to - 1);
```

16. `int erase_from, erase_to;`: This line declares two integer variables `erase_from` and `erase_to` to specify a range of elements to remove from the vector.
17. `cin >> erase_from >> erase_to;`: This line reads two integer values from standard input and stores them in `erase_from` and `erase_to`.
18. `integers.erase(integers.begin() + erase_from - 1, integers.begin() + erase_to - 1);`: This line removes elements from the vector starting at position `erase_from - 1` to `erase_to - 1`. The `erase` function with two iterators removes the range of elements between these positions.

```cpp
    cout << integers.size() << endl;
    for(int i = 0; i < integers.size(); i++){
        cout << integers[i] << " ";
    }
    return 0;
}
```

19. `cout << integers.size() << endl;`: This line prints the size of the `integers` vector (i.e., the number of remaining elements) followed by a newline.
20. `for(int i = 0; i < integers.size(); i++){`: This line starts a `for` loop to iterate over each element in the `integers` vector.
21. `cout << integers[i] << " ";`: Inside the loop, this line prints each element of the `integers` vector followed by a space.
22. `return 0;`: This line indicates that the program finished successfully and returns `0` to the operating system.
23. `}`: This line marks the end of the `main` function.

### Summary
The program reads a list of integers from the input, removes specific elements based on given indices, and then outputs the remaining elements and their count.
