#ifndef CLIB_H
#define CLIB_H

//��Ҫʵ�ֵĺ��� 
void VM_Exit();				//�˳���������� 
void VM_Debug(char* msg);	//���������ĵ�����Ϣ

//�����Ƿ��㿪�������������ĺ�
//ʵ�ּ��ݵĿ������������
#define EXIT VM_Exit()
#define DEBUG(msg) VM_Debug(msg) 

#endif
