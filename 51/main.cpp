ass Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {

        vector<string> out(n, string(n, '.'));
        dfs(0, n, out);
        return res;
    }
    void dfs(int m, int n, vector<string> &out) {
        if (m == n) {
            res.push_back(out);
            return;
        }
        for (int i = 0; i < n; i ++ ) {
            bool st = true;
            for (int j = 0; j < m; j ++ ) {
                if (out[j][i] == 'Q') {
                    st = false;
                    break;
                }
            }
            for (int j = 0; j < m; j ++ ) {
                    // j, (n - i + m) - j
                    if ( (n - i + m) - j >= 0 && out[j][i - m + j] == 'Q') {
                        st = false;
                        break;
                    }
                    // j, (i + m) - j
                    if ( (i + m) - j < n && out[j][(i + m) - j] == 'Q') {
                        st = false;
                        break;
                    }
            }
            if (st) {
                
                out[m][i] = 'Q';
                dfs(m + 1, n, out);
                out[m][i] = '.';
            }
        }
    }
};
