#include <iostream>
#include <string>

using namespace std;

int main(){
    int size;
    cout<<"Enter the size of the array: "<<endl;
    cin>>size;
    int* arr=new int[size];
    for (int i=0;i<size;i++){
        arr[i]=0;
    }
    cout<<"===============================\n";

    cout<<"ARRAY CREATED"<<endl;

    cout<<"===============================\n";


    int flag=0;
    while (flag==0){
        cout<<"Enter the number of the index where you want to update the value or enter -1 if you are done\n";
        int n;
        cin>>n;
        if (n==-1){
            flag=1;
        }
        else{
            cout<<"Enter the new value: \n";
            cin>>arr[n];
            cout<<"===============================\n";

            cout<<"VALUE UPDATED\n";

            cout<<"===============================\n";

        }
    }

    cout<<"===============================\n";

    cout<<"PRINTING THE ARRAY\n";

    cout<<"===============================\n";

    for (int i=0;i<size;i++){
        cout<<arr[i]<<", ";
    }
    cout<<"\n";

    cout<<"===============================\n";

    cout<<"DEALLOCATING THE MEMORY\n";

    cout<<"===============================\n";

    delete[]arr;

    cout<<"PROGRAM TERMINATED";
}

