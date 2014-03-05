#ifndef OPENGL_H_INCLUDED
#define OPENGL_H_INCLUDED


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
 * Charge les textures
 */
void init_textures()
{
    Image* images[NB_TEXTURES];

    images[0] = loadTexture("textures/ground.bmp");
    if(images[0] == NULL)
    {
        printf("ground.bmp was not returned from loadTexture\n");
        exit(0);
    }

    images[1] = loadTexture("textures/skin.bmp");
    if(images[1] == NULL)
    {
        printf("skin.bmp was not returned from loadTexture\n");
        exit(0);
    }

    images[2] = loadTexture("textures/apple.bmp");
    if(images[2] == NULL)
    {
        printf("skin.bmp was not returned from loadTexture\n");
        exit(0);
    }

    glGenTextures(NB_TEXTURES, texName);

    int i;
    for (i=0; i<NB_TEXTURES; ++i)
    {
        glBindTexture(GL_TEXTURE_2D, texName[i]);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
                       GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                       GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, images[i]->sizeX,
                    images[i]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE,
                    images[i]->data);
    }


    //glEnable(GL_TEXTURE_2D);
}

/**
 * Initialisation de l'etat OpenGl
 */
void init (void)
{
    // Choisir la couleur d'effacement
    //glClearColor (0.5, 0.8, 1, 0.0);
    glClearColor(0,0,0,0);
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
    		}
    		else
    			map[y][x] = EMPTY;
    	}
    }

    // Initialisation de la direction
    direction = RIGHT;

    // Chargement des textures
    init_textures();
}

/**
 * Timer général
 */
void my_timer(int v)
{
   glutTimerFunc(timer_speed, my_timer, 1);

   glutPostRedisplay();
}


/**
 * Timer de génération de fruit
 */
void fruit_timer(int v)
{
    int x, y;

    glutTimerFunc(fruit_timer_speed, fruit_timer, 1);

    if (pause) return;

    // On génère un fruit aléatoirement sur la map
    srand(time(NULL));
    do
    {
        x = rand() % PLATEAU_WIDTH;
        y = rand() % PLATEAU_WIDTH;
    }
    while (map[y][x] != EMPTY);
    map[y][x] = FRUIT;
}

#endif // OPENGL_H_INCLUDED
