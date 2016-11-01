#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void write_mem(int *mem,long addr,int val)
{
	*((int *)(mem + addr)) = val;//´æ´¢Æ÷Ğ´ÈëÊı¾İ
}
int read_mem(int *mem)
{
	return *((int*)mem);
}