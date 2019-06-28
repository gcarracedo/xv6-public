#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
//Travis no acepta estas por alguna razon
#include "stdio.h"
#include "sys/mman.h"
#include "stdlib.h"
#include "string.h"
#include "sys/types.h"
#include "unistd.h"
//Travis no acepta estas por alguna razon
//I give up
#define MEM_LENGHT 4000000000
//4gb de memoria

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

int
sys_memorytransform(void)
{
 unsigned long vaddr, pid, paddr = 0, offset;
 char *x;

 x = malloc(MEM_LENGHT);
 if (!x){
    printf("Error en Malloc");
    return -1;
 }
 memset(x, 1, MEM_LENGHT);
 mlock(x, MEM_LENGHT);
//intente usar un codigo similar al de esta pagina
//pero no soy capaz de comprenderlo
//http://eastrivervillage.com/Virtual-memory-to-Physical-memory/
//I give up



 return 0;

}
