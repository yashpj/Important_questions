class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
                
        int n = grid.size();
        int m = grid[0].size();
        int sum =0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    checkIsland(grid,i,j);
                        sum++;
                }
            }
        }
        return sum;
    }
    
    void checkIsland(vector<vector<char>>& grid, int i , int j){
        
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j] == '0'){
            return ;
        }
        
        grid[i][j] = '0';
        checkIsland(grid,i-1,j);
        checkIsland(grid,i,j-1); 
        checkIsland(grid,i+1,j);
        checkIsland(grid,i,j+1);
        
    }
};