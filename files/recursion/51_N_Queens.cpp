==============================================================
|| For a cell (r,c),                                        ||
||                                                          ||
|| >> principal diagonals centered arround (r , c)          ||
|| will have thier co-ordinates (i,j) such that:            ||
||                                                          ||
|| r-c = i - j;                                             ||
||                                                          ||
|| >> For other diagonal,                                   ||
||                                                          ||
|| r+c = i+j;                                               ||
==============================================================

class Solution {
public:
    bool isValid(vector<int>& cols, vector<int>& row_cols, vector<int>& row_plus_cols, int col_number, int row_number){
        if(cols.size() == 0) return true;
        return (find(cols.begin(), cols.end(), col_number)==cols.end()) && (find(row_cols.begin(), row_cols.end(), row_number-col_number)==row_cols.end()) && (find(row_plus_cols.begin(), row_plus_cols.end(),row_number+col_number)==row_plus_cols.end());
    }

    void string_form(string& currStr, int boardSize, int queenPos){
        currStr = "";
        for(int i=0;i<boardSize; i++){
            if(i == queenPos) currStr.push_back('Q');
            else currStr.push_back('.');
        }
    }
    
    void placeQueens(int boardSize, int currRow, string& currStr, vector<string>& answer, vector<vector<string>>& finalConfig, vector<int>& cols, vector<int>& row_cols, vector<int>& row_plus_cols){
        if(boardSize == cols.size()){
            // In this case, we have N-Queens placed in the board. So push the config
            finalConfig.push_back(answer);
            return;
        }

        for(int i=0; i<boardSize; i++){
            // row number is passed in currRow. this i is for columns only.
            // We place queens row by row since n no of queens in n number of rows, each row must have a queen.
            if(isValid(cols, row_cols, row_plus_cols, i, currRow)){
                // If valid, then we place queen here.
                // Forming the string to be pushed.
                string_form(currStr, boardSize, i);
                //Pushing the string to answer
                answer.push_back(currStr);
                // Fill the remaining arrays 
                cols.push_back(i);
                row_cols.push_back(currRow - i);
                row_plus_cols.push_back(currRow + i);

                placeQueens(boardSize, currRow+1, currStr, answer, finalConfig, cols, row_cols, row_plus_cols);

                // Now roll back changes
                answer.pop_back();
                cols.pop_back();
                row_cols.pop_back();
                row_plus_cols.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> cols;
        vector<int> row_cols;
        vector<int> row_plus_cols;

        vector<string> answer;
        vector<vector<string>> finalConfig;
        string currStr="";

        placeQueens(n, 0, currStr, answer, finalConfig, cols, row_cols, row_plus_cols);
        return finalConfig;
        // arrays to keep track of cols and row-cols and row+cols
        // Here we will call for only top row once.
    }
};