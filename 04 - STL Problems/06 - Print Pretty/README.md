<h1 align='center'>Print - Pretty</h1>

## Problem Statement

**Problem URL :** [Print Pretty](https://www.hackerrank.com/challenges/prettyprint/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/8ecacfe5-e384-4f09-88cd-d19078167fc1)
![image](https://github.com/user-attachments/assets/b7407c55-aca6-46a3-aa49-d1c66994a36c)


## Problem Solution
```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    double A, B, C;
    
    for(int i = 0; i < t; i++){
        cin >> A >> B >> C;
        
        long long truncated = static_cast<long long>(A);
        cout<<"0x"<<hex<<nouppercase<<truncated<<endl;
        
        cout<<setw(15)<<setfill('_')<<showpos<<fixed<<setprecision(2)<<B<<endl;
        
        cout<<noshowpos<<scientific<<uppercase<<setprecision(9)<<C<<endl;
    } 
    return 0;
}

```


## Problem Solution Explanation
Let's walk through the code step by step and explain each part in detail, including what it does and how it works.

```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
```

### Header Files:
- `#include <cmath>`: Includes mathematical functions like `sqrt`, `pow`, etc.
- `#include <cstdio>`: Includes functions for input and output, similar to `iostream` but more C-style.
- `#include <vector>`: Includes the `vector` container from the C++ Standard Library.
- `#include <iostream>`: For input (`cin`) and output (`cout`).
- `#include <algorithm>`: Includes algorithms like `sort`, `find`, etc.
- `#include <bits/stdc++.h>`: A shortcut to include almost all C++ standard headers.

### The `main()` Function:

```cpp
int main() {
    int t;
    cin >> t;
```

- **`int t;`**: Declares an integer `t` which will store the number of test cases.
- **`cin >> t;`**: Reads the value of `t` from the standard input, representing the number of test cases.

```cpp
    double A, B, C;
```

- **`double A, B, C;`**: Declares three `double` variables `A`, `B`, and `C` which will store the values for each test case.

### Loop through Test Cases:

```cpp
    for(int i = 0; i < t; i++){
        cin >> A >> B >> C;
```

- **`for(int i = 0; i < t; i++)`**: A loop that iterates `t` times, once for each test case.
- **`cin >> A >> B >> C;`**: Reads three double values `A`, `B`, and `C` from the input for each test case.

### Format and Output:

#### First Line of Output: Hexadecimal Representation of `A`

```cpp
        long long truncated = static_cast<long long>(A);
        cout << "0x" << hex << nouppercase << truncated << endl;
```

- **`long long truncated = static_cast<long long>(A);`**:
  - This line converts the value of `A` from a `double` to a `long long`, effectively truncating any decimal part.
  - For example, if `A = 123.456`, `truncated` will be `123`.
  
- **`cout << "0x" << hex << nouppercase << truncated << endl;`**:
  - `"0x"`: Prints `0x` to indicate that the number is in hexadecimal format.
  - `hex`: Converts the following number to hexadecimal format.
  - `nouppercase`: Ensures that the hexadecimal letters (`a-f`) are printed in lowercase.
  - `truncated`: The truncated integer value of `A`.
  - `endl`: Ends the line and moves to the next line.
  
  **Example**:
  - If `A = 255.123`, `truncated` is `255`.
  - The output will be: `0xff`

#### Second Line of Output: Formatted `B`

```cpp
        cout << setw(15) << setfill('_') << showpos << fixed << setprecision(2) << B << endl;
```

- **`setw(15)`**: Sets the width of the output field to 15 characters. If `B` is shorter, it will be padded.
- **`setfill('_')`**: Pads the output with underscores (`_`) instead of spaces.
- **`showpos`**: Ensures that a positive number is prefixed with a `+` sign.
- **`fixed`**: Outputs the number in fixed-point notation.
- **`setprecision(2)`**: Sets the precision to 2 decimal places.
- **`B`**: The value of `B` is printed.
- **`endl`**: Ends the line.

**Example**:
- If `B = 123.456`, the output will be: `+123.46______` (with `+` sign and two decimal places, and padded to 15 characters).

#### Third Line of Output: Scientific Notation of `C`

```cpp
        cout << noshowpos << scientific << uppercase << setprecision(9) << C << endl;
```

- **`noshowpos`**: Disables the `+` sign for positive numbers.
- **`scientific`**: Outputs the number in scientific notation.
- **`uppercase`**: Ensures that the exponent `e` in scientific notation is printed in uppercase `E`.
- **`setprecision(9)`**: Sets the precision to 9 significant digits.
- **`C`**: The value of `C` is printed.
- **`endl`**: Ends the line.

**Example**:
- If `C = 0.000123456789`, the output will be `1.234567890E-04` (in scientific notation with nine significant digits).

### Example Execution:
Let's assume `t = 1` and the input values are `A = 255.75`, `B = 123.456`, and `C = 0.000123456789`.

- **For `A = 255.75`**:
  - `truncated = 255`
  - Output: `0xff`

- **For `B = 123.456`**:
  - Output: `+123.46________` (with padding to 15 characters)

- **For `C = 0.000123456789`**:
  - Output: `1.234567890E-04`

**Final Output**:
```
0xff
+123.46________
1.234567890E-04
```

This output is formatted according to the instructions given in the problem and showcases different ways to manipulate and format data in C++.
