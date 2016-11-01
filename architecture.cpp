// architecture.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "memory.h"
#include "refine_num.h"
#include "reg.h"

int code(int *memory)
{
	printf("����RISCָ��,����end����\n");
	char Instruction[20];
	int Count=0;//����д�����ʼλ��
	for(;;)
	{
		gets(Instruction);
		char *input1;
		char *input2;
		char *input3;
		char *input4;
		if(strcmp(Instruction,"end")==0)
			break;//�������
		else
		{
			const char *delimer=" ,";
			input1=strtok(Instruction,delimer);
			input2=strtok(NULL,delimer);
			input3=strtok(NULL,delimer);
			char *p;p=strtok(NULL,delimer);
			if(p==NULL)
				input4="  ";
			else
				input4=p;   //�������������������4�����롣���б���
		}

		int imm,opcode,rs1,rs2,funct3,rd,shamt,funct7;
		if(strcmp(input1,"LUI")==0)
		{
			opcode=0x37;//��7λ�洢opcode��,0110111
			rd=refine_num(input2); //Ŀ��Ĵ�����
			imm=atoi(input3);
			int tmp=opcode|(rd<<7)|(imm<<12);
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"AUIPC")==0)
		{
			opcode=0x17;//0010111
			rd=refine_num(input2);//Ŀ��Ĵ���
			imm=atoi(input3);//������
			int tmp=opcode|(rd<<7)|(imm<<12);
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"JAL")==0)
		{
			opcode=0x6f;//1101111
			rd=refine_num(input2);
			imm=atoi(input3);
			int tmp=opcode|(rd<<7)|(imm<<12);
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"JALR")==0)
		{
			opcode=0x67;//1100111
			rd=refine_num(input2);
			funct3=0;
			rs1=refine_num(input3);
			imm=atoi(input4);
			int tmp=opcode|(rd<<7)|(funct3<<12)|(imm<<20);
			write_mem(memory,Count,tmp);
		}
		/***********************ָ����תBϵ�нṹ����****************************/
		else if(strcmp(input1,"BEQ")==0)
		{
			opcode=0x63;//1100111
			funct3=0;
			rs1=refine_num(input2);
			rs2=refine_num(input3);
			imm=atoi(input4);
			int tmp1=opcode|funct3<<12|rs1<<15|rs2<<20;
			int tmp2=((imm>>10)&0x1)<<7|(imm&0xf)<<8|((imm>>4)&0x3f)<<25|((imm>>11)&0x1)<<31;
			int tmp=tmp1|tmp2;
			write_mem(memory,Count,tmp);
		}	
		//printf("%d\n",*((int *)(memory + Count)));
		else if(strcmp(input1,"BNE")==0)
		{
			opcode=0x63;
			funct3=1;
			rs1=refine_num(input2);
			rs2=refine_num(input3);
			imm=atoi(input4);
			int tmp1=opcode|funct3<<12|rs1<<15|rs2<<20;
			int tmp2=((imm>>10)&0x1)<<7|(imm&0xf)<<8|((imm>>4)&0x3f)<<25|((imm>>11)&0x1)<<31;
			int tmp=tmp1|tmp2;
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"BLT")==0)
		{
			opcode=0x63;
			funct3=4;
			rs1=refine_num(input2);
			rs2=refine_num(input3);
			imm=atoi(input4);
			int tmp1=opcode|funct3<<12|rs1<<15|rs2<<20;
			int tmp2=((imm>>10)&0x1)<<7|(imm&0xf)<<8|((imm>>4)&0x3f)<<25|((imm>>11)&0x1)<<31;
			int tmp=tmp1|tmp2;
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"BGE")==0)
		{
			opcode=0x63;
			funct3=5;
			rs1=refine_num(input2);
			rs2=refine_num(input3);
			imm=atoi(input4);
			int tmp1=opcode|funct3<<12|rs1<<15|rs2<<20;
			int tmp2=((imm>>10)&0x1)<<7|(imm&0xf)<<8|((imm>>4)&0x3f)<<25|((imm>>11)&0x1)<<31;
			int tmp=tmp1|tmp2;
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"BLTU")==0)
		{
			opcode=0x63;
			funct3=6;
			rs1=refine_num(input2);
			rs2=refine_num(input3);
			imm=atoi(input4);
			int tmp1=opcode|funct3<<12|rs1<<15|rs2<<20;
			int tmp2=((imm>>10)&0x1)<<7|(imm&0xf)<<8|((imm>>4)&0x3f)<<25|((imm>>11)&0x1)<<31;
			int tmp=tmp1|tmp2;
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"BGEU")==0)
		{
			opcode=0x63;
			funct3=7;
			rs1=refine_num(input2);
			rs2=refine_num(input3);
			imm=atoi(input4);
			int tmp1=opcode|funct3<<12|rs1<<15|rs2<<20;
			int tmp2=((imm>>10)&0x1)<<7|(imm&0xf)<<8|((imm>>4)&0x3f)<<25|((imm>>11)&0x1)<<31;
			int tmp=tmp1|tmp2;
			write_mem(memory,Count,tmp);
		}
		/***********************************************************************************/
		else if(strcmp(input1,"LB")==0)
		{
			opcode=0x3;
			funct3=0;
			rd=refine_num(input2);
			rs1=refine_num(input3);
			imm=atoi(input4);
			int tmp=opcode|(rd<<7)|(funct3<<12)|(rs1<<15)|(imm<<20);
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"LH")==0)
		{
			opcode=0x3;
			funct3=1;
			rd=refine_num(input2);
			rs1=refine_num(input3);
			imm=atoi(input4);
			int tmp=opcode|(rd<<7)|(funct3<<12)|(rs1<<15)|(imm<<20);
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"LW")==0)
		{
			opcode=0x3;
			funct3=2;
			rd=refine_num(input2);
			rs1=refine_num(input3);
			imm=atoi(input4);
			int tmp=opcode|(rd<<7)|(funct3<<12)|(rs1<<15)|(imm<<20);
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"LBU")==0)
		{
			opcode=0x3;
			funct3=4;
			rd=refine_num(input2);
			rs1=refine_num(input3);
			imm=atoi(input4);
			int tmp=opcode|(rd<<7)|(funct3<<12)|(rs1<<15)|(imm<<20);
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"LHU")==0)
		{
			opcode=0x3;
			funct3=5;
			rd=refine_num(input2);
			rs1=refine_num(input3);
			imm=atoi(input4);
			int tmp=opcode|(rd<<7)|(funct3<<12)|(rs1<<15)|(imm<<20);
			write_mem(memory,Count,tmp);
		}

		/************************�Ĵ���д����**************************/
		else if(strcmp(input1,"SB")==0)
		{
			opcode=0x23;
			funct3=0;
			rs1=refine_num(input2);
			rs2=refine_num(input3);
			imm=atoi(input4);
			int tmp1=imm&0x1f;
			int tmp2=(imm>>5)&0x7f;
			int tmp=opcode|(tmp1<<7)|(funct3<<12)|(rs1<<15)|(rs2<<20)|(tmp2<<25);
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"SH")==0)
		{
			opcode=0x23;
			funct3=1;
			rs1=refine_num(input2);
			rs2=refine_num(input3);
			imm=atoi(input4);
			int tmp1=imm&0x1f;
			int tmp2=(imm>>5)&0x7f;
			int tmp=opcode|(tmp1<<7)|(funct3<<12)|(rs1<<15)|(rs2<<20)|(tmp2<<25);
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"SW")==0)
		{
			opcode=0x23;
			funct3=2;
			rs1=refine_num(input2);
			rs2=refine_num(input3);
			imm=atoi(input4);
			int tmp1=imm&0x1f;
			int tmp2=(imm>>5)&0x7f;
			int tmp=opcode|(tmp1<<7)|(funct3<<12)|(rs1<<15)|(rs2<<20)|(tmp2<<25);
			write_mem(memory,Count,tmp);
		}
		/**********************���������*****************************/
		else if(strcmp(input1,"ADDI")==0)
		{
			opcode=0x13;
			funct3=0;
			rs1=refine_num(input3);
			rd=refine_num(input2);
			imm=atoi(input4);
			int tmp=opcode|(rd<<7)|(funct3<<12)|(rs1<<15)|(imm<<20);
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"SLTI")==0)
		{
			opcode=0x13;
			funct3=2;
			rs1=refine_num(input3);
			rd=refine_num(input2);
			imm=atoi(input4);
			int tmp=opcode|(rd<<7)|(funct3<<12)|(rs1<<15)|(imm<<20);
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"SLTIU")==0)
		{
			opcode=0x13;
			funct3=3;
			rs1=refine_num(input3);
			rd=refine_num(input2);
			imm=atoi(input4);
			int tmp=opcode|(rd<<7)|(funct3<<12)|(rs1<<15)|(imm<<20);
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"XORI")==0)
		{
			opcode=0x13;
			funct3=4;
			rs1=refine_num(input3);
			rd=refine_num(input2);
			imm=atoi(input4);
			int tmp=opcode|(rd<<7)|(funct3<<12)|(rs1<<15)|(imm<<20);
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"ORI")==0)
		{
			opcode=0x13;
			funct3=6;
			rs1=refine_num(input3);
			rd=refine_num(input2);
			imm=atoi(input4);
			int tmp=opcode|(rd<<7)|(funct3<<12)|(rs1<<15)|(imm<<20);
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"ANDI")==0)
		{
			opcode=0x13;
			funct3=7;
			rs1=refine_num(input3);
			rd=refine_num(input2);
			imm=atoi(input4);
			int tmp=opcode|(rd<<7)|(funct3<<12)|(rs1<<15)|(imm<<20);
			write_mem(memory,Count,tmp);
		}
		/********************�߼�ָ��ı���*************************/
		else if(strcmp(input1,"SLLI")==0)
		{
			opcode=0x13;
			funct3=1;
			rd=refine_num(input2);
			rs1=refine_num(input3);
			shamt=atoi(input4);
			imm=0;
			int tmp=opcode|(rd<<7)|(funct3<<12)|(rs1<<15)|(shamt<<20)|(imm<<25);
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"SRLI")==0)
		{
			opcode=0x13;
			funct3=5;
			rd=refine_num(input2);
			rs1=refine_num(input3);
			shamt=atoi(input4);
			imm=0;
			int tmp=opcode|(rd<<7)|(funct3<<12)|(rs1<<15)|(shamt<<20)|(imm<<25);
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"SRAI")==0)
		{
			opcode=0x13;
			funct3=5;
			rd=refine_num(input2);
			rs1=refine_num(input3);
			shamt=atoi(input4);
			imm=32;
			int tmp=opcode|(rd<<7)|(funct3<<12)|(rs1<<15)|(shamt<<20)|(imm<<25);
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"ADD")==0)
		{
			opcode=0x33;
			funct3=0;
			rd=refine_num(input2);
			rs1=refine_num(input3);
			rs2=refine_num(input4);
			funct7=0;
			int tmp=opcode|(rd<<7)|(funct3<<12)|(rs1<<15)|(rs2<<20)|(funct7<<25);
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"SUB")==0)
		{
			opcode=0x33;
			funct3=0;
			rd=refine_num(input2);
			rs1=refine_num(input3);
			rs2=refine_num(input4);
			funct7=32;
			int tmp=opcode|(rd<<7)|(funct3<<12)|(rs1<<15)|(rs2<<20)|(funct7<<25);
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"SLL")==0)
		{
			opcode=0x33;
			funct3=1;
			rd=refine_num(input2);
			rs1=refine_num(input3);
			rs2=refine_num(input4);
			funct7=0;
			int tmp=opcode|(rd<<7)|(funct3<<12)|(rs1<<15)|(rs2<<20)|(funct7<<25);
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"SLT")==0)
		{
			opcode=0x33;
			funct3=2;
			rd=refine_num(input2);
			rs1=refine_num(input3);
			rs2=refine_num(input4);
			funct7=0;
			int tmp=opcode|(rd<<7)|(funct3<<12)|(rs1<<15)|(rs2<<20)|(funct7<<25);
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"SLTU")==0)
		{
			opcode=0x33;
			funct3=3;
			rd=refine_num(input2);
			rs1=refine_num(input3);
			rs2=refine_num(input4);
			funct7=0;
			int tmp=opcode|(rd<<7)|(funct3<<12)|(rs1<<15)|(rs2<<20)|(funct7<<25);
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"XOR")==0)
		{
			opcode=0x33;
			funct3=4;
			rd=refine_num(input2);
			rs1=refine_num(input3);
			rs2=refine_num(input4);
			funct7=0;
			int tmp=opcode|(rd<<7)|(funct3<<12)|(rs1<<15)|(rs2<<20)|(funct7<<25);
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"SRL")==0)
		{
			opcode=0x33;
			funct3=5;
			rd=refine_num(input2);
			rs1=refine_num(input3);
			rs2=refine_num(input4);
			funct7=0;
			int tmp=opcode|(rd<<7)|(funct3<<12)|(rs1<<15)|(rs2<<20)|(funct7<<25);
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"SRA")==0)
		{
			opcode=0x33;
			funct3=5;
			rd=refine_num(input2);
			rs1=refine_num(input3);
			rs2=refine_num(input4);
			funct7=32;
			int tmp=opcode|(rd<<7)|(funct3<<12)|(rs1<<15)|(rs2<<20)|(funct7<<25);
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"OR")==0)
		{
			opcode=0x33;
			funct3=6;
			rd=refine_num(input2);
			rs1=refine_num(input3);
			rs2=refine_num(input4);
			funct7=0;
			int tmp=opcode|(rd<<7)|(funct3<<12)|(rs1<<15)|(rs2<<20)|(funct7<<25);
			write_mem(memory,Count,tmp);
		}
		else if(strcmp(input1,"AND")==0)
		{
			opcode=0x33;
			funct3=7;
			rd=refine_num(input2);
			rs1=refine_num(input3);
			rs2=refine_num(input4);
			funct7=0;
			int tmp=opcode|(rd<<7)|(funct3<<12)|(rs1<<15)|(rs2<<20)|(funct7<<25);
			write_mem(memory,Count,tmp);
		}
		Count++;
	}
	return Count;
}

