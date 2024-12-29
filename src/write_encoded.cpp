#include "const.hpp"
#include <cstdint>

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
        cout<<"ERROR!! Cannot open the output file \n";
        exit(1);
    }
    cout<<"Writing to the output file...\n";
    output.clear();

    uint32_t table_size = table.size();
    output.write(reinterpret_cast<char*>(&table_size), sizeof table_size);

    // Write the Huffman table
    for (auto [k,v] : table){
        output.put(k); // Write the character
        uint32_t code_length = v.length(); // Length of the codeword
        output.write(reinterpret_cast<char*>(&code_length), sizeof code_length); // Write code length
        output.write(v.c_str(), code_length); // Write the codeword
    }

    // Build the encoded content
    string bin;
    for (char ch : content)
        bin += table[ch];

    // Get padding size to make the string divisible by 8
    int pad = (8 - (bin.size() % 8)) % 8;
    bin.append(pad, '0'); // Append padding zeros

    // Write the padding size as a single byte
    output.put(static_cast<char>(pad));

    // Write the encoded data
    for (size_t i = 0; i < bin.length(); i += 8){
        bitset<8> byte(bin.substr(i,8));
        char byte_char = static_cast<char>(byte.to_ulong());
        output.put(byte_char);
    }

    output.close();
    cout<<"Done. :)\n";
}