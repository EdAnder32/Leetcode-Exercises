int myAtoi(char* s) {
    int     signal = 1;
    long     result = 0;
    int     i = 0;
    int     k;
    int     start;
    int     int_overflow = 0;

    while (s[i] >= 9 && s[i] <= 13 || s[i] == 32)
        i++;
    if (s[i] == '+' || s[i] == '-')
    {
        if (s[i] == '-')
            signal = -1;
        i++;
    }
    start = i;
    k = 0;
    while (s[i] == '0')
        i++;
    while (s[i] >= '1' && s[i] <= '9')
    {
        k++;
        i++;
    }
    if (k >= 0 && k <= 10)
    {
        i = start;
        while (s[i] >= '0' && s[i] <= '9')
        {
            result = result * 10 + (s[i] - '0');
            if (result >= 2147483647 && signal == 1)
            {
                int_overflow = 1;
                break ;
            }
            else if (result >= 2147483648 && signal == -1)
            {
                int_overflow = 1;
                break ;
            }
            i++;
        }
    }
    else
        int_overflow = 1;
    if (signal == -1 && int_overflow == 1)
        return (-2147483648);
    if (int_overflow == 1)
        result = 2147483647;
    return (result * signal);
}
