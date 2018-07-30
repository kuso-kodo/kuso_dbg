#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/ptrace.h>
#include <sys/wait.h>

#include <kuso_dbg.h>

static void setup_inferior(const char *path, char **argv);
static void attach_inferior(pid_t inferior_pid);

void kuso_exec_inferior(const char*  inferior_path,
                              char** argv) {
	pid_t result = fork();
	switch (result) {
    	case 0:
      		setup_inferior(inferior_path, argv);
      		break;
	case -1:
      		break;
    	default:
      		attach_inferior(result);
      		break;
	}
}

static void setup_inferior(const char *path, char **argv) {
	ptrace(PTRACE_TRACEME, 0, 0, 0);
	execv(path, argv);
}

static void attach_inferior(pid_t inferior_pid) {
	for(;;) {
		int status;
		waitpid(inferior_pid, &status, 0);

		if (WIFSTOPPED(status) && WSTOPSIG(status) == SIGTRAP) {
			puts("SIGTRAP Found...\n");
			ptrace(PTRACE_CONT, inferior_pid, 0, 0);
		} else if (WIFEXITED(status)) {
			puts("Inferior exited...\n");
			exit(0);
		}
	}
}
