#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>
#include <string.h>
#include <ctype.h>

void cargarProductos();
int retrieveEmployees();
int retrieveAreas();
void finish_with_error(MYSQL* con);
char readFile(char* filename);
const char* getInfo(char* line, int num);
void menuOpcionesOperativas();
void menuOpcionesAdministrativas();


//Función para cargar archivos
void cargarProductos(){
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

    if (mysql_real_connect(con, "localhost", "root", "root",
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

//Función para mostrar los empleados en la base de datos
int retrieveEmployees() {
    MYSQL* con = mysql_init(NULL);

    if (con == NULL)
    {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "root", "root",
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

//Función para mostrar los productos en la base de datos
int retrieveProducts() {
    MYSQL* con = mysql_init(NULL);

    if (con == NULL)
    {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "root", "root",
        "sistemaagricola", 0, NULL, 0) == NULL)
    {
        finish_with_error(con);
    }

    if (mysql_query(con, "SELECT * FROM producto"))
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

//Función que imprime en pantalla error de inserción en la base de datos
void finish_with_errorINSERT(MYSQL* con)
{
    printf("La informacion del Archivo ya existe en la base de datos o el archivo presenta errores. Intente de nuevo. \n");
    mysql_close(con);
    menuOpcionesOperativas();
}

//Función que imprime en pantalla error en la base de datos
void finish_with_error(MYSQL* con)
{
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    menuOpcionesOperativas();
}

//Función que concatena strings e inserta información a la base de datos
char* concat(char* str1, char* str2) {

    MYSQL* con = mysql_init(NULL);

    if (con == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }
    if (mysql_real_connect(con, "localhost", "root", "root",
        "sistemaagricola", 0, NULL, 0) == NULL)
    {
        finish_with_error(con);
    }

    // Declare a new Strings
    // to store the concatenated String
    char str3[100];


    int i = 0, j = 0;

    // Insert the first string in the new string
    while (str1[i] != '\0') {
        str3[j] = str1[i];
        i++;
        j++;
    }

    // Insert the second string in the new string
    i = 0;
    while (str2[i] != '\0') {
        str3[j] = str2[i];
        i++;
        j++;
    }
    str3[j] = ')';
    str3[j + 1] = ';';
    str3[j + 2] = '\0';

    printf(str3);
    if (mysql_query(con, str3)) {
        finish_with_errorINSERT(con);
    }

    // Print the concatenated string
    return str3;
}

//Función que lee el archivo enviado por el usuario
char readFile(char* filename) {

    FILE* fp;
    char a[20];
    char b[20];
    char c[20];
    char d[20];
    char query[] = "INSERT INTO producto (idproducto,nombre,costo,impuesto) VALUES (";
    char line[512];
    char par = ')';
    int cur_line = 0;
    fp = fopen(filename, "r");
    if (fp == NULL) { 
        printf("No existe el archivo"); 
    }
    else {
        //printf(fgets(line, 512, fp));
        while (fgets(line, 512, fp) != NULL) {
            if (cur_line != fp) { // 3rd line
                /* get a line, up to 512 chars from in.  done if NULL */
                sscanf(line, "%s %s %s %s \n", a, b, c, d);
                char* stringC = concat(query, a);
                // now you should store or manipulate those strings
            }
            cur_line++;

    
            
        }

    }
    

}

//Función que consigue la información del archivo indicado
const char* getInfo(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
        tok && *tok;
        tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

int registrarNomina() {
    MYSQL* con = mysql_init(NULL);

    
    int mes;
    int year;
    int cedula;
    char combine[100];
    char query = "INSERT INTO nomina VALUES(";
    printf("\n");
    printf("Ingrese el numero del mes de la nomina que desea registrar:\n");
    scanf("%d", &mes);
    printf("\n");
    printf("Ingrese el año de la nomina:\n");
    scanf("%d", &year);
    printf("\n");
    printf("Ingrese de cedula del empleado que desea agregar:\n");
    scanf("%d", &cedula);
    printf("\n");
    sprintf(combine, "INSERT INTO nomina VALUES(%d,%d,%d);", mes, year, cedula);
    if (con == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }
    if (mysql_real_connect(con, "localhost", "root", "root",
        "sistemaagricola", 0, NULL, 0) == NULL)
    {
        finish_with_error(con);
    }
    if (mysql_query(con, combine)) {
        finish_with_error(con);
    }

    return 0;


}

//Pending
int registrarVenta() {
    MYSQL* con = mysql_init(NULL);

    if (con == NULL)
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }
    if (mysql_real_connect(con, "localhost", "root", "root",
        "sistemaagricola", 0, NULL, 0) == NULL)
    {
        finish_with_error(con);
    }
    int idcliente, cantidad, area;
    char* idprod[2];
    char* fecha[12];
    int c = 1;
    char *combine[100];
    printf("\n");
    printf("Lista de Productos Disponibles:\n");
    retrieveProducts();
    printf("\n");
    printf("Lista de Areas registradas:\n");
    retrieveAreas();
    printf("\n");
    printf("Ingrese el id del cliente (cedula):\n");
    scanf("%d", &idcliente);
    printf("\n");
    printf("Ingrese la fecha de la factura en formato YYYY-MM-DD:\n");
    scanf("%s", &fecha);
    while (c != 0) {
        printf("\n");
        printf("Ingrese el id del producto:\n");
        scanf("%s", &idprod);
        printf("\n");
        printf("Ingrese la cantidad del producto:\n");
        scanf("%d", &cantidad);
        printf("\n");
        printf("Ingrese el id del area de produccion:\n");
        scanf("%d", &area);
        sprintf(combine, "INSERT INTO factura(idcliente,idprod,areaprod,cantidad,fecha) VALUES(%d,'%s',%d,%d,'%s');", idcliente, idprod, area, cantidad, fecha);
        if (mysql_query(con, combine)) {
            finish_with_error(con);
        }
        printf("Ingrese 1 para agregar otro producto o 0 para cerrar factura:\n");
        scanf("%d", &c);
        printf("El int es %d", c);
    }
    

}

int retrieveNominas() {
    MYSQL* con = mysql_init(NULL);
    int year;
    int mes;
    char combine[300];
    printf("\n");
    printf("Ingrese el año de la nomina que desea ver:\n");
    scanf("%d", &year);
    printf("\n");
    printf("Ingrese el numero del mes de la nomina que desea ver:\n");
    scanf("%d", &mes);
    sprintf(combine, "SELECT nomina.empleado, empleado.nombre, empleado.primerapellido, empleado.segundoapellido, empleado.salario FROM nomina INNER JOIN empleado ON nomina.empleado = empleado.cedula AND nomina.mes = %d AND nomina.year = %d;", mes, year);
    if (con == NULL)
    {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "root", "root",
        "sistemaagricola", 0, NULL, 0) == NULL)
    {
        finish_with_error(con);
    }

    if (mysql_query(con, combine))
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

int retrieveFactura() {
    MYSQL* con = mysql_init(NULL);
    int cliente;
    char combine[400];
    printf("\n");
    printf("Ingrese el id del cliente cuyas facturas desea ver:\n");
    scanf("%d", &cliente);
    printf("\n");
    sprintf(combine, "SELECT producto.nombre AS Producto, factura.cantidad AS Cantidad, factura.areaprod AS Area, producto.costo*factura.cantidad AS PrecioTotal, producto.impuesto AS Impuesto, producto.costo*producto.impuesto AS PrecioFinal FROM factura INNER JOIN producto ON factura.idprod = idproducto AND factura.idcliente = %d;", cliente);
    if (con == NULL)
    {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "root", "root",
        "sistemaagricola", 0, NULL, 0) == NULL)
    {
        finish_with_error(con);
    }

    if (mysql_query(con, combine))
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

void menuOpcionesOperativas(){
    printf("\n");
    /*Debe ir una verificacion de usuario aca*/
    int opcion = 0;
    printf("Menu opciones operativas\n");
    printf("Ingrese 1 para cargar productos\n");
    printf("Ingrese 2 para listar areas\n");
    printf("Ingrese 3 para listar empleados\n");
    printf("Ingrese 4 para listar productos\n");
    printf("opcion: ");
    scanf("%d", &opcion);
    switch (opcion)
    {
    case 1:
        printf("\n");
        cargarProductos();
        menuOpcionesOperativas();
    
    case 2:
        printf("\n");
        retrieveAreas();
        printf("\n");
        menuOpcionesOperativas();

    case 3:
        printf("\n");
        retrieveEmployees();
        printf("\n");
        menuOpcionesOperativas();

    case 4:
        printf("\n");
        retrieveProducts();
        printf("\n");
        menuOpcionesOperativas();
    }
    return;

}

void menuOpcionesAdministrativas(){
    
    int opcion = 0;
    printf("\n");
    printf("Menu opciones administrativas\n");
    /*Aquí debería ir algo para traer los valores iniciales*/
    printf("Ingrese 1 para ingresar al registro de nómina\n");
    printf("Ingrese 2 para ingresar al registro de venta de productos\n");
    printf("Ingrese 3 para consultar nóminas\n");
    printf("Ingrese 4 para consultar ventas\n");
    printf("Ingrese 5 para ingresar al balance anual\n");
    printf("Ingrese 6 para salir\n");
    printf("opcion: ");
    scanf("%d", &opcion);
    switch (opcion)
    {
    case 1:
        registrarNomina();
        menuOpcionesAdministrativas();
    
    case 2:
        registrarVenta();
        menuOpcionesAdministrativas();

    case 3:
        retrieveNominas();
        menuOpcionesAdministrativas();

    case 4:
        retrieveFactura();
        menuOpcionesAdministrativas();
    
    case 5:
        printf("Balance Anual\n");
        menuOpcionesAdministrativas();

    case 6:
        printf("Salir\n");
        menuOpcionesAdministrativas();
    }
    return;

}

int main() {
    int opcion = 0;
    printf("Menu Principal\n");
    printf("Ingrese 1 para accesar a las opciones operativas\n");
    printf("Ingrese 2 para accesar a las opciones administrativas\n");
    printf("Ingrese 0 para salir\n");
    printf("opcion: ");
    scanf("%d", &opcion);
    while (opcion != 0) {
        switch (opcion)
        {
        case 1:
            menuOpcionesOperativas();
            break;

        case 2:
            menuOpcionesAdministrativas();
            break;
        }
    }
   return 0;
}
