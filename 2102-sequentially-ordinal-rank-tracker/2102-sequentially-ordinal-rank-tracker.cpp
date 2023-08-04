class SORTracker {
public:
    set<pair<int, string>> s;
    set<pair<int, string>>::iterator it = end(s);    
    void add(string name, int score) {
        auto it1 = s.insert({-score, name}).first;
        if (it == end(s) || *it1 < *it){ --it; }
    }
    string get() {
        string ans=it->second;
        it++;
        return ans;
    }
};