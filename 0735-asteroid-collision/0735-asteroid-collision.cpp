class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> dq;
        // dq.push(ast[0]);
        for(int i=0; i<ast.size(); i++){
            int found=false;
            while(!dq.empty() and dq.top()>0 and ast[i]<0){
                if(dq.top()<abs(ast[i])){ dq.pop(); continue; }
                else if(dq.top()==abs(ast[i])){ dq.pop(); }
                found=true; break;
            }
            if(!found){ dq.push(ast[i]); }
        }
        vector<int> ans;
        while(!dq.empty()){ ans.push_back(dq.top()); dq.pop(); } 
        reverse(begin(ans),end(ans));
        return ans;
    }
};