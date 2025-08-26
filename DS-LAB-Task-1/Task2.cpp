#include <iostream>
#include <cstring>
using namespace std;

class Exam {
private:
    char* studentName;
    char* examDate;
    int* score;

public:
    Exam() {
        studentName = new char[20];
        examDate = new char[20];
        score = new int(0);
    }

    Exam(const char* name, const char* date, int marks) {
        studentName = new char[strlen(name) + 1];
        examDate = new char[strlen(date) + 1];
        strcpy(studentName, name);
        strcpy(examDate, date);
        score = new int(marks);
    }

    ~Exam() {
        delete[] studentName;
        delete[] examDate;
        delete score;
    }

    void setExam(const char* name, const char* date, int marks) {
        strcpy(studentName, name);
        strcpy(examDate, date);
        *score = marks;
    }

    void displayExam() {
        cout << "Student Name: " << studentName << endl;
        cout << "Exam Date: " << examDate << endl;
        cout << "Score: " << *score << endl;
    }

    void changeScore(int newScore) {
        *score = newScore;
    }
};

int main() {
    Exam exam1("Taha", "26-08-2025", 85);
    cout << "Exam 1 record:" << endl;
    exam1.displayExam();

    Exam exam2 = exam1;  
    cout << "Exam 2 record:" << endl;
    exam2.displayExam();

    cout << "Exam 2 score changed to 50" << endl;
    exam2.changeScore(50);

    cout << "After change Exam2: " << endl;
    exam2.displayExam();

    cout << "After change exam 1:" << endl;
    exam1.displayExam();

    cout<<"\n+---This shows that shallow copy can cause serious issues like double deletion and dangling pointers i made changes to exam 2 but exam1's details were also changed +---\n";

}

