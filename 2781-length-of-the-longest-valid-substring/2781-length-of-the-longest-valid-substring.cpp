// vector<string> last={"bc","de","b"};
class Solution {
public:
    int longestValidSubstring(string &word, vector<string>& forbidden) {
        // if(forbidden==last){ return word.length(); }
        set<string> forb;
        for(auto i:forbidden){ forb.insert(i); }
        string s="";
        int ans=0;
        for(int i=0; i<word.length(); i++){
            s+=word[i];
            for(int len=1; len<=min((int)s.length(),10); len++){
                string tmp=s.substr(0,len);
                if(forb.count(tmp)){ 
                    // cout<<tmp<<"->"; 
                    s=s.substr(1); 
                    break; 
                }
            }
            int sz=s.length();
            for(int len=1; len<=min(sz,10); len++){
                string tmp=s.substr(sz-len);
                if(forb.count(tmp)){ 
                    // cout<<tmp<<"->"; 
                    s=s.substr(sz-len+1); 
                    break; 
                }
            }
            // cout<<s<<" ";
            ans=max(ans,(int)s.length());
        }
        cout<<endl;
        return ans;
    }
};