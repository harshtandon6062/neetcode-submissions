class Solution {
public:
    bool isAnagram(string s, string t) {
        auto create_map = [](const string& str){
            unordered_map<char,int> freq;
            for (char ch : str) {
                freq[ch]++; 
            }
            return freq;
        };
        return create_map(s) == create_map(t);
    }
};
