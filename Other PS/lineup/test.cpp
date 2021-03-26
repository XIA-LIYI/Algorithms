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

	int N;cin>>N;
	string check,curr,previous;
	cin>>previous;

	for (int i = 1; i < N; ++i){
		cin>>curr;
		if (check.empty()){
			if (previous > curr)
				check="DECREASING";
			else
				check="INCREASING";
		}
		else{
			if (previous > curr){
				if (check != "DECREASING"){
					check="NEITHER";
					break;
				}
			}
		    else{
		    	if (check != "INCREASING"){
		    		check="NEITHER";
		    		break;
		    	}

		    }
		}
	    previous=curr;
	}
	cout<<check;
}