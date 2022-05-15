#include <bits/stdc++.h>
using namespace std;
// backtraking

void solve(int col, vector<string> &board, vector<vector<string>> &ans,
           vector<int> &rowCounter,
           vector<int> &NEDiagonalCounter, vector<int> &SEDiagonalCounter, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (rowCounter[row] == 0 && SEDiagonalCounter[row + col] == 0 && NEDiagonalCounter[n - 1 + col - row] == 0)
        {

            board[row][col] = 'Q';
            rowCounter[row] = 1;
            SEDiagonalCounter[row + col] = 1;
            NEDiagonalCounter[n - 1 + col - row] = 1;

            solve(col + 1, board, ans, rowCounter, NEDiagonalCounter, SEDiagonalCounter, n);

            board[row][col] = '_';
            rowCounter[row] = 0;
            SEDiagonalCounter[row + col] = 0;
            NEDiagonalCounter[n - 1 + col - row] = 0;
        }
    }
}

vector<vector<string>> getSolutions(int n)
{
    vector<vector<string>> ans; // Stores all the solutions
    vector<string> board(n);    // Stores the current board

    string s(n, '_');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }

    vector<int> rowCounter(n, 0);                // Keeps track of which rows are occupied
    vector<int> NEDiagonalCounter(2 * n - 1, 0); // Keeps track of which NW diagonals are occupied
    vector<int> SEDiagonalCounter(2 * n - 1, 0); // Keeps track of which SE diagonals are occupied

    solve(0, board, ans, rowCounter, NEDiagonalCounter, SEDiagonalCounter, n);
    return ans;
}

int main()
{
    int n;
    cout << "Enter the value of N: ";
    cin >> n;
    int cnt = 0;

    vector<vector<string>> ans = getSolutions(n);
    cout << "\nNumber of solutions: " << ans.size() << endl;
    cout << "The solutions are: \n";

    for (int i = 0; i < (int)ans.size(); i++)
    {
        cnt++;
        cout << "solution:- " << cnt <<"\n";

        for (int j = 0; j < (int)ans[i].size(); j++)
        {
            for (int k = 0; k < (int)ans[i][j].length(); k++)
            {
                cout << ans[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}
