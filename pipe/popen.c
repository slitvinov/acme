#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

static int
start(char *const command[], int *pid, int *infd, int *outfd)
{
	int p1[2], p2[2];

	if (!pid || !infd || !outfd)
		return 0;

	if (pipe(p1) == -1)
		goto err_pipe1;
	if (pipe(p2) == -1)
		goto err_pipe2;
	if ((*pid = fork()) == -1)
		goto err_fork;

	if (*pid) {
		*infd = p1[1];
		*outfd = p2[0];
		close(p1[0]);
		close(p2[1]);
		return 0;
	} else {
		dup2(p1[0], 0);
		dup2(p2[1], 1);
		close(p1[0]);
		close(p1[1]);
		close(p2[0]);
		close(p2[1]);
		execvp(*command, command);
		fprintf(stderr, "error running %s:", *command);
		abort();
	}

err_fork:
	close(p2[1]);
	close(p2[0]);
err_pipe2:
	close(p1[1]);
	close(p1[0]);
err_pipe1:
	return 1;
}


int main(int argc, char **argv) {
	int p, i, o, status;
	FILE *fo;
	char out[999];
	char py[] = "print 10 + 9";
	char *const cmd[] = {"python", NULL};

	status = start(cmd, &p, &i, &o);
	write(i, py, strlen(py) + 1);
	close(i);

	fo = fdopen(o, "r");
	fscanf(fo, "%s", out);	
	fprintf(stderr, "out: %s\n", out);

    	return 0;
}
