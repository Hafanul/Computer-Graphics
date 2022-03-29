#include<iostream>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<stdlib.h>

using namespace std;
main()
{
    int gd,gm,n,i,xa[10],ya[10],op,tx,ty,xa1[10],ya1[10],theta,xf,yf,rx,ry,
        sx,sy,shx,shy,xref,yref;
    char d;
    gd=DETECT;
    initgraph(&gd,&gm,"");
    cout<<"enter the no of points : ";
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"enter the coordinates"<<i+1<<" : ";
        cin>>xa[i]>>ya[i];
    }
    
               cout<<"Object /n";
            for(i=0; i<n; i++)
            {
                line(xa[i],ya[i],xa[(i+1)%n],ya[(i+1)%n]);
            }
            
            
            
    do
    {
    	x:
        cout<<"menu";
        cout<<"\n1.translation\n2.rotation\n3.scaling\n4.shearing\n5.reflection\n6.exit";
        cin>>op;
        if(op==1)
        {
            cout<<"enter the translation vector";
            cin>>tx>>ty;
            for(i=0; i<n; i++)
            {
                xa1[i]=xa[i]+tx;
                ya1[i]=ya[i]+ty;
            }
            cleardevice();
            cout<<"before translation";
            for(i=0; i<n; i++)
            {
                line(xa[i],ya[i],xa[(i+1)%n],ya[(i+1)%n]);
            }
            cout<<"\nafter translation";
            for(i=0; i<n; i++)
            {
                line(xa1[i],ya1[i],xa1[(i+1)%n],ya1[(i+1)%n]);

            }
       }
       else if(op==2)
	    {
		
            cout<<"enter the rotation angle";
            cin>>theta;
            theta=(theta*3.14)/180;
            cout<<"enter the reference points";
            cin>>xf>>yf;
            for(i=0; i<n; i++)
            {
                xa1[i]=xf+(xa[i]-xf)*cos(theta)-(ya[i]-yf)*sin(theta);
                ya1[i]=yf+(xa[i]-xf)*sin(theta)-(ya[i]-yf)*cos(theta);
            }
            cout<<"before rotation";
            for(i=0; i<n; i++)
            {
                line(xa[i],ya[i],xa[(i+1)%n],ya[(i+1)%n]);
            }
            cout<<"after rotation ";
            for(i=0; i<n; i++)
            {
                line(xa1[i],ya1[i],xa1[(i+1)%n],ya1[(i+1)%n]);
            }
        }
        else if(op==3)
		{
            cout<<"enter the scaling factor ";
            cin>>sx>>sy;
            cout<<"enter the reference point ";
            cin>>rx>>ry;
            for(i=0; i<n; i++)
            {
                xa1[i]=xa[i]*sx+rx*(1-sx);
                ya1[i]=ya[i]*sy+ry*(1-sy);
            }

            cout<<"before scaling";
            for(i=0; i<n; i++)
            {
                line(xa[i],ya[i],xa[(i+1)%n],ya[(i+1)%n]);
            }
            cout<<"after scaling";

            for(i=0; i<n; i++)
            {
                line(xa1[i],ya1[i],xa1[(i+1)%n],ya1[(i+1)%n]);
            }
        }
		else if(op==4)
		{
            cout<<"enter the shear value";
            cin>>shx>>shy;
            cout<<"enter the reference point";
            cin>>xref>>yref;
            cout<<"enter the shear direction x or y";
            cin>>d;
            if(d=='x')
            {
                for(i=0; i<n; i++)
                {
                    xa1[i]=xa[i]+shx*(ya[i]-yref);
                    ya1[i]=ya[i];
                }
            }
            cleardevice();
            cout<<"before shearing";
            for(i=0; i<n; i++)
           	{
                line(xa[i],ya[i],xa[(i+1)%n],ya[(i+1)%n]);
            }
            cout<<"after shearing";
            for(i=0; i<n; i++)
            {
                line(xa1[i],ya1[i],xa1[(i+1)%n],ya1[(i+1)%n]);
            }
        
   		}
		else if(op==5)
		{
            cout<<"before reflection";
            for(i=0; i<n; i++)
            {
                line(xa[i],ya[i],xa[(i+1)%n],ya[(i+1)%n]);
            }
            cout<<"after reflection";
            for(i=0; i<n; i++)
            {
                line(ya[i],xa[i],ya[(i+1)%n],xa[(i+1)%n]);
            }
        } 	
		else{
			system("clear");
			goto x ;
		}
			
	
    }
    while(op!=6);
}
