#include "const.hpp"





void decoder(string in_file, string out_file){
    while (in_file.back() == ' ')
        in_file.pop_back();
    string extension = in_file.substr(in_file.size() - 4, 4 );
    if (extension != ".txt"){
        cout<<"Wrong format(input file), I only accept \".txt\" files. :)";
        exit(1);
    }
    fstream input(in_file, ios::in);
    if (!input.is_open()){
        cout<<"ERROR!! Cannot open the file \n";
        exit(1);
    }
    cout<<"Reading input file...\n";
    string text, content = "";
    while (getline(input, text)){
        content += text;
        content += '\n';
    }
    huffman* cur = build(content);
    unordered_map<char, string> table;
    build_table(cur, table, "");

    write_encoded(out_file, table, content);
}