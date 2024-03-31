class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0 , i = -1 , j = -1 , k = -1;
        int n = nums.size();
        for(int l = 0 ; l < n ; l++)
        {
            if(nums[l] == minK) i = l;
            if(nums[l] == maxK) j = l;
            if(nums[l] < minK || nums[l] > maxK) k = l;
            ans = ans + max(0LL , min(i , j) - k);
        }
        return ans;
    }
};