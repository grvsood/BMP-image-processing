#include <stdio.h>
#include <stdlib.h>

int main(int argc , char * argv[])
{
    //ensure proper usage
    if(argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }
    
    char* infile = argv[1];
    
    FILE* inptr = fopen(infile, "r");
    if(inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n",infile);
        return 2;
    }
    
    FILE* outptr = NULL;
    int c = 0;
    
    unsigned char *buffer = malloc(512);
    
    while(fread(buffer,1,512,inptr) == 512)
    {
       if ((buffer[0] == 0xff) && 
           (buffer[1] == 0xd8) && 
           (buffer[2] == 0xff) && 
           ((buffer[3] & 0xf0) == 0xe0))
        {
            if(c != 0)
            {
                fclose(outptr);
            }
            
            char outfile[10];
            sprintf(outfile,"%03i.jpg",c);
            c++;
            
            outptr = fopen(outfile,"w");
            if(outptr == NULL)
            {
                fprintf(stderr,"Could not open %s.\n",outfile);
                return 3;
            }
            fwrite(buffer,1,512,outptr);
            
        }
        
        else if (outptr != NULL)
        {
            fwrite(buffer, 1, 512, outptr);
        }
    }
    fclose(outptr);
}