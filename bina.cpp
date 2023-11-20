//Sanchez Santos B. Alexis 367714
//19/NOVIEMBRE/2023
//CREAR, SOBRESCRIBIR Y/O CARGAR ARCHIVOS CON INFOMACION CREADA AUTOMATICAMENTE O CON INFORMACION MODIFICADA Y UTILIZAR ARCHIVOS BINARIOS
//ARCHIVOS BINARIO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include "libreria.h"

typedef int Tkey;
typedef struct _alum
{
    int status;
    Tkey key;
    char appat[30];
    char apmat[30];
    char nombre[30];
    char genero[10];
    int edad;
} Tdato;

int genreg(Tdato vect[5000], int i);
int vali_vec2(Tdato vect[5000], int x, int j);
void edit_reg(Tdato vect[5000], int i, int bandera);
int busqueda(Tdato vect[5000], int x, int j, int bandera);
void impreg(Tdato vect[5000], int inicio);
int ordenado(Tdato vect[5000], int n, int bandera);
void created(Tdato vect[5000], int i, char nomb[30]);
void nombarch(char nomb[30]);
void leerarch(char arch[30]);
void nombarch2(char nomb[30], char nomb2[30]);
int lee_arc_bin(Tdato vect[5000], int i, int bande);
void gen_arch_bin(Tdato vect[5000], int n, char name[30], char name2[30]);
int main()
{
    int opc, bandera1, bandera2, bandera3, bandera4, bandera5;
    int eliminar, macro, busq;
    int i, j, k;
    char archivo[30], archivo2[30], archrio[30], archrio2[30];
    Tdato vct[5000];
    i = 0;
    bandera5 = 0;
    bandera4 = 0;
    bandera3 = 0;
    bandera2 = 1;
    bandera1 = 0;
    system("CLS");
    srand(time(NULL));
    do
    {
        opc = vali_num(0, 11, "ELIGE UNA OPCION\n1-->Agregar automaticamente 100 registros\n2-->Editar registro\n3-->Eliminar registro\n4-->Buscar\n5-->Ordenar\n6-->Imprimir\n7-->Generar archivo\n8-->Ver archivo de texto\n9-->Crear archivo binario\n10-->Cargar archivo binario\n0-->salir ", "Esa opcion no es valida");
        switch (opc)
        {
        case 1:
            i = genreg(vct, i);
            bandera1 = 1;
            bandera2 = 0;
            break;
        case 2:
            edit_reg(vct, i, bandera1);
            break;
        case 3:
            macro = vali_num4(300000, 399999, "Escribe la matricula que quieres eliminar\nRecuerda que las matriculas vasn del 300000 al 399999 ", "Favor de no poner 0s a la izquierda y dentro del rango", 6);
            eliminar = busqueda(vct, macro, i, bandera2);
            if (eliminar != -1)
            {
                eliminar = vali_num4(1, 2, "Registro encontrado\n1-->Eliminar\n2-->Mantener ", "Esa opcion no existe", 1);
                if (eliminar == 1)
                {
                    printf("\nRegistro eliminado\n");
                    system("PAUSE");
                }
                else
                {
                    printf("\nRegistro no eliminado\n");
                    system("PAUSE");
                }
            }
            else
            {
                printf("\nEse registro no existe\n");
                system("PAUSE");
            }
            break;
        case 4:
            macro = vali_num4(300000, 399999, "Escribe la matricula \nRecuerda que las matriculas vasn del 300000 al 399999 ", "Favor de no poner 0s a la izquierda y dentro del rango", 6);
            busq = busqueda(vct, macro, i, bandera2);
            if (busq != -1)
            {
                printf("\nLa matricula %d, es el registro N. %d\n", macro, busq);
                system("PAUSE");
            }
            else
            {
                printf("\nEse registro no existe\n");
                system("PAUSE");
            }
            break;
        case 5:
            bandera2 = ordenado(vct, i, bandera2);
            break;
        case 6:
            impreg(vct, i);
            break;
        case 7:
            if (i > 0)
            {
                if (bandera3 == 0)
                {
                    nombarch(archivo);
                    bandera3 = 1;
                }
                created(vct, i, archivo);
                system("PAUSE");
            }
            else
            {
                printf("\nAun no se ha agregado ningun registro\n");
                system("PAUSE");
            }
            break;
        case 8:
            printf("\nCargar archivo .txt");
            printf("\nRecuerda que el archivo que quieras abrir debe existir y debe estar en la misma carpeta\n");
            system("PAUSE");
            nombarch(archivo2);
            leerarch(archivo2);
            break;
        case 9:
            if (bandera5 == 0)
            {
                if (i == 5000)
                {
                    if (bandera2 == 1)
                    {
                        nombarch2(archrio, archrio2);
                        gen_arch_bin(vct, i, archrio, archrio2);
                        bandera5 = 1;
                    }
                    else
                    {
                        printf("\nPrimero debes ordenar los registros\n");
                        system("PAUSE");
                    }
                }
                else
                {
                    printf("\nPrimero debes completar los 5000 registros\n");
                    system("PAUSE");
                }
            }
            else
            {
                printf("\nYa has creado el archivo binario\n");
                system("PAUSE");
            }
            break;
        case 10:
            j = i;
            i = lee_arc_bin(vct, i, bandera4);
            if (i == j)
            {
                bandera4 = 0;
            }
            else
            {
                bandera4 = 1;
            }
            break;
        default:
            printf("Adios...");
            break;
        }
    } while (opc != 0);

    return 0;
}

