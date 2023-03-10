/**
Problem Link: https://www.codingninjas.com/codestudio/problems/longest-common-prefix_2090383
Date: 2023-03-09 10:12:24
Level: Medium
Notes:
    - 
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

//brute force
string longestCommonPrefix(vector<string> &arr, int n) {
    string ans;
    bool match=true;
    //for each character of the first string of the array
    for(int i=0; i<arr[0].length(); i++) {
        char ch = arr[0][i];
        //for the remaining strings in the array
        for(int j=1; j<arr.size(); j++) {
            if(arr[j].size() < i || ch != arr[j][i]) {
                match = false;
                break;
            }
        }
        if(!match) {
            break;
        } else {
            ans.push_back(ch);
        }
    }
    return ans;
}




//optimised solution using trie
class TrieNode {
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char d) {
        data = d;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
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

        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index] != NULL) { //char present in the trie
            child = root->children[index];
        } else { //char absent
            root->childCount += 1;
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        //recursive case
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word) {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans) {
        for(int i=0; i<str.length(); i++) {
            char ch = str[i];
            if(root->childCount == 1) {
                ans.push_back(ch);
                int index = ch-'a';
                root = root->children[index];
            } else {
                break;
            }

            if(root->isTerminal) {
                break;
            }
        }
    }
};
string longestCommonPrefixUsingTrie(vector<string> &arr, int n) {
    Trie* t = new Trie();
    for(int i=0; i<n; i++) {
        t->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t->lcp(first, ans);
    return ans;     

}



int main() {
    
    return 0;
}