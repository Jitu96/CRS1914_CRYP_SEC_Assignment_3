/* Program1:For Addition */


#include<stdio.h>
int main(){
  static int a[32],b[32],c[5],d[5],s[5];
  int len=0,len2=0,carry=0,len_var=0;
  char ch;
  
  //input of first number
  
  printf("enter a hex number (32 many charecters with first one 1-7 atmost):");
  scanf("%c",&ch);
  while(ch!='\n' && len<32){
    if(ch<=57 && ch>=48)
      a[len]=ch-48;
    if(ch == 'a' ||ch == 'b' || ch == 'c' || ch == 'd' || ch == 'e' || ch == 'f' )
      a[len]=ch-87;
    len++;
    scanf("%c",&ch);
    }
  
  len_var=len;
  
  for(int i=0;i<5;i++){
    for(int j=0;j<7;j++){
      if((len_var-7+j)<0)
        continue;
            
      c[i]=c[i]<<4;
      c[i]= c[i] + (a[(len_var-7+j)]&((1<<4)-1));      
      }
    len_var=len_var-7;     
    }

/*  for(int i=0;i<5;i++)	4 a 
    printf("%x  ",c[i]);
    printf("\n");
*/

  //input of 2nd number
  
  printf("enter another hex number (32 many charecters with first one 1-7 atmost):");
  scanf("%c",&ch);
  while(ch!='\n' && len2<32){
    if(ch<=57 && ch>=48)
      b[len2]=ch-48;
    if(ch == 'a' ||ch == 'b' || ch == 'c' || ch == 'd' || ch == 'e' || ch == 'f' )
      b[len2]=ch-87;
    len2++;
    scanf("%c",&ch);
    }
  
  
  len_var=len2;
  
  for(int i=0;i<5;i++){
    for(int j=0;j<7;j++){
      if((len_var-7+j)<0)
        continue;
            
      d[i]=d[i]<<4;
      d[i]= d[i] + (b[(len_var-7+j)]&((1<<4)-1));      
      }
    len_var=len_var-7;     
    }

    
    
  for(int i=0;i<4;i++){
    s[i]=((carry + c[i]+d[i])&((1<<28)-1));
    carry=(c[i]+d[i]+carry)>>28;
    }
    
  s[4]=((carry + c[4]+d[4])&((1<<15)-1));


  printf("\nsum: 0x%x",(s[4]&((1<<15)-1)));        
  for(int i=3;i>=0;i--)
    printf("%x",s[i]&((1<<28)-1));
    
  printf("\n");
    
    
  }



--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



/* Program2: For Subtraction */




#include<stdio.h>
int main(){
  static int a[32],b[32],c[5],d[5],d1[5],d2[5],s[5];
  int len=0,len2=0,carry=0,len_var=0;
  char ch;
  
  //input of first number
  
  printf("enter a hex number (32 many charecters with first one 1-7 atmost):");
  scanf("%c",&ch);
  while(ch!='\n' && len<32){
    if(ch<=57 && ch>=48)
      a[len]=ch-48;
    if(ch == 'a' ||ch == 'b' || ch == 'c' || ch == 'd' || ch == 'e' || ch == 'f' )
      a[len]=ch-87;
    len++;
    scanf("%c",&ch);
    }
  
  len_var=len;
  
  for(int i=0;i<5;i++){
    for(int j=0;j<7;j++){
      if((len_var-7+j)<0)
        continue;
            
      c[i]=c[i]<<4;
      c[i]= c[i] + (a[(len_var-7+j)]&((1<<4)-1));      
      }
    len_var=len_var-7;     
    }


  //input of 2nd number
  
  printf("enter another hex number (32 many charecters with first one 1-7 atmost):");
  scanf("%c",&ch);
  while(ch!='\n' && len2<32){
    if(ch<=57 && ch>=48)
      b[len2]=ch-48;
    if(ch == 'a' ||ch == 'b' || ch == 'c' || ch == 'd' || ch == 'e' || ch == 'f' )
      b[len2]=ch-87;
    len2++;
    scanf("%c",&ch);
    }
  
  
  len_var=len2;
  
  for(int i=0;i<5;i++){
    for(int j=0;j<7;j++){
      if((len_var-7+j)<0)
        continue;
            
      d[i]=d[i]<<4;
      d[i]= d[i] + (b[(len_var-7+j)]&((1<<4)-1));      
      }
    len_var=len_var-7;     
    }


//	doing 2's complement

  for(int i=0;i<4;i++)
    d1[i]=(~d[i])&((1<<28)-1);
  d1[4] = (~d[4])&((1<<16)-1);
      
  d2[0]=1;  

  for(int i=0;i<4;i++){
    d[i]=((carry + d1[i]+d2[i])&((1<<28)-1));
    carry=(d1[i]+d2[i])>>28;
    }
    
  d[4]=((carry + d1[4]+d2[4])&((1<<15)-1));


/*for(int i=0;i<5;i++)
    printf("%x  ",d[i]);
  printf("\n");*/



  carry=0;

//---------------------------------------------------------------------
    
    
  for(int i=0;i<4;i++){
    s[i]=((carry + c[i]+d[i])&((1<<28)-1));
    carry=(c[i]+d[i]+carry)>>28;
        printf("\n%d\n",carry);
    }
    
  s[4]=((carry + c[4]+d[4])&((1<<15)-1));
  carry=(c[4]+d[4]+carry)>>15;  
  
  if(carry==0){
      for(int i=0;i<4;i++)
        d1[i]=(~s[i])&((1<<28)-1);
      d1[4] = (~s[4])&((1<<16)-1);
      
      d2[0]=1;  d2[1]=d2[2]=d2[3]=d2[4]=0;  

      for(int i=0;i<4;i++){
        s[i]=((carry + d1[i]+d2[i])&((1<<28)-1));
        carry=(d1[i]+d2[i])>>28;
        }
    
      s[4]=((carry + d1[4]+d2[4])&((1<<15)-1));
      
      printf("\nsum: - 0x%x  ",(s[4]&((1<<15)-1)));        
      for(int i=3;i>=0;i--)
        printf("%x  ",s[i]&((1<<28)-1));
  
  
    }
    
  else{

    printf("\nsum: 0x%x  ",(s[4]&((1<<15)-1)));        
    for(int i=3;i>=0;i--)
      printf("%x  ",s[i]&((1<<28)-1));
      }

//  printf("\n%d\n",carry);  
  printf("\n");
   
    
  }

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/* Program3: For Multiplication  */



