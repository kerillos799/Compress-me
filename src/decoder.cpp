#include "const.hpp"





void decoder(string text){
    huffman* cur = build(text);
    unordered_map<char, string> table;
    build_table(cur, table, "");
    for (char s : text){
        cout<<table[s];
    }

}