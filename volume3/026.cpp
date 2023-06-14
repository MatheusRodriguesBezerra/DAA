#include <iostream>
#include <vector>
using namespace std;

int dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j] || grid[i][j] == '.') {
        return 0;
    }
    visited[i][j] = true;
    int size = 1;
    size += dfs(i - 1, j, grid, visited);
    size += dfs(i + 1, j, grid, visited);
    size += dfs(i, j - 1, grid, visited);
    size += dfs(i, j + 1, grid, visited);
    return size;
}

int largestMicrobe(vector<vector<char>>& grid) {
    int largest = 0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '#' && !visited[i][j]) {
                int size = dfs(i, j, grid, visited);
                if (size > largest) {
                    largest = size;
                }
            }
        }
    }
    return largest;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, c;
        cin >> l >> c;
        vector<vector<char>> grid(l, vector<char>(c));
        for (int j = 0; j < l; j++) {
            for (int k = 0; k < c; k++) {
                cin >> grid[j][k];
            }
        }
        cout << largestMicrobe(grid) << endl;
    }
    return 0;
}
