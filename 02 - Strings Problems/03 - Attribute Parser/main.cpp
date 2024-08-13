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
