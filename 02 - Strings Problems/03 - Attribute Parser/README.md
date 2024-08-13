<h1 align='center'>Attribute - Parser</h1>

## Problem Statement

**Problem URL :** [Attribute Parser](https://www.hackerrank.com/challenges/attribute-parser/problem?isFullScreen=true)

![image](https://github.com/user-attachments/assets/cb77572a-1ecb-4077-83cb-295e2ab098f8)
![image](https://github.com/user-attachments/assets/8ee5b214-85f3-4536-8ccc-9614b62b2013)
![image](https://github.com/user-attachments/assets/f82c8490-d042-4b64-9632-6d1641d46dd0)


## Problem Explanation

The problem involves parsing and querying HTML-like tag attributes. Given a list of tags and their attributes, you need to extract the attribute values based on queries.

1. **Input Format**:
   - The first line contains two integers: `num_lines` (the number of lines with tags and attributes) and `query_lines` (the number of queries).
   - The next `num_lines` lines contain HTML-like tags and attributes in the format:
     - `<tagname attribute="value" attribute2="value2">`
     - `</tagname>`
   - The following `query_lines` lines each contain a query in the format `tag1.tag2~attribute`, which requests the value of the attribute within the nested tag structure.

2. **Output Format**:
   - For each query, output the value of the attribute if it exists, otherwise print "Not Found!".



## Problem Solution 
```cpp
#include<iostream>
#include<vector>
#include<sstream>
#include<unordered_map>

using namespace std;
int main(){
    int num_lines, query_lines;
    cin>> num_lines >> query_lines;
    
    unordered_map<string, string> attribute_map;
    vector<string> tag_stack;
    
    string tag, attribute, value;
    char unwanted_char, equal_sign;
    
    for(int i = 0; i < num_lines; i++){
        string line;
        getline(cin >> ws, line);
        
        stringstream line_stream(line);
        line_stream >> unwanted_char >> tag;
        
        if(tag.front() != '/' && tag.back() == '>'){
            tag.pop_back();
            tag_stack.push_back(tag);
            continue;
        }else if(tag[0] != '/'){
            tag_stack.push_back(tag);
            
            do {
                string key;
                line_stream >> attribute >> equal_sign >> value;
                int total_chars_to_remove = (value.back() == '>') ? 3 : 2;
                
                for(const string& t : tag_stack){
                    key += t + '.';
                }
                
                key.pop_back();
                key = key + '~' + attribute;
                attribute_map[key] = value.substr(1, value.size() - total_chars_to_remove);
            }while(value.back() != '>');
        }else{
            tag_stack.pop_back();
        }
    }
    
    while(query_lines--){
        string query;
        getline(cin, query);
        
        if(attribute_map.count(query) > 0){
            cout<<attribute_map[query]<<endl;
        }else{
            cout<<"Not Found!"<<endl;
        }
    }
    
    
    return 0;
}
```

## Problem Solution Explanation
Let's go through the source code line by line and explain its logic for beginners:

```cpp
#include<iostream>
#include<vector>
#include<sstream>
#include<unordered_map>

using namespace std;

int main() {
    int num_lines, query_lines;
    cin >> num_lines >> query_lines;
```

1. **Include Libraries**:
   - `#include<iostream>`: For input and output operations.
   - `#include<vector>`: To use the vector container.
   - `#include<sstream>`: For string stream operations, which help in parsing.
   - `#include<unordered_map>`: For using hash tables to store key-value pairs.

2. **Namespace**:
   - `using namespace std;`: Allows using standard library features without prefixing them with `std::`.

3. **Main Function**:
   - `int main() {`: The starting point of the program.

4. **Read Input Counts**:
   - `cin >> num_lines >> query_lines;`: Read the number of lines containing tags (`num_lines`) and the number of queries (`query_lines`) from the input.

```cpp
    unordered_map<string, string> attribute_map;
    vector<string> tag_stack;
    
    string tag, attribute, value;
    char unwanted_char, equal_sign;
```

5. **Initialize Data Structures**:
   - `unordered_map<string, string> attribute_map;`: A hash table to store attributes with a combination of tag paths as keys and attribute values as values.
   - `vector<string> tag_stack;`: A stack (implemented using a vector) to keep track of the currently open tags.

6. **Variable Declarations**:
   - `string tag, attribute, value;`: Strings to store tag names, attribute names, and attribute values respectively.
   - `char unwanted_char, equal_sign;`: Characters to handle unwanted characters (like `<`) and the equal sign (`=`) in attributes.

```cpp
    for (int i = 0; i < num_lines; i++) {
        string line;
        getline(cin >> ws, line);
```

7. **Process Each Line of Tags**:
   - `for (int i = 0; i < num_lines; i++) {`: Loop to process each tag line.
   - `getline(cin >> ws, line);`: Read a full line of input into the string `line`. `>> ws` ignores any leading whitespace.

```cpp
        stringstream line_stream(line);
        line_stream >> unwanted_char >> tag;
```

8. **Parse the Line**:
   - `stringstream line_stream(line);`: Create a string stream to parse the line.
   - `line_stream >> unwanted_char >> tag;`: Read the first character (`<` or `</`) into `unwanted_char` and the tag name into `tag`.

```cpp
        if (tag.front() != '/' && tag.back() == '>') {
            tag.pop_back(); // Remove trailing '>'
            tag_stack.push_back(tag); // Push tag onto stack
            continue;
        } 
```

9. **Handle Opening Tags**:
   - `if (tag.front() != '/' && tag.back() == '>')`: Check if the tag is an opening tag (does not start with `/` and ends with `>`).
   - `tag.pop_back();`: Remove the trailing `>` from the tag name.
   - `tag_stack.push_back(tag);`: Push the tag onto the `tag_stack` to keep track of the current tag context.
   - `continue;`: Skip to the next line since the current line is processed.

```cpp
        else if (tag[0] != '/') {
            tag_stack.push_back(tag); // Push tag onto stack
            
            do {
                string key;
                line_stream >> attribute >> equal_sign >> value;
                int total_chars_to_remove = (value.back() == '>') ? 3 : 2;
```

10. **Handle Tags with Attributes**:
    - `else if (tag[0] != '/')`: Check if the tag is not a closing tag (does not start with `/`).
    - `tag_stack.push_back(tag);`: Push the tag onto the stack.
    - `do { ... } while (value.back() != '>');`: Loop to process all attributes in the current tag until the closing `>` of the tag is found.

```cpp
                for (const string& t : tag_stack) {
                    key += t + '.'; // Build the key using tags
                }
                
                key.pop_back(); // Remove trailing '.'
                key = key + '~' + attribute; // Append attribute name
                attribute_map[key] = value.substr(1, value.size() - total_chars_to_remove); // Store attribute value
            } while (value.back() != '>'); // Continue until end of tag
        }
        else {
            tag_stack.pop_back(); // Remove tag from stack
        }
    }
```

11. **Processing Attributes**:
    - `for (const string& t : tag_stack) { key += t + '.'; }`: Build the key by concatenating the tags in `tag_stack`, separated by dots.
    - `key.pop_back();`: Remove the trailing dot from the key.
    - `key = key + '~' + attribute;`: Append `~` and the attribute name to the key.
    - `attribute_map[key] = value.substr(1, value.size() - total_chars_to_remove);`: Store the attribute value in the map, removing the leading `"` and trailing `"` or `">"`.

12. **Handle Closing Tags**:
    - `else { tag_stack.pop_back(); }`: If the tag is a closing tag, remove the top tag from `tag_stack`.

```cpp
    while (query_lines--) {
        string query;
        getline(cin, query);
        
        if (attribute_map.count(query) > 0) {
            cout << attribute_map[query] << endl; // Print attribute value
        } else {
            cout << "Not Found!" << endl; // Print "Not Found!" if attribute does not exist
        }
    }
    
    return 0;
}
```

13. **Process Queries**:
    - `while (query_lines--) {`: Loop through each query.
    - `getline(cin, query);`: Read each query line.
    - `if (attribute_map.count(query) > 0)`: Check if the query key exists in the map.
    - `cout << attribute_map[query] << endl;`: If the key exists, print the corresponding value.
    - `else { cout << "Not Found!" << endl; }`: If the key does not exist, print `"Not Found!"`.

14. **End of Program**:
    - `return 0;`: Exit the program successfully.

### Summary

- **Tag Handling**: Tags and their attributes are processed to build a key-value mapping of attributes.
- **Attribute Extraction**: Attributes are stored in a hash table with a unique key representing the tag hierarchy.
- **Query Handling**: Queries are checked against the hash table to retrieve and print the corresponding attribute values or indicate that they are not found.
