#include <gtk/gtk.h>
#include <stdlib.h>
#include "interface.h"


odsloniete check;
int licznik_zdjetych;
GtkWidget *how_many;
GtkWidget *interface_grid;
GtkWidget *secs;
prysowanie pfirst;

int seconds;
extern int exists[64];


void interface_single(GtkWidget *widget, prysowanie data)
{
    const char *name=gtk_entry_get_text(GTK_ENTRY(data->name));
    for (int i=0; i<15; i++)
        data->pierwszy_gracz[i]=name[i];
    data->pierwszy_gracz[15]='\0';

    seconds=licznik_zdjetych=0;
    pfirst=data;
    check.first=check.second=NULL;
    check.number_first_awers=check.number_first_position=check.number_second_awers=check.number_second_position=-1;

    set_position_and_n(data);
    set_skins(data);
    null_pictures(data);
    set_pictures(data);
    create_game_buttons(data);
    draw_map(data);
}



void single_invert(GtkWidget *widget, prysowanie data)
{
    if ((check.first != NULL) && (check.second != NULL))
    {
        if ( (check.number_first_awers) == (check.number_second_awers) )
        {

            if (check.first == widget || check.second == widget)
                return;
            licznik_zdjetych++;
            how_many_left(data);
            gtk_widget_show_all(okno);
            if (licznik_zdjetych == ((data->n*data->n)/2))
                game_over_screen_single(pfirst);
            gtk_widget_destroy(check.first);
            gtk_widget_destroy(check.second);
            GtkWidget *label1=gtk_label_new("");
            GtkWidget *label2=gtk_label_new("");
            gtk_grid_attach(GTK_GRID(siatka_na_przyciski), label1, (((check.number_first_position % data->n)*2)+1), (int)(((check.number_first_position/data->n)*5)+1), 2, 5); //dolaczenie w miejsce usunietego przycisku
            gtk_grid_attach(GTK_GRID(siatka_na_przyciski), label2, (((check.number_first_position % data->n)*2)+1), (int)(((check.number_first_position/data->n)*5)+1) , 2, 5); //dolaczenie w miejsce usunietego przycisku
            gtk_widget_show_all(GTK_WIDGET(okno));
            check.first=NULL;
            check.second=NULL;
            (data-(data->pozycja))[check.number_first_position].kafelek=NULL;
            (data-(data->pozycja))[check.number_second_position].kafelek=NULL;
            check.number_first_awers=check.number_second_awers=check.number_first_position=check.number_second_position-1;
            single_invert(widget, data);
        }

        else
        {
            (data-(data->pozycja))[check.number_first_position].awers=gtk_image_new_from_file((data-(data->pozycja))[check.number_first_position].awers_adres);  //ponowne stworzenie awersu
            (data-(data->pozycja))[check.number_second_position].awers=gtk_image_new_from_file((data-(data->pozycja))[check.number_second_position].awers_adres); //ponowne stworzenie awersu
            gtk_button_set_image(GTK_BUTTON(check.first), ((data-(data->pozycja))[check.number_first_position].rewers));
            gtk_button_set_image(GTK_BUTTON(check.second), ((data-(data->pozycja))[check.number_second_position].rewers));
            check.first=NULL;
            check.second=NULL;
            check.number_first_awers=check.number_second_awers=check.number_first_position=check.number_second_position-1;
            single_invert(widget, data);
        }
    }

    else if ( (check.first == NULL) && (check.second == NULL) )
    {
        data->rewers=gtk_image_new_from_file(data->rewers_adres);  //ponowne stworzenie rewersu
        gtk_button_set_image(GTK_BUTTON(widget), data->awers);
        check.first=widget;
        check.number_first_awers=data->numer_obrazka;
        check.number_first_position=data->pozycja;
    }

    else if ( check.second == NULL )
    {
        if (check.first == widget)
            return;
        data->rewers=gtk_image_new_from_file(data->rewers_adres); //ponowne stworzenie rewersu
        gtk_button_set_image(GTK_BUTTON(widget), data->awers);
        check.second=widget;
        check.number_second_awers=data->numer_obrazka;
        check.number_second_position=data->pozycja;
        if ( (check.number_first_awers) == (check.number_second_awers) )
        {
            if (licznik_zdjetych+1 == ((data->n*data->n)/2))
                game_over_screen_single(pfirst);
        }
    }
}



