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
#include <iterator>
#include<string>
using namespace std;
//2 is deleted, 1 is edited, 0 is not;
int check(list <pair<int, pair<int, string> > > *lst, string name){
    for (auto &x: *lst){
        if (x.second.second == name){
            if (x.first == 0)
                return 1;
        }
    }
    return 0;

}
pair<int,int> edited(string name, list<pair<int, pair<int, string> > > *lst, int level){
    for (auto &x:*lst){
        if (x.second.second == name){
            int temp=x.first;
            x.first+=level;
            return make_pair(temp,x.second.first);
        }
    }
}
void get_delete(string name, list<pair<int, pair<int, string> > > *lst){
    for (auto &x:*lst){
        if (x.second.second == name){
            x.first=0;
            return;
        }

    }
}
int belong(string name){
    int result=0;
    if (name.length() >= 3){
        return (name[0]-'A')*729+(name[1]-'A')*27+(name[2]-'A');
    }
    else if (name.length() == 2){
        return (name[0]-'A')*729+(name[1]-'A')*27+2;
    }
    else{
        return (name[0]-'A')*729;
    }
}
int main(){

    freopen("1.in","r",stdin);

    vector<priority_queue<pair<int,pair<int, string> > > > pq(101);
    vector<list<pair<int, pair<int, string> > > > vt(19683);

    long N; cin>>N;
    long num=0;long min=100;
    long max=100;

    for (long i = 0;i < N; ++i){
        int op;cin>>op;
        // cout<<i<<endl;
        if (op == 0){
            string name;cin>>name;
            int level;cin>>level;
            pq[level].push(make_pair(level,make_pair(N-i, name)));
            vt[belong(name)].push_back(make_pair(level, make_pair(N-i,name)));
            num++;
            if (level > max)
                max=level;
            if (level < min)
                min=level;
        }
        else if (op == 1){
            string name;cin>>name;
            int level;cin>>level;
            list<pair<int,pair<int,string> > > q;
            pair<int,int> index=edited(name,&vt[belong(name)],level);           
            // cout<<"index is "<<index<<endl;
            // while (pq[index].top().second.second != name){
            //     q.push_front(pq[index].top());
            //     pq[index].pop();
            // }
            // pair<int,pair<int,string> > temp;
            pq[index.first+level].push(make_pair(level+index.first,make_pair(index.second,name)));
            // temp=pq[index].top();
            // pq[index].pop();
            // temp.first+=level;
            // cout<<"new is "<<temp.first<<endl;
            // pq[temp.first].push(temp);
            // while (q.size() != 0){
            //     pq[index].push(q.front());
            //     q.pop_front();
            // }
    
            if (level+index.first > max)
                max=level+index.first;
        }
        else if (op == 2){
            string name;cin>>name;
            list<pair<int,pair<int, string> > > q;
            get_delete(name,&vt[belong(name)]);
            // int index=get_delete(name,&vt[belong(name)]);
            // while (pq[index].top().second.second != name){
            //     q.push_front(pq[index].top());
            //     pq[index].pop();
            // }
            // pq[index].pop();
            
            // for (auto x:q){
            //     pq[index].push(x);
            // }
            num--;
        }
        else if (op == 3){
            if (num == 0)
                cout<<"The clinic is empty"<<endl;
            else{
                for (int i = max; i >= min; --i){
                    if (pq[i].size() == 0){
                        continue;
                    }
                    else{
                        while (check(&vt[belong(pq[i].top().second.second)],pq[i].top().second.second) == 1 && pq[i].size()!=0){
                            pq[i].pop();
                        }
                        if (pq[i].size() != 0){
                            cout<<pq[i].top().second.second<<endl;
                            max=i;
                            break;
                        }
                        else{
                            continue;
                        }                       
                    }
                }
            }

        }
    }
}