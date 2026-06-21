class Solution {
public:
    int n = 9;

    pair<pair<int, int>, pair<int, int>>get_grid(int i, int j){
        if(i<3 && j < 3) return {{0,0}, {3,3}};
        else if( i<3 && j<6) return {{0,3}, {3,6}};
        else if (i<3 && j<9) return {{0,6}, {3,9}};
        else if( i<6 && j<3) return {{3,0}, {6,3}};
        else if (i<9 && j<3) return {{6,0}, {9,3}};
        else if( i<6 && j<6) return {{3,3}, {6,6}};
        else if (i<6 && j<9) return {{3,6}, {6,9}};
        else if (i<9 && j<6) return {{6,3}, {9,6}};
        else return {{6,6}, {9,9}};
        
    }

    bool visit(int i, int j, vector<vector<char>>& board){
        set<char> s;
        s.insert(board[i][j]);
        for(int idx=i+1; idx<n; idx++){
            if(board[idx][j] == '.'|| (idx == i)) continue;
            if(s.find(board[idx][j]) != s.end()){
                cout << "col visiting " << idx << " " << j << " returned false" << endl;
                return false;
            }
            s.insert(board[idx][j]);
        }
        s.clear();
        s.insert(board[i][j]);
        for(int idx=j+1; idx<n; idx++){
            if(board[i][idx] == '.'|| (idx == j)) continue;
            if(s.find(board[i][idx]) != s.end()){
                cout << "row visiting " << i << " " << idx << " returned false" << endl;
                return false;
            }
            s.insert(board[i][idx]);
        }
        s.clear();
        s.insert(board[i][j]);
        pair<pair<int, int>, pair<int,int>> grid_idx = get_grid(i, j);
        for(int i_r = grid_idx.first.first; i_r < grid_idx.second.first; i_r++){
            for(int i_c = grid_idx.first.second; i_c < grid_idx.second.second; i_c++){
                if(board[i_r][i_c] == '.' || (i_r == i && i_c ==j)) continue;
                if(s.find(board[i_r][i_c]) != s.end()){
                    cout << "grid visiting " << i_r << " " << i_c << " returned false" << endl;
                    return false;
                }
                s.insert(board[i_r][i_c]);
            }   
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == '.') continue;
                if(!visit(i, j, board)){
                    cout << "visiting " << i << " " << j << " returned false" << endl;
                    return false;
                }
            }
        }

        return true;
    }
};
