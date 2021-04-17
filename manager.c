#include "manager.h"

void saveData(Product *p, int count)
{
    FILE *fp;
    fp = fopen("product.txt", "wt");

    for(int i = 0; i < count; i++){
        if(p[i].price == -1) continue;
        fprintf(fp, "%4s %4d %4d %4d %4d", p[i].name, p[i].weight, p[i].price, p[i].point, p[i].npoint);
    }
    fclose(fp);
    printf("=> 저장됨");
}

int loadData(Product *p)
{
    int count = 0, i = 0;
    FILE *fp;
    fp = fopen("product.txt", "rt");

    for(; i<100; i++){
        fscanf(fp, "%s", p[i].name);
        if(feof(fp)) break;
        fscanf(fp, "%d", &p[i].weight);
        fscanf(fp, "%d", &p[i].price);
        fscanf(fp, "%d", &p[i].point);
        fscanf(fp, "%d", &p[i].npoint);
        count++;
    }
    fclose(fp);
    if(count == 0) printf("=> 파일 없음!\n");
    else printf("=> 로딩 성공!\n");
    return i;
}

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

void listProduct(Product *p, int count){
    printf("\nNo Name Weight Price Point Number\n");
    printf("=======================================\n");

    for(int i = 0; i < count; i++){
        if(p[i].price == -1) continue;
        printf("%3d %4s %4d %4d %4d %4d\n", i+1, p[i].name, p[i].weight, p[i].price, p[i].point, p[i].npoint);
    }
}

int selectDataNo(Product *p, int index){
	int no;
	listProduct(p, index);
	printf("\n번호는 (취소: 0)?");
	scanf(" %d", &no);
	return no;
}
