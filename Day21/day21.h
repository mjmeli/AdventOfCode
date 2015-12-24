#ifndef day21_h
#define day21_h

#define MAX(a,b)    (((a) > (b)) ? (a) : (b))

// Distinguish between the types of items in the store
typedef enum ItemTypes
{
    WEAPON,
    ARMOR,
    RING
} type_t;

// Represents an item in the store
typedef struct item_t {
    type_t type; // weapon, armor, or ring
    int cost;
    int damage;  // for weapons and rings
    int armor;   // for armor and rings
} item_t;

// Represents a player
typedef struct player_t {
    int health;
    int damage;
    int armor;
} player_t;

#endif
