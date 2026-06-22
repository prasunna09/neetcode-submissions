class Solution {
public:
    struct PairHash {
    size_t operator()(const pair<int,int>& p) const {
        return hash<int>{}(p.first) ^ (hash<int>{}(p.second) << 1);
    }
};

unordered_map<pair<int,int>, vector<int>, PairHash> squares;

    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, vector<int>> rows;
        unordered_map<int, vector<int>> col;
        unordered_map<pair<int, int>, vector<int>, PairHash> square; //r/3, col/3

        for(int r=0; r<9; r++){
            for(int c=0; c<9; c++){
                if(board[r][c]=='.'){
                    continue;
                }else{
                    if((find(rows[r].begin(), rows[r].end(), board[r][c]) != rows[r].end()) ||
                        find(col[c].begin(), col[c].end(), board[r][c]) != col[c].end()
                        || find(square[{r/3, c/3}].begin(),
     square[{r/3, c/3}].end(),
     board[r][c]) != square[{r/3, c/3}].end()){
                            
                        return false;   
                    }
                    else{
                        rows[r].push_back(board[r][c]);
                        col[c].push_back(board[r][c]);
                        square[{r/3, c/3}].push_back(board[r][c]);

                    }
                }
            }
        }
        return true;
 
    }
};
