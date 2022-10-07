class MyCalendarThree {
public:
    map<int,int> mp;
    MyCalendarThree() {   
    }
    // If we sum from start to end, the result is the number of bookings in between
    // For the first booking, mp[start,end) = 1 and rest is zero
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int sum = 0;
        int ans = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            sum += it->second;
            ans = max(ans,sum);
        }
        return ans;
    }
};
