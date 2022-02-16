    #include <stdio.h>
    #include <stdlib.h>
    #include <strings.h> // to use strncasecmp

    int DENOM [] = {50,20,10,5};
    char COIN [][20] = {"50 cents" , "20 cents" , "10 cents" , "5 cents"};
    int SIZE = 10;

    typedef struct person{

    char name[255];
    int coin;
    int x50Coin;
    int x20Coin;
    int x10Coin;
    int x5Coin;

    }person;

    void displayChange(int coinCount[]){

    for(int i=0; i<4;i++){
            if(coinCount[i] !=0){
                printf("%s = %d\n", COIN[i],coinCount[i]);

            }

    }
    }

    void countAndSaveChange(person lists[]){

            int coin50=0,coin20=0,coin10=0,coin5=0;
            int totalCoin;
            int i =0;

            for(i=0; i<SIZE;i++){

                totalCoin=lists[i].coin;
                coin50=0;coin20=0;coin10=0;coin5=0;  // reset coin count
                if (totalCoin>=50){
                    coin50=totalCoin/50;
                    totalCoin=totalCoin-(coin50*50);

                }

                 if (totalCoin>=20){
                    coin20=totalCoin/20;
                    totalCoin=totalCoin-(coin20*20);

                }

                 if (totalCoin>=10){
                    coin10=totalCoin/10;
                    totalCoin=totalCoin-(coin10*10);

                }

                 if (totalCoin>=5){
                    coin5=totalCoin/5;
                    totalCoin=totalCoin-(coin5*5);

                }

                lists[i].x50Coin=coin50;
                lists[i].x20Coin=coin20;
                lists[i].x10Coin=coin10;
                lists[i].x5Coin=coin5;

            }

    }


    int getDenom(int coinCount [] , int totalCoin){

    for(int i=0; i<4;i++){

        while(totalCoin>0)
        {
            if (totalCoin>=DENOM[i]){

                totalCoin=totalCoin-DENOM[i];
                coinCount[i]++;

            }

            else{
                break;
            }
        }
    }
    return coinCount;


    }


    /* change(int coinCount [], int length) // reset the coinCount array so the coin counting does not stack
    {

        for (int i = 0 ; i < length ; i++)
            coinCount[i] = 0;
    }*/

    void saveCSV(person lists[]){

         char bufferOut[300];
                FILE* output;
                output = fopen ("change.csv", "w");

                if(output == NULL){
                    return 1;
                }

                  printf("Saving the below to change.csv\n");

                  for(int i=0 ; i<SIZE; i++){


                    countAndSaveChange(lists);
                    printf("%s,%d,%d,%d,%d,%d\n", lists[i].name, lists[i].coin, lists[i].x50Coin,lists[i].x20Coin,lists[i].x10Coin,lists[i].x5Coin);
                    fprintf(output, "%s,%d,%d,%d,%d,%d\n", lists[i].name, lists[i].coin, lists[i].x50Coin,lists[i].x20Coin,lists[i].x10Coin,lists[i].x5Coin);

                  }
                printf("Exiting program, Goodbye");
                fclose(output);
    }


    void searchName(person lists[]){

    int coinCount [] = {0,0,0,0};
            char name [20];
            int boolean = 0;
            printf("Enter name to be searched\n");
            scanf("%s" , &name);


            for (int i = 0; i<10; i++){



                if(strncasecmp(lists[i].name,name,10) == 0){ // comparing string ignoring case sensitivity
                    boolean = 1;
                    printf("Customer:\n");
                    printf("%s %d cents\n", lists[i].name,lists[i].coin);
                    printf("Change:\n");
                    getDenom(coinCount,lists[i].coin);
                    displayChange(coinCount);

                      break;
                }
            }

                if (boolean == 0){

                    printf("Name:%s\n", name);
                    printf("Not found\n");


    }
    }


    int main()
    {

        printf("HELLO GITHUB");
        //Reading from txt file
        FILE *infile; // create file reference, "infile" in this case
        person p;

        infile = fopen ("coins.txt", "r");

        if(infile == NULL){
            return 1;
        }

        char line [500];   // create char for each line read
        fgets(line,500,infile); //reading data from text file

        person lists[200]; // create array of struct
        int i =0;

        while(!feof(infile)){ //loop till end of file, while (!not at end of file) loop continue
            person *p = lists +i;

            sscanf(line, "%s %d" , &p->name,&p->coin); // taking input from the string "line"
            /*printf("%s %d\n", p->name,p->coin);*/ // checking input
            fgets(line,500,infile); //reading data from text file
            i++;
        }

        //display array for reference

        printf("Displaying data from txt file as below\n");

       for(i=0 ; i<SIZE; i++)
        {
            printf("Name: %s Coin: %d\n", lists[i].name, lists[i].coin);

        }


        fclose(infile);

        int choice;

        while(1){


        printf("1. Enter Name\n");
        printf("2. Exit\n");

        scanf("%d", &choice);

        if(choice>2){
            printf("Invalid option, try again\n");
        }

        switch(choice){

        case 1:;

            searchName(lists);
            break;

            case 2:;

            saveCSV(lists);
            exit(0);


        }
        }
        return 0;

    }
