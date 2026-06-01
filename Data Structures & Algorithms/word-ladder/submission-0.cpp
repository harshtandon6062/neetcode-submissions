class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.insert(wordList.begin(), beginWord);
        int n = wordList.size();
        int ws = beginWord.size();
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                int diff_count = 0;
                for(int k = 0; k < ws; k++){
                    if(wordList[i][k] != wordList[j][k]) diff_count++;
                }
                if(diff_count == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        queue<int> q;
        q.push(0);
        vector<bool> visited(n, false);
        visited[0] = true;
        int steps = 1; // beginWord counts as firt step
        int target = find(wordList.begin(), wordList.end(), endWord) - wordList.begin();
        while(!q.empty()){
            int q_size = q.size();
            while(q_size--){
                int word = q.front(); q.pop();
                if(word == target) return steps;
                for(int nei: adj[word]){
                    if(!visited[nei]){
                        visited[nei] = true;
                        q.push(nei);
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};