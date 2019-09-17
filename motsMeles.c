#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int n=15;// la taille de la grille 
// la liste des grille proposée:
//nature:16*16
// latin2:15*15 
//animeaux:15*15
//texte:15*15
/****************************************prototypes des fonctions************************************************************/
void creergrille(char[50][50] );
int gauchedroite( char[50][50] ,char[50],int );
int droitegauche( char[50][50]  ,char[50] ,int );
int hautbas( char[50][50],char[50] ,int );
int bashaut( char[50][50],char[50] ,int );
int DiagMtGD( char[50][50],char[],int );
int sousDiagDsGD( char [50][50],char[50],int );
int DiagDsGD( char[50][50],char[50],int );
int DiagDsDG( char[50][50]  ,char[50] ,int);
int sousDiagDsDG(char[50][50],char[50],int);
int dessusDiagMtDG( char[50][50],char[50],int );
int DiagMtDG( char[50][50],char[50] ,int );
int sousDiagMtGD ( char[50][50] ,char[50] ,int );
void trouvemotif (char[50] , int ,char[50][50] );
 


/************************************** programe principale ************************************************************/
int main()
{
   char chaine[50];
   char	t[50][50];
   int i,j,m;

		puts("  ----------------------------------------------------------------------------");
	puts("                           *******************               ");
	puts("                           *                  *");
    puts(" **************************     Bienvenu(e)  *********************************");
	puts("                           *                  *");
  puts("                            ******************");
   	puts(" -------------------------------------------------------------------------------");
creergrille(t); //appel a la fonction qui cree la grille.
printf("\n \n");
do
{	printf("donner le mot a rechercher et si vous voulez arreter tapez 'STOP' !!!!\n");
    printf("-------------------------------------------------------------- ------\n");
	puts("\n");
	printf("\t");
    gets(chaine);
    puts("\t");
	m=strlen(chaine);
    if(strcmp(chaine,"STOP")!=0)//si l'utilisateur donne "STOP" le programme s'arrete !
    {
      trouvemotif(chaine,m,t);
      puts("\n");
      printf("-------------------------------------------------------------------\n");
    }else
    {
      puts("             Good bye!!!");// message affiché à la fin du programme apres avoir taper "STOP"!
    }
}while(strcmp(chaine,"STOP"));

	system("pause");
	
	return 0;

}
/****************************************************FIN*******************************************************************/
/********************************* cration de la grille ***********************************************************/
void creergrille(char t[50][50])
{

FILE* f;
char c ;
int i,j,k; 
	
	f=fopen("animeaux.txt","rt");
	if(f==NULL)
	{
		printf("erreur d'ouverture !!\n'");
	}
	else
	{
     while(!feof(f))	
     {
       for(i=0;i<n;i++)
       {
   	    for(j=0;j<n;j++)
   	    {
	   	    fscanf(f,"%c",&t[i][j]);
   	        // fread(&t[i][j], sizeof(char), 1, f) ;
        }

   	   }
   	
     }
   	  puts( "\t");
   	  k=1;
   	  printf("     %d",k);
  	  for(k=1;k<n;k++)
      {	    
        printf(" %2d",k+1);
   	   }
       puts("\t");
  	   puts("\n");
   
       for(i=0;i<n;i++)
       {
   	    printf("%2d ",i+1);
   	    for(j=0;j<n;j++)
   	    {
   		   printf("  %c",t[i][j]);
   	    }
          //puts("\n");
         printf("                                  ----------------------------------------------       \n");
   
       }
    }
fclose(f);
}
/********************************************************************************************************************************/	
/************************************************* fonction indice *****************************************************************/
/********************************************** returne la position du 1er  caractere du mot ****************************************/
/******************************************************qu'on cherche *****************************************************************/
int Indice( char s[50],char chaine[50],int taille,int m)
{
	int p,i,j;
	p=0;
	i=p;
	j=0;
	while((i<n)&&(j<m))
	{
		if(s[i]==chaine[j])
		{
		 i=i+1;
		 j=j+1;
		}
		else
		{
			j=0;
            p=p+1;
            i=p;
		}
	}
	if(j>=m)
	{
		return p;
	}
	else
	{
		return -1 ;
	}
}
/***************************************************************************************************************************/
/*---------------------------------------------------------------------------------------------------------------------------*/
/************************************************************ procedure gauche droite *****************************************/
int gauchedroite( char t[50][50] ,char chaine[],int m)
{
	int i,j,k,indice,taille;
	char s[n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			s[j]=t[i][j];
	      
		}
	
	taille=strlen(s);
	indice=Indice(s,chaine,taille,m);
	if(indice!=-1)
	{
		printf("le mot apparait horizontalement DE GAUCHE a DROITE a partir de la case (%d,%d) \n",i+1,indice+1);
		 return 0;
	}
	}
	
	return  1;
}
/**************************************************FIN********************************************************************/
//----------------------------------------------------------------------------------------------------------------------
/************************************************PROCEDURE DE droite a gauche**************************************/
int droitegauche( char t[50][50] ,char chaine[],int m)
{
	int i,j,k,indice,a,taille;
	char s[50];
	
	for(i=0;i<n;i++)
	{
		a=0;
		for(j=(n-1);j>=0;j=j-1)
		{
		  s[a]=t[i][j];
	      a=a+1;
		}
		taille=strlen(s);
	    indice=Indice(s,chaine,taille,m);
	    if(indice!=-1)
	    {
		  printf("le mot apparait horizontalement de DROITE a GAUCHE a partir de la case (%d,%d) \n",i+1,(n-indice));
		  return 0;
	    }
	
	}
	
	 return 1;
}
/**********************************************fin********************************************************************/
//------------------------------------------------------------------------------------------------------------------------
/***************************************** HAUT VERS LE BAS *****************************************************/
int hautbas( char t[50][50] ,char chaine[],int m)
{
	int i,j,k,indice,a,taille;
	char s[50];
	for(j=0;j<n;j++)
	{
		
		for(i=0;i<n;i++)
		{
			s[i]=t[i][j];
	    }
	    taille=strlen(s);
	   // puts(s);
	indice=Indice(s,chaine,taille,m);
	if(indice!=-1)
	{
		printf("le mot apparait verticalement de HAUT vers le  BAS a partir de la case (%d,%d) \n",indice+1,j+1);
		return 0;
	}
	
	
	}
	 return 1;
}
/********************************************************************************************************************/
//---------------------------------------------------------------------------------------------------------------------
/**************************************DE BAS VERS LE HAUT************************************************************/
int bashaut( char t[50][50] ,char chaine[],int m)
{
	int i,j,k,indice,a,taille;
	char s[50];
	
	for(j=0;j<n;j++)
	{
		a=0;
		for(i=(n-1);i>=0;i--)
		{
		  s[a]=t[i][j];
	      a=a+1;
         
	    }
	     taille=strlen(s);
	     indice=Indice(s,chaine,taille,m);
	     if(indice!=-1)
	     {
	     	printf("le mot apparait verticalement du BAS vers le HAUT a partir de la case (%d,%d) \n",n-indice,j+1);
		   return 0;
	     }
	
	}
	 return 1;
	
}
/************************************************FIN*****************************************************************/
/**************************************************************************************************************/
int DiagMtGD( char t[50][50],char chaine[],int m)
{
int i,j,k,indice,taille;
char s[50];
k=0;
while(k<n)
	{
		i=n-k;
		for(j=0;j<=n-k;j++)// l'indice de debut de ligne est l'indice de fin de colonne .
		{
	  		s[j]=t[i][j];
			i--;
		}		
   		 s[j]='\0';
		taille=strlen(s);
	//	puts(s);    //si vous voulez afficher les chaines récupérées !!
		if(m<=taille)
		{
		
			indice=Indice(s,chaine,taille,m);
			if(indice!=-1)
			{
				if(k==1)
				{
					printf("le mot apparait dans la Diagonale MONTANTE  G/D à partir de (%d,%d) \n",n-indice,indice+1);
	          	 	return 0;
				}
				else
				{
					printf("le mot apparait AU-DESSUS de la diagonale MONTANTE G/D a partir de (%d,%d) \n ",n-k-indice+1,indice+1);
					return 0;
				}
		
			}
	
	}
		k++;
}
	return 1;
	}
