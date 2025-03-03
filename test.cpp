#include <iostream>

int main()
{
    int a[10], max, count;
    a[0] = 0;
    for(int i = 1; i < 10; i++)
    {
        std::cin >> a[i];
    }

    max = a[1];
    count = 1;

    for(int i = 2; i < 10; i++)
    {
        if(max < a[i])
        {
            max = a[i];
            count = i;
        }
    }
    
    std::cout << max << std::endl << count << std::endl;

}