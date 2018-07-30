#include <stdio.h>
#include <kuso_dbg.h>

int main(void) {
	char *argv[] = {0};
	kuso_exec_inferior("./fuck",argv);
	return 0;
}
