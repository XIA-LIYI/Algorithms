#include<iostream>
#include<string>
#include<list>
#include<algorithm>
using namespace std;

// class Person {
// public:
// 	void Print() const;

// private:
// 	std::string name_;
//     int age_ = 5;
// };

// void Person::Print() const {
// 	std::cout << name_ << ":" << age_ << std::endl;
//     // "name_" and "age_" are the member variables. The "this" keyword is an
//     // expression whose value is the address of the object for which the member
//     // was invoked. Its type is "const Person*", because the function is declared
//     // const.
// }

int main(){

	list<int> A;
	list<int> B;
	A.insert(A.begin(),7,2);
	B.push_back(1);
	auto t=A.begin();
   	advance(t, 7);
	B.splice(B.end(),A,A.begin(),t);
	for (auto &x: B)
		cout<<x<<" ";
	cout<<endl;
	for (auto &x: A)
		cout<<x<<" ";
	cout<<endl;
}