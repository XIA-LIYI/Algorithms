#include <iostream>
#include <math.h>
#include <cstdio>

using namespace std;

int main(){

	freopen("sample.in","r",stdin);

	int result;
	int N;
	int curr;
	char a[51];

	scanf("%d",&N);

	for (int i =1; i <= N; ++i){
		result=0;
		cin>>a;
		int k=0;
		for (int j=strlen(a)-1; j >= 0; --j){
			if (k % 2 == 0)
				result=result+(a[j]-'0');
			else{
				curr=(a[j]-'0') * 2;
				if (curr < 10){
					result=result+curr;
				}
				else
					result=result+(curr % 10)+1;
			}
			k++;
		}

		if (result % 10 == 0){
			cout<<"PASS\n";
		}
		else
			cout<<"FAIL\n";
	}
	
}