#include <stdio.h>
#define MAXLEN 255
typedef struct {        //定义串结构
	char ch[MAXLEN];
	int length;
}SString;

void Get_nextval(SString T, int nextval[]) {            //KMP优化算法，获得改进的数组
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

int Index_KMP(SString S, SString T,int nextval[]) {       //寻找位置并返回
	int i = 1, j = 1;
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
	SString S,T;                            //主串S和模式串T
	int nextval[MAXLEN] = { 0 };            //初始化模式串数组，为了输出串内数据
	int n,i=1;
	S.length = 0,T.length = 0;
	printf("%s", "输入的主串长度为：n=");
	scanf_s("%d", &n);
	for (i=1; i<= n; i++) {                 //循环输入主串
		while (getchar() != '\n');          //清空缓存区
		scanf_s("%c", &S.ch[i]);
		S.length += 1;
	}
	printf("\n");
	printf("%s", "输入的子串长度为：n=");
	scanf_s("%d", &n); 
	for (i = 1; i <= n; i++) {                 //循环输入子串
		while (getchar() != '\n');       //清空缓存区
		scanf_s("%c", &T.ch[i]);
		T.length += 1;
	}
	printf("\n");
	Get_nextval(T, nextval);
	printf("%s%d\n","子串在主串中的位置：", Index_KMP(S,T,nextval));
	printf("%s", "主串为：");
	for (i = 1; i <= S.length; i++)
		printf("%c\t", S.ch[i]);
	printf("\n");
	printf("%s", "模式串：");
	for (i = 1; i <= T.length; i++) 
		printf("%c\t", T.ch[i]);
	printf("\n");
	printf("%s", "数  组：");
	for (i = 1; i <= T.length; i++) 
		printf("%d\t", nextval[i]);
	return 0;
}
