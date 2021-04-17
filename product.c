#include "product.h"


int main() {
    Product p;
    int count = 0, menu;

    while(1){
        menu = selectMenu();
        if(menu == 0) break;
        if(menu == 1){
            if (count > 0) 
                readProduct(p);
            else
                printf("=> 데이터가 없습니다.\n");
        }
        else if (menu == 2){
            count = createProduct(&p);
        }
        else if (menu == 3){
            updateProduct(&p);
        }
        else if (menu == 4){
            int del = 0;
            del = deleteProduct(&p);
            if (del == 1) {
                printf("=> 삭제됨!\n");
                count = 0;
            }
        }
    }
    printf("종료됨!\n");
    return 0;
}

