<h1 align='center'>Attending - Workshops</h1>

## Problem Statement

**Problem URL :** [Attending Workshops](https://www.hackerrank.com/challenges/attending-workshops/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/66026c80-8f28-4314-9321-405ea61c06dc)
![image](https://github.com/user-attachments/assets/f84db964-fd90-4c1b-858f-9ce3897ade7c)

## Problem Solution
```cpp
#include<bits/stdc++.h>

using namespace std;

struct Workshop{
    friend ostream& operator<<(ostream& os, const Workshop& obj);
    int start_time;
    int duration;
    int end_time;
    bool operator<(const Workshop& rhs){
        return (this->end_time < rhs.end_time);
    }
};

ostream& operator<<(ostream& os, const Workshop& obj){
    os<< obj.start_time << ": "<<obj.end_time<<":"<<obj.duration<<"\n";
    return os;
}

struct Available_Workshops{
    int signed_workshops;
    vector<Workshop> vec;
};

Available_Workshops* initialize(int start_time[], int duration[], int num){
   Available_Workshops *avail = new Available_Workshops;
   avail->signed_workshops = num;
   Workshop test;
   for(int i = 0; i < num; i++){
       test.start_time = start_time[i];
       test.duration = duration[i];
       test.end_time = start_time[i] + duration[i];
       avail->vec.push_back(test);
   }
   sort(avail->vec.begin(), avail->vec.end());
   return avail; 
}

int CalculateMaxWorkshops(Available_Workshops *test){
    int w_count = 0;
    int last_end_time = 0; 
    for(int i=0; i < test->signed_workshops; i++){
        if(test->vec[i].start_time >= last_end_time){
            w_count++;
            last_end_time = test->vec.at(i).end_time;
        }
    }
    return w_count;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}

```

## Problem Solution Explanation
Let's go through the code step by step, explaining each part with examples.

### Headers and Namespace

```cpp
#include<bits/stdc++.h>
using namespace std;
```
- `#include<bits/stdc++.h>`: This is a GCC-specific header file that includes all the standard C++ libraries. It's useful for competitive programming because it saves time, but it’s not recommended for production code due to potential performance issues.
- `using namespace std;`: This line brings all the names from the `std` namespace into the global namespace. This allows you to use standard C++ library names without the `std::` prefix.

### `Workshop` Structure

```cpp
struct Workshop{
    friend ostream& operator<<(ostream& os, const Workshop& obj);
    int start_time;
    int duration;
    int end_time;
    bool operator<(const Workshop& rhs){
        return (this->end_time < rhs.end_time);
    }
};
```
- `struct Workshop`: Defines a structure to store the start time, duration, and end time of a workshop.
- `int start_time;`: The start time of the workshop.
- `int duration;`: The duration of the workshop.
- `int end_time;`: The end time of the workshop, calculated as `start_time + duration`.
- `bool operator<(const Workshop& rhs)`: This operator is overloaded to allow comparison between two `Workshop` objects based on their `end_time`. This is useful for sorting workshops by their end times.

### Overloading the `<<` Operator

```cpp
ostream& operator<<(ostream& os, const Workshop& obj){
    os << obj.start_time << ": " << obj.end_time << ":" << obj.duration << "\n";
    return os;
}
```
- This function overloads the `<<` operator to print out the details of a `Workshop` object in the format `start_time: end_time: duration`.

### `Available_Workshops` Structure

```cpp
struct Available_Workshops{
    int signed_workshops;
    vector<Workshop> vec;
};
```
- `struct Available_Workshops`: Stores a collection of workshops.
- `int signed_workshops;`: Stores the number of workshops available.
- `vector<Workshop> vec;`: A vector to store the list of `Workshop` objects.

### `initialize` Function

```cpp
Available_Workshops* initialize(int start_time[], int duration[], int num){
   Available_Workshops *avail = new Available_Workshops;
   avail->signed_workshops = num;
   Workshop test;
   for(int i = 0; i < num; i++){
       test.start_time = start_time[i];
       test.duration = duration[i];
       test.end_time = start_time[i] + duration[i];
       avail->vec.push_back(test);
   }
   sort(avail->vec.begin(), avail->vec.end());
   return avail; 
}
```
- `Available_Workshops* initialize(int start_time[], int duration[], int num)`: Initializes an `Available_Workshops` object with the given start times and durations.
- `Available_Workshops *avail = new Available_Workshops;`: Dynamically allocates memory for an `Available_Workshops` object.
- `avail->signed_workshops = num;`: Sets the number of workshops.
- `for(int i = 0; i < num; i++)`: Loops through each workshop to populate the `vec` vector.
    - `test.start_time = start_time[i];`: Sets the start time.
    - `test.duration = duration[i];`: Sets the duration.
    - `test.end_time = start_time[i] + duration[i];`: Calculates and sets the end time.
    - `avail->vec.push_back(test);`: Adds the workshop to the vector.
- `sort(avail->vec.begin(), avail->vec.end());`: Sorts the workshops based on their end times using the overloaded `<` operator.
- `return avail;`: Returns the pointer to the `Available_Workshops` object.

### `CalculateMaxWorkshops` Function

```cpp
int CalculateMaxWorkshops(Available_Workshops *test){
    int w_count = 0;
    int last_end_time = 0; 
    for(int i = 0; i < test->signed_workshops; i++){
        if(test->vec[i].start_time >= last_end_time){
            w_count++;
            last_end_time = test->vec.at(i).end_time;
        }
    }
    return w_count;
}
```
- `int CalculateMaxWorkshops(Available_Workshops *test)`: Calculates the maximum number of workshops that can be attended without overlapping.
- `int w_count = 0;`: Initializes a counter for the number of workshops that can be attended.
- `int last_end_time = 0;`: Stores the end time of the last attended workshop.
- `for(int i = 0; i < test->signed_workshops; i++)`: Iterates through all workshops.
    - `if(test->vec[i].start_time >= last_end_time)`: Checks if the current workshop starts after or when the last attended workshop ends.
        - `w_count++`: If yes, increment the workshop count.
        - `last_end_time = test->vec.at(i).end_time;`: Update the `last_end_time` to the current workshop's end time.
- `return w_count;`: Returns the total count of non-overlapping workshops.

### `main` Function

```cpp
int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i = 0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops *ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
```
- `int n;`: Reads the number of workshops.
- `int* start_time = new int[n];`: Dynamically allocates an array for start times.
- `int* duration = new int[n];`: Dynamically allocates an array for durations.
- `for(int i = 0; i < n; i++)`: Reads the start times into the `start_time` array.
- `for(int i = 0; i < n; i++)`: Reads the durations into the `duration` array.
- `Available_Workshops *ptr;`: Declares a pointer to an `Available_Workshops` object.
- `ptr = initialize(start_time, duration, n);`: Initializes the `Available_Workshops` object using the provided arrays and number of workshops.
- `cout << CalculateMaxWorkshops(ptr) << endl;`: Calculates and prints the maximum number of non-overlapping workshops that can be attended.

### Example Walkthrough
Let's say you input:
```
5
1 3 0 5 8
2 2 6 7 1
```
- Number of workshops (`n`) is 5.
- Start times are [1, 3, 0, 5, 8].
- Durations are [2, 2, 6, 7, 1].

Workshops will be:
- Workshop 1: Start = 1, Duration = 2, End = 3
- Workshop 2: Start = 3, Duration = 2, End = 5
- Workshop 3: Start = 0, Duration = 6, End = 6
- Workshop 4: Start = 5, Duration = 7, End = 12
- Workshop 5: Start = 8, Duration = 1, End = 9

After sorting by `end_time`, the workshops are:
- Workshop 1: Start = 1, End = 3
- Workshop 2: Start = 3, End = 5
- Workshop 3: Start = 0, End = 6
- Workshop 5: Start = 8, End = 9
- Workshop 4: Start = 5, End = 12

The maximum number of non-overlapping workshops you can attend is `3`, which might be:
1. Workshop 1 (End at 3)
2. Workshop 2 (End at 5)
3. Workshop 5 (End at 9)

The output would be:
```
3
```

This is how the program works, line by line with an example.
