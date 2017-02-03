#include "libgraphique.h"
#include <stdio.h>
int n;/* nombre de tours */
int victoire;
float t[10][9]; /* ne tableau ne sera graphiquement que de 7 par 6 mais on rajoute 3 pour les tests (voir void Resultat) */
int posa = 0;
int posx = 1 ;
int posy = 7 ;
int k ; // pour l'ordinateur : savoir si il a joué ou pas
int choix;
choix=0;
void animation (int x ,int y)
{
while(x<640){
x=x+1;
draw_line (10,10,x,y);
update_graphics();
}
}
void gros_trait_horizontal (int xa, int ya , int xb , int yb, int g)
{
    int i;
    for (i=0 ; i<g ; i++)
    {
    draw_line (xa,ya+i,xb,yb+i);
    }

}
void gros_trait_vertical (int xa, int ya , int xb , int yb, int g)
{
    int i;
    for (i=0 ; i<g ; i++)
    {
    draw_line (xa+i,ya,xb+i,yb);
    }

}

void animation_horizontale (int xa ,int ya, int xb, int yb , int xc, int yc, int xd, int yd, int g)
{

 while(xb<400)
    {
    xb=xb+1;
    gros_trait_horizontal(xa,ya,xb,yb, g);
    xd=xd-1;
    gros_trait_horizontal(xc,yc,xd-1,yd, g);
    update_graphics();
    }
}

void animation_verticale (int xa ,int ya, int xb, int yb , int xc, int yc, int xd, int yd, int g)
{

    while( yb<450)
    {
    yb=yb+1;
    gros_trait_vertical(xa,ya+20,xb,yb, g);
    yd=yd-1;
    gros_trait_vertical(xc,yc+9,xd,yd, g);
    update_graphics();
    }

}
void rectangle_menu (int xa, int ya, int xb, int yb , int xc, int yc, int xd, int yd)
{
    gros_trait_horizontal(xa,ya,400,yb, 10);
    gros_trait_horizontal(xc,yc,220-1,yd, 10);

    gros_trait_vertical(xa,ya,xb,450, 3);
    gros_trait_vertical(xa+4,ya,xb+4,450, 3);
    gros_trait_vertical(xa+8,ya,xb+8,450, 3);

    gros_trait_vertical(xc,390,xd,yd+10, 3);
    gros_trait_vertical(xc+4,390,xd+4,yd+10, 3);
    gros_trait_vertical(xc+8,390,xd+8,yd+10, 3);
}
void affichage_menu()
{
int xa,ya,xb,yb,xc,yc,xd,yd;
xa=220;
ya=390;
xb=220;
yb=390;
xc=400;
yc=450;
xd=400;
yd=450;
    start_graphics();
        set_drawing_color(color_BLACK);/* = set_background_color(color_BLACK) */
        draw_rectangle_full(0,0,680,680);
        set_font(font_HELVETICA_18);
        set_background_color(color_BLACK);
            set_drawing_color(color_LIGHTRED);
            draw_printf(255,415,"PUIS ");
            set_drawing_color(color_YELLOW);
            draw_printf(299,415,"SANCE ");
            draw_printf(370,416,"4");
    set_drawing_color(color_WHITE);
    set_font(font_HELVETICA_18);
    draw_printf(225,300,"Joueur contre Joueur");
    draw_printf(225,230,"Joueur contre Ordinateur");
    draw_printf(225,160,"Regles");
    draw_printf(225,90,"Credits");
            set_drawing_color(color_RED) ;
            animation_horizontale(xa,ya,xb,yb,xc,yc,xd,yd,10);
            animation_verticale(xa,ya,xb,yb,xc,yc,xd,yd,3);
            animation_verticale(xa+4,ya,xb+4,yb,xc+4,yc,xd+4,yd,3);
            animation_verticale(xa+8,ya,xb+8,yb,xc+8,yc,xd+8,yd,3);
    update_graphics();
}

void changement_couleur(int n)
{
      set_drawing_color(color_WHITE);
    set_font(font_HELVETICA_18);
    if (posa==n)
     set_drawing_color(color_LIGHTCYAN);

}

