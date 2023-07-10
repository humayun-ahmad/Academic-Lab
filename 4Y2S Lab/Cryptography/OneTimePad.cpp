#include <bits/stdc++.h>
#include <string.h>
using namespace std;

map <char, int> mp;

void AssignValue(){
    char c = 'a';
    for(int i=1; i<=26; i++){
        mp[c] = i;
        c++;
    }
}

string OneTimePadEncode(string plaintext, string key){
    string ciphertext="";
    for (int i = 0; i < plaintext.length(); i++) {
        // Encrypt Uppercase letters
        if (isupper(plaintext[i]))
            ciphertext += (plaintext[i] - 65 + mp[key[i]]) % 26 + 65;
        // Encrypt Lowercase letters
        else if(islower(plaintext[i]))
            ciphertext += (plaintext[i] - 97 + mp[key[i]]) % 26 + 97;
        else
            ciphertext += plaintext[i];
    }
    return ciphertext;
}

string OneTimePadDecode(string ciphertext, string key){
    string originaltext="";
    for (int i = 0; i < ciphertext.length(); i++) {
        // Encrypt Uppercase letters
        if (isupper(ciphertext[i])){
            originaltext += ciphertext[i] - mp[key[i]];
            if(originaltext[i]<65)
                originaltext[i]+=26;
        }
        // Encrypt Lowercase letters
        else if(islower(ciphertext[i])){
            originaltext += ciphertext[i] - mp[key[i]];
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
    string key = "abcabc";
    AssignValue();
    cout << "Enter the plain text: ";
    getline(cin, plaintext);

    ciphertext=OneTimePadEncode(plaintext, key);
    cout << "Caesar Cipher Text: " << ciphertext << endl;

    originaltext=OneTimePadDecode(ciphertext, key);
    cout << "Original Text: " << originaltext << endl;

    return 0;
}
