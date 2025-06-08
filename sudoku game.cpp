#include <iostream>
#include <vector>

using namespace std;

const int N = 9;

// Function to print the Sudoku board
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < N; ++i) {
        if (i % 3 == 0 && i != 0)
            cout << "------+-------+------\n";
        for (int j = 0; j < N; ++j) {
            if (j % 3 == 0 && j != 0)
                cout << "| ";
            if (board[i][j] == 0)
                cout << ". ";
            else
                cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Check if it's safe to place num at board[row][col]
bool isSafe(const vector<vector<int>>& board, int row, int col, int num) {
    for (int x = 0; x < N; ++x)
        if (board[row][x] == num || board[x][col] == num)
            return false;

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[startRow + i][startCol + j] == num)
                return false;

    return true;
}

// Solve the Sudoku using backtracking
bool solveSudoku(vector<vector<int>>& board) {
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; ++num) {
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board))
                            return true;
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> board = {
        {5,3,0, 0,7,0, 0,0,0},
        {6,0,0, 1,9,5, 0,0,0},
        {0,9,8, 0,0,0, 0,6,0},

        {8,0,0, 0,6,0, 0,0,3},
        {4,0,0, 8,0,3, 0,0,1},
        {7,0,0, 0,2,0, 0,0,6},

        {0,6,0, 0,0,0, 2,8,0},
        {0,0,0, 4,1,9, 0,0,5},
        {0,0,0, 0,8,0, 0,7,9}
    };

    // Make a copy and solve it for the answer
    vector<vector<int>> solution = board;
    if (!solveSudoku(solution)) {
        cout << "No solution exists.\n";
        return 0;
    }

    cout << "Welcome to Sudoku!\n";
    while (true) {
        printBoard(board);
        cout << "Enter your move (row col value, 1-based index), or 0 0 0 to give up: ";
        int row, col, val;
        cin >> row >> col >> val;
        if (row == 0 && col == 0 && val == 0) {
            cout << "You gave up! The correct solution is:\n";
            printBoard(solution);
            break;
        }
        row--; col--; // Convert to 0-based index
        if (row < 0 || row >= N || col < 0 || col >= N || val < 1 || val > 9) {
            cout << "Invalid input. Try again.\n";
            continue;
        }
        if (board[row][col] != 0) {
            cout << "Cell already filled. Try another.\n";
            continue;
        }
        if (solution[row][col] != val) {
            cout << "Wrong move! The correct solution is:\n";
            printBoard(solution);
            break;
        }
        board[row][col] = val;

        // Check if finished
        bool finished = true;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (board[i][j] == 0)
                    finished = false;
        if (finished) {
            cout << "Congratulations! You solved the Sudoku!\n";
            printBoard(board);
            break;
        }
    }
    return 0;
}