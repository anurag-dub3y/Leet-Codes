/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &m) {
        int s = 0, l = m.length() - 1, mid;
        while(s < l){
            mid = s + (l - s) / 2;
            if(m.get(mid) < m.get(mid + 1)) s = mid + 1;
            else l = mid;
        }
        
        int peak = s;
        
		// Binary Search in First Half
        s = 0; l = peak;
        bool flagL = false, flagR = false;
        while(s <= l){
            mid = s + (l - s) / 2;
            if(m.get(mid) == target){
                flagL = true;
                break;
            }
            else if(m.get(mid) < target) s = mid + 1;
            else l = mid - 1;
        }

        if(flagL){ return mid; }
        
		// Binary Search in second Half
        s = peak + 1; l = m.length() - 1;
        while(s <= l){
            mid = s + (l - s) / 2;
            if(m.get(mid) == target){
                flagR = true;
                break;
            }
            else if(m.get(mid) > target) s = mid + 1;
            else l = mid - 1;
        }

        if(flagR){ return mid; }
        
        return -1;
    }
};