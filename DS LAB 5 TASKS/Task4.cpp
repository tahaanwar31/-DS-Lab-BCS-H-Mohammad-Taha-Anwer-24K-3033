#include <iostream>

using namespace std;

int ackermann(int m, int n){
    if(m==0){
        return n+1;
    }
    else if(m>0 && n==0){
        return ackermann(m-1,1);
    }
    else if(m>0 && n>0){
        return ackermann(m-1,ackermann(m,n-1));
    }
    return -1;
}

int main(){
    int m;
    int n;
    cout<<"Enter value of m: ";
    cin>>m;
    cout<<"Enter value of n: ";
    cin>>n;
    cout<<"Ackermann of ("<<m<<","<<n<<") is "<<ackermann(m,n)<<endl;
}
