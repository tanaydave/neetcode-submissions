class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = { false };
        bool cols[9][9] = { false };
        bool grids[9][9] = { false };

        for(int i = 0 ; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {

                if(board[i][j] == '.') continue;
                // converting from string to number and also making the range from 0 to 8 
                int num = board[i][j] - '0' - 1;
                // total grids 9
                int gridIndex = ((i / 3) * 3) + (j / 3);

                if(rows[i][num] || cols[j][num] || grids[gridIndex][num] ) return false;
                rows[i][num] = true;
                cols[j][num] = true;
                grids[gridIndex][num] = true;

            }
        }
        return true;
    }
};
