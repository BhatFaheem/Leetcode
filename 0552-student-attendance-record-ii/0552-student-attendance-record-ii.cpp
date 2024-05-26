class Solution {
public:
int mod = 1e9+7;
    int checkRecord(int n) {
        int dp[n+1][2][3];
        memset(dp , 0 , sizeof(dp));
        dp[0][0][0] = 1;
        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 0 ; j <= 1 ; j++)
            {
                for(int k = 0 ; k <= 2 ; k++)
                {
                    dp[i][j][0] = (dp[i][j][0] + dp[i-1][j][k])%mod;
                    if(j < 1)dp[i][j+1][0] = (dp[i][j+1][0]+ dp[i-1][0][k])%mod;
                    if(k < 2)dp[i][j][k+1] = (dp[i][j][k+1] + dp[i-1][j][k])%mod;
                }
            }
        }
        int ans = 0;
        for(int j = 0 ; j <= 1 ; j++)
        {
            for(int k = 0 ; k <= 2 ; k++)
            {
                ans += dp[n][j][k];
                ans %= mod;
            }
        }
        return ans;
    }
};