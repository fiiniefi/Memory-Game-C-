#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdbool.h>
#include "interface.h"


GtkWidget *return_level_button()
{
    GtkWidget *back;
    back=gtk_button_new_with_label("Powrót");
    g_signal_connect(G_OBJECT(back), "clicked", G_CALLBACK(single_menu), NULL);
    gtk_widget_set_name(GTK_WIDGET(back), "main_menu_button");
    return back;
}


GtkWidget *credits_label()
{
    GtkWidget *credits;
    credits=gtk_label_new("Marcin Drewniak, 2016");
    gtk_widget_set_name(GTK_WIDGET(credits), "names");
    return credits;
}


void first_player_nickname(GtkWidget *widget, prysowanie data)
{
    gtk_window_resize(GTK_WINDOW(okno), 1200, 800);
    data->name=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(data->name), 15);
    gtk_widget_destroy(siatka_na_przyciski);
    siatka_na_przyciski=gtk_grid_new();
    gtk_grid_set_column_homogeneous(GTK_GRID(siatka_na_przyciski), TRUE);
    gtk_grid_set_row_homogeneous(GTK_GRID(siatka_na_przyciski), TRUE);
    gtk_container_set_border_width(GTK_CONTAINER(siatka_na_przyciski), 10);
    GtkWidget *labelfirst=gtk_label_new("");
    GtkWidget *labelsecond=gtk_label_new("");
    GtkWidget *labelthird=gtk_label_new("");
    GtkWidget *labelfourth=gtk_label_new("");

    GtkWidget *order;
    if (data->tryb_gry == 3)
        order=gtk_label_new("Wprowadź imię pierwszego gracza");
    else if (data->tryb_gry == 2 || data->tryb_gry == 1 || data->tryb_gry == 0)
        order=gtk_label_new("Podaj swoje imię");
    else
        exit(0);
    GtkWidget *confirm=gtk_button_new_with_label("Zatwierdź");
    gtk_widget_set_name(GTK_WIDGET(order), "label");
    gtk_widget_set_name(GTK_WIDGET(confirm), "main_menu_button");

    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelfirst, 0, 0, 10, 3);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), order, 0, 4, 10, 5);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelsecond, 0, 10, 10, 1);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), data->name, 3, 7, 4, 3);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelthird, 0, 16, 10, 2);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), confirm, 3, 14, 4, 2);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelfourth, 0, 22, 10, 3);

    gtk_container_add(GTK_CONTAINER(okno), siatka_na_przyciski);
    gtk_widget_show_all(okno);

    if (data->tryb_gry == 0)
        g_signal_connect(G_OBJECT(confirm), "clicked", G_CALLBACK(interface_single), data);

    else if (data->tryb_gry == 1)
        g_signal_connect(G_OBJECT(confirm), "clicked", G_CALLBACK(interface_single), data);

    else if (data->tryb_gry == 2)
        g_signal_connect(G_OBJECT(confirm), "clicked", G_CALLBACK(interface_single), data);

    else if (data->tryb_gry == 3)
        g_signal_connect(G_OBJECT(confirm), "clicked", G_CALLBACK(second_player_nickname), data);
    else
        exit(0);
}


void second_player_nickname(GtkWidget *widget, prysowanie data)
{
    const char *first=gtk_entry_get_text(GTK_ENTRY(data->name));
    for (int i=0; i<15; i++)
        data->pierwszy_gracz[i]=first[i];
    data->pierwszy_gracz[15]='\0';

    gtk_window_resize(GTK_WINDOW(okno), 1200, 800);
    data->name=gtk_entry_new();
    gtk_entry_set_max_length(GTK_ENTRY(data->name), 15);
    gtk_widget_destroy(siatka_na_przyciski);
    siatka_na_przyciski=gtk_grid_new();
    gtk_grid_set_column_homogeneous(GTK_GRID(siatka_na_przyciski), TRUE);
    gtk_grid_set_row_homogeneous(GTK_GRID(siatka_na_przyciski), TRUE);
    gtk_container_set_border_width(GTK_CONTAINER(siatka_na_przyciski), 10);

    GtkWidget *labelfirst=gtk_label_new("");
    GtkWidget *labelsecond=gtk_label_new("");
    GtkWidget *labelthird=gtk_label_new("");
    GtkWidget *labelfourth=gtk_label_new("");

    GtkWidget *order=gtk_label_new("Wprowadź imię drugiego gracza");
    GtkWidget *confirm=gtk_button_new_with_label("Zatwierdź");
    gtk_widget_set_name(GTK_WIDGET(order), "label");
    gtk_widget_set_name(GTK_WIDGET(confirm), "main_menu_button");
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelfirst, 0, 0, 10, 3);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), order, 0, 4, 10, 5);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelsecond, 0, 10, 10, 1);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), data->name, 3, 7, 4, 3);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelthird, 0, 16, 10, 2);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), confirm, 3, 14, 4, 2);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelfourth, 0, 22, 10, 3);
    gtk_container_add(GTK_CONTAINER(okno), siatka_na_przyciski);
    gtk_widget_show_all(okno);

    g_signal_connect(G_OBJECT(confirm), "clicked", G_CALLBACK(interface_multi), data);
}
