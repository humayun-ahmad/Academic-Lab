#include <bits/stdc++.h>
#include <string.h>
using namespace std;

map <string, string> en_dictionary, dec_dictionary;

void create_dictionary(){
    string s1, s2;
    freopen("Dictionary.txt", "r", stdin);
    while(cin >> s1 >> s2){
        en_dictionary[s1]=s2;
        dec_dictionary[s2]=s1;
    }
}

string PolygramSubstitutionEncode(string plaintext){
    string ciphertext="", tmp="";
    for(int i=0; i<plaintext.length(); i++){
        if(islower(plaintext[i]) || isupper(plaintext[i])){
            tmp+=plaintext[i];
            if(en_dictionary.find(tmp) != en_dictionary.end()){
                ciphertext += en_dictionary[tmp];
                tmp = "";
            }
        }
        else ciphertext += plaintext[i];
    }
    return ciphertext;
}

string PolygramSubstitutionDecode(string ciphertext){
    string originaltext="", tmp="";
    for(int i=0; i<ciphertext.length(); i++){
        if(islower(ciphertext[i]) || isupper(ciphertext[i])){
            tmp+=ciphertext[i];
            if(dec_dictionary.find(tmp) != dec_dictionary.end()){
                originaltext += dec_dictionary[tmp];
                tmp = "";
            }
        }
        else originaltext += ciphertext[i];
    }
    return originaltext;
}

int main(){
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    string plaintext = "Cryptography and Network Security", ciphertext, originaltext;
    cout << "Plaintext: " << plaintext << endl;
    create_dictionary();

    ciphertext=PolygramSubstitutionEncode(plaintext);
    cout << "Polygram Substitution CipherText: " << ciphertext << endl;

    originaltext=PolygramSubstitutionDecode(ciphertext);
    cout << "Original Text: " << originaltext << endl;

    return 0;
}
