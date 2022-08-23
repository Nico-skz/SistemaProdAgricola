#include <stdio.h>
#include <stdlib.h>

/*Función para cargar archivos*/
void cargarProductos(){
    printf("Por favor ingrese la ruta del archivo del cual desea cargar productos\n");
    FILE * a;


    return;
}

void menuOpcionesOperativas(){
    /*Debe ir una verificacion de usuario aca*/
    int opcion = 0;
    printf("Menu opciones operativas\n");
    printf("Ingrese 1 para cargar productos\n");
    printf("Ingrese 2 para listar areas\n");
    printf("Ingrese 3 para listar empleados\n");
    printf("opcion: ");
    scanf("%d", &opcion);
    switch (opcion)
    {
    case 1:
        printf("Carga de productos/n");
        break;
    
    case 2:
        printf("Listar areas/n");
        break;

    case 3:
        printf("Listar empleados/n");
        break;
    }
    return;

}

void menuOpcionesAdministrativas(){
    
    int opcion = 0;
    printf("Menu opciones administrativas\n");
    /*Aquí debería ir algo para traer los valores iniciales*/
    printf("Ingrese 1 para ingresar al resgistro de nómina\n");
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
        printf("Registro de nomina/n");
        break;
    
    case 2:
        printf("Registro de Venta de Productos/n");
        break;

    case 3:
        printf("Consulta de Nominas/n");
        break;
   case 4:
        printf("Consulta de Ventas/n");
        break;
    
    case 5:
        printf("Balance Anual/n");
        break;

    case 6:
        printf("Salir/n");
        break;
    }
    return;

}

int main(){
   int opcion = 0;
   printf("Menu Principal\n");
   printf("Ingrese 1 para accesar a las opciones operativas\n");
   printf("Ingrese 2 para accesar a las opciones administrativas\n");
   printf("opcion: ");
   scanf("%d",&opcion);
   switch (opcion)
   {
   case 1:
    menuOpcionesOperativas();
    break;
   
   case 2:
    menuOpcionesAdministrativas();
    break;
   }
   return 0;
}
