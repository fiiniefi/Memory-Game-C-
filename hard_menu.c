#include <gtk/gtk.h>
#include <stdlib.h>
#include "interface.h"


void hard_menu()
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
    GtkWidget *first=first_hard_button();
    GtkWidget *second=second_hard_button();
    GtkWidget *third=third_hard_button();
    GtkWidget *fourth=fourth_hard_button();
    GtkWidget *fifth=fifth_hard_button();
    GtkWidget *sixth=sixth_hard_button();
    GtkWidget *seventh=seventh_hard_button();
    GtkWidget *eight=eight_hard_button();
    GtkWidget *ninth=ninth_hard_button();
    GtkWidget *tenth=tenth_hard_button();
    GtkWidget *eleventh=eleventh_hard_button();
    GtkWidget *twelfth=twelfth_hard_button();
    GtkWidget *back=return_level_button();
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labeltop, 0, 0, 19, 1);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), first, 2, 1, 3, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), second, 6, 1, 3, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), third, 10, 1, 3, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), fourth, 14, 1, 3, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelfirst, 0, 5, 19, 1);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), fifth, 2, 6, 3, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), sixth, 6, 6, 3, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), seventh, 10, 6, 3, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), eight, 14, 6, 3, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelsecond, 0, 10, 19, 1);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), ninth, 2, 11, 3, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), tenth, 6, 11, 3, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), eleventh, 10, 11, 3, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), twelfth, 14, 11, 3, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelthird, 0, 13, 19, 3);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), back, 9, 16, 9, 2);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelbottom, 0, 18, 19, 1);
    gtk_container_add(GTK_CONTAINER(okno), siatka_na_przyciski);
    gtk_widget_show_all(okno);
}


GtkWidget *first_hard_button()
{
    GtkWidget *first;
    first=gtk_button_new_with_label("1");
    prysowanie sixtyfour=(prysowanie)malloc(sizeof(rysowanie)*64);
    sixtyfour[0].n=8;
    sixtyfour[0].tryb_gry=2;
    sixtyfour[0].sekundy=180;
    g_signal_connect(G_OBJECT(first), "clicked", G_CALLBACK(first_player_nickname), sixtyfour);
    gtk_widget_set_name(GTK_WIDGET(first), "level_button");
    return first;
}


GtkWidget *second_hard_button()
{
    GtkWidget *second;
    second=gtk_button_new_with_label("2");
    prysowanie sixtyfour=(prysowanie)malloc(sizeof(rysowanie)*64);
    sixtyfour[0].n=8;
    sixtyfour[0].tryb_gry=2;
    sixtyfour[0].sekundy=170;
    g_signal_connect(G_OBJECT(second), "clicked", G_CALLBACK(first_player_nickname), sixtyfour);
    gtk_widget_set_name(GTK_WIDGET(second), "level_button");
    return second;
}


GtkWidget *third_hard_button()
{
    GtkWidget *third;
    third=gtk_button_new_with_label("3");
    prysowanie sixtyfour=(prysowanie)malloc(sizeof(rysowanie)*64);
    sixtyfour[0].n=8;
    sixtyfour[0].tryb_gry=2;
    sixtyfour[0].sekundy=160;
    g_signal_connect(G_OBJECT(third), "clicked", G_CALLBACK(first_player_nickname), sixtyfour);
    gtk_widget_set_name(GTK_WIDGET(third), "level_button");
    return third;
}


GtkWidget *fourth_hard_button()
{
    GtkWidget *fourth;
    fourth=gtk_button_new_with_label("4");
    prysowanie sixtyfour=(prysowanie)malloc(sizeof(rysowanie)*64);
    sixtyfour[0].n=8;
    sixtyfour[0].tryb_gry=2;
    sixtyfour[0].sekundy=150;
    g_signal_connect(G_OBJECT(fourth), "clicked", G_CALLBACK(first_player_nickname), sixtyfour);
    gtk_widget_set_name(GTK_WIDGET(fourth), "level_button");
    return fourth;
}


GtkWidget *fifth_hard_button()
{
    GtkWidget *fifth;
    fifth=gtk_button_new_with_label("5");
    prysowanie sixtyfour=(prysowanie)malloc(sizeof(rysowanie)*64);
    sixtyfour[0].n=8;
    sixtyfour[0].tryb_gry=2;
    sixtyfour[0].sekundy=140;
    g_signal_connect(G_OBJECT(fifth), "clicked", G_CALLBACK(first_player_nickname), sixtyfour);
    gtk_widget_set_name(GTK_WIDGET(fifth), "level_button");
    return fifth;
}


