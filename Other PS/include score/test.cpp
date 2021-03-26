#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int score[30]={100,75,60,50,45,40,36,32,29,26,24,22,20,18,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};

struct contest{
    int problem;
    int penalty;
    int time;
    int extra;
    int score;
    int rank;
};

int compare (contest a, contest b) {
    if (a.problem > b.problem) 
        return 1;
    else if (a.problem < b.problem) 
        return -1;
    else {
        if (a.penalty < b.penalty) 
            return 1;
        else if (a.penalty > b.penalty)
            return -1;
        else {
            if (a.time < b.time) 
                return 1;
            else if (a.time > b.time)
                return -1;
            else
                return 0;
        }
    }
}

int main(){

    freopen("1.in","r",stdin);

    int N; cin >> N;

    contest *unit = new contest[N];

    for (int i = 0; i < N; i++){
        cin >> unit[i].problem;
        cin >> unit[i].penalty;
        cin >> unit[i].time;
        cin >> unit[i].extra;
        unit[i].rank = 0;
    }

    int MAX;
    for (int i = 0; i < N; i++){
        MAX = 0;
        while (unit[MAX].rank != 0) MAX ++;
        for (int j = 0; j < N; j++){
            if (unit[j].rank == 0 && compare(unit[MAX], unit[j]) == -1) {
                MAX = j;
            }
        }
        unit[MAX].rank = i+1;
    }

    for (int i = 0; i < N; i++) {
        unit[i].rank--;
    }

    int ranking[N];
    for (int i = 0; i < N; i++) {
        ranking[unit[i].rank] = i;
    }

    for (int i = 0; i < 30; i++) {
        if (i == N-1) {
            unit[ranking[i]].score = score[i];
            break;
        }
        else if (compare(unit[ranking[i]], unit[ranking[i+1]]) == 1) {
            unit[ranking[i]].score = score[i];
        }
        else if (compare(unit[ranking[i]], unit[ranking[i+1]]) == 0) {
            int starting = i;
            int sum = score[i];
            while (i < N-1 && compare(unit[ranking[i]], unit[ranking[i+1]]) == 0) {
                i ++;
                if (i < 30){
                    sum += score[i];
                }
            }
            int ending = i;
            int average = ((double)sum / (double)(ending - starting + 1));
            for (int j = starting; j <= ending; j++){
                unit[ranking[j]].score = average;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << unit[i].score + unit[i].extra << endl; 
    }
}

