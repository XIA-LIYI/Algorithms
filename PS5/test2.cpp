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

typedef pair<int, int> i;
typedef pair<int,pair<long long, int> > ii;
typedef vector<long long> vi;
typedef vector<ii> vii;

const long long inf = 1e9;


// vector<int> check(vector<vector<pair<int,int> > > AL, int V,int s) {
//      priority_queue<i, vector<i>, greater<i> > pq; pq.push(make_pair(0, s));
//      vector<int> dist(V, inf); dist[s] = 0;
//   // sort the pairs by non-decreasing distance from s
//     while (!pq.empty()) {                          // main loop
//         pair<int, long long> x= pq.top(); pq.pop();            // shortest unvisited u
//         if (x.first > dist[x.second]) continue;                   // a very important check
//         for (auto &y: AL[x.second]) {                 // all edges from u
//             if (dist[x.second]+y.second >= dist[y.first]) continue;        // not improving, skip
//             dist[y.first] = dist[x.second]+y.second;                       // relax operation
//             pq.push(make_pair(dist[y.first], y.first));                     // enqueue better pair
//         }
//     }
//     //cout<<s<<" "<<dist[3];
//     // cout<<"S is "<<s;
//     // for (auto x:dist)
//     //  cout<<" "<<x;
//     return dist;
// }
void Dijkstra(vector<vector<pair<int, long long> > > AL, int V, int k,int s, int t) {
    //vector<int> vt=check(table2,V,t);
    //priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(make_pair(make_pair(0, s),k));
    priority_queue<ii> pq;pq.push(make_pair(k,make_pair(0, s)));
    vi dist(V,inf); dist[s] = 0;
    // sort the pairs by non-decreasing distance from s
    while (!pq.empty()) {                          // main loop
        ii x= pq.top(); pq.pop();            // shortest unvisited u
        k = x.first;
        // 
        if (x.second.first > dist[x.second.second] || k == 0) continue;                   // a very important check
        for (auto &y: AL[x.second.second]) {                 // all edges from u
        	//|| vt[y.first] > k-1
            if (dist[x.second.second]+y.second > dist[y.first]) continue;        // not improving, skip
            dist[y.first] = dist[x.second.second]+y.second;                    // relax operation
            if (k-1 != 0)
            pq.push(make_pair(k-1,make_pair(dist[y.first], y.first)));                     // enqueue better pair
        }
        
    }

    if (dist[t] != inf){
        cout<<dist[t]<<endl;
    }
    else
        cout<<"-1"<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);

    int TC;cin>>TC;
    for (int i = 0; i < TC; ++i){
        string line;getline(cin,line);
        int V;cin>>V;
        vector<vector<pair<int, long long> > > table(V);
        //vector<vector<pair<int, int> > > table2(V);

        for (int j = 0; j < V; ++j){
            int X;cin>>X;
            for (int l = 0; l < X; ++l){
                int index,weight;cin>>index>>weight;
                table[j].push_back(make_pair(index,weight));
                //table2[index].push_back(make_pair(j,1));
            }
        }

        int Q;cin>>Q;

        
        for (int j = 0; j < Q; ++j){
            int s,t,k;cin>>s>>t>>k;
            if (s == t)
                cout<<0<<endl;
            else if (k <= 1)
                cout<<"-1\n";
            else
                Dijkstra(table,V,k-1,s,t);

        }

        if (i != TC-1)
            cout<<"\n";
    }
}