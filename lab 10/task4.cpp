#include <iostream>
#include <fstream>
#include <cstdio>    // for rename()
#include <string>
using namespace std;

const string LOG_FILE = "log.txt";
const long MAX_SIZE = 50000; 

long getFileSize(const string& filename) {
    FILE* fp = fopen(filename.c_str(), "rb");
    if (!fp) return 0;
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fclose(fp);
    return size;
}

int getNextLogNumber() {
    int i = 1;
    char name[20];
    while (true) {
        sprintf(name, "log%d.txt", i);
        FILE* fp = fopen(name, "r");
        if (!fp) break;
        fclose(fp);
        i++;
    }
    return i;
}

// Rename log.txt → logN.txt
void rotateLogFile() {
    int nextLogNum = getNextLogNumber();
    string newName = "log" + to_string(nextLogNum) + ".txt";
    rename(LOG_FILE.c_str(), newName.c_str()); // C-style rename
    cout << "[INFO] Rotated log to: " << newName << endl;
}

void writeLog(const string& message) {
    if (getFileSize(LOG_FILE) > MAX_SIZE) {
        rotateLogFile();
    }

    ofstream log(LOG_FILE, ios::app);
    log << message << endl;
    log.close();
}

int main() {
    for (int i = 0; i < 50000; ++i) {
        writeLog("This is log entry number: " + to_string(i));
    }

    cout << "Logging complete.\n";
    return 0;
}