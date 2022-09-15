#include <iostream>
#include <fstream>
#include <cstring>
#include "SDES.h"

using namespace std;

void writeToFile(bool encrypted[8]){
    ofstream outfile;
    outfile.open("outputFile.txt", ios_base::app);
    for(int i=0;i<8;i++){
        outfile << int(encrypted[i]);
    }
}

void printUsage(){
    cerr << "Invalid arguments\n";
    cerr << "   Usage: sdes <encrypt|decrypt> [OPTIONAL <input_file> <output_file> <key_file>]\n";
    cerr << "   Defaults:\n";
    cerr << "       input_file  : inputFile.txt\n";
    cerr << "       output_file : outputFile.txt\n";
    cerr << "       keyFile     : keyfile.txt" << endl;
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
    string plainText;
    string temp;
    
    while(getline(inputFileStream, temp)){
        plainText.append(temp);
    }

    // String to char* found here
    // https://www.geeksforgeeks.org/convert-string-char-array-cpp/
    int textLen = plainText.length();
    char textAry[textLen + 1];
    strcpy(textAry, plainText.c_str());
    removeSpaces(textAry);

    // Get sub-keys
    bool key[10] = {1,1,1,1,1,1,1,1,1,1};

    // Perform Encryption/Decryption
    if(string(argv[1]) == "encrypt"){
        cout << "TODO: Encrypt" << endl;
        //encrypt(data,key);
    }
    else if(string(argv[1]) == "decrypt"){
        cout << "TODO: Decrypt" << endl;
    }
    else{
        printUsage();
        return -1;
    }

    return 0;
}