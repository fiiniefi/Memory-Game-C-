#include <gtk/gtk.h>
#include <stdlib.h>
#include "interface.h"


void normal_menu()
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
    GtkWidget *labelthird=gtk_label_new("");
    GtkWidget *labelbottom=gtk_label_new("");
    GtkWidget *first=first_normal_button();
    GtkWidget *second=second_normal_button();
    GtkWidget *third=third_normal_button();
    GtkWidget *fourth=fourth_normal_button();
    GtkWidget *fifth=fifth_normal_button();
    GtkWidget *sixth=sixth_normal_button();
    GtkWidget *seventh=seventh_normal_button();
    GtkWidget *eight=eight_normal_button();
    GtkWidget *ninth=ninth_normal_button();
    GtkWidget *back=return_level_button();
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labeltop, 0, 0, 20, 1);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), first, 3, 1, 4, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), second, 8, 1, 4, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), third, 13, 1, 4, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelfirst, 0, 5, 20, 1);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), fourth, 3, 6, 4, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), fifth, 8, 6, 4, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), sixth, 13, 6, 4, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelsecond, 0, 10, 20, 1);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), seventh, 3, 11, 4, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), eight, 8, 11, 4, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), ninth, 13, 11, 4, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelthird, 0, 15, 20, 2);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), back, 10, 17, 9, 2);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelbottom, 0, 19, 20, 1);
    gtk_container_add(GTK_CONTAINER(okno), siatka_na_przyciski);
    gtk_widget_show_all(okno);
}


GtkWidget *first_normal_button()
{
    GtkWidget *first;
    first=gtk_button_new_with_label("1");
    prysowanie thirtysix=(prysowanie)malloc(sizeof(rysowanie)*36);
    thirtysix[0].n=6;
    thirtysix[0].tryb_gry=1;
    thirtysix[0].sekundy=90;
    g_signal_connect(G_OBJECT(first), "clicked", G_CALLBACK(first_player_nickname), thirtysix);
    gtk_widget_set_name(GTK_WIDGET(first), "level_button");
    return first;
}


GtkWidget *second_normal_button()
{
    GtkWidget *second;
    second=gtk_button_new_with_label("2");
    prysowanie thirtysix=(prysowanie)malloc(sizeof(rysowanie)*36);
    thirtysix[0].n=6;
    thirtysix[0].tryb_gry=1;
    thirtysix[0].sekundy=85;
    g_signal_connect(G_OBJECT(second), "clicked", G_CALLBACK(first_player_nickname), thirtysix);
    gtk_widget_set_name(GTK_WIDGET(second), "level_button");
    return second;
}


GtkWidget *third_normal_button()
{
    GtkWidget *third;
    third=gtk_button_new_with_label("3");
    prysowanie thirtysix=(prysowanie)malloc(sizeof(rysowanie)*36);
    thirtysix[0].n=6;
    thirtysix[0].tryb_gry=1;
    thirtysix[0].sekundy=80;
    g_signal_connect(G_OBJECT(third), "clicked", G_CALLBACK(first_player_nickname), thirtysix);
    gtk_widget_set_name(GTK_WIDGET(third), "level_button");
    return third;
}


GtkWidget *fourth_normal_button()
{
    GtkWidget *fourth;
    fourth=gtk_button_new_with_label("4");
    prysowanie thirtysix=(prysowanie)malloc(sizeof(rysowanie)*36);
    thirtysix[0].n=6;
    thirtysix[0].tryb_gry=1;
    thirtysix[0].sekundy=75;
    g_signal_connect(G_OBJECT(fourth), "clicked", G_CALLBACK(first_player_nickname), thirtysix);
    gtk_widget_set_name(GTK_WIDGET(fourth), "level_button");
    return fourth;
}


GtkWidget *fifth_normal_button()
{
    GtkWidget *fifth;
    fifth=gtk_button_new_with_label("5");
    prysowanie thirtysix=(prysowanie)malloc(sizeof(rysowanie)*36);
    thirtysix[0].n=6;
    thirtysix[0].tryb_gry=1;
    thirtysix[0].sekundy=70;
    g_signal_connect(G_OBJECT(fifth), "clicked", G_CALLBACK(first_player_nickname), thirtysix);
    gtk_widget_set_name(GTK_WIDGET(fifth), "level_button");
    return fifth;
}


GtkWidget *sixth_normal_button()
{
    GtkWidget *sixth;
    sixth=gtk_button_new_with_label("6");
    prysowanie thirtysix=(prysowanie)malloc(sizeof(rysowanie)*36);
    thirtysix[0].n=6;
    thirtysix[0].tryb_gry=1;
    thirtysix[0].sekundy=65;
    g_signal_connect(G_OBJECT(sixth), "clicked", G_CALLBACK(first_player_nickname), thirtysix);
    gtk_widget_set_name(GTK_WIDGET(sixth), "level_button");
    return sixth;
}


GtkWidget *seventh_normal_button()
{
    GtkWidget *seventh;
    seventh=gtk_button_new_with_label("7");
    prysowanie thirtysix=(prysowanie)malloc(sizeof(rysowanie)*36);
    thirtysix[0].n=6;
    thirtysix[0].tryb_gry=1;
    thirtysix[0].sekundy=60;
    g_signal_connect(G_OBJECT(seventh), "clicked", G_CALLBACK(first_player_nickname), thirtysix);
    gtk_widget_set_name(GTK_WIDGET(seventh), "level_button");
    return seventh;
}


GtkWidget *eight_normal_button()
{
    GtkWidget *eight;
    eight=gtk_button_new_with_label("8");
    prysowanie thirtysix=(prysowanie)malloc(sizeof(rysowanie)*36);
    thirtysix[0].n=6;
    thirtysix[0].tryb_gry=1;
    thirtysix[0].sekundy=55;
    g_signal_connect(G_OBJECT(eight), "clicked", G_CALLBACK(first_player_nickname), thirtysix);
    gtk_widget_set_name(GTK_WIDGET(eight), "level_button");
    return eight;
}


GtkWidget *ninth_normal_button()
{
    GtkWidget *ninth;
    ninth=gtk_button_new_with_label("9");
    prysowanie thirtysix=(prysowanie)malloc(sizeof(rysowanie)*36);
    thirtysix[0].n=6;
    thirtysix[0].tryb_gry=1;
    thirtysix[0].sekundy=50;
    g_signal_connect(G_OBJECT(ninth), "clicked", G_CALLBACK(first_player_nickname), thirtysix);
    gtk_widget_set_name(GTK_WIDGET(ninth), "level_button");
    return ninth;
}
