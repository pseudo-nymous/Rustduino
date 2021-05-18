#include<bits/stdc++.h>
using namespace std;

// I have considered every possible scenarios check throughly for respect++
char op[4]={'/','*','+','-'};
void debug(char x,string input)
{
        cout<<x<<": ";
        for(int i=0;i<input.length();i++)
        {
                if(input[i]==' ')
                        cout<<"_";
                else cout<<input[i];
        }
        cout<<endl;
}
long double evaluate(long double num1,long double num2,char op)
{
        switch(op)
        {
                case '+':
                        return num1+num2;
                case '-':
                        return num1-num2;
                case '*':
                        return num1*num2;
                case '/':
                        return num1/num2;
        }
        return INT_MIN;
}
int main()
{
        string input;
        cout<<"Enter an expression: ";
        getline(cin,input);
        int countOp=0;
        for(int i=0;i<input.length();i++)
        {
                for(int j=0;j<4;j++)
                {
                        if(input[i]==op[j])
                                countOp++;
                }
        }
        if(countOp!=2)
        {
                cout<<"Expression has operators not equal to 2"<<endl;
                return 0;
        }
        //debug('0',input);
        while(input[0]==' ')
                input.erase(0,1);
        //debug('1',input);
        while(input[input.length()-1]==' ')
                input.pop_back();
        //debug('2',input);
        for(int i=0;i<input.length();i++)
        {
                for(int j=0;j<4;j++)
                {
                        if(input[i]==op[j])
                        {
                                while(i+1<input.length() && input[i+1]==' ')
                                        input.erase(i+1,1);
                                int k=i-1;
                                while(k>=0 && input[k]==' ')
                                        input.erase(k--,1);
                                i=k+2;
                                //debug('3',input);
                        }
                }
        }
        vector<int> pos;
        for(int i=0;i<input.length();i++)
        {
                for(int j=0;j<4;j++)
                {
                        if(input[i]==op[j])
                                pos.push_back(i);
                }
        }
        bool valid=true;
        for(int i=0;i<input.length();i++)
        {
                if(i==pos[0] || i==pos[1])
                        continue;
                if(input[i]<'0' || input[i]>'9')
                {
                        valid=false;
                        break;
                }
        }
        if(!valid || !(pos[0]>0 && pos[1]<input.length()-1 && pos[1]-pos[0]>1))
        {
                cout<<"Expression not supported or is invalid"<<endl;
                return 0;
        }
        //debug('4',input);
        vector<string>nums(3);
        nums[0]=string(input,0,pos[0]);
        nums[1]=string(input,pos[0]+1,pos[1]-pos[0]-1);
        nums[2]=string(input,pos[1]+1,input.length()-pos[1]-1);
        char x[2];
        x[0]=input[pos[0]];
        x[1]=input[pos[1]];
        //for(int i=0;i<3;i++)
                //cout<<nums[i]<<endl;
        for(int i=0;i<3;i++)
        {
                while(nums[i][0]=='0' && nums[i].size()>4)
                        nums[i].erase(0,1);
        }
        bool limitExceeded=false;
        for(int i=0;i<3;i++)
        {
                if(nums[i].length()>4)
                {
                        limitExceeded=true;
                        break;
                }
                else if(nums[i].length()==4)
                {
                        int val=stoi(nums[i]);
                        if(val>1000)
                        {
                                limitExceeded=true;
                                break;
                        }
                }
        }
        if(limitExceeded)
        {
                cout<<"Incorrect input: numbers cannot exceed 1000. Program terminated, please try again."<<endl;
                return 0;
        }
        vector<int>vals(3);
        for(int i=0;i<3;i++)
                vals[i]=stoi(nums[i]);
        //for(int i=0;i<3;i++)
                //cout<<vals[i]<<endl;
        cout<<"Result: ";
        if((x[0]=='/' && vals[1]==0) || (x[1]=='/' && vals[2]==0))
        {
                        cout<<"Error: \"division by zero\""<<endl;
                        return 0;
        }
        long double result[2];
        if(x[0]=='/')
        {
                //cout<<"Case 1: ";
                result[0]=(long double)vals[0]/vals[1];
                result[1]=vals[2];
                cout<<evaluate(result[0],result[1],x[1])<<endl;
        }
        else if(x[1]=='/')
        {
                //cout<<"Case 2: ";
                result[1]=(long double)vals[1]/vals[2];
                result[0]=vals[0];
                cout<<evaluate(result[0],result[1],x[0])<<endl;
        }
        else if(x[0]=='*')
        {
                //cout<<"Case 3: ";
                result[0]=(long double)vals[0]*vals[1];
                result[1]=vals[2];
                cout<<evaluate(result[0],result[1],x[1])<<endl;
        }
        else if(x[1]=='*')
        {
                //cout<<"Case 4: ";
                result[1]=(long double)vals[1]*vals[2];
                result[0]=vals[0];
                cout<<evaluate(result[0],result[1],x[0])<<endl;
        }
        else
        {
                //cout<<"Case 5: ";
                result[0]=evaluate(vals[0],vals[1],x[0]);
                result[1]=vals[2];
                cout<<evaluate(result[0],result[1],x[1])<<endl;
        }
}
