class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        int mask = (1 << n);
        for(int i = 0 ; i < mask ; i++)
        {
            vector<int>temp;
            for(int j = 0 ; j < n ; j++)
            {
                if((i >> j )&1)temp.push_back(nums[j]);
            }
            ans.push_back(temp);
        } 
        return ans;
    }
};