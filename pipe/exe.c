#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main()
{
	char cmd[] = "ls";
	int status;
	status = execlp("echo", "echo", "42", (char*)0);
	if (status != 0)
		fprintf(stderr, "fail to run");
}