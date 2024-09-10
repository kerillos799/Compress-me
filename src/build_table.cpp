#include "const.hpp"



void build_table(huffman* node, unordered_map<char,string> & table, string cur){
    if (node){
        if (node->val != '\0'){
            table[node->val] = cur;
        }
        build_table(node->left, table, cur + '0');
        build_table(node->right, table, cur + '1');
    }
}