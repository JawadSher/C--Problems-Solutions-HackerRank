#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> integers(0);
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        
        integers.push_back(num);
    }
    
    int erase_index;
    cin >> erase_index;
    integers.erase(integers.begin() +erase_index -1);
    
    int erase_from, erase_to;
    cin >> erase_from >> erase_to;
    
    integers.erase(integers.begin() +erase_from -1, integers.begin() +erase_to -1);
    
    cout<<integers.size()<<endl;
    for(int i = 0; i < integers.size(); i++){
        cout<<integers[i]<<" ";
    }
    return 0;
}
