#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	printf("helloworld(pid:%d)\n", (int) getpid());
	int rc = fork();
	if (rc < 0) { // fork failed;exit
		fprintf(stderr, "fork failed\n");
		exit(1);
	} elseif (rc == 0) { // child (newprocess)
		printf("hello,I am child (pid:%d)\n", (int)getpid());
		char *myargs[3];
		myargs[0] = strdup("wc"); // program: "wc"(word count)
		myargs[1] = strdup("p3.c"); // argument:file to count
		myargs[2] = NULL; // marks endof array
		execvp(myargs[0], myargs); // runs wordcount
		printf("this shouldn’t printout");
	} else { // parentgoes down thispath (main)
		int wc = wait(NULL);
		printf("hello,I am parent of%d (wc:%d)(pid:%d)\n", rc, wc, (int) getpid());
	}
	return 0;
}
