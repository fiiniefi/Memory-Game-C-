#include <gtk/gtk.h>
#include <stdlib.h>
#include "interface.h"


void single_menu()
{
    gtk_window_resize(GTK_WINDOW(okno), 1200, 800);
    gtk_widget_destroy(siatka_na_przyciski);
    siatka_na_przyciski=gtk_grid_new();
    gtk_grid_set_column_homogeneous(GTK_GRID(siatka_na_przyciski), TRUE);
    gtk_grid_set_row_homogeneous(GTK_GRID(siatka_na_przyciski), TRUE);
    gtk_container_set_border_width(GTK_CONTAINER(siatka_na_przyciski), 10);
    gtk_container_set_border_width(GTK_CONTAINER(siatka_na_przyciski), 10);
    GtkWidget *labeltop=gtk_label_new("");
    GtkWidget *labelbottom=gtk_label_new("");
    GtkWidget *labelfirst=gtk_label_new("");
    GtkWidget *labelsecond=gtk_label_new("");
    GtkWidget *labelthird=gtk_label_new("");
    GtkWidget *labelfourth=gtk_label_new("");
    GtkWidget *easy=easy_button();
    GtkWidget *normal=normal_button();
    GtkWidget *hard=hard_button();
    GtkWidget *back=return_button();
    GtkWidget *resume;
    FILE *plik=fopen("data/txt/save_single", "r");
    char a;
    a=fgetc(plik);
    if (a == EOF)
        resume=resume_single_button(0);
    else
        resume=resume_single_button(1);

    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labeltop, 0, 0, 8, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), resume, 2, 5, 4, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelfirst, 0, 10, 8, 1);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), easy, 2, 11, 4, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelsecond, 0, 16, 8, 1);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), normal, 2, 17, 4, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelthird, 0, 22, 8, 1);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), hard, 2, 23, 4, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelfourth, 0, 28, 8, 1);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), back, 2, 29, 4, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelbottom, 0, 34, 8, 4);
    gtk_container_add(GTK_CONTAINER(okno), siatka_na_przyciski);
    gtk_widget_show_all(okno);
}


GtkWidget *easy_button()
{
    GtkWidget *easy;
    easy=gtk_button_new_with_label("Łatwy");
    g_signal_connect(G_OBJECT(easy), "clicked", G_CALLBACK(easy_menu), NULL);
    gtk_widget_set_name(GTK_WIDGET(easy), "main_menu_button");
    return easy;
}


GtkWidget *normal_button()
{
    GtkWidget *normal;
    normal=gtk_button_new_with_label("Normalny");
    g_signal_connect(G_OBJECT(normal), "clicked", G_CALLBACK(normal_menu), NULL);
    gtk_widget_set_name(GTK_WIDGET(normal), "main_menu_button");
    return normal;
}


GtkWidget *hard_button()
{
    GtkWidget *hard;
    hard=gtk_button_new_with_label("Trudny");
    g_signal_connect(G_OBJECT(hard), "clicked", G_CALLBACK(hard_menu), NULL);
    gtk_widget_set_name(GTK_WIDGET(hard), "main_menu_button");
    return hard;
}


GtkWidget *return_button()
{
    GtkWidget *back;
    back=gtk_button_new_with_label("Powrót");
    g_signal_connect(G_OBJECT(back), "clicked", G_CALLBACK(glowne_menu), NULL);
    gtk_widget_set_name(GTK_WIDGET(back), "main_menu_button");
    return back;
}



GtkWidget *resume_single_button(bool what)
{
    GtkWidget *resume;
    resume=gtk_button_new_with_label("Wznów");
    gtk_widget_set_name(GTK_WIDGET(resume), "main_menu_button");
    if (what == 0)
        gtk_widget_set_sensitive(GTK_WIDGET(resume), FALSE);
    else
        g_signal_connect(G_OBJECT(resume), "clicked", G_CALLBACK(load_single), NULL);
    return resume;
}
