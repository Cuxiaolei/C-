//5. p���Ƴ˷���
//// p(2��16)���Ƴ˷���
#include "stdio.h"
int main() {
    int i, j, t, p;
    char d[] = "0123456789ABCDEF";

    printf("input p��");
    scanf("%d", &p);

    printf(" %d���Ƴ˷���\n", p);

//    for (i = 1; i <= p - 1; i++) {
//        for (j = 1; j <= i; j++) {
//            t = i * j;
//            printf("%c*%c=", d[j], d[i]);
//            if (t < p) {
//                printf(" %c  ", d[t]);
//            } else {
//                printf("%c%c  ", d[t / p], d[t % p]);
//            }
//        }
//        printf("\n");
//    }
	for(int i = 1; i <= p - 1; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			t = i * j;
			printf("%c*%c=", d[j], d[i]);
			if(t < p){
				printf(" %c  ", d[t]); 
			} else{
				printf("%c%c  ", d[t/p], d[t%p]);
			}
		}
		printf("\n");
	}
    return 0;
}
