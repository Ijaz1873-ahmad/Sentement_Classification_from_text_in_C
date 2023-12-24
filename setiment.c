//Name: Ijaz Ahmad

#include <stdio.h>
#include <ctype.h>
#include <string.h>
const int ESC = 27;
char *rtrim(char *str, const char *seps)
{
    int i;
    if (seps == NULL) {
        seps = "\t\n\v\f\r ";
    }
    i = strlen(str) - 1;
    while (i >= 0 && strchr(seps, str[i]) != NULL) {
        str[i] = '\0';
        i--;
    }
    return str;
}

char *ltrim(char *str, const char *seps)
{
    size_t totrim;
    if (seps == NULL) {
        seps = "\t\n\v\f\r ";
    }
    totrim = strspn(str, seps);
    if (totrim > 0) {
        size_t len = strlen(str);
        if (totrim == len) {
            str[0] = '\0';
        }
        else {
            memmove(str, str + totrim, len + 1 - totrim);
        }
    }
    return str;
}
char *trim(char *str, const char *seps)
{
    return ltrim(rtrim(str, seps), seps);
}
int main()
{
	int key = 0;
	char c ;
	do{
	char str[100];
	int nutwords = 0, poswords = 0, negwords = 0, stpwords = 0;

	char positivewords[2050], negativewords[4831];
	char stopwords[1000];

	FILE *st, *pw, *nw;

	printf("enter a review -- Press return to exit: \n");
	scanf("%[^\n]", str);
	key = str[0];
	if (key == 27) return 0;
	int len = strlen(str);
	for(int r=0;r<len;r++){
		if(str[r]=='.'||str[r]=='-'||str[r]==':'||str[r]==';'||str[r]==','||str[r]=='?'){
		str[r]=' ';
		}
		if(str[r] >= 'A' && str[r] <= 'Z'){
		str[r]=str[r]+32;
		}
	}
	
	char *pch;
	int length = strlen(str);
	

	pch = strtok(str, " ,.-");
	while (pch != NULL)
	{	
	st = fopen("stopwords.txt", "r");
	pw = fopen("positive-words.txt", "r");
	nw = fopen("negative-words.txt", "r");
	int flag = 0 ;
	for (int l = 0; l < 127; l++)
		{
		   fgets(stopwords, 127, st);
		   trim(pch,NULL); 
		   trim(stopwords,NULL);
		   if(strcmp(pch , stopwords) == 0){
			flag = 1;
			}
		}
		if(flag == 0){
		for (int k = 0; k < 2050; k++)
		{
			fgets(positivewords, 2050, pw);
			if (strcmp(pch, trim(positivewords,NULL)) == 0)
			{
				poswords++;
			}
		}
		for (int m = 0; m < 4831; m++)
		{
			fgets(negativewords, 4831, nw);
			if (strcmp(pch, trim(negativewords, NULL)) == 0)
			{
				negwords++;
			}
		
		}

		
		}
		
	pch = strtok(NULL, " ,.-");
	flag = 0;
	}
	//printf("Positive %d\n", poswords);
	//printf("Negative  %d\n", negwords);

	if (poswords > negwords)
	{
		printf("Positive Sentiment\n");
	}
	else if (negwords > poswords)
	{
		printf("Negative Sentiment\n");
	}
	else
	{
		printf("Neutral Sentiment\n");
	}

	fclose(st);
	fclose(pw);
	fclose(nw);
	printf("\n\n");
	scanf("%c",&c);
	
	}while(key != 27);
	
	
	return 0;
}
