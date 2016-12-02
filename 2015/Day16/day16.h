// Positions of various fields in the input
#define LINE_LENGTH     (8)
#define SUE_NUM         (1)
#define TRAIT_1_NAME    (2)
#define TRAIT_1_NUM     (3)
#define TRAIT_2_NAME    (4)
#define TRAIT_2_NUM     (5)
#define TRAIT_3_NAME    (6)
#define TRAIT_3_NUM     (7)

// Values that our Sue has for each trait
#define TRAIT_CHILDREN      (3)
#define TRAIT_CATS          (7)
#define TRAIT_SAMOYEDS      (2)
#define TRAIT_POMERANIANS   (3)
#define TRAIT_AKITAS        (0)
#define TRAIT_VIZSLAS       (0)
#define TRAIT_GOLDFISH      (5)
#define TRAIT_TREES         (3)
#define TRAIT_CARS          (2)
#define TRAIT_PERFUMES      (1)

// Operations that certain traits require
#define FEWER_THAN           (-1)
#define EQUAL               (0)
#define GREATER_THAN        (1)
#define OP_TREES            (GREATER_THAN);
#define OP_CATS             (GREATER_THAN)
#define OP_POMERANIANS      (FEWER_THAN)
#define OP_GOLDFISH         (FEWER_THAN)
