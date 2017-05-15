void ticker()
{
  ticks++;
}

double colidir(double clx,double cly,double crx,double cry)
{
	if(clx>crx)
	{
		clx=clx-crx;
	}	
	else{
		clx=crx-clx;
	}
	if(cly>cry)
	{
		cly=cly-cry;
	}
	else
	{
		cly=cry-cly;
	}
	clx=clx*clx;
	cly=cly*cly;
	return cly+clx;	
}
void resetJogo()
{
  bola_x = 540;
    bola_y = 330;

    jogaL_y = 300;
    jogaL_x = 165;

    jogaR_y = 300;
    jogaR_x = 850;

    pontosD = 0;
    pontosL = 0;
    direcao = parado;
    aux_y=0;
    aux_x=0;
    cl_x=jogaL_x+50;
    cl_y=jogaL_y+50;
    cr_x=jogaR_x+50;
    cr_y=jogaR_y+50;
    cb_y=bola_y+20;
    cb_x=bola_x+20;

}
void moverBola()
{
    bola_x+=aux_x;
    bola_y+=aux_y;

	cb_y=bola_y+20;
	cb_x=bola_x+20;

    
    if(bola_y <= 22 || bola_y >= 638)
    {
    	aux_y=aux_y*-1;
      play_sample(colis, 255, 128, 1000, FALSE);
    }
    else if(bola_x <= 20 || bola_x>1060)
    {
    	aux_x=aux_x*-1;
      play_sample(colis, 255, 128, 1000, FALSE);
    }
    else if(bola_y > 135 && bola_y < 150 && bola_x < 70)
    {
    	aux_y=aux_y*-1;	
      play_sample(colis, 255, 128, 1000, FALSE);
    }
    else if(bola_x < 75 && bola_y > 140 && bola_y < 200)
    {
    	aux_x=aux_x*-1;
      play_sample(colis, 255, 128, 1000, FALSE);
    }
    else if(bola_x < 60 && bola_y <= 458 && bola_y >= 200 && bola_x > 40)
    {
    	bola_y = 330;
    	bola_x = 320;
    	jogaL_y = 300;
    	jogaL_x = 165;
    	jogaR_y = 300;
    	jogaR_x = 850;
    	aux_y=0;
    	aux_x=0;
    	cl_x=jogaL_x+50;
      cl_y=jogaL_y+50;
      cr_x=jogaR_x+50;
      cr_y=jogaR_y+50;
	    cb_y=bola_y+20;
	    cb_x=bola_x+20;
      pontosD++;
      play_sample(gol,255,128,1000,FALSE);
      ticks = 0;
      ticker();
      while(ticks < 10){}
    }
    else if(bola_y < 522 && bola_y> 510 && bola_x < 70)
    {
    	aux_y=aux_y*-1;	
      play_sample(colis, 255, 128, 1000, FALSE);
    }
    else if(bola_x < 80 && bola_y > 458 && bola_y < 500)
    {
    	aux_x=aux_x*-1;
      play_sample(colis, 255, 128, 1000, FALSE);
    }
    
    else if(bola_x > 1020 && bola_y <= 458 && bola_y >= 200 && bola_x < 1040)
    {
    	bola_y = 330;
    	bola_x = 760;
    	jogaL_y = 300;
    	jogaL_x = 165;
    	jogaR_y = 300;
    	jogaR_x = 850;
    	aux_y=0;
    	aux_x=0;
    	cl_x=jogaL_x+50;
      cl_y=jogaL_y+50;
      cr_x=jogaR_x+50;
      cr_y=jogaR_y+50;
	    cb_y=bola_y+20;
	    cb_x=bola_x+20;
      pontosL++;
      play_sample(gol,255,128,1000,FALSE);
      ticks = 0;
      ticker();
      while(ticks < 10){}
    }
    else if(bola_y > 135 && bola_y < 150 && bola_x > 1010)
    {
   			aux_y=aux_y*-1;
        play_sample(colis, 255, 128, 1000, FALSE);
    }
    else if(bola_x > 1000 && bola_y > 140 && bola_y < 200)
    {
    	aux_x=aux_x*-1;
      play_sample(colis, 255, 128, 1000, FALSE);
    	 }
    else if(bola_y < 522 && bola_y> 510 && bola_x > 1005)
    {
    	aux_y=aux_y*-1;
      play_sample(colis, 255, 128, 1000, FALSE);
    }
    else if(bola_x > 1010 && bola_y > 458 && bola_y < 500)
    {
    	aux_x=aux_x*-1;
      play_sample(colis, 255, 128, 1000, FALSE);
    }
    if(bola_y<22)
	{
		bola_y=22;
    play_sample(colis, 255, 128, 1000, FALSE);
	}
	if(bola_y>638)
	{
		bola_y=638;
    play_sample(colis, 255, 128, 1000, FALSE);
	}
	if(bola_x<20)
	{
		bola_x=20;
    play_sample(colis, 255, 128, 1000, FALSE);
	}
	if(bola_x>1060)
	{
		bola_x=1060;
    play_sample(colis, 255, 128, 1000, FALSE);
	}
    col_l=colidir(cl_x,cl_y,cb_x,cb_y);
    col_r=colidir(cr_x,cr_y,cb_x,cb_y);

   	if(col_l>0 && col_l<5100)
   	{
   		play_sample(colis, 255, 128, 1000, FALSE);
   		
   		x=cb_x-cl_x;
   		y=cb_y-cl_y;
   		   	aux_x+=x/35;
   			aux_y+=y/35;

   		

   		
   		if(aux_x>4)
   		{
   			aux_x=4;
   		}
   		if(aux_y>4)
   		{
   			aux_y=4;
   		}
   			if(aux_x<-4)
   		{
   			aux_x=-4;
   		}
   		if(aux_y<-4)
   		{
   			aux_y=-4;
   		}

   		

   	}
   	if(col_r>0 && col_r<5100)
   	{
   		x=cb_x-cr_x;
   		y=cb_y-cr_y;

   		aux_x+=x/35;
   			aux_y+=y/35;
      play_sample(colis, 255, 128, 1000, FALSE);
   		if(aux_x>4)
   		{
   			aux_x=4;
   		}
   		if(aux_y>4)
   		{
   			aux_y=4;
   		}
   		if(aux_x<-4)
   		{
   			aux_x=-4;
   		}
   		if(aux_y<-4)
   		{
   			aux_y=-4;
   		}
   		

   	}
   
}