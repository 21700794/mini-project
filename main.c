#include "manager.h"

int main(){
    Product p[20];
    int count = 0, index = 0, no, menu;
#ifdef DEBUG
    printf("DEBUGMODE\n");
#endif
    count = loadData(p);
    index = count;

    while(1){
        menu = selectMenu();
        if(menu == 0) break;
        if(menu == 1){
            if (count > 0)
                listProduct(p, index);
            else
                printf("=> 데이터가 없습니다.\n");
        }
        else if (menu == 2){
            count += createProduct(&p[index++]);
        }
        else if (menu == 3){
            no = selectDataNo(p, index);
            if(no == 0){
                printf("=> 취소됨!");
                continue;
            }
            updateProduct(&p[no-1]);
        }
        else if (menu == 4){
            no = selectDataNo(p, index);
            if(no == 0){
                printf("=> 취소됨!");
                continue;
            }
            int del = 0;
            printf("정말로 삭제하시겠습니까?(삭제 : 1)");
            scanf(" %d", &del);
            if(del == 1){
                if(deleteProduct(&p[no-1])) {
                    printf("=> 삭제됨!\n");
                    count --;
		}
	    }
	}
	else if(menu == 5){
		saveData(p, index);
	}
	else if(menu == 6){
		int search = 0;
		printf("1. 이름, 2. 가격, 3. 별점");
		scanf(" %d", search);
		if(search == 1) searchProduct(p, index);
		if(search == 2) searchPrice(p, index);
		if(search == 3) searchPoint(p, index);
	}
    }
    printf("종료됨!\n");
    return 0;
}
