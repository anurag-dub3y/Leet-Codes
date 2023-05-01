int cap=0;
// typedef pair<int,int> pii;
// struct comp{
//     // bool operator<(const pii &a, const pii &b){
//         // if(a.ff>cap){ return false; }
//         // else if(b.ff>cap){ return true; }
//         // return (double)(a.ss/a.ff)>(double)(b.ss/b.ff);
//         // return true;
//     }
// };
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profit, vector<int>& capital) {
        int n = profit.size();
        vector<pair<int, int>> projects(n);
        for (int i = 0; i < n; i++) {
            projects[i] = {capital[i], profit[i]};
        }
        sort(projects.begin(), projects.end());
        int i = 0;
        priority_queue<int> profits;
        while (k--) {
            while (i < n && projects[i].first <= w) {
                profits.push(projects[i].second);
                i++;
            }
            if(profits.empty()) break;
            w += profits.top();
            profits.pop();
        }
        return w;
    }
};