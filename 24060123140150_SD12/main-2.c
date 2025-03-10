/*Nama file:   main.c*/
/*Deskripsi:   aplikasi driver ADT list berkait dengan representasi fisik pointer*/
/*Tanggal  :   3 Desember 2024*/
/*Pembuat  :   Muhammad Azka Subhan & 24060123130086*/
#include <stdio.h>
#include <stdlib.h>
#include "pohon3.h"
#include "pohon3.c"

int main() {
	// Kamus
      bintree3 W;
      int T;
      List1 Asli, Tambahan, HasilConcat;
      List1 PrefixList, PosfixList, InfixList, A, B;

      // Algoritma
      W = Tree3(NIL, 'A', false,
          Tree3(NIL, 'B', false, NIL,
                Tree3(NIL, 'D', false, NIL, NIL)),
          Tree3(NIL, 'C', false,
                Tree3(NIL, 'E', false, NIL, NIL),
                Tree3(NIL, 'F', false, NIL, NIL)));


    printf("~PRINTDFS~\n");
    printDFS(W);
    printf("\n");
	printf("~PREDIKAT~");
	printf("~ISEMPTYTREE~n");
	printf("Apakah tree kosong : %d\n", IsEmptyTree(W));
	printf("\n");
	printf("~ISDAUN~\n");
	printf("Tree tidak kosong, anak kanan kiri kosong : %d\n", IsDaun(W));
	printf("\n");
	printf("~ISBINER~\n");
	printf("Tree tidak kosong, ada subtree kanan kiri : %d\n", IsBiner(W));
	printf("\n");
	printf("~ISUNERLEFT~\n");
	printf("Tree tidak kosong, hanya mempunyai subpohon kiri : %d\n", IsUnerLeft(W));
	printf("\n");
	printf("~ISUNERRIGHT~\n");
	printf("Tree tidak kosong, hanya mempunyai subpohon kanan : %d\n", IsUnerRight(W));
    printf("\n");
    printf("~PRINTPATHX~\n");
    printPathX(W,'B');
    printf("\n");
    printf("~PRINTPATHDAUN~\n");
    printPathDaunX(W, 'E');
    printf("\n");
    printf("~PRINTALLPATHS~\n");
    printAllPaths(W);
    printf("\n");
	printf("~NBELMTREE~\n");
	printf("Elemen dalam tree adalah : %d\n",NbElmTree(W));
	printf("\n\n");
	printf("~NBDAUN~\n");
	printf("Banyaknya daun dalam tree adalah : %d\n", NbDaun(W));
	printf("\n\n");
	printf("~MAX2~\n");
    printf("Nilai maksimum di pohon: %d\n", max2(1, 2));
	printf("\n");
	printf("~TINGGI~\n");
	printf("Tinggi pohon adalah : %d\n", Tinggi(W));
	printf("\n\n");
	printf("~LEVEL~\n");
    printf("Level tertinggi pada pohon: %d\n", Level(W));
	printf("\n");
	printf("~COUNTLEVELT~\n");
    T = 2; 
    printf("Jumlah node pada level %d: %d\n", T, CountLevelT(W, T));
	printf("\n");
	printf("~PRINTLEVEL~\n");
    printf("Node pada level %d: ", T);
    PrintLevel(W, T);
    printf("\n\n");
	printf("~PRINTBFS~\n");
    PrintBFS(W);
    printf("\n");
    CreateList(&A);
    CreateList(&B);
    InsertVLast(&A, '1');
    InsertVLast(&A, '2');
    InsertVLast(&B, '3');
    InsertVLast(&B, '4');
    PrintList(A);
    printf("\n");
    PrintList(B);
    printf("\n\n");
	printf("~PCONCAT~\n");
    pconcat(&A, B);
    printf("List setelah pconcat : ");
    PrintList(A);
    printf("\n\n");
	printf("FCONCAT\n");
    HasilConcat = Fconcat(A, B);
    printf("Hasil Fconcat : ");
    PrintList(HasilConcat);
    printf("\n\n");
	printf("~LINEARPREFIX~\n");
    PrefixList = LinearPrefix(W);
    PrintList(PrefixList);
    printf("\n\n");
	printf("~LINEARPOSFIX\n");
    PosfixList = LinearPosfix(W);
    PrintList(PosfixList);
    printf("\n\n");
	printf("~INFIXLIST~\n");
    InfixList = LinearInfix(W);
    PrintList(InfixList);
    printf("\n\n");
	printf("~LINEARBREADTHFS~\n");
    PrintList(LinearBreadthFS(W)); 
    return 0;
}