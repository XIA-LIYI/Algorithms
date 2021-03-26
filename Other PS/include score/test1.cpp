#include <iostream>
#include <cmath>

using namespace std;

int scr[30] = {100, 75, 60, 50, 45,
                40, 36, 32, 29, 26,
                24, 22, 20, 18, 16,
                15, 14, 13, 12, 11,
                10, 9, 8, 7, 6, 
                5, 4, 3, 2, 1};

struct contestant
{
    int problem;
    int penalty;
    int time;
    int onSite;
    int score;
    int rank;
};

int betterThan (contestant a, contestant b) {
    if (a.problem > b.problem) 
        return 1;
    else if (a.problem < b.problem) 
        return -1;
    else {
        // equal in problem
        if (a.penalty < b.penalty) 
            return 1;
        else if (a.penalty > b.penalty)
            return -1;
        else {
            // equal in time penalty
            if (a.time < b.time) 
                return 1;
            else if (a.time > b.time)
                return -1;
            else // all three properties are equal, tied
                return 0;
        }
    }
}

int main(int argc, char const *argv[])
{

    freopen("1.in", "r", stdin);

    int n; cin >> n;
    contestant *ctt = new contestant[n];

    for (int i = 0; i < n; i++){
        cin >> ctt[i].problem;
        cin >> ctt[i].penalty;
        cin >> ctt[i].time;
        cin >> ctt[i].onSite;
        ctt[i].rank = 0;
    } // read the data

    // determine the rank by sorting
    int max;
    for (int i = 0; i < n; i++){
        max = 0;
        while (ctt[max].rank != 0) max ++;
        for (int j = 0; j < n; j++){
            if (ctt[j].rank == 0 && betterThan(ctt[max], ctt[j]) == -1) {
                max = j;
            }
        }
        // max == the max (i)th number in the array (equal cases not considered)
        ctt[max].rank = i+1;
    }

    for (int i = 0; i < n; i++) {
        ctt[i].rank --;
    }


    int * ranking = new int [n];
    for (int i = 0; i < n; i++) {
        ranking[ctt[i].rank] = i;
    } 

    for (int i = 0; i < 30; i++) {
        if (i == n-1) {
            ctt[ranking[i]].score = scr[i];
            break;
        }
        else if (betterThan(ctt[ranking[i]], ctt[ranking[i+1]]) == 1) {
            // ranking[i] better than ranking[i+1]
            ctt[ranking[i]].score = scr[i];
        }
        else if (betterThan(ctt[ranking[i]], ctt[ranking[i+1]]) == 0) {
            // there is a plateau in the ranking curve
            int start = i;
            int sumOfPoints = scr[i];
            while (i < n-1 && betterThan(ctt[ranking[i]], ctt[ranking[i+1]]) == 0) {
                i ++;
                if (i < 30){
                    sumOfPoints += scr[i];
                }
            }
            int end = i;
            int average = ceil((double)sumOfPoints / (double)(end - start + 1));

            for (int j = start; j <= end; j++){
                ctt[ranking[j]].score = average;
            }
        }
    }

    delete [] ranking;

    // output the result
    for (int i = 0; i < n; i++) {
        cout << ctt[i].score + ctt[i].onSite << endl;
    }

        

    return 0;
}