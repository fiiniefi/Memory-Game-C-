#include <gtk/gtk.h>
#include "interface.h"


int main(int argc, char *argv[])
{
gtk_init(&argc, &argv);
zdefiniuj_okno();
gtk_css();
glowne_menu();
gtk_main();
}
