#include <iostream>
#include<fstream>
using namespace std;

string txt, encrypted, decrypted;
int l;

string caesarCipher(string txt, int l)
{
    string encrypted = "";
    for(int i = 0; i < txt.length(); i++)
    {
        if(txt[i] > 64 && txt[i] < 91)
        {
            if(txt[i] + l > 90)
                encrypted += txt[i] + l - 26;
            else if(txt[i] + l < 65)
                encrypted += txt[i] + l + 26;
            else
                encrypted += txt[i] + l;
        }
        else if(txt[i] > 96 && txt[i] < 123)
        {
            if(txt[i] + l > 122)
                encrypted += txt[i] + l - 26;
            else if(txt[i] + l < 97)
                encrypted += txt[i] + l + 26;
            else
                encrypted += txt[i] + l;
        }
        else
            encrypted += txt[i];
    }
    return encrypted;
}

string caesarCipherUnencrypt(string encrypted, int l)
{
    string txt = "";
    for(int i = 0; i < encrypted.length(); i++)
    {
        if(encrypted[i] > 64 && encrypted[i] < 91)
        {
            if(encrypted[i] - l > 90)
                txt += encrypted[i] - l - 26;
            else if(encrypted[i] - l < 65)
                txt += encrypted[i] - l + 26;
            else
                txt += encrypted[i] - l;
        }
        else if(encrypted[i] > 96 && encrypted[i] < 123)
        {
            if(encrypted[i] - l > 122)
                txt += encrypted[i] - l - 26;
            else if(encrypted[i] - l < 97)
                txt += encrypted[i] - l + 26;
            else
                txt += encrypted[i] - l;
        }
        else
            txt += encrypted[i];
    }
    return txt;
}

main()
{
    ofstream fileWithResults;
    fileWithResults.open("results.txt");
    cout << "======================================================" << endl;
    fileWithResults << "======================================================" << endl;
    cout << "Give me a text that you want to encrypt: ";
    fileWithResults << "Give me a text that you want to encrypt: ";
    getline(cin,txt);
    fileWithResults << txt << endl;
    cout << "Give me a number that you want to encrypt by: ";
    fileWithResults << "Give me a number that you want to encrypt by: ";
    cin >> l;
    fileWithResults << l << endl;
    cout << "======================================================" << endl;
    fileWithResults << "======================================================" << endl;
    l %= 26;
    encrypted = caesarCipher(txt,l);
    cout << "Your encrypted text: " << encrypted << endl;
    fileWithResults << "Your encrypted text: " << encrypted << endl;
    decrypted = caesarCipherUnencrypt(encrypted,l);
    cout << "Your unencrypted text: " << decrypted << endl;
    fileWithResults << "Your unencrypted text: " << decrypted << endl;
    cout << "======================================================";
    fileWithResults << "======================================================";
    fileWithResults.close();
}
