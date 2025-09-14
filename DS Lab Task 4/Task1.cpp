#include <iostream>
#include <string>
using namespace std;

int main(){
    int size;
    cout<<"enter the array size: "<<endl;
    cin>>size;
    int* arr=new int[size];

    for(int i=0;i<size;i++){
        cout<<"enter number for index "<<i<<endl;
        cin>>arr[i];
    }

    int searchvalue;
    cout<<"enter the searchvalue value: "<<endl;
    cin>> searchvalue;
    int found=-1;

    for(int i=0;i<size;i++){
        if(arr[i]= searchvalue){
            found=i;
            break;
        }
    }

    cout<<"========================================\n";
    if(found!=-1){
        cout<< "Value was found at index "<<found<<endl;
    }
    else{
        cout<<"Value not found"<<endl;
    }
    cout<<"========================================\n";

    delete[] arr;
}