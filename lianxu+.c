#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int MyType ;
int StringFind(const char *pSrc, const char *pDst)  
{  
    int i, j;  
    for (i=0; pSrc[i]!='\0'; i++)  
    {  
        if(pSrc[i]!=pDst[0])  
            continue;         
        j = 0;  
        while(pDst[j]!='\0' && pSrc[i+j]!='\0')  
        {  
            j++;  
            if(pDst[j]!=pSrc[i+j])  
            break;  
        }  
        if(pDst[j]=='\0')  
            return i;  
    }  
    return -1;  
}  
int main()  
{ 


	long row = 300000000;/////�ݼٶ�������2���������������ʱ�̾�����
    long column = 4;/////�ݼٶ�������2���������������ʱ�̾�����
 void **ptdhead = NULL;//////////�ں���˵��ΪʲôҪ��void**����
 void **ptdBody = NULL;//////////�ں���˵��ΪʲôҪ��void**����
 ptdhead = (void **)malloc(sizeof(void*)*row + sizeof(MyType)*row*column);

 ptdBody = ptdhead + row ;

long ncount;
 for( ncount = 0; ncount < row; ncount++)
 ptdhead[ncount] = ptdBody + ncount * column* sizeof(MyType)/sizeof(void*);
 MyType**a;
 a = (MyType**)ptdhead;///////////////////ǿ��ת��Ϊ�Լ�������Ҫ�Ķ�ά����Ԫ�����͵�ָ��
 ptdhead = NULL;
 
 
 	 row = 10000000;/////�ݼٶ�������2���������������ʱ�̾�����
     column = 4;/////�ݼٶ�������2���������������ʱ�̾�����
 //////////�ں���˵��ΪʲôҪ��void**����
 ptdhead = (void **)malloc(sizeof(void*)*row + sizeof(MyType)*row*column);

 ptdBody = ptdhead + row ;


 for( ncount = 0; ncount < row; ncount++)
 ptdhead[ncount] = ptdBody + ncount * column* sizeof(MyType)/sizeof(void*);
 MyType**grop1;
 grop1 = (MyType**)ptdhead;///////////////////ǿ��ת��Ϊ�Լ�������Ҫ�Ķ�ά����Ԫ�����͵�ָ��
 ptdhead = NULL;
 
 
	long i,j; 

 char name[6]="SRC";FILE *fptr = fopen("DATA_condition.txt", "w");
  printf("������Ҫͳ�Ƶ����� ��SRC/DST��\n");
  scanf("%s",name) ;
  int choice=1; 
    
    int adr1,adr2,adrs;
    long tem;long count=0,num1=0,loc1,time1=0,num2=0,time2=0,loc2,count2=0;//a[][]��һ�д�˵���ţ��ڶ��д�typ�������д�adr 
   
   
    
	char szTest[1000] = {0};  char typ[50],adr[10];
    int len = 0;                                                             //          //                                                                     //     //     //       // 
    FILE *fp = fopen("text.txt", "r");  //�������޸��ļ�·���������� // 
    
	if(NULL == fp)                                                    //                          // 
    {                                                                   //                    //                                                                  //             // 
        printf("failed to open dos.txt\n");                                   //       // 
        return 1;                                                                 // 
    }  
    while(!feof(fp))  
    {  memset(typ, 0, sizeof(typ));  
        memset(szTest, 0, sizeof(szTest));  
        fgets(szTest, sizeof(szTest) - 1, fp);  
        if(StringFind(szTest,name)!=-1)//�������Ҫ���ҵ�Ŀ�� 
		{
		
		loc1=StringFind(szTest,name)+strlen(name)+1;             //                 ||
        if(szTest[loc1+1]==32)                                  //                 ||||
        {                                                     //                 ||||||||
        	a[count][0]=szTest[loc1]-48;                       //              /||||||||||||
        	                                        //                    ||||
		}                                                    //                    ||||
        else                                                //                     ||||
        {                                                   //                     |||| 
        	a[count][0]=(szTest[loc1]-48)*10+szTest[loc1+1]-48;//                 |||||| 
        	
		}
	    }
	    if(StringFind(szTest,"TYP")!=-1)
	    {   adrs=StringFind(szTest,"SrcType");
	    	adr1=StringFind(szTest,"TYP")+4;
	    	
	    	for(i=0;i<adrs-adr1;i++)
	    	{	
	    		typ[i]=szTest[adr1+i];
			}
		//	fprintf(fptr,"%s\n",typ);
			if(strcmp(typ,"Invalid Command ")==0)
			   a[count][1]=1;
			else if(strcmp(typ,"ReadReq ")==0)//
			   a[count][1]=2;
			else if(strcmp(typ,"ReadResp ")==0)//
			   a[count][1]=3;   
	    	else if(strcmp(typ,"Read Response With Invalidate ")==0)
			   a[count][1]=4;
			else if(strcmp(typ,"Write Request ")==0)
			   a[count][1]=5;
	    	else if(strcmp(typ,"Write Response ")==0)
			   a[count][1]=6;
			else if(strcmp(typ,"Writeback ")==0)//
			   a[count][1]=7;
	    	else if(strcmp(typ,"UpgradeReq ")==0)//
			   a[count][1]=8;
			else if(strcmp(typ,"UpgradeResp ")==0)//
			   a[count][1]=9;
	    	else if(strcmp(typ,"ReadExReq ")==0)//
			   a[count][1]=10;
			else if(strcmp(typ,"ReadExResp ")==0)//
			   a[count][1]=11;
	    	else if(strcmp(typ,"DowngradeResp ")==0)
			   a[count][1]=12;
			else if(strcmp(typ,"InvalidateReq ")==0)//
			   a[count][1]=13;
			else if(strcmp(typ,"InvalidateResp ")==0)//
			   a[count][1]=14;
			else if(strcmp(typ,"DowngradeReq ")==0)//
			   a[count][1]=15;   
	    	else 
			   a[count][1]=16;	
		}
		if(StringFind(szTest,"ADR")!=-1)
		{
			adr2=StringFind(szTest,"ADR")+6;
			for(i=0;i<8;i++)
			{
				if(szTest[adr2+i]>=97&&szTest[adr2+i]<=102)
			    {
				   tem=10+szTest[adr2+i]-97;
				   for(j=0;j<8-i;j++)
				   tem=tem*16;
				   a[count][2]+=tem;
			    }
			    else
			    {
			    	tem=szTest[adr2+i]-48;
			    	for(j=0;j<8-i;j++)
				    tem=tem*16;
				    a[count][2]+=tem;
			    	
				}	
		}
		} 
		count++;
    }  num1=count;num2=count2;
   fprintf(fptr,"%d�������� \n",count);
     
    for(count=0;count<num1;count++)
    {   
    	if(a[count][0]==a[count+1][0]&&a[count][1]==a[count+1][1]&a[count][2]==a[count+1][2])
		{   
		    count++;
			time1=time1+1;grop1[time1][0]+=2;//grop1[time1][2]=count;
			grop1[time1][1]=a[count][0];
			while(a[count][0]==a[count+1][0]&&a[count][1]==a[count+1][1]&a[count][2]==a[count+1][2])
			{
				count++;
				grop1[time1][0]++;
			}
		}
	}
	
	fprintf(fptr,"��������%d��������ͬ��%s\n****************************���Ƿָ���*****************************\n\n",time1,name);
if(choice==1)	
    
	{
	for(count=1;count<=time1;count++)
	{
		//printf("��%d�������ظ����ظ����ֵ�������%d,�ظ�������%d��\n",count,grop1[count][1],grop1[count][0]);//������ô�ӡ̫���˿��԰�����ע�͵� 
		fprintf(fptr,"%d��  %d  \n",count,grop1[count][0]/*,grop1[count][2]*/);
	}
    } 
	fclose(fp); 
 //     for(i=0;i<num1;i++)
//	  fprintf(fptr,"%d\  \n",a[i][2]);
	
    fclose(fptr);
    return 0;  
    
}  

