<h1 align='center'>Abstract Classes - Polymorphism</h1>

## Problem Statement

**Problem URL :** [Abstract Classes - Polymorphism](https://www.hackerrank.com/challenges/abstract-classes-polymorphism/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/f7b885b2-f7a4-4200-9dfa-364f18d5f7fd)
![image](https://github.com/user-attachments/assets/92781fbb-6d09-4f53-aa1e-eda0ec23ce48)
![image](https://github.com/user-attachments/assets/d2bf92a6-3ea2-4c9a-a446-88f7f5afc2f9)


## Problem Solution
```cpp
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache{
    public:
        LRUCache(int capacity){
            cp = capacity;
            tail = nullptr;
            head = nullptr;
        }
        
        void set(int key, int value) override {
            if(mp.find(key) != mp.end()){
                Node* node = mp[key];
                node->value = value;
                
                // Move the node to the head of the list
                if(node->prev != nullptr){
                    node->prev->next = node->next;
                    if(node->next != nullptr){
                        node->next->prev = node->prev;
                    } else {
                        tail = node->prev;
                    }
                    node->prev = nullptr;
                    node->next = head;
                    head->prev = node;
                    head = node;
                }
            } else {
                Node* node = new Node(nullptr, head, key, value);
                if(head != nullptr){
                    head->prev = node;
                }
                head = node;
                
                if(tail == nullptr){
                    tail = node;
                }
                
                if(mp.size() == cp){
                    mp.erase(tail->key);
                    Node* temp = tail;
                    tail = tail->prev;
                    if(tail) tail->next = nullptr;
                    delete temp;
                }
                
                mp[key] = node;
            }
        }
        
        int get(int key) override {
            if(mp.find(key) != mp.end()){
                Node* node = mp[key];
                
                // Move the accessed node to the head of the list
                if(node->prev != nullptr){
                    node->prev->next = node->next;
                    if(node->next != nullptr){
                        node->next->prev = node->prev;
                    } else {
                        tail = node->prev;
                    }
                    node->prev = nullptr;
                    node->next = head;
                    head->prev = node;
                    head = node;
                }
                return node->value;
            }
            
            return -1;
        }
};


int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}

```

## Problem Solution Explanation
This code implements an **LRU (Least Recently Used) Cache** using a combination of a **doubly linked list** and a **hash map**. The idea behind an LRU Cache is to remove the least recently used item when the cache reaches its capacity, ensuring that the most recently used items stay in the cache.

Let's go through the code line by line:

### 1. Include Statements
```cpp
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
```
- These headers include libraries needed for the program. Not all of them are used in this code, but they provide useful tools like input/output streams (`iostream`), and data structures (`vector`, `map`, `set`).

### 2. Struct `Node`
```cpp
struct Node {
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val): prev(p), next(n), key(k), value(val) {};
   Node(int k, int val): prev(NULL), next(NULL), key(k), value(val) {};
};
```
- **`Node`**: This structure defines the nodes that will be part of the doubly linked list.
  - `Node* next;` and `Node* prev;`: Pointers to the next and previous nodes in the list.
  - `int value;`: The value stored in the node.
  - `int key;`: The key associated with the value (for lookup in the map).
  - **Constructors**: The first constructor initializes a node with a given previous and next node, key, and value. The second constructor initializes a node with just a key and value (and sets the next and prev pointers to `NULL`).

### 3. Class `Cache`
```cpp
class Cache {
   protected:
   map<int, Node*> mp;  // map the key to the node in the linked list
   int cp;  // capacity
   Node* tail;  // double linked list tail pointer
   Node* head;  // double linked list head pointer
   virtual void set(int, int) = 0;  // set function
   virtual int get(int) = 0;  // get function
};
```
- **`Cache`**: This is an abstract base class that represents the basic structure of a cache.
  - `map<int, Node*> mp;`: This map stores a mapping from keys to nodes in the doubly linked list. It allows for O(1) access to any element in the cache.
  - `int cp;`: Stores the capacity of the cache.
  - `Node* tail;` and `Node* head;`: Pointers to the tail and head of the doubly linked list.
  - The `set` and `get` functions are declared as pure virtual (`= 0`), meaning they must be implemented by derived classes.

### 4. Class `LRUCache`
```cpp
class LRUCache : public Cache {
   public:
        LRUCache(int capacity) {
            cp = capacity;
            tail = nullptr;
            head = nullptr;
        }
        
        void set(int key, int value) override {
            if(mp.find(key) != mp.end()) {
                Node* node = mp[key];
                node->value = value;
                
                // Move the node to the head of the list
                if(node->prev != nullptr) {
                    node->prev->next = node->next;
                    if(node->next != nullptr) {
                        node->next->prev = node->prev;
                    } else {
                        tail = node->prev;
                    }
                    node->prev = nullptr;
                    node->next = head;
                    head->prev = node;
                    head = node;
                }
            } else {
                Node* node = new Node(nullptr, head, key, value);
                if(head != nullptr) {
                    head->prev = node;
                }
                head = node;
                
                if(tail == nullptr) {
                    tail = node;
                }
                
                if(mp.size() == cp) {
                    mp.erase(tail->key);
                    Node* temp = tail;
                    tail = tail->prev;
                    if(tail) tail->next = nullptr;
                    delete temp;
                }
                
                mp[key] = node;
            }
        }
        
        int get(int key) override {
            if(mp.find(key) != mp.end()) {
                Node* node = mp[key];
                
                // Move the accessed node to the head of the list
                if(node->prev != nullptr) {
                    node->prev->next = node->next;
                    if(node->next != nullptr) {
                        node->next->prev = node->prev;
                    } else {
                        tail = node->prev;
                    }
                    node->prev = nullptr;
                    node->next = head;
                    head->prev = node;
                    head = node;
                }
                return node->value;
            }
            
            return -1;
        }
};
```
- **`LRUCache`**: This class derives from `Cache` and implements the Least Recently Used (LRU) Cache.
  - **Constructor**: 
    - `LRUCache(int capacity)`: Initializes the cache with a given capacity, setting `cp`, `tail`, and `head`.
  - **`set(int key, int value)`**:
    - This function inserts a new key-value pair into the cache or updates an existing key.
    - **Key exists**: If the key already exists in the cache (`mp.find(key) != mp.end()`), it updates the value and moves the corresponding node to the head of the list (indicating it was recently used).
    - **Key does not exist**: If the key does not exist:
      - Creates a new node and inserts it at the head of the list.
      - If the cache is full, removes the least recently used node (the tail).
      - Inserts the new node into the map `mp`.
  - **`get(int key)`**:
    - This function retrieves the value associated with a key.
    - **Key exists**: If the key exists, it moves the node to the head (marking it as recently used) and returns the value.
    - **Key does not exist**: If the key does not exist, it returns `-1`.

### 5. Main Function
```cpp
int main() {
   int n, capacity, i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0; i<n; i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key, value);
      }
   }
   return 0;
}
```
- **`main()`**: 
  - **Input Handling**: 
    - `cin >> n >> capacity;`: Reads the number of operations (`n`) and the cache capacity (`capacity`).
    - An `LRUCache` object `l` is created with the given capacity.
  - **Loop**:
    - For each operation, it reads a command (`get` or `set`).
    - **Get Operation**: If the command is `get`, it reads a key, calls `l.get(key)`, and prints the result.
    - **Set Operation**: If the command is `set`, it reads a key and a value, then calls `l.set(key, value)` to insert/update the key-value pair.

This code is an implementation of an LRU Cache that efficiently handles insertion and retrieval operations while maintaining the order of access. This is particularly useful in scenarios where you want to ensure that the most frequently accessed data remains in memory.
