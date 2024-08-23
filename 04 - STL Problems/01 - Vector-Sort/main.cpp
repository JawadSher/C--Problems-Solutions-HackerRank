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
        cin>> num;
        
        integers.push_back(num);
    }
    sort(integers.begin(), integers.end());
        
    for(int i = 0; i < integers.size(); i++){
        cout<<integers[i]<<" ";
    }
    return 0;
}
