#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    set<int> s;
    for(int i = 0; i < n; i++){
        int query_type, query_value;
        
        cin >> query_type >> query_value;
        
        if(query_type == 1){
            s.insert(query_value);
        }else if(query_type == 2){
            s.erase(query_value);
        }else if(query_type == 3){
            set<int>:: iterator it = s.find(query_value);
            
            if(it != s.end()){
                cout<<"Yes"<<endl;
            }else{
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}
