class Solution {
public:
    int reverse(int x) {
        bool neg = x < 0;
        x = abs(x);
        int ans = 0;
        while (x) {
            int rem = x%10;
            x = x/10;
            if (ans < INT_MIN/10 or ans > INT_MAX/10) {
                return 0;
            }
            ans = ans*10 + rem;
        }
        if (neg) {
            return -ans;
        }
        return ans;
    }
};
