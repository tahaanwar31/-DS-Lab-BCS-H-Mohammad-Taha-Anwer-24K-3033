#include <iostream>
#include <string>
using namespace std;

int main(){
    int months;
    cout<<"Enter the number of months: ";
    cin>>months;

    int* expenses=new int[months];

    for(int i=0;i<months;i++){
        cout<<"Enter expense for month "<<i+1<<": ";
        cin>>expenses[i];
    }

    string resize;
    cout<<"Enter y if you want to add more months else enter n: ";
    cin>>resize;

    if(resize=="y"){
        int newMonths;
        cout<<"Enter additional months: ";
        cin>>newMonths;

        int* temp=new int[months+newMonths];
        for(int i=0;i<months;i++){
            temp[i]=expenses[i];
        }

        for(int i=months;i<months+newMonths;i++){
            cout<<"Enter expense for month "<<i+1<<": ";
            cin>>temp[i];
        }

        delete[] expenses;
        expenses=temp;
        months=months+newMonths;
    }

    int total=0;
    for(int i=0;i<months;i++){
        total=total+expenses[i];
    }

    int average=total/months;

    cout<<"Total Expenses: "<<total<<endl;
    cout<<"Average Monthly Expense: "<<average<<endl;

    delete[] expenses;
}