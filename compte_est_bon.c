#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>
#include <ctype.h>
//definition de la structure qui nous permettra de gerer le jeu
struct val{
  int tab[7];
  int taille;
  int resultat;
};
typedef struct val val;
//la fonction qui se charge d'afficher le menu a l'utilisateur
int menu (){
  system("cls");
  int choix;
  printf ("-------------------------------------------------------------------------\n");
  printf ("BIENVENUE SUR LE COMPTE EST BON  SOUHAITEZ VOUS CONTINUER?             | \n");
  printf ("-------------------------------------------------------------------------\n");
  printf("                                                                       ---\n");
  printf("--------------------------------------------------------------------------\n");
  printf ("1:  ----------A PROPOS DU JEU-------------------------------------------|\n");
  printf("------------------------------------------------------------------------ -\n");
  printf("                                                                          \n");
  printf("--------------------------------------------------------------------------\n");
  printf ("2:----------- JE SOUHATE JOUER------------------------------------------|\n");
  printf("--------------------------------------------------------------------------\n");
  printf("                                                                          \n");
  printf("--------------------------------------------------------------------------\n");
  printf ("3:----------JE SUIS PAS INTERESSE---------------------------------------|\n");
  printf("--------------------------------------------------------------------------\n");
  printf("                                                                          \n");

  printf ("----------------------VOTRE CHOIX ?----------------------------------- ");
  //on recupere le choix de l'utilisateur en fonction de quoi on saura quoi faire par la suite
  scanf ("%d",&choix);
  return choix;

}
 //fonction qui affiche le principe du jeu a l'utilisateur
 void afficher(){
  system("cls");
  int a;
  printf("\n le principe du jeu est tres simple \n ");
  printf("\n 1: un nombre vous est donne a calculer appele nombre cible \n");
  printf("\n 2: 6 nombres vous sont donnees pour calculer ce nombre       \n");
 // printf("\n ne vous sentez pas oblige d'utiliser tout ces nombres pour  trouver le nombre cible\n");
  printf("\n 3: fait usage des operateurs +,/,-, et * pour effectuer vos operations \n");
  printf("\n 4: si vous trouvez le bon nombre le compte est bon sinon vous pouvez recommencer\n");
  printf("\n souhaitez vous jouer ?");
  printf("\n 1:OUI \n");
  printf("\n 2:REVENIR AU MENU PRINCIPAL \n");
  printf("\n 3:JE SOUHAITE QUITTER        \n");
  scanf("%d",&a);
  switch(a){

  case 1 : jeu();break;
  case 2 : menu();break;
  case 3 : return; break;
  default : return; break;
 }

 }
 //fonction qui nous permettra de faire une operation de l'utilisateur en fonction des operandes et de l'operateur
int calcul(int *a,int *b,char *c){
 int res,f;
 if(*c=='+'){
  res=*a+*b;
  printf("\n operation: %d + %d = %d\n",*a,*b,res);
  return res;
 }
 if(*c=='-'){
  res=*a-*b;
  printf("\n operation: %d - %d = %d\n",*a,*b,res);
  return res;
 }
 if(*c=='*'){
  res=*a*(*b);
  printf("\n operation: %d * %d = %d\n",*a,*b,res);
  return res;
 }
 if(*c=='/'){
  res=*a/(*b);
  f=*a%(*b);
  if(f!=0)return -1;
  printf("\n operation: %d / %d = %d\n",*a,*b,res);
  return res;
 }
 printf("operation inconnue"); return 0;
}
//la fonction qui demande a l'utilisateur de saisir son operation et verifie son calcul
void valide (val v){
  int a, b, k, j, l, contient, m, i;
  char c;
  do
  { printf("veuillez saisir le premier operande ");
    scanf("%d",&a);
    k=-1;
    for(i=0;i<v.taille;i++) if(a==v.tab[i]        ) k=i;
  } while(k==-1);
  printf("\n");
  do
  {
    printf("veuillez saisir l'operateur ");
    scanf("%s",&c);
  }
  while(c!='+'&&c!='-'&&c!='/'&&c!='*');
  //printf("\n mauvaise saissie veuillez recommencer svp ");
  printf("\n");
  do
  {
    printf("veuillez saisir le deuxieme operande ");
    scanf("%d",&b);
    j=-1;
    for(i=0;i<v.taille;i++) if(b==v.tab[i] && i!=k) j=i;
  }while(j==-1);
  contient=calcul(&a,&b,&c);
  while(contient<=0){
    printf("\n operation non valide \n");
    return;
  }
  v.tab[k]=contient;
  l=v.tab[v.taille-1];
  v.tab[v.taille]=v.tab[j];
  v.tab[j]=l;
  v.taille=v.taille-1;
  printf ("les nouvelles valeurs sont ");
  for(m=0;m<v.taille;m++){
    printf("%d-",v.tab[m]);
  }
  printf("\n");
  printf("\n");
}
//fonction qui genere les nombres et appel la fonction qui doit nous faire le calcul
int jeu() {
  val v; int tab; int c;
  int cible;int ind;
  srand(time(NULL));
  cible=rand()%900+100;
  int t[22]={1,2,3,4,5,6,7,8,9,10,25,50,100,1,2,3,4,5,6,7,8,9};
  int np=22;
  int i;
  for (i=0;i<=5;i++){
    ind=rand()%np;
    v.tab[i]=t[ind]; t[ind]=t[--np];
  }
  v.taille=6;
  v.resultat=0;
  system("cls");
  printf ("le nombre cible est  %d \n",cible);
  printf ("veuillez utiliser ces nombres pour faire vos calculs %d %d %d %d %d %d   \n",v.tab[0],v.tab[1],v.tab[2],v.tab[3],v.tab[4],v.tab[5]    );
  while(v.taille>1 && v.resultat!=cible){
    valide(v);
  }
  if(v.resultat==cible){
    printf("\n le compte est bon bravo \n");
  }
  printf("\n souhaitez vous recommencer ? \n");
  printf("choisissez 1:OUI \n");
  printf("\n         2:NON \n");


  scanf("%d",&c);

  switch(c){
    case 1:jeu();break;

    case 0 : printf("\n merci d avoir jouer aurevoir \n");
    return 0;break;
    default: return 0; break;

    jeu();break;
  }

  return 1;

}

int main(int argc, char *argv[]) {
  switch(menu()){
    case 1: afficher(); break;
    case 2: jeu();break;
    case 3: return 0; break;
    default : return 0;break;
  }
  return 0;
}

