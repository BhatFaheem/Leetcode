class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 1 ; i < (1 << n) ; i++)
        {
            int val = 0;
            for(int j = 0 ; j < n ; j++)
            {
                if((i >> j)&1)val ^= nums[j];
            }
            sum += val;
        }
        return sum;
    }
};