<h1 align='center'>Exceptional Server</h1>

## Problem Statement

**Problem URL :** [Exceptional Server](https://www.hackerrank.com/challenges/exceptional-server/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/49f862f5-d088-43da-b486-5fc1415bd3fb)
![image](https://github.com/user-attachments/assets/01355670-c76b-48b8-a184-10efc1b08614)


## Problem Solution
```cpp
#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
using namespace std;

class Server {
private:
	static int load;
public:
	static int compute(long long A, long long B) {
		load += 1;
		if(A < 0) {
			throw std::invalid_argument("A is negative");
		}
		vector<int> v(A, 0);
		int real = -1, cmplx = sqrt(-1);
		if(B == 0) throw 0;
		real = (A/B)*real;
		int ans = v.at(B);
		return real + A - B*ans;
	}
	static int getLoad() {
		return load;
	}
};
int Server::load = 0;

int main() {
	int T; cin >> T;
	while(T--) {
		long long A, B;
		cin >> A >> B;
        
        try{
            cout<<Server::compute(A, B)<<endl;
        }catch(bad_alloc& error){
            cout<<"Not enough memory"<<endl;
        }catch(exception& error){
            cout<<"Exception: "<<error.what()<<endl;
        }catch(...){
            cout<<"Other Exception"<<endl;
        }
        
    
	}
	cout << Server::getLoad() << endl;
	return 0;
}
```

## Problem Solution Explanation
Let's break down the code line by line to understand its functionality.

```cpp
#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
using namespace std;
```
- **`#include <iostream>`**: Includes the standard input-output stream library, allowing the use of `cin` and `cout`.
- **`#include <exception>`**: Includes the base exception class for handling exceptions.
- **`#include <string>`**: Includes the string library for manipulating strings.
- **`#include <stdexcept>`**: Includes standard exception classes like `invalid_argument` and `bad_alloc`.
- **`#include <vector>`**: Includes the vector library, which allows the use of dynamic arrays (vectors).
- **`#include <cmath>`**: Includes the math library, which provides mathematical functions like `sqrt`.
- **`using namespace std;`**: This allows us to use standard library classes and functions (like `cout`, `cin`, `vector`, etc.) without needing to prefix them with `std::`.

```cpp
class Server {
private:
	static int load;
```
- **`class Server`**: Defines a class named `Server`.
- **`private:`**: Specifies that the following members are private, meaning they are only accessible within the class.
- **`static int load;`**: Declares a static integer member `load`, which tracks the server's load. Being `static`, this variable is shared across all instances of the `Server` class.

```cpp
public:
	static int compute(long long A, long long B) {
		load += 1;
```
- **`public:`**: Specifies that the following members are public and can be accessed from outside the class.
- **`static int compute(long long A, long long B)`**: Declares a static method `compute` that takes two `long long` integers `A` and `B` as input parameters. It returns an integer result.
- **`load += 1;`**: Increments the `load` variable by 1 each time the `compute` method is called, simulating an increase in the server's workload.

```cpp
		if(A < 0) {
			throw std::invalid_argument("A is negative");
		}
```
- **`if(A < 0)`**: Checks if the value of `A` is negative.
- **`throw std::invalid_argument("A is negative");`**: If `A` is negative, the program throws an `invalid_argument` exception with the message `"A is negative"`, indicating that negative values for `A` are not allowed.

```cpp
		vector<int> v(A, 0);
		int real = -1, cmplx = sqrt(-1);
```
- **`vector<int> v(A, 0);`**: Creates a vector `v` of size `A` initialized with zeros. This line may cause a `bad_alloc` exception if `A` is too large to allocate memory.
- **`int real = -1, cmplx = sqrt(-1);`**: Declares two integer variables, `real` and `cmplx`. The `cmplx` variable is assigned the result of `sqrt(-1)`, which is mathematically undefined and typically leads to a runtime error (but might be handled differently depending on the system).

```cpp
		if(B == 0) throw 0;
		real = (A/B)*real;
```
- **`if(B == 0) throw 0;`**: If `B` is 0, the program throws an exception of type `int` with the value `0`. This is to handle division by zero errors.
- **`real = (A/B)*real;`**: Divides `A` by `B` and multiplies the result by `real`. If `B` is zero, this line will not be executed because the exception will have been thrown earlier.

```cpp
		int ans = v.at(B);
		return real + A - B*ans;
	}
```
- **`int ans = v.at(B);`**: Accesses the `B`-th element of vector `v` using the `at()` method, which checks for out-of-bounds errors and throws an `out_of_range` exception if `B` is outside the valid range.
- **`return real + A - B*ans;`**: Computes the result by adding `real` to `A`, subtracting `B * ans`, and returning the final value.

```cpp
	static int getLoad() {
		return load;
	}
};
```
- **`static int getLoad()`**: A static method that returns the current value of `load`, which indicates the number of times the `compute` method has been called.
- **`};`**: Closes the class definition.

```cpp
int Server::load = 0;
```
- **`int Server::load = 0;`**: Initializes the static member `load` to `0` at the start of the program.

```cpp
int main() {
	int T; cin >> T;
```
- **`int main()`**: The main function where the program execution begins.
- **`int T; cin >> T;`**: Reads an integer `T` from the user, which represents the number of test cases.

```cpp
	while(T--) {
		long long A, B;
		cin >> A >> B;
```
- **`while(T--)`**: This loop runs `T` times, decrementing `T` with each iteration. Each iteration processes a pair of inputs `A` and `B`.
- **`long long A, B;`**: Declares two `long long` integers `A` and `B`.
- **`cin >> A >> B;`**: Reads the values of `A` and `B` from the user.

```cpp
        try {
            cout << Server::compute(A, B) << endl;
        }
```
- **`try {`**: Begins a `try` block to handle any exceptions that may be thrown by the `compute` method.
- **`cout << Server::compute(A, B) << endl;`**: Calls the `compute` method with `A` and `B` as arguments and prints the result to the console.

```cpp
        catch(bad_alloc& error) {
            cout << "Not enough memory" << endl;
        } catch(exception& error) {
            cout << "Exception: " << error.what() << endl;
        } catch(...) {
            cout << "Other Exception" << endl;
        }
```
- **`catch(bad_alloc& error)`**: Catches a `bad_alloc` exception, which is thrown if the program fails to allocate memory for the vector. Prints `"Not enough memory"` if this exception is caught.
- **`catch(exception& error)`**: Catches all exceptions derived from the standard `exception` class, such as `invalid_argument`. It prints the message `"Exception: "` followed by the exception's description.
- **`catch(...)`**: This is a catch-all handler that catches any exceptions not caught by the previous handlers. It prints `"Other Exception"` for these cases.

```cpp
	cout << Server::getLoad() << endl;
	return 0;
}
```
- **`cout << Server::getLoad() << endl;`**: After processing all test cases, prints the total number of times the `compute` method was called (i.e., the value of `load`).
- **`return 0;`**: Returns `0` from the `main` function, indicating that the program finished successfully.
- **`}`**: Closes the `main` function.

### Summary

- The program simulates a server's workload by computing results based on input values `A` and `B`.
- It handles various exceptions such as memory allocation failure (`bad_alloc`), invalid arguments (`invalid_argument`), and any other generic exceptions.
- After processing all inputs, the program outputs the total number of times the server handled requests (i.e., the number of times `compute` was called).
