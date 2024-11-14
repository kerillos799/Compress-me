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


    int size = table.size();
    output.write(reinterpret_cast<char*> (& size), sizeof table.size());
    for (auto [k,v] : table){
        output.put(k);
        size = v.length();
        output.write(reinterpret_cast<char*> (&size), sizeof size);
        output.write(reinterpret_cast<char*> (&v), sizeof v);
    }


    string bin = "";
    for (char ch : content)
        bin += table[ch];
    // get padding size to make the string divisible by 8
    int pad = (8 - (bin.size()%8))%8;
    for (int i = 0; i<pad; i++)
        bin += '0';

    output.write(reinterpret_cast<char*>(&pad), sizeof pad);
    for (int i = 0; i<bin.length(); i+= 8){
        bitset<8> byte(bin.substr(i,8));
        char byte_char = static_cast<char>(byte.to_ullong());
        output.put(byte_char);
    }
    output.close();
    cout<<"Done. :)\n";
}