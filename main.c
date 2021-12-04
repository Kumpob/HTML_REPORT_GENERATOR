#include <stdio.h>
#include <stdlib.h>

struct emp{
    char fn[20];
    char ln[20];
    int sn;
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
            int size = strlen(s);
            s[size-1] = '\0';
            if(t%3==1){
                strcpy(no[t2].fn,s);
            }
            else if(t%3==2){
                strcpy(no[t2].ln,s);
                remove_spaces(no[t2].ln);

            }
            else if(t%3==0){
                sscanf(s, "%d", &no[t2].sn);
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
    fprintf(output,"table, td, th{border: 1px solid black}\n");
    fprintf(output,"</style>\n");
    fprintf(output,"</head>\n");
    fprintf(output,"<body>\n");
    fprintf(output,"<h1>\n");
    fprintf(output,"<center>\n");
    fprintf(output,"Html report generator\n");
    fprintf(output,"Employee List\n");
    fprintf(output,"</center>\n");
    fprintf(output,"<table >\n");
    fprintf(output,"<tr>\n");
    fprintf(output,"<th>Serial Number</th>\n");
    fprintf(output,"<th>First Name</th>\n");
    fprintf(output,"<th>Last Name</th>\n");
    fprintf(output,"</tr>\n");
    for(int i=1;i<t2;i++){
        fprintf(output,"<tr>\n");
        fprintf(output,"<td>%d</td>\n",no[i].sn);
        fprintf(output,"<td>%s</td>\n",no[i].fn);
        fprintf(output,"<td>%s</td>\n",no[i].ln);
        fprintf(output,"</tr>\n");
    }
    fprintf(output,"</table>\n");
    fprintf(output,"</h1>\n");
    fprintf(output,"</body>\n");
    fprintf(output,"</html>\n");
    return 0;
}
