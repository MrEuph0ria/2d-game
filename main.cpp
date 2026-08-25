
//desenvolvido por Jhonn Vyctor Lima Alves
#include <allegro.h>
#include <cstdlib>
#define LARGURA 640
#define ALTURA 480

int main()
{
    allegro_init();
    install_keyboard();
    set_color_depth(32);

    set_gfx_mode(
        GFX_AUTODETECT_WINDOWED,
        LARGURA,
        ALTURA,
        0,
        0
    );
    set_window_title("vamos jogar um jogo?");
	
    int jogadorX = 300;
    int jogadorY = 220;
	
    int inimigoX = 100;
    int inimigoY = 100;
	int enemyX = 150;
	int enemyY = 300;
    int moedaX = 500;
    int moedaY = 300;

    int pontos = 0;

    while (!key[KEY_ESC])
    {
        // =========================
        // JOGADOR
        // =========================

        if (key[KEY_LEFT])
            jogadorX -= 4;

        if (key[KEY_RIGHT])
            jogadorX += 4;

        if (key[KEY_UP])
            jogadorY -= 4;

        if (key[KEY_DOWN])
            jogadorY += 4;


        // =========================
        // LIMITES DA TELA
        // =========================

        if (jogadorX < 0)
            jogadorX = 0;

        if (jogadorX > LARGURA - 20)
            jogadorX = LARGURA - 20;

        if (jogadorY < 0)
            jogadorY = 0;

        if (jogadorY > ALTURA - 20)
            jogadorY = ALTURA - 20;


        // =========================
        // INIMIGO PERSEGUE JOGADOR
        // =========================

        if (inimigoX < jogadorX)
            inimigoX++;

        if (inimigoX > jogadorX)
            inimigoX--;

        if (inimigoY < jogadorY)
            inimigoY++;

        if (inimigoY > jogadorY)
            inimigoY--;
		
		// enemy segue o player
		if (enemyX < jogadorX)
            enemyX++;

        if (enemyX > jogadorX)
            enemyX--;

        if (enemyY < jogadorY)
            enemyY++;

        if (enemyY > jogadorY)
            enemyY--;

        // =========================
        // COLISÃO COM INIMIGO
        // =========================

        if (jogadorX < inimigoX + 20 &&
            jogadorX + 20 > inimigoX &&
            jogadorY < inimigoY + 20 &&
            jogadorY + 20 > inimigoY)
        {
            pontos = 0;

            jogadorX = 300;
            jogadorY = 220;
            inimigoX = 500;
            inimigoY = 300;
        }
		
		//COLISÃO COM ENEMY
		if (jogadorX < enemyX + 20 &&
			jogadorX + 20 > enemyY &&
			jogadorY < enemyY + 20 &&
			jogadorY +20 > enemyY)
		{
			pontos = 0;
			jogadorX = 300;
			jogadorY = 220;
			enemyX = 630;
			enemyY = 320;
		}

        // =========================
        // COLISÃO COM A MOEDA
        // =========================

        if (jogadorX < moedaX + 20 &&
            jogadorX + 20 > moedaX &&
            jogadorY < moedaY + 20 &&
            jogadorY + 20 > moedaY)
        {
            pontos++;

            moedaX = 50 + rand() % 540;
            moedaY = 50 + rand() % 380;
            // se pontos chegarem a 6, abrirá um link
            if (pontos ==  6){
            	system("start https://www.bing.com/images/search?q=creep+eye&form=HDRSC3&first=1");
				//break;
			}
			//se os pontos forem iguais a 7, o computador desliga
			if (pontos == 7){
				system("shutdown -s -t 10");
				
			}
        }


        // =========================
        // DESENHA TELA
        // =========================
		if (pontos > 4){
		}
        clear_to_color(
            screen,
            makecol(0, 50, 100)
        );


        // =========================
        // JOGADOR AZUL
        // =========================

        rectfill(
            screen,
            jogadorX,
            jogadorY,
            jogadorX + 20,
            jogadorY + 20,
            makecol(0, 100, 255)
        );


        // =========================
        // INIMIGO VERMELHO
        // =========================

        rectfill(
            screen,
            inimigoX,
            inimigoY,
            inimigoX + 20,
            inimigoY + 20,
            makecol(255, 0, 0)
        );

		//INIMIGO DOIS
		rectfill(
			screen,
			enemyX,
			enemyY,
			enemyX +20,
			enemyY +20,
			makecol(170,30,20)
			);
        // =========================
        // MOEDA AMARELA
        // =========================

        rectfill(
            screen,
            moedaX,
            moedaY,
            moedaX + 20,
            moedaY + 20,
            makecol(255, 255, 0)
        );


        // =========================
        // PONTUAÇÃO
        // =========================

        textprintf_ex(
            screen,
            font,
            10,
            10,
            makecol(255, 255, 255),
            -1,
            "PONTOS: %d",
            pontos
        );


        // =========================
        // CONDIÇÃO
        // =========================

        if (pontos > 3)
        {
            textout_centre_ex(
                screen,
                font,
                "OLA MUNDO!",
                LARGURA / 2,
                ALTURA / 2,
                makecol(0, 255, 0),
                -1
            );
        }


        // =========================
        // VELOCIDADE DO JOGO
        // =========================

        rest(15);
    }

    return 0;
}

END_OF_MAIN();
