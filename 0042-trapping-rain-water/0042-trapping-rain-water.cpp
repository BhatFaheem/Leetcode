class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        vector<int>left(n , 0) , right(n , 0);
        int val = 0;
        for(int i = 0 ; i < n ; i++)
        {
            left[i] = val;
            val = max(val , a[i]);
        }
        val = 0;
        for(int i = n-1 ; i >= 0 ; i--)
        {
            right[i] = val;
            val = max(val , a[i]);
        }
        int sum = 0;
        for(int i = 0 ; i <n ; i++)
        {
            int x = min(left[i] , right[i]);
            sum += max(0 , x - a[i]);
        }
        return sum;
    }
};