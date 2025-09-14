#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int main(){
    int size;
    cout<<"enter the array size: "<<endl;
    cin>>size;
    int* numbers=new int[size];

    for(int i=0;i<size;i++){
        cout<<"enter number for index "<<i<<endl;
        cin>>numbers[i];
    }

    int* shellnums=new int[size];
    int* bubblenums=new int[size];
    int* insertnums=new int[size];
    for(int i=0;i<size;i++){
        shellnums[i]=numbers[i];
        bubblenums[i]=numbers[i];
        insertnums[i]=numbers[i];
    }

    clock_t start=clock();
    int shellcomp=0;
    int shellswap=0;
    int gap=size/2;
    while(gap>0){
        for(int i=gap;i<size;i++){
            int temp=shellnums[i];
            int j=i;
            while(j>=gap && shellnums[j-gap]>temp){
                shellcomp++;
                shellnums[j]=shellnums[j-gap];
                shellswap++;
                j=j-gap;
            }
            shellnums[j]=temp;
            shellswap++;
        }
        gap=gap/2;
    }
    clock_t shellend=clock();
    double shelltime=(double)(shellend-start)/CLOCKS_PER_SEC;

    start=clock();
    int bubblecomp=0;
    int bubbleswap=0;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            bubblecomp++;
            if(bubblenums[j]>bubblenums[j+1]){
                int temp=bubblenums[j];
                bubblenums[j]=bubblenums[j+1];
                bubblenums[j+1]=temp;
                bubbleswap++;
            }
        }
    }
    clock_t bubbleend=clock();
    double bubbletime=(double)(bubbleend-start)/CLOCKS_PER_SEC;

    start=clock();
    int insertcomp=0;
    int insertswap=0;
    for(int i=1;i<size;i++){
        int key=insertnums[i];
        int j=i-1;
        while(j>=0 && insertnums[j]>key){
            insertcomp++;
            insertnums[j+1]=insertnums[j];
            insertswap++;
            j--;
        }
        insertnums[j+1]=key;
        insertswap++;
    }
    clock_t insertend=clock();
    double inserttime=(double)(insertend-start)/CLOCKS_PER_SEC;

    cout<<"========================================\n";
    cout<<"shell sort time: "<<shelltime<<" seconds"<<endl;
    cout<<"shell comparisons: "<<shellcomp<<endl;
    cout<<"shell swaps: "<<shellswap<<endl;
    cout<<"bubble sort time: "<<bubbletime<<" seconds"<<endl;
    cout<<"bubble comparisons: "<<bubblecomp<<endl;
    cout<<"bubble swaps: "<<bubbleswap<<endl;
    cout<<"insertion sort time: "<<inserttime<<" seconds"<<endl;
    cout<<"insertion comparisons: "<<insertcomp<<endl;
    cout<<"insertion swaps: "<<insertswap<<endl;
    cout<<"========================================\n";

    delete[] numbers;
    delete[] shellnums;
    delete[] bubblenums;
    delete[] insertnums;
}