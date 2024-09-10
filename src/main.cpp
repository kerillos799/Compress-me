#include "const.hpp"


int main(){
    cout<<"Welcome to Compress me :). \nPlease enter the text you want to encode:  ";
    string text;
    getline(cin,text);
    cout<<"Encoding.....\n";
    decoder(text);
}