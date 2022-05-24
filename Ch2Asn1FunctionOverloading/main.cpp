#include <iostream>
class BaseClass {
	public:
 void print() {
 std::cout << "In Base Class\n";
 }
};
class DerivedClass : public BaseClass {
 void print() {
 std::cout << "In Derived Class\n";
 }
};
int main() {
	DerivedClass obj;
	obj.print();
	return 0;
}
