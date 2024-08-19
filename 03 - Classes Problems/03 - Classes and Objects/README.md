<h1 align='center'>Classes - And - Objects</h1>

## Problem Statement

**Problem URL :** [Classes and Objects](https://www.hackerrank.com/challenges/classes-objects/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/a43375fd-d484-455f-8a63-eaa225f4de25)
![image](https://github.com/user-attachments/assets/270577a5-110f-4be8-b8a3-d3ccee30503b)

## Problem Solution 
```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Student{
    private:
        vector<int> scores;
    
    public:
        void input(){
            int i = 5;
            while (i){
                int score;
                cin >> score;
                scores.push_back(score);
                i--;
            }
        }
        
        int calculateTotalScore(){
            int total_score = 0;
            for(int i = 0; i < 5; i++){
                total_score += scores[i];
            }
            return total_score;
        }    
};

int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}

```

## Problem Solution Explanation

let's break down the provided C++ code step by step.

### 1. **Include Headers**
```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
```
- These headers include standard libraries for mathematical functions (`<cmath>`), formatted input/output (`<cstdio>`), dynamic arrays (`<vector>`), input/output streams (`<iostream>`), algorithms (`<algorithm>`), and assertions (`<cassert>`). 
- `using namespace std;` allows the use of standard library names without the `std::` prefix.

### 2. **Define the `Student` Class**
```cpp
class Student {
    private:
        vector<int> scores;

    public:
        void input() {
            int i = 5;
            while (i) {
                int score;
                cin >> score;
                scores.push_back(score);
                i--;
            }
        }

        int calculateTotalScore() {
            int total_score = 0;
            for (int i = 0; i < 5; i++) {
                total_score += scores[i];
            }
            return total_score;
        }
};
```
- **Private Members:**
  - `vector<int> scores;` is a dynamic array to store scores of a student.
  
- **Public Members:**
  - `void input()`: Reads 5 scores from standard input and stores them in the `scores` vector. The loop runs 5 times (`i--` decrements `i` until it is 0).
  - `int calculateTotalScore()`: Computes the total score of a student by summing up all values in the `scores` vector. It assumes that the `scores` vector always has exactly 5 scores.

### 3. **Main Function**
```cpp
int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students

    for (int i = 0; i < n; i++) {
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0;
    for (int i = 1; i < n; i++) {
        int total = s[i].calculateTotalScore();
        if (total > kristen_score) {
            count++;
        }
    }

    // print result
    cout << count;

    return 0;
}
```
- `int n;`: Variable to store the number of students.
- `cin >> n;`: Reads the number of students from input.
- `Student *s = new Student[n];`: Creates an array of `Student` objects with `n` elements using dynamic memory allocation.

**Input Scores:**
- A loop runs from `0` to `n-1`, calling `input()` for each student object to read their scores.

**Calculate Kristen's Score:**
- `int kristen_score = s[0].calculateTotalScore();`: Calculates the total score for the first student (assumed to be Kristen).

**Count Higher Scores:**
- A loop runs from `1` to `n-1` (skipping Kristen) to calculate and compare the total score of each student.
- If a student’s total score is higher than Kristen’s, increment `count`.

**Print Result:**
- `cout << count;`: Prints the number of students who scored higher than Kristen.

### **Example Walkthrough**

**Input Example:**
```
3
1 2 3 4 5
2 3 4 5 6
1 2 3 4 8
```
**Explanation:**
1. `n` is 3, meaning there are 3 students.
2. Scores for each student:
   - Student 1 (Kristen): `1 2 3 4 5` -> Total = 15
   - Student 2: `2 3 4 5 6` -> Total = 20
   - Student 3: `1 2 3 4 8` -> Total = 18
3. Kristen’s score = 15.
4. Count students with scores higher than 15:
   - Student 2’s score is 20 (higher than 15).
   - Student 3’s score is 18 (higher than 15).
5. Result: 2 students scored higher than Kristen.

**Output:**
```
2
```

This example demonstrates that 2 students scored higher than Kristen.

