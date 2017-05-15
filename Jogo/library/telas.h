void jogo()
{
  clear_to_color(buffer,makecol(255,0,255));
  draw_sprite(buffer,fundo,0,0);
  draw_sprite(buffer,bola,bola_x,bola_y);
  draw_sprite(buffer,barraL,jogaL_x,jogaL_y);
  draw_sprite(buffer,barraR,jogaR_x,jogaR_y);
  textprintf_ex(buffer,alien36,525,30,BRANCO,-1,"%d",pontosL);
  textprintf_ex(buffer,alien36,580,30,BRANCO,-1,"%d",pontosD); 
  blit(buffer,screen,0,0,0,0,buffer->w,buffer->h);
}
void escolher()
{
	int sair = FALSE;
	BITMAP* escolher = load_bitmap("img/escolher.bmp",NULL);
	while(!sair)
	{
		if(key[KEY_S])
			sair = TRUE;
		if(key[KEY_A])
			nMapa = 0;
		if(key[KEY_B])
			nMapa = 1;
		if(key[KEY_C])
			nMapa = 2;
		blit(escolher,screen,0,0,0,0,escolher->w,escolher->h);
	}
}
void menu()
{
	int sair = FALSE;
	BITMAP* menu = load_bitmap("img/menu.bmp",NULL);
	while(!sair)
	{
		if(key[KEY_X]){
			sair = TRUE;
		}
		if(key[KEY_Q] || key[KEY_ESC])
		{
			sair = TRUE;
			sair_jogo = TRUE;
		}
		if(key[KEY_M])
			escolher();
		blit(menu,screen,0,0,0,0,menu->w,menu->h);

	}
}

void pausa()
{
	int sair = FALSE;
	BITMAP* pause = load_bitmap("img/pausa.bmp",NULL);
	while(!sair)
	{
		if(key[KEY_C])
			sair = TRUE;
		if(key[KEY_Q]){
			sair_jogo = TRUE;
			sair = TRUE;
		}
		if(key[KEY_B]){
			espera = 1;
			sair = TRUE;
		}

		blit(pause, screen,0,0,400,120,pause->w,pause->h);
	}
}

int recursao()
{
    jog2[0] = toupper(jog2[0]);
    textprintf_ex(screen,alien36,420,180,BRANCO,-1,"%s ganhou !",jog2);
    if(key[KEY_Q])
    {
      sair_jogo = TRUE;
      
      return TRUE;
    }
    else if(key[KEY_C])
    {
      resetJogo();
      
      jvn = 1;
      stop_sample(vitoria);
      return TRUE;
    }
    else if(key[KEY_B]){
      
      jvn2 = 1;
      stop_sample(vitoria);
      return TRUE;
    }
    else
    {
      return recursao();
    }

}
int recursao2()
{
      jog1[0] = toupper(jog1[0]);
    textprintf_ex(screen,alien36,410,180,BRANCO,-1,"%s ganhou !",jog1);
    if(key[KEY_Q])
    {
      sair_jogo = TRUE;
      
      return TRUE;
    }
    else if(key[KEY_C])
    {
      resetJogo();
      
      jvn = 1;
      stop_sample(vitoria);
      return TRUE;
    }
    else if(key[KEY_B]){
      
      jvn2 = 1;
      stop_sample(vitoria);
      return TRUE;
    }
    else
    {
      return recursao2();
    }
}

void ganhou()
{
  BITMAP* ganhou = load_bitmap("img/ganhou.bmp",NULL);
  play_sample(vitoria, 255, 128, 1000, FALSE);
  int sair = FALSE;
  blit(ganhou,screen,0,0,400,120,ganhou->w,ganhou->h);
  if(!sair && pontosD == 7){
    sair=recursao();
  }
  if(!sair && pontosL == 7){
    sair=recursao2();
  }
}
void nome()
{
  int sair = FALSE;
  BITMAP* nome = load_bitmap("img/nome.bmp",NULL);
  BITMAP* aux = create_bitmap(230,50);
  BITMAP* aux2 = create_bitmap(230,50);
  while(!sair)
  {

    i = 0;
    blit(nome,screen,0,0,0,0,nome->w,nome->h);
    draw_sprite(screen,barraL,195,340);
    draw_sprite(screen,barraR,760,340);
    do{
      if(keypressed())
      {
        int tecla = readkey();
        char ASCII = tecla & 0xff;
        char scan = tecla >> 8;

        if(ASCII >= 32 && ASCII <= 126)
        {
            if(i < N - 1)
            {
              jog1[i] = ASCII;
              i++;
              jog1[i] = '\0';
            }
        }

        else if(scan  == KEY_BACKSPACE)
        {
          if(i > 0) i--;
          jog1[i] = '\0';
        }

        clear(aux);
        textout(aux,alien36,jog1,0,0,BRANCO);
        blit(aux,screen,0,0,130,230,aux->w,aux->h);

      }
    }while(!key[KEY_ENTER]);
    while(key[KEY_ENTER])
    {
    }
    i = 0;
    do{
      if(keypressed())
      {
        int tecla = readkey();
        char ASCII = tecla & 0xff;
        char scan = tecla >> 8;

        if(ASCII >= 32 && ASCII <= 126)
        {
            if(i < N - 1)
            {
              jog2[i] = ASCII;
              i++;
              jog2[i] = '\0';
            }
        }

        else if(scan  == KEY_BACKSPACE)
        {
          if(i > 0) i--;
          jog2[i] = '\0';
        }
        clear(aux2);
        //textout(aux2,font,jog1,20,20,BRANCO);
        textout(aux2,alien36,jog2,0,0,BRANCO);
        blit(aux2,screen,0,0,700,230,aux2->w,aux2->h);

      }
    }while(!key[KEY_ENTER]);
    printf("%s\n",jog1);
    printf("%s\n",jog2);
    break;
  }
}
