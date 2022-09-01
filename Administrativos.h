#ifndef ADMINISTRATIVOS_H
#define ADMINISTRATIVOS_H

#include <stdbool.h>

int retrieveProducts();

void finish_with_errorINSERT(MYSQL* con);

char* concat(char* str1, char* str2);

char readFile(char* filename);

const char* getInfo(char* line, int num);


int registrarNomina();


int registrarVenta();


int retrieveNominas();

int retrieveFactura();

#endif // ADMINISTRATIVOS_H