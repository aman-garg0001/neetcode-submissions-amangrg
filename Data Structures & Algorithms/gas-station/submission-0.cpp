class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int fuel = 0;
        int i, j, n = gas.size();
        for (i = 0; i < n; i = i + j + 1) {
            fuel = 0;
            for (j = 0; j < n; j++) {
                int k = (i + j)%n;
                fuel += gas[k];
                if (fuel >= cost[k]) {
                    fuel -= cost[k];
                } else {
                    break;
                }
            }
            if (j == gas.size()) {
                return i;
            }
        }
        return -1;
    }
};