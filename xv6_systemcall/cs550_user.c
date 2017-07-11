#include "types.h"
#include "stat.h"
#include "user.h"
#include "date.h"
int
main(void)
{
struct rtcdate r;
int num=0,time=0,i=0,time1=0,tmp=0;
//printf(1,"\ncs550_user main enter function name:\n");
if(date(&r))
{
printf(2,"failed");
exit();
}

printf(1,"Syscall date:\n year: %d  month: %d day: %d\n",r.year,r.month,r.day);

time=uptime();
for(i=0;i<1000000;i++)
{
num = getpid();
}
time1=uptime();
tmp = time1-time;
tmp = tmp*10;
printf(1,"\n\nSyscall pid UPTIME: %d\n\n",tmp);



time = uptime();
//printf(1,"\n*Before aaICO*\n");
for(i=0;i<1000000;i++)
{
num = aaICO();
}
time1 = uptime();
tmp = (time1-time)*10;
printf(1,"\nLinear Search SYSCALL65: aaICO\nreturned value:* %d\nUPTIME: %d\n",num,tmp);


//printf(1,"\n*Before xMznMiMbd2ASBAopjUBD*\n");
time=uptime();
for(i=0;i<1000000;i++)
{
num = xMznMiMbd2ASBAopjUBD();
}
time1=uptime();
tmp = time1-time;
tmp = tmp*10;
printf(1,"\nLinear Search SYSCALL65: xMznMiMbd2ASBAopjUBD\nreturned value:%d\nUPTIME: %d\n",num,tmp);



time = uptime();
//printf(1,"\n*Before  lQ5p2*\n");
for(i=0;i<1000000;i++)
{
num =  BfPAS();
}
time1 = uptime();
tmp = (time1-time)*10;
printf(1,"\nHashing SYSCALL66: BfPAS\nReturned Value: %d\nUPTIME: %d\n",num,tmp);


time = uptime();
//printf(1,"\n*Before dN3rB    *\n");
for(i=0;i<1000000;i++)
{
num = dN3rB();
}
time1 = uptime();
tmp = (time1-time)*10;
printf(1,"\nHashing SYSCALL66:dN3rB \nReturned Value: %d\nUPTIME: %d\n",num,tmp);

char *p = "himanshu";
int rv;
asm volatile("movl %0, %%eax" : : "rm" (p));
asm volatile("int $65" : :);
asm volatile("movl %%eax, %0" : "=rm" (rv) : );

printf(1,"\nLinear Bad addresss value: %d \n",rv);

asm volatile("movl %0, %%eax" : : "rm" (p));
asm volatile("int $66" : :);
asm volatile("movl %%eax, %0" : "=rm" (rv) : );
printf(1,"\nHashTable Bad addresss value: %d\n ",rv);

exit();


}
