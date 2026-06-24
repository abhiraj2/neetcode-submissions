class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        int l, r, target;
        sort(nums.begin(), nums.end());
        int t_s;
        set<vector<int>> resS;
        for(int i=0; i<n; i++){
            l=i+1;
            r=n-1;
            target = -nums[i];
            while(l<r){
                t_s = nums[l] + nums[r];
                if(t_s == target){
                    resS.insert({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
                else if(t_s < target) l++;
                else r--; 
            }
        }
        vector<vector<int>> res(resS.begin(), resS.end());
        return res;
    }
};
