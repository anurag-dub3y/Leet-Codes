class Solution {
public:
    double average(vector<int>& salary) {
        sort(begin(salary),end(salary));
        return accumulate(begin(salary)+1,begin(salary)+salary.size()-1,0.00)/(salary.size()-2);
    }
};