#include <stdio.h>
#define MAXLEN 255
typedef struct {        //���崮�ṹ
	char ch[MAXLEN];
	int length;
}SString;

void Get_nextval(SString T, int nextval[]) {            //KMP�Ż��㷨����øĽ�������
	int i=1, j = 0;
	nextval[1] = 0;
	while (i < T.length) {
		if (j == 0 || T.ch[i] == T.ch[j]) {
			++i; ++j;
			if (T.ch[i] != T.ch[j]) nextval[i] = j;
			else nextval[i] = nextval[j];
		}
		else
			j = nextval[j];
	}
}

int Index_KMP(SString S, SString T,int nextval[]) {       //Ѱ��λ�ò�����
	int i = 1, j = 1;
	//int nextval[T.length + 1];
	//get_nextval(T, nextval);
	while (i <= S.length && j <= T.length) {
		if (j == 0 || S.ch[i] == T.ch[j]) {
			++i;
			++j;
		}
		else
			j = nextval[j];
	}
	if (j > T.length)
		return i - T.length;
	else 
		return 0;
}

void main() {
	SString S,T;                            //����S��ģʽ��T
	int nextval[MAXLEN] = { 0 };            //��ʼ��ģʽ�����飬Ϊ�������������
	int n,i=1;
	S.length = 0,T.length = 0;
	printf("%s", "�������������Ϊ��n=");
	scanf_s("%d", &n);
	for (i=1; i<= n; i++) {                 //ѭ����������
		while (getchar() != '\n');          //��ջ�����
		scanf_s("%c", &S.ch[i]);
		S.length += 1;
	}
	printf("\n");
	printf("%s", "������Ӵ�����Ϊ��n=");
	scanf_s("%d", &n); 
	for (i = 1; i <= n; i++) {                 //ѭ�������Ӵ�
		while (getchar() != '\n');       //��ջ�����
		scanf_s("%c", &T.ch[i]);
		T.length += 1;
	}
	printf("\n");
	Get_nextval(T, nextval);
	printf("%s%d\n","�Ӵ��������е�λ�ã�", Index_KMP(S,T,nextval));
	printf("%s", "����Ϊ��");
	for (i = 1; i <= S.length; i++)
		printf("%c\t", S.ch[i]);
	printf("\n");
	printf("%s", "ģʽ����");
	for (i = 1; i <= T.length; i++) 
		printf("%c\t", T.ch[i]);
	printf("\n");
	printf("%s", "��  �飺");
	for (i = 1; i <= T.length; i++) 
		printf("%d\t", nextval[i]);
	return 0;
}