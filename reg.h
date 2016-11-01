#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void write_reg(int *reg,long addr,int val)
{
	*((int *)(reg + addr)) = val;//´æ´¢Æ÷Ğ´ÈëÊı¾İ
}
int read_reg(int *reg,long addr)
{
	return *((int*)reg+addr);
}