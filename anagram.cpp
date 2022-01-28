/*
 * Name: Charlie Hartsell
 * Date Submitted: March 14, 2021 (I was granted an extension)
 * Assignment Name: Single-Word Anagram Finder
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

/**
 * Using the algorithm library because I just had
 * a severe injury and honestly don't have the energy
 * to write my own sorting function lol
 */
#include <algorithm>

using namespace std;

vector<string> loadWordlist(string filename);

/*Implement the following function:
  anagram() takes a word (string) and a wordlist of all words (vector of strings)
  and builds a dictionary/map where the key is a specific number of times each
  letter occurs in a word and the associated value is a vector of strings
  containing all words using those letters (anagrams).
  The value returned is a vector of strings containing the corresponding
  set of anagrams
*/
vector<string> anagram(string word, vector<string> wordlist);

// Helper function to ease readability
string createKey(string word);

int main()
{
    vector<string> words;
    vector<string> anagrams;
    string inputWord;
    words=loadWordlist("wordlist.txt");
    cout << "Find single-word anagrams for the following word: ";
    cin >> inputWord;
    anagrams = anagram(inputWord, words);
    for (int i=0; i<anagrams.size(); i++)
    {
        cout << anagrams[i] << endl;
    }
    return 0;
}

vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if(inFile.is_open())
    {
        while(getline(inFile,word))
        {
            if(word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}

/**
* Key generation explanation:
* Each word is sorted alphabetically, which is then used
* as a string type key. Using this algorithm, all anagrams
* will be sorted and will end up as the same string, falling in the
* same "bucket" in the dictionary. That way, when a word is searched, 
* it is easy to return an anagram of that word.
*/
// I made this a helper function to ease readability
string createKey(string word) {
    sort(word.begin(), word.end());
    return word;
}

/*Implement the following function:
  anagram() takes a word (string) and a wordlist of all words (vector of strings)
  and builds a dictionary/map where the key is a specific number of times each
  letter occurs in a word and the associated value is a vector of strings
  containing all words using those letters (anagrams).
  The value returned is a vector of strings containing the corresponding
  set of anagrams
*/
vector<string> anagram(string word, vector<string> wordlist) {
    // Table to hold the anagrams
    unordered_map<string, vector<string>> dict;

    // Result vector
    vector<string> anagrams;

    // Key variable
    string oKey = createKey(word);


    for(int index = 0; index < wordlist.size(); index++) {
        string current = wordlist[index];
        string key = createKey(current);

        dict[key].push_back(current);
    }

    // Find and return all values in the dictionary
    // that are present at the key location
    anagrams = dict[oKey];
    return anagrams;
}
