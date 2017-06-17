#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "interface.h"



odsloniete check;
int wyniki[2];
int licznik;
int licznik_zdjetych;
GtkWidget *first_score;
GtkWidget *second_score;
GtkWidget *who;
GtkWidget *interface_grid;
prysowanie pfirst;



int exists[64]; //load only



void interface_multi(GtkWidget *widget, prysowanie data)
{
    const char *second=gtk_entry_get_text(GTK_ENTRY(data->name));
    for (int i=0; i<15; i++)
        data->drugi_gracz[i]=second[i];
    data->drugi_gracz[15]='\0';
    licznik_zdjetych=wyniki[0]=wyniki[1]=licznik=0;
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



void multi_invert(GtkWidget *widget, prysowanie data)  //funkcja wywolywana po nacisnieciu kafelka
{

    if ((check.first != NULL) && (check.second != NULL))
    {
        if ( (check.number_first_awers) == (check.number_second_awers) )
        {

            if (check.first == widget || check.second == widget)
                return;
            wyniki[licznik%2]++;
            actualize_scores(data);
            gtk_widget_show_all(okno);
            licznik_zdjetych++;
            if (licznik_zdjetych == ((data->n*data->n)/2))
                game_over_screen_multi(pfirst);
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
            multi_invert(widget, data);
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
            multi_invert(widget, data);
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

        if ( (check.number_first_awers) != (check.number_second_awers) )
        {
            licznik++;
            whos_turn_now(data);
        }

        else
        {
            if (licznik_zdjetych+1 == ((data->n*data->n)/2))
                game_over_screen_multi(pfirst);
        }
    }
}




void interface_map_multi(prysowanie data)
{
    interface_grid=gtk_grid_new();
    gtk_widget_set_name(GTK_WIDGET(interface_grid), "counts");
    gtk_grid_set_column_homogeneous(GTK_GRID(interface_grid), TRUE);
    gtk_grid_set_row_homogeneous(GTK_GRID(interface_grid), TRUE);
    gtk_container_set_border_width(GTK_CONTAINER(interface_grid), 10);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), interface_grid, (data->n*2)+6, 0, (data->n)+data->n/2, (data->n*5)+2);
    GtkWidget *labelfirst=gtk_label_new("");
    GtkWidget *labelbottom=gtk_label_new("");
    GtkWidget *first_player;
    GtkWidget *second_player;
    GtkWidget *scores;
    GtkWidget *save;
    GtkWidget *pause;
    save=save_multi_button();
    pause=pause_multi_button(data);
    first_player=gtk_label_new(data->pierwszy_gracz);
    second_player=gtk_label_new(data->drugi_gracz);
    actualize_scores(data);
    scores=gtk_label_new("Wyniki:");
    gtk_widget_set_name(scores, "label");
    gtk_widget_set_name(first_player, "names");
    gtk_widget_set_name(second_player, "names");
    gtk_grid_attach(GTK_GRID(interface_grid), labelfirst, 0, 0, 10, 1);
    gtk_grid_attach(GTK_GRID(interface_grid), scores, 0, 3, 5, 4);
    gtk_grid_attach(GTK_GRID(interface_grid), first_player, 0, 6, 10, 4);
    gtk_grid_attach(GTK_GRID(interface_grid), second_player, 0, 13, 10, 4);
    gtk_grid_attach(GTK_GRID(interface_grid), save, 1, 30, 3, 2);
    gtk_grid_attach(GTK_GRID(interface_grid), pause, 6, 30, 3, 2);
    GtkWidget *now;
    now=gtk_label_new("Ruch gracza:");
    gtk_widget_set_name(now, "names");
    gtk_grid_attach(GTK_GRID(interface_grid), now, 0, 20, 4, 10);
    gtk_grid_attach(GTK_GRID(interface_grid), labelbottom, 0, 32, 10, 1);
    whos_turn_now(data);
}



void actualize_scores(prysowanie data)
{
    if (first_score != NULL)
        gtk_widget_destroy(first_score);
    if (second_score != NULL)
        gtk_widget_destroy(second_score);
    char fsc[3];
    sprintf(fsc, "%d", wyniki[0]);
    char ssc[3];
    sprintf(ssc, "%d", wyniki[1]);
    first_score=gtk_label_new(fsc);
    second_score=gtk_label_new(ssc);
    gtk_widget_set_name(GTK_WIDGET(first_score), "names");
    gtk_widget_set_name(GTK_WIDGET(second_score), "names");
    gtk_grid_attach(GTK_GRID(interface_grid), first_score, 0, 8, 10, 3);
    gtk_grid_attach(GTK_GRID(interface_grid), second_score, 0, 15, 10, 3);
}



