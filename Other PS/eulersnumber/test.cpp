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
	freopen("1.in", "r", stdin);

	int n;cin>>n;
	long long num=1;
	double result=1.0;
	n=min(50,n);
	for (int i = 1; i <= n; ++i){
		num=num*i;
		result+=(1.0/num);
	}
	printf("%.12lf",result);

}