#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string FILENAME = "tasks.txt";

void addTask() {
    string task;
    cout << "Enter a new task: ";
    getline(cin, task);

    ofstream file(FILENAME, ios::app);
    file << "[ ] " << task << "\n";
    file.close();
    cout << "Task added.\n";
}

void viewTasks() {
    ifstream file(FILENAME);
    string line;
    int count = 1;
    cout << "\n--- TO-DO LIST ---\n";
    while (getline(file, line)) {
        cout << count++ << ". " << line << "\n";
    }
    file.close();
}

void markTaskDone() {
    vector<string> tasks;
    ifstream file(FILENAME);
    string line;

    while (getline(file, line)) {
        tasks.push_back(line);
    }
    file.close();

    viewTasks();
    int taskNum;
    cout << "\nEnter task number to mark as done: ";
    cin >> taskNum;
    cin.ignore(); // clear newline

    if (taskNum < 1 || taskNum > tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }

    if (tasks[taskNum - 1].substr(0, 3) == "[x]") {
        cout << "Task already marked as done.\n";
    } else {
        tasks[taskNum - 1][1] = 'x';
        cout << "Task marked as done.\n";
    }

    ofstream outFile(FILENAME); // overwrite
    for (const string& task : tasks) {
        outFile << task << "\n";
    }
    outFile.close();
}

int main() {
    while (true) {
        cout << "\n--- TO-DO MANAGER ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Done\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;
        cin.ignore(); // to handle newline after int input

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markTaskDone(); break;
            case 4: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice.\n";
        }
    }
}