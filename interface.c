#include <gtk/gtk.h>
#include "interface.h"


void zdefiniuj_okno()
{
    okno=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(okno), "Memory Game");
    gtk_window_set_default_size(GTK_WINDOW(okno), 1200, 800);
    gtk_window_set_position(GTK_WINDOW(okno), GTK_WIN_POS_CENTER_ALWAYS);
    gtk_window_set_resizable(GTK_WINDOW(okno), TRUE);
    //gtk_window_set_hide_titlebar_when_maximized(GTK_WINDOW(okno), TRUE);
    //gtk_window_fullscreen(GTK_WINDOW(okno));
    gtk_window_set_skip_taskbar_hint(GTK_WINDOW(okno), FALSE);
    gtk_window_set_icon_from_file(GTK_WINDOW(okno), "data/txt/img/ikona.png", NULL);
    g_signal_connect(G_OBJECT(okno), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    //GtkWidget *tlo;
    //tlo=gtk_image_new_from_file("data/img/tlo2.jpg");
    kontener=gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    //gtk_box_pack_start(GTK_BOX(kontener), tlo, TRUE, TRUE, 0);
}

void glowne_menu()
{
    if (siatka_na_przyciski != NULL)
        gtk_widget_destroy(siatka_na_przyciski);
    gtk_window_resize(GTK_WINDOW(okno), 1920, 1080);
    siatka_na_przyciski=gtk_grid_new();
    gtk_grid_set_column_homogeneous(GTK_GRID(siatka_na_przyciski), TRUE);
    gtk_grid_set_row_homogeneous(GTK_GRID(siatka_na_przyciski), TRUE);
    gtk_container_set_border_width(GTK_CONTAINER(siatka_na_przyciski), 10);
    GtkWidget *labeltop=gtk_label_new("");
    GtkWidget *labelbottom=gtk_label_new("");
    GtkWidget *labelfirst=gtk_label_new("");
    GtkWidget *labelsecond=gtk_label_new("");
    GtkWidget *single=single_button();
    GtkWidget *multi=multi_button();
    GtkWidget *exit=exit_button();
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labeltop, 0, 0, 8, 8);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), single, 2, 6, 4, 3);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelfirst, 0, 10, 8, 1);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), multi, 2, 11, 4, 3);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelsecond, 0, 15, 8, 1);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), exit, 2, 16, 4, 3);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelbottom, 0, 17, 8, 8);
    /*GtkWidget *image=gtk_image_new_from_file("data/txt/img/button_skin.png");
    GtkWidget *layout=gtk_layout_new(NULL, NULL);
    GtkWidget *but=gtk_button_new();
    gtk_layout_put(GTK_LAYOUT(layout), GTK_WIDGET(image), 0, 0);
    gtk_button_set_image(GTK_BUTTON(but), GTK_WIDGET(layout));
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), but, 0, 25, 4, 4);*/
    gtk_container_add(GTK_CONTAINER(okno), siatka_na_przyciski);
    gtk_widget_show_all(okno);
}


GtkWidget *single_button()
{
    GtkWidget *single;
    single=gtk_button_new_with_label("Jeden Gracz");
    gtk_widget_set_name(GTK_WIDGET(single), "main_menu_button");
    g_signal_connect(G_OBJECT(single), "clicked", G_CALLBACK(single_menu), NULL);
    return single;
}


GtkWidget *multi_button()
{
    GtkWidget *multi;
    multi=gtk_button_new_with_label("Dwóch Graczy");
    gtk_widget_set_name(GTK_WIDGET(multi), "main_menu_button");
    g_signal_connect(G_OBJECT(multi), "clicked", G_CALLBACK(multi_menu), NULL);
    return multi;
}


GtkWidget *exit_button()
{
    GtkWidget *exit;
    exit=gtk_button_new_with_label("Wyjdź");
    gtk_widget_set_name(GTK_WIDGET(exit), "main_menu_button");
    g_signal_connect(G_OBJECT(exit), "clicked", G_CALLBACK(gtk_main_quit), NULL);
    return exit;
}
