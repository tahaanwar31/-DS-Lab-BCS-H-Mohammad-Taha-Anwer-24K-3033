#include <iostream>
#include <string>
using namespace std;

int main(){
    int categories;
    cout<<"Enter the number of categories: "<<endl;
    cin>>categories;

    int** books=new int*[categories];
    int size[categories];
    string* names=new string[categories];

    for(int i=0;i<categories;i++){
        cout<<"Enter name of category:"<<i+1<<"\n";
        cin>>names[i];
        cout<<"Enter number of books in category:"<<i+1<<"\n";
        cin>>size[i];
        books[i]=new int[size[i]];
    }

    for(int i=0;i<categories;i++){
        cout<<"Start entering book IDs for category:"<<i+1<<"\n";
        for(int j=0;j<size[i];j++){
            cout<<"Book: "<<j+1<<endl;
            cin>>books[i][j];
        }
    }

    cout<<"========================================\n";
    cout<<"SEARCH FOR A BOOK ID\n";
    cout<<"========================================\n";
    int searchid;
    cout<<"Enter book ID to search: "<<endl;
    cin>>searchid;

    bool flag=false;
    int foundcat=-1;
    for(int i=0;i<categories;i++){
        for(int j=0;j<size[i];j++){
            if(books[i][j]==searchid){
                flag=true;
                foundcat=i;
                break;
            }
        }
        if(flag==true){
            break;
        }
    }

    cout<<"========================================\n";
    if(flag==true){
        cout<<"Book ID "<<searchid<<" is available in category "<<names[foundcat]<<endl;
    }
    else{
        cout<<"Book ID "<<searchid<<" is not available\n";
    }
    cout<<"========================================\n";

    for(int i=0;i<categories;i++){
        delete[] books[i];
    }
    delete[] books;
    delete[] names;
}