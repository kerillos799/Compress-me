#include "const.hpp"



void write_encoded(string out_file, unordered_map<char,string> & table, string content){
    while (out_file.back() == ' ')
        out_file.pop_back();
    string extension = out_file.substr(out_file.size() - 4, 4 );
    if (extension != ".bin"){
        cout<<"Wrong format(output file), I only accept \".bin\" files. :)";
        exit(1);
    }
    fstream output(out_file, ios::out | ios::binary);
    if (!output.is_open()){
        cout<<"ERROR!! Cannot open output the file \n";
        exit(1);
    }
    cout<<"Writing to the output file...\n";
    output.clear();

    output<<table.size()<<"\n";
    for (auto [ch,st] : table){
        for (auto c : st){
            output<< c - '0';
        }
        output<<" ";
        if (ch != '\n')
            output<<ch<<"\n";
        else
            output<<"nl\n";
    }
     for(auto ch : content){
        for(auto num : table[ch]){
            output<<num - '0';
        }
    }

    cout<<"Done. :)\n";
}