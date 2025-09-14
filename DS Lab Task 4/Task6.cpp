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

    int gap=size;
    float shrink=1.3;
    int swaps=0;
    int comparisons=0;
    bool swapped=false;

    do{
        gap=(int)(gap/shrink);
        if(gap<1){
            gap=1;
        }
        swapped=false;
        for(int i=0;i<size-gap;i++){
            comparisons++;
            if(arr[i]>arr[i+gap]){
                int temp=arr[i];
                arr[i]=arr[i+gap];
                arr[i+gap]=temp;
                swaps++;
                swapped=true;
            }
        }
    }while(gap>1 || swapped==true);

    cout<<"========================================\n";
    cout<<"sorted array: ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"total swaps: "<<swaps<<endl;
    cout<<"total comparisons: "<<comparisons<<endl;
    cout<<"========================================\n";

    delete[] arr;
}