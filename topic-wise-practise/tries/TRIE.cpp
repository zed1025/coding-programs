/**
 * - https://youtu.be/Y6dOuGjwsxU
 * - Suppose we want to implement a dictionary
 *      - operations that need to be supported - 
 *          - addWord, TC:O(length of word)
 *          - searchWord, TC:O(length of word)
 *          - removeWord, TC:O(length of word)
 * - one way to implement it is using a HashMap, which gives O(1) time for all the above operations in average case
 * - in worst case the time complexity will differ. O(l), l is the length of word
 * - Better DS? -> trie
 * - Structure of trie node
 *      TrieNode{
 *          char data;
 *          TrieNode* childredn[26]; //each node can have upto 26 children corresponding to the letters of the alphabet
 *          bool isTerminal; //tells us whether a node is terminal node
 *      }
 * 
 * 
 * - Problem
 *      https://www.codingninjas.com/codestudio/problems/implement-trie_631356
*/


#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for(int i=0; i<26; i++)  {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }


    void insertUtil(TrieNode* root, string word) {
        //base case
        if(word.length() == 0) {
            root->isTerminal = true;
            return ;
        }

        //assumption: only capital letters
        int index = word[0] - 'A';
        TrieNode* child;
        if(root->children[index] != NULL) { //char present in the trie
            child = root->children[index];
        } else { //char absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        //recursive case
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word) {
        //base case
        if(word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word) {
        return searchUtil(root, word);
    }

    void deleteUtil(TrieNode* root, string word) {
        /**
         * TODO: find way to optimize space, remove the space taken by unabailable words
        */
        if(word.length() == 0) {
            root->isTerminal = false;
        }

        int index = word[0] - 'A';
        TrieNode* child;
        if(root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return ;
        }

        return deleteUtil(child, word.substr(1));
    }

    void deleteWord(string word) {
        return deleteUtil(root, word);
    }
};

int main() {
    Trie *t = new Trie();
    
    t->insertWord("ABCD");
    cout << "hello";
    t->insertWord("TIME");
    t->insertWord("AMIT");
    t->insertWord("PRIYA");
    t->insertWord("SNEHA");
    
    cout << "ABCD present in trie? -> " << t->searchWord("ABCD") << endl;
    cout << "AMIT present in trie? -> " << t->searchWord("AMIT") << endl;
    cout << "PRIYA present in trie? -> " << t->searchWord("PRIYA") << endl;
    cout << "SNEHA present in trie? -> " << t->searchWord("SNEHA") << endl;
    cout << "AMITK present in trie? -> " << t->searchWord("AMITK") << endl;

    cout << "\n\nDeleting node: \n";
    t->deleteWord("AMIT");
    t->deleteWord("SNEHA");
    cout << "AMIT present in trie? -> " << t->searchWord("AMIT") << endl;
    cout << "SNEHA present in trie? -> " << t->searchWord("SNEHA") << endl;
    cout << "PRIYA present in trie? -> " << t->searchWord("PRIYA") << endl; 

    return 0;
}