class Solution {
public:
    int totalFruit(vector<int>& f) {
        map<int,int> m;
        queue<int> q;
        int ans=0, cnt=0, i=0, n=f.size();
        for(int i=0; i<n; i++){
            q.push(i);
            ++m[f[i]];
            cnt++;
            // cout<<m.size()<<' '<<cnt<<endl;
            while(m.size()>2){
                // cout<<f[q.front()]<<" will be deleted\n";
                --m[f[q.front()]];
                if(m[f[q.front()]]==0){ m.erase(f[q.front()]); }
                q.pop();
                cnt--;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};