#include "const.hpp"


int main(){
    cout<<"Welcome to Compress me :).\n";
    cout<<"Type 1 to encode, 2 to decode:\n";
    int choice ;
    cin>>choice;
    cin.ignore();
    if(choice == 1) {
        cout << "Please enter the path to the file you want to encode: \n";
        string in_file;
        getline(cin, in_file);
        cout << "Please enter the path to the file you want to the output in: \n";
        string out_file;
        getline(cin, out_file);
        cout << "Encoding.....\n";
        encoder(in_file, out_file);
    }else if(choice == 2){
        cout << "Please enter the path to the file you want to decode: \n";
        string in_file;
        getline(cin, in_file);
        cout << "Please enter the path to the file you want to the output in: \n";
        string out_file;
        getline(cin, out_file);
        cout << "Decoding.....\n";
        decode_file(in_file, out_file);
    }else{
        cout<<"Error, please type 1 or 2.\n";
    }
}