void menu()
{
    set_background_color(color_BLACK);
int xa,ya,xb,yb,xc,yc,xd,yd;
xa=220;
ya=390;
xb=220;
yb=390;
xc=400;
yc=450;
xd=400;
yd=450;
while (choix==0)
{

    set_drawing_color(color_RED);

    rectangle_menu (xa, ya, xb, yb, xc, yc, xd, yd);
    set_font(font_HELVETICA_18);
     set_drawing_color(color_LIGHTRED);
    draw_printf(255,415,"PUIS ");
    set_drawing_color(color_YELLOW);
    draw_printf(299,415,"SANCE ");
    draw_printf(370,416,"4");
    changement_couleur(3) ;
    draw_printf(225,300,"Joueur contre Joueur");

    changement_couleur(2) ;
    draw_printf(225,230,"Joueur contre Ordinateur");

    changement_couleur(1) ;
    draw_printf(225,160,"Regles");

    changement_couleur(0) ;
    draw_printf(225,90,"Credits");
    cursor_menu();
    update_graphics();

    	switch(get_key())
    	{

		case key_UP:
		    if (posa<3)
            {
                posa++;
            }
			break;
        case key_DOWN:
             if (posa>0)
             {
                posa--;
             }
			break;
        case key_RIGHT:
            choix=posa+1;
			break;
    	}
    	clear_screen();
}
}
void rectangle(int n, int m)
{
n=n+2;
m=m+2;
int step=640/(n);
int step2=480/(m);
set_drawing_color(color_BLUE) ;
draw_rectangle_full(step,step2,(step*n)-(step),(step2*m)-(step2));
}
void cursor_menu()
	{
	set_drawing_color(color_WHITE) ;
	draw_circle_full(190,100+(posa*70),10) ;
	set_drawing_color(color_RED) ;
	draw_circle(190,100+(posa*70),10) ;
	}
void cursor()
	{
	set_drawing_color(color_GREEN) ;
	draw_circle_full(posx*(640/9)+(640/9/2),posy*(480/8)+(480/8/2),10) ;
	set_drawing_color(color_BLACK) ;
	draw_circle(posx*(640/9)+(640/9/2),posy*(480/8)+(480/8/2),10) ; /* LE 640/9/2 SERT A CE QUE LE POINT SOIT AU MILIEU D'UNE CASE */
	}
void pas_pion()
{
int x,y;
for (x=0 ; x<7 ; x++)
{
    for (y=0 ; y<6 ; y++)
    {
        if ((t[x][y])==0)
        {
            set_drawing_color(color_WHITE) ;
            draw_circle_full((x+1)*(640/9)+(640/9/2),(y+1)*(480/8)+(480/8/2),25);
            set_drawing_color(color_BLACK) ;
            draw_circle((x+1)*(640/9)+(640/9/2),(y+1)*(480/8)+(480/8/2),25);/* LE TABLEAU DEMARRE A LA CASE 0 DONC ON EST DECALES DE 1 DONC +1 */

        }

    }

}
}
void pion_j1()
{
int x,y;
for (x=0 ; x<7 ; x++)
{
    for (y=0 ; y<6 ; y++)
    {
        if ((t[x][y])==2)
        {
            set_drawing_color(color_RED) ;
            draw_circle_full((x+1)*(640/9)+(640/9/2),(y+1)*(480/8)+(480/8/2),25);
            set_drawing_color(color_BLACK) ;
            draw_circle((x+1)*(640/9)+(640/9/2),(y+1)*(480/8)+(480/8/2),25);/* LE TABLEAU DEMARRE A LA CASE 0 DONC ON EST DECALES DE 1 DONC +1 */
        }
    }
}
}
void pion_j2()
{
int x,y;
for (x=0 ; x<7 ; x++)
{
    for (y=0 ; y<6 ; y++)
    {
        if ((t[x][y])==1)
        {
            set_drawing_color(color_YELLOW) ;
            draw_circle_full((x+1)*(640/9)+(640/9/2),(y+1)*(480/8)+(480/8/2),25);
           set_drawing_color(color_BLACK) ;
            draw_circle((x+1)*(640/9)+(640/9/2),(y+1)*(480/8)+(480/8/2),25); /* LE TABLEAU DEMARRE A LA CASE 0 DONC ON EST DECALES DE 1 DONC +1 */
        }
    }
}
}
int tour_joueur (int x)
{
    if (x%2==0)
        return 0;
    else
        return 1;
}
void nombre_tours(int n)
{
set_drawing_color(color_BLACK);
set_font(font_HELVETICA_18);
draw_printf(430, 30,"Tour numero : %d",n);
}
void refresh(int c, int l, int n)
{
rectangle(c,l);
pas_pion();
pion_j1();
pion_j2();
nombre_tours(n);
}

