class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obs) {
        vector<int> ans, mono;
        for (auto a : obs) {
            int l = 0, r = mono.size();
            while (l < r) {
                int mid = (l + r) / 2;
                if(mono[mid] <= a){ l = mid + 1; }
                else{ r = mid; }
            }
            ans.push_back(l + 1);
            if (mono.size() == l){ mono.push_back(a); }
            mono[l] = a;
        }
        return ans;
    }
};