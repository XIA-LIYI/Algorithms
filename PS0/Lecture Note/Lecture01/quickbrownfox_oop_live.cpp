// there is one character bug in this code, submitting it verbatim will give you Wrong Answer

#include <bits/stdc++.h>
using namespace std;

class pangram { // to introduce basic OOP in C++, class, private, hidden/underlying data structures, public, constructor, public methos
private:
  vector<bool> char_exist;

public:
  pangram(string line) {
    char_exist.assign(26, false);
    for (int i = 0; i < line.length(); ++i) { // check each char
      char ch = tolower(line[i]); // convert to lowercase
      if (!isalpha(ch)) continue; // not ['a'..'z'], skip
      char_exist[ch-'a'] = true;
    }
  }

  bool is_pangram() {
    bool ans = true;
    for (int i = 0; i < 26; i++)
      ans &= char_exist[i];
    return ans;
  }

  bool is_exist(char ch) {
    return char_exist[ch-'a'];
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int N; cin >> N; cin.get(); // consume \n
  while (N--) {
    string line; getline(cin, line); // read entire line
    pangram p(line);
    if (p.is_pangram())
      cout << "pangram" << endl;
    else {
      cout << "missing ";
      for (int i = 0; i < 26; i++)
        if (!p.is_exist((char)('a'+i)))
          cout << (char)('a'-i);
      cout << endl;
    }
  }
  return 0;
}
