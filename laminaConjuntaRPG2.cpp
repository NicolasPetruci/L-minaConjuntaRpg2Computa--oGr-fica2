

#include <allegro5/allegro5.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

/*
    ALUNOS:
        Nicolas Petruci Penga (2211600184)
        Lucas Roberto (2211600445)
        Felipe Delgado (2211600317)
*/

#define GRIDMAP 32
#define ALTMAP 70 //x
#define LAGMAP 25 //Y
#define SCREENWIDTH GRIDMAP *ALTMAP/2
#define SCREENHEIGHT GRIDMAP *LAGMAP



int mapa[LAGMAP][ALTMAP] = {
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,},
{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 2, 2, 2, 2, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,},
{0, 1, 1, 1, 1, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 2, 2, 2, 13, 11, 2, 2, 2, 2, 2, 13, 11, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,},
{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 7, 8, 3, 2, 2, 2, 2, 9, 11, 2, 2, 2, 2, 2, 2, 2, 2, 9, 2, 2, 2, 2, 2, 2, 9, 2, 2, 2, 2, 13, 11, 2, 2, 2, 2, 0,},
{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 2, 2, 2, 2, 2, 13, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 9, 2, 5, 2, 2, 0,},
{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 7, 6, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 5, 0,},
{0, 1, 1, 1, 1, 1, 1, 6, 1, 1, 1, 4, 4, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 2, 2, 2, 2, 2, 2, 7, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,},
{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 7, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 2, 2, 2, 2, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 5, 0,},
{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 2, 2, 2, 2, 2, 2, 2, 5, 2, 2, 2, 2, 2, 9, 11, 2, 2, 2, 2, 2, 2, 5, 0,},
{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 13, 2, 2, 2, 2, 2, 2, 2, 0,},
{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 1, 1, 1, 3, 8, 7, 3, 2, 2, 2, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 9, 11, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,},
{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 7, 8, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 13, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,},
{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 13, 11, 2, 2, 2, 5, 0,},
{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 1, 1, 1, 3, 3, 3, 3, 2, 2, 2, 5, 2, 2, 2, 2, 2, 9, 11, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 13, 2, 2, 2, 2, 0,},
{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 5, 2, 2, 2, 13, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,},
{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 9, 11, 2, 2, 2, 2, 2, 2, 2, 2, 2, 8, 2, 2, 2, 0,},
{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 13, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,},
{0, 1, 1, 1, 1, 1, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 1, 1, 1, 1, 1, 1, 1, 6, 6, 1, 1, 1, 1, 3, 3, 3, 3, 2, 2, 2, 2, 2, 11, 9, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,},
{0, 1, 1, 1, 1, 4, 4, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 6, 1, 1, 1, 1, 3, 3, 3, 3, 2, 2, 2, 2, 2, 13, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 9, 11, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,},
{0, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 6, 1, 1, 1, 1, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 13, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,},
{0, 1, 1, 1, 1, 8, 1, 1, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 6, 6, 1, 1, 1, 1, 3, 8, 7, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,},
{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 5, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 5, 0,},
{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 8, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0,},
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}
};
ALLEGRO_BITMAP *gridMapGeral[15] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};

enum controle
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};
enum controle2
{
    W,
    S,
    A,
    D
};

void FormulaDoGrid()
{
    for (int i = 0; i < LAGMAP; i++)
    {
        for (int j = 0; j < ALTMAP; j++)
        {
            al_draw_bitmap(gridMapGeral[mapa[i][j]], j * GRIDMAP, i * GRIDMAP, 0);
        }
    }
}


bool checagemDoPixel(int x, int y, int pixelBlock, int alternar) {
    if (mapa[y][x] == pixelBlock) {
        mapa[y][x] = alternar;
        return true;
    }
    return false;
}

bool formulaDaColisao(int x, int y, int pixelBlock, int alternar) {
    int player1X = x / GRIDMAP;
    int player1Y = y / GRIDMAP;
    int player2X = (x + 25) / GRIDMAP;
    int player2Y = (y + 25) / GRIDMAP;

    bool golpe = false;

    golpe = checagemDoPixel(player1X, player1Y, pixelBlock, alternar) ||
            checagemDoPixel(player2X, player2Y, pixelBlock, alternar) ||
            checagemDoPixel(player1X, player2Y, pixelBlock, alternar) ||
            checagemDoPixel(player2X, player1Y, pixelBlock, alternar);

    return golpe;
}




