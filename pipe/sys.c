#include <stdio.h>
#include <stdlib.h>

int
main()
{
	char cmd[] = "ls";
	int status;
	status = system(cmd);
	if (status != 0)
		fprintf(stderr, "fail to run '%s'\n", cmd);
}