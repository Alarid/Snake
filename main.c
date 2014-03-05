#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <GL/glut.h>
#include <stdarg.h>

#include "const.h"
#include "vars.h"
#include "move.h"
#include "draw.h"
#include "bmp.h"
#include "opengl.h"
#include "event.h"

/**
 * Dessine la scène
 */
void display()
{
	// Caméra
	glLoadIdentity();
	gluLookAt(ex, ey, ez,   PLATEAU_WIDTH/2, -PLATEAU_WIDTH/2, 0,    0, 1, 0);
	//printf("{%f,%f,%f}\n", ex, ey, ez);

	// Vide l'ecran
    glClear (GL_COLOR_BUFFER_BIT);
    glClear (GL_DEPTH_BUFFER_BIT);

    // Déplacements
    if (!pause)
        move_snake();

    // Affichages
    draw_plateau();

    // Force le rendu maintenant
    glutSwapBuffers();
}


/**
 * Main
 */
int main(int argc, char** argv)
{
	/* Initialisation de la GLUT */
	glutInit(&argc, argv);

	/* Choix du mode d'affichage */
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	/* Creation de la fenetre puis choix de sa taille et de sa position */
	glutInitWindowSize (WIDTH, HEIGHT);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Snake 3D");
	glutTimerFunc(timer_speed, my_timer, 1);
	glutTimerFunc(40, fruit_timer, 1);

	init ();

	/* Connexion callbacks puis boucle d'evenements */
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(key);
	glutSpecialFunc(game_key);
	glutMainLoop();

	return 0;
}
