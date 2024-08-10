<h1 align='center'>String - Stream</h1>

## Problem Statement

**Problem URL :** [String Stream](https://www.hackerrank.com/challenges/c-tutorial-stringstream/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/7068ab82-ab8e-4fda-967b-be22254952d9)
![image](https://github.com/user-attachments/assets/a0e65821-4fdb-4fac-b7ab-cb5bea018f95)


## Problem Solution
```cpp
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	vector<int> integers;
    stringstream ss(str);
    
    char ch;
    int num;
    
    while(ss >> num){
        integers.push_back(num);
        ss >> ch;
    }
    return integers;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
```

## Problem Solution Explanation

The code reads a string of integers separated by commas from the user, parses these integers, and then prints each integer on a new line.


1. **Include Headers:**
   ```cpp
   #include <sstream>
   #include <vector>
   #include <iostream>
   ```
   - `#include <sstream>`: Includes the string stream library, which allows for input and output operations using strings.
   - `#include <vector>`: Includes the vector library, which provides the `std::vector` container for storing sequences of elements.
   - `#include <iostream>`: Includes the input-output stream library for standard input/output operations.

2. **Namespace Declaration:**
   ```cpp
   using namespace std;
   ```
   - This line allows you to use names from the `std` namespace directly without prefixing them with `std::`.

3. **Function Definition:**
   ```cpp
   vector<int> parseInts(string str) {
       vector<int> integers;
       stringstream ss(str);
       
       char ch;
       int num;
       
       while(ss >> num) {
           integers.push_back(num);
           ss >> ch;
       }
       return integers;
   }
   ```
   - **Function Name:** `parseInts`
   - **Input Parameter:** `string str` – A string containing integers separated by commas.
   - **Return Type:** `vector<int>` – A vector of integers.

   **Inside the function:**
   - `vector<int> integers;`: Creates a vector to store the integers.
   - `stringstream ss(str);`: Initializes a stringstream with the input string, which allows you to extract integers from the string.
   - `char ch; int num;`: Declares a character variable `ch` to handle commas and an integer variable `num` to store extracted integers.

   **Processing Loop:**
   - `while(ss >> num)`: Reads integers from the stringstream `ss` into the variable `num`. The loop continues until there are no more integers to read.
   - `integers.push_back(num);`: Adds the extracted integer `num` to the `integers` vector.
   - `ss >> ch;`: Reads and discards the next character (which should be a comma) from the stringstream.

   **Return Statement:**
   - `return integers;`: Returns the vector of integers.

4. **Main Function:**
   ```cpp
   int main() {
       string str;
       cin >> str;
       vector<int> integers = parseInts(str);
       for(int i = 0; i < integers.size(); i++) {
           cout << integers[i] << "\n";
       }
       
       return 0;
   }
   ```
   - **Variable Declaration:**
     - `string str;`: Declares a string variable to hold user input.
   
   - **Input Operation:**
     - `cin >> str;`: Reads a string from standard input into the variable `str`. In this case, the string should be a series of integers separated by commas (e.g., "1,2,3,4").
   
   - **Function Call:**
     - `vector<int> integers = parseInts(str);`: Calls the `parseInts` function with the input string and stores the returned vector of integers in `integers`.

   - **Output Operation:**
     - `for(int i = 0; i < integers.size(); i++)`: Loops through each element in the `integers` vector.
     - `cout << integers[i] << "\n";`: Prints each integer followed by a newline.

   - **Return Statement:**
     - `return 0;`: Returns 0 to indicate that the program finished successfully.

### Summary

- The `parseInts` function reads integers from a comma-separated string and returns them as a vector.
- The `main` function reads a string of integers from the user, parses them using `parseInts`, and prints each integer on a new line.

This program is useful for processing and displaying integer data from a formatted string input.
