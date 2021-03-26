#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){

	freopen("1.in","r",stdin);

	int height,width,num;
	cin>>height>>width>>num;
	int curr=0,total=0,k=0;
	// cout<<height<<' '<<width<<' '<<num;
	for (int i=1; i <= height; ++i){
		total=0;
		while (total < width){
			cin>>curr;
			total+=curr;
			// cout<<curr;
			k++;
			cout<<total<<" "<<k<<" "<<i<<endl;
			if (k == num && (total != width || i != height)){
				cout<<"NO";
				return 0;
			}
			// cout<<total<<" ";
		}
		if (total > width){
			cout<<"NO";
			return 0;
		}

	}
	cout<<"YES";
	return 0;
}