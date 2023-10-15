class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> ans;
        vector<int> temp;
        int i=0, j=0;
        for(auto &s:words){
            if(s=="prev"){ 
                i--; 
                if(i<0){ ans.push_back(-1); }  
                else{ ans.push_back(temp[i]); }
            }
            else{ 
                int t=stoi(s); 
                temp.push_back(t);
                i=temp.size(); 
            }
        }
        return ans;
    }
};