#define LINE_LENGTH     (11)
#define INGREDIENT_NAME (1)
#define CAPACITY        (3)
#define DURABILITY      (5)
#define FLAVOR          (7)
#define TEXTURE         (9)
#define CALORIES        (0)

#define POS(x)          ((x) < 0 ? 0 : (x))     // sets to 0 if negative

typedef struct ingredient {
    int capacity;
    int durability;
    int flavor;
    int texture;
    int calories;
    struct ingredient *next;
} ingredient_t;

typedef struct cookie {
    int capacity;
    int durability;
    int flavor;
    int texture;
    int calories;
} cookie_t;

// Prepends a ingredient to the ingredients linked list
void addIngredient(ingredient_t **list, ingredient_t *new)
{
    if (*list == NULL) {
        *list = new;
    }
    else {
        new->next = *list;
        *list = new;
    }
}

// Get count of number of ingredients in the list
int getCount(ingredient_t *list)
{
    ingredient_t *p = list;
    int i = 0;
    while (p != NULL) {
        i++;
        p = p->next;
    }
    return i;
}

ingredient_t * getIngredient(ingredient_t *list, int index)
{
    ingredient_t *p = list;
    while (p != NULL && index-- != 0) p = p->next;
    return p;
}
