#include<iostream>
#include<list>
#include<deque>
#include<vector>
#include<string>
#include <iterator>
using namespace std;

int op(int a, int b, int c){
	if (c == 0)
		return a + b;
	else if ( c == 1)
		return a - b;
	else if ( c == 2)
		return a * b;
	else 
		return a / b;
}
string op1(int a){
	if (a == 0)
		return "+";
	else if (a == 1)
		return "-";
	else if (a == 2)
		return "*";
	else if (a == 3)
		return "/";
}
int get(int a, int b, int c){
	if (a < 2){
		if (b < 2)
			if (c < 2)
				return op(op(op(4,4,a),4,b),4,c);
			else
				return op(op(4,4,a),op(4,4,c),b);
		else
			if (c < 2)
				return op(op(4,op(4,4,b),a),4,c);
			else
				return op(4,op(op(4,4,b),4,c),a);
	}
	else
		if (b < 2)
			if (c < 2)
				return op(op(op(4,4,a),4,b),4,c);
			else
				return op(op(4,4,a),op(4,4,c),b);
		else
			if (c < 2)
				return op(op(op(4,4,a),4,b),4,c);
			else
				return op(op(op(4,4,a),4,b),4,c);

}
int main(){

	freopen("4thought.in","r",stdin);

	int N;cin>>N;

	for (int i = 0; i < N; ++i){
		int a;cin>>a;
		int k=0;

		for (int first = 0; first < 4; ++first){
			if (k == 1) break;

			for (int second = 0; second < 4; ++second){
				if (k == 1) break;
				for (int third = 0; third < 4; ++third){
					int result;
					result=get(first,second,third);
					if (result == a){
						cout<<"4 "<<op1(first)<<" 4 "<<op1(second)<<" 4 "<<op1(third)<<" 4 = "<<a<<endl;
						k=1;
						break;
					}
					
				}
				
			}
		}
		if (k == 0) 		cout<<"no solution"<<endl;
	}
	
}

