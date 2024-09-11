#include "const.hpp"


int main(){
    cout<<"Welcome to Compress me :).\n";
    cout<<"Please enter the path to the file you want to encode: \n";
    string in_file;
    getline(cin, in_file);
    cout<<"Please enter the path to the file you want to the output in: \n";
    string out_file;
    getline(cin, out_file);
    cout<<"Encoding.....\n";
    decoder(in_file, out_file);
}