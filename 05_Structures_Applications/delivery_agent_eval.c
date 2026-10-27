#include <stdio.h>
struct DeliveryAgent{
     int ID;
     int cdv[4];
     int ldv[4];
};

int dayScore (struct DeliveryAgent x, int day){
    return (x.cdv[day - 1] - 2 * x.ldv[day - 1]);
}

int overallScore (struct DeliveryAgent x){
    int score = 0;
    for (int i = 1; i < 5; i ++){
        score += dayScore(x, i);
    }
    return score;
}

int cdel (struct DeliveryAgent x){
    int cd = 0;
    for (int i = 0; i < 4; i ++){
        cd += x.cdv[i];
    }
    return cd;
}

int bestDay (struct DeliveryAgent x){
    int bday = 1;
    for (int i = 1; i < 5; i++){
        if (dayScore(x, bday) < dayScore(x, i)){
            bday = i;
        }
    }
    return bday;
}

int bestAgent (struct DeliveryAgent x[], int N){
    int bda = 0;
    for (int i = 0; i < N; i ++){
        if (overallScore(x[bda]) < overallScore(x[i])){
            bda = i;
        }
        else if (overallScore(x[bda]) == overallScore(x[i])){
            if (cdel(x[bda]) < cdel(x[i])){
                bda = i;
            }
            else if (cdel(x[bda]) == cdel(x[i])){
                if (x[bda].ID > x[i].ID){
                    bda = i;
                }
            }
        }
    }
    
    return x[bda].ID;
}


int main()
{
    int N;
    int best, index;
    scanf("%d", &N);
    struct DeliveryAgent agent[N];
    for (int i = 0; i < N; i ++){
        scanf("%d", &agent[i].ID);
        for (int j = 0; j < 4; j ++){
            scanf("%d", &agent[i].cdv[j]);
        }
        for (int j = 0; j < 4; j ++){
            scanf("%d", &agent[i].ldv[j]);
        }
    }
    
    best = bestAgent(agent, N);
    for (int i = 0; i < N; i ++){
        if (best == agent[i].ID){
            index = i;
            break;
        }
    }
    
    printf ("%d %d %d %d", best, overallScore(agent[index]), bestDay(agent[index]), cdel(agent[index]));
    return 0;
}