#include <allegro.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include "library/variaveis.h"
#include "library/bola.h"
#include "library/rebatedor.h"
#include "library/telas.h"
int main() {
    allegro_init();
    install_keyboard();
    install_timer();
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
    install_int_ex(ticker,BPS_TO_TIMER(temp));

    colis = load_sample("sound/colisao.wav");
    vitoria = load_sample("sound/vitoria.wav");
    music = load_midi("sound/game.mid");
    gol = load_sample("sound/gol.wav");

    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1120, 700, 0, 0);
    set_window_title("Air Hockey");
    srand(time(NULL));
    buffer = create_bitmap(SCREEN_W,SCREEN_H);
    inicio:
    resetJogo();
	alien36 = load_font("font/georgia26.pcx",NULL,NULL);

    menu();
    espera = 0;
    jvn = 0;
    jvn2 = 0;
    if(!nMapa)
    {
	bola = load_bitmap("img/bola.bmp",NULL);
    barraR = load_bitmap("img/barraR.bmp",NULL);
    barraL = load_bitmap("img/barraL.bmp",NULL);
    fundo = load_bitmap("img/mapa.bmp",NULL);
	  }
	  if(nMapa == 1)
	  {
		bola = load_bitmap("img/bola2.bmp",NULL);
		barraR = load_bitmap("img/ra2.bmp",NULL);
		barraL = load_bitmap("img/ra1.bmp",NULL);
		fundo = load_bitmap("img/mapafrio.bmp",NULL);
	  }
	  if(nMapa == 2)
	  {
	  bola = load_bitmap("img/bola.bmp",NULL);
    barraR = load_bitmap("img/barraR.bmp",NULL);
    barraL = load_bitmap("img/barraL.bmp",NULL);
    fundo = load_bitmap("img/mapaesp.bmp",NULL);
	  }
    remove_keyboard();
    install_keyboard();
    jog1[0] = '\0';
    jog2[0] = '\0';
    if(!sair_jogo)
      nome();
    inicio2:
    jvn2 = 0;
    jvn = 0;
    play_midi(music, TRUE);
    while(!sair_jogo)
    {
        if(key[KEY_ESC])
        {
        	pausa();
        }
        if(espera) goto inicio;
        moverBola();
        teclado();
        jogo();
        if(pontosL == 7 || pontosD == 7) 
          ganhou();
        if(jvn) goto inicio2;
        if(jvn2) goto inicio;
        clear(buffer);
    }
    destroy_bitmap(bola);
    destroy_bitmap(clear);
    destroy_bitmap(barraL);
    destroy_bitmap(barraR);
    destroy_font(alien36);
    destroy_sample(colis);
    destroy_sample(gol);
    return 0;
}
END_OF_MAIN()