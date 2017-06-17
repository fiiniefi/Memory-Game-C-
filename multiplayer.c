#include <gtk/gtk.h>
#include <stdlib.h>
#include "interface.h"


void multi_menu()
{
    gtk_window_resize(GTK_WINDOW(okno), 1200, 800);
    gtk_widget_destroy(siatka_na_przyciski);
    siatka_na_przyciski=gtk_grid_new();
    gtk_grid_set_column_homogeneous(GTK_GRID(siatka_na_przyciski), TRUE);
    gtk_grid_set_row_homogeneous(GTK_GRID(siatka_na_przyciski), TRUE);
    gtk_container_set_border_width(GTK_CONTAINER(siatka_na_przyciski), 10);
    GtkWidget *labeltop=gtk_label_new("");
    GtkWidget *labelbottom=gtk_label_new("");
    GtkWidget *labelfirst=gtk_label_new("");
    GtkWidget *labelsecond=gtk_label_new("");
    GtkWidget *start=start_game();
    GtkWidget *back=return_button();
    GtkWidget *resume;

    FILE *plik;
    plik=fopen("data/txt/save_multi", "r");
    char a;
    a=fgetc(plik);
    if (a == EOF)
        resume=resume_multi_button(0);
    else
        resume=resume_multi_button(1);

    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labeltop, 0, 0, 8, 8);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), resume, 2, 6, 4, 3);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelfirst, 0, 10, 8, 1);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), start, 2, 11, 4, 3);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelsecond, 0, 15, 8, 1);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), back, 2, 16, 4, 3);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelbottom, 0, 17, 8, 8);
    gtk_container_add(GTK_CONTAINER(okno), siatka_na_przyciski);
    gtk_widget_show_all(okno);
}


GtkWidget *start_game()
{
    GtkWidget *start;
    start=gtk_button_new_with_label("Nowa Gra");
    prysowanie multi=(prysowanie)malloc( ( sizeof(rysowanie) )*64);
    multi[0].n=8;
    multi[0].tryb_gry=3;
    multi[0].sekundy=0;
    g_signal_connect(G_OBJECT(start), "clicked", G_CALLBACK(first_player_nickname), multi);
    gtk_widget_set_name(GTK_WIDGET(start), "main_menu_button");
    return start;
}



GtkWidget *resume_multi_button(bool what)
{
    GtkWidget *resume;
    resume=gtk_button_new_with_label("Wznów");
    gtk_widget_set_name(GTK_WIDGET(resume), "main_menu_button");
    if (what == 0)
        gtk_widget_set_sensitive(GTK_WIDGET(resume), FALSE);
    else
        g_signal_connect(G_OBJECT(resume), "clicked", G_CALLBACK(load_multi), NULL);
    return resume;
}