void Resultat(int n)
{
    int i,j;
    for (i=0;i<7;i++)
        for (j=0;j<8;j++)
        //test l'issue de jeu du joueur 1
        {
                if ((t[i][j]==1)&&(t[i+1][j]==1)&&(t[i+2][j]==1)&&(t[i+3][j]==1)) //horizontale
                {
                victoire=1;
                }
                else if ((t[i][j]==1)&&(t[i][j+1]==1)&&(t[i][j+2]==1)&&(t[i][j+3]==1)) //verticale
                {
                 victoire=1;
                }
                else if ((t[i][j]==1)&&(t[i+1][j-1]==1)&&(t[i+2][j-2]==1)&&(t[i+3][j-3]==1)) //diagonale gauche
                {
                  victoire=1;
                }
                else if ((t[i][j]==1)&&(t[i+1][j+1]==1)&&(t[i+2][j+2]==1)&&(t[i+3][j+3]==1)) //diagonale droite
                {
                 victoire=1;

                }

        //test l'issue de jeu du joueur 2
             else if ((t[i][j]==2)&&(t[i+1][j]==2)&&(t[i+2][j]==2)&&(t[i+3][j]==2)) //horizontale
              {
                 victoire=2;

              }
             else if ((t[i][j]==2)&&(t[i][j+1]==2)&&(t[i][j+2]==2)&&(t[i][j+3]==2)) //verticale
              {
                 victoire=2;

              }
             else if ((t[i][j]==2)&&(t[i+1][j-1]==2)&&(t[i+2][j-2]==2)&&(t[i+3][j-3]==2)) //diagonale gauche
              {
                 victoire=2;

              }
             else if ((t[i][j]==2)&&(t[i+1][j+1]==2)&&(t[i+2][j+2]==2)&&(t[i+3][j+3]==2)) //diagonale droite
              {
                 victoire=2;

              }
              else if (n==42)
              {
                  victoire=3;
              }
         }
}

