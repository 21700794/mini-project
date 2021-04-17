#include <stdio.h>

typedef struct _product{
    char name[100];
    int weight;
    int price;
    int point;
    int npoint;
} Product;

void saveData(Product *p, int count)
int createProduct(Product *p);
void readProduct(Product p);
int updateProduct(Product *p);
int deleteProduct(Product *p);
int selectMenu();
void listProduct(Product *p, int count);
int selectDataNo(Product *p, int index);
