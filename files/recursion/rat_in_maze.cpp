class Solution {
  public:
    // The question asks lexicographical ordering.
    // Thus we go in alphabetical order of direction D-L-R-U
    vector<vector<int>> dir ={{1,0},{0,-1},{0,1},{-1,0}};
    void navMaze(int row, int col, string& path, vector<vector<int>>& maze, vector<string>& validPath){
        // Since we are pushing direction of the next recursion in previous level, can not add (if last cell is marked) check here because that will also include the direction in which it went to the invalid path.
        
        //Return if out of bounds or marked with 9 already.
        if(row<0 || row>=maze.size() || col<0 || col>=maze[0].size() || maze[row][col] == 9 || maze[row][col] == 0){
            return;
        }
        //That means a valid place. Just mark it,, recurse, remove mark
        else{
            if(row == maze.size()-1 && col==maze[0].size()-1){
                validPath.push_back(path);
                return;
            }
            int temp = maze[row][col];
            //marking cell "visited"
            maze[row][col] = 9;
            for(auto& d: dir){
                int row_next = row + d[0];
                int col_next = col + d[1];
                // Pushing alphabets conditionally
                if(d[0] == 0 && d[1]==1) path.push_back('R');
                else if(d[0] == 1 && d[1]==0) path.push_back('D');
                else if(d[0]== 0 && d[1]==-1) path.push_back('L');
                else path.push_back('U');
                
                navMaze(row_next, col_next, path, maze, validPath);
                // BackTrack to previous
                path.pop_back();
            }
            // Unmark the cell
            maze[row][col] = temp;
        }
        
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        string path="";
        vector<string> validPath;
        
        navMaze(0, 0, path, maze, validPath);
        return validPath;
    }
};