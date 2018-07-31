#include <stdio.h>
#include <kuso_dbg.h>


int main(void) {
	// A useless test
	char *argv[] = { NULL };
	kuso_exec_inferior("./inferior/fuck", argv);
	puts("A sample test, done nothing.");
}
