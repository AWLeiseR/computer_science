/**
 * Teste com Allegro 5
 *
 * by CrociDB
 * http://crocidb.wordpress.com/
 */

#include <allegro5/allegro5.h>
#include <allegro5/a5_primitives.h>
#include <stdio.h>

int main()
{
    // Inicia o Allegro
    al_init();
    
    // Instalando o Teclado
    al_install_keyboard();

    // Cria um "BITMAP" de exibição
    ALLEGRO_DISPLAY *screen;    
    screen = al_create_display(640, 480);
    
    // Agora já vem coisa completamente nova no Allegro... EVENTOS! =D
    // Isso daqui é só para o teclado funcionar.
    ALLEGRO_EVENT_QUEUE *queue;
    queue = al_create_event_queue();
    al_register_event_source(queue, (ALLEGRO_EVENT_SOURCE*)al_get_keyboard());    
    ALLEGRO_EVENT evento;
    
    // Vamos desenhar algo na tela
    al_draw_filled_rectangle(10, 10, 100, 100, al_map_rgb(255,0,128));
    
    int i;
    for (i = 0; i < 10; i++)
        al_draw_circle(al_get_display_width() - (100 + i*2), al_get_display_height() - (100 + i*2), 100, al_map_rgb(255,0,0), 0);
    
    al_draw_filled_circle(al_get_display_width()/2, al_get_display_height()/2, 150, al_map_rgb(0,150,0));
    al_draw_filled_circle(al_get_display_width()/2, al_get_display_height()/2 - 30, 105, al_map_rgb(255,255,255));
    
    al_flip_display();    
    
    // Variável para o looping
    bool loop = true;
    
    // Looping para pegar os eventos de teclado
    while (loop)
    {
        al_wait_for_event(queue, &evento);
        if (evento.type == ALLEGRO_EVENT_KEY_DOWN && evento.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
        {
            loop = false;
        }
    }

    return 0;
}END_OF_MAIN();