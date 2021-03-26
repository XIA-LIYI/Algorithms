#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<queue>
#include<algorithm>
#include<stack>
#include<deque>

using namespace std;

int main(){
	freopen("filip.dummy.1.in", "r", stdin);

	int A,B;cin>>A>>B;

	A=(A/100)+(A%10)*100+(A/10%10)*10;
	B=(B/100)+(B%10)*100+(B/10%10)*10;
	if (A > B)
		cout<<A;
	else
		cout<<B;
}