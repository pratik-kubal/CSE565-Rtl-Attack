#include <stdio.h>
#include <string.h>
int main() {
	char *shell = getenv("MYSHELL");
	if (shell)
	printf("%x\n", shell);
	//sleep(120);
	return 0;
}
