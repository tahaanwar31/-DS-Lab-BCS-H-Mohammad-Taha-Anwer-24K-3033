#include <iostream>

using namespace std;

int calculateFactorial(int n){
    if(n==0 || n==1){
        return 1;
    }
    else{
        return n*calculateFactorial(n-1);
    }
}

int main(){
    cout<<calculateFactorial(4);
}