#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int refine_num(char *p)//��ȡ�ַ��е�����,û�����쳣�������뱣֤������ȷ��
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