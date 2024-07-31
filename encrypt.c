// define encryption key macro - add custom command to readme
// check arguments: file1
// create destination file
// read binary
// print new character else original

#include <stdio.h>
#include <ctype.h>

#define ENCYRPTION_KEY '/'
#define XOR ^

int main(int argc, char *argv[]) {
    if (argc != 2) {
        // print error invalid # of arguments
        fprintf(stderr, "Invalid number of argumetns");
        return -1;
    }

    FILE *input_fp, *output_fp;
    if ((input_fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Unable to open stream to input file");
        return -1;
    }
    if ((output_fp = fopen("encryptedfile", "wb")) == NULL) {
        fprintf(stderr, "Unable to open stream to output file");
        return -1;
    }

    // loop through characters from first file
    // encrypt

    int original_char, encrypted_char;
    while ((original_char = getc(input_fp)) != EOF) {
        encrypted_char = original_char XOR ENCYRPTION_KEY;
        if (isprint(encrypted_char)) {
            putc(encrypted_char, output_fp);
        } else {
            putc(original_char, output_fp);
        }
    }

}