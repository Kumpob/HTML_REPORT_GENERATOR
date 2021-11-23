#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *output=fopen("Generated.html","w");
    fprintf(output, "<!DOCTYPE>\n");
    fprintf(output,"<html>\n");
    fprintf(output,"<head>\n");
    fprintf(output,"<title>Html report generator</title>\n");
    fprintf(output,"<style>\n");
    fprintf(output,"img{float: left; margin-left:10px; margin-right:10px;}\n");
    fprintf(output,"</style>\n");
    fprintf(output,"</head>\n");
    fprintf(output,"<body>\n");
    fprintf(output,"<h1>\n");
    fprintf(output,"<center>\n");
    fprintf(output,"Hello World\n");
    fprintf(output,"</center>\n");
    fprintf(output,"</h1>\n");
    fprintf(output,"<a href=\"img1.jfif\" target=\"_blank\">\n");
    fprintf(output,"<img src=\"img1.jfif\" width=\"250\">\n");
    fprintf(output,"<p>\n");
    fprintf(output,"click!\n");
    fprintf(output,"</p>\n");
    fprintf(output,"</a>\n");
    fprintf(output,"<br><br><br><br><br><br><br>\n");
    fprintf(output,"</body>\n");
    fprintf(output,"</html>\n");
    return 0;
}
