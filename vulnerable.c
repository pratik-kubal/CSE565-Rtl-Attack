/* vulnerable.c */
// 0x080484ab
#include <stdio.h>
#include <string.h> 
int main(int argc, char *argv[]) {
	char buffer[7];
	//FILE *input = fopen("badfile", "r");
	//fread(buffer, sizeof(char),31, input);
	strcpy(buffer,argv[1]);
	printf("Read from file: %s\n", buffer);
	return 0;
}
