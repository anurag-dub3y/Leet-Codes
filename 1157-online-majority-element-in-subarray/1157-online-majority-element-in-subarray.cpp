class MajorityChecker {
public:
    vector<int> arr;
    unordered_map<int, vector<int>> idx;
    MajorityChecker(vector<int>& arr) : arr(arr) {
      for (auto i = 0; i < arr.size(); ++i)
          idx[arr[i]].push_back(i);
    }
    int query(int l, int r, int threshold) {
      for (auto n = 0; n < 5; ++n) {
        auto it = idx.find(arr[l + rand() % (r - l + 1)]);
        const auto &id = it->second;
        if (upper_bound(begin(id), end(id), r) - 
            lower_bound(begin(id), end(id), l) >= threshold)
            return it->first;
      }
      return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */