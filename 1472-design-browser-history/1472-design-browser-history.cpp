class BrowserHistory {
public:
    vector<string> s;
    int i=0;
    BrowserHistory(string homepage) {
        s.clear();
        i=0;
        s.push_back(homepage);
    }
    
    void visit(string url) {
        s.erase(s.begin()+i+1,s.end());
        s.push_back(url);
        i++;
    }
    
    string back(int steps) {
        i=max(0,i-steps);
        return s[i];
    }
    
    string forward(int steps) {
        i=min((int)(s.size()-1),i+steps);
        return s[i];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */