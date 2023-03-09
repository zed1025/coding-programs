#include<iostream>
#include<unordered_map>
#include<sstream>
using namespace std;
template<typename T, typename U>
void showUM(unordered_map<T, U> um) {
	for(auto it=um.begin(); it!=um.end(); ++it) {
		cout << it->first << ": " << it->second << endl;
		// for for-each style loop, replace -> with .
	}cout << endl;
}
int main() {
	unordered_map<int, string> um;
	um[0] = "Amit";
	um[1] = "Priya";
	um[3] = "Manju";
	um[4] = "John";
	um.insert(make_pair(5, "Sasuke"));
	um.emplace(6, "Naruto");
	um.insert({{7, "Sakura"}, {8, "Neji"}});
	showUM(um);
	um.erase(4);
	showUM(um);
	if(um.find(4) != um.end()) cout << "Found: " << um.find(4)->second << endl << endl;
	// find word frequency, program
	string str = "geeks for geeks geeks quiz practice qa for";
	unordered_map<string, int> wordFreq;
	stringstream ss(str);  // Used for breaking words
    string word; // To store individual words
    while (ss >> word)
        wordFreq[word]++;
    showUM(wordFreq);
    cout << "Value at key=3 is: " << um.at(3);
    // hash_function(), try checking for um
    unordered_map<string, string> ss1;
    unordered_map<string, string>::hasher fn = ss1.hash_function();
    cout << "\nHashed value of 1: " << fn("amit");
    cout << "\nHashed value of 3: " << fn("manju");
    // other functions
    cout << "\nLoad factor: " << um.load_factor();
    cout << "\nBucket Count: " << um.bucket_count();
    cout << "\nBucket size for 1: " << um.bucket_size(1);
    cout << "\n3:Manju is in bucket: " << um.bucket(3);
    cout << "\nCount of key=3: " << um.count(3);
	return 0;
}