class TopVotedCandidate {
public:
    map<int,int> leader;
    int mxVotes=0;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        map<int,int> votes;
        for(int i=0; i<times.size(); i++){
            votes[persons[i]]++;
            if(votes[persons[i]]>=mxVotes){ leader[times[i]]=persons[i]; mxVotes=votes[persons[i]]; }
            else{ leader[times[i]]=leader[times[i-1]]; }
        }
        // for(auto &[t,l]:leader){ cout<<t<<' '<<l<<endl; }
    }
    
    int q(int t) {
        auto it=leader.lower_bound(t);
        if(it->first>t or it==leader.end()){ it--; }
        return it->second;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */