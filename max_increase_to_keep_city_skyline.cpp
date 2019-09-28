class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        for(int i=0; i<height; i++)
            t.push_back(vector<int>{grid[0][i]});
        for(int i=1; i<height; i++)
            for (int j=0; j<width; j++)
                t[j].push_back(grid[i][j]);
        
        for(int i=0; i<height; i++){
            temp = grid[i];
            sort(temp.begin(),temp.end());
            horizontal.push_back(temp[width-1]);
        }
        for(int i=0; i<width; i++){
            temp = t[i];
            sort(temp.begin(),temp.end());
            vertical.push_back(temp[width-1]);
        }
        
        int res = 0;
        for(int i=0; i<height; i++)
            for (int j=0; j<width; j++){
                int x = horizontal[i]-grid[i][j];
                int y = vertical[j]-grid[i][j];
                res+= x<y?x:y; 
            }
        

        return res;
        
    }
private:
    vector<int> temp;
    vector<vector<int>> t;
    vector<int> horizontal;
    vector<int> vertical;
};
