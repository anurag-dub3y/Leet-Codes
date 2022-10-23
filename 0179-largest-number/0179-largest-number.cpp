class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(auto i:nums){ v.push_back(to_string(i)); }
        sort(v.begin(),v.end(),[&](const string a, const string b){
            return (string)(a+b)>(string)(b+a);
        });
        string largestN="";
        for(auto it:v){ largestN+=it; }
        if(count(largestN.begin(),largestN.end(),'0')==largestN.length()){ return "0"; }
        return largestN;
    }
};