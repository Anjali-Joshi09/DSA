class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            vector<int> freq(n+1,0);
            for(int j=0;j<n;j++)
            {
                int val = matrix[i][j];
                if (val < 1 || val > n || freq[val]++)
                return false;
            }
        }
        for (int j = 0; j < n; j++) 
        {
            vector<int> freq(n + 1, 0);
            for (int i = 0; i < n; i++) 
            {
                int val = matrix[i][j];
                if (val < 1 || val > n || freq[val]++)
                return false;
            }
        }
        return true;
    }
};