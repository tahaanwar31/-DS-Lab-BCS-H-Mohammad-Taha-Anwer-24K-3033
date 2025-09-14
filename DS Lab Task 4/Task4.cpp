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

    for(int i=1;i<size;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }

    cout<<"========================================\n";
    cout<<"sorted array: ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int target;
    cout<<"enter the target value: "<<endl;
    cin>>target;
    int left=0;
    int right=size-1;
    int found=-1;

    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]==target){
            found=mid;
            break;
        }
        else if(arr[mid]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }

    if(found!=-1){
        cout<<"target found at index "<<found<<endl;
    }
    else{
        cout<<"target not in array"<<endl;
    }
    cout<<"========================================\n";

    delete[] arr;
}