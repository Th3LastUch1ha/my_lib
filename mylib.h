
/*
                                    --- INDICE: 1) RIEMPIMENTI 2) SWAP, SHIFT e UTILI 3) STAMPE 4) ORDINAMENTI 5) RICERCHE ---
*/

#pragma once 

#include <string>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <time.h>
#include <Windows.h>

#define MAX 100
#define MIN 1

using namespace std;



//                                                                  **RIEMPIMENTI**



//funzione per la grandezza del vettore
unsigned int vector_cell(int N)
{
    unsigned int n;
    do
    {
        cout << "\nInserisci la grandezza dell'array :";
        cin >> n;
        if (n <= 0 && n > N)
        {
            cout << "\nERRORE:\n troppe celle :";
        }
    } while (n <= 0 && n > N);
    return n;
}

//funzione di riempimento del vettore con inserimento dell'utente
void userStuffing(int arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        cin>> arr[i];
    }
}

//funzione di riempimento del vettore di tipo stringa con inserimento dall'utente
void userStringArrStuffing(string arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        getline(cin,arr[i]);
    }
}

//funzione di riempimento randomico del vettore
void randomArrStuffing(int arr[], int r)
{
    srand(time(0));
    for (int i = 0; i < r; i++)
    {
        arr[i] = (rand() % MAX);
    }
}

//funzione di riempimento randomico del vettore tra due limiti (MAX, MIN)
void randomArrStuffingWLimits(int arr[], int r, int max, int min)
{
    srand(time(0));
    for (int i = 0; i < r; i++)
    {
        arr[i] = min + (rand() % (max - min));
    }
}



//                                                                  **SWAP, SHIFT e UTILI**



//Funzione per spostare tutti gli elementi del vettore
void shift(int V[], int& position, int neww)
{
    while (position > 0 && V[position - 1] > neww)
    {
        V[position] = V[position - 1];
        position--;
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

//funzione di estrazione randomica di un indice
int drawIndex(int NUMS)
{
    int result;
    srand(time(0));
    result = (rand() % NUMS);

    return result;
}

//funzione che imposta l'array nel verso opposto
void reverse(int arr[], int N)
{

    int temp;

    for(int i = 0, j = N-1; i < N/2; i++, j--)
        {

        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        }
}

//funzione che addiziona in un terzo array due array paralleli cella per cella
void sumParallelArray(int arr1[], int arr2[], int sumArr[], int N)
{

    for(int i=0; i<N; i++)
    {
        sumArr[i]=arr1[i]+arr2[i];
    }

}



//                                                                             **STAMPE**



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

//funzione di stampa del vettore di tipo stringa
void stringVectorPrint(string vet[], int r)
{
    cout << "\n";
    for (int i = 0; i < r; i++)
    {
        cout << vet[i] << " ";
    }
    cout << "\n";
}

//funzione necessaria per l'implementazione della funzione a seguire (vectorPrintWColoredIndex)
void SetColor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}

//funzione di stampa del vettore con un desiderato indice colorato
void vectorPrintWColoredIndex(int arr[], int r, int index)
{
    for (int i = 0; i < r; i++)
    {
        if (i == index)
        {
            SetColor(9);
            cout << arr[i] << " ";
            SetColor(15);
        }
        else
        {
            cout << arr[i] << " ";
        }
    }
    cout << "\n";
}



//                                                                      **ORDINAMENTI**



//prima implementazione basica del bubble sort
void basicBubbleSort(int arr[], int N)
{
    int x, y;
    int support;
    for (x = 0; x < N - 1; x++)
    {
        for (y = 0; y < N - 1; y++)
        {
            if (arr[y] > arr[y + 1])
            {
                support = arr[y];
                arr[y] = arr[y + 1];
                arr[y + 1] = support;
            }
        }
    }

}

//bubble sort con sentinella
void flagBubbleSort(int arr[], int N)
{
    int support = 0;
    bool flag = false;
    int j = 0;
    do
    {
        flag = false;

        for (int i = 0; i < N - 1 - j; i++)
        {
            if (arr[i] > arr[i + 1])
            {

                support = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = support;
                flag = true;

            }
        }
        j++;
    } while (flag);

}



//bubble sort con sentinella per vettori paralleli
void flagParallelSort(int arr[], string text[], int N)
{
    int support = 0;
    string strsupport;
    bool flag = false;
    int j = 0;
    do
    {
        flag = false;

        for (int i = 0; i < N - 1 - j; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                flag = true;
                support = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = support;

                strsupport=text[i];
                text[i]=text[i+1];
                text[i+1]=strsupport;
            }
        }
        j++;
    } while (flag);

}

//bubble sort con sentinella ma inverso
void inverseFlagBubbleSort(int arr[], int N)
{
    int support = 0;
    bool flag = false;
    int j = 0;
    do
    {
        flag = false;

        for (int i = 0; i < N - 1 - j; i++)
        {
            if (arr[i] <= arr[i + 1])
            {

                support = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = support;
                flag = true;

            }
        }
        j++;
    } while (flag);

}

//bubble sort con sentinella per vettori paralleli
void reverseFlagParallelSort(int arr[], string text[], int N)
{
    int support = 0;
    string strsupport;
    bool flag = false;
    int j = 0;
    do
    {
        flag = false;

        for (int i = 0; i < N - 1 - j; i++)
        {
            if (arr[i] <= arr[i + 1])
            {
                flag = true;
                support = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = support;

                strsupport=text[i];
                text[i]=text[i+1];
                text[i+1]=strsupport;
            }
        }
        j++;
    } while (flag);

}

//funzione per ordinare un vettore con l'insertion sort
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

//Funzione per riorganizzare un vettore in base al pivot
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



//                                                                     **RICERCHE**



//ricerca lineare di un numero
int linear_search(int vet[], int n, int r)
{
    for (int i = 0; i < r; i++)
    {
        if (vet[i] == n)
        {
            return i;
        }
    }
    return -1;
}
//ricerca binaria di un numero ( modo iterativo )
int binarySearch_iterative(int inizio, int fine, int numero, int vet[])
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
int binarySearch_recursive(int inizio, int fine, int numero, int vet[])
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
        return binarySearch_recursive(media + 1, fine, numero, vet);
    }
    else
    {
        return binarySearch_recursive(inizio, media - 1, numero, vet);
    }

}