void Execution(int *reg,int *memory,int flag)
{
	int *pc;
	pc=memory;
	for (;;)
	{
		int *tmp;
		tmp=memory+flag;
		if(pc>=tmp)
			break;
		else
		{
			int Instruction=read_mem(pc);
			int rd,rs1,rs2,funct3,opcode,imm,shamt,funct7;
			opcode=Instruction&0x7f;//��ȡopcode
			if(opcode==0x37)//ִ��LUI����
			{
				rd=(Instruction>>7)&0x1f;
				imm=(Instruction>>12)&0xfffff;
				write_reg(reg,rd,imm);
				pc=pc+1;
			}
			else if(opcode==0x17)//ִ��AUIPC����
			{
				rd=(Instruction>>7)&0x1f;
				imm=(Instruction>>12)&0xfffff;
				write_reg(reg,rd,(int)(imm+pc));
				pc=pc+1;
			}
			else if(opcode==0x6f)//ִ��JALָ��
			{
				rd=(Instruction>>7)&0x1f;
				imm=Instruction>>12;
				write_reg(reg,rd,(int)(1+pc));
				pc=pc+imm;
			}
			else if(opcode==0x67)//ִ��JALRָ��
			{
				rd=(Instruction>>7)&0x1f;
				//rs1=(Instruction>>15)&0x1f;
				rs1=(int)pc;
				imm=Instruction>>20;
				write_reg(reg,rd,(int)(1+pc));
				//pc=(int*)(read_reg(reg,rs1)+imm);
				pc=(int*)(rs1+4*imm);
			}
			else if(opcode==0x63)//ִ��BEQ��һ��ָ��ָ��
			{
				rs1=(Instruction>>15)&0x1f;
				rs2=(Instruction>>20)&0x1f;
				funct3=(Instruction>>12)&0x7;
				imm=(Instruction>>20)&0x800|(Instruction<<3)&0x400|(Instruction>>21)&0x3f0|(Instruction>>8)&0xf;
				switch(funct3)
				{
					int i,j;
					i=read_reg(reg,rs1);
					j=read_reg(reg,rs2);
					case 0: //ִ��BEQ										
						if(i==j)
							pc=pc+imm;
						else
							pc=pc+1;
						break;
					
					case 1://ִ��BNE				
						if(i!=j)
							pc=pc+imm;
						else
							pc=pc+1;
						break;
					
					case 4://ִ��BLE				
						if(i<j)
							pc=pc+imm;
						else
							pc=pc+1;
						break;
					
					case 5://ִ��BGE				
						if(i>j)
							pc=pc+imm;
						else
							pc=pc+1;
						break;
					
					case 6://ִ��BLTU�����޷������Ĳ���				
						if((unsigned int)i<(unsigned int)j)
							pc=pc+imm;
						else
							pc=pc+1;
						break;
					
					case 7://ִ��BGEU�����޷������Ĳ���				
						if((unsigned int)i>(unsigned int)j)
							pc=pc+imm;
						else
							pc=pc+1;
						break;

					default:
						break;
				}				
			}
			/*����c�����У������Ѿ��̶�������Ĭ�ϴ�����һ����*/
			else if(opcode==0x3)//ָ��LOADϵ��ִ�д���
			{
				rd=(Instruction>>7)&0x1f;
				funct3=(Instruction>>12)&0x7;
				rs1=(Instruction>>15)&0x1f;
				imm=(Instruction>>20)&0xfff;
				int val=read_reg(reg,rs1+imm);
				switch(funct3)
				{
					case 0 :						
						write_reg(reg,rd,val);
						break;
					case 1 :
						write_reg(reg,rd,val);
						break;
					case 2 :
						write_reg(reg,rd,val);
						break;
					case 4 :
						write_reg(reg,rd,val);
						break;
					case 5 :
						write_reg(reg,rd,val);
						break;
					default :
						break;
				}
				pc=pc+1;
			}
			else if(opcode==0x23)//ִ��S��ָ��Ĵ���
			{
				rs1=(Instruction>>15)&0x1f;
				rs2=(Instruction>>20)&0x1f;
				funct3=(Instruction>>12)&0x7;
				imm=(Instruction>>7)&0x1f|(Instruction>>25)&0x7f;
				int val=read_reg(reg,rs2);
				switch(funct3)
				{
					case 0:
						write_reg(reg,rs1+imm,val);
						break;
					case 1:
						write_reg(reg,rs1+imm,val);
						break;
					case 2:
						write_reg(reg,rs1+imm,val);
						break;
					default:
						break;
				}
				pc=pc+1;
			}
			else if(opcode==0x13)//ִ��������ָ����룬����������
			{
				rd=(Instruction>>7)&0x1f;
				funct3=(Instruction>>12)&0x7;
				rs1=(Instruction>>15)&0x1f;
				imm=(Instruction>>20)&0xfff;
				int val=read_reg(reg,rs1);
				switch(funct3)
				{
					case 0:// ADDI
						write_reg(reg,rd,val+imm);
						break;
					case 2://SLTI
						if(val<imm)
							write_reg(reg,rd,1);
						else
							write_reg(reg,rd,0);
						break;
					case 3://SLTIU
						if((unsigned int)val<(unsigned int)imm)
							write_reg(reg,rd,1);
						else
							write_reg(reg,rd,0);
						break;
					case 4://XORI
						write_reg(reg,rd,val^imm);
						break;
					case 6://ORI
						write_reg(reg,rd,val|imm);
						break;
					case 7: //ANDI
						write_reg(reg,rd,val&imm);
						break;
					case 1://SLLI
						imm=(Instruction>>25)&0x7f;
						shamt=(Instruction>>20)&0x1f;
						write_reg(reg,rd,val<<shamt);
						break;
					case 5://SRLI��SRAI
						imm=(Instruction>>25)&0x7f;
						shamt=(Instruction>>20)&0x1f;
						if(imm==0)
							write_reg(reg,rd,(unsigned int)val>>shamt);//�߼����ƣ�ǿ��Ϊ�޷���������
						else if(imm==32)
							write_reg(reg,rd,val>>shamt);//�������ƣ���������ֱ���ƶ���:-D
						else 
							break;
						break;
					default:
						break;
				}
				pc=pc+1;
			}
			else if(opcode==0x33)
			{
				rd=(Instruction>>7)&0x1f;
				funct3=(Instruction>>12)&0x7;
				rs1=(Instruction>>15)&0x1f;
				rs2=(Instruction>>20)&0x1f;
				funct7=(Instruction>>25)&0x7f;
				int i,j;
				i=read_reg(reg,rs1);
				j=read_reg(reg,rs2);
				switch(funct3)
				{
					case 0:
						if(funct7==0)
							write_reg(reg,rd,i+j);
						else
							write_reg(reg,rd,i-j);
						break;
					case 1:
						write_reg(reg,rd,i<<j);
						break;
					case 2:
						if(i<j)
							write_reg(reg,rd,0);
						else
							write_reg(reg,rd,1);
						break;
					case 3:
						if((unsigned int)i<(unsigned int)j)
							write_reg(reg,rd,0);
						else
							write_reg(reg,rd,1);
						break;
					case 4:
						write_reg(reg,rd,i^j);
						break;
					case 5:
						if(funct7==0)
							write_reg(reg,rd,(unsigned int)i>>(unsigned int)j);
						else
							write_reg(reg,rd,i>>j);
						break;
					case 6:
						write_reg(reg,rd,i|j);
						break;
					case 7:
						write_reg(reg,rd,i&j);
						break;
					default:
						break;
				}
				pc=pc+1;
			}
		}
	}

}
int main(int argc, char const *argv[])
{
	int *memory;
	int *reg;
	int flag;//���������־λ
 	memory=(int*)malloc(sizeof(int)*10000);//��ų����memory
 	reg=(int*)malloc(sizeof(int)*32);//�Ĵ�������Χ��R0~R31
 	flag=code(memory);
 	Execution(reg,memory,flag);
	printf("%x",*(reg+1));
 	return 0;
}