using namespace  std;
int main()
{
	int T,Arr[1000],N;
	cin>>T;
	while(T--)
	{
		cin>>N;
		for(int i=0;i<N;i++)
		cin>>Arr[i];
		if(N!=1)
		{
		int Flag=0;
		for(int i=0,j=N-1;i<j;i++,j--)
		{
			if(Arr[i]<Arr[j]){
			Flag=1;
			}
			else if(Arr[i]>Arr[j]){
			Flag=0;
			}
			Arr[j]=Arr[i];
		}
		if(Flag==1)
		{
			for(int i=(N-1)/2;i>=0;i--)
			{
			Arr[i]=(Arr[i]+1)%10;
			Arr[N-1-i]=Arr[i];
			if(Arr[i]!=0)
			break;
		    }
		}
		for(int i=0;i<N;i++)
		cout<<Arr[i]<<" ";
		cout<<"\n";
		}
		else if(N==1)
		{
		if(Arr[0]<9)
		{
		    Arr[0]=Arr[0]+1;
		    cout<<Arr[0];
		}
		else cout<<1<<" "<<1;
		cout<<"\n";
		}
	}
}
