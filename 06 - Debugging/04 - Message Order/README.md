<h1 align='center'>Message - Order</h1>

## Problem Statement

**Problem URL :** [Message Order](https://www.hackerrank.com/challenges/messages-order/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/f32aecfa-24fc-4704-8d0a-2f0ae039b25c)
![image](https://github.com/user-attachments/assets/37f1f7e8-3b06-46fb-988d-8b85bd80bfee)

## Problem Solution
```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Message {
private :
    string text;
    static int id;
    int current_id;
    
public: 
    Message(){current_id = ++id;}
    Message(string t){current_id = ++id; text=t;}
    const string& get_text() {
        return text;
    }
    
    bool operator<(const Message& other) const{
        if(current_id < other.current_id){
            return true;
        }else{
            return false;
        }
    }
};

int Message::id = 0;
class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(const string& text) {
        Message m = Message(text);
        return m;
    }
};

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
    // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());         
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}

```

## Problem Solution Explanation

let's walk through this C++ code step by step:

### Includes and Namespace

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
```

- `#include <iostream>`: Includes the input-output stream library for handling console input and output.
- `#include <algorithm>`: Includes algorithms like `sort` and `random_shuffle`.
- `#include <vector>`: Includes the vector container class.

```cpp
using namespace std;
```

- This line allows us to use standard library names (like `vector`, `string`, etc.) without prefixing them with `std::`.

### Message Class

```cpp
class Message {
private:
    string text;
    static int id;
    int current_id;
    
public: 
    Message() { current_id = ++id; }
    Message(string t) { current_id = ++id; text = t; }
    const string& get_text() const {
        return text;
    }
    
    bool operator<(const Message& other) const {
        return current_id < other.current_id;
    }
};
```

- **Private Members**:
  - `string text`: Stores the message text.
  - `static int id`: A static member to keep track of the global message ID count.
  - `int current_id`: Unique ID for each `Message` instance.

- **Public Members**:
  - `Message()`: Default constructor. Initializes `current_id` with the next value of `id`.
  - `Message(string t)`: Parameterized constructor. Sets `text` and initializes `current_id`.
  - `const string& get_text() const`: Returns a constant reference to `text`.
  - `bool operator<(const Message& other) const`: Overloaded `<` operator to compare `Message` objects based on their `current_id`.

```cpp
int Message::id = 0;
```

- Initializes the static `id` member to `0`.

### MessageFactory Class

```cpp
class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(const string& text) {
        Message m = Message(text);
        return m;
    }
};
```

- **Public Members**:
  - `MessageFactory()`: Default constructor.
  - `Message create_message(const string& text)`: Creates and returns a `Message` object with the given `text`.

### Recipient Class

```cpp
class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};
```

- **Public Members**:
  - `Recipient()`: Default constructor.
  - `void receive(const Message& msg)`: Adds a `Message` to the `messages_` vector.
  - `void print_messages()`: Calls `fix_order()` to sort messages by `current_id`, prints each message's text, and clears the `messages_` vector.

- **Private Members**:
  - `void fix_order()`: Sorts the `messages_` vector based on the overloaded `<` operator.
  - `vector<Message> messages_`: Stores received messages.

### Network Class

```cpp
class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
        random_shuffle(messages.begin(), messages.end());         
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};
```

- **Public Members**:
  - `static void send_messages(vector<Message> messages, Recipient& recipient)`: Static method to simulate sending messages in a random order. It shuffles the `messages` vector and then sends each `Message` to the `recipient`.

### main Function

```cpp
int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
```

- **Variable Declarations**:
  - `MessageFactory message_factory;`: Creates a `MessageFactory` instance.
  - `Recipient recipient;`: Creates a `Recipient` instance.
  - `vector<Message> messages;`: Vector to store `Message` objects.
  - `string text;`: String to read input lines.

- **Input Reading**:
  - `while (getline(cin, text))`: Reads lines from the standard input until EOF, creating a `Message` for each line and adding it to `messages`.

- **Message Sending and Printing**:
  - `Network::send_messages(messages, recipient);`: Sends the messages to the `recipient` in a shuffled order.
  - `recipient.print_messages();`: Prints the messages in sorted order by their `current_id`.

This code demonstrates a message system where messages are created, sent in a random order, and then printed in the order they were created.
