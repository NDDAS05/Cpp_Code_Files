
// Bellow is the first iteration of the problem.
// Optimization comes after that.


class Solution {
private:
    
public:
    bool findStr(int row, int col, int currPos, string& word, vector<vector<char>>& board, vector<vector<int>>& visited){
        // This is more important condition than the following out of bounds one. If the last char of the word is at the edge of the grid, row/col may go out of bounds.
        // But that does not mean we have not found answer.
        if(currPos == word.length()) return true;
        // Now we are sure no answer is found, first check if the indices are valid or not
        else if(row<0 || row+1>board.size() || col<0 || col+1 > board[0].size()){
            return false;
        }
        else if(visited[row][col]!=1 && board[row][col]==word[currPos]){
            // Found. Now just set up 4 recursive calls
            visited[row][col] = 1;
            bool res;

            // Make 4 recursive calls.
            // The following structure to make sure that if in any path answer is found we do not recurse further.
            res= findStr(row, col+1, currPos+1, word, board, visited);
            if(!res) res= findStr(row, col-1, currPos+1, word, board, visited);
            if(!res) res= findStr(row-1, col, currPos+1, word, board, visited);
            if(!res) res= findStr(row+1, col, currPos+1, word, board, visited);

            // While backtracking from the explored route, set visited to 0
            visited[row][col] = 0;
            return res;
        }
        else return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        // Logic: The logic is to grow the tree recursively by checking character of the grid if they matches with what we want or not.
        // We start off by looping over the given grid [NOTE: There can be duplicates in the grid. So 1st character matching at any position in the grid- and not finding the given word from there does NOT mean the string does not exist at all in the given grid]
        
        // We use res: to store boolean return value of the recursive calls
        //        visited: 2D vector marks the cell visited already.

        // So when we find the first character, we mark that cell as visited.
        // Then we set up 4 recursive calls for 4 adjacent cells.
        // The recursive calls take the cell (i,j) they will be looking at, currPos: the character in the string they will be looking at, and relevant strings grid and visited array.

        // In the recursive calls:
        // 
        // We want to exit out as soon as we find a non matching character.
        // i.e. we set up recursive conditions for the adjacent cells only when we find a matching.
        // So if we travarsed up the entire string and currPos >= word.length that means we travarsed entire string by finding matches and now we have ended the string itself. Then we return true.

        // Else If otherwise we see out of bounds row/col and the fact that currPos is < word.length signalling we have not checked the entire string yet, we return false.

        // Else if now we know at least row/ol indices are valid, if character matches and that cell is not visited already, we visit it.
        // Similarly mark as visited, set up recursive call for adjacent cells, unmark the cells before returning.

        // Else, if this also does not match then, we are sure the string does not exist in this path. So we return false.
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));

        int row_size = board.size();
        int col_size = board[0].size();
        bool res=false;

        for(int i=0; i<row_size; i++){
            for(int j=0; j<col_size; j++){
                if(board[i][j] == word[0]){
                    // Set visited[i][j] to 1
                    visited[i][j] = 1;
                    // Set up 4 recursive calls
                    res= findStr(i, j+1, 1, word, board, visited)+findStr(i, j-1, 1, word, board, visited)+findStr(i-1, j, 1, word, board, visited)+findStr(i+1, j, 1, word, board, visited);

                    // if found, return true
                    if(res) return true;
                    // If not, set visited[i][j] as false and continue the loop like normal.
                    visited[i][j] = 0;
                }
            }
        }

        return res;
    }
};