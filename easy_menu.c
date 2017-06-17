#include <gtk/gtk.h>
#include <stdlib.h>
#include "interface.h"


void easy_menu()
{
    gtk_window_resize(GTK_WINDOW(okno), 1200, 800);
    gtk_widget_destroy(siatka_na_przyciski);
    siatka_na_przyciski=gtk_grid_new();
    gtk_grid_set_column_homogeneous(GTK_GRID(siatka_na_przyciski), TRUE);
    gtk_grid_set_row_homogeneous(GTK_GRID(siatka_na_przyciski), TRUE);
    gtk_container_set_border_width(GTK_CONTAINER(siatka_na_przyciski), 10);
    GtkWidget *labeltop=gtk_label_new("");
    GtkWidget *labelfirst=gtk_label_new("");
    GtkWidget *labelsecond=gtk_label_new("");
    GtkWidget *labelbottom=gtk_label_new("");
    GtkWidget *first=first_easy_button();
    GtkWidget *second=second_easy_button();
    GtkWidget *third=third_easy_button();
    GtkWidget *fourth=fourth_easy_button();
    GtkWidget *fifth=fifth_easy_button();
    GtkWidget *sixth=sixth_easy_button();
    GtkWidget *back=return_level_button();
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labeltop, 0, 0, 24, 2);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), first, 5, 3, 4, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), second, 10, 3, 4, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), third, 15, 3, 4, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelsecond, 0, 8, 24, 1);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), fourth, 5, 9, 4, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), fifth, 10, 9, 4, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), sixth, 15, 9, 4, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelfirst, 0, 14, 24, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), back, 12, 18, 11, 2);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelbottom, 0, 21, 24, 1);
    gtk_container_add(GTK_CONTAINER(okno), siatka_na_przyciski);
    gtk_widget_show_all(okno);
}



GtkWidget *first_easy_button()
{
    GtkWidget *first;
    first=gtk_button_new_with_label("1");
    prysowanie sixteen=(prysowanie)malloc(sizeof( rysowanie ) * 16);
    sixteen[0].n=4;
    sixteen[0].tryb_gry=0;
    sixteen[0].sekundy=40;
    g_signal_connect(G_OBJECT(first), "clicked", G_CALLBACK(first_player_nickname), sixteen);
    gtk_widget_set_name(GTK_WIDGET(first), "level_button");
    return first;
}


GtkWidget *second_easy_button()
{
    GtkWidget *second;
    second=gtk_button_new_with_label("2");
    prysowanie sixteen=(prysowanie)malloc(sizeof( rysowanie ) * 16);
    sixteen[0].n=4;
    sixteen[0].tryb_gry=0;
    sixteen[0].sekundy=35;
    g_signal_connect(G_OBJECT(second), "clicked", G_CALLBACK(first_player_nickname), sixteen);
    gtk_widget_set_name(GTK_WIDGET(second), "level_button");
    return second;
}


GtkWidget *third_easy_button()
{
    GtkWidget *third;
    third=gtk_button_new_with_label("3");
    prysowanie sixteen=(prysowanie)malloc(sizeof( rysowanie ) * 16);
    sixteen[0].n=4;
    sixteen[0].tryb_gry=0;
    sixteen[0].sekundy=30;
    g_signal_connect(G_OBJECT(third), "clicked", G_CALLBACK(first_player_nickname), sixteen);
    gtk_widget_set_name(GTK_WIDGET(third), "level_button");
    return third;
}


GtkWidget *fourth_easy_button()
{
    GtkWidget *fourth;
    fourth=gtk_button_new_with_label("4");
    prysowanie sixteen=(prysowanie)malloc(sizeof( rysowanie ) * 16);
    sixteen[0].n=4;
    sixteen[0].tryb_gry=0;
    sixteen[0].sekundy=26;
    g_signal_connect(G_OBJECT(fourth), "clicked", G_CALLBACK(first_player_nickname), sixteen);
    gtk_widget_set_name(GTK_WIDGET(fourth), "level_button");
    return fourth;
}


GtkWidget *fifth_easy_button()
{
    GtkWidget *fifth;
    fifth=gtk_button_new_with_label("5");
    prysowanie sixteen=(prysowanie)malloc(sizeof( rysowanie ) * 16);
    sixteen[0].n=4;
    sixteen[0].tryb_gry=0;
    sixteen[0].sekundy=22;
    g_signal_connect(G_OBJECT(fifth), "clicked", G_CALLBACK(first_player_nickname), sixteen);
    gtk_widget_set_name(GTK_WIDGET(fifth), "level_button");
    return fifth;
}


GtkWidget *sixth_easy_button()
{
    GtkWidget *sixth;
    sixth=gtk_button_new_with_label("6");
    prysowanie sixteen=(prysowanie)malloc(sizeof( rysowanie ) * 16);
    sixteen[0].n=4;
    sixteen[0].tryb_gry=0;
    sixteen[0].sekundy=18;
    g_signal_connect(G_OBJECT(sixth), "clicked", G_CALLBACK(first_player_nickname), sixteen);
    gtk_widget_set_name(GTK_WIDGET(sixth), "level_button");
    return sixth;
}
