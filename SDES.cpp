#include <iostream>

using namespace std;

void printBitArray(bool* ary, int arySize){
    for(int i = 0; i < arySize; i++){
        cout << ary[i] << " ";
    }

    cout << endl;
}

void p10(bool key[10]){
    int newpos[10] = {3,5,2,7,4,10,1,9,8,6};
    bool temp[10];
    for(int i=0; i<10; i++)
    {
        temp[i] = key[newpos[i]-1];
    }
    for(int i=0; i<10; i++){
        key[i] = temp[i];
    }
}

void p8(bool key[10], bool nkey[8]){
    int newpos[8] = {6,3,7,4,8,5,10,9};
    for(int i = 0; i<8; i++){
        nkey[i] = key[newpos[i]-1];
    }
}

void ip(bool key[8]){
    int newpos[8] = {2,6,3,1,4,8,5,7};
    bool temp[8];
    for(int i = 0; i<8; i++){
        temp[i] = key[newpos[i]-1];
    }
    for(int i=0; i<8; i++){
        key[i] = temp[i];
    }
}

void ep(bool key[4], bool nkey[8]){
    int newpos[8] = {4,1,2,3,2,3,4,1};
    for(int i = 0; i<8; i++){
        nkey[i] = key[newpos[i]-1];
    }
}

void p4(bool key[4]){
    int newpos[4] = {2,4,3,1};
    bool temp[4];
    for(int i=0; i<4; i++){
        temp[i] = key[newpos[i]-1];
    }
    for(int i=0; i<4; i++){
        key[i] = temp[i];
    }
}

// Perform and Xor between outArray and xorArray and store the 
// result in outArray.
void exclusiveOr(bool* outArray, bool* xorArray, int arraySize){
    for(int i = 0; i < arraySize; i++)
    {
        outArray[i] = outArray[i] != xorArray[i];
    }
}

void leftShift(bool* array, int arraySize){
    bool firstBit = array[0];
    for(int i = 0; i < (arraySize - 1); i++)
    {
        array[i] = array[i + 1];
    }
    array[arraySize - 1] = firstBit;
}

// Return a short representation of a 2 element bit array
//
// function found on this page:
// https://stackoverflow.com/questions/20434787/convert-bit-array-to-short
short shortFromBits(bool bits[2]){
    short res = 0;

    // Handle first two bits
    if (bits[0]) {
        res |= 1 << 1;
    }
    if (bits[1]) {
        res |= 1 << 0;
    }

    // Pad
    for(int i = 0; i < 13; i++){
        res |= 0 << (i + 2);
    }
    return res;
}

// return the bit representation of a short num
// where 0 <= num <= 3
void bitsFromShort(short num, bool bits[2]){
    bits[0] = num & (1 << 1);
    bits[1] = num & (1 << 0);
}

// Perform the S-Box lookup. `Data` is the array used to
// derrive the row and column, and `box` is the S table. The
// result will be stored in the array `output`
void _s(bool data[4], bool output[2], short box[4][4]){
    bool rowAry[2];
    bool colAry[2];
    rowAry[0] = data[0];
    rowAry[1] = data[3];
    colAry[0] = data[1];
    colAry[1] = data[2];

    short row = shortFromBits(rowAry);
    short col = shortFromBits(colAry);
    int boxResult = box[row][col];

    bitsFromShort(boxResult, output);
}

// Perfrom the S0 computation. This function
// is used by sBox.
void _sZero(bool data[4], bool output[2]){
    short box[4][4] = {{1,0,3,2},
                     {3,2,1,0},
                     {0,2,1,3},
                     {3,1,3,2}};
    _s(data, output, box);
}

// Perfrom the S1 computation. This function
// is used by sBox.
void _sOne(bool data[4], bool output[2]){
    short box[4][4] = {{0,1,2,3},
                     {2,0,1,3},
                     {3,0,1,0},
                     {2,1,0,3}};
    _s(data, output, box);
}

// Perform the compete SBox computation
void sBox(bool data[8], bool output[4]){
    bool leftHalf[4];
    bool rightHalf[4];
    for(int i = 0; i < 4; i++){
        leftHalf[i] = data[i];
        rightHalf[i] = data[i + 4];
    }

    bool leftOut[2];
    bool rightOut[2];
    _sZero(leftHalf, leftOut);
    _sOne(rightHalf, rightOut);

    for(int i = 0; i < 2; i++){
        output[i] = leftOut[i];
        output[i + 2] = rightOut[i];
    }
}

// Swap the first half of the array
// with the second, and the second with
// the first
void swapHalf(bool data[8]){
    bool temp;

    for(int i = 0; i < 4; i++){
        temp = data[i];
        data[i] = data[i + 4];
        data[i + 4] = temp;
    }
}
