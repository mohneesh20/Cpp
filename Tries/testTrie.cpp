#include<iostream>
#include"Trie.h"
#include<string>
using namespace std;
int main(){
    Trie t;
    t.insertWord("Mohneesh");
    t.insertWord("Bansal");
    t.insertWord("Monu");
    cout<<t.searchWord("Monu")<<endl;
    t.removeWord("Monu");
    cout<<t.searchWord("Mohneesh");
}