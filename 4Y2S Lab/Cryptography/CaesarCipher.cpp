#include <bits/stdc++.h>
#include <string.h>
using namespace std;

string caesarCipherEncode(string plaintext){
    string ciphertext="";
    for (int i = 0; i < plaintext.length(); i++) {
        // Encrypt Uppercase letters
        if (isupper(plaintext[i]))
            ciphertext += (plaintext[i] - 65 + 3) % 26 + 65;
        // Encrypt Lowercase letters
        else if(islower(plaintext[i]))
            ciphertext += (plaintext[i] - 97 + 3) % 26 + 97;
        else
            ciphertext += plaintext[i];
    }
    return ciphertext;
}

string caesarCipherDecode(string ciphertext){
    string originaltext="";
    for (int i = 0; i < ciphertext.length(); i++){
        // Encrypt Uppercase letters
        if (isupper(ciphertext[i])){
            originaltext += ciphertext[i] - 3;
            if(originaltext[i]<65)
                originaltext[i]+=26;
        }
        // Encrypt Lowercase letters
        else if(islower(ciphertext[i])){
            originaltext += ciphertext[i] - 3;
            if(originaltext[i]<97)
                originaltext[i]+=26;
        }
        else
            originaltext += ciphertext[i];
    }
    return originaltext;
}

int main(){
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    string plaintext, ciphertext, originaltext;
    cout << "Enter the plain text: ";
    getline(cin, plaintext);

    ciphertext=caesarCipherEncode(plaintext);
    cout << "Caesar Cipher Text: " << ciphertext << endl;

    originaltext=caesarCipherDecode(ciphertext);
    cout << "Original Text: " << originaltext << endl;

    return 0;
}
