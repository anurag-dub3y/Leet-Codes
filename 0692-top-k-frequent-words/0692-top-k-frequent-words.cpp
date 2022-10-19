class Solution {
public:
    struct comp{
        bool operator()(const pair<string,int>& a, const pair<string,int>& b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for(auto w : words){ freq[w]++; }
        priority_queue< pair<string,int>, vector<pair<string,int>>,comp> pq;
        for(auto w : freq ){
            pq.emplace(w.first, w.second);
            if(pq.size()>k) pq.pop();
        }
        vector<string> ans;
        while(!pq.empty()){
            ans.insert(ans.begin(), pq.top().first);
            pq.pop();
        }
        return ans;
    }

};