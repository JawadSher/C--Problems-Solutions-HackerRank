#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    
    vector<int> sorted_nums(0);
    
    for(int i=0; i < n; i++){
        int num;
        cin >> num;
        sorted_nums.push_back(num);
    } 
    
    int num_queries;
    cin >> num_queries;
    
    for(int i=0; i < num_queries; i++){
        int num;
        cin>> num;
        vector<int>::iterator x;
        
        x = lower_bound(sorted_nums.begin(), sorted_nums.end(), num);
        int index = x - sorted_nums.begin();
        
        if(index < sorted_nums.size() && sorted_nums[index] == num){
            cout<<"Yes"<<" "<<index+1<<endl;
        }else{
            cout<<"No"<<" "<<index+1<<endl;
        }
        
    }
    return 0;
}
