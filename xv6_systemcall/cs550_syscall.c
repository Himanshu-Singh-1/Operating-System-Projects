#include "types.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "x86.h"
#include "syscall.h"
#include "date.h"
//#include "string.h"  //t

int sys_date(void)
{

struct rtcdate *r;
//cprintf("\n Reached date sytem call");
if(argptr(0, (void*)&r, sizeof(&r)) < 0)
    return -1; 
cmostime(r);
return 0;
}

int sys_aaICO(void)
{
//cprintf("\n**Reached aaico function**\n");
return 413;
}

int sys_RwwzQ(void)
{ 
return 523;
}





//all linear functions

//all linear functions
//int sys_aaICO(void)
//{
// return 413;}
//int sys_RwwzQ(void)
//{
//return 523;}
int sys_vPlkH(void)
{
 return 485;}
int sys_nAAkW(void)
{
 return 434;}
int sys_V4XHy(void)
{
 return 419;}
int sys_DIJ1J(void)
{
 return 338;}
int sys_uby8E(void)
{
 return 461;}
int sys_HrYmw(void)
{
 return 503;}
int sys_It9GD(void)
{
 return 385;}
int sys_kBqyL(void)
{
 return 483;}
int sys_uFvqh(void)
{
 return 522;}
int sys_kCOzo(void)
{
 return 486;}
int sys_BdglP(void)
{
 return 457;}
int sys_vsu9T(void){
 return 491;}
int sys_GhENr(void){
 return 436;}
int sys_cNlc2(void){
 return 434;}
int sys_AUX47(void){
 return 345;}
int sys_OJjUF(void){
 return 414;}
int sys_rwbCB(void){
 return 464;}
int sys_U63O6(void){
 return 323;}
int sys_buYn9(void){
 return 471;}
int sys_pvRfc(void){
 return 513;}
int sys_IbIsf(void){
 return 461;}
int sys_RH7FR(void){
 return 361;}
int sys_u5Ncu(void){
 return 464;}
int sys_vA3kF(void){
 return 411;}
int sys_ZyJFv(void){
 return 473;}
int sys_a_kuY(void){
 return 505;}
int sys_DF2ak(void){
 return 392;}
int sys_bifXB(void){
 return 459;}
int sys_OpuAe(void){
 return 474;}
int sys_DNUxN(void){
 return 429;}
int sys_ancIB(void){
 return 445;}
int sys_fiuCL(void){
 return 467;}
int sys_f85c4(void){
 return 362;}
int sys_pKQyj(void){
 return 495;}
int sys_sPh9f(void){
 return 458;}
int sys_aSdV9(void){
 return 423;}
int sys_hEwee(void){
 return 494;}
int sys_m7xSo(void){
 return 478;}
int sys_lpg5S(void){
 return 459;}
int sys_J7GF1(void){
 return 319;}
int sys_GYEGy(void){
 return 421;}
int sys_UHuoA(void){
 return 450;}
int sys_lfawm(void){
 return 535;}
int sys_SkxVQ(void){
 return 477;}
int sys_m7dk_(void){
 return 466;}
int sys_C2FTH(void){
 return 343;}
int sys_ZFvwG(void){
 return 468;}
int sys_xMznMiMbd2ASBAopjUBD(void){
 return 1763;}



typedef struct
{
 char *name;
 int (* funct)();
}linear_functions;



