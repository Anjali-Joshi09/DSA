class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        vector<int>ans;
        int cols=matrix[0].size();
        int max_rows=INT_MIN;
        int min_cols=INT_MAX;
        int minimum=INT_MAX;
        for(int i=0;i<rows;i++)
        {
            int minimum=INT_MAX;
            for(int j=0;j<cols;j++)
            {
                minimum=min(minimum,matrix[i][j]);
            }
            max_rows=max(max_rows,minimum);
        }
        int maximum=INT_MIN;
        for(int i=0;i<cols;i++)
        {
            int maximum=INT_MIN;
            for(int j=0;j<rows;j++)
            {
                maximum=max(maximum,matrix[j][i]);
            }
            min_cols=min(min_cols,maximum);
        }
        if(max_rows==min_cols)
        ans.push_back(max_rows);
        return ans;
    }
};