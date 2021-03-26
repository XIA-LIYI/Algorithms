//XIA LIYI
//A0177873L
//Group 08
//AAryam
#include<iostream>
#include<list>
#include<deque>
#include<queue>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>
#include<map>
#include<set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("sample01.in","r",stdin);


    long x;cin>>x;
    long point;cin>>point;
    long n;cin>>n;
    map<string, int> check;
    vector<long> lst(x);
    int k=0;

    for (long i = 0; i < x; ++i){
        string a;cin>>a;
        check[a]=i;
        lst[i]=0;
    } 

    for (long i = 0; i < n; ++i){
        string unit_name;cin>>unit_name;
        long p;cin>>p;

        long index=check[unit_name];
        if (lst[index] >= point)
            continue;
        lst[index]+=p;
        if (lst[index] >= point){
            cout<<unit_name<<" wins!"<<endl;
            k=1;
        }   
    }

    if (k == 0){
        cout<<"No winner!"<<endl;
    }


    
}