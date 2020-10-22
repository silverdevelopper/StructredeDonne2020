#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#include "kdTree.h"
void init_tree(kdNode** root);
void init2_tree(kdNode** root);
int main()
{
  // Soru 1e cevap
  // ilk önce I indexli kapıyı eklerdim x'leri iki parçaya bölmüş olurdum
  int t[K]={28,2};
  kdNode *T=create_tree("CEVAHİR BEDESTENİ -MERKEZ",'T',t);
  kdNode *root=NULL;
  init_tree(&root);
  int depth=getLevel(root);
  printf("Level is: %d\n",depth);
  // Soru 4 hocam ben level'ı başka bir şekilde hallediyorum
  kdNode* serc= search_port(root,"Lütfullah");
  printNode(serc);
  kdNode* serc2= search_index(root,'T');
  printNode(serc2);
  printf("\n------Inorder Traversal---\n");
  print_inorder(root);
  printf("\n------Preorder Traversal---\n");
  print_preorder(root);
  printf("\n------Postorder Traversal---\n");
  print_postorder(root);

  /** SORU 11
   * Ağaç balance değil, en kötü durumda hatta :)
   *  
  */
 freeTree(&root);
 depth=getLevel(root);
 printf("Level is: %d\n",depth); // depth 0 geldiğinde ağaç öldü demek
 root=NULL;
  printf("\n------Inorder Traversal2---\n");
  init2_tree(&root);
  print_inorder(root);
  //soru 11 için yorum
  //Hepsini kağıda tek tek yazmak çok uzun olduğu için 6 kapı ekleyip inorder yazdırdım sonuç doğru çıktı görsel ektedir

return 0;
}
void init_tree(kdNode** root){
  insert(root,"Örücüler",'A',16,43);
  insert(root,"Cebeci Han",'B',5,33);
  insert(root,"Lütfullah",'C',4,22);
  insert(root,"Yorgancılar",'D',6,17);
  insert(root,"Bodrum Han",'E',3,10);
  insert(root,"Fesçiler",'F',4,5);
  insert(root,"Hacı Hüsnü",'G',4,4);
  insert(root,"Beyazıt",'H',5,2);
  insert(root,"Çarşıkapı",'I',16,3);
  insert(root,"Sorguçlu Han",'J',25,2);
  insert(root,"Merdivenli",'K',32,3);
  insert(root,"Kürkçüler",'L',32,2);
  insert(root,"Nuruosmaniye",'M',46,7);
  insert(root,"Sandal Bedesteni",'N',45,13);
  insert(root,"Kilitçiler",'O',45,17);
  insert(root,"MahmutPaşa",'P',44,24);
  insert(root,"Mercan",'R',32,29);
  insert(root,"Tacirler",'S',26,31);
  insert(root,"CEVAHİR BEDESTENİ -MERKEZ",'T',28,16);

}
void init2_tree(kdNode** root){
  //J kapısı olsun. Sırasıyla E, T, H, I, D, A, B, C, R, L, S, P, O, K, M, G, F, N
  
  insert(root,"Sorguçlu Han",'J',25,2);
  insert(root,"Bodrum Han",'E',3,10);
  insert(root,"CEVAHİR BEDESTENİ -MERKEZ",'T',28,16);
  insert(root,"Beyazıt",'H',5,2);
  insert(root,"Çarşıkapı",'I',16,3);
  insert(root,"Yorgancılar",'D',6,17);
 
  insert(root,"Örücüler",'A',16,43);
  insert(root,"Cebeci Han",'B',5,33);
  insert(root,"Lütfullah",'C',4,22);
  insert(root,"Mercan",'R',32,29);
  insert(root,"Kürkçüler",'L',32,2);
  insert(root,"Tacirler",'S',26,31);
  insert(root,"MahmutPaşa",'P',44,24);
  insert(root,"Kilitçiler",'O',45,17);
  insert(root,"Merdivenli",'K',32,3);
  insert(root,"Nuruosmaniye",'M',46,7);
  insert(root,"Hacı Hüsnü",'G',4,4);
  insert(root,"Fesçiler",'F',4,5);
  insert(root,"Sandal Bedesteni",'N',45,13);
  
  
}