void interface_map_sixteen(prysowanie data)
{
    interface_grid=gtk_grid_new();
    gtk_widget_set_name(GTK_WIDGET(interface_grid), "counts");
    gtk_grid_set_column_homogeneous(GTK_GRID(interface_grid), TRUE);
    gtk_grid_set_row_homogeneous(GTK_GRID(interface_grid), TRUE);
    gtk_container_set_border_width(GTK_CONTAINER(interface_grid), 10);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), interface_grid, (((data->n)-1)*2)+5, 0, ((data->n)+data->n/2)+1, (data->n*5)+2);
    GtkWidget *labeltop=gtk_label_new("");
    GtkWidget *labelbottom=gtk_label_new("");
    GtkWidget *left;
    GtkWidget *seconds_left;
    GtkWidget *pause;
    pause=pause_single_button(data);
    left=gtk_label_new("Par na planszy:");
    gtk_widget_set_name(left, "label");
    seconds_left=gtk_label_new("Pozostało sekund:");
    gtk_widget_set_name(seconds_left, "secs");

    gtk_grid_attach(GTK_GRID(interface_grid), labeltop, 0, 0, 10, 6);
    gtk_grid_attach(GTK_GRID(interface_grid), left, 1, 2, 8, 4);
    how_many_left(data);
    gtk_grid_attach(GTK_GRID(interface_grid), seconds_left, 1, 12, 8, 4);
    seconds_init(data);
    gtk_grid_attach(GTK_GRID(interface_grid), pause, 1, 20, 8, 3);
    gtk_grid_attach(GTK_GRID(interface_grid), labelbottom, 0, 14, 10, 10);
}



void interface_map_thirtysix(prysowanie data)
{
    interface_grid=gtk_grid_new();
    gtk_widget_set_name(GTK_WIDGET(interface_grid), "counts");
    gtk_grid_set_column_homogeneous(GTK_GRID(interface_grid), TRUE);
    gtk_grid_set_row_homogeneous(GTK_GRID(interface_grid), TRUE);
    gtk_container_set_border_width(GTK_CONTAINER(interface_grid), 10);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), interface_grid, (((data->n)-1)*2)+6, 0, ((data->n)+data->n/2)+1, (data->n*5)+2);
    GtkWidget *labeltop=gtk_label_new("");
    GtkWidget *labelbottom=gtk_label_new("");
    GtkWidget *left;
    GtkWidget *seconds_left;
    GtkWidget *pause;
    pause=pause_single_button(data);
    left=gtk_label_new("Par na planszy:");
    gtk_widget_set_name(left, "label");
    seconds_left=gtk_label_new("Pozostało sekund:");
    gtk_widget_set_name(seconds_left, "secs");

    gtk_grid_attach(GTK_GRID(interface_grid), labeltop, 0, 0, 10, 6);
    gtk_grid_attach(GTK_GRID(interface_grid), left, 1, 2, 8, 4);
    how_many_left(data);
    gtk_grid_attach(GTK_GRID(interface_grid), seconds_left, 1, 12, 8, 4);
    seconds_init(data);
    gtk_grid_attach(GTK_GRID(interface_grid), pause, 1, 17, 8, 3);
    gtk_grid_attach(GTK_GRID(interface_grid), labelbottom, 0, 11, 10, 10);
}



