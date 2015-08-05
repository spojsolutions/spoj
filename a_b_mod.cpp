//a^b % m;
int modular(int base, unsigned int exp, unsigned int mod)
{
    int x = 1;
    int power = base % mod;

    for (int i = 0; i < sizeof(int) * 8; i++) {
        int least_sig_bit = 0x00000001 & (exp >> i);
        if (least_sig_bit)
            x = (x * power) % mod;
        power = (power * power) % mod;
    }

    return x;
}