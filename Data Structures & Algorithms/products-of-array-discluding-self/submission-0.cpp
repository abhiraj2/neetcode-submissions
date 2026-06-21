class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n, 1);
        vector<int> suff(n, 1);
        pre[0] = nums[0];
        suff[n-1] = nums[n-1];
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1] * nums[i];
        }

        for(int i=n-2; i>-1; i--){
            suff[i] = suff[i+1] * nums[i];
        }
        vector<int> res;
        res.push_back(suff[1]);
        for(int i=1; i<n-1; i++){
            res.push_back(pre[i-1] * suff[i+1]);
        }
        res.push_back(pre[n-2]);
        return res;
    }
};
