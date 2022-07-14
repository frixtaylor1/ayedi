// TAYLOR, Kevin Daniel
// ISFT 151
// Algoritmos y Estructura de Datos I
// Marco Practico
// Array Multidimensionales Unidad 6

/*
1)Un archivo de texto contiene información acerca de los productos que se venden en un 
almacén. Lo único que se sabe acerca del número de productos es que no puede superar 
un cierto valor MaxProductos. De cada producto se guarda información sobre su código 
identificador (entero positivo), su precio (real) y el número de unidades existentes (entero 
positivo). El formato en el que se guarda la información dentro del archivo es el siguiente:
id1 precio1 unidades1
id2 precio2 unidades2
...
idN precioN unidadesN
-1
a) Declara un tipo tProducto que represente la información de un producto y
un tipo tLista que mantenga la información de todos los productos.
b) Escribe un subprograma que lea los datos del archivo de texto que almacena
la información, los guarde en la lista y luego los muestre en la pantalla.
c) Escribe un subprograma que encuentre el producto con máximo valor en el
almacén, considerando que el valor del producto i es precioi*unidadesi. 
d) Escribe un subprograma que dado un identificador de producto a eliminar
del almacén, lo busque en la lista y lo elimine actualizando la lista como
corresponda.
*/
#include <iostream>
#include <fstream>
#include <iomanip>


using std::ifstream;

const int CAPACITY = 50;

// Simple TDA in struct...
typedef struct 
{
    int     id;
    float   price; 
    int     unitys;
} tProduct;
typedef tProduct product[CAPACITY];
typedef struct 
{
    product products;
    int counter;

    void showDataProduct();
    void identifyMaxValue();
    void removeProduct(int id);

} tList;

void evaluateFile(ifstream& file, std::string error);
ifstream openFile(std::string fileNameDir);
tList getFileData(ifstream& file);

int main()
{
    std::ofstream openingfile("TICKET.txt", std::ofstream::app);
    std::ifstream file = openFile("TICKET.txt");

    tList lista = getFileData(file);
    file.close();

    lista.showDataProduct();

    lista.identifyMaxValue();

    int id;
    std::cout << "Enter The ID to REMOVE: ";
    std::cin >> id;
    lista.removeProduct(id);

    lista.showDataProduct();

    return EXIT_SUCCESS;
}
void tList::showDataProduct()
{
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << std::setw(15) << "ID" 
              << std::setw(15) << "UNITYS" 
              << std::setw(15) << "PRICE" 
              << std::endl;
    for (int idx = 0; idx < counter; idx++)
    {
        std::cout << std::setw(15) << products[idx].id
                  << std::setw(15) << products[idx].price 
                  << std::setw(15) << products[idx].unitys
                  << std::endl;
    }
    std::cout << "----------------------------------------------" << std::endl;

}
void tList::identifyMaxValue()
{
    int max = 0;
    int temp = 0;
    float maxprice = 0;
    for (int i = 0; i < counter; ++i)
    {
        maxprice = products[i].unitys * products[i].price;
        if (maxprice > max )
        {
            max = maxprice;
            temp = i; 
        }
    }
    std::cout << "----------------------------------------------" << std::endl;
    std::cout << "Most expensive is the [id: " << products[temp].id 
              << "] = $ " << max << std::endl;
    std::cout << "----------------------------------------------" << std::endl;
    
}
void tList::removeProduct(int iden)
{
    for (int i = 0; i < counter; ++i)
    {
        if (iden == products[i].id)
        {
            products[i] = products[i+1];        
        }    
    } 
    counter--;
}

void evaluateFile(ifstream& file, std::string error)
{
    bool condition = (!(file.is_open()) || !(file.good()));
    if (condition)
    {
        std::cout << error << std::endl;
        exit(EXIT_FAILURE);
    }
}
ifstream openFile(std::string fileNameDir)
{
    ifstream file;
    file.open(fileNameDir);
    evaluateFile(file, "Error, opening file!!");    

    return file;
}
tList getFileData(ifstream& file)
{
    tList ticketProducts;
    ticketProducts.counter = 0;
    if (file.is_open())
    {
        while(!file.eof())
        {
            file >> ticketProducts.products[ticketProducts.counter].id
                 >> ticketProducts.products[ticketProducts.counter].price
                 >> ticketProducts.products[ticketProducts.counter].unitys;
            ticketProducts.counter++;
        }
    }
    return ticketProducts;
}