/*Nama file:   main.c*/
/*Deskripsi:   aplikasi driver ADT list berkait dengan representasi fisik pointer*/
/*Tanggal  :   09 Desember 2024*/
/*Pembuat  :   Indra Purwanto & 24060123140150*/
#include <stdio.h>
#include <stdlib.h>
#include "pohon3.h"
#include "pohon3.c"

int main() {
	// Kamus
      bintree3 W;
      int T;
      List1 Asli, Tambahan, HasilConcat;
      List1 PrefixList, PosfixList, InfixList;

      // Algoritma
      W = Tree3(NIL, 'A', false,
          Tree3(NIL, 'B', false, NIL,
                Tree3(NIL, 'D', false, NIL, NIL)),
          Tree3(NIL, 'C', false,
                Tree3(NIL, 'E', false, NIL, NIL),
                Tree3(NIL, 'F', false, NIL, NIL)));


      printf("\n------Print DFS------\n");
      printDFS(W);
      printf("\n");

	printf("\nPREDIKAT\n");
	printf("---------Is Empty Tree---------\n");
	printf("Tree kosong?  %d", IsEmptyTree(W));
	IsEmptyTree(W) ? printf("True\n") : printf("False\n");

	printf("\n---------Is Daun---------\n");
	printf("Tree tidak kosong, anak kanan kiri kosong? ");
	IsDaun(W) ? printf("True\n") : printf("False\n");

	printf("\n---------Is Biner---------\n");
	printf("Tree tidak kosong, ada subtree kanan kiri? ");
	IsBiner(W) ? printf("True\n") : printf("False\n");

	printf("\n---------Is Uner Left---------\n");
	printf("Tree tidak kosong, hanya mempunyai subpohon kiri? ");
	IsUnerLeft(W) ? printf("True\n") : printf("False\n");

	printf("\n---------Is Uner Right---------\n");
	printf("Tree tidak kosong, hanya mempunyai subpohon kanan? ");
	IsUnerRight(W) ? printf("True\n") : printf("False\n");
      printf("=========================\n\n");

	printf("PREDIKAT\n");
      printf("Print Path X = B\n");
      printPathX(W, 'B');
      printf("\n");

      printf("\nPrint Path Daun X = E\n");
      printPathDaunX(W, 'E');
      printf("\n");

      printf("\nPrint All Paths\n");
      printAllPaths(W);
      printf("\n");

	printf("---------Nb Elm---------\n");
	printf("%d",NbElmTree(W));
	printf("\n\n");

	printf("---------NbDaun---------\n");
	printf("Banyaknya daun A: %d", NbDaun(W));
	printf("\n\n");

	printf("---------Max2---------\n");
      printf("Nilai maksimum di pohon: %d\n", max2(1, 2));
	printf("\n");

	printf("---------Tinggi Pohon---------\n");
	printf("Tinggi pohon A: %d", Tinggi(W));
	printf("\n\n");

	printf("---------Level---------\n");
      printf("Level tertinggi pada pohon: %d\n", Level(W));
	printf("\n");

	printf("---------Count Level It---------\n");
      T = 2; 
      printf("Jumlah node pada level %d: %d\n", T, CountLevelT(W, T));
	printf("\n");

	printf("---------Print Level---------\n");
      printf("Node pada level %d: ", T);
      PrintLevel(W, T);
      printf("\n\n");

	printf("---------Print BFS---------\n");
      printf("Node dalam urutan BFS: ");
      PrintBFS(W);
      printf("\n");
      printf("=========================\n\n");

	printf("SOAL TAMBAHAN\n");
      CreateList(&Asli);
      CreateList(&Tambahan);
    
      InsertVLast(&Asli, '1');
      InsertVLast(&Asli, '2');
      InsertVLast(&Tambahan, '3');
      InsertVLast(&Tambahan, '4');

      printf("List Asli sebelum Pconcat: ");
      PrintList(Asli);
      printf("\n");

      printf("List Tambahan: ");
      PrintList(Tambahan);
      printf("\n\n");

	printf("---------Pconcat---------\n");
      pconcat(&Asli, Tambahan);
      printf("List Asli setelah Pconcat: ");
      PrintList(Asli);
      printf("\n\n");

	printf("---------Fconcat---------\n");
      HasilConcat = Fconcat(Asli, Tambahan);
      printf("Hasil Fconcat (tanpa memengaruhi Asli): ");
      PrintList(HasilConcat);
      printf("\n\n");

	printf("---------Linear Prefix---------\n");
      PrefixList = LinearPrefix(W);
      printf("Hasil LinearPrefix: ");
      PrintList(PrefixList);
      printf("\n\n");

	printf("---------Linear Posfix---------\n");
      PosfixList = LinearPosfix(W);
      printf("Hasil LinearPosfix: ");
      PrintList(PosfixList);
      printf("\n\n");

	printf("---------Linear Infix---------\n");
      InfixList = LinearInfix(W);
      printf("Hasil LinearInfix: ");
      PrintList(InfixList);
      printf("\n\n");

	printf("---------Linear Breadth FS---------\n");
      PrintList(LinearBreadthFS(W)); 

      return 0;
}