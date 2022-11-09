#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

int check_number_k(int x, int k){
    if (x < 0) {
        x = -x;
    }
    int length = 1<<(k+1);
    if (x >= 0 && x < length){
        return 1;
    } else {
        return 0;
    }
}

void print_mass(int* result, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", result[i]);
    }
}

void mass_right(int* result, int length, int index) {
    for (int i = length; i > index; i--) {
        result[i] = result[i-1];
    }
}

int check_number_l(int x, int flag, int l){
    int temp_flag = 0;
    if (x < 0) {
        temp_flag = 1;
        x = -x;
    }
    int count = 0;
    int temp = x;
    if (flag == 1) {
        while (x) {
            if (x & 1 == 1){
                count++;
            }
            x = x>>1;
            
        }
        if (count == l) {
            if (temp_flag){
                    return -temp;
                }
            return temp;
        } else {
            return 0;
        }
    } else if (flag == 2) {
        while (x) {
            if (x & 1 == 1){
                count++;
            } else {
                count = 0;
            }
            if (count == l && (((x>>1) & 1) == 0)){
                if (temp_flag){
                    return -temp;
                }
                return temp;
            }
            x = x>>1;
            
        }
        return 0;
    }
}

void search_with_units(int mass[], int k, int l, int* result, int* length, int* status_cod){
    if (l < 0 || k < 1 || l > k) {
        *status_cod = 1;
    }
    if (result == NULL) {
        *status_cod = 2;
    }
    int count = 0;
    int flag = 1;
    int j = 0;
    for (int i = 0; i<SIZE; i++){
        if (check_number_k(mass[i], k)) {
            if (check_number_l(mass[i], flag, l)) {
                j = 0;
                while (j < *length) {
                    if (mass[i] < result[j]) {
                        mass_right(result, *length, j);
                        result[j] = mass[i];
                        break;
                    }
                    j++;
                }
                if (j == *length) {
                    result[j] = mass[i];
                }
                (*length)++;
            }
        }
    }
    result = (int*)realloc(result, *length);
    if (result == NULL) {
        *status_cod = 3;
    }
    *status_cod = 0;
}

void search_with_unitsrow(int mass[], int k, int l, int* result, int* length, int* status_cod){
    if (l < 0 || k < 1 || l > k) {
        *status_cod = 1;
    }
    if (result == NULL) {
        *status_cod = 2;
    }
    int count = 0;
    int flag = 2;
    int j = 0;
    for (int i = 0; i<SIZE; i++){
        if (check_number_k(mass[i], k)) {
            if (check_number_l(mass[i], flag, l)) {
                j = 0;
                while (j < *length) {
                    if (mass[i] < result[j]) {
                        mass_right(result, *length, j);
                        result[j] = mass[i];
                        break;
                    }
                    j++;
                }
                if (j == *length) {
                    result[j] = mass[i];
                }
                (*length)++;
            }
        }
    }
    result = (int*)realloc(result, *length);
    if (result == NULL) {
        *status_cod = 3;
    }
    *status_cod = 0;
}


int main()
{
    int mass[SIZE] = {6, 2, 0, -24, 7, 13, 27, 24};
    int* result = malloc(sizeof(int) * SIZE);
    int* length = malloc(sizeof(int));
    int* status_cod = malloc(sizeof(int));
    int* result_1 = malloc(sizeof(int) * SIZE);
    int* length_1 = malloc(sizeof(int));
    int* status_cod_1 = malloc(sizeof(int));
    *status_cod = -1;
    *length = 0;
    *status_cod_1 = -1;
    *length_1 = 0;
    int k, l = 0;
    scanf("%d%d", &k, &l);
    search_with_units(mass, k, l, result, length, status_cod);
    search_with_unitsrow(mass, k, l, result_1, length_1, status_cod_1);
    if (*status_cod == 1) {
        printf("Wrong options");
    } else if (*status_cod == 2) {
        printf("Problem with memory");
    } else if (*status_cod == 3) {
        printf("problem with realloc in funtion");
    } else if (*status_cod == 0) {
        print_mass(result, *length);
        printf("\n%d\n", *length);    
    }
    if (*status_cod_1 == 1) {
        printf("Wrong options");
    } else if (*status_cod_1 == 2) {
        printf("Problem with memory");
    } else if (*status_cod_1 == 3) {
        printf("problem with realloc in funtion");
    } else if (*status_cod_1 == 0) {
        print_mass(result_1, *length_1);
        printf("\n%d\n", *length_1);    
    }
    free(result);
    free(length);
    free(status_cod);
    free(result_1);
    free(length_1);
    free(status_cod_1);
    return 0;
}
