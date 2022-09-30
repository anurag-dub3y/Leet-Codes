class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<pair<int, int>> heights;
        vector<vector<int>> skyline;
        int pos = 0; 
        int currDist = buildings[0][0]; // The current x-position
        while (pos < buildings.size() or !heights.empty()) {
            if (heights.empty()) {
                // If there is nothing in the heap, then it was a gap; 
                // just push the next building and then we can continue by placing the start
                int nextLeft = buildings[pos][0];
                while (pos < buildings.size() and buildings[pos][0] == nextLeft) {
                    heights.push({buildings[pos][2], buildings[pos][1]});
                    pos++;
                }
                // Add the first point
                skyline.push_back({nextLeft, heights.top().first});
                currDist = nextLeft;
                continue;
            }
            // The height before the next possible current spot is chosen
            int currHeight = heights.top().first;
            if (pos < buildings.size()) { // If there are buildings to add
                
                int nextLeft = buildings[pos][0];
                int endOfBlock = heights.top().second;

                // Add the buildings at the next currDistance
                // If there are buildings before the current end, add them so we can check
                if (nextLeft <= endOfBlock) {
                    // Add all of the buildings with this start position
                    while (pos < buildings.size() and buildings[pos][0] == nextLeft) {
                        heights.push({buildings[pos][2], buildings[pos][1]});
                        pos++;
                    }
                    currDist = nextLeft; 
                }
                else { //Otherwise get to the end of this block
                    currDist = endOfBlock;
                    // Remove the current, as well as those that have "expired" 
                    while (not heights.empty() and heights.top().second <= currDist)
                        heights.pop();
                }
            }
            else {
                // Now just give the next possible drop as well as set the end point at the drop
                currDist = heights.top().second;
                while (not heights.empty() and heights.top().second <= currDist)
                    heights.pop();
            }
            // If it goes to the ground (0)
            if (heights.empty()) {
                skyline.push_back({currDist, 0});
                continue;
            } 
            // If there was a height change 
            if (heights.top().first != currHeight) 
                skyline.push_back({currDist, heights.top().first});
            
        }
        
        return skyline;

    }
};