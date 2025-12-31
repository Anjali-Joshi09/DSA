class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int ones=0;
        int count=0;
        int idx=0;
        vector<int> ans;
        for(int i=0;i<m;i++)
        {
            count=0;
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1)
                count++;
            }
            if(ones<count)
            {
                ones=count;
                idx=i;
            }
        }
        ans.push_back(idx);
        ans.push_back(ones);
        return ans;
    }
};