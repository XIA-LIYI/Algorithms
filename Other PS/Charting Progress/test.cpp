#include <iostream> 
#include <string>
#include <vector>

using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
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
            	swapped = true;
                swap(Array[j], Array[j + 1]);
            }
        }
        if (swapped == false)
            break;
    }
}

int main()
{
    freopen("sample.in", "r", stdin);

    while (cin.eof() == false) {
        
        string line; 
        vector<string> box; 

        while ((getline(cin, line)) && (!line.empty())) { 
                box.push_back(line);
                cout<<line[1];
        }

        int len = box[0].size();
        int row = box.size();
        int col [len+1];

        for (int j = 0; j < len; j++){ 
            for (int i = 0; i < row; i++) { 
                if (box[i][j] == '*') {
                    col[j] = i;
                    break;
                }
            }
        }

        char result[row + 1][len + 1];
        bubbleSort(col,len);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < len; j++) {
                result[i][j] = '.';
            }
            result[i][len] = '\0';
        }

        for (int j = 0; j < len; j++) {
            result[col[j]][j] = '*';
        }

        for (int i = 0; i < row; i++) {
            cout << result[i] << endl;
        }
        cout << endl;

    }

    return 0;
}