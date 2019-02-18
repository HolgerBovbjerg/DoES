#include <stdlib.h>
#include <stdio.h>
// 1.3
int IsLittleEndian() {
    long a = 1;
    char *b;
    b = (char*)&a;
    if(b[0]==1)
        printf("Is Little Endian \n");
    else
        printf("Is Not Little Endian \n");
return 0;
}

// 1.4
int TwosComplement(){
    struct SixteenBits {
        int b0 : 1;
        int b1 : 1;
        int b2 : 1;
        int b3 : 1;
        int b4 : 1;
        int b5 : 1;
        int b6 : 1;
        int b7 : 1;
        int b8 : 1;
        int b9 : 1;
        int b10 : 1;
        int b11 : 1;
        int b12 : 1;
        int b13 : 1;
        int b14 : 1;
        int b15 : 1;
    };
    union Number {
        struct SixteenBits bits;
        signed short all;
    };
    union Number num;
        num.all=0; /* Clear bits */
        num.bits.b0=1;
        num.bits.b1=0;
        num.bits.b2=0;
        num.bits.b3=1;
        num.bits.b4=1;
        num.bits.b5=0;
        num.bits.b6=0;
        num.bits.b7=1;
        num.bits.b8=1;
        num.bits.b9=0;
        num.bits.b10=1;
        num.bits.b11=1;
        num.bits.b12=0;
        num.bits.b13=1;
        num.bits.b14=1;
        num.bits.b15=1;
    printf("%d\n",(int)num.all);
    return 0;
}

// 1.5
int ToHexaDecimal(){
    long decimal, quotient, remainder;
    int i, j = 0;
    char hexadecimal[100];
    printf("Skriv et tal i base 10: ");
    scanf("%ld", &decimal);
    printf("Du indtastede: %ld\n", decimal);

    quotient = decimal;
    while (quotient != 0){
        remainder = quotient % 16;          //step 1
        if (remainder < 10)
            hexadecimal[j++] = 48 + remainder;   //step 2
        else
            hexadecimal[j++] = 55 + remainder;   //step 3
        quotient = quotient / 16;            //step 4
    }
    printf("Dette er i hexadecimal:");
    for (i = j; i >= 0; i--)
        printf("%c", hexadecimal[i]);
    printf("\n");

    return 0;
}

int main(void) {
    IsLittleEndian();
    TwosComplement();
    ToHexaDecimal();
return 0;
}
