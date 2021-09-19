#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
int main(int argc,char** argv)
{
    const char* salt="fallen";
    FILE *enc,*dec;
    char encrypted,decrypted;
    if(argc!=2) {
        printf("Usage: %s input_file\n",argv[0]);
        return EXIT_FAILURE;
    }
    int input_file_name_length=strlen(argv[1]);
    char* output_file_name = malloc(input_file_name_length+5);
    strcpy(output_file_name,argv[1]);
    strcpy(output_file_name+input_file_name_length,".out");
    enc = fopen(argv[1],"rb");
    dec = fopen(output_file_name,"wb");
    if(enc == NULL)
    {
        fprintf(stderr,"Error:Open file failed.\n");
        return EXIT_FAILURE;
    }
    uint64_t file_length=0;
    fseek(enc,0,SEEK_END);
    file_length = ftell(enc);
    printf("size:%lld bytes.\n",file_length);
    fseek(enc,0,SEEK_SET);
    for(int i=0;i<file_length;i++) {
        encrypted = fgetc(enc);
        decrypted = encrypted^salt[i%6];
        fputc(decrypted,dec);
    }
    fclose(enc);
    fclose(dec);
    free(output_file_name);
    return EXIT_SUCCESS;
}
