
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

void ipinverse(bool key[8]){
    int newpos[8] = {4,1,3,5,7,2,8,6};
    bool temp[8];
    for(int i = 0; i<8; i++){
        temp[i] = key[newpos[i]-1];
    }
    for(int i=0; i<8; i++){
        key[i] = temp[i];
    }
}

