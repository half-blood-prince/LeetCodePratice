Question link:https://leetcode.com/problems/number-of-islands/
class Solution {
    private:
    void bfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &grid){
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int delrow=-1; delrow<=1;delrow++){
                int nrow=row+delrow;
                if(nrow>=0 and nrow<n and !vis[nrow][col] and grid[nrow][col]=='1'){
                    vis[nrow][col]=1;
                    q.push({nrow,col});
                }
            }
            for(int delcol=-1; delcol<=1;delcol++){
                int ncol=col+delcol;
                if(ncol>=0 and ncol<m and !vis[row][ncol] and grid[row][ncol]=='1'){
                    vis[row][ncol]=1;
                    q.push({row,ncol});
                }
            }

        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int count=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] and grid[row][col]=='1'){
                    count++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return count;
    }
};
