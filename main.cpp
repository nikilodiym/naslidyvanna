#include <iostream>
#include <string>

using namespace std;

class A {
public:
	void seeNow() {
		cout << "Class A" << endl;
	}
};

class B : public A {};
class C : public A {};
class D : public B, public C {};

int main() {
	D obj;
	obj.seeNow();
	system("pause");
	return 0;
}