#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
            char pt[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
            char ct[26]={'Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M','L','K','J','I','H','G','F','E','D','C','B','A'};
            char p[20]={'\0'},c[20]={'\0'},r[20]={'\0'};
            int i,j;
            printf("\n enter the plain text:");
            gets(p);
            //converting plain text into cipher text (encryption)
            for(i=0;i<strlen(p);i++)
            {
                        for(j=0;j<26;j++)
                        {
                        if(pt[j]==p[i])
                        {
                                    c[i]=ct[j];
                        }
                        }
            }
            printf("\n cipher text is: %s",c);

            //converting cipher text into plain text (decryption)
            for(i=0;i<strlen(c);i++)
            {
                        for(j=0;j<26;j++)
                        {
                        if(ct[j]==c[i])
                        {
                                    r[i]=pt[j];
                        }
                        }
            }
            printf("\n \n plain text is: %s",r);
            getch();
}
