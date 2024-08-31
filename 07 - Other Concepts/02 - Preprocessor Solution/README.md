<h1 align='center'>Preprocessor - Solution</h1>

## Problem Statement

**Problem URL :** [Preprocessor Solution](https://www.hackerrank.com/challenges/preprocessor-solution/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/c425e22b-a630-415c-a968-5fd0de84b58e)
![image](https://github.com/user-attachments/assets/c742ff3f-90f9-4b05-bf73-ff11a7d2952a)

## Problem Explanation
Preprocessor directives are lines in your code that are processed before the actual compilation begins. They are used for tasks like defining constants, including files, and conditional compilation. Here’s a breakdown of the directives used in your code with examples:

1. **`#define`**: Used to create macros, which are simple text replacements.
   - **Example**: 
     ```cpp
     #define PI 3.14159
     ```
     This replaces every occurrence of `PI` in the code with `3.14159`.

2. **`#include`**: Used to include the contents of a file into another file. This is commonly used to include header files.
   - **Example**: 
     ```cpp
     #include <iostream>
     ```
     This includes the contents of the iostream library, which provides functionalities for input and output operations.

3. **`#if` / `#ifdef` / `#ifndef`**: Used for conditional compilation. They check whether a macro is defined or not.
   - **Example**:
     ```cpp
     #ifdef DEBUG
     cout << "Debug mode is on";
     #endif
     ```
     This will include the debug message only if `DEBUG` is defined.

4. **`#error`**: Generates a compilation error with a custom message if the condition is true.
   - **Example**:
     ```cpp
     #ifndef PI
     #error "PI is not defined"
     #endif
     ```
     This will cause a compilation error if `PI` is not defined.
## Problem Solution
```cpp

// Define preprocessor macros before including iostream
#define toStr(x) #x
#define io(v) cin>>v 
#define INF 10000000000
#define foreach(v, i) for(int i = 0; i < v.size(); i++)
#define subtract(a, b) a - b
#define FUNCTION(name, op) void name(int &a, int b) { if (b op a) a = b; }
#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;
	return 0;

}
```

## Problem Solution Explanation

Here’s a detailed explanation of each part of your code:

1. **Macro Definitions**

   ```cpp
   #define toStr(x) #x
   #define io(v) cin >> v 
   #define INF 10000000000
   #define foreach(v, i) for(int i = 0; i < v.size(); i++)
   #define subtract(a, b) a - b
   #define FUNCTION(name, op) void name(int &a, int b) { if (b op a) a = b; }
   ```

   - **`#define toStr(x) #x`**: Defines a macro `toStr` that converts the argument `x` to a string literal. For example, `toStr(Result =) ` will expand to `"Result ="`.
   
   - **`#define io(v) cin >> v`**: Defines a macro `io` that reads a value into `v` using `cin`. For instance, `io(v[i])` will be expanded to `cin >> v[i]`.

   - **`#define INF 10000000000`**: Defines `INF` as a large constant value used to represent a very large number (infinity).

   - **`#define foreach(v, i) for(int i = 0; i < v.size(); i++)`**: Defines a macro `foreach` that iterates over a vector `v` with index `i`. This is essentially a shorthand for the standard for-loop.

   - **`#define subtract(a, b) a - b`**: Defines a macro `subtract` to subtract `b` from `a`. However, this macro is not used in the code.

   - **`#define FUNCTION(name, op) void name(int &a, int b) { if (b op a) a = b; }`**: Defines a macro `FUNCTION` to create a function that updates `a` based on a comparison operation `op` with `b`. For example, `FUNCTION(minimum, <)` creates a `minimum` function that updates `a` to the smaller of `a` and `b`.

2. **Include Headers**

   ```cpp
   #include <iostream>
   #include <vector>
   using namespace std;
   ```

   - **`#include <iostream>`**: Includes the iostream library for input and output operations.
   - **`#include <vector>`**: Includes the vector library for using the `vector` container.
   - **`using namespace std;`**: Allows you to use standard library names without prefixing them with `std::`.

3. **Preprocessor Check**

   ```cpp
   #if !defined toStr || !defined io || !defined FUNCTION || !defined INF
   #error Missing preprocessor definitions
   #endif
   ```

   - This checks if any of the macros `toStr`, `io`, `FUNCTION`, or `INF` are not defined. If any are missing, it will trigger a compilation error with the message "Missing preprocessor definitions".

4. **Function Definitions**

   ```cpp
   FUNCTION(minimum, <)
   FUNCTION(maximum, >)
   ```

   - **`FUNCTION(minimum, <)`**: Expands to a function `minimum` that sets `a` to the smaller value between `a` and `b`.
   - **`FUNCTION(maximum, >)`**: Expands to a function `maximum` that sets `a` to the larger value between `a` and `b`.

5. **Main Function**

   ```cpp
   int main(){
       int n; 
       cin >> n;
       vector<int> v(n);

       foreach(v, i) {
           io(v[i]);
       }

       int mn = INF;
       int mx = -INF;

       foreach(v, i) {
           minimum(mn, v[i]);
           maximum(mx, v[i]);
       }

       int ans = mx - mn;
       cout << toStr(Result =) << ' ' << ans;
       return 0;
   }
   ```

   - **`int n; cin >> n;`**: Reads the number of elements `n` from the input.
   - **`vector<int> v(n);`**: Creates a vector `v` of size `n`.
   - **`foreach(v, i) { io(v[i]); }`**: Uses the `foreach` macro to iterate over the vector and read each element into it.
   - **`int mn = INF; int mx = -INF;`**: Initializes `mn` to a very large value (`INF`) and `mx` to a very small value (`-INF`).
   - **`foreach(v, i) { minimum(mn, v[i]); maximum(mx, v[i]); }`**: Updates `mn` and `mx` with the minimum and maximum values from the vector.
   - **`int ans = mx - mn;`**: Calculates the difference between the maximum and minimum values.
   - **`cout << toStr(Result =) << ' ' << ans;`**: Prints the result with the label "Result =".

This explanation should clarify how each part of your code works and how preprocessor directives play a role in its functionality.
