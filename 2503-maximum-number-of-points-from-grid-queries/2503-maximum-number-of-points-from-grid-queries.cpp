class Solution {
public:
    #define pii pair<int,int>
    int d[5]={0,-1,0,1,0};
    vector<int> maxPoints(vector<vector<int>>& g, vector<int>& q) {
        int k=q.size(), m=g.size(), n=g[0].size();
        vector<int> ans(k);
        vector<int> later=q;
        sort(q.begin(),q.end());
        int curr=0;
        vector<int> vis(m*1001+1,0);
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        pq.push({g[0][0],0}); vis[0]=1;
        unordered_map<int,int> um;
        for(int qq=0; qq<k; qq++){
            int val=q[qq];
            while(!pq.empty()){
                pii top=pq.top(); pq.pop();
                if(top.first>=val){ pq.push(top); break; }
                curr++;
                int i=top.second/1001, j=top.second%1001;
                cout<<i<<' '<<j<<' '<<curr<<endl;
                for(int r=1; r<5; r++){
                    int x=i+d[r], y=j+d[r-1];
                    if(x>=m or y>=n or x<0 or y<0 or vis[1001*x+y]){ continue; }
                    vis[1001*x+y]=1;
                    pq.push({g[x][y],1001*x+y});
                }
            }
            um[q[qq]]=curr;
        }
        for(int i=0; i<k; i++){
            ans[i]=um[later[i]];
        }
        return ans;
    }
};