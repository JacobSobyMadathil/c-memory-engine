#include <stdio.h>

struct Product{
        int Product_ID;
        int stock[3];
    };

int Total_Stock (struct Product x){
    int sum = 0;
    for (int i = 0; i < 3; i ++){
        sum += x.stock[i];
    }
    return sum;
}

int Highest_Branch (struct Product x){
    int high = 0;
    for (int i = 1; i < 3; i ++){
        if (x.stock[i] > x.stock[high]){
            high = i;
        }
    }
    return (high + 1);
}

int Highest_Stock (struct Product x[], int N){
    int high = x[0].Product_ID, sum = 0;
    for (int i = 0; i < N; i ++){
        if (Total_Stock (x[i]) > sum){
            sum = Total_Stock (x[i]);
            high = x[i].Product_ID;
        }
        else if (Total_Stock (x[i]) == sum){
            if (high > x[i].Product_ID){
                high = x[i].Product_ID;
            }
        }
    }
    return high;
}

int main()
{
    int N, selected, index;
    scanf("%d", &N);
    struct Product Product_Records[N];
    
    for (int i = 0; i < N; i ++){
        scanf("%d", &Product_Records[i].Product_ID);
        for (int j = 0; j < 3; j ++){
            scanf("%d", &Product_Records[i].stock[j]);
        }
    }
    
    selected = Highest_Stock (Product_Records, N);
    for (int i = 0; i < N; i ++){
        if (Product_Records[i].Product_ID == selected){
            index = i;
            break;
        }
    }
    
    printf("%d %d %d", selected, Total_Stock (Product_Records[index]), Highest_Branch (Product_Records[index]));
    return 0;
}