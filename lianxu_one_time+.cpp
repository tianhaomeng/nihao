#include <stdio.h>  
#include <string.h>  
int StringFind(const char *pSrc, const char *pDst)  //pSrc为待查找字符串，pDst为查找目标 
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
    return -1;  //若该行无制定字符串则返回-1； 
} 
int main()  
{   long row=1500000,column=3,i,j;
    int adr1,adr2,adrs;
    long tem;long count=0,num1=0,loc1,grop1[50000][3],time1=0,num2=0,time2=0,loc2,grop2[50000][2],count2=0;//a[][]第一列存核的序号，第二列存typ，第三列存adr 
    
   long **a=new long*[row];
   for( i= 0; i < row; i++)  
   {
     a[i]  = new long[column];
   
   }
   long **b=new long*[row];
   for( i= 0; i < row; i++)  
   {
     b[i]  = new long[column];
   
   } 
    
	char szTest[1000] = {0};  char typ[50],adr[10];
    int len = 0;
	int src[65][1] ,dst[65][1];int data[65][65][1];// 分别是 来源 目的地 包的数量 

    FILE *fptr = fopen("统计结果.txt", "w");  //请输入文件路径 
    FILE *fp = fopen("text.txt", "r");  //请输入文件路径 
    if(NULL == fp)  
    {  
        printf("failed to open dos.txt\n");  //打开失败时 
        return 1;  
    }  
  
    while(!feof(fp))  //单行读入直到文件结束 
    {   memset(typ, 0, sizeof(typ));  
        memset(szTest, 0, sizeof(szTest));  //置空字符串 
        fgets(szTest, sizeof(szTest) - 1, fp);  //单行读入 
        if(StringFind(szTest,"SRC:")!=-1)//在这里改要查找的目标 
		{
		
		  loc1=StringFind(szTest,"SRC:")+4;//确定SRC后第一个数字的下标 
          if(szTest[loc1+1]==32)// 数据为个位数 
          {
        	  a[count][0]=szTest[loc1]-48;
			  //src[a[count]][0]++;
        	  
        	  
	  	  }
          else//数据为两位数 
          {
        	  a[count][0]=(szTest[loc1]-48)*10+szTest[loc1+1]-48;
        	  //src[a[count]][0]++;
        	  
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
	    if(StringFind(szTest,"DST:")!=-1) 
		{
		
		    loc1=StringFind(szTest,"DST:")+4;
            if(szTest[loc1+1]==32)
            {
        	    b[count2][0]=szTest[loc1]-48;
        	//     dst[b[count2]][0]++;
        	   
	  	    }
            else
            {
        	    b[count2][0]=(szTest[loc1]-48)*10+szTest[loc1+1]-48;
        	  //   dst[b[count2]][0]++;
        	   
		    }
	    }
		//data[a[count]][b[count2]][0]++;
		b[count2][1]=a[count][1];b[count2][2]=a[count][2];
		count++; count2++;
	}
	    
     num1=count-1;num2=count2-1;
    fprintf(fptr,"%d组数据中 ",count);
     
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
	fprintf(fptr,"共出现了%d次连续相同的SRC \n",time1);
	for(count=1;count<=time1;count++)
	{
		fprintf(fptr,"%d: %d\n",count,grop1[count][0]);//如果觉得打印太慢了可以吧这行注释掉 	
	}
	//printf("*********************************************我是分割线**********************************************\n*********************************************我是分割线**********************************************\n%d组数据中 ",num2+1);
     
  
	for(count=0;count<num2;count++)
    {   
    	if(b[count][0]==b[count+1][0]&&b[count][1]==b[count+1][1]&b[count][2]==b[count+1][2])
		{   
		    count++;
			time2=time2+1;grop2[time2][0]+=2;
			grop2[time2][1]=b[count][0];
			while(b[count][0]==b[count+1][0]&&b[count][1]==b[count+1][1]&b[count][2]==b[count+1][2])
			{
				count++;
				grop2[time2][0]++;
			}
		}
	
	}
	fprintf(fptr,"共出现了%d次连续相同的DST \n",time2);
	for(count=1;count<=time2;count++)
	{
		fprintf(fptr,"%d: %d\n",count,grop2[count][0]);//如果觉得打印太慢了可以吧这行注释掉 
		
	}
	
	
//	for(i=1;i<65;i++)
	{
	//	fprintf(fptr,"从核%d发送的包的数量为%d\n",i,src[i][0]);
		
		
		
	}
	printf("\n\n*********************************************我是分割线**********************************************\n") ;
//	for(i=1;i<65;i++)
	{
//		fprintf(fptr,"以核%d为目的地的包的数量为%d\n",i,dst[i][0]);
		
		
		
	}
/*	for(i=1;i<64;i++)
	{
		for(count=1;count<64;count++)
		{if(count!=63) 
		    fprintf(fptr,"从节点%d发送到节点%d的包数量为%d\n ",i,count,data[i][count][0]);
		 else
		     fprintf(fptr,"%d;",data[i][count][0]/*i,count,);
		} 
		*/
	
	fclose(fp); 
	fclose(fptr); 
    return 0;  
}  

