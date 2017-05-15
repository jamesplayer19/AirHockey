void teclado()
{
    
    if(key[KEY_W])
    {      
        jogaL_y -= 2.5;
    }
    if(key[KEY_S])
        jogaL_y += 2.5;
    if(key[KEY_A])
        jogaL_x -= 2.5;
    if(key[KEY_D])
        jogaL_x += 2.5;


    if(key[KEY_UP]){
        jogaR_y -= 2.5;
    }
    if(key[KEY_DOWN]){
        jogaR_y += 2.5;
    }
    if(key[KEY_LEFT]){
        jogaR_x -= 2.5;
    }
    if(key[KEY_RIGHT]){
        jogaR_x += 2.5;
    }

    if(jogaL_x < 22)
        jogaL_x = 22;
    else if(jogaL_x > 453)
        jogaL_x = 453;


    if(jogaL_y > 75 && jogaL_y < 80 && jogaL_x < 40)
    {
    	jogaL_y = 75;
    }
    else if(jogaL_y < 522 && jogaL_y > 510 && jogaL_x < 40)
    	jogaL_y = 522;
    else if(jogaL_x < 68 && jogaL_y > 80 && jogaL_y < 490)
    {
    	jogaL_x = 68;
    }

    if(jogaR_y > 75 && jogaR_y < 80 && jogaR_x > 980)
    {
    	jogaR_y = 75;
    }
    else if(jogaR_y < 522 && jogaR_y > 510 && jogaR_x > 980)
    {
    	jogaR_y = 522;
    }

    else if(jogaR_x > 950 && jogaR_y > 80 && jogaR_y < 490)
    {
    	jogaR_x = 950;
    }
    cl_x=jogaL_x+50;
    cl_y=jogaL_y+50;
     cr_x=jogaR_x+50;
    cr_y=jogaR_y+50;
	if(jogaL_y < 25)
        jogaL_y = 25;
    else if(jogaL_y > 580)
        jogaL_y = 580;

    if(jogaR_y < 25)
        jogaR_y = 25;
    else if(jogaR_y > 580)
        jogaR_y = 580;

    if(jogaR_x > 1000)
        jogaR_x = 1000;
    else if(jogaR_x < 566)
        jogaR_x = 566;
}
void direcaoVertical()
{
    if((direcao%2) == 0)
        ++direcao;
    else --direcao;
}
void direcaoHorizontal()
{
	    direcao = (direcao + 2) % 4;
}