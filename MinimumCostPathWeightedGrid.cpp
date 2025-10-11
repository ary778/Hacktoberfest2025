/*
    Problem: Minimum Cost Path in a Weighted Grid
    --------------------------------------------------------
    Approach:
    - Use DP to store the minimum cost to reach each cell.
    - dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
      (if i>0 and j>0, handle borders separately)
    - Time Complexity: O(n*m)
    - Space Complexity: O(n*m) (can be optimized to O(m))
*/

#include <bits/stdc++.h>
using namespace std;

int minCostPath(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    dp[0][0] = grid[0][0];

    // Fill first row
    for(int j=1; j<m; j++) dp[0][j] = dp[0][j-1] + grid[0][j];

    // Fill first column
    for(int i=1; i<n; i++) dp[i][0] = dp[i-1][0] + grid[i][0];

    // Fill rest of the grid
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n-1][m-1];
}

int main() {
    int n, m;
    cout << "Enter grid size (n m): ";
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Enter grid values:\n";
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> grid[i][j];

    int ans = minCostPath(grid);
    cout << "Minimum cost to reach bottom-right: " << ans << endl;
    return 0;
}
