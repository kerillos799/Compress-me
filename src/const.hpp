#include <bits/stdc++.h>
using namespace std;

struct huffman{
    int freq;
    char val;
    huffman* left = nullptr;
    huffman* right = nullptr;
    huffman(char c, int fr){
        val = c;
        freq = fr;
        right = nullptr;
        left = nullptr;
    }
    huffman(){
        val = '\0';
        freq = 0;
        right = nullptr;
        left = nullptr;
    }
};

struct compare{
    bool operator()(const huffman* lft , const huffman* rght) const{
        return lft->freq > rght->freq;
    }
};
void decoder(string text);
huffman* build(string text);
void build_table(huffman* node, unordered_map<char,string> & table, string cur);