void fin (int a, int b, int n)
{
    int j;
    if (n==42)
    {
    j=3;
    }
    else if (n==n%2)
    {
    j=2;
    }
    else
    {
    j=1;
    }
start_graphics();
set_background_color(color_LIGHTGRAY);
rectangle(a,b);
refresh(a,b,n);
update_graphics();
set_drawing_color(color_WHITE) ;
set_font(font_HELVETICA_18);
if(j==1)
{
    draw_printf(240,440,"Le joueur %d gagne !",j);
    set_drawing_color(color_YELLOW) ;
    draw_circle_full(450,450,15);
     set_drawing_color(color_BLACK) ;
    draw_circle(450,450,15);
     set_drawing_color(color_YELLOW) ;
    draw_circle_full(180,450,15);
     set_drawing_color(color_BLACK) ;
    draw_circle(180,450,15);
}
else if(j==2)
{
    draw_printf(240,440,"Le joueur %d gagne !",j);
     set_drawing_color(color_RED) ;
    draw_circle_full(450,450,15);
     set_drawing_color(color_BLACK) ;
    draw_circle(450,450,15);
     set_drawing_color(color_RED) ;
    draw_circle_full(180,450,15);
     set_drawing_color(color_BLACK) ;
    draw_circle(180,450,15);
}
else if(j==3)
{
draw_printf(270,440,"Match Nul !",j);
     set_drawing_color(color_RED) ;
    draw_circle_full(450,450,15);
     set_drawing_color(color_BLACK) ;
    draw_circle(450,450,15);
     set_drawing_color(color_YELLOW) ;
    draw_circle_full(180,450,15);
     set_drawing_color(color_BLACK) ;
    draw_circle(180,450,15);
}
set_drawing_color(color_RED) ;
draw_printf(70, 30,"Press UP : Quit");
draw_printf(70, 1,"Press DOWN : Menu");

}
void mode_joueur_contre_joueur()
{
int x,y;
int a,b;
a=7;
b=6; /* UNE GRILLE DE PUISSANCE 4 CONTIENT 7 LIGNES ET 6 COLONNES */
for (x=0 ; x<10 ; x++)
{
    for (y=0 ; y<9 ; y++)     /* On créer un tableau plus grand en arrière plan pour que les tests ne soient pas faussés (voir void Resultat) */
    {
    t[x][y]=0;
    }
}
n=0;
victoire=0;
  /* FIN DE L'INITIALISATION */

set_background_color(color_LIGHTGRAY);
rectangle(a,b);
/* show_grid(a,b); */
cursor(a ,b) ;
nombre_tours(n);
update_graphics();
while(victoire==0)
{                   /* TANT QUE LE DRAPEAU (=FIN DE PARTIE ) N'EST PAS LEVE */
	clear_screen();
	refresh(a, b,n);
	cursor(a, b);
	update_graphics();
	switch(get_key()){

		case key_LEFT:
		    if (posx>1)
			posx--;
			break;
		case key_RIGHT:
		    if (posx<a)
			posx++;
			break;
        case key_DOWN:
if(tour_joueur(n)==0) /* SI CEST AU TOUR DU JAUNE*/
            {
            if ((t[posx-1][0])==0)   /* GALERE IL FAUT SIMPLIFIER */
            {t[posx-1][0]=1;
            n=n+1;}
            else if ((t[posx-1][1])==0)
            {t[posx-1][1]=1;
            n=n+1;}
             else if ((t[posx-1][2])==0)
            {t[posx-1][2]=1;
            n=n+1;}
             else if ((t[posx-1][3])==0)
            {t[posx-1][3]=1;
            n=n+1;}
             else if ((t[posx-1][4])==0)
            {t[posx-1][4]=1;
            n=n+1;}
            else if ((t[posx-1][5])==0)
            {t[posx-1][5]=1;
            n=n+1;}
            else if ((t[posx-1][5])==1||t[posx-1][5]==2)
            {
            n=n;
            } /* COMPTEUR DE TOURS*/
            }
else if(tour_joueur(n)==1) /*SI CEST AU TOUR DU BLEU*/
            {
            if ((t[posx-1][0])==0)   /* GALERE IL FAUT SIMPLIFIER */
            {t[posx-1][0]=2;
            n=n+1;}
            else if ((t[posx-1][1])==0)
            {t[posx-1][1]=2;
            n=n+1;}
             else if ((t[posx-1][2])==0)
            {t[posx-1][2]=2;
            n=n+1;}
             else if ((t[posx-1][3])==0)
            {t[posx-1][3]=2;
            n=n+1;}
             else if ((t[posx-1][4])==0)
            {t[posx-1][4]=2;
            n=n+1;}
            else if ((t[posx-1][5])==0)
            {t[posx-1][5]=2;
            n=n+1;}
            else if ((t[posx-1][5])==1||t[posx-1][5]==2)
            {n=n;/* COMPTEUR DE TOURS*/
            }
            break;
		}
    }
  Resultat(n);
    }
    clear_screen();
    fin(a,b,n);
    update_graphics();
        switch(get_key())
    {

		case key_UP:
		 clear_screen();
			break;
		case key_DOWN:
		    choix=0;
		    clear_screen();
		    main();
			break;
    }

}
void placer_pion_droite_gauche(int i, int j)
{

    if ((i+3)<7) //Si on ne dépasse pas le bord              //PLACER UN PION A DROITE
    {
        if ((t[i+3][j]==0)) //si la case a droite de la ligne est vide
        {
            if ((j-1)>(0-1))  // si on est "dans les airs"
            {
                if ((t[i+3][j-1])==0)
                {
                placer_pion_gauche(i,j); // on regarde si on peut poser a gauche
                }
                else
                {
                t[i+3][j]=2;
                n=n+1;
                k=1;
                i=7;
                j=6;
                }
            }
            else  // si on est au sol
            {
            t[i+3][j]=2;
            n=n+1;
            k=1;
            i=7;
            j=6;
            }
        }
        else
        {
        placer_pion_gauche(i,j); // La case est prise a droite donc on regarde si on peut poser a gauche
        }
    }
    else        // On dépasse le bord donc on regarde si on peut poser a gauche
    {
    placer_pion_gauche(i,j);
    }

}
void placer_pion_gauche(int i, int j)
{
   if ((i-1)>(0-1))   // la case a droite est prise, donc on regarde si on PEUT poser a gauche
    {
        if ((t[i-1][j]==0))  // si la case a gauche de cette ligne est vide
        {
            if ((j-1)>(0-1))  // si on est "dans les airs"
            {
                if ((t[i-1][j-1])==0) // si la case d'en dessous (j-1) est vide on ne peut PAS poser
                {
                n=n; // ne rien faire, car on aura déja esseyé de jouer a droite
                }
                else              // si cette case est prise on peut poser
                {
                t[i-1][j]=2;
                n=n+1;
                k=1;
                i=7;
                j=6;
                }
            }
            else  // si on est au sol
            {
            t[i-1][j]=2;
            n=n+1;
            k=1;
            i=7;
            j=6;
            }
        } // pas de else : donc si la case a gauche est prise, ne rien faire
    }  // pareil ici mais pour le bord a gauche
}
void placer_pion_diago_bas_droite (int i, int j)
{
 if(((i+3)<7) && ((j-3)>(-1)))  // si on ne touche pas le bord a droite et en bas                      1
{
    if ((t[i+3][j-3]==0))
    {
        if ((j-4)>(0-1))   // si on est "dans les airs"
        {
            if ((t[i+3][j-4]==0)) //si la case d'en dessous est vide
            {
            placer_pion_diago_haut_gauche(i,j);                 // on esseye alors a gauche
            }
            else
            {
            t[i+3][j-3]=2;
            n=n+1;
            k=1;
            i=7;
            j=6;
            }
        }
        else // si on est "au sol"
        {
        t[i+3][j-3]=2;
        n=n+1;
        k=1;
        i=7;
        j=6;
        }
    }
    else // si la case est prise on esseye a gauche
    {
    placer_pion_diago_haut_gauche(i,j);
    }
}
else // si on est aux bords du tableau
{
placer_pion_diago_haut_gauche(i,j);
}
}
void placer_pion_diago_haut_gauche(int i,int j)
{
    if(((i-1)>(0-1)) && ((j+1)<6))  // si on ne touche pas le bord a gauche et en haut
    {
                if ((t[i-1][j+1]==0))
                {
                   if ((t[i-1][j]==0)) //si la case d'en dessous est vide
                    {
                    n=n;                // on ne fais rien
                    }
                   else
                    {
                    t[i-1][j+1]=2;
                    n=n+1;
                    k=1;
                    i=7;
                    j=6;
                    }
                }
    }
}
void placer_pion_diago_haut_droite(int i,int j)
{
    if(((i+3)<7) && ((j+3)<6))  // si on ne touche pas le bord a gauche et en haut           1
    {
                if ((t[i+3][j+3]==0))
                {
                   if ((t[i+3][j+2]==0)) //si la case d'en dessous est vide
                    {
                    n=n;                // on ne fais rien
                    }
                   else
                    {
                    t[i+3][j+3]=2;
                    n=n+1;
                    k=1;
                    i=7;
                    j=6;
                    }
                }
    }
}
void contre_deux_pions_droite_gauche(int i , int j)
{
if ((t[i][j]==1)&&(t[i+1][j]==1)&& (k==0)) //horizontale 2 pions ALIGNES pour ,notamment, empêcher de perdre dès le début ...
{
        if ((i+2)<7) //Si on ne dépasse pas le bord              //PLACER UN PION A DROITE
        {
            if ((t[i+2][j]==0)) //si la case a droite de la ligne est vide
            {
                if ((j-1)>(0-1))  // si on est "dans les airs"
                {
                    if ((t[i+2][j-1])==0)
                    {
                    contre_deux_pions_gauche(i,j); // on regarde si on peut poser a gauche
                    }
                    else
                    {
                    t[i+2][j]=2;
                    n=n+1;
                    k=1;
                    i=7;
                    j=6;
                    }
                }
            else  // si on est au sol
            {
            t[i+2][j]=2;
            n=n+1;
            k=1;
            i=7;
            j=6;
            }
        }
        else
        {
        contre_deux_pions_gauche(i,j); // La case est prise a droite donc on regarde si on peut poser a gauche
        }
    }
    else        // On dépasse le bord donc on regarde si on peut poser a gauche
    {
    contre_deux_pions_gauche(i,j);
    }
}
}
void contre_deux_pions_gauche(int i , int j)
{
        if ((i-1)>(-1)) //Si on ne dépasse pas le bord              //PLACER UN PION A GAUCHE
        {
            if ((t[i-1][j]==0)) //si la case a Gauche de la ligne est vide
            {
                if ((j-1)>(0-1))  // si on est "dans les airs"
                {
                    if ((t[i-1][j-1])==0)
                    {
                   n=n; // on ne fais rien car on aura déja esseyé a droite
                    }
                    else
                    {
                    t[i-1][j]=2;
                    n=n+1;
                    k=1;
                    i=7;
                    j=6;
                    }
                }
                else  // si on est au sol
                {
                t[i-1][j]=2;
                n=n+1;
                k=1;
                i=7;
                j=6;
                }
            }
        }
}
void tour_ordinateur()
{
k=0;
int i,j;


    for (i=0;i<7;i++)
    for (j=0;j<6;j++)
    {
                if ((t[i][j]==1)&&(t[i][j+1]==1)&&(t[i][j+2]==1)&& (k==0)) //verticale 3pions
                {
                    if ((j+3)<6)
                    {
                        if ((t[i][j+3]==0))
                        {
                            t[i][j+3]=2;
                            n=n+1;
                            k=1;
                            i=7;
                            j=6;
                        }
                    }
                }
                if ((t[i][j]==1)&&(t[i+1][j]==1)&&(t[i+2][j]==1) && (k==0)) //horizontale 3pions ALIGNES
                {
                placer_pion_droite_gauche(i,j);
                }
                if ((t[i][j]==1)&&(t[i+2][j]==1)&&(t[i+3][j]==1) && (k==0)) // horizontale 3 pions separes 1011
                {
                    if ((t[i+1][j]==0))          // si cette case est vide
                    {
                        if ((j-1)>(0-1))   // si on est "dans les airs"
                        {
                            if ((t[i+1][j-1]==0)) //si la case d'en dessous est vide
                            {
                            n=n;                  // ne rien faire
                            }
                            else
                            {
                            t[i+1][j]=2;
                            n=n+1;
                            k=1;
                            i=7;
                            j=6;
                            }

                        }
                        else
                        {
                        t[i+1][j]=2;
                        n=n+1;
                        k=1;
                        i=7;
                        j=6;
                        }
                    }
                }
                if ((t[i][j]==1)&&(t[i+1][j]==1)&&(t[i+3][j]==1) && (k==0)) // horizontale 3 pions separes 1101
                {
                      if ((t[i+2][j]==0))          // si cette case est vide
                    {
                        if ((j-1)>(0-1))   // si on est "dans les airs"
                        {
                            if ((t[i+2][j-1]==0)) //si la case d'en dessous est vide
                            {
                            n=n;                  // ne rien faire
                            }
                            else
                            {
                            t[i+2][j]=2;
                            n=n+1;
                            k=1;
                            i=7;
                            j=6;
                            }

                        }
                        else // si on est "au sol"
                        {
                        t[i+2][j]=2;
                        n=n+1;
                        k=1;
                        i=7;
                        j=6;
                        }
                    }
                }

                if ((t[i][j]==1)&&(t[i+1][j-1]==1)&&(t[i+2][j-2]==1) && (k==0)) //diagonale gauche en haut 3pions ALIGNES 1
                {                                                                                                            //  1
                placer_pion_diago_bas_droite (i,j);                                                                           //   1
                }
                if ((t[i][j]==1)&&(t[i+1][j-1]==1)&&(t[i+3][j-3]==1) && (k==0)) //diagonale gauche 3pions non-ALIGNES 1101
                {
                    if ((t[i+2][j-2]==0))
                    {
                                if ((t[i+2][j-3]==0)) //si la case d'en dessous est vide
                                {
                                n=n;
                                }
                                else
                                {
                                t[i+2][j-2]=2;
                                n=n+1;
                                k=1;
                                i=7;
                                j=6;
                                }

                    }
                }
                if ((t[i][j]==1)&&(t[i+2][j-2]==1)&&(t[i+3][j-3]==1) && (k==0)) //diagonale gauche 3pions non-ALIGNES 1011
                {
                    if ((t[i+1][j-1]==0))
                    {
                                if ((t[i+1][j-2]==0)) //si la case d'en dessous est vide
                                {
                                n=n;
                                }
                                else
                                {
                                t[i+1][j-1]=2;
                                n=n+1;
                                k=1;
                                i=7;
                                j=6;
                                }

                    }
                }
                if ((t[i][j]==1)&&(t[i+1][j+1]==1)&&(t[i+2][j+2]==1) && (k==0)) //diagonale droite 3pions ALIGNES     1 A VERIFIER
                {                                                                                                   //   1
                     if(((i-1)>(-1)) && ((j-1)>(-1)))  // si on ne touche pas le bord a gauche et en bas                1
                     {
                        if ((t[i-1][j-1]==0))
                        {
                            if ((j-2)>(0-1))   // si on est "dans les airs"
                            {
                                if ((t[i-1][j-2]==0)) //si la case d'en dessous est vide
                                {
                                placer_pion_diago_haut_droite(i,j);                 // on esseye alors en haut a droite
                                }
                                else
                                {
                                t[i-1][j-1]=2;
                                n=n+1;
                                k=1;
                                i=7;
                                j=6;
                                }

                            }
                            else // si on est "au sol"
                            {
                            t[i-1][j-1]=2;
                            n=n+1;
                            k=1;
                            i=7;
                            j=6;
                            }
                        }
                        else // si la case est prise on esseye en haut a droite
                        {
                        placer_pion_diago_haut_droite(i,j);
                        }

                    }
                     else
                    {
                    placer_pion_diago_haut_droite(i,j);
                    }
                }
                if ((t[i][j]==1)&&(t[i+1][j+1]==1)&&(t[i+3][j+3]==1) && (k==0))    // diago droite 1101
                {
                    if ((t[i+2][j+2]==0))
                    {
                        if ((t[i+2][j+1]==0)) //si la case d'en dessous est vide
                            {
                            n=n;
                            }
                            else
                            {
                            t[i+2][j+2]=2;
                            n=n+1;
                            k=1;
                            i=7;
                            j=6;
                            }
                    }
                }
                if ((t[i][j]==1)&&(t[i+2][j+2]==1)&&(t[i+3][j+3]==1) && (k==0))    // diago droite 1011
                {
                    if ((t[i+1][j+1]==0))
                    {
                            if ((t[i+1][j]==0)) //si la case d'en dessous est vide
                            {
                            n=n;
                            }
                            else
                            {
                            t[i+1][j+1]=2;
                            n=n+1;
                            k=1;
                            i=7;
                            j=6;
                            }
                    }
                }
                if ((t[i][j]==1)&&(t[i+1][j]==1)&& (k==0)) //horizontale 2 pions ALIGNES pour ,notamment, empêcher de perdre dès le début ...
                {
                contre_deux_pions_droite_gauche(i ,j);
                }
        }

 if (k==0) // si l'ordinateur n'a pas déja joué , il joue sur la premiere case vide qu'il repère
 {
        for (i=0;i<7;i++)
    for (j=0;j<6;j++)
    {
            if ((t[i][0])==0)
            {
            t[i][0]=2;
            n=n+1;
            i=7;
            j=6;
             }
            else if ((t[i][1])==0)
            {
            t[i][1]=2;
            n=n+1;
            i=7;
            j=6;
            }
             else if ((t[i][2])==0)
            {
            t[i][2]=2;
            n=n+1;
            i=7;
            j=6;
             }
             else if ((t[i][3])==0)
            {
            t[i][3]=2;
            n=n+1;
            i=7;
            j=6;
            }
             else if ((t[i][4])==0)
            {
            t[i][4]=2;
            n=n+1;
            i=7;
            j=6;
            }
            else if ((t[i][5])==0)
            {
            t[i][5]=2;
            n=n+1;
            i=7;
            j=6;
            }
    }
 }
}


  void mode_joueur_contre_ordi()
{
int x,y;
int a,b;
a=7;
b=6; /* UNE GRILLE DE PUISSANCE 4 CONTIENT 7 LIGNES ET 6 COLONNES */
for (x=0 ; x<10 ; x++)
{
    for (y=0 ; y<9 ; y++)     /* On créer un tableau plus grand en arrière plan pour que les tests ne soient pas faussés (voir void Resultat) */
    {
    t[x][y]=0;
    }
}
n=0;
victoire=0;
  /* FIN DE L'INITIALISATION */

set_background_color(color_LIGHTGRAY);
rectangle(a,b);
cursor(a ,b) ;
nombre_tours(n);
update_graphics();
while(victoire==0)
{                   /* TANT QUE LE DRAPEAU (=FIN DE PARTIE ) N'EST PAS LEVE */
	clear_screen();
	refresh(a,b,n);
	cursor(a,b);
	update_graphics();
	if(tour_joueur(n)==0)
{

	switch(get_key())
	{

		case key_LEFT:
		    if (posx>1)
			posx--;
			break;
		case key_RIGHT:
		    if (posx<a)
			posx++;
			break;
        case key_DOWN:
            if ((t[posx-1][0])==0)
            {t[posx-1][0]=1;
            n=n+1;}
            else if ((t[posx-1][1])==0)
            {t[posx-1][1]=1;
            n=n+1;}
             else if ((t[posx-1][2])==0)
            {t[posx-1][2]=1;
            n=n+1;}
             else if ((t[posx-1][3])==0)
            {t[posx-1][3]=1;
            n=n+1;}
             else if ((t[posx-1][4])==0)
            {t[posx-1][4]=1;
            n=n+1;}
            else if ((t[posx-1][5])==0)
            {t[posx-1][5]=1;
            n=n+1;}
            else if ((t[posx-1][5])==1||t[posx-1][5]==2)
            {
            n=n;
            }
    }
}
else if(tour_joueur(n)==1) /*SI CEST AU TOUR DU BLEU*/
            {
            tour_ordinateur();
            }
  Resultat(n);
}
    clear_screen();
    fin(a,b,n);
    update_graphics();
        switch(get_key())
    {

		case key_UP:
		 clear_screen();
			break;
		case key_DOWN:
		    choix=0;
		    clear_screen();
		    main();
			break;
    }

}
void regles()
{
        set_drawing_color(color_BLACK);
        draw_rectangle_full(0,0,640,480);
        set_drawing_color(color_WHITE);
        set_font(font_HELVETICA_18);
        draw_printf(280,410,"Regles");
        draw_printf(150,300,"<-- ou --> pour deplacer le curseur");
        draw_printf(153,258,"|");
        draw_printf(150,245,"v");
        draw_printf(150,250,"   pour selectionner la colonne de jeu");
        draw_printf(150,200,"Le but est d'aligner 4 pions d'une meme couleur.");
        draw_printf(150,180,"Vous pouvez aligner les pions a l'horizontale,");
        draw_printf(150,160,"en verticale ou en diagonale.");
        set_font(font_HELVETICA_12);
        draw_printf(10, 30,"Press UP : Quit");
        draw_printf(10, 1,"Press DOWN : Menu");
        update_graphics();

    switch(get_key())
    {

		case key_UP:
		 clear_screen();
			break;
		case key_DOWN:
		    choix=0;
		    clear_screen();
		    main();
			break;
    }


}
void credits ()
{
    set_drawing_color(color_BLACK);
    draw_rectangle_full(0,0,640,480);
    set_drawing_color(color_WHITE);
    set_font(font_HELVETICA_18);
    draw_printf(280,410,"Credits");
    draw_printf(100,320,"Cree par Ugo Tagnati et Olivier Mignot");
    draw_printf(470,100,"Annee 2014/2015");
    draw_printf(20,100,"L1 Math-Info");
    draw_printf(90,250,"Remerciements a : Mr Philippe JEGOU");
    draw_printf(245,230,"Mme Valerie CAMPILLO");
    update_graphics();
    set_font(font_HELVETICA_12);
    draw_printf(10, 30,"Press UP : Quit");
    draw_printf(10, 1,"Press DOWN : Menu");
    update_graphics();

    switch(get_key())
    {

		case key_UP:
		 clear_screen();
			break;
		case key_DOWN:
		    {
            choix=0;
		    clear_screen();
		    main();
		    }
			break;
    }

}
int main (void)
{

start_graphics();
set_background_color(color_BLACK);
affichage_menu();
menu();
if (choix==4)
{
    mode_joueur_contre_joueur();
}
if (choix==3)
{
    mode_joueur_contre_ordi();
}
else if (choix==2)
{
    regles();
}
else if (choix==1)
{
    credits();
}
}

