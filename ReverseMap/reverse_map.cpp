#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

void PrintMap(const map <int,string> &m) {
    for (auto item : m) {
        cout << item.first << " " << item.second << endl;
    }
}

void PrintReversedMap(const map <string,int> &m) {
    for (auto item : m) {
        cout << item.first << " " << item.second << endl;
    }
}

map<string, int> BuildReversedMap(const map<int, string>& m) {
  map<string, int> result;
  for (auto item : m) {
    result[item.second] = item.first;
  }
  return result;
}


int main() {
    vector<string> words = {"one", "two", "one"};
    map <string, int> counters;
    // for (const string& word : words) {
    //     if (counters.count(word) == 0) {
    //         counters[word] = 1;
    //     }
    //     else {
    //         ++counters[word];
    //     }
    // }
    for (const string& word : words) {
        ++counters[word];
    }
    return 0;
}
