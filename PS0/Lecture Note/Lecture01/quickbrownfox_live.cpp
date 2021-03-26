// there is one character bug in this code, submitting it verbatim will give you Wrong Answer

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int N; cin >> N; cin.get(); // consume \n
  while (N--) {
    string line; getline(cin, line); // read entire line
    bool char_exist[26];
    for (int i = 0; i < 26; ++i)
      char_exist[i] = false;
    // we can also use vector<bool> char_exist(26, false);
    for (int i = 0; i < line.length(); ++i) { // check each char
      char ch = tolower(line[i]); // convert to lowercase
      if (!isalpha(ch)) continue; // not ['a'..'z'], skip
      char_exist[ch-'a'] = true;
    }
    bool is_pangram = true;
    for (int i = 0; i < 26; i++)
      is_pangram = is_pangram & char_exist[i];
    if (is_pangram)
      cout << "pangram" << endl;
    else {
      cout << "missing ";
      for (int i = 0; i < 26; i++)
        if (!char_exist[i])
          cout << (char)('a'-i);
      cout << endl;
    }
  }
  return 0;
}
