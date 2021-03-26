//A0177900A
//Ge Yao
//lab 07
//Aaryam

#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main(){

    freopen("1.in", "r", stdin);

    int TC;cin>>TC;
    
    for (int i=0;i<TC;i++){
        list<char> a;
        if (i==0) getchar();
        list<char> b;
        string s;
        bool start;
        getline(cin,s);
        for (char &i:s){
            
            if(i=='<'){
                if(start==true){
                    if(!b.empty())
                        b.pop_front();
                }
                else{
                    if(!a.empty())
                        a.pop_front();
                }
            }
            else if(i=='['){
                if (start == true){
                    a.splice(a.end(),b);
                }
                else
                    start=true;
            }
            else if(i==']'){
                if (start==true){
                    a.splice(a.end(),b);
                    start=false;
                }
            }
            else{
                if(start==true)
                    b.push_front(i);
                else
                    a.push_front(i);
            }

            for (auto it:a)
                cout <<it;
            cout<<endl;
        }

        if (!b.empty()){
            a.splice(a.end(), b);
        }
        // if(!a.empty())
        // {
            a.reverse();
            for (auto it:a)
                cout <<it;
        // }
        // else{
        //     b.reverse();
        //     for (auto it:b)
        //         cout <<it;
        // }
        cout<<endl;
    }
}


