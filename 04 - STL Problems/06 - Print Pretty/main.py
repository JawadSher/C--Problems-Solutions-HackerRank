#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    double A, B, C;
    
    for(int i = 0; i < t; i++){
        cin >> A >> B >> C;
        
        long long truncated = static_cast<long long>(A);
        cout<<"0x"<<hex<<nouppercase<<truncated<<endl;
        
        cout<<setw(15)<<setfill('_')<<showpos<<fixed<<setprecision(2)<<B<<endl;
        
        cout<<noshowpos<<scientific<<uppercase<<setprecision(9)<<C<<endl;
    } 
    return 0;
}
