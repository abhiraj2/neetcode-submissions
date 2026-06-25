class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l=0; 
        int r=n-1;
        int res=-1;
        int t_a;
        while(l<r){
            t_a = min(heights[l],heights[r]) * (r-l);
            res = max(res, t_a);
            if(min(heights[l],heights[r]) == heights[l]) l++;
            else r--;
        }

        return res;
    }
};
