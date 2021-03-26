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
    if (name.length() >= 2){
        return (name[0]-'A')*27+1+(name[1]-'A');
    }
    else{
        return (name[0]-'A')*27;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("1.in","r",stdin);
    vector<set<string> > male(729);
    vector<set<string> > female(729);
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
                male[belong(name)].insert(name);
                lst[name]=1;
                male_num[name[0]]+=1;
            }
            else{
                female[belong(name)].insert(name);
                lst[name]=2;
                female_num[name[0]]+=1;
            }
        }
        else if (op == 2){
            string name;cin>>name;
            int gender;
            gender=lst[name];
            if (gender == 1){
                auto itr=male[belong(name)].begin();
                while (*itr != name){
                    itr++;
                }
                male[belong(name)].erase(itr);
                male_num[name[0]]-=1;
            }
            else{
                auto itr=female[belong(name)].begin();
                while (*itr != name){
                    itr++;
                }
                female[belong(name)].erase(itr);
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
                int k=0;
                for (auto x:male[belong(start)]){
                    if (x >= start){
                        total+=(male[belong(start)].size()-k);
                        break;
                    }
                    k++;
                }
                cout<<total<<endl;
                for (int i = belong(start)+1; i < 27*(start[0]-'A'+1); ++i){
                    total+=male[i].size();
                }
                for (int i = start[0]-'A'+1; i < end[0]-'A'; ++i){
                    total+=male_num[i+'A'];
                }
                for (int i = 27*(end[0]-'A'); i < belong(end); ++i){
                    total+=male[i].size();
                }
                if (belong(start) != belong(end)){
                for (auto x:male[belong(end)]){
                    if (x >= end){
                        break;
                    }
                    else{
                        total++;
                    }
                }}
            }
            if (n == 2 || n == 0){
                int k=0;;
                for (auto x:female[belong(start)]){
                    if (x >= start){
                        total+=(male[belong(start)].size()-k);
                        break;
                    }
                    k++;
                }
                for (int i = belong(start)+1; i < 27*(start[0]-'A'+1); ++i){
                    total+=female[i].size();
                }
                for (int i = start[0]-'A'+1; i < end[0]-'A'; ++i){
                    total+=female_num[i+'A'];
                }
                for (int i = 27*(end[0]-'A'); i < belong(end); ++i){
                    total+=female[i].size();
                }
                if (belong(start) != belong(end)){
                for (auto x:female[belong(end)]){
                    if (x >= end){
                        break;
                    }
                    else{
                        total++;
                    }
                }}
            }

            cout<<total<<"\n";
        }

    }
}