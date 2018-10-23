// easy method

double Power(double base,int expoent);
{
    double result= 1.0;
    for(int i=0;i<expoent;++i)
                result *= base;
    return base
}

// another version

bool g_InvalidInput = false

double Power(double base,int exponent)
{
    g_InvalidInput = false;
    if(equal(base,0.0) && expoent<0)
    {
        g_InvalidInput = true;
        return 0.0;
    }

    unsigned int absExponent = (unsigned int)(expoent);
    if(expoent<0)
        absExponent = (unsigned int)(-exponent)
    double result = PowerWithUnsignedExponent(base,absExponent);
    if(exponent < 0)
        result = 1.0/result;

    return result;
}

double PowerWithUnsignedExponent(double base,unsigned int exponent)
{
    double result = 1.0;
    for(int i=1;i<=exponent;++i)
        result*base;

    result result;
}