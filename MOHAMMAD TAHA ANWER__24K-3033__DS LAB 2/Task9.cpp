#include <iostream>
#include <string>
using namespace std;

int main(){
    int rows;
    cout<<"Enter the number of rows: "<<endl;
    cin>>rows;
    int cols;
    cout<<"Enter the number of columns: "<<endl;
    cin>>cols;

    float** matrix=new float*[rows];
    for(int i=0;i<rows;i++){
        matrix[i]=new float[cols];
    }

    for(int i=0;i<rows;i++){
        cout<<"Start entering elements for Row:"<<i+1<<"\n";
        for(int j=0;j<cols;j++){
            cout<<"Column: "<<j+1<<endl;
            cin>>matrix[i][j];
        }
    }

    cout<<"========================================\n";
    cout<<"MATRIX IN NORMAL FORM\n";
    cout<<"========================================\n";
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    int nonZero=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i][j]!=0){
                nonZero++;
            }
        }
    }

    float** compressed=new float*[nonZero];
    for(int i=0;i<nonZero;i++){
        compressed[i]=new float[3];
    }

    int k=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(matrix[i][j]!=0){
                compressed[k][0]=i+1;
                compressed[k][1]=j+1;
                compressed[k][2]=matrix[i][j];
                k++;
            }
        }
    }

    cout<<"========================================\n";
    cout<<"MATRIX IN COMPRESSED FORM (ROW, COLUMN, VALUE)\n";
    cout<<"========================================\n";
    for(int i=0;i<nonZero;i++){
        cout<<compressed[i][0]<<" "<<compressed[i][1]<<" "<<compressed[i][2]<<endl;
    }
    cout<<"========================================\n";

    for(int i=0;i<rows;i++){
        delete[] matrix[i];
    }
    delete[] matrix;

    for(int i=0;i<nonZero;i++){
        delete[] compressed[i];
    }
    delete[] compressed;
}