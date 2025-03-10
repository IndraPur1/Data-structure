/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : Indra Purwanto*/
/* Tanggal   : 20 Spetember 2024*/
/***********************************/

#include <stdio.h>
#include "tstack.c"
#include "tstack.h"
#include "boolean.h"

int main() 
{	/* kamus main */
	Tstack A; // variabel A bertipe tStack
	
	/*algoritma*/
	// inisialisasi dan print matriks//
	printf("--inisialisasi stacks--\n");
	top(A) = 11;
	createStack(&A);
	printStack(A);
	viewStack(A);
	printf("\n");

	// inisialisasi PushN//
	int N;
	printf("--inisialisasi PushN stacks--\n");
	Tstack B;
	createStack(&B);
	printf("berapa stacks yang mau diisi: ");
	scanf("%d", &N);
	pushN(&B, N);
	viewStack(B);

	// // inisialisasi Pus/Pop//
	char E;
	printf("--inisialisasi push/pop stacks--\n");
	Tstack C;
	createStack(&C);
	printf("push\n");
	printf("masukan char : ");
	scanf("%c", &E);
	push(&C, E);
	viewStack(C);
	printf("\n");
	printf("pop \n");
	char X;
	pop(&C, &X);
	printf("\n");
	printStack(C);

	// // inisialisasi PusBabel1//
	char E;
	printf("--inisialisasi PushBabel--\n");
	Tstack D;
	createStack(&D);
	push(&D, '1');
	push(&D, '2');
	push(&D, '3');
	push(&D, '4');
	push(&D, '5');
	push(&D, '6');
	push(&D, '7');
	push(&D, '8');
	push(&D, '9');
	push(&D, '0');
	push(&D, '1');
	viewStack(D);
	printf("\n");
	printf("PushBabel\n");
	printf("masukan char : ");
	scanf("%c", &E);
	pushBabel1(&D, E);
	printStack(D);

	// inisialisasi PusZuma//
	char E;
	printf("--inisialisasi PushZuma--\n");
	Tstack F;
	createStack(&F);
	push(&F, '1');
	push(&F, '2');
	push(&F, '3');
	push(&F, 'E');
	viewStack(F);
	printf("\n");
	printf("PushZuma\n");
	printf("masukan char : ");
	scanf("%c", &E);
	pushZum(&F, E);
	viewStack(F);
	return 0;
}
