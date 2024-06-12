class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt_zero = 0 , cnt_one = 0;
        for(auto n : nums) cnt_zero += (n == 0) , cnt_one += (n == 1);
        for(int &n : nums)
        {
            if(cnt_zero > 0) n = 0 , cnt_zero--;
            else if(cnt_one > 0)n =1 , cnt_one--;
            else n = 2;
        }
    }
};