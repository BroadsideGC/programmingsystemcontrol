#include <iostream>
#include "cobs.cpp"

void cobs_res(float f, uint8_t *b)
{
    uint8_t a[6];
    uint8_t m = 245;
    a[0] = 10;

    //uint8_t b[8];
    unsigned char *c = reinterpret_cast<unsigned char *>(&f);
    for (int i = 0; i < 4; i++) {
        a[i + 1] = c[i];
        m -= c[i];

    }
    a[5] = m;
    int t = StuffData(&a[0], 6, &b[0]);

}
