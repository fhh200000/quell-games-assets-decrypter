#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    enc = fopen(argv[1],"r");
    dec = fopen(output_file_name,"wb");
    int i=0;
    while(!feof(enc)) {
        encrypted = fgetc(enc);
        if(encrypted==EOF) {
            break;
        }
        decrypted = encrypted^salt[i%6];
        fputc(decrypted,dec);
        i++;
    }
    fclose(enc);
    fclose(dec);
    free(output_file_name);
    return EXIT_SUCCESS;
}
