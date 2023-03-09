// C++ program to find freq of every word using
// unordered_map
#include<sstream>
#include<iostream>
#include<unordered_map>
using namespace std;
  
// Prints frequencies of individual words in str
int printFrequencies(const string &str)
{
    // declaring map of <string, int> type, each word
    // is mapped to its frequency
    unordered_map<string, int> wordFreq;
  
    // breaking input into word using string stream
    stringstream ss(str);  // Used for breaking words
    string word; // To store individual words
    auto count=0;
    while (ss >> word) {
        count++;
        wordFreq[word]++;
    }
  
    // now iterating over word, freq pair and printing
    // them in <, > format
    unordered_map<string, int>:: iterator p;
    for (p = wordFreq.begin(); p != wordFreq.end(); p++)
        cout << "(" << p->first << ", " << p->second << ")\n";
    return count;
}
  
// Driver code
int main()
{
    string str = "geeks for geeks geeks quiz "
                 "practice qa for";
    // auto x = printFrequencies(str);
    stringstream ss(str);  // Used for breaking words
    string word; // To store individual words
    auto count=0;
    while (ss >> word) 
        count++;
    cout << "\n\nWord Count= " << count << endl;
    return 0;
}