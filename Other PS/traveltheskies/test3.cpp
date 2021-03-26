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
typedef pair<int,int> ii;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    //freopen("2.in","r",stdin);

    int k,n,m;
    cin>>k>>n>>m;
    vector< vector <vector <ii> > > flights(n, vector<vector<ii> >(k));
    int arrival[15][15];
    for (int i = 0; i < m; ++i){
        int a,b,c,d;cin>>a>>b>>c>>d;
        flights[c-1][a-1].push_back(make_pair(b-1,d));
    }

    for (int i = 0; i < k*n; ++i){
        int a,b,c;cin>>a>>b>>c;
        arrival[b-1][a-1]=c;
    }


    vector<int> current(k,0), next(k,0);

    for (int i = 0; i < n; i++){
    
        for (int j = 0; j < k; j++){
            current[j]+= arrival[i][j];
        }
        for (int j = 0; j < k; j++){
            for (auto flight: flights[i][j]){
                current[j]-=flight.second;
                next[flight.first]+=flight.second;

            }
            if (current[j] < 0){
                    cout<<"suboptimal";
                    return 0;
                }

        }

        for (int j = 0; j < k; j++){
            current[j] += next[j];
            next[j]=0;
        }
    }

    cout<<"optimal";

    
}