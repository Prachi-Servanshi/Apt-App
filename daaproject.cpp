#include<iostream>
#include <bits/stdc++.h> 
#include<fstream>
using namespace std;

ifstream fin;
void knapSack(int W, int wt[], float val[], int n, string name[]) 
{ 
   int i, w; 
   float K[n+1][W+1]; 
  
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i-1] <= w) 
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
  	float res = K[n][W];     
      
    w = W; 
    for (i = n; i > 0 && res > 0; i--) { 

        if (res == K[i - 1][w])  
            continue;         
        else { 
            //cout<<"RESULT"<<endl;
            cout<<name[i-1]<<" ";
			cout<<wt[i - 1]<<" ";
			cout<<val[i-1]<<endl;
              
            res = res - val[i - 1]; 
            w = w - wt[i - 1]; 
        } 
    } 
    
} 
  
int main(int argc, char** argv) 
{ 
	string str;
	string name[10];
	int lt[10];
	float l;
	float rate[10],r;
	int i=0,k,sum=0,avg;
	int choice[10],z=0;
	 cout<<"****** SELECT DOMAIN *********";
	 cout<<" 1) FOOD \n 2)EWallet \n 3)trip \n 4)ECommerce \n 5)Cab \n 6)Entertainment \n 7)Music \n";
	 cin>>choice[z];
	 char ch;
	 cout<<"press T to continue";
	 cin>>ch;
	while(ch=='T')
	{
		z++;
		cout<<"\nenter next domain number";
		cin>>choice[z];
		cout<<"\npress T to continue";
		cin>>ch;
	}
	for(k=0;k<=z;++k)
	{
		switch(choice[k])
		{
			case 1:fin.open("food.txt");
			break;
			case 2:fin.open("ewallet.txt");
			break;
			case 3:fin.open("trip.txt");
			break;
			case 4:fin.open("Ecommerce.txt");
			break;
			case 5:fin.open("cab.txt");
			break;
			case 6:fin.open("entertainment.txt");
			break;
			case 7:fin.open("music.txt");
			break;
			default: cout<<"wrong!";
		}
		i=0;
		sum=0;
		cout<<"\n\n------------------------- APPS -----------------------------"<<endl;
		while(getline(fin,str))
		{
			stringstream in(str);
			string s;
			in>>s;
			name[i] =s;
			cout<<name[i]<<" ";
			
			in>>l;
			lt[i]=(int)l;
			cout<<lt[i]<<" ";
			
			in>>r;
			rate[i]=r;
			cout<<rate[i]<<endl;
			i++;
		}
		
		int n = i, temp;
		float tempf;
		string temps;
/*		for(i=0; i<n-1; i++)
		{
			for(int j=0; j<n-1-i; j++)
			{
				if(lt[j] < lt[j+1])
				{
					temp = lt[j];
					lt[j] = lt[j+1];
					lt[j+1] = temp;
					
					tempf = rate[j];
					rate[j] = rate[j+1];
					rate[j+1] = tempf;
					
					temps = name[j];
					name[j] = name[j+1];
					name[j+1] = temps;
				}
			}
		}
		
		for(i=0; i<n; i++)
		{
			cout<<name[i]<<lt[i]<<rate[i]<<endl;
		}*/
		
		for(int j=0;j<i;j++){
			sum+=lt[j];
		}
		avg=sum/i;
		int W= avg;
	cout<<endl<<"--------- RESULT -------------"<<endl;
    knapSack(W, lt, rate, i,name); 
    fin.close();
}
    return 0; 
}


/*
\begin{algorithm}
\caption{AptApp}
\begin{algorithmic}[1]
\Procedure{aptapp}{$w$, $wt[]$, $val[]$, $n$, $name$}
    \For{i:=0 to n}
        \For{w:=0 to W}
            \If{$i == 0 \parallel w == 0$}
                \State $k[i][w] \gets 0$
            \ElsIf{$wt[i-1] \leq w$}
                \State $k[i][w] \gets max(val[i-1]+k[i-1][w-wt],k[i-1][w])$
            \Else
                \State $k[i][w] \gets k[i-1][w]$
            \EndIf
        \EndFor
    \EndFor\label{aptappendfor}
    \State $res \gets k[n][W]$
    \State $w \gets W$
    \State $result \gets Null$
    \For{i:=n to 0}
        \If{$res > 0$}
            \If{$res == k[i-1][w]$}
                \State \textbf{continue}
            \Else
                \State $result \gets result \cup name[i-1]$
                \State $res \gets res - val[i-1]$
                \State $w \gets w - wt[i-1]$
            \EndIf
        \EndIf
    \EndFor
    \State \textbf{return} $result$
\EndProcedure
\end{algorithmic}
\end{algorithm}
*/ 
