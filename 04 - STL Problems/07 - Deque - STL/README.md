<h1 align='center'>Deque - STL</h1>

## Problem Statement

**Problem URL :** [Deque-STL](https://www.hackerrank.com/challenges/deque-stl/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/e215ef55-b6d1-4843-97ba-ac23946f280d)
![image](https://github.com/user-attachments/assets/8999c77e-0c01-40cd-86fd-6e3e18aa146d)

## Problem Solution
```cpp
#include <iostream>
#include <deque>
using namespace std;

void printKMax(int arr[], int n, int k) {
    deque<int> dq;
    
    for(int i = 0; i < n; i++){
        if(!dq.empty() && dq.front() == i-k){
            dq.pop_front();
        }
        
        while(!dq.empty() && arr[dq.back()] <= arr[i]){
            dq.pop_back();   
        }
        
        dq.push_back(i);
        
        if(i >= k-1){
            cout<<arr[dq.front()]<<" ";
        }
    }
    cout<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t > 0) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}

```

## Problem Solution Explanation
Let's go through the code line by line to understand how it works.

### Code Overview

This code efficiently finds the maximum element in every subarray (or "window") of size `k` within an array `arr[]`. It uses a deque (double-ended queue) to store indices of useful elements, enabling a time complexity of \(O(n)\).


```cpp
#include <iostream>
#include <deque>
using namespace std;
```

- **Headers:**
  - `#include <iostream>`: Includes the input-output stream, necessary for using `cin` and `cout`.
  - `#include <deque>`: Includes the deque container, which is used to maintain a list of indices.

```cpp
void printKMax(int arr[], int n, int k) {
```

- **Function Definition:**
  - This function takes three arguments:
    - `arr[]`: The array of integers.
    - `n`: The size of the array.
    - `k`: The size of the sliding window.
  - The purpose of this function is to print the maximum element of each subarray of size `k`.

```cpp
    deque<int> dq;
```

- **Deque Declaration:**
  - `deque<int> dq;`: Declares a deque of integers `dq`. The deque will store indices of elements from the array `arr[]` that are candidates for being the maximum in the current window.

```cpp
    for(int i = 0; i < n; i++){
```

- **Main Loop:**
  - The loop iterates over each element in the array `arr[]` using the index `i`, where `i` ranges from `0` to `n-1`.

```cpp
        if(!dq.empty() && dq.front() == i-k){
            dq.pop_front();
        }
```

- **Removing Out-of-Window Elements:**
  - `dq.front()` gives the index of the oldest element in the deque.
  - `if(!dq.empty() && dq.front() == i-k)`: Checks if the deque is not empty and if the element at the front of the deque is outside the current window (i.e., if its index is `i-k`).
  - `dq.pop_front();`: If the condition is true, remove the front element from the deque because it is no longer in the current window.

```cpp
        while(!dq.empty() && arr[dq.back()] <= arr[i]){
            dq.pop_back();   
        }
```

- **Maintaining Deque for Maximum Element:**
  - `while(!dq.empty() && arr[dq.back()] <= arr[i])`: This loop removes all elements from the back of the deque that are less than or equal to the current element `arr[i]`.
  - The logic here is that any smaller elements will never be needed again as they can't be the maximum for the current or any future windows. Therefore, they are removed from the deque.

```cpp
        dq.push_back(i);
```

- **Add Current Element to Deque:**
  - `dq.push_back(i);`: Adds the current element's index `i` to the back of the deque. This element is a candidate to be the maximum in the current or future windows.

```cpp
        if(i >= k-1){
            cout<<arr[dq.front()]<<" ";
        }
```

- **Output the Maximum for the Current Window:**
  - `if(i >= k-1)`: Checks if the current index `i` is at least `k-1`, which means the first window of size `k` has been formed.
  - `cout << arr[dq.front()] << " ";`: Prints the maximum element of the current window. The maximum element is at the front of the deque because of the way the deque is maintained (largest elements are always at the front).

```cpp
    }
    cout<<endl;
}
```

- **End of Function:**
  - The loop ends after processing all elements in the array.
  - `cout << endl;`: Moves the cursor to a new line after printing all maximum elements for the current test case.

```cpp
int main() {
    int t;
    cin >> t;
    while (t > 0) {
```

- **Main Function and Input Handling:**
  - `int t; cin >> t;`: Reads the number of test cases `t`.
  - The `while (t > 0)` loop processes each test case one by one.

```cpp
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
```

- **Reading Array and Window Size:**
  - `cin >> n >> k;`: Reads the size of the array `n` and the window size `k`.
  - `int arr[n];`: Declares an array `arr[]` of size `n`.
  - The `for` loop reads `n` elements into the array `arr[]`.

```cpp
        printKMax(arr, n, k);
        t--;
    }
```

- **Calling the Function:**
  - `printKMax(arr, n, k);`: Calls the `printKMax` function to find and print the maximum element in every window of size `k` for the current test case.
  - `t--;`: Decreases the test case counter.

```cpp
    return 0;
}
```

- **End of Program:**
  - The program returns `0`, indicating successful execution.

### Summary

This code efficiently finds and prints the maximum elements of all subarrays (windows) of size `k` in the given array using a deque. The deque helps maintain the indices of potential maximum elements, ensuring that the solution runs in \(O(n)\) time, which is much faster and avoids the TLE (Time Limit Exceeded) error that might occur with a less efficient brute-force approach.
