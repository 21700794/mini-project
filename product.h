#include <stdio.h>

typedef struct _product{
    char name[100];
    int weight;
    int price;
    int point;
    int npoint;
} Product;

int createProduct(Product *p) 
{
    printf("제품명은? : ");
    scanf(" %s", p->name);
    printf("중량은? : ");
    scanf(" %d", &p->weight);
    printf("가격은? : ");
    scanf(" %d", &p->price);
    printf("별점은? : ");
    scanf(" %d", &p->point);
    printf("별점 개수는? : ");
    scanf(" %d", &p->npoint);
    printf("=> 저장되었습니다.\n");
    return 1; 
}

void readProduct(Product p) 
{
    printf("%4s %4d %4d %4d %4d\n", p.name, p.weight, p.price, p.point, p.npoint);
}

int updateProduct(Product *p)
{
    printf("제품명은? : ");
    scanf(" %s", p->name);
    printf("중량은? : ");
    scanf(" %d", &p->weight);
    printf("가격은? : ");
    scanf(" %d", &p->price);
    printf("별점은? : ");
    scanf(" %d", &p->point);
    printf("별점개수는? : ");
    scanf(" %d", &p->npoint);
    printf("=> 수정되었습니다.\n");
    return 1; 
}

int deleteProduct(Product *p) 
{
    p->price = -1;
    p->npoint = -1;
    p->weight = -1;
    p->point = -1;
    return 1;
}

int selectMenu()
{
    int menu;
    printf("\n*** 쇼핑몰 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}
