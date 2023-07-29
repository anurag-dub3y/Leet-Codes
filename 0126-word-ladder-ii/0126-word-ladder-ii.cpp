class Solution {
    unordered_map<string, int> mp;
    vector<vector<string>> ans;
    string b;
    void dfs(string word, vector<string> &seq){
        if(word == b){
            vector<string> tmp(seq.rbegin(),seq.rend());
            ans.push_back(tmp);
            return;
        }
        int steps = mp[word];
        for(int i=0; i<word.size(); i++){
            char original = word[i];
            for(char c = 'a'; c <= 'z'; c++){
                word[i] = c;
                if(mp.find(word) != mp.end() && mp[word] == steps - 1){
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<string> q;
        b = beginWord;
        q.push({beginWord});
        mp[beginWord] = 1;

        int sizee= beginWord.size();
        st.erase(beginWord);
        
        while(!q.empty()){
            string word = q.front();
            int steps = mp[word];
            q.pop();

            if(word == endWord) break;

            for(int i=0; i<sizee; i++){
                char original = word[i];
                for(char c = 'a'; c <= 'z'; c++){
                    word[i] = c;
                    if(st.count(word)){
                        
                        q.push(word);
                        st.erase(word);

                        mp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }

        if(mp.find(endWord) != mp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }

        
        return ans;
    }
};

// class Solution {
// public:
// //     vector<vector<string>> findLadders(string bW, string eW, vector<string>& wordList) {
// //     auto cntDiff = [&](string& s1) {
// //         int cnt = 0;
// //         for (int i = 0; i < s1.length(); i++) {
// //             if (s1[i] != eW[i]) {
// //                 cnt++;
// //             }
// //         }
// //         return cnt;
// //     };

// //     queue<vector<string>> pq;
// //     unordered_set<string> words(wordList.begin(), wordList.end());

// //     pq.push({bW});
// //     int mnLength = 1e6;
// //     vector<vector<string>> ans;

// //     while (!pq.empty()) {
// //         int sz = pq.size();
// //         while (sz--) {
// //             vector<string> curr = pq.front();
// //             pq.pop();
// //             if (curr.back() == eW) {
// //                 if (curr.size() == mnLength) {
// //                     ans.push_back(curr);
// //                 }
// //                 else if (curr.size() < mnLength) {
// //                     mnLength = curr.size();
// //                     ans={curr};
// //                 }
// //                 continue;
// //             }

// //             for (int i = 0; i < curr.back().length(); i++) {
// //                 string tmp = curr.back();
// //                 for (char c = 'a'; c <= 'z'; c++) {
// //                     tmp[i] = c;
// //                     if (words.count(tmp) != 0 && count(begin(curr),end(curr),tmp) == 0) {
// //                         vector<string> tmpV = curr;
// //                         tmpV.push_back(tmp);
// //                         pq.push(tmpV);
// //                     }
// //                 }
// //             }
// //         }
// //     }

// //     return ans;
// // }
// vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//     set<vector<string>> result;
//     unordered_set<string> wordSet(wordList.begin(), wordList.end());
//     if (wordSet.find(endWord) == wordSet.end()) return result;

//     unordered_map<string, vector<string>> parentMap; // To store parent words for each word
//     queue<string> q;
//     q.push(beginWord);

//     unordered_set<string> visited; // To mark visited words
//     visited.insert(beginWord);
//     bool foundEnd = false;

//     while (!q.empty()) {
//         int levelSize = q.size();
//         unordered_set<string> currentLevelVisited;

//         for (int i = 0; i < levelSize; i++) {
//             string currentWord = q.front();
//             q.pop();

//             for (int j = 0; j < currentWord.length(); j++) {
//                 string newWord = currentWord;

//                 for (char ch = 'a'; ch <= 'z'; ch++) {
//                     newWord[j] = ch;

//                     if (wordSet.find(newWord) != wordSet.end()) {
//                         if (newWord == endWord)
//                             foundEnd = true;

//                         if (visited.find(newWord) == visited.end()) {
//                             q.push(newWord);
//                             currentLevelVisited.insert(newWord);
//                             parentMap[newWord].push_back(currentWord);
//                         }
//                     }
//                 }
//             }
//         }

//         visited.insert(currentLevelVisited.begin(), currentLevelVisited.end());

//         if (foundEnd)
//             break;
//     }

//     if (foundEnd) {
//         vector<string> path = {endWord};
//         buildPath(endWord, beginWord, parentMap, path, result);
//     }
//     vector<vector<string>> ans(begin(result),end(result));
//     return ans;
// }

// void buildPath(string& word, string& beginWord, unordered_map<string, vector<string>>& parentMap, vector<string>& path, set<vector<string>>& result) {
//     if (word == beginWord) {
//         reverse(path.begin(), path.end());
//         result.insert(path);
//         // reverse(path.begin(), path.end());
//         return;
//     }

//     for (string parent : parentMap[word]) {
//         path.push_back(parent);
//         buildPath(parent, beginWord, parentMap, path, result);
//         path.pop_back();
//     }
// }
// };

