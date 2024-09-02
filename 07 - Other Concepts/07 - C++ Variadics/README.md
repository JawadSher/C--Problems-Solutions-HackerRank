<h1 align='center'>C++ - Variadics</h1>

## Problem Statement

**Problem URL :** [C++ Variadics](https://www.hackerrank.com/challenges/cpp-variadics/problem?isFullScreen=true)


![image](https://github.com/user-attachments/assets/98105bce-8b07-499a-bffa-6aefd68059d4)
![image](https://github.com/user-attachments/assets/5bc07dc9-fb76-4844-81c7-7cdd3691e592)

## Problem Solution
```cpp
#include <iostream>
using namespace std;

template <bool a> int reversed_binary_value() { return a; }

template <bool a, bool b, bool... d> int reversed_binary_value() {
  return (reversed_binary_value<b, d...>() << 1) + a;
}

template <int n, bool...digits>
struct CheckValues {
  	static void check(int x, int y)
  	{
    	CheckValues<n-1, 0, digits...>::check(x, y);
    	CheckValues<n-1, 1, digits...>::check(x, y);
  	}
};

template <bool...digits>
struct CheckValues<0, digits...> {
  	static void check(int x, int y)
  	{
    	int z = reversed_binary_value<digits...>();
    	std::cout << (z+64*y==x);
  	}
};

int main()
{
  	int t; std::cin >> t;

  	for (int i=0; i!=t; ++i) {
		int x, y;
    	cin >> x >> y;
    	CheckValues<6>::check(x, y);
    	cout << "\n";
  	}
}

```

## Problem Solution Explanation
Let's break down the code step by step:

### 1. Template Function `reversed_binary_value`

```cpp
template <bool a> 
int reversed_binary_value() { 
    return a; 
}
```

- This template function takes a single boolean template parameter `a`.
- It returns the integer value of `a`, which will be `1` if `a` is `true` and `0` if `a` is `false`.
- This acts as the base case for the recursion.

```cpp
template <bool a, bool b, bool... d> 
int reversed_binary_value() {
    return (reversed_binary_value<b, d...>() << 1) + a;
}
```

- This is the recursive version of `reversed_binary_value`.
- It takes multiple boolean template parameters: `a`, `b`, and a parameter pack `d`.
- The function recursively calls `reversed_binary_value` with the remaining parameters (`b, d...`), computes the value, shifts it left by one position (which is equivalent to multiplying by 2), and then adds `a`.
- This builds the integer value from the binary digits in reverse order.

### 2. Template Struct `CheckValues`

```cpp
template <int n, bool...digits>
struct CheckValues {
    static void check(int x, int y) {
        CheckValues<n-1, 0, digits...>::check(x, y);
        CheckValues<n-1, 1, digits...>::check(x, y);
    }
};
```

- This is a templated struct that recursively generates all possible binary numbers of length `n`.
- `n` is an integer template parameter that indicates the number of binary digits.
- `digits...` is a parameter pack of boolean values representing the binary digits.

#### `check` Function

- The `check` function is a static member function that performs the recursive generation.
- It calls itself twice, decrementing `n` each time:
  - Once adding `0` to the list of digits (`CheckValues<n-1, 0, digits...>::check(x, y)`).
  - Once adding `1` to the list of digits (`CheckValues<n-1, 1, digits...>::check(x, y)`).

### 3. Base Case for `CheckValues`

```cpp
template <bool...digits>
struct CheckValues<0, digits...> {
    static void check(int x, int y) {
        int z = reversed_binary_value<digits...>();
        std::cout << (z+64*y==x);
    }
};
```

- This is the base case of the `CheckValues` template struct, specialized for when `n = 0`.
- When `n` reaches `0`, all possible binary digits have been generated, and the function now processes the current set of digits.

#### `check` Function in Base Case

- `reversed_binary_value<digits...>()` is called to compute the integer value of the binary number formed by the `digits`.
- It then checks if this computed value (`z`) plus `64 * y` equals `x`.
- The result of this check (either `true` or `false`, which prints as `1` or `0` respectively) is printed to the output.

### 4. `main` Function

```cpp
int main()
{
    int t; 
    std::cin >> t;

    for (int i = 0; i != t; ++i) {
        int x, y;
        cin >> x >> y;
        CheckValues<6>::check(x, y);
        cout << "\n";
    }
}
```

- The `main` function reads in the number of test cases `t`.
- For each test case:
  - It reads two integers `x` and `y`.
  - Calls `CheckValues<6>::check(x, y)`, which checks all possible 6-bit binary numbers combined with `y`.
  - The result of each test case is printed on a new line.

### How the Code Works

1. **Input**: The program reads the number of test cases `t`, followed by pairs of integers `x` and `y`.
2. **Binary Combinations**: For each pair, the program generates all possible 6-bit binary numbers (`0` to `63`).
3. **Reverse Binary Value**: For each binary number, it computes the integer value considering the digits in reverse order.
4. **Check Condition**: It checks if `z + 64 * y == x` for each binary combination.
5. **Output**: The program outputs `1` for each combination that satisfies the condition, otherwise `0`.

### Example Walkthrough

Consider the input:

```
1
65 1
```

- The program will generate all possible 6-bit binary numbers and check if `z + 64 * y == x`.
- Here, for binary `000001`, `z = 1` and `1 + 64*1 = 65`, so the output would include a `1` when this combination is checked.
- For all other binary numbers, the condition would fail, resulting in `0` being printed for those. The output will be `1` followed by `63` zeroes.

In summary, this code checks for all possible combinations of a 6-bit reversed binary number added to `64 * y` and compares it to `x`, printing `1` if the condition is met.
