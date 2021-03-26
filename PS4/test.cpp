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
ios_base::sync_with_stdio(false);
cin.tie(NULL);
   freopen("1.in","r",stdin);
    vector<list<string> > male(19683);
    vector<list<string> > female(19683);
    map<string, int> lst;
    map<char, int> female_num;
    map<char, int> male_num;
    for (int i = 0; i < 26; ++i){
        male_num['A'+i]=0;
        female_num['A'+i]=0;
    }
    while (1){
        int op;cin>>op;

        if (op == 0){
            break;
        }
        else if (op == 1){
            string name; cin>>name;
            int n;cin>>n;
            if (n == 1){               
                male[belong(name)].push_front(name);
                lst[name]=1;
                male_num[name[0]]+=1;
            }
            else{
                female[belong(name)].push_front(name);
                lst[name]=2;
                female_num[name[0]]+=1;
            }
        }
        else if (op == 2){
            string name;cin>>name;
            int gender;
            gender=lst[name];
            int a = belong(name);
            if (gender == 1){
                auto itr=male[a].begin();
                while (*itr != name){
                    itr++;
                }
                male[a].erase(itr);
                male_num[name[0]]-=1;
            }
            else{
                auto itr=female[a].begin();
                while (*itr != name){
                    itr++;
                }
                female[a].erase(itr);
                female_num[name[0]]-=1;
            }

            //lst.erase(name);
        }
        else if (op == 3){
            string start,end;
            cin>>start>>end;
            int n;cin>>n;
            long total=0;
            if (n == 1 || n == 0){
                for (auto x:male[belong(start)]){
                    if (x >= start)
                        total++;
                }
                for (int i = belong(start)+1; i < 729*(start[0]-'A'+1); ++i){
                    total+=male[i].size();
                }
                for (int i = start[0]-'A'+1; i < end[0]-'A'; ++i){
                    total+=male_num[i+'A'];
                }
                for (int i = 729*(end[0]-'A'); i < belong(end); ++i){
                    total+=male[i].size();
                }
                for (auto x:male[belong(end)]){
                    if (x < end)
                        total++;
                }
            }
            if (n == 2 || n == 0){
                for (auto x:female[belong(start)]){
                    if (x >= start)
                        total++;
                }
                for (int i = belong(start)+1; i < 729*(start[0]-'A'+1); ++i){
                    total+=female[i].size();
                }
                for (int i = start[0]-'A'+1; i < end[0]-'A'; ++i){
                    total+=female_num[i+'A'];
                }
                for (int i = 729*(end[0]-'A'); i < belong(end); ++i){
                    total+=female[i].size();
                }
                for (auto x:female[belong(end)]){
                    if (x < end)
                        total++;
                }
            }

            cout<<total<<"\n";
        }

    }
}