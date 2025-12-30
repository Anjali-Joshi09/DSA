class Solution {
public:
    int countSoldiers(vector<int>& row) {
        int low = 0, high = row.size();
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (row[mid] == 1)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        priority_queue<pair<int,int>> pq;

        for (int i = 0; i < mat.size(); i++) {
            int soldiers = countSoldiers(mat[i]);
            pq.push({soldiers, i});

            if (pq.size() > k)
                pq.pop();
        }

        vector<int> ans(k);
        for (int i = k - 1; i >= 0; i--) {
            ans[i] = pq.top().second;
            pq.pop();
        }

        return ans;
    }
};
