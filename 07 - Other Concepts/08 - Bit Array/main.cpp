#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;


int main() {
    int N, S, P, Q;
    int mod = (1 << 31);
    
    
    int tortoise = S % mod;
    int here = tortoise;
    
    int count = 0;
    
    while(count < N){
        count++;
        tortoise = (tortoise * P + Q) % mod;
        
        here = (here * P + Q) % mod;
        here = (here * P + Q) % mod;
        
        if(here == tortoise) break;
    }
    cout<< count;
    return 0;
}
