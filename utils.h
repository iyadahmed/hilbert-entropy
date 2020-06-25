#define INT_SIZE sizeof(int)
#define INT_BITS INT_SIZE * 8 -1

int gray_code(int x){
    return x^(x>>1);
}

int igray_code(int x){
    int inv = 0;

    //taking xor until n becomes zero
    for (; x; x = x >> 1)
        inv ^= x;

    return inv;
}

void int2bits(unsigned int x, int count, int* out){
    unsigned int mask = 1U << (count -1);
    int i = 0;
    for (; i < count; i++){
        out[i] = (x & mask) ? 1 : 0;
        x <<= 1;
    }
}

void bits2int(int*)
