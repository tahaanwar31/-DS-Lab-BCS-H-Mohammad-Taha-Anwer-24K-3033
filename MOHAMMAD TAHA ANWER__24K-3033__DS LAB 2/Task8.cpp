#include <iostream>
#include <string>
using namespace std;

int main(){
    int days;
    cout<<"Enter the number of days: "<<endl;
    cin>>days;
    int times;
    cout<<"Enter the number of times per day: "<<endl;
    cin>>times;

    float** temps=new float*[days];
    for(int i=0;i<days;i++){
        temps[i]=new float[times];
    }

    for(int i=0;i<days;i++){
        cout<<"Start entering temperatures for day:"<<i+1<<"\n";
        for(int j=0;j<times;j++){
            cout<<"Time: "<<j+1<<endl;
            cin>>temps[i][j];
        }
    }

    cout<<"========================================\n";
    cout<<"DAILY AVERAGE TEMPERATURES\n";
    cout<<"========================================\n";
    float maxAvg,minAvg;
    int maxDay,minDay;
    for(int i=0;i<days;i++){
        cout<<"Day: "<<i+1<<" ";
        float total=0,average;
        for(int j=0;j<times;j++){
            total=total+temps[i][j];
        }
        average=total/times;
        cout<<average<<endl;
        if(i==0){
            maxAvg=average;
            minAvg=average;
            maxDay=i;
            minDay=i;
        }
        if(average>maxAvg){
            maxAvg=average;
            maxDay=i;
        }
        if(average<minAvg){
            minAvg=average;
            minDay=i;
        }
    }

    cout<<"========================================\n";
    cout<<"Hottest day: Day "<<maxDay+1<<" with average "<<maxAvg<<endl;
    cout<<"Coldest day: Day "<<minDay+1<<" with average "<<minAvg<<endl;
    cout<<"========================================\n";

    for(int i=0;i<days;i++){
        delete[] temps[i];
    }
    delete[] temps;
}