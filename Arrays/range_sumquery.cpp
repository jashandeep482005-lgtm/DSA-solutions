class Solution {
public:
    vector<int> buildPrefix(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n);

        prefix[0] = arr[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }

        return prefix;
    }

    int getRangeSum(vector<int>& prefix, int L, int R) {
        if (L == 0)
            return prefix[R];

        return prefix[R] - prefix[L - 1];
    }

    vector<int> rangeSumQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefix = buildPrefix(arr);
        vector<int> ans;

        for (auto &q : queries) {
            ans.push_back(getRangeSum(prefix, q[0], q[1]));
        }

        return ans;
    }
};