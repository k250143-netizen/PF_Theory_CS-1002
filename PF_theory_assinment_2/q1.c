#include <stdio.h>

#define LEN 100

void add_book(int *idx, int isbns[], char titles[LEN][50], float prices[100],
              int quantities[100]) {

  if (*idx >= 100) {
    printf("Max data storage limit reached\n");
    return;
  }

  int i = *idx;
  int isbns_num;
  printf("Enter book's ISBN: ");
  scanf("%d", &isbns_num);

  for (int j = 0; j < *idx; j++) {
    if (isbns_num == isbns[j]) {
      printf("Duplicate ISBN found! Duplicate ISBNs are not allowed.\n");
      return;
    }
  }

  isbns[i] = isbns_num;

  while (getchar() != '\n')
    ;
  printf("Enter book's title: ");
  scanf("%[^\n]s", titles[i]);
  printf("Enter book's price: ");
  scanf("%f", &prices[i]);
  printf("Enter book's quantities: ");
  scanf("%d", &quantities[i]);

  *idx += 1;
  printf("Book added successfully.\n");
}

void process_sale(int idx, int isbns[], int quantities[]) {
  int isbns_num, copies_sold;
  printf("Enter ISBN of the book: ");
  scanf("%d", &isbns_num);

  int i, found = 0;

  for (i = 0; i < idx; i++) {
    if (isbns_num == isbns[i]) {
      found = 1;
      break;
    }
  }

  if (!found) {
    printf("No book record found with the following ISBN: %d\n", isbns_num);
    return;
  }

  printf("Enter number of copies sold: ");
  scanf("%d", &copies_sold);

  if (quantities[i] < copies_sold) {
    printf("Not enough books in stock! Only %d book(s) available.\n",
           quantities[i]);
    return;
  }

  quantities[i] -= copies_sold;
  printf("Sale processed. Remaining quantity: %d\n", quantities[i]);
}

void low_stock_report(int idx, int isbns[], char titles[LEN][50],
                      float prices[], int quantities[]) {
  printf("\n--- Low Stock Report (less than 5 copies) ---\n");
  printf("%-10s \t %-50s \t %10s \t %10s\n", "ISBN", "Title", "Price",
         "Quantity");
  printf("---------------------------------------------------------------------"
         "----------------------\n");

  int found_low_stock = 0;

  for (int i = 0; i < idx; i++) {

    if (quantities[i] < 5) {
      printf("%-10d \t %-50s \t %10.2f \t %10d\n", isbns[i], titles[i],
             prices[i], quantities[i]);
      found_low_stock = 1;
    }
  }

  if (!found_low_stock) {
    printf("No books are currently low on stock.\n");
  }
  printf("---------------------------------------------------------------------"
         "----------------------\n");
}

int main() {

  int isbns[LEN] = {0};
  char titles[LEN][50];
  float prices[LEN] = {0};
  int quantities[LEN] = {0};
  int idx = 0;

  while (1) {
    int choice;
    printf("\n===Welcome to Liberty Books Management System===\n");
    printf("---Main Menu---\n");
    printf("[1]. Add a new book \n[2]. Process a sale \n[3]. Generate low "
           "stock report \n[4]. Exit\n");
    printf("Enter your choice: ");

    if (scanf("%d", &choice) != 1) {
      printf("Invalid input! Please enter a number.\n");

      while (getchar() != '\n')
        ;
      continue;
    }

    switch (choice) {
    case 1:
      add_book(&idx, isbns, titles, prices, quantities);
      break;
    case 2:
      process_sale(idx, isbns, quantities);
      break;
    case 3:
      low_stock_report(idx, isbns, titles, prices, quantities);
      break;
    case 4:
      printf("Thank you for using the application\n");
      return 0;
    default:
      printf("Invalid choice! Please try again.\n");
      break;
    }
  }

  return 0;
}
