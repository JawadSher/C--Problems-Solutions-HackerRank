<h1 align='center'>Box - It!</h1>

## Problem Statement

**Problem URL :** [Box It!](https://www.hackerrank.com/challenges/box-it/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/95f28f0a-4828-4463-8d7c-da61d7eead2b)
![image](https://github.com/user-attachments/assets/ba4c1ab3-351a-42e7-aa60-8e5f61f1ebaf)


## Problem Solution
```cpp
#include<bits/stdc++.h>

using namespace std;

class Box {
private:
    int length;
    int height;
    int width;

public:
    Box() : length(0), height(0), width(0) {}

    Box(int l, int h, int w) : length(l), height(h), width(w) {}

    int getLength() const {
        return length;
    }

    int getHeight() const {
        return height;
    }

    int getWidth() const {
        return width;
    }

    long long CalculateVolume() const {
        return static_cast<long long>(length) * height * width;
    }

    bool operator<(const Box& b) const {
        if(length < b.length){
            return true;
        }
        else if (length == b.length && width < b.width){
            return true;
        }
        else if(length == b.length && width == b.width && height < b.height){
            return true;
        }
        else{
            return false;
        }
    }
    
    friend ostream& operator<<(ostream& out, const Box& b) {
        out << b.length << " " << b.height << " " << b.width;
        return out;
    }
};


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
```

## Problem Solution Explanation
Let's go through the C++ code step by step to understand how it works.

#### Class Definition: `Box`

1. **Private Members:**
   - `int length;`
   - `int height;`
   - `int width;`
   
   These private members store the dimensions of the box.

2. **Constructors:**
   - **Default Constructor:**
     ```cpp
     Box() : length(0), height(0), width(0) {}
     ```
     Initializes the box with default dimensions: length, height, and width all set to 0.

   - **Parameterized Constructor:**
     ```cpp
     Box(int l, int h, int w) : length(l), height(h), width(w) {}
     ```
     Initializes the box with specified dimensions: length `l`, height `h`, and width `w`.

3. **Member Functions:**
   - **Getters:**
     ```cpp
     int getLength() const { return length; }
     int getHeight() const { return height; }
     int getWidth() const { return width; }
     ```
     These functions return the respective dimensions of the box.

   - **Calculate Volume:**
     ```cpp
     long long CalculateVolume() const {
         return static_cast<long long>(length) * height * width;
     }
     ```
     Computes the volume of the box using the formula: `length * height * width`. The `static_cast<long long>` ensures that the result can handle large values.

   - **Overloaded `<` Operator:**
     ```cpp
     bool operator<(const Box& b) const {
         if (length < b.length) return true;
         if (length == b.length && width < b.width) return true;
         if (length == b.length && width == b.width && height < b.height) return true;
         return false;
     }
     ```
     This operator allows comparing two `Box` objects. It first compares lengths, then widths if lengths are equal, and finally heights if both lengths and widths are equal. If all are equal, it returns `false`.

   - **Overloaded `<<` Operator:**
     ```cpp
     friend ostream& operator<<(ostream& out, const Box& b) {
         out << b.length << " " << b.height << " " << b.width;
         return out;
     }
     ```
     This operator allows printing the box dimensions in the format `length height width`.

#### Main Function: `check2`

This function performs various operations based on user input:

1. **Read Number of Operations:**
   ```cpp
   int n;
   cin >> n;
   ```
   Reads the number of operations to be performed.

2. **Create a Box Object:**
   ```cpp
   Box temp;
   ```
   Initializes a `Box` object `temp` with default dimensions.

3. **Process Operations:**
   ```cpp
   for (int i = 0; i < n; i++) {
       int type;
       cin >> type;
       ...
   }
   ```
   Iterates through each operation based on the input `type`.

   - **Type 1: Print Default Box Dimensions:**
     ```cpp
     if (type == 1) {
         cout << temp << endl;
     }
     ```
     Prints the dimensions of the default box `temp`.

   - **Type 2: Set New Box Dimensions and Print:**
     ```cpp
     if (type == 2) {
         int l, b, h;
         cin >> l >> b >> h;
         Box NewBox(l, b, h);
         temp = NewBox;
         cout << temp << endl;
     }
     ```
     Reads new dimensions for the box, creates a new `Box` object `NewBox`, assigns it to `temp`, and prints the new dimensions.

   - **Type 3: Compare with a New Box:**
     ```cpp
     if (type == 3) {
         int l, b, h;
         cin >> l >> b >> h;
         Box NewBox(l, b, h);
         if (NewBox < temp) {
             cout << "Lesser\n";
         } else {
             cout << "Greater\n";
         }
     }
     ```
     Reads dimensions for a new box, compares it with `temp`, and prints whether `NewBox` is "Lesser" or "Greater" based on the overloaded `<` operator.

   - **Type 4: Print Volume of Current Box:**
     ```cpp
     if (type == 4) {
         cout << temp.CalculateVolume() << endl;
     }
     ```
     Prints the volume of the `temp` box using the `CalculateVolume` method.

   - **Type 5: Copy and Print the Box:**
     ```cpp
     if (type == 5) {
         Box NewBox(temp);
         cout << NewBox << endl;
     }
     ```
     Creates a copy of `temp` and prints its dimensions.

#### Example Usage

Suppose the input is:

```
5
1
2
5
3
4
```

1. **Type 1:** Prints `0 0 0` (default dimensions).
2. **Type 2:** Reads `5 10 15`, creates a new box with these dimensions, assigns it to `temp`, and prints `5 10 15`.
3. **Type 5:** Copies `temp` and prints `5 10 15`.
4. **Type 3:** Compares a new box with dimensions `4 8 12` to `temp`. Since `4 8 12` is less than `5 10 15`, it prints "Lesser".
5. **Type 4:** Prints the volume of `temp`, which is `5 * 10 * 15 = 750`.

This code provides a way to manage and manipulate `Box` objects, including comparisons and volume calculations.
