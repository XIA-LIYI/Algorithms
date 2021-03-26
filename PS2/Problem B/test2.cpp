#include<iostream>
#include<deque>
#include<vector>
#include<list>
using namespace std;
int main(){

    freopen("1.in","r",stdin);
    list<long> line;
    long N; cin>>N;

    vector<long> vet;
    for (long i = 0; i < N; ++i){
        string command;
        cin>>command;
        long num;
        cin>>num;
        if (command == "push_back")
            line.push_back(num);
        else if (command == "push_front")
            line.insert(line.begin(),num);
        else if (command == "push_middle"){
            auto itr=line.begin();
            advance(itr, (line.size()+1)/2);
            line.insert(itr,num);
        }
        if (command == "get"){
            auto itr=line.begin();
            advance(itr, num);     
            cout<<*itr<<endl;
        }
    }
}
