class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int, int> left_to_include;
        for(char c: t) left_to_include[c]++;
        int l = 0, r = 0;
        int total_left = t.size();
        while(r < s.size() && total_left > 0){
            if(left_to_include.count(s[r])){
                if(left_to_include[s[r]] > 0) total_left--;
                left_to_include[s[r]]--;
            }
            r++;
        }
        if(total_left > 0) return "";   //possible that r = s.size() after this point
               
        int min_size= r-l, min_l=l, min_r=r;
        
        while(true){
            if(left_to_include.count(s[l])) left_to_include[s[l]]++;
            while(r < s.size() && left_to_include.count(s[l]) && left_to_include[s[l]] > 0){   // FIX: was s.size()-1
                if (left_to_include.count(s[r])) left_to_include[s[r]]--;  // FIX: moved before r++
                r++;                                                       // FIX: moved after decrement
            }
            if(left_to_include.count(s[l]) && left_to_include[s[l]] > 0) break;//possible that r = s.size() after this point
            l++;
            if(r-l < min_size){                   // FIX: was r-l+1
                min_size= r-l;                     // FIX: was r-l+1
                min_l=l;
                min_r=r;
            }
        }
        return s.substr(min_l, min_size);
    }
};