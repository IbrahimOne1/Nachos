#include "syscall.h"


void print(int n)
{
#if 1
 PutInt(n);
#endif
}

int main()
{
	print(1236); 
	PutChar('\n');
	Halt();
}
