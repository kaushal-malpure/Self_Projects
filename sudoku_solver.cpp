#include <bits/stdc++.h> 

bool isSafe(int row, int col, vector<vector<int>>& board, int val)
{
    for(int i = 0; i < 9; i++)
    {
        if(board[row][i] == val)
            return false;
        if(board[i][col] == val)
            return false;
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val)
            return false;
    }
    return true;
}

bool solve(vector<vector<int>>& board)
{
    for(int i = 0;i < board.size(); i++)
    {
        for(int j = 0; j < board.size(); j++)
        {
            if(board[i][j] == 0)
            {
                for(int val = 1; val <= 9; val++)
                {
                    if(isSafe(i, j, board, val))
                    {
                        board[i][j] = val;
                        bool nextsoln = solve(board);

                        if(nextsoln)
                        {
                            return true;
                        }
                        else
                        {
                            board[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
    // Passing a sudoku in a 2d vector format
	solve(sudoku);
}