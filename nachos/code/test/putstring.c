#include "syscall.h"


void print(char *s){
#if 1
 PutString(s);
#endif
}

int main(){
	
	print("Hello I'm PutString!\0"); 
        //Exit(0);
	
}
