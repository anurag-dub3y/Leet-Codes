class Solution {
public:
    int find(vector<int>& parent,int a){
		if(a==parent[a]){ return a; }
        parent[a]=find(parent,parent[a]);
        return parent[a];
	}
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        vector<int> par(n);
        iota(par.begin(),par.end(),0);
        map<int,int> max_element, count;
        sort(edges.begin(),edges.end(),[&](const vector<int> &a, const vector<int> &b){
            int x=max(vals[a[0]],vals[a[1]]), y=max(vals[b[0]],vals[b[1]]);
            return x<y;
        });
        int ans=n;
        for(int i=0;i<n;i++){
			par[i]=i;
			max_element[i]=vals[i];
			count[i]=1;
		}
        for(auto &e:edges){
            int a=find(par,e[0]), b=find(par,e[1]);
            if(max_element[a]!=max_element[b]){
                if(max_element[a]>max_element[b]){ par[b]=a; }
                else{ par[a]=b; }
            }
            else{
                ans+=count[a]*count[b];
                par[b]=a;
                count[a]+=count[b];
            }
        }
        return ans;
    }
};