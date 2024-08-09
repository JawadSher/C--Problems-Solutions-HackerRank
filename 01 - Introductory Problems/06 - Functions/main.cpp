#include<iostream>
using namespace std;

int four_nums(int a, int b, int c, int d){
    if (a > b && a > c && a > d ) {
        return a;
    }
    else if(b > c && b > a && b > d){
        return b;
    }
    else if(c > d && c > a && c > b){
        return c;
    }
    else if(d > a && d > b && d > c){
        return d;
    } 
    else {
        return a;
    }
}

int main(){
    int h1,h2,h3,h4;
    cin>> h1>> h2>> h3>> h4;
    cout<<four_nums(h1,h2,h3,h4);
    return 0;
}
