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

void search_with_units(int mass[], int k, int l, int* result, int* length){
    if (l < 0 || k < 1 || l > k) {
        printf("Wrong input\n");
    }
    /*if (result == NULL) {
        //some exit
    }*/
    int count = 0;
    int flag = 1;
    int j = 0;
    for (int i = 0; i<SIZE; i++){
        if (check_number_k(mass[i], k)) {
            if (check_number_l(mass[i], flag, l)) {
                printf("%d ", mass[i]);
                result[j++] = mass[i];
                (*length)++;
            }
        }
    }
    result = (int*)realloc(result, *length);
}

void search_with_unitsrow(int mass[], int k, int l, int* result, int* length){
    if (l < 0 || k < 1 || l > k) {
        printf("Wrong input\n");
    }
    /*if (result == NULL) {
        //some exit
    }*/
    int count = 0;
    int flag = 2;
    int j = 0;
    for (int i = 0; i<SIZE; i++){
        if (check_number_k(mass[i], k)) {
            if (check_number_l(mass[i], flag, l)) {
                result[j++] = mass[i];
                (*length)++;
            }
        }
    }
    result = (int*)realloc(result, *length);
}


int main()
{
    int mass[SIZE] = {6, 2, 0, -24, 7, 13, 27, 24};
    int* result = malloc(sizeof(int) * SIZE);
    int* length = malloc(sizeof(int));
    search_with_unitsrow(mass, 6, 2, result, length);
    printf("%d %d\n", result[1], *length);
    free(result);
    free(length);
    return 0;
}
