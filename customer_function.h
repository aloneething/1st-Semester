# ifndef CUSTOMER_FUNCTION_H
# define CUSTOMER_FUNCTION_H
# include "all_customer_functions.cpp"

void bubbleSort (char name[][20], int items[], int price[], int n);
void order (char name[][20], int items[], int price[], int i, int &bill);
void order_online (char name[][20], int items[], int price[], int i, int &bill);
void customer_order ();
void online_order_customer ();
void search_all_c ();
void noti_c ();

# endif
