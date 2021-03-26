#include<iostream>
#include<string>
#include<cstdio>

using namespace std;

void swap(int *x, int *y)
{
    int change = *x;
    *x = *y;
    *y = change;
}

void bubbleSort(int Array[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (Array[j] < Array[j + 1])
            {
                swap(&Array[j], &Array[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

int main()
{
	freopen("sample.in", "r", stdin);

    while (!cin.eof()) {
        string line; 
        vector<string> grid; 
        while (getline(cin, line) && !line.empty()) { 
                grid.push_back(line);
        }


}
