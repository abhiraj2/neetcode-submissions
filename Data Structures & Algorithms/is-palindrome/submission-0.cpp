class Solution {
public:
    bool isPalindrome(string s) {
        int st = 0;
        string ws="";
        for(char c:s){
            if((c -'0' > 9 || c -'0' < 0) && 
            (c-'a' > 25 || c-'a' < 0) &&
            (c-'A' > 25 || c-'A' < 0)
            ){
                continue;
            }
            ws += tolower(c);
        }
        cout << ws;
        int end = ws.size()-1;
        while(st < end){
            if(ws[st] != ws[end]) return false;
            st++;
            end--;
        }
        return true;
    }
};