#include<stdio.h>
int main(){
  static long a[32],b[32],c[5],d[5],m[9],carry=0;
  int len=0,len2=0,len_var=0;
  char ch;
  
  //input of first number
  
  printf("enter a hex number (32 many charecters with first one 1-7 atmost):");
  scanf("%c",&ch);
  while(ch!='\n' && len<32){
    if(ch<=57 && ch>=48)
      a[len]=ch-48;
    if(ch == 'a' ||ch == 'b' || ch == 'c' || ch == 'd' || ch == 'e' || ch == 'f' )
      a[len]=ch-87;
    len++;
    scanf("%c",&ch);
    }
  
  len_var=len;
  
  for(int i=0;i<5;i++){
    for(int j=0;j<7;j++){
      if((len_var-7+j)<0)
        continue;
            
      c[i]=c[i]<<4;
      c[i]= c[i] + (a[(len_var-7+j)]&((1<<4)-1));      
      }
    len_var=len_var-7;     
    }


  //input of 2nd number
  
  printf("enter another hex number (32 many charecters with first one 1-7 atmost):");
  scanf("%c",&ch);
  while(ch!='\n' && len2<32){
    if(ch<=57 && ch>=48)
      b[len2]=ch-48;
    if(ch == 'a' ||ch == 'b' || ch == 'c' || ch == 'd' || ch == 'e' || ch == 'f' )
      b[len2]=ch-87;
    len2++;
    scanf("%c",&ch);
    }
  
  
  len_var=len2;
  
  for(int i=0;i<5;i++){
    for(int j=0;j<7;j++){
      if((len_var-7+j)<0)
        continue;
            
      d[i]=d[i]<<4;
      d[i]= d[i] + (b[(len_var-7+j)]&((1<<4)-1));      
      }
    len_var=len_var-7;     
    }

// a0 + a1 + a2 + a3 + a4
// b0 + b1 + b2 + b3 + b4

// a0b0 + (a0b1 + a1b0) + ( a2b0 + a1b1 + a0b2)


  for(int k=0;k<9;k++){
    for(int i=0;i<5;i++)
      for(int j=0;j<5;j++)
        if(i+j==k)
          m[k]=m[k]+(c[i]*d[j]);

    m[k]=m[k]+carry;
    carry=m[k]>>28;     
    m[k]=m[k]&((1<<28)-1);
    }
 
//  printf("\nsum: 0x%x",(s[4]&((1<<15)-1)));    

  printf("\nmult: 0x");    
  for(int i=8;i>=0;i--)
    printf("%lx",m[i]);
     
  printf("\n");
    
  }






