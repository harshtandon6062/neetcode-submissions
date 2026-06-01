class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(string str: strs){
            res.append(to_string(str.size()) + "#" + str);
        }
        return res;

    }

    vector<string> decode(string s) {
        int i = 0;
        int n = s.size();
        vector<string>res;
        while(i < n){
            int j = i;
            string str;
            while(j < n && s[j] != '#') j++;
            int str_len = stoi(s.substr(i, j-i));
            i = j+1;
            for (int k = 0; k < str_len; k++){
                str.push_back(s[i+k]);
            }
            i += str_len;
            res.push_back(str);
        }
        return res;
    }
};