linear_functions lfunc[] = {
	{"aaICO",&sys_aaICO},
	{"RwwzQ",&sys_RwwzQ}, 
	{"vPlkH",&sys_vPlkH},
	{"nAAkW",&sys_nAAkW}, 
	{"V4XHy",&sys_V4XHy}, 
	{"DIJ1J",&sys_DIJ1J}, 
	{"uby8E",&sys_uby8E},
	{"HrYmw",&sys_HrYmw}, 
	{"It9GD",&sys_It9GD}, 
	{"kBqyL",&sys_kBqyL},
	{"uFvqh",&sys_uFvqh},
	{"kCOzo",&sys_kCOzo},
	{"BdglP",&sys_BdglP},
	{"vsu9T",&sys_vsu9T},
	{"GhENr",&sys_GhENr},
	{"cNlc2",&sys_cNlc2},
	{"AUX47",&sys_AUX47},
	{"OJjUF",&sys_OJjUF},
	{"rwbCB",&sys_rwbCB},
	{"U63O6",&sys_U63O6},
	{"buYn9",&sys_buYn9},
	{"pvRfc",&sys_pvRfc},
	{"IbIsf",&sys_IbIsf},
	{"RH7FR",&sys_RH7FR},
	{"u5Ncu",&sys_u5Ncu},
	{"vA3kF",&sys_vA3kF},
	{"ZyJFv",&sys_ZyJFv},
	{"a_kuY",&sys_a_kuY},
	{"DF2ak",&sys_DF2ak},
	{"bifXB",&sys_bifXB},
	{"OpuAe",&sys_OpuAe},
	{"DNUxN",&sys_DNUxN},
	{"ancIB",&sys_ancIB},
	{"fiuCL",&sys_fiuCL},
	{"f85c4",&sys_f85c4},
	{"pKQyj",&sys_pKQyj},
	{"sPh9f",&sys_sPh9f},
	{"aSdV9",&sys_aSdV9},
	{"hEwee",&sys_hEwee},
	{"m7xSo",&sys_m7xSo},
	{"lpg5S",&sys_lpg5S},
	{"J7GF1",&sys_J7GF1},
	{"GYEGy",&sys_GYEGy},
	{"UHuoA",&sys_UHuoA},
	{"lfawm",&sys_lfawm},
	{"SkxVQ",&sys_SkxVQ},
	{"m7dk_",&sys_m7dk_},
	{"C2FTH",&sys_C2FTH},
	{"ZFvwG",&sys_ZFvwG},
	{"xMznMiMbd2ASBAopjUBD",&sys_xMznMiMbd2ASBAopjUBD}
};



int linear_search(char *name)
{
//cprintf("\n**Inside linear search name: %s**\n",name);
int i=0,num=0,tmp=0,tmpret=1;
for(i=0;i<50;i++)
{

tmp = strlen(lfunc[i].name) - strlen(name);
if(tmp!=0)
continue;
tmp = strlen(name);
tmpret = strncmp(lfunc[i].name,name,tmp);
if(tmpret==0)
{
num=lfunc[i].funct();
break;
}
}
if(tmpret!=0)
	return -1;
//cprintf("\n\n** loops: %d",count);
return num;
}



//hash functions:
int sys_ajJ2rUS36Ds7gCvYhWvRMQ4cM(void){
 return 2106;}
int sys_lcQQ6(void){
 return 423;}
int sys_tG0cd(void){
 return 434;}
int sys_BQaye(void){
 return 466;}
int sys_vRL61(void){
 return 379;}
int sys_BfPAS(void){
 return 396;}
int sys_VWqcU(void){
 return 470;}
int sys_rNV_x(void){
 return 493;}
int sys_m9TVP(void){
 return 416;}
int sys_dN3rB(void){
 return 409;}
int sys_NEorw(void){
 return 491;}
int sys_iE45d(void){
 return 379;}
int sys_VFGu_(void){
 return 439;}
int sys_zqf7e(void){
 return 493;}
int sys_Ayr5H(void){
 return 425;}
int sys_y7dVW(void){
 return 449;}
int sys_RhaR2(void){
 return 415;}
int sys_GUT_3(void){
 return 386;}
int sys_mtwGL(void){
 return 491;}
int sys_Rz1qA(void){
 return 431;}
int sys_BDslj(void){
 return 463;}
int sys_DYcHF(void){
 return 398;}
int sys_XVI4N(void){
 return 377;}
