#include <iostream>
#include <stdlib.h>
#include <algorithm>

void Permutation1(int* array, int len)
{
    std::srand(std::time(0));
    for (int i = 0; i < len; i++)
    {
        do {
            array[i] = std::rand()%len + 1;
            bool duplicated = false;
            for (int j = 0; j < i; j++)
            {
                if (array[j] == array[i])
                {
                    duplicated = true;
                    break; 
                }
            }
            if (!duplicated)
            {
                break;
            }
        } while (true);
    }
    return;
}
void Permutation2(int* array, int len)
{
    std::srand(std::time(0));
    bool* duplicated = new bool[len];
    for(int i = 0; i < len; i++)
    {
        duplicated[i] = false;
    }
    for(int i = 0; i < len; i++)
    {
        do {
            array[i] = std::rand()%len + 1;
            if (duplicated[array[i]-1] == false)
            {
                duplicated[array[i]-1] = true;
                break;
            }
        } while (true);
    }
    delete []duplicated;
}
void Permutation3(int* array, int len)
{
    for (int i = 0; i < len; i++)
    {
        array[i] = i+1;
    }
    std::srand(std::time(0));
    for (int i = 0; i < len; i++)
    {
        int rand = std::rand()%len;
        std::swap(array[i], array[rand]);
    }
}
int main(int argc, char** argv)
{
    int count = atoi(argv[1]);
    int perm = atoi(argv[2]);
    printf("array size:%d; permutation:%d\n", count, perm);
    int* array = NULL;
    array = new int[count];
    if (perm == 1)
    {
        Permutation1(array, count);
    }
    else if (perm == 2)
    {
        Permutation2(array, count);
    }
    else if (perm == 3)
    {
        Permutation3(array, count);
    }
    printf("Permutation:");
    for (int i = 0; i < count; i++)
    {
//        printf("%d ", array[i]);
    }
    printf("\n");
    delete []array;
    return 0;
};
