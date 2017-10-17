#ifdef CHANGED
#include "copyright.h"
#include "system.h"
#include "synchconsole.h"
#include "synch.h"
static Semaphore*readAvail;
static Semaphore*writeDone;
#ifdef CHANGED 
static Semaphore*mutexRead;
static Semaphore*mutexWrite;
#endif //CHANGED
static void ReadAvailHandler(void * arg)
{
  (void) arg; readAvail->V();
}
static void WriteDoneHandler(void * arg)
{
  (void) arg; writeDone->V();
}
SynchConsole::SynchConsole(const char * in, const char * out)
{
  readAvail = new Semaphore("read avail", 0);
  writeDone = new Semaphore("write done", 0);
  console = new Console (in , out , ReadAvailHandler, WriteDoneHandler,0);
 #ifdef CHANGED
  mutexRead = new Semaphore ("SynchGetString Semaphore",1);//Semaphore for reading 
  mutexWrite = new Semaphore ("SynchPutString Semaphore",1);//Semaphore for writting 
 #endif //CHANGED
    }
SynchConsole::~SynchConsole()
{
  delete console;
  delete writeDone;
  delete readAvail;
}
void SynchConsole::SynchPutChar(int ch)
{
	console->PutChar(ch);
        writeDone->P();
}
int SynchConsole::SynchGetChar()
{
  int ch;
  readAvail->P();
  ch=console->GetChar();
  return ch;
  
}

void SynchConsole::SynchPutString(const char s[])
{  mutexWrite->P();
  int i=0;
  while (s[i]!='\0')
    {
      SynchPutChar(s[i]);
      i++;
    }
  mutexWrite->V();	 
}

int SynchConsole::SynchGetString(char *s, int n)
{ mutexRead->P();
  char c;
  int i=0;
  while (i<n)
    {
      c=SynchGetChar ();
      s[i]=c;
      i++;
    }
  
  
  s[i]='\0'; 
  return i;
 mutexRead->V();
}

void SynchConsole::SynchPutInt(int n)
{
  char buffer[MAX_STRING_SIZE];
  snprintf (buffer,MAX_STRING_SIZE,"%d",n);
   synchconsole->SynchPutString(buffer);
   
}

void SynchConsole::SynchGetInt(int *n)
{ 
  char *buffer= (char*) malloc (MAX_STRING_SIZE);
  synchconsole->SynchGetString(buffer,MAX_STRING_SIZE);
  sscanf (buffer,"%d",n);
  free( buffer); // desallocation du buffer
}
#endif // CHANGED