int sys_RknTi(void){
 return 488;}
int sys_eraAb(void){
 return 475;}
int sys_K7plu(void){
 return 467;}
int sys_UPjQy(void){
 return 473;}
int sys_uFjK1(void){
 return 417;}
int sys_E8Jj9(void){
 return 362;}
int sys_viJpE(void){
 return 478;}
int sys_y8hmu(void){
 return 507;}
int sys_GhPNY(void){
 return 422;}
int sys_mEymb(void){
 return 506;}
int sys_UAi7z(void){
 return 432;}
int sys_g3fke(void){
 return 464;}
int sys_spiXC(void){
 return 487;}
int sys_sCY6P(void){
 return 405;}
int sys_lQ5p2(void){
 return 404;}
int sys_yFLZV(void){
 return 443;}
int sys_y7NBZ(void){
 return 410;}
int sys_JS_81(void){
 return 357;}
int sys_pHGgA(void){
 return 423;}
int sys_D3BT2(void){
 return 319;}
int sys_LYSUb(void){
 return 431;}
int sys_UHDeS(void){
 return 409;}
int sys_zQQm5(void){
 return 446;}
int sys_T4IiC(void){
 return 381;}
int sys_ZnCtG(void){
 return 454;}
int sys_TBDYx(void){
 return 427;}
int sys_k_jNM(void){
 return 463;}

//hash functions structure:
 
typedef struct
{
char *name;
int (* funct)();
}hash_functions;

hash_functions hfunction[] = {
	
{"ajJ2rUS36Ds7gCvYhWvRMQ4cM",&sys_ajJ2rUS36Ds7gCvYhWvRMQ4cM},	
{"lcQQ6",&sys_lcQQ6},
{"tG0cd",&sys_tG0cd},
{"BQaye",&sys_BQaye},
{"vRL61",&sys_vRL61},
{"BfPAS",&sys_BfPAS},
{"VWqcU",&sys_VWqcU},
{"rNV_x",&sys_rNV_x},
{"m9TVP",&sys_m9TVP},
{"dN3rB",&sys_dN3rB},
{"NEorw",&sys_NEorw},
{"iE45d",&sys_iE45d},
{"VFGu_",&sys_VFGu_},
{"zqf7e",&sys_zqf7e},
{"Ayr5H",&sys_Ayr5H},
{"y7dVW",&sys_y7dVW},
{"RhaR2",&sys_RhaR2},
{"GUT_3",&sys_GUT_3},
{"mtwGL",&sys_mtwGL},
{"Rz1qA",&sys_Rz1qA},
{"BDslj",&sys_BDslj},
{"DYcHF",&sys_DYcHF},
{"XVI4N",&sys_XVI4N},
{"RknTi",&sys_RknTi},
{"eraAb",&sys_eraAb},
{"K7plu",&sys_K7plu},
{"UPjQy",&sys_UPjQy},
{"uFjK1",&sys_uFjK1},
{"E8Jj9",&sys_E8Jj9},
{"viJpE",&sys_viJpE},
{"y8hmu",&sys_y8hmu},
{"GhPNY",&sys_GhPNY},
{"mEymb",&sys_mEymb},
{"UAi7z",&sys_UAi7z},
{"g3fke",&sys_g3fke},
{"spiXC",&sys_spiXC},
{"sCY6P",&sys_sCY6P},
{"lQ5p2",&sys_lQ5p2},
{"yFLZV",&sys_yFLZV},
{"y7NBZ",&sys_y7NBZ},
{"JS_81",&sys_JS_81},
{"pHGgA",&sys_pHGgA},
{"D3BT2",&sys_D3BT2},
{"LYSUb",&sys_LYSUb},
{"UHDeS",&sys_UHDeS},
{"zQQm5",&sys_zQQm5},
{"T4IiC",&sys_T4IiC},
{"ZnCtG",&sys_ZnCtG},
{"TBDYx",&sys_TBDYx},
{"k_jNM",&sys_k_jNM}
};


