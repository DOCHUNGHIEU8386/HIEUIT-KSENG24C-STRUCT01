#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float price;
} Dish;

Dish menu[100] = {
    {1, "Dau Phu Luot Van", 2000},
    {2, "Rong Xanh Vuot Bien", 2000},
    {3, "Trung Luoc Bong Dem", 2000},
    {4, "Hau Nuong Mo Hanh", 2000},
    {5, "Bun Dau Mam Tom", 200}
};

int n = 5;

void MenuFood() {
    printf("\nMENUFOOD\n");
    printf("1. In ra cac gia tri phan tu co trong menu mon an theo dang 1.member:value\n");
    printf("2. Them moi phan tu vao vi tri chi dinh\n");
    printf("3. Sua mot phan tu o vi tri chi dinh\n");
    printf("4. Xoa mot phan tu o vi tri chi dinh\n");
    printf("5. Sap xep cac phan tu\n");
    printf("6. Tim kiem phan tu theo name nhap vao\n");
    printf("7. Thoat\n");
    printf("Nhap lua chon cua ban: ");
}

int main() {
    int choice;

    do {
        MenuFood();
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("Chuc nang 1 duoc chon.\n");
                for (int i = 0; i < n; i++) {
                    printf("%d. ID: %d, Name: %s, Price: %.2f\n", i + 1, menu[i].id, menu[i].name, menu[i].price);
                }
                break;
            }
            case 2: {
                printf("Chuc nang 2 duoc chon.\n");
                int pos;
                Dish newDish;
                printf("Nhap vi tri can them: ");
                scanf("%d", &pos);
                printf("Nhap ID: ");
                scanf("%d", &newDish.id);
                printf("Nhap ten mon an: ");
                scanf("%s", newDish.name);
                printf("Nhap gia: ");
                scanf("%f", &newDish.price);
                if (pos < 1 || pos > n + 1) {
                    printf("Vi tri khong hop le\n");
                } else {
                    for (int i = n; i >= pos; i--) {
                        menu[i] = menu[i - 1];
                    }
                    menu[pos - 1] = newDish;
                    n++;
                    printf("Da them mon an moi vao vi tri %d\n", pos);
                }
                break;
            }
            case 3: {
                printf("Chuc nang 3 duoc chon.\n");
                int pos;
                Dish newDish;
                printf("Nhap vi tri can sua: ");
                scanf("%d", &pos);
                if (pos < 1 || pos > n) {
                    printf("Vi tri khong hop le\n");
                } else {
                    printf("Nhap ID moi: ");
                    scanf("%d", &newDish.id);
                    printf("Nhap ten mon an moi: ");
                    scanf("%s", newDish.name);
                    printf("Nhap gia moi: ");
                    scanf("%f", &newDish.price);
                    menu[pos - 1] = newDish;
                    printf("Da sua mon an o vi tri %d\n", pos);
                }
                break;
            }
            case 4: {
                printf("Chuc nang 4 duoc chon.\n");
                int pos;
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &pos);
                if (pos < 1 || pos > n) {
                    printf("Vi tri khong hop le\n");
                } else {
                    for (int i = pos - 1; i < n - 1; i++) {
                        menu[i] = menu[i + 1];
                    }
                    n--;
                    printf("Da xoa mon an o vi tri %d\n", pos);
                }
                break;
            }
            case 5: {
                printf("Chuc nang 5 duoc chon.\n");
                for (int i = 0; i < n - 1; i++) {
                    for (int j = i + 1; j < n; j++) {
                        if (menu[i].price > menu[j].price) {
                            Dish temp = menu[i];
                            menu[i] = menu[j];
                            menu[j] = temp;
                        }
                    }
                }
                printf("Sap Xep Theo Gia Tang Dan Thanh Cong!\n");
                break;
            }
            case 6: {
                printf("Chuc nang 6 duoc chon.\n");
                char name[50];
                printf("Nhap Ten Mon Can Tim: ");
                scanf("%s", name);
                for (int i = 0; i < n; i++) {
                    if (strcmp(menu[i].name, name) == 0) {
                        printf("Tim Thay Mon: %d. Ten Mon: %s - Gia Tien: %.2f\n", menu[i].id, menu[i].name, menu[i].price);
                        break;
                    }
                }
                break;
            }
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
                break;
        }
    } while (choice != 7);

    return 0;
}

