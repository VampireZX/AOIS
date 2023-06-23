//#include "Header.h"
#include <string>
#include <iostream>
#define ll long long
using namespace std;

int h1(string s, int arrSize)
{
    ll int hash = 0;
    for (int i = 0; i < s.size(); i++)
    {
        hash = (hash + ((int)s[i]));
        hash = hash % arrSize;
    }
    return hash;
}

// lookup operation
bool lookup(bool* bitarray, int arrSize, string s)
{
    int a = h1(s, arrSize);

    if (bitarray[a])
        return true;
    else
        return false;
}

// insert operation
void insert(bool* bitarray, int arrSize, string s)
{
    // check if the element in already present or not
    if (lookup(bitarray, arrSize, s))
        cout << s << " is Probably already present" << endl;
    else
    {
        int a = h1(s, arrSize);
        bitarray[a] = true;
        cout << s << " inserted" << endl;
    }
}

// Main func
int main()
{
    bool bitarray[100] = { false };
    int arrSize = 100;
    string sarray[33]
        = { "abound",   "abounds",       "abundance",
            "abundant", "accessible",    "bloom",
            "blossom",  "bolster",       "bonny",
            "bonus",    "bonuses",       "coherent",
            "cohesive", "colorful",      "comely",
            "comfort",  "gems",          "generosity",
            "generous", "generously",    "genial",
            "bluff",    "cheater",       "hate",
            "war",      "humanity",      "racism",
            "hurt",     "nuke",          "gloomy",
            "facebook", "geeksforgeeks", "twitter" };
    for (int i = 0; i < 33; i++) {
        insert(bitarray, arrSize, sarray[i]);
    }
    return 0;
}