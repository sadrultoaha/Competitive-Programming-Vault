/***
    MY LIBRARY FUNCTIONS
***/

string DeciToBin(LL q)
{
   /**
   ALGO:
     7=floor(log2(236)),Generally, p=int(logBV).
    (7) 236>128==1, number=236-128=108
    (6) 108>64==1, number=108-64=44
    (5) 44>32==1, number=44-32=12
    (4) 12>16==0
    (3) 12>8==1, number=12-8=4
    (2) 4>=4==1, number=4-4=0 number==0 ends calculations
    (1) ==0
    (0) ==0

    So 236 is 11101100 in binary.
   **/
   string res="";
   LL p=floor(log2(q));
   while(p>=0)
   {
       LL x=pow(2,p);
       if(q>=x){res+=to_string(1);q-=x;}
       else res+=to_string(0);
       p--;
   }
   return res;

}
void bin(unsigned n)
{
	if (n > 1)
	bin(n>>1);

	printf("%d", n & 1);
}
LL BinToDeci(string ans)
{
    LL dec = bitset<64>(ans).to_ullong();
    return dec
}
LL BinToDeciA(LL ADD,LL sz)
{
    LL j=sz-1,ans=0;
    for(LL i=0;i<sz;i++)
    {
        ans+=(ADD[i]*pow(2,j));
        j--;
    }
    return ans;
}
LL BinSum(LL ADD[],LL p,LL q)
{
        LL in=0,sz=0;
        while(1)
        {
            if(p==0) {ADD[in]=p;reverse(ADD,ADD+sz);break;}
            ADD[in]=p%2;
            p=p/2;
            in++;
            sz++;
        }
        return ADD;
}

ULL getBITS(ULL q)
{
    ULL cnt=0,leng=1;
    while(q>0)
    {
        cnt++;
        q=q>>1;
    }
    return cnt;
}

