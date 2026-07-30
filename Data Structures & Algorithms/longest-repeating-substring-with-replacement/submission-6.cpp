class Solution {
public:

    int characterReplacement(string s, int k) {
        string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int res = 0;
        // if(k == 0){
        //     for(char c: alphabet){
        //         int i = 0, j = 0;
        //         while(j < s.size()){
        //             while(i < s.size() && s[i] != c)i++;
        //             j = i;
        //             while(j < s.size() && s[j] == c)j++;
        //             res = max(res, j-i);
        //             i = j;
        //         }
        //     }
        //     return res;
        // }
        
        for(char c: alphabet){
            int replacements = k;
            int l = 0;
            for(int r = 0; r < s.size(); r++){
                if(s[r] == c) {}
                else if (replacements > 0) replacements--;
                else{
                    while(s[l] == c) l++;
                    l++;
                }
                res = max(res, r-l+1);
            }
        }
        return res;


        
    }
};