void interface_map_sixtyfour(prysowanie data)
{
    interface_grid=gtk_grid_new();
    gtk_widget_set_name(GTK_WIDGET(interface_grid), "counts");
    gtk_grid_set_column_homogeneous(GTK_GRID(interface_grid), TRUE);
    gtk_grid_set_row_homogeneous(GTK_GRID(interface_grid), TRUE);
    gtk_container_set_border_width(GTK_CONTAINER(interface_grid), 10);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), interface_grid, (data->n*2)+6, 0, (data->n)+data->n/2, (data->n*5)+2);
    GtkWidget *labeltop=gtk_label_new("");
    GtkWidget *labelbottom=gtk_label_new("");
    GtkWidget *left;
    GtkWidget *seconds_left;
    GtkWidget *pause;
    pause=pause_single_button(data);
    left=gtk_label_new("Par na planszy:");
    gtk_widget_set_name(left, "label");
    seconds_left=gtk_label_new("Pozostało sekund:");
    gtk_widget_set_name(seconds_left, "secs");

    gtk_grid_attach(GTK_GRID(interface_grid), labeltop, 0, 0, 10, 6);
    gtk_grid_attach(GTK_GRID(interface_grid), left, 0, 2, 10, 4);
    how_many_left(data);
    gtk_grid_attach(GTK_GRID(interface_grid), seconds_left, 1, 12, 8, 4);
    seconds_init(data);
    gtk_grid_attach(GTK_GRID(interface_grid), pause, 1, 17, 8, 3);
    gtk_grid_attach(GTK_GRID(interface_grid), labelbottom, 0, 11, 10, 10);
}



void how_many_left(prysowanie data)
{
    if (how_many != NULL)
        gtk_widget_destroy(how_many);
    char number[3];
    sprintf(number, "%d", ((data->n*data->n)/2)-licznik_zdjetych);
    how_many=gtk_label_new(number);
    gtk_widget_set_name(how_many, "label");
    gtk_grid_attach(GTK_GRID(interface_grid), how_many, 3, 4, 4, 4);
    gtk_widget_show_all(okno);
}



void seconds_init(prysowanie data)
{
    char sec_tab[4];
    sprintf(sec_tab, "%d", data->sekundy-seconds);
    secs=gtk_label_new(sec_tab);
    gtk_widget_set_name(secs, "secs");
    seconds++;
    gtk_grid_attach(GTK_GRID(interface_grid), secs, 3, 14, 4, 4);
}



bool actualize_seconds(prysowanie data)
{
    if (data->istnieje_licznik == 0)
        return 0;
    if (secs != NULL)
        gtk_widget_destroy(secs);

    char sec_tab[4];
    sprintf(sec_tab, "%d", (data->sekundy)-seconds);
    seconds++;
    secs=gtk_label_new(sec_tab);
    gtk_widget_set_name(secs, "secs");
    gtk_grid_attach(GTK_GRID(interface_grid), secs, 3, 14, 4, 4);
    gtk_widget_show_all(okno);
    save_single(data);
    return 1;
}