int genreg(Tdato vect[5000], int i)
{
    Tdato reg;
    char nombresm[][20] = {{"GIDEON"}, {"OFNIR"}, {"GODWYN"}, {"GODFREY"}, {"RADAGON"}, {"ALEXANDER"}, {"KALE"}, {"GODRIK"}, {"ROGIER"}, {"THOPS"}, {"KENNETH"}, {"SELUVIS"}, {"RYKARD"}, {"RADAHN"}, {"PARCHES"}, {"MORGOTT"}, {"MOHG"}, {"MALIKETH"}, {"MARGIT"}, {"HEWG"}, {"IJI"}, {"BLAIDD"}, {"MIRIEL"}, {"VARRE"}, {"YURA"}, {"CORHYM"}, {"AZUR"}, {"GOWRY"}};
    char nombresf[][20] = {{"FIA"}, {"SELLEN"}, {"HYETTA"}, {"IRINA"}, {"TANITH"}, {"RYA"}, {"RODERIKA"}, {"RENNALA"}, {"MARIKA"}, {"RANNI"}, {"NEPHELI"}, {"MIQUELLA"}, {"MILICENT"}, {"MELINA"}, {"MALENIA"}, {"LATENNA"}, {"ISIDORA"}, {"ANTONELA"}, {"EMILIA"}, {"MADISON"}, {"AVA"}, {"OLIVIA"}, {"ISABELA"}, {"EMMA"}, {"SOPHIA"}, {"ELIZABETH"}, {"ELENA"}, {"SAMARA"}};
    char apellidos[][20] = {{"SODEBERG"}, {"MIKKONEN"}, {"WALLGREN"}, {"HEGG"}, {"GEMBALLA"}, {"HELDEN"}, {"SCHLEGEL"}, {"GREYWOLF"}, {"DORN"}, {"FALCONCINI"}, {"FILIA"}, {"CAVALIERI"}, {"HOGLAN"}, {"WALTS"}, {"ALATRIZ"}, {"GONTIER"}, {"BASS"}, {"KERCH"}, {"SHADOWS"}, {"CRAHAN"}, {"JORDISON"}, {"FAGENSON"}, {"SOUZA"}, {"MOMSEN"}, {"ROSES"}, {"OSBORNE"}, {"TAYLOR"}, {"BLINK"}, {"FORGE"}, {"MAY"}, {"DEACON"}, {"LEE"}, {"DRAIMAN"}, {"DONEGAN"}, {"MOYER"}, {"HARRIS"}, {"MURRAY"}};
    int gen, rango, rango2, j, matro, subopc;
    j = 0;
    rango2 = 60 - 18;
    system("CLS");
    if (i < 5000)
    {
        while (j < 100)
        {
            reg.status = 1;
            gen = rand() % 2;
            if (gen == 0)
            {
                strcpy(reg.genero, "MASCULINO");
                strcpy(reg.nombre, nombresm[rand() % 28]);
            }
            else
            {
                strcpy(reg.genero, "FEMENINO");
                strcpy(reg.nombre, nombresf[rand() % 28]);
            }
            strcpy(reg.appat, apellidos[rand() % 37]);
            strcpy(reg.apmat, apellidos[rand() % 37]);
            reg.edad = (rand() % rango2) + 18;
            do
            {
                matro = (rand() % rango) + 300000;
                subopc = vali_vec2(vect, matro, i);
                if (subopc == 0)
                {
                    reg.key = matro;
                }

            } while (subopc == 1);
            vect[i] = reg;
            i++;
            j++;
        }
        printf("\nSe han agregado correctamente 100 registros\n");
    }
    else
    {
        printf("\nYa se han alcanzado el limite de registros\n");
    }
    system("PAUSE");

    return i;
}

