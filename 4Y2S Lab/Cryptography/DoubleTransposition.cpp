#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int width, x, y;

string TranspositionCipherEncode(string plaintext){
    string ciphertext="";
    x = (plaintext.length()+width-1)/width;
    y = (plaintext.length()-1)%width;
    string s[x+5];
    int c = 0, k = 0;
    for(int i=0; i<plaintext.length(); i++){
        s[k][c]=plaintext[i];
        c++;
        if(c>=width){
            c=0;
            k++;
        }
    }
    for(int i=0; i<width; i++){
        if(i<=y)
            for(int j=0; j<x; j++)
                ciphertext+=s[j][i];
        else
            for(int j=0; j<x-1; j++)
                ciphertext+=s[j][i];
    }

    return ciphertext;
}

string TranspositionCipherDecode(string ciphertext){
    string originaltext="";
    x = (ciphertext.length()+width-1)/width;
    y = (ciphertext.length()-1)%width;
    string s[x+5];

    int k=0;
    for(int i=0; i<width; i++){
        if(i<=y)
            for(int j=0; j<x; j++)
                s[j][i]=ciphertext[k++];
        else
            for(int j=0; j<x-1; j++)
                s[j][i]=ciphertext[k++];
    }
    for(int i=0; i<x-1; i++){
        for(int j=0; j<width; j++)
            originaltext += s[i][j];
    }
    for(int i=0; i<=y; i++)
        originaltext += s[x-1][i];
    return originaltext;
}

int main(){
    //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

    string plaintext, ciphertext, originaltext;
    cout << "Enter the plain text: ";
    getline(cin, plaintext);
    cout << "Enter the width: ";
    cin >> width;

    ciphertext = TranspositionCipherEncode(plaintext);
    cout << "Transposition CipherText: " << ciphertext << endl;

    ciphertext = TranspositionCipherEncode(ciphertext);
    cout << "Double Transposition CipherText: " << ciphertext << endl;

    originaltext = TranspositionCipherDecode(ciphertext);
    originaltext = TranspositionCipherDecode(originaltext);
    cout << "Original Text: " << originaltext << endl;

    return 0;
}
