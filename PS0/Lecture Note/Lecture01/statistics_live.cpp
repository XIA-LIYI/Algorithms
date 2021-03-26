// there is one character bug in this code, submitting it verbatim will give you Compile Error
// see much more detailed comment in the polished statistics.cpp/java

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, caseNo = 0;
  while (cin >> n, !cin.eof()) {
    int arr[n];
    for (int i = 0; i < n; ++i)
      cin >> arr[i];
    auto [cur_min, cur_max] = *minmax_element(arr, arr+n);
    cout << "Case " << ++caseNo << ": " << *cur_min << " " << *cur_max << " " << (*cur_max-*cur_min) << endl;
  }
  return 0;
}
