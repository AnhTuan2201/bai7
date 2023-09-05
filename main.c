#include <stdio.h>
#include <string.h>

// Định nghĩa cấu trúc dữ liệu để lưu trữ thông tin liên hệ
struct Contact {
    char name[100];
    char phone[15];
    char address[200];
};

// Hàm để thêm thông tin liên hệ mới vào tập tin danh bạ
void add_contact() {
    struct Contact contact;
    FILE *file = fopen("contacts.txt", "a");

    if (file == NULL) {
        printf("Không thể mở tập tin danh bạ.\n");
        return;
    }

    printf("Nhập tên: ");
    scanf("%s", contact.name);
    printf("Nhập số điện thoại: ");
    scanf("%s", contact.phone);
    printf("Nhập địa chỉ: ");
    scanf("%s", contact.address);

    fprintf(file, "%s,%s,%s\n", contact.name, contact.phone, contact.address);
    fclose(file);

    printf("Liên hệ được thêm thành công!\n");
}

// Hàm để hiển thị toàn bộ danh sách liên hệ từ tập tin
void display_contacts() {
    struct Contact contact;
    FILE *file = fopen("contacts.txt", "r");

    if (file == NULL) {
        printf("Danh bạ rỗng.\n");
        return;
    }

    printf("Danh bạ liên hệ:\n");
    int count = 1;
    while (fscanf(file, "%[^,],%[^,],%[^\n]\n", contact.name, contact.phone, contact.address) != EOF) {
        printf("%d. Name: %s\n   Phone: %s\n   Address: %s\n", count, contact.name, contact.phone, contact.address);
        count++;
    }

    fclose(file);
}

// Hàm để tìm kiếm thông tin liên hệ dựa trên tên
void search_contact() {
    char search_name[100];
    printf("Nhập tên để tìm kiếm: ");
    scanf("%s", search_name);

    struct Contact contact;
    FILE *file = fopen("contacts.txt", "r");

    if (file == NULL) {
        printf("Danh bạ rỗng.\n");
        return;
    }

    while (fscanf(file, "%[^,],%[^,],%[^\n]\n", contact.name, contact.phone, contact.address) != EOF) {
        if (strcmp(search_name, contact.name) == 0) {
            printf("Liên hệ được tìm thấy:\nName: %s\nPhone: %s\nAddress: %s\n", contact.name, contact.phone, contact.address);
            fclose(file);
            return;
        }
    }

    printf("Không tìm thấy liên hệ với tên '%s'.\n", search_name);
    fclose(file);
}

int main() {
    printf("Welcome to the Contact Manager!\n");

    while (1) {
        printf("1. Thêm một liên hệ mới\n");
        printf("2. Hiển thị toàn bộ danh sách liên hệ\n");
        printf("3. Tìm kiếm liên hệ\n");
        printf("4. Thoát\n");

        int choice;
        printf("Nhập lựa chọn của bạn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                display_contacts();
                break;
            case 3:
                search_contact();
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Lựa chọn không hợp lệ.\n");
        }
    }

    return 0;
}
