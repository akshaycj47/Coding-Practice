#include <string>

class TrieNode {
private:
    TrieNode** m_Links;
    int m_R;
    bool m_IsEnd;
    
public:
    TrieNode() {
        m_R = 26;
        m_Links = new TrieNode*[m_R];
        for(int i = 0; i < m_R; i++) {
            m_Links[i] = nullptr;
        }
        m_IsEnd = false;
    }
    
    void setEnd() {
        m_IsEnd = true;
    }
    
    bool isEnd() {
        return m_IsEnd;
    }
    
    bool checkKey(char c) {
        return m_Links[c - 'a'] != nullptr;
    }
    
    TrieNode* get(char c) {
        return m_Links[c - 'a'];
    }
    
    void put(char c, TrieNode* node) {
        m_Links[c - 'a'] = node;
    }
};

class Trie {
private: 
    TrieNode* root;
    
    TrieNode* searchPrefix(std::string word) {
        
        TrieNode* currNode = root;
        for(int i = 0; i < word.size(); i++) {
            char currChar = word[i];
            if(currNode->checkKey(currChar)) {
                currNode = currNode->get(currChar);
            }
            else {
                return nullptr;
            }
        }
        
        return currNode;
    }
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(std::string word) {
        
        TrieNode* currNode = root;
        for(int i = 0; i < word.size(); i++) {
            char currChar = word[i];
            if(!currNode->checkKey(currChar)) {
                currNode->put(currChar, new TrieNode());
            }
            currNode = currNode->get(currChar);
        }
        currNode->setEnd();
    }
    
    /** Returns if the word is in the trie. */
    bool search(std::string word) {
        
        TrieNode* node = searchPrefix(word);
        return node != nullptr && node->isEnd();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix) {
        
        TrieNode* node = searchPrefix(prefix);
        return node != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
