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
    FILE *fp=fopen(fu,"r");
    int tl;
    char tmp[50] = {0};
    fgets(tmp, 50, fp);
    tl = atoi(tmp);
    struct emp no[tl];
    char line2[80] = {0};
    unsigned int line_count = 0;
    unsigned int line_count2 = 0;
    int l;
    while (fgets(line2, 80, fp))
    {
        ++line_count;
        printf("%s",line2);
        if((line_count)%5 == 1)
            strcpy(no[line_count2].fn, line2);
        else if((line_count)%5 == 2)
            strcpy(no[line_count2].ln, line2);
        else if((line_count)%5 == 3)
            sscanf(line2, "%d", &no[line_count2].sn);
        else if((line_count)%5 == 4)
            strcpy(no[line_count2].email, line2);
        else if((line_count)%5 == 0){
            sscanf(line2, "%lf", &no[line_count2].GPA);
            ++line_count2;
            }
        l=line_count2;
    }
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
    for(int i=0;i<l;i++){
        fprintf(out,"<tr>\n");
        fprintf(out,"<td>%d</td>\n",i+1);
        fprintf(out,"<td>%d</td>\n",no[i].sn);
        fprintf(out,"<td>%s</td>\n",no[i].fn);
        fprintf(out,"<td>%s</td>\n",no[i].ln);
        fprintf(out,"<td><a href=\"mailto:%s\"target=\"_blank\">%s</a></td>\n",no[i].email,no[i].email);
        fprintf(out,"<td>%.2lf</td>\n",no[i].GPA);
        fprintf(out,"</tr>\n");
        totG=totG+no[i].GPA;
    }
    fprintf(out,"</table>\n");
    double avgpa=totG/(l);
    fprintf(out,"<br><center>Average GPA=%.2lf</center>",avgpa);
    fprintf(out,"</body>\n");
    fprintf(out,"</html>\n");
    fclose(out);
    return 0;
}