bool colisao(int x, int y) {
    int player1X = x / GRIDMAP;
    int player1Y = y / GRIDMAP;
    int player2X = (x + 32) / GRIDMAP;
    int player2Y = (y + 32) / GRIDMAP;

    int tiles[4] = {
        mapa[player1Y][player1X],
        mapa[player2Y][player2X],
        mapa[player1Y][player2X],
        mapa[player2Y][player1X]
    };

    for (int i = 0; i < 4; i++) {
        if (tiles[i] == 4 || tiles[i] == 5 || tiles[i] == 0) {
            return true;
        }
    }

    return false;
}

int main()
{

    ALLEGRO_DISPLAY *telaDoGame;

    //algumas definições bases
    const float FPS = 120.0;
    bool loading = false;
    bool atualizar = true;

    //posicionamento dos herois
    int posX = SCREENWIDTH/4;
    int posY = SCREENHEIGHT/4;
    int posX2 = SCREENWIDTH/2 + 25;
    int posY2 = SCREENHEIGHT/2 + 25;


    //código pra definir a dimensão da tela, não confunda Delga
    float dimensaoX=0;
    float dimensaoY=0;

    bool controle[4] = {false, false, false, false};
    bool controle2[4] = {false, false, false, false};

    al_init();
    telaDoGame = al_create_display(SCREENWIDTH, SCREENHEIGHT);

    al_init_primitives_addon();
    al_init_image_addon();
    al_install_keyboard();

    ALLEGRO_TIMER *temporizador = al_create_timer(2.0 / FPS);

    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    al_register_event_source(event_queue, al_get_timer_event_source(temporizador));
    al_register_event_source(event_queue, al_get_display_event_source(telaDoGame));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    gridMapGeral[0] = al_load_bitmap("areiaDoHorizonte.png");
    gridMapGeral[1] = al_load_bitmap("areiaDoDeserto.png");
    gridMapGeral[2] = al_load_bitmap("areiaCorrompida.png");
    gridMapGeral[3] = al_load_bitmap("agua.png");
    gridMapGeral[4] = al_load_bitmap("arvoreDoDeserto.png");
    gridMapGeral[5] = al_load_bitmap("arvoreDoDesertoCorrompida.png");
    gridMapGeral[6] = al_load_bitmap("cactos.png");
    gridMapGeral[7] = al_load_bitmap("frascosDeVida.png");
    gridMapGeral[8] = al_load_bitmap("frascoDeMana.png");
    gridMapGeral[9] = al_load_bitmap("lugarPraJogarMagia.png");
    gridMapGeral[10] = al_load_bitmap("magiaDeFogo.png");
    gridMapGeral[11] = al_load_bitmap("demonioCorrompido.png");
    gridMapGeral[12] = al_load_bitmap("sangueDeMorte.png");
    gridMapGeral[13] = al_load_bitmap("ataqueComEspada.png");
    gridMapGeral[14] = al_load_bitmap("ataqueEfetuado.png");

    ALLEGRO_BITMAP *player = al_load_bitmap("lamina.png");
    ALLEGRO_BITMAP *player2 = al_load_bitmap("conjunta.png");

    al_start_timer(temporizador);

    ALLEGRO_TRANSFORM transf;


    //Movimentação dos herois com o lamina batendo no chão e a conjunta no foguinho nicolas.
    while (!loading)
{
    ALLEGRO_EVENT events;
    al_wait_for_event(event_queue, &events);
    ALLEGRO_EVENT_TYPE acoes = events.type;

    switch (acoes)
    {
    case ALLEGRO_EVENT_TIMER:
        atualizar = true;
        break;

    case ALLEGRO_EVENT_DISPLAY_CLOSE:
        loading = true;
        break;

    case ALLEGRO_EVENT_KEY_DOWN:
    {
        int keyDoTeclado = events.keyboard.keycode;

        switch (keyDoTeclado)
        {
        case ALLEGRO_KEY_UP:
            controle[UP] = true;
            break;

        case ALLEGRO_KEY_DOWN:
            controle[DOWN] = true;
            break;

        case ALLEGRO_KEY_LEFT:
            controle[LEFT] = true;
            break;

        case ALLEGRO_KEY_RIGHT:
            controle[RIGHT] = true;
            break;
        }
        break;
    }

    case ALLEGRO_EVENT_KEY_UP:
    {
        int keyDoTeclado = events.keyboard.keycode;

        switch (keyDoTeclado)
        {
        case ALLEGRO_KEY_UP:
            controle[UP] = false;
            break;

        case ALLEGRO_KEY_DOWN:
            controle[DOWN] = false;
            break;

        case ALLEGRO_KEY_LEFT:
            controle[LEFT] = false;
            break;

        case ALLEGRO_KEY_RIGHT:
            controle[RIGHT] = false;
            break;

        case ALLEGRO_KEY_ESCAPE:
            loading = true;
            break;
        }
        break;
    }
    }

    // Movimentação do lamina
    if (!colisao(posX, posY - controle[UP] * 2))
        posY -= controle[UP] * 2;
    if (!colisao(posX, posY + controle[DOWN] * 2))
        posY += controle[DOWN] * 2;
    if (!colisao(posX - controle[LEFT] * 2, posY))
        posX -= controle[LEFT] * 2;
    if (!colisao(posX + controle[RIGHT] * 2, posY))
        posX += controle[RIGHT] * 2;

    // Colisão com lamina
    formulaDaColisao(posX, posY, 7, 1);
    formulaDaColisao(posX, posY, 8, 1);
    formulaDaColisao(posX, posY, 11, 12);
    formulaDaColisao(posX, posY, 13, 14); //ataque físico

    // Movimentação da conjunta
    if (!colisao(posX2, posY2 - controle2[W] * 2))
        posY2 -= controle2[W] * 2;
    if (!colisao(posX2, posY2 + controle2[S] * 2))
        posY2 += controle2[S] * 2;
    if (!colisao(posX2 - controle2[A] * 2, posY2))
        posX2 -= controle2[A] * 2;
    if (!colisao(posX2 + controle2[D] * 2, posY2))
        posX2 += controle2[D] * 2;

    // Colisão com conjunta
    formulaDaColisao(posX2, posY2, 7, 1);
    formulaDaColisao(posX2, posY2, 8, 1);
    formulaDaColisao(posX2, posY2, 9, 10); //ataque de fogo
    formulaDaColisao(posX2, posY2, 11, 12);

    if (posX > SCREENWIDTH - 120 - dimensaoX)
    {
        dimensaoX -= 60;
    }

    if (posX < 120 - dimensaoX)
    {
        dimensaoX += 60;
    }

    if (posX2 > SCREENWIDTH - 120 - dimensaoX)
    {
        dimensaoX -= 60;
    }

    if (posX2 < 120 - dimensaoX)
    {
        dimensaoX += 60;
    }

    if (events.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        switch (events.keyboard.keycode)
        {
        case ALLEGRO_KEY_W:
            controle2[W] = true;
            break;

        case ALLEGRO_KEY_S:
            controle2[S] = true;
            break;

        case ALLEGRO_KEY_A:
            controle2[A] = true;
            break;

        case ALLEGRO_KEY_D:
            controle2[D] = true;
            break;
        }
    }
    else if (events.type == ALLEGRO_EVENT_KEY_UP)
    {
        switch (events.keyboard.keycode)
        {
        case ALLEGRO_KEY_W:
            controle2[W] = false;
            break;

        case ALLEGRO_KEY_S:
            controle2[S] = false;
            break;

        case ALLEGRO_KEY_A:
            controle2[A] = false;
            break;

        case ALLEGRO_KEY_D:
            controle2[D] = false;
            break;

        case ALLEGRO_KEY_ESCAPE:
            loading = true;
            break;
        }
    }

    al_identity_transform(&transf);
    al_translate_transform(&transf, dimensaoX, dimensaoY);
    al_use_transform(&transf);

    if (atualizar)
    {
        FormulaDoGrid();
        al_draw_bitmap(player, posX, posY, 0);
        al_draw_bitmap(player2, posX2, posY2, 0);
        al_flip_display();
        atualizar = false;
    }
}

al_destroy_display(telaDoGame);
al_destroy_timer(temporizador);
al_destroy_event_queue(event_queue);

return 0;

}
