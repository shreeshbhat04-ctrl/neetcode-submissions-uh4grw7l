class WordDictionary {
public:
vector<string>stor;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        stor.push_back(word);
    }
    
    bool search(string word) {
        for(string w:stor){
            if(w.size()!=word.size())continue;
            int i=0;
            while(i<w.size()){
                if(w[i]==word[i]||word[i]=='.'){
                    i++;
                }else{
                    break;
                }
            }
            if(i==word.size()){return true;}
        }
        return false;
    }
};
