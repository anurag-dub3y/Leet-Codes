class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string> >  mp;
        vector<vector<string> > res;
        
        for (const auto& path : paths) {
            stringstream ss(path);
            string directoryName;
            string s;
            getline(ss, directoryName, ' ');
            while (ss >> s) {
                string fileName = s.substr(0, s.find('('));
                string fullName = directoryName + '/' + fileName;
                string fileContent = s.substr(s.find('(') + 1, s.find(')')
                                              -s.find('(') - 1);
                mp[fileContent].push_back(fullName);
            }
        }
        
        for (const auto& m : mp) 
            if (m.second.size() > 1)
                res.push_back(m.second);

        return res;    
    }
};