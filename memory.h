#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void write_mem(int *mem,long addr,int val)
{
	*((int *)(mem + addr)) = val;//�洢��д������
}
int read_mem(int *mem)
{
	return *((int*)mem);
}