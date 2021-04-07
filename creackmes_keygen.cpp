#include <iostream>



//login hash
unsigned int cme1_hash1(char* str) {
    int res = 0xffffffff;
    for (int i = 0; str[i] != '\0'; i++) {
        res ^= (int)str[i];

        for (int j = 7; j >= 0; j--) {
            res = res >> 1 ^ -(res & 1) & 0xedb88320;
        }
    }

    return ~res;
}


//password hash
unsigned int cme1_hash2(char* str) {
    long int res = 0;
    for (int i = 0; i < strlen(str); i++) {
        res += ((int)str[i]) ^ 0x99U;
    }
    return res;
}


int str_chech(char* str) {
    int nan = 1;//Not a number
    int nal = 1;//Not a letter
    int naL = 1;//Not an Upper Letter
    for (int i = 0; i < strlen(str) && (nan | nal | naL); i++) {
        nan = 1;
        nal = 1;
        naL = 1;
        if (str[i] < '0' || str[i] > '9') {
            nan = 0;
        }
        if (str[i] < 'a' || str[i] > 'z') {
            nal = 0;
        }
        if (str[i] < 'A' || str[i] > 'Z') {
            naL = 0;
        }
    }
    return (nan | nal | naL);
}


//Generated passwords are exactly 3 character long
int main()
{
    char login[256];
    char pass[4];
    pass[3] = '\0';
    printf("Login:\n");
    scanf_s("%s", login, 255);

    int h1 = cme1_hash1(login) & 0xff;

    //pretty bad brutforce
    for (int i = int('0'); i < (int)'Z'; i++) {
        for (int j = int('0'); j < (int)'Z'; j++) {
            for (int k = int('0'); k < (int)'Z'; k++) {
                pass[0] = (char)i;
                pass[1] = (char)j;
                pass[2] = (char)k;


                if (str_chech(pass) && (cme1_hash2(pass) & 0xff) == h1) {
                    printf("%s\n", pass);
                }
            }
        }
    }
}

