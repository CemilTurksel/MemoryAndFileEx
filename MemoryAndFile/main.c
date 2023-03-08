#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    int *ptr;
    printf("Enter n value:\n");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));
    srand(time(NULL));
    for(int i=0;i<n;i++){
        *(ptr+i)=rand()%100;
    }
    printf("The randomly generated numbers:\n");
    for(int i=0;i<n;i++){
        printf("%d\t",*(ptr+i));
    }
    FILE *file;
    file=fopen("numbers.txt","w");
    if(file==NULL){
        perror("Error creating");
        return -1;
    }
    else{
        for(int i=0;i<n;i++){
            fprintf(file,"%d ",*(ptr+i));
        }
        fclose(file);
        file=fopen("numbers.txt","r");
        int a=0;
        printf("\n");
        fscanf(file,"%d",&a);
        if(a!=EOF){
           printf("Numbers read from file:\n");
           do{
                printf("%d\t",a);
                fscanf(file,"%d",&a);
            }while(!feof(file));
            fclose(file);
            free(ptr);
        }
    }
    return 0;
}
