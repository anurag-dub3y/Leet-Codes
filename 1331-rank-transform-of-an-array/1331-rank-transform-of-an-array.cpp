class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
    int n=arr.size();
    set<int> orderedSet;
    for (int num : arr) {
        orderedSet.insert(num);
    }

    unordered_map<int, int> rankMap;
    int rank = 1;
    for (int num : orderedSet) {
        rankMap[num] = rank++;
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = rankMap[arr[i]];
    }
    return arr;
    }
};