#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int refine_num(char *p)//提取字符中的数字,没有做异常处理，必须保证输入正确。
{
	int num=0;
	while(*p!='\0')
	{
		if(*p>'0'&&*p<'9')
			break;
		p++;
	}
	if(*(p-1)=='-')
		num=-atoi(p);
	else
		num=atoi(p);
	return num;
}