/******************************************fin*********************************************************************/
//--------------------------------------------------------------------------------------------------------------------
//--------------------------------------les chaines se trouvant sous la diagonale ---------------------------/
/********************************************** descendante gauche droite ***************************************/
int sousDiagDsGD( char t[50][50] ,char chaine[],int m)
{
	
int i,j,k,indice,a,taille;

	char s[50]; k=1;
	while(k<n)
	{

		a=0;	
		for(i=0;i<(n-k);i++)
		{

			s[a]=t[i+k][i];
			a=a+1;

		}
	s[a]='\0';
	taille=strlen(s);

//	puts(s);//si vous voulez afficher les chaines récupérées !!
	if(m <=taille)
	{
		indice=Indice(s,chaine,taille,m);
		if(indice!=-1)
		{
			printf("le mot apparait AU-DESSOUS DE LA DIAGONALE  DESCENDANTE G/D a partir de (%d,%d) \n",indice+1+k,indice+1);
        	return 0;		
        
		}
    }
	k=k+1;
	
}
return 1;
}
/************************************************fin**********************************************************************/

/******************************************* Diagonale descendante gauche droite ***********************************/
/********************************************** et les chaines au dessus d'elle**************************************/
int DiagDsGD( char t[50][50] ,char chaine[],int m)
{	
int i,j,k,indice,a,taille;
char s[50]; k=0;
while(k<n)
{
	a=0;	
	for(i=0;i<(n-k);i++)
	{
		s[a]=t[i][i+k];
		a=a+1;
	}
	s[a]='\0';
	taille=strlen(s);
//	puts(s);//si vous voulez afficher les chaines récupérées !!
	if(m <=taille)
	{
		indice=Indice(s,chaine,taille,m);

		if(indice!=-1)
		{
			if(k==0)
			{
				printf("le mot apparait dans la  Diagonale DESCENDANTE G/D à partir de (%d,%d) \n",indice+1,indice+1);
					return 0;
			}
			else
			{
				printf("le mot apparait  AU-DESSUS DE LA DIAGONALE DESCENDANTE G/D A partir de (%d,%d) \n",indice+1,indice+k+1);
					return 0;
			}
		}
	
	}

k++;
}
return 1;
}
/************************************************fin*******************************************************************/
/*****************************************Diagonale descendante droite gauche*********************************************/
/***********************************************et les chaines au dessus d'elle ***********************************************/
int DiagDsDG( char t[50][50] ,char chaine[],int m)
{
	
int i,j,k,indice,a,taille;
char s[50]; k=1;
while(k<n)
{
	a=0;	
	for(i=0;i<=(n-k);i++)
	{
		s[a]=t[i][n-a-k];
		a=a+1;
	}
	s[a]='\0';
	taille=strlen(s);
//	puts(s);//si vous voulez afficher les chaines récupérées !!
	if(m<=taille)// on ne cherche que dans les chaines dont la taille est superieur a la sous chaine donnée !!
	{
		indice=Indice(s,chaine,taille,m);
		if(indice!=-1)
		{
			if(k==1)
			{
    			printf("le mot apparait en DIAGONALE DESCENDANTE D/G à partir de (%d,%d) \n",indice+1,n-indice);
				return 0;
			}
			else
			{	
				printf("le mot apparait AU-DESSUS de la DIAGONALE DESCENDANTE D/G a partir de (%d,%d) \n",indice+1,n-k-indice+1);
        		return 0;
        	}
		}
	
	}
k++;

}
return 1;
}
/**********************************************fin*******************************************************************/
//-----------------------------------------------------------------------------------------------------------------------

