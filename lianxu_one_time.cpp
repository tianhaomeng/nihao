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
{   int i, a[30000],count=0,num1=0,loc1,grop1[50000][2],time1=0,num2=0,time2=0,loc2,grop2[50000][2],count2=0,b[30000];//a 和b两个数组用于存数据，grop用来存连续情况 
    int src[65][1] ,dst[65][1];int data[65][65][1];// 分别是 来源 目的地 包的数量 
	char szTest[1000] = {0};  //szTest存每行的字符串 
    int len = 0;  
    FILE *fptr = fopen("统计结果.txt", "w");  //请输入文件路径 
    FILE *fp = fopen("text.txt", "r");  //请输入文件路径 
    if(NULL == fp)  
    {  
        printf("failed to open dos.txt\n");  //打开失败时 
        return 1;  
    }  
  
    while(!feof(fp))  //单行读入直到文件结束 
    {  
        memset(szTest, 0, sizeof(szTest));  //置空字符串 
        fgets(szTest, sizeof(szTest) - 1, fp);  //单行读入 
        if(StringFind(szTest,"SRC:")!=-1)//在这里改要查找的目标 
		{
		
		  loc1=StringFind(szTest,"SRC:")+4;//确定SRC后第一个数字的下标 
          if(szTest[loc1+1]==32)// 数据为个位数 
          {
        	  a[count]=szTest[loc1]-48;
			  src[a[count]][0]++;
        	  
        	  
	  	  }
          else//数据为两位数 
          {
        	  a[count]=(szTest[loc1]-48)*10+szTest[loc1+1]-48;
        	  src[a[count]][0]++;
        	  
		  }
	    }
	    if(StringFind(szTest,"DST:")!=-1) 
		{
		
		    loc1=StringFind(szTest,"DST:")+4;
            if(szTest[loc1+1]==32)
            {
        	    b[count2]=szTest[loc1]-48;
        	     dst[b[count2]][0]++;
        	   
	  	    }
            else
            {
        	    b[count2]=(szTest[loc1]-48)*10+szTest[loc1+1]-48;
        	     dst[b[count2]][0]++;
        	   
		    }
	    }
		//data[a[count]][b[count2]][0]++;
		
		count++; count2++;
	}
	    
     num1=count-1;num2=count2-1;
    printf("%d组数据中 ",count);
     
    for(count=0;count<num1;count++)//timie统计连续出现的组数 
    {   
    	if(a[count]==a[count+1])
		{   
		    count++;
			time1=time1+1;grop1[time1][0]+=2;//grop[][0] 存相同数据的个数，grop[][1]存重复的数据的值。 
			grop1[time1][1]=a[count];
			while(a[count]==a[count+1])
			{
				count++;
				grop1[time1][0]++;
			}
		}
	}
	printf("共出现了%d次连续相同的SRC \n",time1);
	for(count=1;count<=time1;count++)
	{
	//	fprintf(fptr,"第%d次连续重复，重复出现的数据是%d,重复出现了%d次\n",count,grop1[count][1],grop1[count][0]);//如果觉得打印太慢了可以吧这行注释掉 	
	}
	printf("*********************************************我是分割线**********************************************\n*********************************************我是分割线**********************************************\n%d组数据中 ",num2);
     
  
	for(count=0;count<num2;count++)
    {   
    	if(b[count]==b[count+1])
		{   
		    count++;
			time2=time2+1;grop2[time2][0]+=2;
			grop2[time2][1]=b[count];
			while(b[count]==b[count+1])
			{
				count++;
				grop2[time2][0]++;
			}
		}
	
	}
	printf("共出现了%d次连续相同的DST \n\n\n\n",time2);
	for(count=1;count<=time2;count++)
	{
		fprintf(fptr,"第%d次连续重复，重复出现的数据是%d,重复出现了%d次\n",count,grop2[count][1],grop2[count][0]);//如果觉得打印太慢了可以吧这行注释掉 
		
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

