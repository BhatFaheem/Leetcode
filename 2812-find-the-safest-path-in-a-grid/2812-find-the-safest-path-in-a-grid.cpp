class Solution {
public:
vector<pair<int , int>> vp;
int dx[4] = {0 , 0 ,-1 , 1};
int dy[4] = {1 , -1, 0 , 0};
int get_d(int x , int y)
{
    int mini = 1e6;
    for(auto v : vp) mini = min(mini , abs(v.first - x) + abs(v.second - y));
    return mini;
}
bool safe(int mid , int n , vector<vector<int>>&grid)
{
    priority_queue<array<int , 3>> pq;
    vector<vector<int>>vis(n , vector<int>(n , 0));
    int d = get_d(0 , 0);
    pq.push({d , 0 , 0});
    vis[0][0] = 1;
    while(!pq.empty())
    {
        auto it = pq.top();
        int dist = it[0] , x = it[1] , y = it[2];
        pq.pop();
        if(x == n-1 && y == n-1) return dist >= mid;
        for(int i = 0 ; i < 4 ; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0 && vis[nx][ny] == 0)
            {
                int d = get_d(nx , ny);
                vis[nx][ny] = 1;
                pq.push({min(dist  , d) , nx , ny});
            }
        }
    }
    return false;
}
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return 0;
        int s = 0 , e =2*n;
        int ans = 0;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++) if(grid[i][j] == 1)vp.push_back({i , j});
        while(s <= e)
        {
            int mid = s + (e-s)/2;
            if(safe(mid , n , grid))
            {
                ans = mid;
                s = mid+1;
            }
            else e = mid-1;
        }
        return ans;
    }
};