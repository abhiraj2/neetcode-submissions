class Solution {
public:
// I do not want to use count with sets here
// Why, because I like hashmaps 
// That being said, amorized complexity of this ans is also O(n) hehe.
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, pair<int,int>> mp;
        // unordered_set<int> s;
        if(nums.size() == 0) return 0;
        for(auto x:nums){
            mp[x] = {1, -1};
        }

        for(auto x:nums){
            if(mp[x+1].first != 0) mp[x].second = 1;
            else mp[x].second = 0;
        }

        int res = 1;
        int t;
        for(auto x:nums){
            if(!mp[x].second || mp[x].second > 1) continue;
            t = x+1;
            cout << "visiting x: " << x << endl;
            while(mp[t].second != 0){
                if(mp[t].second > 1){
                    mp[x].second += mp[t].second;
                    mp[x].second--;
                    break;
                }
                mp[x].second++;
                mp[t].second = 0;
                t++;
            }
            mp[x].second++;
            res = max(res, mp[x].second);
        }
        return res;
    }
};
