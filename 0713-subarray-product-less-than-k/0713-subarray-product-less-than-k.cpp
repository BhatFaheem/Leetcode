class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
        {
            int p = 1;
            for(int j = i ; j < n ; j++)
            {
                if(p * nums[j] < k)ans++ , p *= nums[j];
                else break;
            }
        }
        return ans;
    }
};