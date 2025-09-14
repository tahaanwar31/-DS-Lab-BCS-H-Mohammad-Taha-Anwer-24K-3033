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

    int target;
    cout<<"enter the target value: "<<endl;
    cin>>target;
    int left=0;
    int right=size-1;
    int found=-1;

    while(left<=right && arr[left]<=target && arr[right]>=target){
        int pos=left+((target-arr[left])*(right-left))/(arr[right]-arr[left]);
        if(arr[pos]==target){
            found=pos;
            break;
        }
        else if(arr[pos]<target){
            left=pos+1;
        }
        else{
            right=pos-1;
        }
    }

    cout<<"========================================\n";
    if(found!=-1){
        cout<<"target found at index "<<found<<endl;
    }
    else{
        cout<<"target not in array"<<endl;
    }
    cout<<"========================================\n";

    delete[] arr;
}