#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<queue>
#include<algorithm>
#include<stack>
#include<deque>

using namespace std;
void get(char a, int A[]){
	if (a == 'C')
		cout<<A[2]<<" ";
	if (a == 'B')
		cout<<A[1]<<" ";
	else if (a == 'A')
		cout<<A[0]<<" ";
}

int main(){
	freopen("2.in", "r", stdin);
	int A[3];
	cin>>A[0]>>A[1]>>A[2];
	sort(A,A+3);
	char x,y,z;
	cin>>x>>y>>z;
	get(x,A);
	get(y,A);
	get(z,A);


}