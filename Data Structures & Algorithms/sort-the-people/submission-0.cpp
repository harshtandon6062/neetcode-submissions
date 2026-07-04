class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<string, int> freq;
        for(auto& name: names){
            freq[name]++;
            name += to_string(freq[name]);
        }
        unordered_map<string, int> height;
        for(int i = 0; i < names.size(); i++){
            height[names[i]] = heights[i];
        }
        sort(names.begin(), names.end(), [height](const string&a , const string& b){
            return height.at(a) > height.at(b);
        });
        for(auto& name: names){
            while(isdigit(name.back())){
                name.pop_back();
            }
        }
        return names;
    }
};