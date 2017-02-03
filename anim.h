#ifndef ANIM_H_INCLUDED
#define ANIM_H_INCLUDED

#include <stdio.h>
#include "libgraphique.h"


int cooy = 0;
int posx = 1;
int posy = 1;
int t[8][7];
int joueur = 1 ;
int c;
int victoire = 0;

// animation

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
        void animation (int x ,int y)
        {
        while(x<640){
        x=x+1;
        draw_line (10,10,x,y);
        update_graphics();
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

        void curs_menu()
        {
            set_drawing_color(color_WHITE);
            draw_circle(245,362+(75*cooy),10);
        }

        void anim()
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
            set_drawing_color(color_BLACK);
                draw_rectangle_full(0,0,640,480);
                set_drawing_color(color_WHITE);
                set_font(font_HELVETICA_18);
                curs_menu();
                //draw_printf(255,415,"PUISSANCE 4");
                draw_printf(280,350,"J1 Vs J2");
                draw_printf(260,275,"Joueur Vs IA");
                draw_printf(285,200,"Credits");
                draw_printf(287,125,"Regles");
                draw_printf(290,50,"Quitter");
                set_font(font_HELVETICA_10);
                set_drawing_color(color_RED) ;
                        animation_horizontale(xa,ya,xb,yb,xc,yc,xd,yd,10);
                        animation_verticale(xa,ya,xb,yb,xc,yc,xd,yd,3);
                        animation_verticale(xa+4,ya,xb+4,yb,xc+4,yc,xd+4,yd,3);
                        animation_verticale(xa+8,ya,xb+8,yb,xc+8,yc,xd+8,yd,3);
                        update_graphics();

            }

#endif // ANIM_H_INCLUDED
