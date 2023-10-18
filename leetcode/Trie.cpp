//
// Created by Jev on 2023/6/6.
//
#include "string"
#include "vector"
#include "stack"
#include "queue"
#include "iostream"
#include "unordered_map"

using namespace std;
class Trie {
private:
    vector<Trie*> children;
    bool isEnd;
    Trie* searchPrefix(string word){
        Trie *node = this;
        for(char s : word){
            int ch = s - 'a';
            if(node->children[ch] == nullptr) return nullptr;
            node = node->children[ch];
        }
        return node;
    }
public:
    /** Initialize your data structure here. */
    Trie() : children(26), isEnd(false) {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node = this;
        for(char s : word){
            int ch = s - 'a';
            if(node->children[ch] == nullptr){
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return (searchPrefix(word) != nullptr && searchPrefix(word)->isEnd) ? true : false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return searchPrefix(prefix) != nullptr ? true : false;
    }
};