#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
// void PrintMap(const map <string,vector<string>> &m) {
//     for (auto item : m) {
//       cout << item.first << " ";
//       for (auto i : item.second) {
//         cout << i << " ";
//       }
//       cout << endl;
//     }
// }
bool BusContainsStop(const string &stop, vector<string> stops) {
  for (string s : stops) {
    if (s == stop) {
      return true;
    }
  }
  return false;
}

vector<string> buses_for_stop (string& stop, map <string,vector<string>>& bus_stops) {
  vector <string> buses;
  for (auto bus : bus_stops) {
    if (BusContainsStop(stop, bus.second)) {
      buses.push_back(bus.first);
    }
    else continue;
  }
  return buses;
}

int main() {
  int N;
  cin >> N;

  map<string, vector<string>> bus_stops;

  for (int i = 0; i < N; i++) {
    string operation_code;
    cin >> operation_code;
    if (operation_code == "NEW_BUS") {
      string bus;
      cin >> bus;
      int stop_count;
      cin >> stop_count;
      vector<string> stops;
      for (int i = 0; i < stop_count; i++) {
        string stop;
        cin >> stop;
        stops.push_back(stop);
      }
      bus_stops[bus] = stops;
    }

    else if (operation_code == "BUSES_FOR_STOP") {
      string stop;
      cin >> stop;
      bool flag = false;
      for (auto bus : bus_stops) {
        if (BusContainsStop(stop, bus.second)) {
          flag = true;
          cout << bus.first << " ";
        }
        else continue;
      }
      if (flag == false) {
        cout << "No stop" << endl;
      } else {
        cout << endl;
      }
    }

    else if (operation_code == "STOPS_FOR_BUS") {
      string bus;
      cin >> bus;
      if (bus_stops.count(bus) == 0) {
        cout << "No bus" << endl;
      }
      else {
        vector<string> interchanges;
        for (string stop : bus_stops[bus]) {
          interchanges = buses_for_stop(stop, bus_stops);
          if ((interchanges.size() == 1) && (interchanges[0] == bus)) {
            cout << "Stop " << stop << ": " <<"no interchange" << endl;
          }
          else {
            cout << "Stop " << stop << ": ";
            for (string result_bus : interchanges) {
              if (bus != result_bus) {
                cout << result_bus << " ";
              }
            }
            cout << endl;
          }
        }
      }
    }

    else if (operation_code == "ALL_BUSES") {
      if (bus_stops.size() == 0) {
        cout << "No buses" << endl;
      }
      else {
        for (auto item: bus_stops) {
          cout << "Bus " << item.first << ": ";
          for (string stop : item.second) {
            cout << stop << " ";
          }
          cout << endl;
        }
      }
    }
  }

  return 0;
}
