//
// Created by austin stone on 2020/9/5.
//

#include <stdlib.h>
#include <stdio.h>

struct Per {
    char *name;
    int age;
};

struct Per **init(int len) {
    struct Per **per = malloc(sizeof(struct Per *) * len);
    for (int i = 0; i < len; ++i) {
        per[i] = malloc(sizeof(struct Per));
        per[i]->name = malloc(sizeof(char *));
        sprintf(per[i]->name, "name:%d", i + 1);
        per[i]->age = 18 + i;
    }
    return per;
}

void printPer(struct Per **p, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%s,age:%d\n", p[i]->name, p[i]->age);
    }
}

void freePer(struct Per **p) {
    if (p == NULL) return;
    int len = sizeof(p) / sizeof(struct Per);
    for (int i = 0; i < len; ++i) {
        if (p[i] == NULL) continue;
        if (p[i]->name != NULL) {
            free(p[i]->name);
            p[i]->name = NULL;
        }
        free(p[i]);
    }
    free(p);
    p = NULL;
}


int main() {
    int len = 5;
    struct Per **p = init(len);
    printPer(p, len);
    freePer(p);
}