
int writeinFile(FILE *file, char *string) {

    if(file == NULL) {
        perror("Datei existiert nicht");
        return -1;
    }
    
    int anzahlZeichen = fprintf(file, "%s", string);
    
    
    
    
    fclose(file);
    
    return anzahlZeichen;
    
    
    
    



}



int main(){
    
    FILE *file = fopen("testfile.txt", "w");
     if(file == NULL) {
        perror("Datei existiert nicht");
        return -1;
    }
    char *myString = "Hello bruh!";
    
    int number = writeinFile(file, myString);
    
    printf("Number of chars written in the file: %d\n", number);
    return 0;

    







}
