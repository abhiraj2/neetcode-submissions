class Solution {
public:
    vector<pair<int, int>> index;

    string encode(vector<string>& strs) {
        int n = strs.size();
        string res = "";
        for(int i=0; i<n; i++){
            index.push_back({i, strs[i].size()});
            res = res + strs[i];
        }
        // cout << res;
        return res;
    }

    vector<string> decode(string s) {
        int n = s.size();
        int m = index.size();
        vector<string> res;
        string temp = "";
        int start = 0;
        int next_size;
        for(int i=0; i<m; i++){
            temp = "";
            next_size = index[i].second;
            int end = start + next_size;
            int j = start;
            while(j < end){
                // cout << j << " " << start << " " << end << endl;
                temp += s[j];
                j++;
            }
            res.push_back(temp);
            start = start + temp.size();
        }
        return res;
    }
};
