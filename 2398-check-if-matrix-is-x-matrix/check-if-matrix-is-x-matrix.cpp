class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    if(grid[i][j]<1)
                    return false;
                }
                if(grid[i][n-i-1]<1)
                    return false;
                if(i!=j && j!=n-i-1 && grid[i][j]!=0)
                return false;
            }
        }
        return true;
    }
};