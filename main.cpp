#include <iostream>
#include <string>

using namespace std;

class A {
public:
    void show() {
        cout << "Class A method" << endl;
    }
};

class B : virtual public A {};

class C : virtual public A {};

class D : public B, public C {};

int main() {
    D obj;
    obj.show();

	system("pause");
	return 0;
}