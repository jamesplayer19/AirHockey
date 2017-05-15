#define BRANCO makecol(255,255,255)
#define DOWN_RIGHT 0
#define UP_RIGHT 1
#define DOWN_LEFT 2
#define UP_LEFT 3
#define cima 17
#define baixo 18
#define frente 20
#define atras 19
#define ciatx 4
#define ciatxy 5
#define ciaty 6
#define cifex 7
#define cifey 8
#define cifexy 9
#define bafex 10
#define bafexy 11
#define bafey 12
#define batx 13
#define batxy 14
#define baty 15
#define parado 16
#define N 150
char jog1[N];
char jog2[N];

int i = 0;
int nMapa = 0;
int sair_jogo = FALSE;
int jvn;
int jvn2;
double bola_x;
double bola_y;
int direcao;

volatile int ticks = 0;
const int temp = 100;

int espera;
double yrb;
double ybr;

double yrb;
double ybr;

double aux_y=0;
double aux_x=0;

double col_l;
double col_r;

double ca_l;
double ca_r;

double jogaL_y;
double jogaL_x;
double jogaR_y;
double jogaR_x;


long double aux_y1;
long double aux_x1;

double x;
double y;

double cb_x;
double cb_y;

double cl_x;
double cl_y;

double cr_x;
double cr_y;

int pontosL;
int pontosD;

BITMAP *bola;
BITMAP *barraL;
BITMAP *barraR;
BITMAP *buffer;
BITMAP *fundo;
FONT *alien36;
SAMPLE *colis;
SAMPLE *vitoria;
MIDI *music;
SAMPLE *gol;