void game_over_screen_multi(prysowanie data)
{
    char komunikat[38]={'W', 'y', 'g', 'r', 'y', 'w', 'a', ' ', 'g', 'r', 'a', 'c', 'z', ' '};

    if (wyniki[0]!=wyniki[1])
    {
        int i;

        if (wyniki[0]>wyniki[1])
        {
            for (i=0; i<15; i++)
            {
                komunikat[i+14]=data->pierwszy_gracz[i];
                if (data->pierwszy_gracz[i] == '\0')
                    break;
            }
        }

        else if (wyniki[1]>wyniki[0])
        {
            for (i=0; i<15; i++)
            {
                komunikat[i+14]=data->drugi_gracz[i];
                if (data->drugi_gracz[i] == '\0')
                    break;
            }
        }
    }

    else
    {
        for (int i=0; i<14; i++)
            komunikat[i]='\0';
        komunikat[0]='R';
        komunikat[1]='e';
        komunikat[2]='m';
        komunikat[3]='i';
        komunikat[4]='s';
        komunikat[5]='\0';
    }
    gtk_widget_destroy(first_score);
    first_score=NULL;
    gtk_widget_destroy(second_score);
    second_score=NULL;
    gtk_widget_destroy(who);
    who=NULL;
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
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), label, 0, 5, 10, 3);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), return_to_main_menu, 3, 9, 4, 2);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelbottom, 0, 12, 10, 5);
    gtk_container_add(GTK_CONTAINER(okno), siatka_na_przyciski);
    gtk_widget_show_all(okno);
    free(data);
}



void whos_turn_now(prysowanie data)
{
    if (who != NULL)
        gtk_widget_destroy(who);
    if (licznik%2 == 1)
        who=gtk_label_new(data->drugi_gracz);
    else
        who=gtk_label_new(data->pierwszy_gracz);
    gtk_widget_set_name(who, "names");
    gtk_grid_attach(GTK_GRID(interface_grid), who, 4, 20, 5, 10);
    gtk_widget_show_all(okno);
}



void save_multi(GtkWidget *widget, prysowanie data)
{
    FILE *plik;
    plik=fopen("data/txt/save_multi", "w");
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
    fputs(data->drugi_gracz, plik);
    putc('\n', plik);
    fprintf(plik, "%d", licznik_zdjetych);
    putc(' ', plik);
    fprintf(plik, "%d", licznik);
    putc(' ', plik);
    fprintf(plik, "%d", wyniki[0]);
    putc(' ', plik);
    fprintf(plik, "%d", wyniki[1]);
    fclose(plik);
}



void load_multi()
{
    int size;
    int a;
    int value;

    FILE *plik;
    plik=fopen("data/txt/save_multi", "r");
    if (plik == NULL)
        exit(0);
    value=fscanf(plik, "%d", &size);
    prysowanie data=(prysowanie)malloc( ( sizeof(rysowanie) )*(size*size));
    data[0].n=size;
    data[0].sekundy=0;
    data[0].tryb_gry=3;

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
    size=0;
    while ( (a=fgetc(plik)) != '\n'  && size<15)
        data[0].drugi_gracz[size++]=a;
    data[0].drugi_gracz[size]='\0';

    value=fscanf(plik, "%d", &licznik_zdjetych);
    value=fscanf(plik, "%d", &licznik);
    value=fscanf(plik, "%d", &wyniki[0]);
    value=fscanf(plik, "%d", &wyniki[1]);
    if (value == EOF)
        exit(0);
    fclose(plik);
    plik=fopen("data/txt/save_multi", "w");
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



GtkWidget *save_multi_button()
{
    GtkWidget *save;
    save=gtk_button_new_with_label("Zapisz");
    gtk_widget_set_name(save, "main_menu_button");
    g_signal_connect(G_OBJECT(save), "clicked", G_CALLBACK(save_multi), pfirst);
    return save;
}




GtkWidget *pause_multi_button(prysowanie data)
{
    GtkWidget *pause;
    pause=gtk_button_new_with_label("Pauza");
    gtk_widget_set_name(pause, "main_menu_button");
    g_signal_connect(G_OBJECT(pause), "clicked", G_CALLBACK(pause_multi_menu), data);
    return pause;
}



void pause_multi_menu(GtkWidget *widget, prysowanie data)
{
    FILE *plik;
    plik=fopen("data/txt/save_single", "w");
    fclose(plik);
    save_multi(widget, data);
    gtk_widget_destroy(first_score);
    first_score=NULL;
    gtk_widget_destroy(second_score);
    second_score=NULL;
    gtk_widget_destroy(who);
    who=NULL;
    gtk_widget_destroy(interface_grid);
    interface_grid=NULL;
    gtk_widget_destroy(siatka_na_przyciski);
    free(data);

    siatka_na_przyciski=gtk_grid_new();
    gtk_grid_set_column_homogeneous(GTK_GRID(siatka_na_przyciski), TRUE);
    gtk_grid_set_row_homogeneous(GTK_GRID(siatka_na_przyciski), TRUE);
    gtk_container_set_border_width(GTK_CONTAINER(siatka_na_przyciski), 10);
    GtkWidget *labeltop=gtk_label_new("");
    GtkWidget *labelbottom=gtk_label_new("");
    GtkWidget *labelfirst=gtk_label_new("");
    GtkWidget *resume;
    GtkWidget *menu;
    resume=resume_multi_button(1);
    menu=main_menu_button();
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labeltop, 0, 0, 12, 6);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), resume, 3, 7, 6, 2);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelfirst, 0, 8, 12, 2);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), menu, 3, 10, 6, 2);
    gtk_grid_attach(GTK_GRID(siatka_na_przyciski), labelbottom, 0, 12, 12, 6);
    gtk_container_add(GTK_CONTAINER(okno), siatka_na_przyciski);
    gtk_widget_show_all(okno);
}