GtkWidget *sixth_hard_button()
{
    GtkWidget *sixth;
    sixth=gtk_button_new_with_label("6");
    prysowanie sixtyfour=(prysowanie)malloc(sizeof(rysowanie)*64);
    sixtyfour[0].n=8;
    sixtyfour[0].tryb_gry=2;
    sixtyfour[0].sekundy=130;
    g_signal_connect(G_OBJECT(sixth), "clicked", G_CALLBACK(first_player_nickname), sixtyfour);
    gtk_widget_set_name(GTK_WIDGET(sixth), "level_button");
    return sixth;
}


GtkWidget *seventh_hard_button()
{
    GtkWidget *seventh;
    seventh=gtk_button_new_with_label("7");
    prysowanie sixtyfour=(prysowanie)malloc(sizeof(rysowanie)*64);
    sixtyfour[0].n=8;
    sixtyfour[0].tryb_gry=2;
    sixtyfour[0].sekundy=120;
    g_signal_connect(G_OBJECT(seventh), "clicked", G_CALLBACK(first_player_nickname), sixtyfour);
    gtk_widget_set_name(GTK_WIDGET(seventh), "level_button");
    return seventh;
}


GtkWidget *eight_hard_button()
{
    GtkWidget *eight;
    eight=gtk_button_new_with_label("8");
    prysowanie sixtyfour=(prysowanie)malloc(sizeof(rysowanie)*64);
    sixtyfour[0].n=8;
    sixtyfour[0].tryb_gry=2;
    sixtyfour[0].sekundy=110;
    g_signal_connect(G_OBJECT(eight), "clicked", G_CALLBACK(first_player_nickname), sixtyfour);
    gtk_widget_set_name(GTK_WIDGET(eight), "level_button");
    return eight;
}


GtkWidget *ninth_hard_button()
{
    GtkWidget *ninth;
    ninth=gtk_button_new_with_label("9");
    prysowanie sixtyfour=(prysowanie)malloc(sizeof(rysowanie)*64);
    sixtyfour[0].n=8;
    sixtyfour[0].tryb_gry=2;
    sixtyfour[0].sekundy=100;
    g_signal_connect(G_OBJECT(ninth), "clicked", G_CALLBACK(first_player_nickname), sixtyfour);
    gtk_widget_set_name(GTK_WIDGET(ninth), "level_button");
    return ninth;
}


GtkWidget *tenth_hard_button()
{
    GtkWidget *tenth;
    tenth=gtk_button_new_with_label("10");
    prysowanie sixtyfour=(prysowanie)malloc(sizeof(rysowanie)*64);
    sixtyfour[0].n=8;
    sixtyfour[0].tryb_gry=2;
    sixtyfour[0].sekundy=90;
    g_signal_connect(G_OBJECT(tenth), "clicked", G_CALLBACK(first_player_nickname), sixtyfour);
    gtk_widget_set_name(GTK_WIDGET(tenth), "level_button");
    return tenth;
}


GtkWidget *eleventh_hard_button()
{
    GtkWidget *eleventh;
    eleventh=gtk_button_new_with_label("11");
    prysowanie sixtyfour=(prysowanie)malloc(sizeof(rysowanie)*64);
    sixtyfour[0].n=8;
    sixtyfour[0].tryb_gry=2;
    sixtyfour[0].sekundy=80;
    g_signal_connect(G_OBJECT(eleventh), "clicked", G_CALLBACK(first_player_nickname), sixtyfour);
    gtk_widget_set_name(GTK_WIDGET(eleventh), "level_button");
    return eleventh;
}


GtkWidget *twelfth_hard_button()
{
    GtkWidget *twelfth;
    twelfth=gtk_button_new_with_label("12");
    prysowanie sixtyfour=(prysowanie)malloc(sizeof(rysowanie)*64);
    sixtyfour[0].n=8;
    sixtyfour[0].tryb_gry=2;
    sixtyfour[0].sekundy=75;
    g_signal_connect(G_OBJECT(twelfth), "clicked", G_CALLBACK(first_player_nickname), sixtyfour);
    gtk_widget_set_name(GTK_WIDGET(twelfth), "level_button");
    return twelfth;
}
