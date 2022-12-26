class Solution {
public:
    vector<int> topStudents(vector<string>& pf, vector<string>& nf, vector<string>& r, vector<int>& student_id, int k) {
        unordered_set<string> ps(begin(pf), end(pf));
        unordered_set<string> ng(begin(nf), end(nf));
        unordered_map<int, int> mp;
        mp.reserve(size(student_id));
        for(int i=0; i<size(r); ++i){
            int sz = r[i].size(), id = student_id[i];
            for(int j = 0; j < sz; j++){
                string p;
                while(j < sz && r[i][j] != 32) p+= r[i][j], j++;
                if(ps.count(p)) mp[id]+=3;
                if(ng.count(p)) mp[id]--;
            }
        }
        partial_sort(begin(student_id), begin(student_id) + k, end(student_id), [&](auto a, auto b){
             return mp[a] == mp[b]? a < b : mp[b] < mp[a];
        });
        student_id.resize(k);
        return student_id;
    }
};