class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // simple BFS
        // Flood fill:
        // If starting img[sr][sc] color(0) is already same as new color(0), flood fill can only change the color of color=newColor(0). But it does not change the image and also the cells that are to be colored are already colored.
        // Say newColor = 0, sr,sc= 0,0
        //[[0 0 1]
        // [0 1 0]] output will be same as floodfill can not change diff-than-og (also 0 color) cell so just return.
        int originalColor = image[sr][sc];
        if(color == originalColor) return image;
        image[sr][sc] = color;
        
        int colMax = image[0].size();
        int rowMax = image.size();
        vector<pair<int, int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

        queue<pair<int, int>> q;

        // change starting pixel colour

        q.push({sr, sc});

        while(!q.empty()){
            int currSize = q.size(); // not necessary as we only need to cover all cells not in min time or smth unlike rotten oranges.
            for(int i=0; i<currSize; i++){ // so not needed. Can omit inner for. We do not need strictly "level wise traversal"
                pair currCell = q.front();
                q.pop();

                for(auto& d: dir){
                    int newRow = currCell.first + d.first;
                    int newCol = currCell.second +d.second;

                    if((newRow>=0 && newRow < rowMax) && (newCol >= 0 && newCol <colMax) && (image[newRow][newCol] == originalColor)){
                        image[newRow][newCol] = color;
                        q.push({newRow, newCol});
                    }
                }
            }
        }

        return image;
    }
};