class Solution {
public:
    int x=0;
    map<pair<string,string>,bool> ans;
    bool areSentencesSimilar(string &sentence1, string &sentence2) {
        deque<string> words1;
        deque<string> words2;
        string w1; stringstream ww1(sentence1);
        while(ww1>>w1){
            words1.push_back(w1);
        }
        string w2; stringstream ww2(sentence2);
        while(ww2>>w2){
            words2.push_back(w2);
        }
        while(words1.size() != 0 && words2.size() != 0 && (words1.front() == words2.front())){ 
            words1.pop_front(); 
            words2.pop_front(); 
        }
        
		while(words1.size() != 0 && words2.size() != 0 && (words1.back() == words2.back())){ 
            words1.pop_back(); 
            words2.pop_back(); 
        }
		if(words1.size() == 0 or words2.size() == 0){ return true; }
        return false;
    }
};