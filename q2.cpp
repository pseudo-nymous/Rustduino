#include<bits/stdc++.h>
using namespace std;
const string filename="courses.txt";
int main()
{
        fstream file;
        file.open(filename,ios::in);
        if(file.is_open())
        {
                string str;
                cout<<"Enter a search string: ";
                getline(cin,str);
                // for temporarily storing each line of text and count
                string line;
                int count=0;
                while(getline(file,line))
                {
                        bool matched=false;
                        for(int i=0;i+str.length()<=line.length();i++)
                        {
                                // compare returns 0 only if matches perfectly
                                if(line.compare(i,str.length(),str)==0)
                                {
                                        // found a match
                                        matched=true;
                                        break;
                                }
                        }
                        if(matched)
                        {
                                // print the match and increment count
                                cout<<line<<endl;
                                count++;
                        }
                }
                file.close();
                cout<<"Number of matches: "<<count<<endl;
        }
        else
        {
                cout<<"Error opening the file"<<endl;
                return 1;
        }
        return 0;
}
