/**
 * endian.c -- Ways of judging the endian of the running processor.
 *
 * Author: Leon (yong.he1982(at)gmail.com)
 * Date  : 2013-07-08 [Monday, 189]
 */

#include <stdio.h>
#include <stdint.h> // uint8_t
#define p(x) printf("%s\n", (x))

// ============================================================================
// method 1: using array
// ============================================================================
enum {
    ENDIAN_UNKNOWN,
    ENDIAN_BIG,
    ENDIAN_LITTLE,
    ENDIAN_BIG_WORD,   /* Middle-endian, Honeywell 316 style */
    ENDIAN_LITTLE_WORD /* Middle-endian, PDP-11 style */
};

int judgeByArray(void)
{
    uint8_t buffer[4];
    buffer[0]=0x00;
    buffer[1]=0x01;
    buffer[2]=0x02;
    buffer[3]=0x03;
    switch(*((uint32_t*)buffer)){
    case 0x00010203: return ENDIAN_BIG;
    case 0x03020100: return ENDIAN_LITTLE;
    case 0x02030001: return ENDIAN_BIG_WORD;
    case 0x01000302: return ENDIAN_LITTLE_WORD;
    default:        return ENDIAN_UNKNOWN;
    }
}

// ============================================================================
// method 2: using define
// ============================================================================
const int i = 1;
#define isBigEndian() ( (*(char*)&i) == 0 )

// ============================================================================
// method 3: using union
// ============================================================================
int judgeByUnion()
{
    union{
    int i;
    char c[sizeof(int)];
    }x;
    x.i = 1;
    if(x.c[0] == 1) {
        return ENDIAN_LITTLE;
    } else {
        return ENDIAN_BIG;
    }
}

void printEndian(int code)
{
    switch(code){
    case ENDIAN_BIG:
        p("BIG ENDIAN");
        break;
    case ENDIAN_BIG_WORD:
        p("BIG WORLD ENDIAN");
        break;
    case ENDIAN_LITTLE:
        p("LITTLE ENDIAN");
        break;
    case ENDIAN_LITTLE_WORD:
        p("LITTLE WORLD ENDIAN");
        break;
    default:
        p("UNKNOWN ENDIAN");
        break;
    }
}

void printEndianCase(int test, int endian)
{
    printf("Case %d: ", test);
    printEndian(endian);
}


int main(int argc, char* argv[])
{
    // test 1
    int endian = judgeByArray();
    printEndianCase(1, endian);

    // test 2
    int big = isBigEndian();
    if(big) {
        p("Case 2: BIG ENDIAN");
    } else {
        p("Case 2: LITTLE ENDIAN");
    }

    // test 3
    endian = judgeByUnion();
    printEndianCase(3, endian);

    return 0;
}