int vali_vec2(Tdato vect[5000], int x, int j)
{
    int i;
    for (i = 0; i < j; i++)
    {
        if (vect[i].key == x)
        {
            return 1;
        }
    }
    return 0;
}

void edit_reg(Tdato vect[5000], int i, int bandera)
{
    int pos, edit, bande, matro, largo, edad, gen;
    char temp[30];
    int j;
    system("CLS");
    if (bandera == 1)
    {
        do
        {
            printf("   MATRICULA   NOMBRE  APPATERNO  APMATERNO EDAD    SEXO\n");
            for (j = 0; j < i; j++)
            {
                printf("%4d  %d %9s %10s %10s %3d  %9s\n", j, vect[j].key, vect[j].nombre, vect[j].appat, vect[j].apmat, vect[j].edad, vect[j].genero);
            }
            system("PAUSE");
            j = i - 1;
            pos = vali_num(-1, j, "Cual posicion de registro quiere editar\nSi necesitas volver a ver la lista escribe -1 ", "Ese registro no existe");

        } while (pos == -1);
        edit = vali_num(0, 7, "Que quieres editar?\n1-->La matricula\n2-->Nombre\n3-->Apellido paterno\n4-->Apellido materno\n5-->Edad\n6-->Genero\n0-->Nada ", "Esa opcion no es valida");
        switch (edit)
        {
        case 1:
            do
            {
                matro = vali_num4(300000, 399999, "Matricula\nEscribe la nueva matricula\nRecuerda que las matriculas van de 300000 a 399999 ", "No agregar 0s a la izquierda y Escribir matriculas validas", 6);
                bande = vali_vec2(vect, matro, i);
                if (bande == 1)
                {
                    printf("No puedes escribir matriculas ya existentes\n");
                    system("PAUSE");
                }
                else
                {
                    vect[pos].key = matro;
                    printf("Matricula cambiada\n");
                    system("PAUSE");
                }
            } while (bande != 0);

            break;
        case 2:
            lee_cad(temp, "Escribe el nuevo nombre\nSi el nombre enie cambiala por una n o una x ");
            largo = largo_cadena(temp);
            strcpy(vect[pos].nombre, temp);
            vect[pos].nombre[largo] = '\0';
            printf("\nNombre cambiado\n");
            system("PAUSE");
            break;
        case 3:
            lee_cad(temp, "Escribe el nuevo apellido paterno\nSi el apellido enie cambiala por una n o una x ");
            largo = largo_cadena(temp);
            strcpy(vect[pos].appat, temp);
            vect[pos].appat[largo] = '\0';
            printf("\nApellido paterno cambiado\n");
            system("PAUSE");
            break;
        case 4:
            lee_cad(temp, "Escribe el nuevo apellido materno\nSi el apellido enie cambiala por una n o una x ");
            largo = largo_cadena(temp);
            strcpy(vect[pos].apmat, temp);
            vect[pos].apmat[largo] = '\0';
            printf("\nApellido materno cambiado\n");
            system("PAUSE");
            break;
        case 5:
            vect[pos].edad = vali_num(18, 70, "Escribe la nueva edad\nDe 18 a 70 ", "Solo aceptamos a mayores de edad o y no mayores a 70");
            printf("\nEdad cambiada\n");
            system("PAUSE");
            break;
        case 6:
            gen = vali_num(1, 2, "1-->MASCULINO\n2-->FEMENINO ", "Esa opcion no es valida");
            if (gen == 1)
            {
                strcpy(vect[pos].genero, "MASCULINO");
            }
            else
            {
                strcpy(vect[pos].genero, "FEMENINO");
            }
            printf("\nGenero cambiado\n");
            system("PAUSE");
            break;
        default:
            printf("Regresando...\n");
            system("PAUSE");
            break;
        }
    }
    else
    {
        printf("Aun no has cargado ningun registro\n");
        system("PAUSE");
    }
}

int busqueda(Tdato vect[5000], int x, int j, int bandera)
{
    int i;
    if (bandera == 0)
    {
        for (i = 0; i < j; i++)
        {
            if (vect[i].key == x)
            {
                return i;
            }
        }
    }
    else
    {
        for (i = 0; i < j; i++)
        {
            if (vect[i].key <= x)
            {
                if (vect[i].key == x)
                {
                    return i;
                }
            }
            else
            {
                return -1;
            }
        }
    }

    return -1;
}

