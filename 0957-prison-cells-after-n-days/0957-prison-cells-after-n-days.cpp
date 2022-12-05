class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cell, int n) {
        vector<int> temp(8,0);
        vector<vector<int>> seen;
        while(n--){
            for(int i=1; i<7; i++){
                temp[i]=(cell[i-1]==cell[i+1]);
            }
            if(count(seen.begin(),seen.end(),temp)!=0){ return seen[n%seen.size()]; }
            seen.push_back(temp);
            cell=temp;
        }
        return cell;
    }
};