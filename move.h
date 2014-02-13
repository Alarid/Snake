#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED

/**
 * Déplacement du corps du snake
 */
void move_snake_body(pos_snake_part* body, int* prev_y, int* prev_x)
{
    map[body->y][body->x] = EMPTY;
    map[*prev_y][*prev_x] = SNAKE_BODY;
    body->x = prev_x;
    body->y = prev_y;
}

/**
 * Déplacement de la tête du snake
 */
void move_snake_head(pos_snake_part* head)
{
    int next_i = head->y, next_j = head->x;

    switch (direction)
    {
        case RIGHT:
            next_j++;
            break;

        case LEFT:
            next_j--;
            break;

        case DOWN:
            next_i++;
            break;

        case UP:
            next_i--;
            break;
    }

    // Si le snake est sorti du plateau, la partie est perdue
    if (next_i >= PLATEAU_WIDTH || next_i < 0 || next_j >= PLATEAU_WIDTH || next_j < 0)
    {
        exit(0);
        return;
    }

    // On met à jour la position du serpent
    map[next_i][next_j] = SNAKE_HEAD;
    head->x = next_j;
    head->y = next_i;
}


/**
 * Déplacement du snake
 */
void move_snake()
{
    int prev_x, prev_y;

    // On bouge la tête du snake
    pos_snake_part* temp = snake;
    prev_x = temp->x;
    prev_y = temp->y;
    move_snake_head(temp);
    temp = temp->next;

    while(temp->next != NULL)
    {
        move_snake_body(temp, &prev_x, &prev_y);
        temp = temp->next;
    }
}


/**
 * Ajoute un bout de snake
 */
void add_snake_part(int x, int y)
{
    /* On crée un nouvel élément */
    pos_snake_part* new_snake_part = malloc(sizeof(pos_snake_part));

    /* On assigne la valeur au nouvel élément */
    new_snake_part->x = x;
    new_snake_part->y = y;

    /* On ajoute en fin, donc aucun élément ne va suivre */
    new_snake_part->next = NULL;

    /* On met à jour l'ancien dernier élément */
    if(snake != NULL)
    {
        /* Sinon, on parcourt la liste à l'aide d'un pointeur temporaire et on
        indique que le dernier élément de la liste est relié au nouvel élément */
        pos_snake_part* temp = snake;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_snake_part;
    }
}

/**
 * Supprime un bout de snake
 */
void delete_snake_part()
{
    // Si la liste est vide on a rien à faire
    if (snake == NULL)
        return;

    // Si la liste contient un seul élément
    if (snake->next == NULL)
    {
        // On le libère
        free(snake);
        return;
    }

    // Si la liste contient au moins deux éléments
    pos_snake_part* tmp = snake;
    pos_snake_part* ptmp = snake;
    while (tmp->next != NULL)
    {
        // ptmp stocke l'adresse de tmp
        ptmp = tmp;
        // tmp se déplace
        tmp = tmp->next;
    }

    ptmp->next = NULL;
    free(tmp);
}

#endif // MOVE_H_INCLUDED
