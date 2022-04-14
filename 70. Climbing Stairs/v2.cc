/*
 * sapce O(1) solution
 */

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        int x = 0, y = 1, z = 2;
        
        for(auto i = 3; i <= n; ++i) {
            x = y;
            y = z;
            z = x + y;
        }
        
        return z;
    }
};
