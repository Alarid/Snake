#ifndef DRAW_H_INCLUDED
#define DRAW_H_INCLUDED

void draw_cube(float x, float y, float z, int id_texture, int repeat)
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texName[id_texture]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

   //glColor3f (1.0, 1.0, 1.0);
   glBegin(GL_POLYGON);
      glTexCoord2f(0,               0);                 glVertex3f (0, 0, 0);
      glTexCoord2f(repeat,  0);                 glVertex3f (x, 0, 0);
      glTexCoord2f(repeat,  repeat);    glVertex3f (x, y, 0);
      glTexCoord2f(0,               repeat);    glVertex3f (0, y, 0);
   glEnd();

   glBegin(GL_POLYGON);
      glTexCoord2f(repeat,  0);                 glVertex3f (0, 0, 0);
      glTexCoord2f(repeat,  repeat);    glVertex3f (0, 0, z);
      glTexCoord2f(0,               repeat);    glVertex3f (x, 0, z);
      glTexCoord2f(0,               0);                 glVertex3f (x, 0, 0);
   glEnd();

   glBegin(GL_POLYGON);
      glTexCoord2f(repeat,  repeat);    glVertex3f (0, y, z);
      glTexCoord2f(0,               repeat);    glVertex3f (0, y, 0);
      glTexCoord2f(0,               0);                 glVertex3f (0, 0, 0);
      glTexCoord2f(repeat,  0);                 glVertex3f (0, 0, z);
   glEnd();

   glBegin(GL_POLYGON);
      glTexCoord2f(0,               repeat);    glVertex3f (0, y, z);
      glTexCoord2f(0,               0);                 glVertex3f (0, y, 0);
      glTexCoord2f(repeat,  0);                 glVertex3f (x, y, 0);
      glTexCoord2f(repeat,  repeat);    glVertex3f (x, y, z);
   glEnd();

   glBegin(GL_POLYGON);
      glTexCoord2f(repeat,  repeat);    glVertex3f (x, y, z);
      glTexCoord2f(0,               repeat);    glVertex3f (x, y, 0);
      glTexCoord2f(0,               0);                 glVertex3f (x, 0, 0);
      glTexCoord2f(repeat,  0);                 glVertex3f (x, 0, z);
   glEnd();

   glBegin(GL_POLYGON);
      glTexCoord2f(0,               repeat);    glVertex3f (0, y, z);
      glTexCoord2f(repeat,  repeat);    glVertex3f (x, y, z);
      glTexCoord2f(repeat,  0);                 glVertex3f (x, 0, z);
      glTexCoord2f(0,               0);                 glVertex3f (0, 0, z);
   glEnd();

   glDisable(GL_TEXTURE_2D);
}


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
        glColor3f(0.4, 0.2, 0.3);
        //glutSolidCube(1);
        draw_cube(1, 1, 1, 1, 1);
    }

    // Corps du snake
    if (map[i][j] == SNAKE_BODY)
    {
        glColor3f(1, 1, 1);
//        glutSolidCube(1);
        draw_cube(1, 1, 1, 1, 1);
    }

    glPopMatrix();
}


/**
 * Dessine un fruit
 */
void draw_fruit(int i, int j)
{
    // Préparation du dessin
    glPushMatrix();
    glTranslatef(0, 1, 0);
    glColor3f(1, 0, 0);

    // Dessin du fruit
    draw_cube(1, 1, 1, 2, 1);

    glPopMatrix();
}


/**
 * Affiche du texte
 */
void drawBitmapText(char *string,float x,float y,float z)
{
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
}


/**
 * Dessine le plateau
 */
void draw_plateau()
{
    int i, j;

    // Affiche le score
    glColor3f(1, 1, 1);
    char str[50];
    snprintf(str, sizeof(str), "Score : %d", snake_body_size);
    drawBitmapText(str, -2, 8, 0);

    // On parcourt les cases du tableau
    for (i=0; i<PLATEAU_WIDTH; i++) {
        glPushMatrix();
        glTranslatef(0, 0, i);
        for(j=0; j<PLATEAU_WIDTH; j++) {
            glTranslatef(1, 0, 0);
            glColor3f(0.5, 0.5, 1);
            //glutSolidCube(1);
            draw_cube(1, 1, 1, 0, 1);

            if (map[i][j] == SNAKE_HEAD || map[i][j] == SNAKE_BODY)
                draw_snake(i, j);
            else if (map[i][j] == FRUIT)
                draw_fruit(i, j);
        }
        glPopMatrix();
    }
}

#endif // DRAW_H_INCLUDED
