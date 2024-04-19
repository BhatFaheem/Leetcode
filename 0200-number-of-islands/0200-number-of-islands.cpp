class Solution {
public:
void bfs(int i , int j , vector<vector<int>>& vis , vector<vector<char>> grid)
{
    vis[i][j] = 1;
    queue<pair<int , int >> q;
    q.push({i , j});
    int n = grid.size();
    int m = grid[0].size();
    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        int x = row+1;
        int y = col;
        if(x < n && vis[x][y] == 0 && grid[x][y] == '1')
        {
            q.push({x, y});
            vis[x][y] = 1;
        }
        x = row-1;
        y = col;
        if(x >= 0 && vis[x][y] == 0 && grid[x][y] == '1')
        {
            q.push({x, y});
            vis[x][y] = 1;
        }
        x = row;
        y = col+1;
        if(y < m && vis[x][y] == 0 && grid[x][y] == '1')
        {
            q.push({x, y});
            vis[x][y] = 1;
        }
        x = row;
        y = col-1;
        if(y >= 0 && vis[x][y] == 0 && grid[x][y] == '1')
        {
            q.push({x, y});
            vis[x][y] = 1;
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n , vector<int>(m , 0));
        int cnt = 0;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j] == '1' && vis[i][j] == 0)
                {
                    bfs(i, j, vis, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};