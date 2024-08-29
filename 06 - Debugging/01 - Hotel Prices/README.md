<h1 align='center'>Hotel - Prices</h1>

## Problem Statement

**Problem URL :** [Hotel Prices](https://www.hackerrank.com/challenges/hotel-prices/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/b3fac4f4-d35f-48cb-8c99-bf736f1d5327)
![image](https://github.com/user-attachments/assets/74d4438b-e781-48f0-aece-607048593910)

## Problem Explanation
Sure! Let’s first outline the problem statement for "Hotel Prices" from HackerRank:

### **Problem Statement: Hotel Prices**

You are given a task to compute the total profit for a hotel based on the prices of various rooms. The hotel has two types of rooms:

1. **Standard Hotel Room**: The price is calculated using the formula:
   \[
   \text{Price} = 50 \times \text{bedrooms} + 100 \times \text{bathrooms}
   \]

2. **Hotel Apartment**: This is a special type of room where the price is the same as a standard room with the same number of bedrooms and bathrooms, plus an additional 100.

You need to read the number of rooms booked and their details, compute the total profit for all rooms, and print it.

## Problem Solution
```cpp


#include <iostream>
#include <vector>

using namespace std;

class HotelRoom {
    private:
        int bedrooms_;
        int bathrooms_;
        
    public:
        HotelRoom(int bedrooms, int bathrooms) 
        : bedrooms_(bedrooms), bathrooms_(bathrooms) {}
        
        virtual int get_price() {
            return 50*bedrooms_ + 100*bathrooms_;
        }
};

class HotelApartment : public HotelRoom {
public:
    HotelApartment(int bedrooms, int bathrooms) 
    : HotelRoom(bedrooms, bathrooms) {}

    int get_price() {
        return HotelRoom::get_price() + 100;
    }
};

int main() {
    int n;
    cin >> n;
    vector<HotelRoom*> rooms;
    for (int i = 0; i < n; ++i) {
        string room_type;
        int bedrooms;
        int bathrooms;
        cin >> room_type >> bedrooms >> bathrooms;
        if (room_type == "standard") {
            rooms.push_back(new HotelRoom(bedrooms, bathrooms));
        } else {
            rooms.push_back(new HotelApartment(bedrooms, bathrooms));
        }
    }

    int total_profit = 0;
    for (auto room : rooms) {
        total_profit += room->get_price();
    }
    cout << total_profit << endl;

    for (auto room : rooms) {
        delete room;
    }
    rooms.clear();

    return 0;
}
```

## Problem Solution Explanation

Now, let’s go through the code line by line:

```cpp
#include <iostream>
#include <vector>

using namespace std;
```
- **`#include <iostream>`**: Includes the input-output stream library to use `cin` and `cout` for reading input and printing output.
- **`#include <vector>`**: Includes the vector library to use the `vector` container.
- **`using namespace std;`**: Allows direct access to standard library names without the `std::` prefix.

#### **HotelRoom Class**

```cpp
class HotelRoom {
private:
    int bedrooms_;
    int bathrooms_;
    
public:
    HotelRoom(int bedrooms, int bathrooms) 
    : bedrooms_(bedrooms), bathrooms_(bathrooms) {}
    
    virtual int get_price() {
        return 50*bedrooms_ + 100*bathrooms_;
    }
};
```
- **`class HotelRoom`**: Defines the `HotelRoom` class.
- **`private:`**: Access specifier indicating that members below are private and can only be accessed within the class.
  - **`int bedrooms_;`**: Private integer member to store the number of bedrooms.
  - **`int bathrooms_;`**: Private integer member to store the number of bathrooms.
- **`public:`**: Access specifier indicating that members below are public and can be accessed from outside the class.
  - **`HotelRoom(int bedrooms, int bathrooms)`**: Constructor that initializes `bedrooms_` and `bathrooms_` with the given values.
  - **`virtual int get_price()`**: Virtual member function that calculates and returns the price of the room. Marked as `virtual` to allow polymorphism. The price calculation formula is `50 * bedrooms_ + 100 * bathrooms_`.

#### **HotelApartment Class**

```cpp
class HotelApartment : public HotelRoom {
public:
    HotelApartment(int bedrooms, int bathrooms) 
    : HotelRoom(bedrooms, bathrooms) {}

    int get_price() {
        return HotelRoom::get_price() + 100;
    }
};
```
- **`class HotelApartment : public HotelRoom`**: Defines `HotelApartment` as a subclass of `HotelRoom`. Inherits `bedrooms_`, `bathrooms_`, and the `get_price()` method.
- **`public:`**: Access specifier indicating that members below are public.
  - **`HotelApartment(int bedrooms, int bathrooms)`**: Constructor that initializes `bedrooms_` and `bathrooms_` using the base class constructor.
  - **`int get_price()`**: Overrides the `get_price()` method from `HotelRoom`. Calls the base class method using `HotelRoom::get_price()` and adds an additional 100 to account for the apartment's extra charge.

#### **Main Function**

```cpp
int main() {
    int n;
    cin >> n;
    vector<HotelRoom*> rooms;
    for (int i = 0; i < n; ++i) {
        string room_type;
        int bedrooms;
        int bathrooms;
        cin >> room_type >> bedrooms >> bathrooms;
        if (room_type == "standard") {
            rooms.push_back(new HotelRoom(bedrooms, bathrooms));
        } else {
            rooms.push_back(new HotelApartment(bedrooms, bathrooms));
        }
    }

    int total_profit = 0;
    for (auto room : rooms) {
        total_profit += room->get_price();
    }
    cout << total_profit << endl;

    for (auto room : rooms) {
        delete room;
    }
    rooms.clear();

    return 0;
}
```
- **`int main()`**: The main function, which is the entry point of the program.
- **`int n;`**: Declares an integer `n` to store the number of rooms.
- **`cin >> n;`**: Reads the number of rooms from the input.
- **`vector<HotelRoom*> rooms;`**: Declares a vector of pointers to `HotelRoom`, which will hold pointers to `HotelRoom` and `HotelApartment` objects.
- **`for (int i = 0; i < n; ++i)`**: Loop to process each room.
  - **`string room_type;`**: Declares a string to store the type of room.
  - **`int bedrooms;`** and **`int bathrooms;`**: Declares integers to store the number of bedrooms and bathrooms.
  - **`cin >> room_type >> bedrooms >> bathrooms;`**: Reads the room type, number of bedrooms, and number of bathrooms.
  - **`if (room_type == "standard")`**: Checks if the room type is `"standard"`. If so, creates a `HotelRoom` object and adds it to the `rooms` vector.
  - **`else`**: If the room type is not `"standard"`, assumes it is `"apartment"` and creates a `HotelApartment` object.
- **`int total_profit = 0;`**: Initializes `total_profit` to 0.
- **`for (auto room : rooms)`**: Iterates through each room in the vector.
  - **`total_profit += room->get_price();`**: Adds the price of each room to `total_profit`. Polymorphism ensures the correct `get_price()` method is called for each object type.
- **`cout << total_profit << endl;`**: Prints the total profit.
- **`for (auto room : rooms)`**: Iterates through the vector to deallocate memory.
  - **`delete room;`**: Deletes each dynamically allocated `HotelRoom` or `HotelApartment` object to free up memory.
- **`rooms.clear();`**: Clears the vector, though it's not strictly necessary since the program is ending.
- **`return 0;`**: Returns 0 to indicate successful execution.

### **Summary**

This code correctly implements the problem requirements by defining classes for different types of rooms, using polymorphism to compute room prices, and managing dynamic memory. The virtual keyword ensures that the appropriate `get_price()` method is called for each type of room, allowing for accurate profit calculation.
