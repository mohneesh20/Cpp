#include"TrieNode.h"
#include<string>
using namespace std;
class Trie{
    TrieNode *root;
    public:
    Trie(){
        root=new TrieNode('\0');
    }
    void insertWord(TrieNode *root,string word){
        if(word.size()==0){
            root->isTerminal=true;
            return;
        }
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        insertWord(child,word.substr(1));
        // insertWord(word.substr(1,word.size()-1));
    }
    void insertWord(string word){
        insertWord(root,word);
    }
    bool searchWord(TrieNode* root,string word){
        if(word.size()==0){
            return root->isTerminal==true;
        }
        int index=word[0]-'a';
        if(root->children[index]==NULL){
            return false;
        }
        if(root->children[index]->data==word[0]){
            bool result=searchWord(root->children[index],word.substr(1));
            if(!result){
                return result;
            }
        }
        else{
            return false;
        }
        return true;
    }
    bool searchWord(string word){
        return searchWord(root,word);
    }
    void removeWord(TrieNode *root,string word){
        if(word.size()==0){
            root->isTerminal=false;
            return;
        }
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return; 
        }
        removeWord(child,word.substr(1));
        if(child->isTerminal==false){
            for(int i=0;i<26;i++){
                if(child->children[i]!=NULL){
                    return;
                }
            }
            delete child;
            root->children[index]=NULL;
        }
    }
    void removeWord(string word){
        removeWord(root,word);
    };
};