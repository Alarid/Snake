#ifndef OPENGL_H_INCLUDED
#define OPENGL_H_INCLUDED


/**
 * Reshape de la fen�tre
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
    			snake = add_snake_part(snake, x, y);
    			snake = add_snake_part(snake, x-1, y);
    			snake = add_snake_part(snake, x-2, y);
                snake = add_snake_part(snake, x-3, y);
    		}
    		else
    			map[y][x] = EMPTY;
    	}
    }

    // Initialisation de la direction
    direction = RIGHT;
}

/**
 * Timer g�n�ral
 */
void my_timer(int v)
{
   glutTimerFunc(timer_speed, my_timer, 1);

   glutPostRedisplay();
}

#endif // OPENGL_H_INCLUDED