void game_over_screen_single(prysowanie data)
{
    g_source_remove(data->control_timer);
    data->istnieje_licznik=0;
    FILE *plik;
    plik=fopen("data/txt/save_single", "w");
    fclose(plik);

    char komunikat[35]={'V', 'E', 'N', 'I', ',', ' ', 'V', 'I', 'D', 'I', ',', ' ', 'V', 'I', 'C', 'I', '\n', '~'};

    for (int i=0; i<15; i++)
    {
        komunikat[i+18]=data->pierwszy_gracz[i];
        if (data->pierwszy_gracz[i] == '\0')
            break;
    }

    char time[4];
    sprintf(time, "%d", seconds-1);
    char communique[14]={'C', 'z', 'a', 's', ' ', 'g', 'r', 'y', ':', ' '};
    for (int i=0; i<4; i++)
        communique[i+10]=time[i];
    GtkWidget *time_statement;
    time_statement=gtk_label_new(communique);
    gtk_widget_set_name(time_statement, "label");

    gtk_widget_destroy(how_many);
    how_many=NULL;
    gtk_widget_destroy(secs);
    secs=NULL;
    gtk_widget_destroy(interface_grid);
    interface_grid=NULL;
    gtk_widget_destroy(siatka_na_przyciski);
    siatka_na_przyciski=gtk_grid_new();
    gtk_grid_set_column_homogeneous(GTK_GRID(siatka_na_przyciski), TRUE);
    gtk_grid_set_row_homogeneous(GTK_GRID(siatka_na_przyciski), TRUE);
    gtk_grid_set_row_spacing(GTK_GRID(siatka_na_przyciski), 2);
    gtk_grid_set_column_spacing(GTK_GRID(siatka_na_przyciski), 2);
    gtk_container_set_border_width(GTK_CONTAINER(siatka_na_przyciski), 10);
    GtkWidget *label;
    GtkWidget *return_to_main_menu;
    GtkWidget *labelbottom=gtk_label_new("");
    GtkWidget *labeltop=gtk_label_new("");
    label=gtk_label_new(komunikat);
    gtk_widget_set_name(label, "label");
    return_to_main_menu=main_menu_button();
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labeltop, 0, 0, 10, 5);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), label, 0, 2, 10, 6);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), return_to_main_menu, 3, 7, 4, 2);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), time_statement, 0, 17, 10, 4);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelbottom, 0, 15, 10, 5);
    gtk_container_add(GTK_CONTAINER(okno), siatka_na_przyciski);
    gtk_widget_show_all(okno);
    free(data);
}



gint lose_screen(prysowanie data)
{
    g_source_remove(data->control_timer);
    data->istnieje_licznik=0;
    FILE *plik;
    plik=fopen("data/txt/save_single", "w");
    fclose(plik);
    gtk_widget_destroy(how_many);
    how_many=NULL;
    gtk_widget_destroy(secs);
    secs=NULL;
    gtk_widget_destroy(interface_grid);
    interface_grid=NULL;
    gtk_widget_destroy(siatka_na_przyciski);
    siatka_na_przyciski=gtk_grid_new();
    gtk_grid_set_column_homogeneous(GTK_GRID(siatka_na_przyciski), TRUE);
    gtk_grid_set_row_homogeneous(GTK_GRID(siatka_na_przyciski), TRUE);
    gtk_grid_set_row_spacing(GTK_GRID(siatka_na_przyciski), 2);
    gtk_grid_set_column_spacing(GTK_GRID(siatka_na_przyciski), 2);
    gtk_container_set_border_width(GTK_CONTAINER(siatka_na_przyciski), 10);
    GtkWidget *labeltop=gtk_label_new("");
    GtkWidget *labelbottom=gtk_label_new("");
    GtkWidget *label;
    label=gtk_label_new("Przegrałeś, spróbuj jeszcze raz!");
    gtk_widget_set_name(label, "label");
    GtkWidget *return_to_main_menu=main_menu_button();
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labeltop, 0, 0, 10, 5);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), label, 0, 5, 10, 6);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), return_to_main_menu, 3, 11, 4, 2);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelbottom, 0, 15, 10, 5);
    gtk_container_add(GTK_CONTAINER(okno), siatka_na_przyciski);
    gtk_widget_show_all(okno);
    free(data);
    return 0;
}



void save_single(prysowanie data)
{
    FILE *plik;
    plik=fopen("data/txt/save_single", "w");
    if (plik == NULL)
        exit(0);
    fprintf(plik, "%d", data->n);
    putc('\n', plik);

    for (int i=0; i<(data->n * data->n); i++)
    {
        if (data[i].kafelek == NULL)
            putc('0', plik);
        else
            putc('1', plik);
        putc(' ', plik);
    }
    putc('\n', plik);

    for (int i=0; i<(data->n*data->n); i++)
    {
        fprintf(plik, "%d", data[i].numer_obrazka);
        putc(' ', plik);
    }

    putc('\n', plik);
    fputs(data->pierwszy_gracz, plik);
    putc('\n', plik);
    fprintf(plik, "%d", data->tryb_gry);
    putc(' ', plik);
    fprintf(plik, "%d", licznik_zdjetych);
    putc(' ', plik);
    fprintf(plik, "%d", data->sekundy);
    putc(' ', plik);
    fprintf(plik, "%d", seconds-1);
    fclose(plik);
}



