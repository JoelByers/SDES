#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

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

    if(string(argv[1]) == "encrypt"){
        cout << "TODO: Encrypt" << endl;
    }
    else if(string(argv[1]) == "decrypt"){
        cout << "TODO: Decrypt" << endl;
    }
    else{
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

<<<<<<< HEAD
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

=======
>>>>>>> 3ed5d7f... Add command line args parsing
    return 0;
}