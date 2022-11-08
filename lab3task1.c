#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


int bigger_power(int number, int power){
    if (number == 0){
        return 1;
    }
    int count = 0;
    while (number){
        number = number>>power;
        count++;
    }
    return count;
}

char* transfer(int number, int power) {
    int flag_minus = 0;
    if (number < 0){
        flag_minus = 1;
        number = -number;
    }
    int power_of_number = bigger_power(number, power);
    char* result = (char*)malloc((power_of_number+2)*sizeof(char));
    if (result == NULL) {
        return "False with malloc";
    }
    if (power < 1 || power > 5){
        return "False with condition";
    }
    char* ps = result + power_of_number + 1;
    *ps-- = '\0';
    int notation = 1<<power;
    if (number == 0){
        *(result+1) = '0';
        *result = '+';
        return result;
    } else {
        while (number){
            int rank = ((number)&(notation-1));
            *ps-- = rank > 9 ? 'A' + (rank - 10) : '0' + rank;
            number = number>>power;
        }
        if (flag_minus){
            *(ps) = '-';
        } else {
            *(ps) = '+';
        }
        return result;
    }
    
}


int main() {
    int number = -31;
    int power = 5;
    char* result = transfer(number, power);
    printf("%s", result);
    free(result);
    return 0;
}