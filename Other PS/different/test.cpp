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
	freopen("sample.in", "r", stdin);
	int k=0;
	while (!cin.eof()){
		if (k != 0) 
			cout<<endl;
		string a,b;

		cin>>a>>b;


		string bigger,smaller;
		if (a.length() > b.length()){
			bigger=a;
			smaller=b;
		}
		else if (a.length() < b.length()){
			bigger=b;
			smaller=a;
		}
		else{
			if (a > b){
				bigger=a;
			    smaller=b;
			}
			else{
				bigger=b;
				smaller=a;
			}

		}

		int j=0;
		list<char> A;

		for (int i = smaller.length()-1; i >= 0; --i){
			int result;

			if (j == 0){
				if (bigger[i+bigger.length()-smaller.length()] >= smaller[i])
					result=bigger[i+bigger.length()-smaller.length()]-smaller[i];
				else{
					result=bigger[i+bigger.length()-smaller.length()]-smaller[i]+10;
					j=1;
				}
			}
			else{
				if (bigger[i+bigger.length()-smaller.length()] - 1 >= smaller[i]){
					result=bigger[i+bigger.length()-smaller.length()]-smaller[i]-1;
					j=0;
				}
				else{
					result=bigger[i+bigger.length()-smaller.length()]-1-smaller[i]+10;
					j=1;
				}
			}			
			// cout<<bigger[i]<<" "<<smaller[i]<<" "<<result<<" "<<j<<endl;
			A.push_front(result+'0');
		}

		for (int i = bigger.length()-smaller.length()-1; i >= 0; --i){
			if (j == 0){
				A.push_front(bigger[i]);
			}
			else{
				if (bigger[i] == '0'){
					j=1;
					A.push_front('9');
				}
				else{
					j=0;
					A.push_front(bigger[i]-1);
				}
			}

		}
		while (A.size() > 1){
			if (A.front() == '0')
				A.pop_front();
			else
				break;
		}

		for (auto x:A)
			cout<<x;
		k++;
	}


}