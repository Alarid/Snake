#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED


/**
 * Evènements clavier de la caméra
 */
void camera_key(unsigned char k)
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
        case 'p':
            pause=!pause;
            break;
        default:
            break;
	}
}


/**
 * Evènements clavier
 */
static void key(unsigned char k, int x, int y)
{
	switch (k)
	{
		case 27:
			exit(0);
			break;
	}

    camera_key(k);
	glutPostRedisplay();
}


/**
 * Evènements clavier du jeu
 */
static void game_key(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_DOWN:
        	if (direction != UP)
            	direction = DOWN;
            break;

        case GLUT_KEY_UP:
        	if (direction != DOWN)
            	direction = UP;
            break;

        case GLUT_KEY_LEFT:
        	if (direction != RIGHT)
            	direction = LEFT;
            break;

        case GLUT_KEY_RIGHT:
        	if (direction != LEFT)
            	direction = RIGHT;
            break;

        default:
            break;
    }
}
#endif // EVENT_H_INCLUDED
