#pragma once 

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <time.h>

#define MAX 100
#define MIN 1

using namespace std;

//funzione per la grandezza del vettore
unsigned int vector_cell(int N)
{
    unsigned int n;
    do
    {
        cout << "\ninserisci la grandezza dell'array :";
        cin >> n;
        if (n <= 0 && n > N)
        {
            cout << "\nERRORE:\n troppe celle :";
        }
    } while (n <= 0 && n > N);
    return n;
}

//ricerca binaria di un numero ( modo iterativo )
int binarySearch_iterativo(int inizio, int fine, int numero, int vet[])
{
    while (inizio <= fine)
    {
        int media = (inizio + fine - 1) / 2;
        if (numero == vet[media])
        {
            return media;
        }
        else if (numero > vet[media])
        {
            inizio = media + 1;
        }
        else
        {
            fine = media - 1;
        }
    }
    return -1;
}


//ricerca binaria di un numero ( modo ricorsivo )
int binarySearch_ricorsivo(int inizio, int fine, int numero, int vet[])
{
    if (inizio > fine)
    {
        return -1;
    }
    int media = (inizio + fine) / 2;
    if (numero == vet[media])
    {
        return media;
    }
    else if (numero > vet[media])
    {
        return binarySearch_ricorsivo(media + 1, fine, numero, vet);
    }
    else
    {
        return binarySearch_ricorsivo(inizio, media - 1, numero, vet);
    }

}

//funzione di riempimento del vettore
void fillVector(int vet[], int r)
{
    srand(time(0));
    for (int i = 0; i < r; i++)
    {
        vet[i] = MIN + (rand() % (MAX - MIN));
    }
}

//funzione di stampa del vettore
void vectorPrint(int vet[], int r)
{
    cout << "\n";
    for (int i = 0; i < r; i++)
    {
        cout << vet[i] << " ";
    }
    cout << "\n";
}

//funzione per ordinare un vettore con il selection sort
void selectionSort(int vet[], int r)
{
    int i_min;
    int temp;
    for (int i = 0; i < r; i++)
    {
        i_min = i;
        for (int x = i + 1; x < r; x++)
        {
            if (vet[x] < vet[i_min])
            {
                i_min = x;
            }
        }
        temp = vet[i_min];
        vet[i_min] = vet[i];
        vet[i] = temp;
    }
}

//funzione che riorganizza il vettore in base al pivot 
//(destra numeri piu grandi del pivot-sinistra numeri piu piccoli)
void riorganization_vector(int vet[], int vet2[], int r, int pivot)
{
    int j = 0, k = r - 1;
    for (int i = 0; i < r; i++)
    {
        if (i != pivot)
        {
            if (vet[i] <= vet[pivot])
            {
                vet2[j] = vet[i];
                j++;
            }
            else
            {
                vet2[k] = vet[i];
                k--;
            }
        }
    }
    vet2[j] = vet[pivot];
}

//Funzione per spostare tutti gli elementi del vettore
void shift(int V[], int& position, int neww)
{
    while (position > 0 && V[position - 1] > neww)
    {
        V[position] = V[position - 1];
        position--;
    }
}

//Funzione per ordinare un vettore con l'insertion sort
void insertSort(int V[], int N) {
    int position = 0, neww;
    srand((unsigned)time(nullptr));
    for (int i = 0; i < N; i++)
    {
        neww = rand() % MAX;
        position = i;
        shift(V, position, neww);
        V[position] = neww;
    }
}

//Funzione per riorgabizzare un vettore in base al pivot
void vector_sort_with_pivot(int V[], int N, int vet2[])
{
    int position = 0, neww;
    srand((unsigned)time(nullptr));
    for (int i = 0; i < N; i++) {
        neww = V[i];
        position = i;
        shift(vet2, position, neww);
        vet2[position] = neww;
    }
}

//funzione per scambiare celle vettori
void vector_swap(int vet[], int var1, int var2)
{
    int temp;

    temp = vet[var1];
    vet[var1] = vet[var2];
    vet[var2] = temp;

}

//effettua il partizionamento in due sottovettori individuando il pivot
int  partition(int vet[], int sx, int dx, int r)
{
    int pivot, ipivot, temp;
    ipivot = sx;
    pivot = vet[ipivot];
    while (sx < dx)
    {
        while (vet[sx] <= pivot && sx < dx)
        {
            sx++;
        }
        while (vet[dx] > pivot)
        {
            dx--;
        }
        if (sx < dx)
        {
            vector_swap(vet, sx, dx);
        }
    }
    vector_swap(vet, ipivot, dx);
    vectorPrint(vet, r);

    return dx;
}

//funzione di ordinamento quick sort 
void quick_sort(int vet[], int e_sx, int e_dx, int r)
{
    int pivot;
    if (e_sx < e_dx)
    {
        pivot = partition(vet, e_sx, e_dx, r);

        quick_sort(vet, e_sx, pivot - 1, r);
        quick_sort(vet, pivot + 1, e_dx, r);
    }
    vectorPrint(vet, r);
}
