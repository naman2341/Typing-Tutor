#define FILEREADSIZE 5000
void createcontent();
void inittyping();
void createbuffer(char * inptr);
void processstatistics();
void matchwordinbuffer(char * token);
void readfile();
int istokeninbuffer(char *inptr,int bufferlength);
