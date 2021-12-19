#include <stdio.h>
#include <stdlib.h>

struct emp{
    int sn;
    double GPA[5];
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

char titletaker(char *title){
    char tf[20];
    char tu[25];
    printf("Enter title file(without .txt) name: ");
    gets(tf);
    tf[strcspn(tf, "\r\n")] = 0;
    sprintf(tu,"%s.txt",tf);
    FILE *fp2=fopen(tu,"r");
    const size_t line_size = 300;
    char* line = malloc(line_size);
    while (fgets(line, line_size, fp2) != NULL){
        strcpy(title, line);
        }
    free(line);
    fclose(fp2);
    return title;
}
int lcount(char *fu){
    FILE *fp5=fopen(fu,"r");
    int tl;
    char line3[80] = {0};
    while (fgets(line3, 80, fp5))
    {
        ++tl;
    }
    fclose(fp5);
    return tl;
}
int gpataker(char *line2, int line_count2, struct emp *no, int nl){
    char a[100];
    int i=0,n=0;
    double d[5];
    char temp[100];
    int l2=0;
    strcpy(temp,line2);
    while(temp[i]!='\n'){
        if(temp[i]!=' '){
            a[n]=temp[i];
            n++;
        }
        else{
            sscanf(a, "%lf", &no[line_count2].GPA[l2]);
            strcpy(a,"");
            n=0;
            l2=l2+1;
            nl=nl+1;
        }
        i++;
    }
    return nl;
}

void htmlmaker(struct emp *no,int l,int *a,int nl,char *title){
    for(int i=0;i<l;i++){
            a[i]=0;
        for(int j=0;j<5;j++){
            if((int)(no[i].GPA[j])!=0){
                a[i]=a[i]+1;
            }
        }
    }
    FILE *out=fopen("Generated2.html","w");
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
        for(int j=0;j<a[i];j++){
            fprintf(out,"<td>%.2lf</td>\n",no[i].GPA[j]);
            totG=totG+no[i].GPA[j];
        }
        fprintf(out,"</tr>\n");
    }
    fprintf(out,"</table>\n");
    double avgpa=totG/nl;
    fprintf(out,"<br><center>Average GPA=%.3lf</center>",avgpa);
    fprintf(out,"</body>\n");
    fprintf(out,"</html>\n");
    fclose(out);
}

int main()
{
    char title[50];
    titletaker(&title);
    char fi[20];
    printf("enter your data file(without .txt) name: ");
    gets(fi);
    char fu[25];
    sprintf(fu,"%s.txt",fi);
    int tl= lcount(&fu);
    FILE *fp=fopen(fu,"r");
    struct emp no[tl/5];
    char line2[80] = {0};
    unsigned int line_count = 0;
    unsigned int line_count2 = 0;
    int l;
    int nl=0;
    while (fgets(line2, 80, fp))
    {
        ++line_count;
        if((line_count)%5 == 1)
            strcpy(no[line_count2].fn, line2);
        else if((line_count)%5 == 2)
            strcpy(no[line_count2].ln, line2);
        else if((line_count)%5 == 3)
            sscanf(line2, "%d", &no[line_count2].sn);
        else if((line_count)%5 == 4)
            strcpy(no[line_count2].email, line2);
        else if((line_count)%5 == 0){
            nl=gpataker(&line2,line_count2,&no,nl);
            ++line_count2;
            }
        l=line_count2;
    }
    int a[l];
    htmlmaker(&no,l,a,nl,&title);
    return 0;
}
