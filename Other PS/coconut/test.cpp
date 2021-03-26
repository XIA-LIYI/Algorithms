#include<iostream>
#include<vector>
using namespace std;

int main(){
	freopen("sample02.in","r",stdin);
	int s,p;
	cin>>s>>p;

	vector<pair<int, int> > unit;

	for (int i = 0; i < p; ++i)
		unit.push_back(make_pair(i,0));

	int number=0;

	while(unit.size() > 1){
        number += s-1;
        number=number % unit.size();

        if (unit[number].second == 0) {
            unit[number].second ++;
            unit.insert(unit.begin()+number, make_pair(unit[number].first, unit[number].second));
        }
        else if (unit[number].second == 1) {
            unit[number].second ++;
            number ++;
        }
        else if (unit[number].second == 2) {
            unit.erase(unit.begin()+number);
        }
	}
	cout<<unit[0].first+1;

}