void load_single()
{
    int size;
    int a;
    int value;

    FILE *plik;
    plik=fopen("data/txt/save_single", "r");
    if (plik == NULL)
        exit(0);
    value=fscanf(plik, "%d", &size);

    prysowanie data=(prysowanie)malloc( ( sizeof(rysowanie) )*(size*size));
    data[0].n=size;

    for (int i=0; i<(data->n*data->n); i++)
    {
        value=fscanf(plik, "%d", &exists[i]);
    }

    for (int i=0; i<(data->n*data->n); i++)
    {
        value=fscanf(plik, "%d", &data[i].numer_obrazka);
    }

    size=0;
    a=fgetc(plik);
    a=fgetc(plik);
    while ( (a=fgetc(plik)) != '\n' && size<15)
        data[0].pierwszy_gracz[size++]=a;
    data[0].pierwszy_gracz[size]='\0';

    value=fscanf(plik, "%d", &data[0].tryb_gry);
    value=fscanf(plik, "%d", &licznik_zdjetych);
    value=fscanf(plik, "%d", &data->sekundy);
    value=fscanf(plik, "%d", &seconds);
    if (value == EOF)
        exit(0);

    fclose(plik);
    plik=fopen("data/txt/save_single", "w");
    fclose(plik);


    pfirst=data;
    check.first=check.second=NULL;
    check.number_first_awers=check.number_first_position=check.number_second_awers=check.number_second_position=-1;

    set_position_and_n(data);
    set_skins(data);
    null_pictures(data);
    set_pictures_load(data);
    create_game_buttons_load(data);
    draw_map(data);
}



GtkWidget *pause_single_button(prysowanie data)
{
    GtkWidget *pause;
    pause=gtk_button_new_with_label("Pauza");
    gtk_widget_set_name(pause, "main_menu_button");
    g_signal_connect(G_OBJECT(pause), "clicked", G_CALLBACK(pause_single_menu), data);
    return pause;
}



gint pause_single_menu(GtkWidget *widget, prysowanie data)
{
    FILE *plik;
    plik=fopen("data/txt/save_single", "w");
    if (plik == NULL)
        exit(0);
    fclose(plik);
    save_single(data);
    g_source_remove(data->control_timer);
    data->istnieje_licznik=0;
    free(data);
    gtk_widget_destroy(how_many);
    how_many=NULL;
    gtk_widget_destroy(secs);
    secs=NULL;
    gtk_widget_destroy(interface_grid);
    interface_grid=NULL;
    gtk_widget_destroy(siatka_na_przyciski);
    siatka_na_przyciski=gtk_grid_new();
    gtk_grid_set_column_homogeneous(GTK_GRID(siatka_na_przyciski), TRUE);
    gtk_grid_set_row_homogeneous(GTK_GRID(siatka_na_przyciski), TRUE);
    gtk_grid_set_row_spacing(GTK_GRID(siatka_na_przyciski), 2);
    gtk_grid_set_column_spacing(GTK_GRID(siatka_na_przyciski), 2);
    gtk_container_set_border_width(GTK_CONTAINER(siatka_na_przyciski), 10);

    GtkWidget *labeltop=gtk_label_new("");
    GtkWidget *labelbottom=gtk_label_new("");
    GtkWidget *labelfirst=gtk_label_new("");
    GtkWidget *resume;
    GtkWidget *menu;
    resume=resume_single_button(1);
    menu=main_menu_button();
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labeltop, 0, 0, 12, 6);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), resume, 3, 7, 6, 2);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelfirst, 0, 8, 12, 2);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), menu, 3, 10, 6, 2);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelbottom, 0, 12, 12, 6);
    gtk_container_add(GTK_CONTAINER(okno), siatka_na_przyciski);
    gtk_widget_show_all(okno);
    return 0;
}
