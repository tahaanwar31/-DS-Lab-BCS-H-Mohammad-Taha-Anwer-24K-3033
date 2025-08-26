#include <iostream>
using namespace std;

class Box {
private:
    int* value;

public:
    Box() {
        value = new int(0);
    }

    Box(int v) {
        value = new int(v);
    }

    Box(const Box& other) {
        value = new int(*other.value);
    }

    Box& operator=(const Box& other) {
        if (this != &other) {
            delete value;
            value = new int(*other.value);
        }
        return *this;
    }

    ~Box() {
        delete value;
    }

    void setValue(int v) {
        *value = v;
    }

    void showValue(string name) {
        cout << name << " value: " << *value << endl;
    }

    void shallowCopy(Box& other) {
        delete value;
        value = other.value;
    }
};

int main() {
    cout << "+---Deep Copy---+" << endl;
    Box b1(100);
    Box b2 = b1;
    b2.setValue(200);

    b1.showValue("b1");
    b2.showValue("b2");

    cout << "+---Using Assignment operator:---+" << endl;
    Box b3;
    b3 = b1;
    b3.setValue(300);

    b1.showValue("b1");
    b3.showValue("b3");

    cout << "+---Shallow Copy---+" << endl;
    Box b4(400);
    Box b5;
    b5.shallowCopy(b4);
    b5.setValue(500);

    b4.showValue("b4");
    b5.showValue("b5");

}