/**************************************LES chaines se trouvant sous la diagonal************************************/
/**********************************************************descendante droite gauche***********************************/
int sousDiagDsDG(char t[50][50] ,char chaine[],int m)
{
int i,j,k,indice,a,taille;
char s[50];
 k=1;// pour ne pas recupérer la diagonale 
while(k<n)
{
 	a=0;	
	for(i=k;i<n;i++)
	{
		s[a]=t[i][n-a-1];//n-(a+1)
		a=a+1;
	}
	s[a]='\0';
	k++;
 	taille=strlen(s);

//	puts(s); //si vous voulez afficher les chaines récupérées !!
	if(m<=taille)// on ne cherche que dans les chaines dont la taille est superieur a la sous chaine donnée !!
	{
		indice=Indice(s,chaine,taille,m);
		if(indice!=-1)
		{	
			printf("le mot apparait AU-DESSOUS DE LA DIAGONALE DESCENDANTE  D/G a partir de (%d,%d) \n",indice+k,n-indice);
        	return 0;
		}
	}
}
return 1;
}
/*******************************************************FIN***************************************************/


//--------------------------------------------------------------------------------------------------------------------------
/******************************************chaines au dessus de la diagonale m  ***********************************/
/**********************************************Montante droite gauche **************************************/
int dessusDiagMtDG ( char t[50][50] ,char chaine[],int m)
{
int i,j,k,indice,a,taille;
char s[50]; 
k=1; // le k=1 pour ne pas recuperer la diagonale.
while(k<n)
{	
	a=0;	
	for(i=(n-1-k);i>=0;i--)
	{
	 s[a]=t[i][i+k];
     a=a+1;
	}
    k++;
	s[a]='\0';// pour delimiter la chaine!!
	taille=strlen(s);
//	puts(s);//si vous voulez afficher les chaines récupérées !!
    if(m <=taille)// on ne cherche que dans les chaines dont la taille est superieur ou egale a celle du mot .
	    {
		indice=Indice(s,chaine,taille,m);
		if(indice!=-1)
		{
		printf("le mot apparait AU-DESSUS DE LA DIAGONALE MONTANTE D/G a partir de (%d,%d) \n",n-indice-k+1,n-indice);
	    		
		return 0;	
		}
	
	}

}
return 1;
}
/***************************************** Diagonale Montante et toute les sous chaines ****************************/
/********************************************  Droite Gauche ***********************************/

