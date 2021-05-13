
#ifndef MENU_H_
#define MENU_H_
/* 	brief muestra un menu con 5 opciones y devuelve por parametro puntero la opcion elegida.
 *  opcion 1 loguea (no se puede realizar ninguna otra accion sin loguearse primero)
 *  opcion 2 compra
 *  opcion 3 ve sus compras
 *  opcion 4 vende (no puede vender si no compro y si ya vendio una vez tampoco)
 *  opcion 5 sale del menu
 * */
int menu(int* opcionPuntero);
int subMenu(int* opcionSubMenuPuntero);
#endif /* MENU_H_ */
