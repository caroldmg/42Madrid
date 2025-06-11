#!/bin/bash

# Archivo Makefile donde se hará la actualización
MAKEFILE="Makefile"

# Buscar todos los archivos .c en src y subcarpetas, y unirlos con espacios
SRC_FILES=$(find ./src/ -type f -name "*.c" | tr '\n' ' ')

# Escapar caracteres especiales para evitar problemas en sed
ESCAPED_SRC=$(echo "$SRC_FILES" | sed 's/\//\\\//g')

# Reemplazar la línea que comienza con "SRC = " en el Makefile
sed -i "s/^SRC = .*/SRC = $ESCAPED_SRC/" "$MAKEFILE"

echo "Makefile actualizado con los archivos fuente:"
echo "$SRC_FILES"