//using hashtable:


int retascii(char *s)
{
int ret =0,i=0;
char c=s[0];
while(c!='\0'){
ret = ret + s[i];
c =s[i];
i++;
}
return ret;
}



struct node{
int index;
hash_functions hfunc; 
};

struct node hashtable[51];

int ini_hashtable()
{
int i=0,index=1;
//int count=0;
//cprintf("\n**Inside initialize hash table**\n");
for(i=0;i<50;i++)
{
index = retascii(hfunction[i].name) % 50 + 1;
//cprintf("\n**Inside intialize hash table: index: %d**\n",index);
if(hashtable[index].index ==0)
	{
	hashtable[index].hfunc.name = hfunction[i].name;
	hashtable[index].hfunc.funct = hfunction[i].funct;
	hashtable[index].index = index;
	//if(index==0)
	//hashtable[0].index = 100;
	}
	
else
	{
		//count = index;
	while(hashtable[index].index!=0)
	{
	//cprintf("\n**Inside intialize hash table inside else: index: %d**\n",index);
	index++;
	if(index>50)
		index =1;
	}
	hashtable[index].hfunc.name = hfunction[i].name;
	hashtable[index].hfunc.funct = hfunction[i].funct;
	
	hashtable[index].index = index;
	
	//count = index-count;
	//if(count!=0)
	//cprintf("\n** for function: %s count collision is: %d  **\n",hfunction[i].name,count);
	}
//cprintf("\n**Inside intialize hash table: index: %d**\n",index);
//cprintf("\n** for function: %s index: %d**\n",hashtable[index].hfunc.name,hashtable[index].index);
}
//hashtable[0].index = 0;
//cprintf("\n\n** first function inside hashtable: %s    **\n\n",hashtable[0].hfunc.name);
return 0;
}



int hashcall(char *name)
{
	int index =0,tmp=0,var=1,count=1;
	index = retascii(name)%50 + 1;
	tmp = strlen(name) - strlen(hashtable[index].hfunc.name);
	if(tmp==0)
	{
		var = strncmp(hashtable[index].hfunc.name,name,tmp);
		if(var==0)
			return (hashtable[index].hfunc.funct());
			
	}
	
	/*
	if(tmp<0)
		tmp = strlen(name);
	else
		tmp = strlen(hashtable[index].hfunc.name);
	var = strncmp(hashtable[index].hfunc.name,name,tmp);
	*/
	
	while(var!=0){
		if(count>=49)
			return -1;
    if(index>=49)
		index =0;
	tmp = strlen(name) - strlen(hashtable[index].hfunc.name);
	if(tmp!=0)
	{
		index++;
		count++;
		continue;
	}
	else
	{
		tmp = strlen(name);
	var = strncmp(hashtable[index].hfunc.name,name,tmp);
	index++;
	count++;
	}
	}
	index--;
	return (hashtable[index].hfunc.funct());
}



void 
cs550_syscall65(void)
{

int num=0;
char *str = (char *)proc->tf->eax;   //w
//cprintf("\n** inside cs550_syscall65 function string: %s**",(char *)proc->tf->eax);
//num = sys_aaICO();   --w
//testin lfunctions:
num = linear_search(str);      //w
//cprintf("\n** num return after linear search**: %d\n",num);

//ini_hashtable();   //t
//cprintf("\n** after initialize hashtable**\n");
//num = hashcall(str);
//cprintf("\n** num return atfer hashcall**: %d\n",num);
proc->tf->eax = num;
}

void 
cs550_syscall66(void)
{
int num=0;
char *str = (char *)proc->tf->eax;   //w
//cprintf("\n** inside cs550_syscall66 function string: %s**",(char *)proc->tf->eax);
num = hashcall(str);
//cprintf("\n** num return atfer hashcall**: %d\n",num);
proc->tf->eax = num;
}
