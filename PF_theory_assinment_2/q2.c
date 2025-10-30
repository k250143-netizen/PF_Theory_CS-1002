#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 5
#define PROMO_CODE "Eid2025"
#define DISCOUNT_RATE 0.25

int product_code[MAX_PRODUCTS] = {1, 2, 3, 4, 5};
float product_prices[MAX_PRODUCTS] = {220.0, 180.0, 350.0, 300.0, 750.0};
int product_stock[MAX_PRODUCTS] = {100, 150, 200, 80, 50};

int cart[MAX_PRODUCTS] = {0};

char customer_name[100] = "N/A";
char customer_cnic[20] = "N/A";

float total_bill = 0.0;
float discounted_bill = 0.0;
int discount_applied = 0;

void get_customer_info() {
  printf("\n--- Customer Information ---\n");
  printf("Enter Customer Name: ");
  scanf(" %[^\n]s", customer_name);

  printf("Enter Customer CNIC (e.g., 12345-6789012-3): ");
  scanf("%s", customer_cnic);

  printf("\nCustomer information updated successfully!\n");
}

void display_inventory() {
  printf("\n--- Current Inventory ---\n");
  printf("ID\tPrice\t\tStock\n");
  printf("\n");

  for (int i = 0; i < MAX_PRODUCTS; i++) {

    printf("%d\tRs. %-7.2f\t%d\n", product_code[i], product_prices[i],
           product_stock[i]);
  }
  printf("\n");
}

void add_item_to_cart() {
  int product_id, quantity;
  int choice;

  do {
    display_inventory();

    printf("\nEnter Product ID to add to cart (1-%d): ", MAX_PRODUCTS);
    if (scanf("%d", &product_id) != 1) {
      printf("Invalid input. Please enter a number.\n");
      while (getchar() != '\n')
        ;
      continue;
    }

    if (product_id < 1 || product_id > MAX_PRODUCTS) {
      printf("Error: Invalid Product ID. Please try again.\n");
      continue;
    }

    int index = product_id - 1;

    printf("Enter quantity for PRODUCT: %d: ", product_code[index]);
    if (scanf("%d", &quantity) != 1) {
      printf("Invalid input. Please enter a number.\n");
      while (getchar() != '\n')
        ;
      continue;
    }

    if (quantity <= 0) {
      printf("Error: Quantity must be greater than 0.\n");
    } else if (quantity > product_stock[index]) {
      printf("Error: Not enough stock! Only %d available.\n",
             product_stock[index]);
    } else {

      cart[index] += quantity;
      product_stock[index] -= quantity;
      printf("\n%d pieces of PRODUCT: %d added to cart.\n", quantity,
             product_code[index]);
    }

    printf("\nDo you want to add another item? (1/0): ");
    scanf(" %d", &choice);
    while (getchar() != '\n')
      ;

  } while (choice == 1);
}

void display_total_bill() {

  total_bill = 0.0;
  discounted_bill = 0.0;
  discount_applied = 0;
  char promo_input[50];
  int items_in_cart = 0;

  printf("\n---Checkout & Bill Calculation---\n");

  for (int i = 0; i < MAX_PRODUCTS; i++) {
    if (cart[i] > 0) {
      total_bill += (cart[i] * product_prices[i]);
      items_in_cart++;
    }
  }

  if (items_in_cart == 0) {
    printf("Your cart is empty. Please add items first.\n");
    return;
  }

  printf("Your total bill (before discount) is: Rs. %.2f\n", total_bill);

  printf("\nDo you have a voucher code? (1/0): ");
  int choice;
  scanf(" %d", &choice);

  if (choice == 1) {
    printf("Enter promo code: ");
    scanf("%s", promo_input);

    if (strcmp(promo_input, PROMO_CODE) == 0) {
      discounted_bill = total_bill * (1.0 - DISCOUNT_RATE);
      discount_applied = 1;
      printf("Success! '%s' applied. You get a 25%% discount.\n", PROMO_CODE);
    } else {
      printf("Invalid promo code. No discount applied.\n");
      discounted_bill = total_bill;
      discount_applied = 0;
    }
  } else {
    printf("No promo code entered.\n");
    discounted_bill = total_bill;
    discount_applied = 0;
  }

  printf("\n");
  printf("Your final amount to pay is: Rs. %.2f\n", discounted_bill);
}

void show_invoice() {
  printf("\n---FINAL INVOICE--- \n");

  printf("Customer Name: %s\n", customer_name);
  printf("Customer CNIC: %s\n", customer_cnic);

  if (total_bill == 0.0) {
    printf("\nNo items have been processed for checkout.\n");
    printf("Please 'Add Items to Cart' (Option 3) and 'Proceed to Checkout' "
           "(Option 4) first.\n");
    return;
  }

  printf("\nItems Purchased:\n");
  printf("\n");
  printf("%-15s\tQty\tUnit Price\tTotal\n", "Prdct Code");
  printf("\n");

  for (int i = 0; i < MAX_PRODUCTS; i++) {
    if (cart[i] > 0) {
      printf("%-15d\t%d\tRs. %-7.2f\tRs. %.2f\n", product_code[i], cart[i],
             product_prices[i], (cart[i] * product_prices[i]));
    }
  }
  printf("\n");

  printf("\nOriginal Total:\t\t\tRs. %.2f\n", total_bill);

  if (discount_applied) {
    float discount_amount = total_bill - discounted_bill;
    printf("Discount (%s -> 25%%):\t-Rs. %.2f\n", PROMO_CODE, discount_amount);
  } else {
    printf("Discount:\t\t\t-Rs. 0.00\n");
  }

  printf("---------------------------------------------------\n");
  printf("Final Bill (Paid):\t\tRs. %.2f\n", discounted_bill);
  printf("\nThank you for shopping with us!\n");
}

int main() {
  int choice;

  do {

    printf("\n---Supermarket Management System---\n");
    printf("[1]. Enter Customer Information\n");
    printf("[2]. Display Inventory\n");
    printf("[3]. Add Item to Cart\n");
    printf("[4]. Proceed to Checkout\n");
    printf("[5]. Show Final Invoice\n");
    printf("[6]. Exit\n");
    printf("Enter your choice (1-6): ");

    scanf("%d", &choice);
    while (getchar() != '\n')
      ;

    switch (choice) {
    case 1:
      get_customer_info();
      break;
    case 2:
      display_inventory();
      break;
    case 3:
      add_item_to_cart();
      break;
    case 4:
      display_total_bill();
      break;
    case 5:
      show_invoice();
      break;
    case 6:
      printf("\nExiting system.\n");
      break;
    default:
      printf("\nError: Invalid choice. Please select from 1-6.\n");
    }

  } while (choice != 6);

  return 0;
}
