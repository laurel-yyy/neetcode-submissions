struct PrefixNode {
    bool isEnd;
    vector<PrefixNode*> next;
    PrefixNode(){isEnd = false; next.resize(26);}
};

class PrefixTree {
public:
    PrefixNode* root;
    PrefixTree() {
         root = new PrefixNode();
    }
    
    void insert(string word) {
        PrefixNode* p = root;
        for(int i=0; i<word.size(); ++i){
            if(!p->next[word[i]-'a']) {
                p->next[word[i]-'a'] = new PrefixNode();
            }
            p = p->next[word[i]-'a'];
        }
        p->isEnd = true;
    }
    
    bool search(string word) {
        PrefixNode* p = root;
        for(int i=0; i<word.size(); ++i){
            if(!p->next[word[i]-'a'])return false;
            p = p->next[word[i]-'a'];
        }
        return p->isEnd;
    }
    
    bool startsWith(string prefix) {
        PrefixNode* p = root;
        for(int i=0; i<prefix.size(); ++i){
            if(!p->next[prefix[i]-'a'])return false;
            p = p->next[prefix[i]-'a'];
        }
        return true;
    }
};
