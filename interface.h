#include <gtk/gtk.h>
#include <stdbool.h>



typedef struct rys* prysowanie;
typedef struct rys
{
    int n;  //wymiar nxn
    int pozycja;  //pozycja w tablicy [n/2][n%2]
    GtkWidget *kafelek;  //button
    GtkWidget *rewers;  //skin
    GtkWidget *awers;  //obrazek
    GtkWidget *name; //entry1
    GtkWidget *name_second; //entry2
    char *rewers_adres;  //adres skina
    char *awers_adres;  //adres obrazka
    char pierwszy_gracz[16];
    char drugi_gracz[16];
    int sekundy;
    int numer_obrazka;  //numer obrazka w tablicy stringow
    bool istnieje_licznik;
    int tryb_gry; //0 - 4x4, 1 - 6x6, 2 - 8x8, 3 - multi
    guint control_timer;
}rysowanie;


typedef struct odsl
{
    GtkWidget *first;
    int number_first_awers;
    int number_first_position;
    GtkWidget *second;
    int number_second_awers;
    int number_second_position;
}odsloniete;


extern char *najmniejsze[92];
extern char *srednie[92];
extern char *najwieksze[92];


/***************interface.c***************/
GtkWidget *okno;
GtkWidget *siatka_na_przyciski;
GtkWidget *kontener;


void zdefiniuj_okno();
void glowne_menu();
GtkWidget *single_button();
GtkWidget *multi_button();
GtkWidget *exit_button();
/***************interface.c***************/



/***************gtk_css.c***************/
void gtk_css();
/***************gtk_css.c***************/



/***************single_player.c***************/
void single_menu();
GtkWidget *easy_button();
GtkWidget *normal_button();
GtkWidget *hard_button();
GtkWidget *return_button();
GtkWidget *resume_single_button(bool what);
/***************single_player.c***************/



/***************multiplayer.c***************/
void multi_menu();
GtkWidget *start_game();
GtkWidget *resume_multi_button(bool what);
/***************multiplayer.c***************/



/***************easy_menu.c***************/
void easy_menu();
GtkWidget *first_easy_button();
GtkWidget *second_easy_button();
GtkWidget *third_easy_button();
GtkWidget *fourth_easy_button();
GtkWidget *fifth_easy_button();
GtkWidget *sixth_easy_button();
/***************easy_menu.c***************/



/***************normal_menu.c***************/
void normal_menu();
GtkWidget *first_normal_button();
GtkWidget *second_normal_button();
GtkWidget *third_normal_button();
GtkWidget *fourth_normal_button();
GtkWidget *fifth_normal_button();
GtkWidget *sixth_normal_button();
GtkWidget *seventh_normal_button();
GtkWidget *eight_normal_button();
GtkWidget *ninth_normal_button();
/***************normal_menu.c***************/



/***************hard_menu.c***************/
void hard_menu();
GtkWidget *first_hard_button();
GtkWidget *second_hard_button();
GtkWidget *third_hard_button();
GtkWidget *fourth_hard_button();
GtkWidget *fifth_hard_button();
GtkWidget *sixth_hard_button();
GtkWidget *seventh_hard_button();
GtkWidget *eight_hard_button();
GtkWidget *ninth_hard_button();
GtkWidget *tenth_hard_button();
GtkWidget *eleventh_hard_button();
GtkWidget *twelfth_hard_button();
/***************hard_menu.c***************/



/***************universal.c***************/
GtkWidget *return_level_button();
void first_player_nickname(GtkWidget *widget, prysowanie data);
void second_player_nickname(GtkWidget *widget, prysowanie data);
/***************universal.c***************/



/***************universal-p.c***************/
void create_game_buttons(prysowanie data);
void set_skins(prysowanie data);
void set_position_and_n(prysowanie data);
void null_pictures(prysowanie data);
void set_pictures(prysowanie data);
void draw_map(prysowanie data);
GtkWidget *main_menu_button();
/***************universal-p.c***************/



/***************multiplayer_mode.c***************/
void interface_multi(GtkWidget *widget, prysowanie data);
void multi_invert(GtkWidget *widget, prysowanie data);
void actualize_scores(prysowanie data);
void whos_turn_now(prysowanie data);
void interface_map_multi(prysowanie data);
void game_over_screen_multi(prysowanie data);
void save_multi(GtkWidget *widget, prysowanie data);
void load_multi();
void set_pictures_load(prysowanie data);
void create_game_buttons_load(prysowanie data);
GtkWidget *save_multi_button();
GtkWidget *pause_multi_button(prysowanie data);
void pause_multi_menu(GtkWidget *widget, prysowanie data);
/***************multiplayer_mode.c***************/



/***************single_mode.c***************/
void interface_single(GtkWidget *widget, prysowanie data);
void single_invert(GtkWidget *widget, prysowanie data);
void interface_map_sixteen(prysowanie data);
void interface_map_thirtysix(prysowanie data);
void interface_map_sixtyfour(prysowanie data);
void how_many_left(prysowanie data);
void game_over_screen_single(prysowanie data);
gint lose_screen(prysowanie data);
void seconds_init(prysowanie data);
bool actualize_seconds(prysowanie data);
void save_single(prysowanie data);
void load_single();
GtkWidget *pause_single_button(prysowanie data);
gint pause_single_menu(GtkWidget *widget, prysowanie data);
/***************single_mode.c***************/
