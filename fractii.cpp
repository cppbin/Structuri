/** alg Euclid - calculeaza cmmdc(x, y) **/
struct fractie
{
    int n, m;
};

int cmmdc(int x, int y)
{
    while(x != y)
        if(x > y)
            x = x - y;
        else
            y = y - x;
    return x;
}

fractie suma(fractie A, fractie B)
{
    fractie S;
    S.n = A.n * B.m + B.n * A.m;
    S.m = A.m * B.m;
    int c = cmmdc(S.n, S.m);
    if(c != 1)
    {
        S.n = S.n / c;
        S.m = S.m / c;
    }
    return S;
}





