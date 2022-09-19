#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#ifdef _WIN32
#endif
    //         function to set color 
    void SetColor(int ForgC){
     WORD wColor;               
     //This handle is needed to get the current background attribute
     
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;   
     //csbi is used for wAttributes word
             
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
    
}
  // la strecture produit
    typedef struct Produit{
      char code[20];
	  char nom[20];
	  int quantite;
	  float prix;	
	}Produit;
     
   typedef struct stat{
   	 char tiime[25];
   	 float tot;
   	 float max;
   	 float min;
   }stat;

//    struct tm *mytime=localtime(&ti);
//  printf("%i/%i/%i\n",mytime->tm_mon+1,mytime->tm_mday,mytime->tm_year+1900); 
     
  stat st;
  
  Produit p[100];
  // la fonction ajouter Produit
  int i=0,j;
  int k=0;
  int l=0;
   
//void make_tolower(char s[])
//{
//  int length = strlen(s);
//  for (int i=0;i<length;i++)
//    {
//      s[i]=toupper(s[i]);
//    }
//}

    void AjouterProduit(){
    	
  	SetColor(10);
  	printf("\n\tdonner le code de votre produit:\t");
  	scanf("%s",p[i].code);
  	printf("\tdonner le nom du produit:\t");
  	scanf("%s",p[i].nom);
  	printf("\tdonner le prix du produit:\t");
  	scanf("%f",&p[i].prix);
  	printf("\tdonner la quantité du produit:\t");
  	scanf("%d",&p[i].quantite);
  	SetColor(5);
  	printf("\n\tvotre produit est bien enregistrer\n");
  	i++;
  	int r;
  	SetColor(6);
  	printf("\n\t0-> Retour au menu principale\n");
  	printf("\t");
  	scanf("%d",&r);
  	while(r!=0){
  		SetColor(4);
  		printf("\til faut entrer le 0 pour retourner au menu principale:\t");
  		scanf("%d",&r);
	  }
	  system("cls");
	  main();
  }
  // Ajouter plusieur produit
    void AjouterPlusiurProduit(){
  	int np;
  	SetColor(5);
    printf("\n\tdonner le nombre des produit que tu veux saisir :");
    printf("\t");
  	scanf("%d",&np);
  	while(np<0 || np>100){
  		SetColor(4);
  		printf("\n\tveuiller saisir un nombre comprie entre 0 et 100 :");
  		printf("\t");
  		scanf("%d",&np);
	  }
	  int a=i;
	  for(i;i<np+a;i++){
	  	SetColor(10);
     	printf("\n\tdonner le code du produit N°%d:\t",i+1);
    	scanf("%s",p[i].code);
    	printf("\tdonner le nom du produit N°%d:\t",i+1);
    	scanf("%s",p[i].nom);
    	printf("\tdonner le prix du produit N°%d:\t",i+1);
    	scanf("%f",&p[i].prix);
     	printf("\tdonner la quantité du produit N°%d:\t",i+1);
    	scanf("%d",&p[i].quantite);
//       AjouterProduit();
    	printf("\n");
	  }
	  int x;
	    SetColor(6);
	    printf("\n\t0-> Retour au menu principale\n\t");
	    scanf("%d",&x);
	    while(x!=0){
	    	SetColor(4);
	    	printf("\til faut entrer le 0 pour retourner au menu principale:\t");
	    	scanf("%d",&x);
		}
		system("cls");
		main();
  }
  // la fonction lister les produit
    void ListerProduit(){
  	int nl;
  	SetColor(1);
  	printf("\n\t1->lister tous les produits selon l’ordre alphabétique  croissant du nom\n");
  	printf("\t2->lister tous les produits selon l’ordre  décroissant du prix\n\n\t");
    SetColor(6);
	printf("\n\t0-> Retour au menu principale\n\t");
	wrong:
	scanf("%d",&nl);
  	switch (nl)
	{
		int k;
		Produit ch;
		case 0:
			system("cls");
			main();
			break;
    	case 1:
    		system("cls");
    		SetColor(5);
			printf("\n\tProduit :Nom \t Prix \t PrixTTc  \n");
    		for(j=0;j<i;j++){
    			for(k=j+1;k<i;k++){
    				if(strcasecmp(p[j].nom,p[k].nom)>0){
    					ch=p[j];
    					p[j]=p[k];
    					p[k]=ch;
					}   

				}
			}
            for(j=0;j<i;j++){
    	    printf("\n\tP[%d]   :%s \t %.2f \t %.2f  \n",j+1,p[j].nom,p[j].prix,p[j].prix*1.15);
    		}
			SetColor(6);
		   	printf("\n\t0-> Retour au menu principale\n");
		   	printf("\t1-> Retour au menu précidant\n\t");
		   	int pm;
		   	se:
		   	scanf("%d",&pm);
		   	switch(pm){
		   	    case 0:
		   		system("cls");
		   		main();
		   		break;
		   		case 1:
		   		system("cls");
		   		ListerProduit();
		   		break;
		   		default:
		   		
		   				SetColor(4);
		   				printf("\tc'est opération n'existe pas !!\n");
		   				printf("\tentrer le 0 ou le 1:\t");
		   				goto se;
		   		break;
		   	}
		break;
    	case 2:
    	system("cls");
    	SetColor(5);
    	printf("\n\tProduit :Nom \t Prix \t PrixTTc \t la date d'achat \n");

    		for(j=0;j<i;j++){
    		for(k=j+1;k<i;k++){
    	    if(p[j].prix<p[k].prix){
    	    	ch=p[k];
    	    	p[k]=p[j];
    	    	p[j]=ch;
			}
    	    }
    	   	}
            for(j=0;j<i;j++){
    	    printf("\tP[%d]   :%s \t %.2f \t %.2f \n",j+1,p[j].nom,p[j].prix,p[j].prix*1.15);
    	    }
    	    SetColor(6);
    	    printf("\n\t0-> Retour au menu principale\n");
		   	printf("\t1-> Retour au menu précidant\n\t");
		   	int spm;
		   	sse:
		   	scanf("%d",&spm);
		   	switch(spm){
		   	    case 0:
		   		system("cls");
		   		main();
		   		break;
		   		case 1:
		   		system("cls");
		   		ListerProduit();
		   		break;
		   		default:
		   		
		   				SetColor(4);
		   				printf("\tc'est opération n'existe pas !!\n");
		   				printf("\tentrer le 0 ou le 1:\t");
		   				goto sse;
		   		break;
		   	}
    	break;
    	default:
    		SetColor(4);
    		printf("\tc'est opération n'existe pas !!!\n");
    		printf("\tentrer une opération valide \n\t");
    		goto wrong;
    	break;
    }
}
  // la fonction Acheter Produit
  // **N.B :Pour chaque produit acheté, vous devez enregistrer le prix TTC et la date d’achat.**
    void Acheterproduit(){
//    char *ctime(const time_t *timer);

	int comp=0;
	char code1[20];
	first:
	SetColor(10);
	printf("\n\tdonner un code du produit: \t");
	scanf("%s",code1);
	for(j=l;j<i;j++){

    if(strcmp(p[j].code,code1)==0){
    	comp++;
    	break;
	}
	}
	if(comp>0){
		
			int q;
			printf("\tdonner la qauntité que tu veut déduire:\t");
			scanf("%d",&q);
			if(p[j].quantite==0){
				SetColor(4);
				printf("\tCe produit est en rupture de stock");
				goto first;
			}else{
			while(q>p[j].quantite || q<0){
				SetColor(5);
				printf("la quantité de se produit dans le stock est %d\n",p[j].quantite);
				printf("donc il faut entrer une quantité raisonable:\n");
				scanf("%d",&q);
			}
			 time_t ti;
             time(&ti);
             st.max=p[0].prix;
			 st.min=p[0].prix;
             if(p[j].prix<st.min){
             	st.min=p[j].prix;
			 }
			 if(p[j].prix>st.max){
			 	st.max=p[j].prix;
			 }
             st.tot+=p[j].prix*q;
		   	 strcpy(st.tiime,ctime(&ti));
        	 p[j].quantite-=q;
//        	 st.tot1+=p[j].prix;
        	// il faut enregistrer la date et le prix ttc ;
        	int n;
			printf("\n\topération bien éfectuer");
		    l++;
			
//			printf(ctime(&t));
            SetColor(2);
			printf("\n\t0-> retour au menu principale\t\n");
			scanf("%d",&n);
			while(n!=0){
				SetColor(4);
				printf("\tinvalide operation \n ");
				printf("\tentrer le 0 pour retourner au menu principale\n\t");
				scanf("%d",&n);
			}
			system("cls");
			main();
		}

    
	}else{
		printf("\t le code que tu as entrer n'éxiste pas\n");
		goto first;
	}

}
  // la fonction Rechercher un produit
    void RechercherProduits(){
	int o;
	SetColor(1);
	printf("\n\t1->chercher le produit selon le code\n");
	printf("\t2->chercher le produit selon la quantité\n\n");
	SetColor(6);
	printf("\t0->Retour au menu Principale\n\t");
	oper:
//	SetColor(2);	
//	printf("\n\tchoisir une operation:\t");
	scanf("%d",&o);
	while(o<0 || o>2){
		SetColor(4);
		printf("\tc'est opération n'éxiste pas\n\t");
		goto oper;
	}
	char c[20];
   	int cmp=0;
   	int qu;
	switch (o){
	  case 0:
	  	system("cls");
	  	main();
	  break;	
	  case	1:
	  	system("cls");
	  	SetColor(2);
	  	printf("\n\tdonner un code :\n\t");
	  	scanf("%s",c);
	  	for(j=0;j<i;j++){
	  		if(strcmp(p[j].code,c)==0){
	  	   	printf("P[%d]   :%s \t %.2f \t %.2f \n",j+1,p[j].nom,p[j].prix,p[j].prix*1.15);
			 cmp++;
			}
		  }
		  if(cmp==0){
		  	system("cls");
		  	SetColor(4);
		  	printf("\n\tle code que tu as entrer ne reference aucun produit\n");
		  	SetColor(6);
		  	printf("\n\t0->Retour au menu précedant\n");
		    printf("\t1->Retour au menu principale\n\t");
		    int op;
		    opr:
		    scanf("%d",&op);
		    	switch (op){
	                case 1:
	  	            system("cls");
	             	main();
	                break;
	                case 0:
	                system("cls");
	                RechercherProduits();
	                break;
	                default:
	                SetColor(4);
	                printf("\tcette opération n'éxiste pas\n");
	                goto opr;
	                break;
                }
		    
		  }else{
		  	SetColor(6);
		  	printf("\n\t0->\tRetour au menu précedant\n");
		    printf("\t1->tRetour au menu principale\n\t");
		    int ope;
		    opra:
		    scanf("%d",&ope);
		    	switch (ope){
	                case 1:
	  	            system("cls");
	             	main();
	                break;
	                case 0:
	                system("cls");
	                RechercherProduits();
	                break;
	                default:
	                SetColor(4);
	                printf("\tcette opération n'éxiste pas\n");
	                goto opra;
	                break;
                }
		  }
		  
	  break;
	  case 2:
	  	system("cls");
	  	SetColor(2);
	  	printf("\n\tdonner une quantité :\n\t");
	  	scanf("%d",&qu);
	  	for(j=0;j<i;j++){
	  		if(p[j].quantite==qu){
	  	   	printf("\tP[%d]   :%s \t %.2f \t %.2f \n",j+1,p[j].nom,p[j].prix,p[j].prix*1.15);
			 cmp++;
			}
		  }
		  	if(cmp==0){
		  	system("cls");
		  	SetColor(4);
		  	printf("\n\tla quantité que tu as entrer ne reference aucun produit\n");
		  	SetColor(6);
		  	printf("\n\t0->Retour au menu précedant\n");
		    printf("\t1->Retour au menu principale\n\t");
		    int op;
		    opr1:
		    
		    scanf("%d",&op);
		    	switch (op){
	                case 1:
	  	            system("cls");
	             	main();
	                break;
	                case 0:
	                system("cls");
	                RechercherProduits();
	                break;
	                default:
	                SetColor(4);
	                printf("\tcette opération n'éxiste pas\n");
	                goto opr1;
	                break;
                }
		    
		  }else{
		  	SetColor(6);
		  	printf("\n\t0->\tRetour au menu précedant\n");
		    printf("\t1->tRetour au menu principale\n\t");
		    int ope;
		    opra1:
		  
		    scanf("%d",&ope);
		    	switch (ope){
	                case 1:
	  	            system("cls");
	             	main();
	                break;
	                case 0:
	                system("cls");
	                RechercherProduits();
	                break;
	                default:
	                SetColor(4);
	                printf("\tcette opération n'éxiste pas\n");
	                goto opra1;
	                break;
                }
		  }
	  break;
	}
	
	
}
  // Etat du stock
    void EtatStock(){
    	int comp=0;
    
	SetColor(5);
	printf("\n\tles produit dont la quantité inferieur à 3 est : \n");
	for(j=0;j<i;j++){
		if(p[j].quantite<3){
		 SetColor(8);
		 printf("\n\tP[%d]   :%s \t %.2f \t %.2f \n",j+1,p[j].nom,p[j].prix,p[j].prix*1.15);
		 comp++;
		}
	}
	int n;
	if(comp==0){
		SetColor(4);
		printf("\n\til n'existe aucun produit dans la quantité est inferieur à 3\n");
		SetColor(6);
		printf("\n\t0->Retour au menu principale:\n\t");
		scanf("%d",&n);
		while(n!=0){
			SetColor(4);
			printf("\tc'est opération n'existe pas\n");
			printf("\tentrer une opération validé:\n\t");
		    scanf("%d",&n);
		}
		system("cls");
		main();
	}
	else{
		SetColor(7);
		printf("\n\t0->Retour au menu principale:\n\t");
		scanf("%d",&n);
		while(n!=0){
			SetColor(4);
			printf("\tc'est opération n'éxiste pas\n");
			SetColor(2);
			printf("\tentrer un opération validé:\n\t");
		    scanf("%d",&n);
		}
		system("cls");
		main();
	}
}
  //Alimenter le stock
    void AlimenterStock(){
    char ch[20];
    int q,cmp=0;
    SetColor(5);
  	printf("\n\tdonner le code du produit que tu veut augmenter dans votre stock\n\t");
  	scanf("%s",&ch);
  	for(j=0;j<i;j++){
  		if(strcmp(p[j].code,ch)==0){
  			cmp++;
  			break;
		  }
	  }
	  if(cmp>0){
	  	printf("\tdonner la quantité que tu veux ajouter\n\t");
	  	scanf("%d",&q);
	  	while(q<=0){
	  		printf("\tvous devez ajouter une quantité supérieur à 0\n\t");
	  		scanf("%d",&q);
		  }
		  p[j].quantite+=q;
		  printf("\n\topération bien éffectuer\n");
		  printf("\n\t0->retour au menu principale\n\t");
		  int n;
		  scanf("%d",&n);
		  while(n!=0){
		  	printf("\til faut entrer le 0 pour retour au menu principale\n\t");
		    scanf("%d",&n);
		  }
		  system("cls");
		  main();
	  }
	  else{
	  	int n;
	  	SetColor(4);
	  	printf("\n\tle code que tu as entrer ne reference aucun produit\n");
	  	SetColor(6);
	  	printf("\n\t0-> Retour au menu Principale\n\t");
		scanf("%d",&n);
		  while(n!=0){
		  	printf("\til faut entrer le 0 pour retour au menu principale\n\t");
		  	scanf("%d",&n);
		  }
		  system("cls");
		  main();
	  }
  }

    void SupprimerProduits(){
    	char sc[20];
    	int comp=0;
    	SetColor(5);
    	printf("\tdonner le code du produit que tu veux supprimer\n\t");
    	scanf("%s",&sc);
    	for(j=0;j<i;j++){
    		if(strcmp(p[j].code,sc)==0){
    			comp++;
			}
		}
		if(comp==0){
			SetColor(4);
			printf("\tle code que tu as entrer ne réfernce aucun produit\n");
			SetColor(6);
			printf("\t0->Retour au menu principale\n\t");
			int n;
			scanf("%d",&n);
			while(n!=0){
				SetColor(4);
				printf("\topération non valide \n");
				printf("\til faut entrer le 0 pour retourner au menu principale\n\t");
				scanf("%d",&n);
			}
				system("cls");
			main();
		}else{
			SetColor(2);
			int k;
			Produit ch;
			for(j=0;j<i;j++){
					p[j]=p[j+1];				
			}
			i--;
			SetColor(2);
			printf("\tle produit est bien supprimer\n");
			SetColor(4);
			printf("\t0->Retour au menu Principale\n\t");
			int n;
			scanf("%d",&n);
			while(n!=0){
				SetColor(4);
				printf("\topération non valide \n");
				printf("\til faut entrer le 0 pour retourner au menu principale\n\t");
				scanf("%d",&n);
			}
			system("cls");
			main();
			
		}
	}

    void StatistiqueVente(){
    	SetColor(9);
    	int n,m;
    	printf("\n\t1->Afficher le total des prix des produits vendus en journée courante \n");
    	printf("\t2->Afficher la moyenne des prix des produits vendus en journée courante \n");
    	printf("\t3->Afficher le Max des prix des produits vendus en journée courante \n");
    	printf("\t4->Afficher le Min des prix des produits vendus en journée courante \n");
    	SetColor(6);
    	printf("\n\t0->Retour au menu principale\n\t");
    	scanf("%d",&n);
    	menup:
    	switch(n){
    	
    		case 0:
    			system("cls");
    			main();
    		break;
			case 1:
    		    system("cls");
//    		    for(j=0;j<i;j++){
//    		    	st.tot+=p[j].prix;
//				}
				SetColor(5);
    		    printf("\n\tle total des prix des produits vendus en journée courante sont:%.2f dont la date est %s\t",st.tot,st.tiime);
    		    SetColor(2);
    		    printf("\n\t0->Retour au menu précedant ");
    		    printf("\n\t1->Retour au menu principale\n\t");
                scanf("%d",&m);
                menu:
                switch(m){
                	case 0:
						system("cls");
						StatistiqueVente();
					break;
                	case 1:
                		system("cls");
                		main();
                	break;
					
					default:
						SetColor(4);
						printf("\tc'est opération n'est pas validé\n\t");
						scanf("%d",&m);
						goto menu;
					break;	
				}
    		break;	
			case 2:
				 system("cls");
			    
				SetColor(5);
				if(i==0){
					SetColor(4);
					printf("\n\til n'ya aucun produit dans votre stock\n");
						SetColor(2);
    		    printf("\n\t0->Retour au menu précedant ");
    		    printf("\n\t1->Retour au menu principale\n\t");
                scanf("%d",&m);
                menuu:
                switch(m){
                	case 1:
                		system("cls");
                		main();
                	break;
					case 0:
						system("cls");
						StatistiqueVente();
					break;
					default:
						SetColor(4);
						printf("\tc'est opération n'est pas validé\n\t");
						scanf("%d",&m);
						goto menuu;
					break;	
				}
				}else{
				
				printf("\n\t la moyenne des prix des produits vendus en journée courante est:%.2f dont la date est %s\t\n",st.tot/l,st.tiime);
    			SetColor(2);
    		    printf("\n\t0->Retour au menu précedant ");
    		    printf("\n\t1->Retour au menu principale\n\t");
                scanf("%d",&m);
                menu1:
                switch(m){
                	case 1:
                		system("cls");
                		main();
                	break;
					case 0:
						system("cls");
						StatistiqueVente();
					break;
					default:
						SetColor(4);
						printf("\tc'est opération n'est pas validé\n\t");
						scanf("%d",&m);
						goto menu1;
					break;	
				}
				}
    		break;	
			case 3:
				system("cls");    			
				SetColor(5);
    			printf("\n\tle Max des prix des produits vendus en journée courante sont :%.2f dont la date est %s\t\t",st.max);
    			 SetColor(2);
    		    printf("\n\n\t0->Retour au menu précedant ");
    		    printf("\n\t1->Retour au menu principale\n\t");
                scanf("%d",&m);
                 menu2:
                switch(m){
                	case 1:
                		system("cls");
                		main();
                	break;
					case 0:
						system("cls");
						StatistiqueVente();
					break;
					default:
						SetColor(4);
						printf("\tc'est opération n'est pas validé\n\t");
						scanf("%d",&m);
						goto menu2;
					break;	
				}
    		break;	
			case 4:
			    system("cls");
			 
				SetColor(5);
    			printf("\tle Min des prix des produits vendus en journée courante sont :%.2f dont la date est %s\t\t",st.min);
    			 SetColor(2);
    		    printf("\n\t0->Retour au menu précedant ");
    		    printf("\n\t1->Retour au menu principale\n\t");
                scanf("%d",m);
                 menu3:
                switch(m){
                	case 1:
                		system("cls");
                		main();
                	break;
					case 0:
						system("cls");
						StatistiqueVente();
					break;
					default:
						SetColor(4);
						printf("\tc'est opération n'est pas validé\n\t");
						scanf("%d",&m);
						goto menu3;
					break;	
				}
    		break;
    		default:
    				SetColor(4);
						printf("\tc'est opération n'est pas validé\n\t");
						scanf("%d",&n);
						goto menup;
    		break;	
		}
	
	
}

    //MAIN FUNCTION 
    int main() {
    // specifeid charcters
    SetConsoleOutputCP(GetACP());
    SetConsoleCP(GetACP());
    // 

    SetColor(7);
    int i,j;
    SetColor(11);
    
    printf("\n\t\t\t\t \\");
    for(i=0;i<30;i++){
    	
    	printf("*");
    	// j'ai utilise ici usleep(1000microsecond) et non sleep car sleep(0.1) ne fonction pas  
    	usleep(1000);
	}
    printf("  Bienvenu !! ");
    for(i=0;i<30;i++){
    	printf("*");
    	usleep(1000);
	}
    printf("\\ \n\n");
    SetColor(9);
              // menu
    printf("\t1-> Ajouter un nouveau produit\n");
    usleep(100000);
    printf("\t2-> Ajouter plusieurs nouveaux produits\n");
    usleep(100000);
    printf("\t3-> Lister tous les produits \n");
    usleep(100000);
    printf("\t4-> Acheter un produit\n");
    usleep(100000);
    printf("\t5-> Rechercher des produits \n");
    usleep(100000);
    printf("\t6-> Etat du stock\n");
    usleep(100000);
    printf("\t7-> Alimenter le stock\n");
    usleep(100000);
    printf("\t8-> Supprimer les produits\n");
    usleep(100000);
    printf("\t9-> Statistique de vente\n\n");
    usleep(100000);
    SetColor(15);
    int numerooperation;
    do{
    printf("\tchoisire votre propre opération :\n");
    printf("\t");
    scanf("%d",&numerooperation);
	}while(numerooperation<1 || numerooperation>9);
	// system("cls") fonction pour exit in old menu and present another menu
    system("cls");
    // switch pour sortir d'un menu à un autre menu
    switch (numerooperation)
	{
    	case 1:
    	    AjouterProduit();
    	break;
    	case 2:
    		AjouterPlusiurProduit();
    	break;
    	case 3:
    		ListerProduit();
    	break;
    	case 4:
    		Acheterproduit();
    	break;
    	case 5:
    		RechercherProduits();
    	break;
    	case 6:
    		EtatStock();
    	break;
    	case 7:
    		AlimenterStock();
    	break;
    	case 8:
    	    SupprimerProduits();
    	break;
    	case 9:
    		StatistiqueVente();
    	break;
	}
	
	

	return 0;
}
