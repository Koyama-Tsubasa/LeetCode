class BrowserHistory {
private:
    std::vector<std::string> DBH;
    int curPid, lastPid;

public:
    BrowserHistory(string homepage) {

        DBH.push_back(homepage);
        curPid = 0;
        lastPid = 0;

    }
    
    void visit(string url) {

        curPid++;
        if (DBH.size() > curPid) DBH[curPid] = url;
        else DBH.push_back(url);
        lastPid = curPid;

    }
    
    string back(int steps) {
        
        curPid = std::max(0, curPid-steps);
        return DBH[curPid];

    }
    
    string forward(int steps) {

        curPid = std::min(lastPid, curPid+steps);
        return DBH[curPid];
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
