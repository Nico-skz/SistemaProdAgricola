#include "Operativos.h"
#include <stdlib.h>
#include <mysql.h>
#include <cstdio>

void cargarProductos() {
    char filename[300];
    printf("Por favor ingrese la ruta del archivo del cual desea cargar productos\n");
    scanf("%s", &filename);
    readFile(&filename);




    return;
}

//Función para mostrar las areas en la base de datos
int retrieveAreas() {
    MYSQL* con = mysql_init(NULL);

    if (con == NULL)
    {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "root", "2min",
        "sistemaagricola", 0, NULL, 0) == NULL)
    {
        finish_with_error(con);
    }

    if (mysql_query(con, "SELECT * FROM area"))
    {
        finish_with_error(con);
    }

    MYSQL_RES* result = mysql_store_result(con);

    if (result == NULL)
    {
        finish_with_error(con);
    }

    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result)))
    {
        for (int i = 0; i < num_fields; i++)
        {
            printf("%s ", row[i] ? row[i] : "NULL");
        }

        printf("\n");
    }

    mysql_free_result(result);
    mysql_close(con);


}

//

//Función para mostrar los empleados en la base de datos
int retrieveEmployees() {
    MYSQL* con = mysql_init(NULL);

    if (con == NULL)
    {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "root", "2min",
        "sistemaagricola", 0, NULL, 0) == NULL)
    {
        finish_with_error(con);
    }

    if (mysql_query(con, "SELECT * FROM empleado"))
    {
        finish_with_error(con);
    }

    MYSQL_RES* result = mysql_store_result(con);

    if (result == NULL)
    {
        finish_with_error(con);
    }

    int num_fields = mysql_num_fields(result);

    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result)))
    {
        for (int i = 0; i < num_fields; i++)
        {
            printf("%s ", row[i] ? row[i] : "NULL");
        }

        printf("\n");
    }

    mysql_free_result(result);
    mysql_close(con);


}