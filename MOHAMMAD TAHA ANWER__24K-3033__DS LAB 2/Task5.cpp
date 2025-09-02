#include <iostream>
#include <string>
using namespace std;

int main(){
    int rows,cols;
    cout<<"Enter number of rows: ";
    cin>>rows;
    cout<<"Enter number of columns: ";
    cin>>cols;

    if(rows<=0 || cols<=0){
        cout<<"Invalid input for rows and columns\n";
        return 1;
    }

    int** arr1=new int*[rows];
    for(int i=0;i<rows;i++){
        arr1[i]=new int[cols];
    }

    int** arr2=new int*[rows];
    for(int i=0;i<rows;i++){
        arr2[i]=new int[cols];
    }

    cout<<"Enter elements for the array1:\n";
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(i>=rows || j>=cols){
                cout<<"Index out of range\n";
                return 1;
            }
            cout<<"Element ["<<i+1<<"]["<<j+1<<"]: ";
            cin>>arr1[i][j];
        }
    }

    cout<<"Enter elements for array2:\n";
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(i>=rows || j>=cols){
                cout<<"Index out of range\n";
                return 1;
            }
            cout<<"Element ["<<i+1<<"]["<<j+1<<"]: ";
            cin>>arr2[i][j];
        }
    }

    int** sum=new int*[rows];
    for(int i=0;i<rows;i++){
        sum[i]=new int[cols];
    }

    int** diff=new int*[rows];
    for(int i=0;i<rows;i++){
        diff[i]=new int[cols];
    }

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(i>=rows || j>=cols){
                cout<<"Index out of bounds\n";
                return 1;
            }
            sum[i][j]=arr1[i][j]+arr2[i][j];
            diff[i][j]=arr1[i][j]-arr2[i][j];
        }
    }

    cout<<"SUM OF MATRICES:\n";
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(i>=rows || j>=cols){
                cout<<"Index out of range\n";
                return 1;
            }
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"DIFFERENCE OF MATRICES:\n";
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(i>=rows || j>=cols){
                cout<<"Index out of range\n";
                return 1;
            }
            cout<<diff[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<rows;i++){
        delete[] arr1[i];
        delete[] arr2[i];
        delete[] sum[i];
        delete[] diff[i];
    }

    delete[] arr1;
    delete[] arr2;
    delete[] sum;
    delete[] diff;
}
