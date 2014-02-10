#include <stdlib.h>
#include <GL/glut.h>

#define WIDTH 800
#define HEIGHT 600
#define PLATEAU_WIDTH 20
#define START_HEAD_X 10
#define START_HEAD_Y 10

float ex=10;
float ey=23;
float ez=28;

typedef enum {EMPTY, SNAKE_HEAD, SNAKE_BODY, FRUIT} map_elem;
map_elem map[PLATEAU_WIDTH][PLATEAU_WIDTH];

/**
 * Dessine le plateau
 */
void draw_plateau()
{
	int i, j;
	glColor3f(0.5, 0.5, 1);
    for (i=0; i<PLATEAU_WIDTH; i++) {
    	glPushMatrix();
    	glTranslatef(0, 0, i);
    	for(j=0; j<PLATEAU_WIDTH; j++) {
    		glTranslatef(1, 0, 0);
    		glutSolidCube(1);

    		glPushMatrix();
    		glTranslatef(0, 1, 0);
    		glColor3f(1, 0.5, 0.5);
    		if (map[i][j] == SNAKE_BODY)
    			glutSolidCube(1);
    		glColor3f(0, 1, 0);
    		if (map[i][j] == SNAKE_HEAD)
    			glutSolidCube(1);
    		glPopMatrix();
    		glColor3f(0.5, 0.5, 1);
    	}
    	glPopMatrix();
    }
}


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

    // Plateau
    draw_plateau();

    // Force le rendu maintenant
    glutSwapBuffers();
}


/**
 * Reshape de la fenêtre
 */
void reshape (int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ();
	gluPerspective(50, w/h, 1, 50);
	glMatrixMode (GL_MODELVIEW);
}


/**
 * Initialisation de l'etat OpenGl
 */
void init (void)
{
    // Choisir la couleur d'effacement
    glClearColor (0.5, 0.8, 1, 0.0);
    glEnable (GL_DEPTH_TEST);

    // Initialisation du tableau de la map 
    int x, y;
    for (y=0; y<PLATEAU_WIDTH; y++) 
    {
    	for (x=0; x<PLATEAU_WIDTH; x++) 
    	{
    		if (x == START_HEAD_X && y == START_HEAD_Y)
    		{
    			map[y][x] = SNAKE_HEAD;
    			map[y][x-1] = SNAKE_BODY;
    			// map[y][x-2] = SNAKE_BODY;
    		}
    		else
    			map[y][x] = EMPTY;
    	}
    }
}


/**
 * Evènements clavier
 */
static void key(unsigned char k, int x, int y)
{
	switch (k)
	{
		case 'x':
			ex=ex+0.05;
			break;
		case 'X':
			ex=ex-0.05;
			break;
		case 'y':
			ey=ey+0.05;
			break;
		case 'Y':
			ey=ey-0.05;
			break;
		case 'z':
			ez=ez+0.05;
			break;
		case 'Z':
			ez=ez-0.05;
			break;
		case 27:
			exit(0);
			break;
	}

	glutPostRedisplay();
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

	init ();

	/* Connexion callbacks puis boucle d'evenements */
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(key);
	glutMainLoop();

	return 0;
}