#include<iostream>
#include<list>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(string A, string B){
    string A1;
    A1.push_back(A[0]);
    A1.push_back(A[1]);
    string B1;
    B1.push_back(B[0]);
    B1.push_back(B[1]);
    return (A1 < B1);
}
int main(){

    freopen("sample.in","r",stdin);

    int num=0;
    int N;cin>>N;

    while (N){
        vector<string> lst;
        for (int i = 0; i < N; ++i){
            string A;
            cin>>A;
            lst.push_back(A);
        }
        stable_sort(lst.begin(),lst.end(),comp);
        for(auto x: lst)
            cout<<x<<endl;
        cin>>N;
        if (N) cout<<endl;
    }



}



// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// int main () {
//     int N;
//     freopen("sample.in","r",stdin);

//     cin >> N;
//     while (N) {
//         vector<string> str;
//         for (int i = 0; i < N; i++) {
//             string A; cin>>A;
//             str.push_back(A);
//         }

//         bool sorted = false;
//         while (!sorted){
//             sorted = true;
//             for (int i = 0; i < N-1; i++) {
//                 if (str[i].compare(0, 2, str[i+1], 0, 2) > 0) {
//                     str[i].swap(str[i+1]);
//                     sorted=false;
//                 }
//             }

//         }

//         for (int i = 0; i < N; i++) {
//             cout << str[i] << endl;
//         }

//         cin >> N;
//         if (N){
//             cout << endl;
//         }

//     }
// }