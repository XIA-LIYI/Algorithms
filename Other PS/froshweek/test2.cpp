#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long result = 0;

void merge (vector<int>& arr, int low, int mid, int high) {
    int temp[high-low+1];
    // alternatively, use new and delete to dynamically allocate memory
    int i = low, j = mid+1, k = 0; 
    // i -- elements in left subarray
    // j -- elements in right subarray
    // k -- elements in temp array

    // fill in the temp array
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else {
            temp[k] = arr[j];
            k++;
            j++;
            result += mid-i+1;
        }
        // alternatively: temp[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
    }
    // collect remaining elements
    while (i <= mid) 
        temp[k++] = arr[i++];
    while (j <= high)
        temp[k++] = arr[j++];
    // put temp array back in arr
    for (k = 0; k < high-low+1; k++) 
        arr[low+k] = temp[k];
}

void mergeSort (vector<int>& arr, int low, int high) {
    if (low >= high) return; // base case: 0 or 1 items
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    // mid is the index of the end of the left array
    merge(arr, low, mid, high);
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false); cin.tie(NULL);

    freopen("E.0.in", "r", stdin);
    int n; cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++){
        int temp; cin >> temp;
        a.push_back(temp);
    }

    mergeSort(a, 0, n-1);
    cout << result;

    return 0;
}