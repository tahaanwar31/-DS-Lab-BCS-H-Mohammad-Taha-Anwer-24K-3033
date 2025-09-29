#include <iostream>

using namespace std;

//PART 1
int printNumbers(int n){
    cout<<n<<",";
    if(n==1){
        return 1;
    }
    else{
        return (printNumbers(n-1));
    }
}
int main(){
    printNumbers(5);
}

//PART 2

void functionA(int n){
    if (n <= 0) {
        return; 
    }
    cout << "A: " << n << endl;
    functionB(n - 1); 
}

void functionB(int n) {
    if (n<=0) {
        return; 
    }
    cout<<"B: "<<n<<endl;
    functionA(n - 1); 
}

int main() {
functionA(5); 
    return 0;
}
