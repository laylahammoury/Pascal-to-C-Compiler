//~~~~~~~~~ main.c ~~~~~~~~

#include "global.h"

int main(int argc, char* argv[])
{
    char* input;
    char* output;
    int i;
    if (argc >= 2)
    {
        input = argv[1];
        output = argv[2];
    }
    else
    {
        printf("The default file names are choosen\n");
        input = "input.txt";
        output = "output.txt";
    }

    ofptr = fopen(output, "w");
    ifptr = fopen(input, "r");

    init();
    parse();

    fclose(ifptr);
    fclose(ofptr);
    exit(0); /* successful termination */
    return 0;
}



