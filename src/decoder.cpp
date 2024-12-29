#include "const.hpp"

void decode_file(const string& input_file, const string& output_file) {
    ifstream input(input_file, ios::in | ios::binary);
    if (!input.is_open()) {
        cout << "ERROR!! Cannot open the input file \n";
        exit(1);
    }
    cout << "Reading the input file...\n";

    int table_size;
    input.read(reinterpret_cast<char*>(&table_size), sizeof table_size);

    unordered_map<string, char> code_to_char;
    for (int i = 0; i < table_size; ++i) {
        char ch;
        input.get(ch);
        int code_length;
        input.read(reinterpret_cast<char*>(&code_length), sizeof code_length);
        string codeword(code_length, ' ');
        input.read(&codeword[0], code_length);
        code_to_char[codeword] = ch;
    }

    char pad_char;
    input.get(pad_char);
    int pad = static_cast<unsigned char>(pad_char);

    string bit_str;
    char byte;
    while (input.get(byte)) {
        bitset<8> bits(static_cast<unsigned char>(byte));
        bit_str += bits.to_string();
    }
    input.close();

    if (pad > 0 && pad <= 7)
        bit_str.erase(bit_str.end() - pad, bit_str.end());

    cout << "Decoding the data...\n";

    string decoded_content;
    string current_code;
    for (char bit : bit_str) {
        current_code += bit;
        auto it = code_to_char.find(current_code);
        if (it != code_to_char.end()) {
            decoded_content += it->second;
            current_code.clear();
        }
    }

    ofstream output(output_file, ios::out);
    if (!output.is_open()) {
        cout << "ERROR!! Cannot open the output file \n";
        exit(1);
    }
    output << decoded_content;
    output.close();

    cout << "Decoding completed successfully.\n";
}
