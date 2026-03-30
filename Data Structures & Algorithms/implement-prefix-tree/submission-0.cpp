class Trie{
    public:
    Trie* child[26];
    bool isword;
    Trie(){
        isword=false;
        for(auto &a:child)a=nullptr;
    }
};
class PrefixTree {
public:
  Trie* root;
    PrefixTree() {
        root=new Trie();
    }
    
    void insert(string word) {
        Trie* p=root;
        for(auto&a:word){
            int i=a-'a';
            if(!p->child[i])p->child[i]=new Trie();
            p=p->child[i];
        }p->isword=true;
    }
    
    bool search(string word,bool key=false) {
         Trie* p=root;
        for(auto& a:word){
            int i=a-'a';
            if(!p->child[i])return false;
            p=p->child[i];

        }
        if(key==false)return p->isword;
        return true;
    }
    
    bool startsWith(string prefix) {
        return search(prefix,true);
    }
};
