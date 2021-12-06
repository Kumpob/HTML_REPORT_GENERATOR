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
    free(line);
    fclose(fp2);
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
    fclose(fp);
    FILE *out=fopen("Generated.html","w");
    fprintf(out, "<!DOCTYPE>\n");
    fprintf(out,"<html>\n");
    fprintf(out,"<head>\n");
    fprintf(out,"<title>Html report generator</title>\n");
    fprintf(out,"</head>\n");
    fprintf(out,"<body>\n");
    fprintf(out,"<h1>\n");
    fprintf(out,"<center>\n");
    fprintf(out,"Html report generator\n");
    fprintf(out,"<br>%s\n",title);
    fprintf(out,"</center>\n");
    fprintf(out,"</h1>\n");
    fprintf(out,"<table border=\"1\", width=\"800\" style=\"margin-left:auto;margin-right:auto;\">\n");
    fprintf(out,"<tr>\n");
    fprintf(out,"<th>No.</th>\n");
    fprintf(out,"<th>Serial Number</th>\n");
    fprintf(out,"<th>First Name</th>\n");
    fprintf(out,"<th>Last Name</th>\n");
    fprintf(out,"<th>Email Address</th>\n");
    fprintf(out,"<th>GPA</th>\n");
    fprintf(out,"</tr>\n");
    double totG;
    for(int i=1;i<t2;i++){
        fprintf(out,"<tr>\n");
        fprintf(out,"<td>%d</td>\n",i);
        fprintf(out,"<td>%d</td>\n",no[i].sn);
        fprintf(out,"<td>%s</td>\n",no[i].fn);
        fprintf(out,"<td>%s</td>\n",no[i].ln);
        fprintf(out,"<td><a href=\"mailto:%s\"target=\"_blank\">%s</a></td>\n",no[i].email,no[i].email);
        fprintf(out,"<td>%.2lf</td>\n",no[i].GPA);
        fprintf(out,"</tr>\n");
        totG=totG+no[i].GPA;
    }
    fprintf(out,"</table>\n");
    double avgpa=totG/(t2-1);
    fprintf(out,"<br><center>Average GPA=%.2lf</center>",avgpa);
    fprintf(out,"</body>\n");
    fprintf(out,"</html>\n");
    fclose(out);
    return 0;
}
