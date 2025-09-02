#include <iostream>
#include <string>

using namespace std;

int main(){
    int students;
    cout<<"Enter the number of students: "<<endl;
    cin>>students;

    int** arr=new int*[students];
    int size[students];

    for (int i=0;i<students;i++){
        cout<<"Enter the number of courses Student:"<<i+1<<" takes\n";
        cin>>size[i];

        arr[i]=new int[size[i]];
    }

    for (int i=0;i<students;i++){
        cout<<"Start entering marks for the courses Student:"<<i+1<<" takes\n";
        for (int j=0;j<size[i];j++){
            cout<<"Course: "<<j+1<<endl;
            cin>>arr[i][j];
        }
    }

    cout<<"========================================\n";
    cout<<"DISPLAYING AVERAGE MARKS OF EACH STUDENT\n";
    cout<<"========================================\n";
    for (int i=0;i<students;i++){
        cout<<"Student: "<<i+1<<" ";
        int total,average;
        for (int j=0;j<size[i];j++){
            total=total+arr[i][j];
        }
        average=total/size[i];
        cout<<average<<endl;
    }

    for (int i=0;i<students;i++){
        delete[] arr[i];
    }

    delete[] arr;

}