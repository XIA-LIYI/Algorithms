#include <iostream>

#include <cstring>

using namespace std;

int main(){

	freopen("2.in","r",stdin);

	char str1[10000];
	char str2[10000];
	
	scanf("%s",str1);
	scanf("%s",str2);

    int len1,len2;
	len2=strlen(str2);
	len1=strlen(str1);

	char result[10000];
	int MAX;
	MAX=max(len1,len2);
	int curr_result,last=0;
	int curr_str1,curr_str2;
	for (int i=0;i<MAX;++i){
		if (i >= len1){
			curr_str1=0;
		}
		else
			curr_str1=str1[len1-i-1]-'0';
		if (i >= len2)
			curr_str2=0;
		else
			curr_str2=str2[len2-i-1]-'0';

		curr_result=curr_str1+curr_str2+last;
		//cout<<curr_str1<<" "<<curr_str2<<" "<<curr_result<<endl;

		if (curr_result < 10){
			result[MAX-i-1]='0'+curr_result;
			last=0;
		}
		else{
			result[MAX-i-1]='0'+curr_result%10;
			last=1;
		}



	}
	if (last == 1)
		cout<<'1';

	cout<<result;



}