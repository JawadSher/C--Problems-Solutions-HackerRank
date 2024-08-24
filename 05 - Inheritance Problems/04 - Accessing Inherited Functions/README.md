<h1 align='center'>Accessing - Inherited - Functions</h1>

## Problem Statement

**Problem URL :** [Accessing Inherited Functions](https://www.hackerrank.com/challenges/accessing-inherited-functions/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/7b9f5a08-d2a4-457d-8d32-f315df942ba9)
![image](https://github.com/user-attachments/assets/3065195d-50ae-4ab6-a7be-845e9cc7dd95)
![image](https://github.com/user-attachments/assets/0cad11ef-19f3-48bb-99ee-d7bab653a3bb)
![image](https://github.com/user-attachments/assets/061bb429-bea0-4cc2-b298-768dee78b994)
![image](https://github.com/user-attachments/assets/3b3f4587-6c04-4220-9b30-b52f47bda535)

## Problem Solution
```cpp
#include<iostream>
using namespace std;

class A
{
    public:
        A(){
            callA = 0;
        }
    private:
        int callA;
        void inc(){
            callA++;
        }

    protected:
        void func(int & a)
        {
            a = a * 2;
            inc();
        }
    public:
        int getA(){
            return callA;
        }
};

class B
{
    public:
        B(){
            callB = 0;
        }
    private:
        int callB;
        void inc(){
            callB++;
        }
    protected:
        void func(int & a)
        {
            a = a * 3;
            inc();
        }
    public:
        int getB(){
            return callB;
        }
};

class C
{
    public:
        C(){
            callC = 0;
        }
    private:
        int callC;
        void inc(){
            callC++;
        }
    protected:
        void func(int & a)
        {
            a = a * 5;
            inc();
        }
    public:
        int getC(){
            return callC;
        }
};

class D : public A, public B, public C
{

	int val;
	public:
		//Initially val is 1
		 D()
		 {
		 	val = 1;
		 }

		 //Implement this function
		 void update_val(int new_val)
		 {

			while(new_val % 2 == 0){
                A::func(val);
                new_val /= 2;
            }
            while(new_val % 3 == 0){
                B::func(val);
                new_val /= 3;
            }
            while(new_val % 5 == 0){
                C::func(val);
                new_val /= 5;
            }
		 }
		 //For Checking Purpose
		 void check(int); //Do not delete this line.
};



void D::check(int new_val)
{
    update_val(new_val);
    cout << "Value = " << val << endl << "A's func called " << getA() << " times " << endl << "B's func called " << getB() << " times" << endl << "C's func called " << getC() << " times" << endl;
}


int main()
{
    D d;
    int new_val;
    cin >> new_val;
    d.check(new_val);

}
```

## Problem Solution Explanation


