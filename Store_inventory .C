#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
pid_t pidClothes,pidFood,pidMale,pidFeMale,pidVeg,pidFruit;

printf("Store process %d\n",getpid());
//Clothes Node and its Children

pidClothes=fork();
if(pidClothes<0){ 
fprintf(stderr,"Fork Failed"); 
return 1;}
else if (pidClothes==0){ 
//
pidMale=fork();
if(pidMale<0){ 
fprintf(stderr,"Fork Failed");
 return 1;}
else if(pidMale==0){ printf("No child of Male\n");  }

else{ 
printf("pidMale process %d\n",getpid());
//  process for male clothes
        int shirt, jeans;
        printf("Enter the quantity of shirt for male: ");
        scanf("%d", &shirt);
        printf("Enter the quantity of jeans for male: ");
        scanf("%d", &jeans);
        // create and write to file
        //
    	char file_name[50];
    	sprintf(file_name, "Male .txt");
    
  	 int fd = open(file_name, O_RDWR | O_CREAT | O_APPEND ,0644);
          if (fd < 0) {
            perror("Failed");
            exit(1);
        }

	char data[100];
        sprintf(data, "shirt: %d\njeans: %d", shirt, jeans);
        int sz = write(fd, data, strlen(data));

        printf("Male Clothes data saved to file%s\n=%s\n", file_name, data);
   close(fd);
        //

wait(NULL);
//
pidFeMale=fork();
if(pidFeMale<0){ 
fprintf(stderr,"Fork Failed"); 
return 1;}
else if(pidFeMale==0){
 printf("No child of F\n"); }
else{ printf("pidFeMale process %d\n",getpid());  
 
        //  process for female clothes
        int shirt, jeans;
        printf("Enter the quantity of shirt for female: ");
        scanf("%d", &shirt);
        printf("Enter the quantity of jeans for female: ");
        scanf("%d", &jeans);
        // create and write to file
        char file_name[50];
    	sprintf(file_name, "FeMale .txt");
    
  	 int fd = open(file_name, O_RDWR | O_CREAT | O_APPEND ,0644);
          if (fd < 0) {
            perror("Failed");
            exit(1);
        }

	char data[100];
        sprintf(data, "shirt: %d\njeans: %d", shirt, jeans);
        int sz = write(fd, data, strlen(data));

        printf("FeMale Clothes data saved to file%s\n=%s\n", file_name, data);
   close(fd);
} 

return 0;
}
else
{
printf("Clothes process %d\n",getpid());
wait(NULL);

}


// Food Node and its Children
pidFood=fork();
if(pidFood<0)
{
fprintf(stderr,"Fork Failed");
return 1;
}
else if (pidFood==0)
{
pidVeg=fork();
if(pidVeg<0){ 
fprintf(stderr,"Fork Failed"); 
return 1;}
else if(pidVeg==0){ 
printf("No pidVeg Child\n");  }
else{ 
printf("pidVeg process %d\n",getpid());
 //  process for veg
        int potato, tomato;
        printf("Enter the quantity of potato: ");
        scanf("%d", &potato);
        printf("Enter the quantity of tomato: ");
        scanf("%d", &tomato);
        // create and write to file
        char file_name[50];
    	sprintf(file_name, "Veg .txt");
    
   	int fd = open(file_name, O_RDWR | O_CREAT | O_APPEND ,0644);
          if (fd < 0) {
            perror("Failed");
            exit(1);
        }

	char data[100];
        sprintf(data, "potato: %d\ntomato: %d", potato, tomato);
        int sz = write(fd, data, strlen(data));

        printf("Veg data saved to file%s\n=%s\n", file_name, data);
   	close(fd);

wait(NULL);
//
pidFruit=fork();
if(pidFruit<0){ 
fprintf(stderr,"Fork Failed"); 
return 1;}
else if(pidFruit==0){
 printf("No child of Fruit\n"); }
else{ printf("pidFruit process %d\n",getpid());  
// process for fruit
        int apple, banana;
        printf("Enter the quantity of apple: ");
        scanf("%d", &apple);
        printf("Enter the quantity of banana: ");
        scanf("%d", &banana);
        // create and write to file
        char file_name[50];
   	 sprintf(file_name, "Fruit .txt");
    
   	int fd = open(file_name, O_RDWR | O_CREAT | O_APPEND ,0644);
          if (fd < 0) {
            perror("Failed");
            exit(1);
        }

	char data[100];
        sprintf(data,  "apple: %d\nbanana: %d", apple, banana);
        int sz = write(fd, data, strlen(data));

        printf("Fruit data saved to file%s\n=%s\n", file_name, data);
   close(fd);
wait(NULL);} }

return 0;
}
else
{
printf("Food process %d\n",getpid());
wait(NULL);
//printf("Child_C complete\n");
}
return 0;
}