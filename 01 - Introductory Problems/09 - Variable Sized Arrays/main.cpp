#include<iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){

   int n, q;
   cin>> n >> q;
   
   vector<int> array[n];
   
   for(int i = 0; i < n; i++){
       int k;
       cin>>k;
       
       for(int j = 0; j < k; j++){
           int l;
           cin>>l;
           array[i].push_back(l);
       }
   }
   
   for(int i = 0; i < q; i++){
       int m, n;
       cin>> m >> n;
       
       cout<<array[m].at(n)<<endl;
   }
    return 0;
}
