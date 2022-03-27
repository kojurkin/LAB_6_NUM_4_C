#include <stdio.h>

int main()
{
    unsigned int n;
    int num = 1;
    int tmp;
    printf("Enter n ");
    scanf( "%d", &n);
    FILE* output = fopen("output.bin", "wb");
    for (int i = 0; i <= n; i++)
    {
        fwrite(&num, sizeof(int), 1, output);
        num = num * 2;
    }
    fclose(output);
    FILE* input = fopen("output.bin", "rb");
    int sizeoffile;
    //input.seekg(0, std::ios::beg);
    fseek(input, 0, SEEK_END);
    sizeoffile = ftell(input);
    fseek(input, 0, SEEK_SET);
    while (ftell(input) < sizeoffile)
    {
        fread(&num, sizeof(int), 1, input);
        printf("%d ", num);
    }
    fclose(input);
    return 0;
    return 0;
}
