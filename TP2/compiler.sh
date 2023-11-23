#!/bin/bash

compile() {
    echo "Compilation de l'exercice $1"
    gcc -Wall -ansi -pedantic exercice$1.c -o exercice$1
}

compile $1
