class Solution {
public:
    bool prime[1000006];
    vector<int> closestPrimes(int left, int right) {
        memset(prime,true,sizeof(prime));
        prime[1]=false;
        for(int i=2; i*i<=1e6+5; i++){
            if(prime[i]){
                for(int j=i*i; j<=1e6+5; j+=i){ prime[j]=false; }
            }
        }
        for(int i=left; i<=right; i++){ if(prime[i]){ cout<<i<<' '; } }
        vector<int> ans;
		vector<int> temp;
		int diff=1e7;
		for(int i=left; i<=right; i++){
			if(prime[i]){
				temp.push_back(i);
				if(temp.size()==2){
					if(temp[1]-temp[0]<diff){
						diff=temp[1]-temp[0];
						ans=temp;
					}
					temp.clear();
					temp.push_back(i);
				}
			}    
		}
		if(ans.size()==0) return {-1,-1};
		return ans;
    }
};