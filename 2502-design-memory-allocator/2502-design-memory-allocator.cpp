class Allocator {
public:
    vector<int> a;
    Allocator(int n) {
        a.resize(n,0);
    }
    
    int allocate(int size, int mID) {
        int sz=0;
        for(int i=0; i<a.size(); i++){
            if(a[i]!=0){ sz=0; }
            else{ ++sz; }
            if(sz==size){
                for(int j=i-size+1; j<=i; j++){ a[j]=mID; }
                return i-size+1;
            }
        }
        return -1;
    }
    
    int free(int mID) {
        int cnt=count(a.begin(),a.end(),mID);
        for(auto &it:a){ if(it==mID){ it=0; } }
        return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */