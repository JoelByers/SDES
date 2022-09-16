#include <iostream>
#include <fstream>
#include <cstring>
#include "SDES.h"

using namespace std;

void writeToFile(bool data[8], string fileName){
    ofstream outfile;
    outfile.open(fileName, ios_base::app);
    outfile << '\n';
    for(int i=0;i<8;i++){
        outfile << int(data[i]);
    }
}

void printUsage(){
    cerr << "Invalid arguments\n";
    cerr << "   Usage: sdes <encrypt|decrypt> [OPTIONAL <input_file> <output_file> <key_file>]\n";
    cerr << "   Defaults:\n";
    cerr << "       input_file  : input.txt\n";
    cerr << "       output_file : output.txt\n";
    cerr << "       keyFile     : key.txt" << endl;
}

// Function found here:
// https://www.geeksforgeeks.org/remove-spaces-from-a-given-string/
void removeSpaces(char *str){
    int count = 0;
 
    for (int i = 0; str[i]; i++){
        if (str[i] != ' '){
            str[count++] = str[i];
        }
    }

    str[count] = '\0';
}

void strToArray(string input, bool *output){
    for(int i=0;i<input.length();i++){
        if(input[i]=='0'){
            output[i] = 0;
        }
        else{
            output[i] = 1;
        }
    }
}

int main(int argc, char *argv[]){

    // Handle command line arguments
    string inputFile = "inputFile.txt";
    string outputFile = "outputFile.txt";
    string keyFile = "keyFile.txt";

    if(argc < 2){
        printUsage();
        return -1;
    }

    if(argc >= 3){
        inputFile = string(argv[2]);
    }

    if(argc >= 4){
        outputFile = string(argv[3]);
    }

    if(argc >= 5){
        keyFile = string(argv[4]);
    }

    // Read data from files
    ifstream inputFileStream(inputFile);
    string inputData;
    string temp;
    
    ifstream keyFileStream(keyFile);
    string keystring;
    bool key[10] = {0,0,0,0,0,0,0,0,0,0};
    getline(keyFileStream, keystring);
    strToArray(keystring,key);

    while(getline(inputFileStream, temp)){
        inputData.append(temp);
    }

    // String to char* found here
    // https://www.geeksforgeeks.org/convert-string-char-array-cpp/
    int textLen = inputData.length();
    char textAry[textLen + 1];
    strcpy(textAry, inputData.c_str());
    removeSpaces(textAry);

    // Perform Encryption/Decryption
    if(string(argv[1]) == "encrypt"){
        cout << "Encrypting..." << endl;
        bool data[8] = {0,0,0,0,0,0,0,0};
        for(char c : inputData){
            asciiToBinary(c, data);
            encrypt(data,key);
            writeToFile(data, outputFile);
        }
        cout << "Encryption Complete" << endl;
    }
    else if(string(argv[1]) == "decrypt"){
        cout << "Decrypting..." << endl;
        for(int i=0; i<inputData.length();i+=8){
            string temp;
            for(int j=0; j<8; j++){
                temp.push_back(inputData[i+j]);
            }
            bool inputDecrypt[8] = {0,0,0,0,0,0,0,0};
            strToArray(temp,inputDecrypt);
            decrypt(inputDecrypt,key);
            writeToFile(inputDecrypt, outputFile);
            
        }
        cout<<"Decryption complete"<<endl;
    }
    else{
        printUsage();
        return -1;
    }

    return 0;
}