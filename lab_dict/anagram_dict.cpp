/**
 * @file anagram_dict.cpp
 * Implementation of the AnagramDict class.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "anagram_dict.h"

#include <algorithm>
#include <fstream>

using std::string;
using std::vector;
using std::ifstream;

/**
 * Constructs an AnagramDict from a filename with newline-separated
 * words.
 * @param filename The name of the word list file.
 */
AnagramDict::AnagramDict(const string& filename)
{
    ifstream wordsFile(filename);
    string word;
    if (wordsFile.is_open()) {
      while (getline(wordsFile, word)) {
        string temp = word;
        sort(temp.begin(), temp.end());
        dict[temp].push_back(word);
      }
    }
}

/**
 * Constructs an AnagramDict from a vector of words.
 * @param words The vector of strings to be used as source words.
 */
AnagramDict::AnagramDict(const vector<string>& words)
{
    for (unsigned i = 0; i < words.size(); i++) {

        string t = words[i];
        std::sort(t.begin(), t.end());
        dict[t].push_back(words[i]);
        
    } 
}

/**
 * @param word The word to find anagrams of.
 * @return A vector of strings of anagrams of the given word. Empty
 * vector returned if no anagrams are found or the word is not in the
 * word list.
 */
vector<string> AnagramDict::get_anagrams(const string& word) const
{
    string t = word;
    std::sort(t.begin(), t.end());

    if (dict.find(t) == dict.end() || dict.at(t).size() == 1) {
        return vector<string>();
    } else {
        return dict.at(t);
    }
}

/**
 * @return A vector of vectors of strings. Each inner vector contains
 * the "anagram siblings", i.e. words that are anagrams of one another.
 * NOTE: It is impossible to have one of these vectors have less than
 * two elements, i.e. words with no anagrams are ommitted.
 */
vector<vector<string>> AnagramDict::get_all_anagrams() const
{
    vector<vector<string>> anagram_vect;
    for (std::pair<string, vector<string>> word : dict) {
      if (word.second.size() > 1) {
          anagram_vect.push_back(word.second);
      }
    }
    return anagram_vect;
}
