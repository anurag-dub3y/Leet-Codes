class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int totalCapacity){
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int i = 0, j = 0, n = buses.size(), m = passengers.size(), currentCapacity;
        while(i < n){
            currentCapacity = 0;
            while(j < m && currentCapacity < totalCapacity && passengers[j] <= buses[i]){
                j++;
                currentCapacity++;
            }
            if(i == n - 1){
                j--;
                if(currentCapacity < totalCapacity){
                    int time = buses[i];
                    while(j >= 0 && time == passengers[j]){ time--, j--; }
                    return time;
                }
                else{
                    int time = passengers[j] - 1;
                    j--;
                    while(j >= 0 && time == passengers[j]){ time--, j--; }
                    return time;
                }
            }
            i++;
        }
        return buses.back();
    }
};