int DiagMtDG( char t[50][50] ,char chaine[],int m)

{
	int i,j,k,indice,a,taille;
	char s[50];
	k=0;/*** k c'est le <Pas> ***/
while(k<n)
{
	
	a=0;
	for(i=(n-1);i>=k;i--)
	{
		s[a]=t[i][i-k];
		a=a+1;
	}
		s[a]='\0';

	taille=strlen(s);
	//puts(s);//si vous voulez afficher les chaines récupérées !!
	if(m<=taille)// on ne fait la recherche que si la taille du mot est inferieur ou egale a la taille de la chaine récuperée .
	{
	indice=Indice(s,chaine,taille,m);
	if(indice!=-1)
	{
		if(k==0)// On veut avoir un message à part pour les mots qui se trouvent dans la diagonale .
		{		
	     	printf("le mot apparait dans LA DIAGONALE MONTANTE D/G à partir de (%d,%d) \n",n-indice,n-indice);
	        return 0;
		}
		else
		{
		printf("le mot apparait AU-DESSOUS DE LA DIAGONALE MONTANTE D/G a partir de (%d,%d) \n",n-indice,n-indice-k);
	    		return 0;
		}
		
	}
}
k++;// incrémentation du pas ! 
}
 				return 1;
}
/***************************************************FIN******************************************************************/
/******************************************------ Les chaines de caracteres sous la diagonale------**************/
/**************************************************** Montante Gauche Droite*****************************************/

int sousDiagMtGD ( char t[50][50] ,char chaine[],int m)
{
	
int a,i,j,k,indice,taille;
char s[50];
   k=1;
while(k<n)
{
	i=n-1;
	a=0;
	for(j=k;j<n;j++)// l'indice i de debut de chaque chaine  est l'indice j de fin cette derniere .
	{
	  s[a]=t[i][j];
			i--;
			a++;
	}
	s[a]='\0';
	//puts(s);//si vous voulez afficher les chaines récupérées !!
	taille=strlen(s); //determiner la taille de chaque chaine recupérée .
	if(m <=taille)// on ne fait la recherche que si la taille du mot est inferieur ou egale a la taille de la chaine récuperée .
	{
	indice=Indice(s,chaine,taille,m);
	if(indice!=-1)
	{
		printf("le mot apparait AU-DESSOUS de la DIAGONALE MONTANTE G/D a partir de (%d,%d)\n",n-indice,indice+k+1);
		
								return 0;
	}
}
k++;	
}
	   						    return 1;
}

/********************************************fin**********************************************************************/
void trouvemotif (char S[50], int m,char t[50][50])
{

if((gauchedroite(t,S,m)==1)&&(droitegauche(t,S,m)==1)&&(bashaut(t,S,m)==1)&&(hautbas(t,S,m)==1)&&(DiagDsGD(t,S,m)==1)&&(sousDiagDsGD(t,S,m)==1)&&(DiagDsDG(t,S,m)==1)&&(sousDiagDsDG(t,S,m)==1)&&(dessusDiagMtDG(t,S,m)==1)&&(DiagMtDG(t,S,m)==1)&&(DiagMtGD(t,S,m)==1)&&(sousDiagMtGD(t,S,m)==1))
{
	printf("le mot n'existe pas ! \n");
}
}
