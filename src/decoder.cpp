#include "const.hpp"





void decoder(string in_file, string out_file){
    while (in_file.back() == ' ')
        in_file.pop_back();
    string extension = in_file.substr(in_file.size() - 4, 4 );
    if (extension != ".txt"){
        cout<<"Wrong format, I only accept \".txt\" files. :)";
        exit(1);
    }
    fstream input(in_file, ios::in);
    if (!input.is_open()){
        cout<<"ERROR!! Cannot open the file \n";
        exit(1);
    }
    string text, content = "";
    while (getline(input, text)){
        content += text;
        content += '\n';
    }
    cout<<content;
    /*
    huffman* cur = build(text);
    unordered_map<char, string> table;
    build_table(cur, table, "");
    for (char s : text){
        cout<<table[s];
    }
     */
}