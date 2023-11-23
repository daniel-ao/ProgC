#include <stdio.h>

enum NumericType {
    entier,
    decimal
};

typedef enum NumericType typage;

union Valeur {
    int ent;
    float dec;
};

struct Nombre {
    typage premier;
    union Valeur deuxieme;
};

struct Nombre nombre_entier(int i) {
    struct Nombre result;
    result.premier = entier;
    result.deuxieme.ent = i;
    return result;
}

struct Nombre nombre_decimal(float f) {
    struct Nombre result;
    result.premier = decimal;
    result.deuxieme.dec = f;
    return result;
}

int est_entier(struct Nombre n) {
    switch (n.premier) {
        case entier:
            return 1;
        case decimal:
            return 0;
    }
}

int est_decimal(struct Nombre n) {
    switch (n.premier) {
        case entier:
            return 0;
        case decimal:
            return 1;
    }
}

void afficher_nombre(struct Nombre n) {
    switch (n.premier) {
        case entier:
            printf("%d", n.deuxieme.ent);
            break;
        case decimal:
            printf("%.2f", n.deuxieme.dec);
            break;
    }
}


int main() {
    struct Nombre num1 = nombre_entier(42);
    struct Nombre num2 = nombre_decimal(3.14);

    printf("num1 is an %s: ", est_entier(num1) ? "entier" : "decimal");
    afficher_nombre(num1);
    printf("\n");

    printf("num2 is a %s: ", est_decimal(num2) ? "decimal" : "entier");
    afficher_nombre(num2);
    printf("\n");

    return 0;
}
