#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

void PrintVector(vector<string> &v) {
    for (auto s : v) {
        cout << s << " ";
    }
    cout << endl;
}

int main () {
    vector<int> days_in_months = {31,28,31,30,31,30,31,31,30,31,30,31};
    int current_month = 0;
    vector<vector <string>> vector_of_todos;
    vector_of_todos.resize(days_in_months[current_month]);
    int number_of_operations;
    cin >> number_of_operations;
    for (int i  = 0; i < number_of_operations; i++) {
        string operation_code;
        cin >> operation_code;

        if (operation_code == "ADD") {
            int day;
            cin >> day;
            string assignment;
            cin >> assignment;
            vector_of_todos[day-1].push_back(assignment);
        }

        else if (operation_code == "DUMP") {
            int day;
            cin >> day;
            cout << vector_of_todos[day-1].size() << " ";
            PrintVector(vector_of_todos[day-1]);
        }

        else if (operation_code == "NEXT"){

            if (days_in_months[(current_month + 1) % 12] < days_in_months[current_month]) {
                int extra_days = days_in_months[current_month] - days_in_months[(current_month + 1) % 12];
                vector<string> extra_todos;
                for (int i = 0; i < extra_days; i++) {
                    extra_todos.insert(end(extra_todos), begin(vector_of_todos[days_in_months[current_month] - 1 - i]),
                                    end(vector_of_todos[days_in_months[current_month] - 1 - i]));
                }
                // тут начинается лишний код. 
                //1. Стоило итерироваться не от 0, а от новой длины массива
                //2. vector_of_todos[days_in_months[current_month] - 1] - часто повторяется, можно создать ссылку с коротким названием
                //3. days_in_months[current_month] -- создать переменные new_length и old_length
                vector_of_todos[days_in_months[(current_month + 1) % 12] - 1].insert(end(vector_of_todos[days_in_months[(current_month + 1) % 12] - 1]), 
                                    begin(extra_todos), end(extra_todos));
            }
            vector_of_todos.resize(days_in_months[(current_month + 1) % 12]);
            current_month = (current_month + 1) % 12;
        }
    }
    return 0;
}
