#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    map<string, int> Student_info;
    cin.ignore();

    for(int i = 0; i < Q; i++){
        int query_type;
        string stdnt_name;
        int stdnt_marks;
        
        cin >> query_type;
        
        if(query_type == 1){
            cin >> stdnt_name >> stdnt_marks;
            Student_info[stdnt_name] += stdnt_marks;
            
        }else if(query_type == 2){
            cin >> stdnt_name;
            Student_info.erase(stdnt_name);
            
        }else if(query_type == 3){
            cin >> stdnt_name;
            if(Student_info.find(stdnt_name) != Student_info.end()){
                cout<< Student_info[stdnt_name] <<endl;
            }else{
                cout<< 0 << endl;
            }

            
        }
    }

    return 0;
}
