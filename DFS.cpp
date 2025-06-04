#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 4;
const int COLS = 4;

// Directions: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y, int target) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS) return; // Out of bounds
    if (visited[x][y]) return; // Already visited
    if (grid[x][y] != target) return; // Not the target

    visited[x][y] = true;
    cout << "Found target at (" << x << ", " << y << ")\n";

    // Explore neighbors
    for (int dir = 0; dir < 4; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        dfs(grid, visited, nx, ny, target);
    }
}

// Function to estimate memory usage (in bytes)
size_t estimateMemoryUsage(const vector<vector<int>>& grid, const vector<vector<bool>>& visited) {
    size_t gridMem = ROWS * COLS * sizeof(int);
    size_t visitedMem = ROWS * COLS * sizeof(bool);
    return gridMem + visitedMem;
}

int main() {
    vector<vector<int>> grid = {
        {1, 2, 3, 4},
        {5, 9, 1, 2},
        {3, 1, 4, 6},
        {2, 3, 8, 5}
    };
    vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
    int target;
    cout << "Enter the number you want to search: ";
    cin >> target;

    bool found = false;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (grid[i][j] == target && !visited[i][j]) {
                dfs(grid, visited, i, j, target);
                found = true;
            }
        }
    }
    if (!found) {
        cout << "Number " << target << " not found in the grid.\n";
    }

    // Print estimated memory usage
    size_t memUsed = estimateMemoryUsage(grid, visited);
    cout << "Estimated memory used by grid and visited: " << memUsed << " bytes\n";

    return 0;
}