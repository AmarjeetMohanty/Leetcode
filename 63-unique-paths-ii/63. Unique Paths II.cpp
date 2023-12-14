class Solution {
public:
//to avoid stack overflow or index error
    bool isValid(int i, int j,vector<vector<int>> &obstacleGrid){
        if(i < 0 || i >= obstacleGrid.size() || j < 0  || j >= obstacleGrid[i].size())
        return false;
        return true;
    }
//recursive function to calculate number of paths
    int solve(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){
        int ans = 0;
// if the answer already exists
         if(dp[i][j] != -1) return dp[i][j];
//base condition
        if(i == 0 && j == 0){
            return dp[i][j] = 1;
        }
//check whether the current grid is an obstacle 
        if(obstacleGrid[i][j] != 1){
//if the immediate upper index and the  immediate left index are not  obstacles and exist  
        if(isValid(i,j-1,obstacleGrid) && isValid(i-1,j,obstacleGrid) && obstacleGrid[i-1][j] != 1 && obstacleGrid[i][j-1] != 1){
        ans = max(ans, solve(i,j-1,obstacleGrid,dp)+solve(i-1,j,obstacleGrid,dp));
        }
//if the immediate left index is not an obstacle and exists 
        if(isValid(i,j-1,obstacleGrid) && obstacleGrid[i][j-1] != 1){
        ans = max(ans, solve(i,j-1,obstacleGrid,dp));
        }
//if the immediate upper index is not an obstacle and exists 
        if(isValid(i-1,j,obstacleGrid) && obstacleGrid[i-1][j] != 1){
        ans = max(ans,solve(i-1,j,obstacleGrid,dp));
        }
        }
//return answer
        return dp[i][j] = ans;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//find dimensions of the grid
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
//base conditions
        if(obstacleGrid[0][0] == 1) return 0;
         if(n ==1 && m == 1) return 1;
//initialize dp 
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
//call the function recursively
        return solve(n-1,m-1,obstacleGrid,dp);
    }
};