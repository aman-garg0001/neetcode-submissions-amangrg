class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        char dot = '.';
        for (int i = 0; i < 9; i++) {
            map<char, int> mp1, mp2;
            for (int j = 0; j < 9; j++) {
                if (((board[i][j] != dot) and (mp1.find(board[i][j]) != mp1.end())) or ((board[j][i] != dot) and (mp2.find(board[j][i]) != mp2.end()))) {
                    return false;
                }
                mp1[board[i][j]] = 1;
                mp2[board[j][i]] = 1;
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                map<char, int> mp3;
                for (int k = i*3; k < min(9, (i+1)*3); k++) {
                    for (int l = j*3; l < min(9, (j+1)*3); l++) {
                        if (board[k][l] != dot and mp3.find(board[k][l]) != mp3.end()) {
                            return false;
                        }
                        mp3[board[k][l]] = 1;
                    }
                }
            }
        }

        return true;
    }
};