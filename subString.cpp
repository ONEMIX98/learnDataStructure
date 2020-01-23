#include <iostream>
#include<string.h>
using namespace std;
class String
{
	protected:
    char *mystr;
    int len;
	public:
    	String(const char *p) 
    	{
        	len = strlen(p);
        	mystr = new char[len + 1];
        	strcpy(mystr, p);
    	}
    	~String() 
    	{
        	if (mystr != NULL)
        	{
            	delete[]mystr;
            	mystr = NULL;
            	len = 0;
        	}
    	}
    	void showStr() { cout << mystr; }
    	char * GetStr() { return mystr; }
    	virtual bool IsSubString(const char *str) 
    	{
        	int i, j;
        	for (i = 0; i<len; i++)
        	{
            	int k = i;
            	for (j = 0; str[j] != '\0'; j++, k++)
            	{
                	if (str[j] != mystr[k]) break;
            	}
            	if (str[j] == '\0') return true;
        	}
        	return false;
    	}
};

class EditString :public String 
{
	public:
    	EditString(const char *p) :String(p) {}
    	int IsSubString(int start, const char *str);
    	void EditChar(char s, char d);
   	    void EditSub(char * subs, char *subd);
   	 	void DeleteChar(char ch);
		void DeleteSub(char * sub);
};

int EditString::IsSubString(int start, const char *str)
{
        int i, j;
    	for (i = start; i<len; i++)
    	{
        	int k = i;
        	for (j = 0; str[j] != '\0'; j++, k++)
        	{
            	if (str[j] != mystr[k]) break;
        	}
        	if (str[j] == '\0') return i;
    	}
    	return -1;
}

void EditString::EditChar(char s,char d)
{
	for(int i=0;i<len;i++)
	{
		if(mystr[i]==s)
		{
			mystr[i] = d;
		}
	}
}
	
void EditString::EditSub(char *subs, char *subd)
{
	string subdstr, mstr,subsstr;
	mstr = mystr;
	subdstr=subd;
	subsstr=subs;
	
	int start = 0;
	int index;
	while(1)
	{
		index = mstr.find(subsstr,start);
		if(index != string::npos)
		{
			mstr.replace(index,strlen(subs),subdstr);
			start=index+strlen(subd);
			len-=(strlen(subs)-strlen(subd));
		}
		else
		{
			break;
		}
	}
	
	mstr.copy(mystr,mstr.length(),0);
	mystr[len] = '\0';
}

void EditString::DeleteChar(char ch)
{
	int j;
	for(int i=0;mystr[i]!='\0';i++)
	{
		if(mystr[i] == ch)
		{
			for(j=i+1;mystr[j]!='\0';j++)
			{
				mystr[j-1]=mystr[j];
			}
			mystr[j-1] = '\0';
			
		}
	}
}

void EditString::DeleteSub(char *sub)
{
	string mstr = mystr;
	string substr = sub;
	int start = 0;
	int index;
	while(1)
	{
		index = mstr.find(substr,start);
		if(index!=string::npos)
		{
			mstr.replace(index,strlen(sub),"");
			start=index;
			len-=strlen(sub);
		}
		
		
		else
		{
			break;
		}
		
		mstr.copy(mystr,mstr.length(),0);
		mystr[len] = '\0';
	}
}
int main(int argc, char const *argv[])
{
	int type;
	cin>>type;
	EditString s("testeditstring1");
	switch(type)
	{
		case 1:
			cout<<s.IsSubString(2,"edit")<<endl;
			cout<<s.IsSubString(5,"edit")<<endl;
			break;
		case 2:
			s.EditChar('t','Y');
			cout<<s.GetStr()<<endl;
			break;
		case 3:
			s.EditSub("edit","");
			cout<<s.GetStr()<<endl;
	    	s.EditSub("test","TEST");
			cout<<s.GetStr()<<endl;
			break;
		case 4:
			s.DeleteChar('t');
			cout<<s.GetStr()<<endl;
			break;
		case 5:
			s.DeleteSub("test");
			cout<<s.GetStr()<<endl;
			break;
	}
	return 0;
}
