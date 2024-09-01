<h1 align='center'>Overload - Operators</h1>

## Problem Statement

**Problem URL :** [Overload Operators](https://www.hackerrank.com/challenges/overload-operators/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/108589c4-1c7c-4bc9-8834-c9954457da68)
![image](https://github.com/user-attachments/assets/b2180c7c-c828-4f78-bd1a-bd431fd9d7d0)

## Problem Solution
```cpp
//Operator Overloading

#include<iostream>

using namespace std;

class Complex
{
public:
    int a,b;
    void input(string s)
    {
        int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
    }
};

Complex operator+(const Complex& x, const Complex& y){
    Complex result;
    
    result.a = x.a + y.a;
    result.b = x.b + y.b;
    return result;
}

ostream& operator<<(ostream& os, const Complex& z){
    os << z.a << "+i" << z.b;
    return os;
}

int main()
{
    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z=x+y;
    cout<<z<<endl;
}

```

## Problem Solution Explanation
Let's go through the code line by line and explain its functionality in detail.

```cpp
#include<iostream>
```
- This line includes the input-output stream library in C++, which allows you to use `std::cin` for input and `std::cout` for output.

```cpp
using namespace std;
```
- This line allows you to use names from the `std` namespace (like `cout`, `cin`, etc.) without having to prefix them with `std::`. It's a common practice to simplify the code.

### Class Definition

```cpp
class Complex
{
public:
    int a,b;
```
- Here, a class `Complex` is defined. This class has two public member variables, `a` and `b`, which represent the real part and the imaginary part of a complex number, respectively. 

For example, if you have a complex number `3 + i4`, then `a = 3` and `b = 4`.

```cpp
    void input(string s)
    {
        int v1=0;
        int i=0;
```
- The `input` function takes a string `s` as input, which represents a complex number in the format "real_part + imaginary_part". `v1` and `i` are integer variables used to parse the real and imaginary parts from the string.

```cpp
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
```
- This loop extracts the real part of the complex number from the string. It starts from the beginning of the string and keeps reading characters until it finds the '+' sign, which separates the real and imaginary parts. 
- `v1=v1*10+s[i]-'0';` converts the character digit to an integer and adds it to `v1`. This builds the integer value digit by digit. 
- Example: For the string "3+i4", `v1` becomes `3`.

```cpp
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
```
- This loop skips any characters that are spaces, the '+' sign, or the 'i' character. This moves the index `i` to the beginning of the imaginary part in the string.

```cpp
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
```
- This loop extracts the imaginary part of the complex number from the string, just like how the real part was extracted earlier.
- `v2=v2*10+s[i]-'0';` converts the characters representing the imaginary part into an integer.
- Example: For the string "3+i4", `v2` becomes `4`.

```cpp
        a=v1;
        b=v2;
    }
```
- The extracted values `v1` and `v2` are assigned to the member variables `a` and `b` of the `Complex` object, representing the real and imaginary parts, respectively.

### Operator Overloading

```cpp
Complex operator+(const Complex& x, const Complex& y)
{
    Complex result;
    
    result.a = x.a + y.a;
    result.b = x.b + y.b;
    return result;
}
```
- This function overloads the `+` operator to allow the addition of two `Complex` objects.
- It takes two `Complex` objects `x` and `y` as input.
- Inside the function, a new `Complex` object `result` is created.
- The real parts (`a`) of `x` and `y` are added together and stored in `result.a`.
- The imaginary parts (`b`) of `x` and `y` are added together and stored in `result.b`.
- The `result` object is returned, representing the sum of the two complex numbers.

Example:
- If `x` is `3+i4` and `y` is `5+i6`, then `result.a` will be `3+5=8` and `result.b` will be `4+6=10`. So, the resulting complex number will be `8+i10`.

```cpp
ostream& operator<<(ostream& os, const Complex& z)
{
    os << z.a << "+i" << z.b;
    return os;
}
```
- This function overloads the `<<` operator to allow a `Complex` object to be output using `cout`.
- It takes an `ostream` object `os` (like `cout`) and a `Complex` object `z`.
- It outputs the complex number in the format "real_part+iimaginary_part".
- Finally, it returns the `ostream` object `os` to allow chaining of `<<` operations.

Example:
- If `z` is `8+i10`, `cout << z;` will output `8+i10`.

### Main Function

```cpp
int main()
{
    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
```
- The `main` function begins by creating two `Complex` objects `x` and `y`.
- It then declares two strings `s1` and `s2`.
- The program reads two complex numbers in string format from the user and stores them in `s1` and `s2`.

Example:
- The user enters "3+i4" and "5+i6".

```cpp
    x.input(s1);
    y.input(s2);
```
- The `input` function is called on `x` and `y` to parse the strings `s1` and `s2`, setting the real and imaginary parts of `x` and `y`.

```cpp
    Complex z=x+y;
```
- The overloaded `+` operator is used to add the two complex numbers `x` and `y`. The result is stored in a new `Complex` object `z`.

Example:
- `z` will be `8+i10` when `x` is `3+i4` and `y` is `5+i6`.

```cpp
    cout<<z<<endl;
}
```
- The overloaded `<<` operator is used to output the complex number `z`. The output is followed by a newline.
- The program prints the resulting complex number to the console.

Example:
- The output will be `8+i10`.

### Summary
- This code allows you to input two complex numbers, adds them together, and prints the result.
- Operator overloading is used to simplify the addition and output operations for complex numbers, making the code more intuitive and readable.
