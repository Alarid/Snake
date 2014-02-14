#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

/**
 * Dessine le snake
 */
void draw_snake(int i, int j)
{
    // Préparation du dessin
    glPushMatrix();
    glTranslatef(0, 1, 0);

    // Tête du snake
    if (map[i][j] == SNAKE_HEAD)
    {
        glColor3f(0, 1, 0);
        glutSolidCube(1);
    }

    // Corps du snake
    if (map[i][j] == SNAKE_BODY)
    {
        glColor3f(1, 0.5, 0.5);
        glutSolidCube(1);
    }

    glPopMatrix();
}


/**
 * Dessine le plateau
 */
void draw_plateau()
{
    int i, j;
    for (i=0; i<PLATEAU_WIDTH; i++) {
        glPushMatrix();
        glTranslatef(0, 0, i);
        for(j=0; j<PLATEAU_WIDTH; j++) {
            glTranslatef(1, 0, 0);
            glColor3f(0.5, 0.5, 1);
            glutSolidCube(1);

            draw_snake(i, j);
        }
        glPopMatrix();
    }
}

#endif // DRAW_H_INCLUDED
