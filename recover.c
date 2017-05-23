#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE* fi = fopen("card.raw","r");
    if(fi == NULL)
    {
        printf("I can't open card!");
        return 1;
    }
    int c = 0;
    uint8_t buf[512];
    FILE* fo = NULL;
    char fName[8];
    fread(buf, 512, 1, fi);
    while(fread(buf, 512, 1, fi) > 0)
    {
        if(buf[0] == 0xff && buf[1] == 0xd8 && buf[2] == 0xff && (buf[3] == 0xe0 || buf[3] == 0xe1))
        {
            if(fo != NULL)
            {
                fclose(fo);
            }
            sprintf(fName, "%03d.jpg", c);
            fo = fopen(fName, "w");
            fwrite(buf, 512, 1, fo);
            c++;
        }else
        {
            if(fo != NULL)
            {
                fwrite(buf, 512, 1, fo);
            }
        }
    }
    if(fo != NULL)
    {
        fclose(fo);
    }
    fclose(fi);
    return 0;
}