int ordenado(Tdato vect[5000], int n, int bandera)
{
    int i, j;
    Tdato temp;
    system("CLS");
    if (bandera == 0)
    {
        for (i = 0; i < (n - 1); i++)
        {
            for (j = (i + 1); j < n; j++)
            {
                if (vect[j].key < vect[i].key)
                {
                    temp = vect[i];
                    vect[i] = vect[j];
                    vect[j] = temp;
                }
            }
        }
        printf("ORDENADO\n");
        system("PAUSE");
    }
    else
    {
        printf("Ya esta ordenado\n");
        system("PAUSE");
    }
    return 1;
}

void impreg(Tdato vect[5000], int inicio)
{
    int i;
    system("CLS");
    printf("IMPRESION\n");
    printf("Registros validos\n");
    printf("   MATRICULA   NOMBRE  APPATERNO  APMATERNO EDAD    SEXO\n");
    for (i = 0; i < inicio; i++)
    {
        if (vect[i].status == 1)
        {
            printf("%4d %d %9s %10s %10s %3d %9s\n", i, vect[i].key, vect[i].nombre, vect[i].appat, vect[i].apmat, vect[i].edad, vect[i].genero);
        }
        if (i % 40 == 0)
        {
            printf("\n\n");
        }
    }

    system("PAUSE");
}

void nombarch(char nomb[30])
{
    int largo;
    lee_cad2(nomb, "Escribe el nombre del archivo sin la extension .txt");
    largo = largo_cadena(nomb);
    nomb[largo] = '.';
    nomb[largo + 1] = 't';
    nomb[largo + 2] = 'x';
    nomb[largo + 3] = 't';
    nomb[largo + 4] = '\0';
}

void created(Tdato vect[5000], int i, char nomb[30])
{
    FILE *fa;
    int j;
    fa = fopen(nomb, "w");
    for (j = 0; j < i; j++)
    {
        if (vect[j].status == 1)
        {
            fprintf(fa, "%4d %d %9s %10s %10s %3d %9s\n", j, vect[j].key, vect[j].nombre, vect[j].appat, vect[j].apmat, vect[j].edad, vect[j].genero);
        }
        if (j % 40 == 0)
        {
            fprintf(fa, "\n\n");
        }
    }
    fclose(fa);
}

void leerarch(char arch[30])
{
    FILE *fa;
    char caracter;
    system("CLS");
    fa = fopen(arch, "r");
    if (fa)
    {

        do
        {
            caracter = fgetc(fa);
            printf("%c", caracter);

        } while (!feof(fa));
        fclose(fa);
        system("PAUSE");
    }
    else
    {
        printf("\nEse archivo no existe\n");
        system("PAUSE");
    }
}

void nombarch2(char nomb[30], char nomb2[30])
{
    int largo;
    lee_cad2(nomb, "Escribe el nombre del archivo binario sin extension ");
    strcpy(nomb2, nomb);
    largo = largo_cadena(nomb);
    nomb[largo] = '.';
    nomb[largo + 1] = 'd';
    nomb[largo + 2] = 'l';
    nomb[largo + 3] = 'l';
    nomb[largo + 4] = '\0';
    nomb2[largo] = '.';
    nomb2[largo + 1] = 't';
    nomb2[largo + 2] = 'm';
    nomb2[largo + 3] = 'p';
    nomb2[largo + 4] = '\0';
}

int lee_arc_bin(Tdato vect[5000], int i, int bande)
{
    Tdato reg;
    FILE *fa;
    system("CLS");
    if (bande == 0)
    {
        fa = fopen("datos.dll", "rb");
        if (fa)
        {
            while (fread(&reg, sizeof(Tdato), 1, fa))
            {
                vect[i++] = reg;
            }
            fclose(fa);
        }
        else
        {
            printf("\nEl archivo no existe");
            system("PAUSE");
        }
    }
    else
    {
        printf("\nEl archivo ya esta cargado\n");
        system("PAUSE");
    }
    return i;
}

void gen_arch_bin(Tdato vect[5000], int n, char name[30], char name2[30])
{
    Tdato reg;
    int i;
    FILE *fa;
    FILE *gb;
    fa = fopen(name, "ab");
    for (i = 0; i < n; i++)
    {
        reg = vect[i];
        fwrite(&reg, sizeof(Tdato), 1, fa);
    }
    fclose(fa);
    gb = fopen(name2, "ab");
    for (i = 0; i < n; i++)
    {
        reg = vect[i];
        fwrite(&reg, sizeof(Tdato), 1, fa);
    }
    fclose(gb);
}