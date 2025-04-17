#include<iostream>
#include<string>

using namespace std;

class Logger{
    private:
    static const int maxLogs = 1000;
    string logs[maxLogs];
    int logCount;
    void storeLog(const string &sev, const string &mod, const string &msg){
        string formatted="[" + sev + "] (" + mod + "): " + msg;
        if (logCount<maxLogs){
            logs[logCount++]=formatted;
        }
        else{
            for (int i=1; i<maxLogs; ++i){
                logs[i-1]=logs[i];
            }
            logs[maxLogs-1]=formatted;
        }
    }
    public:
    Logger() : logCount(0){}
    void logInfo(const string &mod, const string &msg){
        storeLog("INFO", mod, msg);
    }
    void logWarning(const string &mod, const string &msg){
        storeLog("WARNING", mod, msg);
    }
    void logError(const string &mod, const string &msg){
        storeLog("ERROR", mod, msg);
    }
    friend class AuditingSystem;
};

class AuditingSystem{
    private:
    string validAuditorToken;
    bool authenticate(const string &token) const{
        return token==validAuditorToken;
    }
    public:
    AuditingSystem(const string &token="secure123") : validAuditorToken(token){}
    void retrieveLogs(const Logger &logger, const string &token) const{
        if (!authenticate(token)){
            cout<<"Access Denied: Invalid auditor token."<<endl;
            return;
        }
        cout<<"--- Logs ---"<<endl;
        for (int i=0; i<logger.logCount; ++i){
            cout<<logger.logs[i]<<endl;
        }
        cout<<"--- End of Logs (" <<logger.logCount<< " entries) ---"<<endl;
    }
};

int main(){
    Logger L1;
    L1.logInfo("Network", "Connected to server.");
    L1.logWarning("Database", "Slow response on query.");
    L1.logError("Auth", "Login attempt failed.");
    L1.logInfo("UI", "User clicked 'Submit'.");

    AuditingSystem a1;

    cout<<endl<<"--- Attempt with correct token ---"<<endl;
    a1.retrieveLogs(L1, "secure123");
    cout<<endl<<"--- Attempt with wrong token ---"<<endl;
    a1.retrieveLogs(L1, "wrongToken");
    return 0;
}