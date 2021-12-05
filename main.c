#include <stdio.h>
#include <stdlib.h>

struct emp{
    int sn;
    double GPA;
    char fn[20];
    char ln[20];
    char email[20];
};
void remove_spaces(char* s) {
    char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}
int main()
{
    char fi[20];
    char tf[20];
    char tu[25];
    printf("Enter title file(without .txt) name: ");
    gets(tf);
    tf[strcspn(tf, "\r\n")] = 0;
    sprintf(tu,"%s.txt",tf);
    char title[50];
    FILE *fp2=fopen(tu,"r");
    const size_t line_size = 300;
    char* line = malloc(line_size);
    while (fgets(line, line_size, fp2) != NULL){
        strcpy(title, line);
        }
    printf("enter your file(without .txt) name: ");
    gets(fi);
    char fu[25];
    sprintf(fu,"%s.txt",fi);
    struct emp no[20];
    FILE *fp=fopen(fu,"r");
    char ch;
    char s[100];
    int count=0;
    int t=1;
    int t2=1;
    int c2=0;
    ch=fgetc(fp);
    while(ch != EOF){
        s[count]=ch;
        ch=fgetc(fp);
        if(s[count]=='\n'){
            if(t%5==1){
                strcpy(no[t2].fn,s);
                remove_spaces(no[t2].fn);
                no[t2].fn[strcspn(no[t2].fn, "\r\n")] = 0;
            }
            else if(t%5==2){
                strcpy(no[t2].ln,s);
                remove_spaces(no[t2].ln);
                no[t2].ln[strcspn(no[t2].ln, "\r\n")] = 0;
            }
            else if(t%5==3){
                sscanf(s, "%d", &no[t2].sn);
            }
            else if(t%5==4){
                strcpy(no[t2].email,s);
                remove_spaces(no[t2].email);
                no[t2].email[strcspn(no[t2].email, "\r\n")] = 0;
            }
            else if(t%5==0){
                sscanf(s, "%lf", &no[t2].GPA);
                t2=t2+1;
            }
            t=t+1;
            for(int i=0;i<c2;i++){
                s[i]=' ';
            }
            count=count-1;
        }
        count++;
        c2=c2+1;
    }
    FILE *output=fopen("Generated.html","w");
    fprintf(output, "<!DOCTYPE>\n");
    fprintf(output,"<html>\n");
    fprintf(output,"<head>\n");
    fprintf(output,"<title>Html report generator</title>\n");
    fprintf(output,"<style>\n");
    fprintf(output,"\n");
    fprintf(output,"</style>\n");
    fprintf(output,"</head>\n");
    fprintf(output,"<body>\n");
    fprintf(output,"<h1>\n");
    fprintf(output,"<center>\n");
    fprintf(output,"Html report generator\n");
    fprintf(output,"<br>%s\n",title);
    fprintf(output,"</h1>\n");
    fprintf(output,"<table border=\"1\", width=\"800\" style=\"margin-left:auto;margin-right:auto;\">\n");
    fprintf(output,"<tr>\n");
    fprintf(output,"<th>No.</th>\n");
    fprintf(output,"<th>Serial Number</th>\n");
    fprintf(output,"<th>First Name</th>\n");
    fprintf(output,"<th>Last Name</th>\n");
    fprintf(output,"<th>Email Address</th>\n");
    fprintf(output,"<th>GPA</th>\n");
    fprintf(output,"</tr>\n");
    for(int i=1;i<t2;i++){
        fprintf(output,"<tr>\n");
        fprintf(output,"<td>%d</td>\n",i);
        fprintf(output,"<td>%d</td>\n",no[i].sn);
        fprintf(output,"<td>%s</td>\n",no[i].fn);
        fprintf(output,"<td>%s</td>\n",no[i].ln);
        fprintf(output,"<td>%s</td>\n",no[i].email);
        fprintf(output,"<td>%.2lf</td>\n",no[i].GPA);
        fprintf(output,"</tr>\n");
    }
    fprintf(output,"</table>\n");
    fprintf(output,"</center>\n");
    fprintf(output,"</body>\n");
    fprintf(output,"</html>\n");
    return 0;
}
