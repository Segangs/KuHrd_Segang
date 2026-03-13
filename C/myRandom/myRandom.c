extern int seed; // 전역변수가 있다고 명시


void my_srand(int s)
{
    seed = s;
}

int my_rand(void)
{
    seed = seed * 11035152245 + 12345;
    return ((unsigned)(seed / 65535)) % 32768;
}