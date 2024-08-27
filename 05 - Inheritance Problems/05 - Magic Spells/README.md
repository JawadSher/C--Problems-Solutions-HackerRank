<h1 align='center'>Magic - Spells</h1>

## Problem Statement

**Problem URL :** [Magic Spells](https://www.hackerrank.com/challenges/magic-spells/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/1dfb1aa6-69f2-4b5e-9544-509ce85eccda)
![image](https://github.com/user-attachments/assets/1670e66c-44d9-4b90-9496-45d87c4a8e7f)

## Problem Explanation
The "Magic Spells" problem on HackerRank is a C++ challenge focused on object-oriented programming, particularly inheritance. Here's a breakdown of the problem:

### Problem Statement
You are given a base class and derived classes that represent different types of spells in a magical world. The goal is to handle various types of spells and output specific information based on the spell type.

### Classes and Inheritance Structure:
1. **Base Class: `Spell`**
   - This is an abstract base class from which other spell classes will inherit.
   - It has a pure virtual function `revealScrollName()`.

2. **Derived Classes:**
   - **`Fireball`**: Represents a fireball spell.
   - **`Frostbite`**: Represents a frostbite spell.
   - **`Thunderstorm`**: Represents a thunderstorm spell.
   - **`Waterbolt`**: Represents a waterbolt spell.

Each derived class overrides the `revealScrollName()` function to return a unique name based on the spell type and its power.

### Problem Requirements:
- You need to implement the logic to handle these spells and print specific information depending on the spell type.
- The input consists of a number of spells, and for each spell, you must determine its type, extract relevant information, and output it.

### Input Format:
- First, an integer `T`, the number of spells.
- For each spell:
  - A string indicating the type of the spell (`Fireball`, `Frostbite`, `Thunderstorm`, or `Waterbolt`).
  - An integer representing the power of the spell.

### Output Format:
- For each spell, print the name of the spell followed by its power.

### Example:
#### Input:
```
3
Fireball 5
Frostbite 10
Thunderstorm 7
```
#### Output:
```
Fireball:5
Frostbite:10
Thunderstorm:7
```

### Explanation:
1. **Base Class (`Spell`)**: This class has a pure virtual function `revealScrollName()` that must be overridden by any derived class.
2. **Derived Classes**: `Fireball`, `Frostbite`, `Thunderstorm`, and `Waterbolt` inherit from `Spell` and implement the `revealScrollName()` function.
3. **counterspell() Function**: This function takes a pointer to a `Spell` object and prints the result of the `revealScrollName()` function.
4. **identifySpell() Function**: This function determines the type of spell and creates the appropriate derived class object.

### Key Concepts:
- **Inheritance**: The problem illustrates how different classes can inherit from a common base class.
- **Polymorphism**: By using pointers to the base class (`Spell`), you can call the `revealScrollName()` function on any derived class object without knowing its exact type at compile time.

This problem is a great exercise in understanding and applying inheritance and polymorphism in C++.

## Problem Solution
```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

    if(Fireball* fb = dynamic_cast<Fireball*>(spell)){
        fb->revealFirepower();
    }else if(Frostbite* frb = dynamic_cast<Frostbite*>(spell)){
        frb->revealFrostpower();
    }else if(Thunderstorm* ts = dynamic_cast<Thunderstorm*>(spell)){
        ts->revealThunderpower();
    }else if(Waterbolt* wb = dynamic_cast<Waterbolt*>(spell)){
        wb->revealWaterpower();
    }else{
        string scrollName = spell->revealScrollName();
        string journal = SpellJournal::read();
        
        int m = scrollName.length();
        int n = journal.length();
        
        vector<vector<int>> dp(m+1,vector<int>( n+1, 0));
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(scrollName[i-1] == journal[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        cout<<dp[m][n]<<endl;
    }

}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}
```

## Problem Solution Explanation

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;
```

- **Includes**:
  - `<iostream>`: For input and output operations (e.g., `cin`, `cout`).
  - `<vector>`: For using the `vector` container.
  - `<string>`: For using the `string` class.

- **`using namespace std;`**: Allows direct use of standard library names without prefixing them with `std::`.

```cpp
class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};
```

- **`class Spell`**:
  - Represents a base class for all spells.
  - **Private Attributes**:
    - `string scrollName`: Stores the name of the spell.
  - **Public Methods**:
    - **Default Constructor**: Initializes `scrollName` to an empty string.
    - **Parameterized Constructor**: Initializes `scrollName` with the provided `name`.
    - **Destructor**: Virtual destructor (ensures proper cleanup for derived classes).
    - **`revealScrollName()`**: Returns the `scrollName`.

```cpp
class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};
```

- **`class Fireball`**:
  - Inherits from `Spell`.
  - **Private Attributes**:
    - `int power`: Stores the power of the fireball spell.
  - **Public Methods**:
    - **Constructor**: Initializes `power` with the provided value.
    - **`revealFirepower()`**: Prints the spell type and power.

```cpp
class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};
```

- **`class Frostbite`**:
  - Inherits from `Spell`.
  - **Private Attributes**:
    - `int power`: Stores the power of the frostbite spell.
  - **Public Methods**:
    - **Constructor**: Initializes `power` with the provided value.
    - **`revealFrostpower()`**: Prints the spell type and power.

```cpp
class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};
```

- **`class Thunderstorm`**:
  - Inherits from `Spell`.
  - **Private Attributes**:
    - `int power`: Stores the power of the thunderstorm spell.
  - **Public Methods**:
    - **Constructor**: Initializes `power` with the provided value.
    - **`revealThunderpower()`**: Prints the spell type and power.

```cpp
class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};
```

- **`class Waterbolt`**:
  - Inherits from `Spell`.
  - **Private Attributes**:
    - `int power`: Stores the power of the waterbolt spell.
  - **Public Methods**:
    - **Constructor**: Initializes `power` with the provided value.
    - **`revealWaterpower()`**: Prints the spell type and power.

```cpp
class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";
```

- **`class SpellJournal`**:
  - Provides a static journal entry.
  - **Static Attributes**:
    - `string journal`: Stores the journal entry.
  - **Static Methods**:
    - **`read()`**: Returns the current journal entry.
  - **`string SpellJournal::journal = "";`**: Initializes the static journal entry to an empty string.

```cpp
void counterspell(Spell *spell) {
    if(Fireball* fb = dynamic_cast<Fireball*>(spell)){
        fb->revealFirepower();
    }else if(Frostbite* frb = dynamic_cast<Frostbite*>(spell)){
        frb->revealFrostpower();
    }else if(Thunderstorm* ts = dynamic_cast<Thunderstorm*>(spell)){
        ts->revealThunderpower();
    }else if(Waterbolt* wb = dynamic_cast<Waterbolt*>(spell)){
        wb->revealWaterpower();
    }else{
        string scrollName = spell->revealScrollName();
        string journal = SpellJournal::read();
        
        int m = scrollName.length();
        int n = journal.length();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(scrollName[i-1] == journal[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        cout << dp[m][n] << endl;
    }
}
```

- **`void counterspell(Spell *spell)`**:
  - **Purpose**: Processes the spell based on its type.
  - **Dynamic Cast**: 
    - Checks if `spell` is of type `Fireball`, `Frostbite`, `Thunderstorm`, or `Waterbolt`.
    - Calls the respective `revealPower()` method.
  - **If Not a Known Type**:
    - Retrieves the spell’s name and the journal entry.
    - Initializes a 2D vector `dp` for the dynamic programming table used to find the longest common subsequence (LCS).
    - **Filling the `dp` Table**:
      - Iterates through characters of `scrollName` and `journal` to populate the `dp` table.
      - Updates `dp[i][j]` based on character matches and previous values.
    - **Prints**: The length of the longest common subsequence.

```cpp
class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};
```

- **`class Wizard`**:
  - **Purpose**: Allows casting spells.
  - **`cast()` Method**:
    - Reads input to determine the spell type and power.
    - Creates the appropriate `Spell` object based on the input.
    - If the input type is unknown, it creates a generic `Spell` object and reads a journal entry.

```cpp
int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}
```

- **`int main()`**:
  - **Purpose**: Main program execution.
  - Reads the number of test cases `T`.
  - Creates a `Wizard` object `Arawn`.
  - **Loop**:
    - For each test case, casts a spell using `Arawn.cast()` and processes it with `counterspell()`.
  - Returns `0` indicating successful execution.

### Sample Output

**Input**:
```
2
fire 10
frost 20
```

**Explanation**:
- **First Test Case**:
  - Input: `fire 10`
  - Creates a `Fireball` object with power `10`.
  - `counterspell()` calls `revealFirepower()` which prints: `Fireball: 10`.
- **Second Test Case**:
  - Input: `frost 20`
  - Creates a `Frostbite` object with power `20`.
  - `counterspell()` calls `revealFrostpower()` which prints: `Frostbite: 20`.

**Output**:
```
Fireball: 10
Frostbite: 20
```

