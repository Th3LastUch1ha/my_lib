# all u need for exercises with arrays!

# in this library you'll find all you need for an exercise with arrays

++++++++++++++++++++++++++++++++++++

functions used in this library:

unsigned int vector_cell(int N);      //this function returns lenght for your array

void userStuffing(int arr[], int N)     //this function gives the user the possibility to fill manually the array

void randomArrStuffing(int arr[], int r);     //this function fills your array with random numbers 

void randomArrStuffingWLimits(int arr[], int r, int max, int min);      //this function fills your array with random numbers between limits

void shift(int V[], int& position, int neww);      //this function shift values in your array

void vector_swap(int vet[], int var1, int var2);      //this function swaps values in your array

int drawIndex(int NUMS);      //this function draws a casual index

void vectorPrint(int vet[], int r);      //this function prints your array

void SetColor(int ForgC);      //this function is useful for the "vectorPrintWColoredIndex" function

void vectorPrintWColoredIndex(int arr[], int r, int index);      //this function prints an array with 1 desired index colored (see this-> colors for SetColor() func. ) 

void basicBubbleSort(int arr[], int N);      //this function order your array with the basic vers. of Bubble Sort

void flagBubbleSort(int arr[], int N);      //this function order your array with the evolved vers. of Bubble Sort

void insertSort(int V[], int N);      //this function order your array with the Insert Sort

void vector_sort_with_pivot(int V[], int N, int vet2[]);      //this function order your array with the Insert Sort but with a Pivot number

void selectionSort(int vet[], int r);      //this function order your array with the Selection Sort

int partition(int vet[], int sx, int dx, int r);      //this function is useful for the "quick_sort" function

void quick_sort(int vet[], int e_sx, int e_dx, int r);      //this function order your array with the Quick Sort

void riorganization_vector(int vet[], int vet2[], int r, int pivot);      //this function rearrange your array

int linear_search(int vet[], int n, int r);     //this function searches an element using the Linear Search

int binarySearch_iterativo(int inizio, int fine, int numero, int vet[]);     //this function searches an element using the iterative vers. of Binary Search

int binarySearch_ricorsivo(int inizio, int fine, int numero, int vet[]);     //this function searches an element using the recursive vers. of Binary Search
