#include <iostream>
#include <string>

using namespace std;

int main(){
    int benches,seats;

    cout<<"Enter the number of benches: \n";
    cin>>benches;

    cout<<"Enter the number of seats: \n";
    cin>>seats;
    
    //benches are rows and seats are columns

    int** arr=new int* [benches];
    for (int i=0;i<benches;i++){
        arr[i]=new int[seats];
    } 

    cout<<"===============================\n";
    cout<<"ARRAY CREATED\n";
    cout<<"===============================\n";

    for (int i=0;i<benches;i++){
        for (int j=0;j<seats;j++){
            arr[i][j]=0;
        }
    }

    cout<<"===============================\n";
    cout<<"UPDATING VALUES IN THE ARRAY\n";
    cout<<"===============================\n";

    for (int i=0;i<benches;i++){
        for (int j=0;j<seats;j++){
            cout<<"Enter 1 if 'bench: "<<i+1<<" seat: "<<j+1<<"' is filled: \n";
            int n;
            cin>>n;
            if(n==1){
                arr[i][j]=1;
            }

        }
    }

    cout<<"===============================\n";
    cout<<"VALUES UPDATED IN THE ARRAY\n";
    cout<<"===============================\n";


    
    cout<<"===============================\n";
    cout<<"PRINTING THE SEATING ARRANGEMENT\n";
    cout<<"===============================\n";


    for (int i=0;i<benches;i++){
        for (int j=0;j<seats;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }



}
