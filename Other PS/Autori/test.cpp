#include<iostream>

using namespace std;

int main(){
	freopen("autori.2.in","r",stdin);
	string B;
	char A[100];
	int i=0;
	while (!cin.eof()){
		cin>>A[i];
		i++;
	}



	for (auto x: A){
		if (x <= 'Z' && x >= 'A')
			B.push_back(x);
	}
	cout<<B;
}