/*
2026FA-ENGR-2304-3-AZAK-ISMAIL-P02
*/
#include <stdio.h>
#include <string.h>

void decBin(){
 int n,m;
 printf("Enter decimal (-127 to 127): "); scanf("%d",&n);
 if(n<-127||n>127){printf("Invalid range.\n");return;}
 m=n<0?-n:n;
 printf("8-bit signed magnitude: %d",n<0);
 for(int i=6;i>=0;i--) printf("%d",(m>>i)&1);
 printf("\n");
}

void binDec(){
 char b[20]; int v=0;
 printf("Enter 8-bit signed magnitude binary: "); scanf("%19s",b);
 if(strlen(b)!=8){printf("Enter exactly 8 bits.\n");return;}
 for(int i=0;i<8;i++) if(b[i]!='0'&&b[i]!='1'){printf("Invalid binary number.\n");return;}
 for(int i=1;i<8;i++) v=v*2+b[i]-'0';
 printf("Decimal: %d\n",b[0]=='1'?-v:v);
}

int hv(char c){
 if(c>='0'&&c<='9')return c-'0';
 if(c>='A'&&c<='F')return c-'A'+10;
 if(c>='a'&&c<='f')return c-'a'+10;
 return -1;
}

void binHex(char *b){
 char h[]="0123456789ABCDEF",*p=strchr(b,'.');
 int l=p?(int)(p-b):(int)strlen(b),r=p?(int)strlen(p+1):0;
 if(l>32||r>32||l+r>64){printf("Binary input is too long.\n");return;}
 for(int i=0;b[i];i++)if(b[i]!='0'&&b[i]!='1'&&b[i]!='.'){printf("Invalid binary number.\n");return;}
 printf("Hexadecimal: 0x");
 int pad=(4-l%4)%4;
 for(int i=-pad;i<l;i+=4){
  int v=0;
  for(int j=0;j<4;j++){int x=i+j;v=v*2+(x<0?0:b[x]-'0');}
  printf("%c",h[v]);
 }
 if(r){
  printf(".");
  for(int g=0;g<(r+3)/4;g++){
   int v=0;
   for(int j=0;j<4;j++){int x=g*4+j;v=v*2+(x<r?p[1+x]-'0':0);}
   printf("%c",h[v]);
  }
 }
 printf("\n");
}

void hexBin(char *s){
 char *p=s+2,*q=strchr(p,'.'); int l=q?(int)(q-p):(int)strlen(p),r=q?(int)strlen(q+1):0;
 if(l>8||r>8||l+r>16){printf("Hex input is too long.\n");return;}
 for(int i=0;p[i];i++)if(p[i]!='.'&&hv(p[i])<0){printf("Invalid hexadecimal number.\n");return;}
 printf("Binary: ");
 for(int i=0;i<l;i++){int v=hv(p[i]);for(int bit=3;bit>=0;bit--)printf("%d",(v>>bit)&1);}
 if(r){
  printf(".");
  for(int i=0;i<r;i++){int v=hv(q[1+i]);for(int bit=3;bit>=0;bit--)printf("%d",(v>>bit)&1);}
 }
 printf("\n");
}

void option2(){
 char s[80];
 printf("Enter binary or hexadecimal (hex starts with 0x): ");scanf("%79s",s);
 if(s[0]=='0'&&(s[1]=='x'||s[1]=='X'))hexBin(s);else binHex(s);
}

int main(){
 int c,s;
 while(1){
  printf("\n===== NUMBER CONVERSION MENU =====\n1. Decimal <-> Binary\n2. Binary <-> Hexadecimal\n3. Exit\nChoice: ");
  if(scanf("%d",&c)!=1)break;
  if(c==1){
   printf("\n1. Decimal to Binary\n2. Binary to Decimal\nChoice: ");scanf("%d",&s);
   if(s==1)decBin();else if(s==2)binDec();else printf("Invalid choice.\n");
  }else if(c==2)option2();
  else if(c==3){printf("Program exited.\n");break;}
  else printf("Invalid choice.\n");
 }
 return 0;
}