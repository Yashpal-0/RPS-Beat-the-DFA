#include<bits/stdc++.h>

using namespace std;

struct node{
    char state='\0';
    int r=0,p=0,s=0;
}fsm[51];
int n;
void copy_fsm(node bs[])
{
    for(int i=1;i<=50;i++)
    {
        bs[i].state=fsm[i].state;
        bs[i].r=fsm[i].r;
        bs[i].p=fsm[i].p;
        bs[i].s=fsm[i].s;
    }
}
void generate_random()
{
    //random number generator from 1 to 3 and 1 to 50
    for(int i=1;i<=50;i++)
    {
        int x=rand()%3+1;
        if(x==1)
            fsm[i].state='R';
        else if(x==2)
            fsm[i].state='P';
        else
            fsm[i].state='S';
    }
    for(int i=3;i<153;i++)
    {
        int x=i%3;
        int y=rand()%50+1;
        switch(x)
        {
            case 0:
                fsm[i/3].r=y;
                break;
            case 1:
                fsm[i/3].p=y;
                break;
            case 2:
                fsm[i/3].s=y;
                break;  
        }        
    }
}
long int simulate_game(node s[]){
    long int score=0;
    for(int i=1;i<=n;i++)
    {
        int m=1,o=i;
        for(int j=1;j<=300;++j)
        {
            if(s[o].state=='R')
            {
                if(fsm[m].state=='R')
                {
                    score+=0;
                    o=s[o].r;
                }
                else if(fsm[m].state=='P')
                {
                    score+=1;
                    o=s[o].p;
                }
                else
                {
                    score+=-1;
                    o=s[o].s;
                }
                m=fsm[m].r;
            }    
            else if(s[o].state=='P')
            {
                if(fsm[m].state=='R')
                {
                    score+=-1;
                    o=s[o].r;
                }
                else if(fsm[m].state=='P')
                {
                    score+=0;
                    o=s[o].p;
                }
                else
                {
                    score+=1;
                    o=s[o].s;
                }
                m=fsm[m].p;
            }
            else
            {
                if(fsm[m].state=='R')
                {
                    score+=1;
                    o=s[o].r;
                }
                else if(fsm[m].state=='P')
                {
                    score+=0;
                    o=s[o].p;
                }
                else
                {
                    score+=0;
                    o=s[o].s;
                }
                m=fsm[m].s;
            }
            
        }
        }
        return score;
    }
void print(node s[],int size)
{
 for(int i=1;i<=size;i++)
 {
    cout<<s[i].state<<' '<<s[i].r<<' '<<s[i].p<<' '<<s[i].s<<endl;
 }
}

int main()
{
cin>>n;
node s[n+1],bs[51];

for(int i=1;i<=n;i++)
{
    cin>>s[i].state>>s[i].r>>s[i].p>>s[i].s;
    if(s[i].state=='R');
    else if(s[i].state=='P');
    else if(s[i].state=='S');
    else{
    cout<<"Invalid input";
    exit(1);
    }
}
clock_t start = clock();
int score=0;
while(clock()-start<900000)
{
    generate_random();
    long int temp=simulate_game(s);
    if(temp>score)
    {
        score=temp;
        copy_fsm(bs);
    }
}
cout<<50<<endl;
print(bs,50);
return 0;
}