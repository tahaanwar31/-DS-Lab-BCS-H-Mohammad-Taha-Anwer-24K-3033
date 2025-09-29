#include <iostream>

using namespace std;

void sumTail(int n, int total){
    if(n==0){
        cout<< total;
        return;
    }
    else{
        sumTail(n-1,total+n);
    }
}

int sumNonTail(int n){
    if(n==0){
        return 0;
    }
    else{
        return(n+sumNonTail(n-1));
    }
}
int main(){
    cout<<"Tail: ";
    sumTail(5,0);
    cout<<endl;
    
    cout<<"Non Tail: "<< sumNonTail(5);
}

/*
n tail recursion the recursive call is the last step so nothing is left 
after it returns and the stack does not grow deep while in non tail 
recursion some work is left after the recursive call so each call stays 
in memory until the end and the call stack grows deeper
*/