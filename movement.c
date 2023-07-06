#include <stdio.h>

void fill_with_zeros(int vet[3][3]);\

void print_vet(int vet[3][3])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("%d ",  vet[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void calc_dif(int veto[3][3], int vetn[3][3], int vetr[3][3])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(veto[i][j] == vetn[i][j])
            {
                vetr[i][j] = 0;
            }
            else
            {
                vetr[i][j] = 1;
            }   
        }
    }
}

int define_movement(int vet[3][3])
{
    int m[11];
    int move = -1;
    for(int i=0; i<12; i++)
    {
        m[i] = 0;
    }

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(vet[i][j] == 1)
            {
                switch(i+j)
                {
                    case 0: // q1
                        m[0]++; m[3]++; m[6]++; m[8]++; m[10]++;
                        break;
                    case 1:
                        if(i == 0)  // b1
                        {
                            m[1]++; m[3]++; m[6]++; m[7]++; m[8]++; m[10]++;
                        }
                        else        // b2
                        {
                            m[0]++; m[4]++; m[6]++; m[8]++; m[9]++; m[10]++;
                        }
                        break;
                    case 2:
                        if(i == 0)  // q2
                        {
                            m[2]++; m[3]++; m[7]++; m[8]++; m[10]++;
                        }
                        else 
                        {
                            if(i == 1)  // c
                            {
                                m[1]++; m[4]++; m[6]++; m[7]++; m[8]++; m[9]++;
                            }
                            else        // q3
                            {
                                m[0]++; m[5]++; m[6]++; m[9]++; m[10]++;
                            }
                        }
                        break;
                    case 3:
                        if(i == 1)  // b3
                        {
                            m[2]++; m[4]++; m[7]++; m[8]++; m[9]++; m[10]++;
                        }
                        else        // b4
                        {
                            m[1]++; m[5]++; m[6]++; m[7]++; m[9]++; m[10]++;
                        }
                        break;
                    case 4:         // q4
                        m[2]++; m[5]++; m[7]++; m[9]++; m[10]++;
                        break;
                }
            }
        }
    }

    if(m[10] >= 7)
    {
        move = 10;
    }
    else
    {
        if(m[9] >= 5)
        {
            move = 9;
        }
        else
        {
            if(m[8] >= 5)
            {
                move = 8;
            }
            else
            {
                if(m[7] >= 5)
                {
                    move = 7;
                }
                else
                {
                    if(m[6] >= 5)
                    {
                        move = 6;
                    }
                    else
                    {
                        if(m[5] >= 2)
                        {
                            move = 5;
                        }
                        else
                        {
                            if(m[4] >= 2)
                            {
                                move = 4;
                            }
                            else
                            {
                                if(m[3] >= 2)
                                {
                                    move = 3;
                                }
                                else
                                {
                                    if(m[2] >= 2)
                                    {
                                        move = 2;
                                    }
                                    else
                                    {
                                        if(m[1] >= 2)
                                        {
                                            move = 1;
                                        }
                                        else
                                        {
                                            if(m[0] >= 2)
                                            {
                                                move = 0;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return move;
}

// Colors:
// 0 = White
// 1 = Yellow
// 2 = Blue
// 3 = Green
// 4 = Red
// 5 = Orange


int main() 
{
    int old[3][3], new[3][3], movement[3][3];

    fill_with_zeros(old);
    fill_with_zeros(new);
    fill_with_zeros(movement);

    old[0][0]=2; old[0][1]=3; old[0][2]=1;
    old[1][0]=2; old[1][1]=5; old[1][2]=1;
    old[2][0]=3; old[2][1]=1; old[2][2]=4;

    new[0][0]=2; new[0][1]=3; new[0][2]=1;
    new[1][0]=4; new[1][1]=2; new[1][2]=3;
    new[2][0]=3; new[2][1]=1; new[2][2]=4;

    print_vet(old);
    print_vet(new);

    calc_dif(old, new, movement);

    print_vet(movement);

    printf("Movimento: %d\n", define_movement(movement));



    return 0;
}

void fill_with_zeros(int vet[3][3])
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            vet[i][j] = 0;
        }
    }
}