#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
void  update(int *a , int *b){
    
    int q = *a;
    int w = *b;
    cout<<(q + w)<<endl;
    cout<<abs(q-w)<<endl;
}

int main() {
    
    int z , x;
    cin>>z>>x;
    update(&x,&z);     
  
    return 0;
}
