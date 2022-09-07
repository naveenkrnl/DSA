class Solution {
public:
   
    int cherryPickupRecursion(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        if(i==grid.size() || j1<0 || j1==grid[0].size() || j2<0 || j2==grid[0].size())  return 0;
        
        if(dp[i][j1][j2]!=-1)   return dp[i][j1][j2];
        
        int maxi = 0;
        for(int k = -1;k<=1;k++){
            for(int l = -1;l<=1;l++){
                if(j1==j2)  maxi = max(maxi, grid[i][j1] + cherryPickupRecursion(i+1, j1+k, j2+l, grid, dp));
                else maxi = max(maxi, grid[i][j1]+grid[i][j2] + cherryPickupRecursion(i+1, j1+k, j2+l, grid, dp));
            }
        }
        dp[i][j1][j2]=maxi;
        return maxi;
    }
    
    int cherryPickupTabulation(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1, vector<int>(m+1, 0)));
        
        for(int i=n-1;i>=0;i--){
            for(int j1=0;j1<m;j1++)
            {
                for(int j2=m-1;j2>=0;j2--){
                    int maxi = 0;
                    for(int k = -1;k<=1;k++){
                        for(int l = -1;l<=1;l++){
                            if((j1+k)>=0 && (j1+k)!=m && (j2+l)>=0 && (j2+l)!=m){
                                if(j1==j2)  maxi = max(maxi, grid[i][j1] + dp[i+1][j1+k][j2+l]);
                                else maxi = max(maxi, grid[i][j1]+grid[i][j2] + dp[i+1][j1+k][j2+l]);                           
                            }
                        }
                    }
                    dp[i][j1][j2]=maxi;
                }
            }
        }
        
        return dp[0][0][m-1];
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> prev(m+1, vector<int>(m+1, 0));
        
        
         
        for(int i=n-1;i>=0;i--){
            vector<vector<int>> curr(m+1, vector<int>(m+1, 0));

            for(int j1=0;j1<m;j1++)
            {
                for(int j2=m-1;j2>=0;j2--){
                    int maxi = 0;
                    for(int k = -1;k<=1;k++){
                        for(int l = -1;l<=1;l++){
                            if((j1+k)>=0 && (j1+k)!=m && (j2+l)>=0 && (j2+l)!=m){
                                if(j1==j2)  maxi = max(maxi, grid[i][j1] + prev[j1+k][j2+l]);
                                else maxi = max(maxi, grid[i][j1]+grid[i][j2] + prev[j1+k][j2+l]);                           
                            }
                        }
                    }
                    curr[j1][j2]=maxi;
                }
            }
            prev = curr;
        }
        
        return prev[0][m-1];
    }
    
};