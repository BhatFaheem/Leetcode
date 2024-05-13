class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0 ; i < n ; i++)
        {
            bool flag = false;
            if(grid[i][0] == 0)flag = true;
            for(int j = 0 ; j < m ; j++)
            {
                if(flag)grid[i][j] = !grid[i][j];
            }
        }
        int ans = n * (1 << (m-1));
        for(int i = 1 ; i < m ; i++)
        {
            int cnt = 0;
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[j][i] == 1)cnt++;
            }
            cnt = max(cnt , n -cnt);
            ans += (cnt * (1 << (m-i-1)));
        }
        return ans;
    }
};