#include "const.hpp"

huffman* build(string text){
    unordered_map<char,int> freq;
    for (char s : text) {
        if(s != ' ' && s != '\n')
            freq[s]++;
    }
    priority_queue<huffman*, vector<huffman*>, compare> pq;
    for(auto [k,v] : freq){
        huffman* node = new huffman(k,v);
        pq.push(node);
    }
    while(pq.size() > 1){
        auto rt = pq.top();
        pq.pop();
        auto lft = pq.top();
        pq.pop();
        huffman* node = new huffman();
        node->freq = rt->freq + lft->freq;
        node->right = rt;
        node->left = lft;
        pq.push(node);
    }
    return pq.top();
}
