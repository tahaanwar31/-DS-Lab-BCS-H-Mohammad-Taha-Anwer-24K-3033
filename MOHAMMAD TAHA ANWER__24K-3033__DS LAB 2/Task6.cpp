#include <iostream>
#include <string>
using namespace std;

class SafePointer{
    int* ptr;
public:
    SafePointer(){
        ptr=new int;
    }
    void setValue(int value){
        *ptr=value;
    }
    int getValue(){
        return *ptr;
    }
    void release(){
        delete ptr;
        ptr=nullptr;
    }
};

int main(){
    int size=5;
    SafePointer* students=new SafePointer[size];

    for(int i=0;i<size;i++){
        int mark;
        cout<<"Enter marks for student "<<i+1<<": ";
        cin>>mark;
        if(i>=size){
            cout<<"Index out of range\n";
            return 1;
        }
        students[i].setValue(mark);
    }

    cout<<"MARKS OF STUDENTS:\n";
    for(int i=0;i<size;i++){
        if(i>=size){
            cout<<"Index out of range\n";
            return 1;
        }
        cout<<"Student "<<i+1<<": "<<students[i].getValue()<<endl;
    }

    for(int i=0;i<size;i++){
        students[i].release();
    }
    delete[] students;
}