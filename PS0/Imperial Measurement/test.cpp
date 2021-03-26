#include<iostream>
#include<cstdio>
using namespace std;


double check1(double num, string a){
	if (a == "thou" or a == "th")
		return check1(num*1000,"inch");
	else if (a == "inch" or a == "in")
		return check1(num*12,"ft");
	else if (a == "foot" or a == "ft")
		return check1(num*3, "yd");
	else if (a == "yard" or a == "yd")
		return check1(num*22, "ch");
	else if (a == "chain" or a == "ch")
		return num;
	else if (a == "furlong" or a == "fur")
		return check1(num/10, "chain");
	else if (a == "mile" or a == "mi")
		return check1(num/8, "furlong");
	else if (a == "league" or a == "lea")
		return check1(num/3, "mile");
}

double check(double num, string a){
	if (a == "thou" or a == "th")
		return check(num/1000,"in");
	else if (a == "inch" or a == "in")
		return check(num/12,"foot");
	else if (a == "foot" or a == "ft")
		return check(num/3, "yd");
	else if (a == "yard" or a == "yd")
		return check(num/22, "ch");
	else if (a == "chain" or a == "ch")
		return num;
	else if (a == "furlong" or a == "fur")
		return check(10*num, "chain");
	else if (a == "mile" or a == "mi")
		return check(8*num, "furlong");
	else if (a == "league" or a == "lea")
		return check(3*num, "mile");
}

int main(){

	freopen("sample2.in", "r", stdin);
	double num;
	string a,b,c;
	cin>>num;
	cin>>a>>b>>c;

	//cout<<check(num,a)<<endl;
	//printf("%.12lf",check1(check(num,a),c));

	num=check1(check(num,a),c);
	if ( num / ((int) num) == 1 )
		cout<<num;
	else
		printf("%.13lf",num);

}