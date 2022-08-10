class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> diff(n);
        transform(gas.begin(), gas.end(), cost.begin(), diff.begin(), minus<int>());
        
        int i = 0, j = 0;
        int sum = diff[0];
        
        while(!(i == j % n && i != j)) { // j reaches i's position
            if(sum < 0) {
                if(j >= n - 1) return -1;
                j = i = j + 1;
                sum = diff[i];
            } else {
		++j;
                sum += diff[j % n];
            }
        }
        
        return i;
    }
};
