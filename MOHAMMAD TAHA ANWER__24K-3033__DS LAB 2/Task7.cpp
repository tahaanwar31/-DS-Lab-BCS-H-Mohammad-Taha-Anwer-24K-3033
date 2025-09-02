#include <iostream>
#include <string>
using namespace std;

int main(){
    int depts;
    cout<<"Enter the number of departments: "<<endl;
    cin>>depts;

    int** salaries=new int*[depts];
    int size[depts];

    for(int i=0;i<depts;i++){
        cout<<"Enter number of employees in department:"<<i+1<<"\n";
        cin>>size[i];
        salaries[i]=new int[size[i]];
    }

    for(int i=0;i<depts;i++){
        cout<<"Start entering salaries for department:"<<i+1<<"\n";
        for(int j=0;j<size[i];j++){
            cout<<"Employee: "<<j+1<<endl;
            cin>>salaries[i][j];
        }
    }

    cout<<"========================================\n";
    cout<<"HIGHEST SALARY IN EACH DEPARTMENT\n";
    cout<<"========================================\n";
    for(int i=0;i<depts;i++){
        cout<<"Department: "<<i+1<<" ";
        int max;
        float total,average;
        for(int j=0;j<size[i];j++){
            if(j==0){
                max=salaries[i][j];
            }
            if(salaries[i][j]>max){
                max=salaries[i][j];
            }
            total=total+salaries[i][j];
        }
        average=total/size[i];
        cout<<max<<endl;
    }

    float maxAvg;
    int maxAvgDept;
    for(int i=0;i<depts;i++){
        float total,average;
        for(int j=0;j<size[i];j++){
            total=total+salaries[i][j];
        }
        average=total/size[i];
        if(i==0){
            maxAvg=average;
            maxAvgDept=i;
        }
        if(average>maxAvg){
            maxAvg=average;
            maxAvgDept=i;
        }
    }

    cout<<"===========================================================================================================\n";
    cout<<"Department with highest average salary: Department "<<maxAvgDept+1<<" with average "<<maxAvg<<endl;
    cout<<"===========================================================================================================3\n";

    for(int i=0;i<depts;i++){
        delete[] salaries[i];
    }
    delete[] salaries;
}