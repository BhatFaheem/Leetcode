class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 28 ; i >= 0 ; i--)
        {
            int bit = (k >> i)&1;
            int cnt = 0;
            for(auto n : nums)
            {
                if((n>>i)&1)cnt++;
            }
            cnt %=2;
            ans += (cnt != bit);
        }
        return ans;
    }
};