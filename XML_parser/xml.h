#include <string>
#using <system.dll>

using namespace std;
using namespace System;
using namespace System::Text::RegularExpressions;


//����� ���������
class Attr{
public:
	//���
	string name;
	//��������
	string value;
	//�����������

	Attr(string n,string v){
		name=n;
		value=v;
	}

};

//����� �����
class Tag{
public:
	//���
	string name;
	//����� � ����
	string value;
	//��������� ����
	Tag *tags;
	//�������� ����
	Attr *attr;
	//����������� � ����
	string comments;
	//���� ����� ������������ � ����
	string text;
	//�����������
	Tag(string n){
		name=n;
	}


};



//����� xml
class Xml_doc{
public:
	//�������� ���
	Tag tag;
	//�������� ���������
	Attr *attr;
	//���������� ���������
	int read(string path);
	//�������� xml �����
	int create(string path);
	//�����������
	Xml_doc(void);

	static	string get_tag(string text, int pos)
	{
		int start = text.find("<",pos)+1;
		int end = text.find("/>",pos);
		text=text.substr(start,end-start);
		return text;
	}


	static String^  reg()
	{
		array<String^>^ address=
    {
        
        "barry@adatum.com",
        "treyresearch.net",
        "karen@proseware.com",
		"man2   man = \"dude\"tertert "
    };

		//Regex^ emailregex = gcnew Regex("(?<user>[^ =]+)");
		Regex^ emailregex = gcnew Regex("/.../");
	String^ text;
	
    for (int i=0; i<address->Length; i++)
    {
        Match^ m = emailregex->Match( address[i] );
        Console::Write("\n{0,25}", address[i]);

        if ( m->Success ) 
        {

			text=m->Groups["user"]->Value;
			//text="dsfsdf";
			//text->Insert(5, m->Groups["value"]->Value);

        }
        else 
            Console::Write("   (invalid email address)");
        }

    Console::WriteLine("");
	//text.Insert(1,"test");
	
    return text;
	}

	string get_attr(string text, int pos)
	{
		int start = text.find(" ",pos)+1;
		int end = text.find("=",pos);
		text=text.substr(start,end-start);  
		//text=text.replace(,"1");
		return text;

	}

private:
	string get_tag(string text)
	{
		int start=text.find('<');
		int end=text.find('\>');
	}


}; 









string n="data";
string v="1234";
Attr atrreb(n,v);
Xml_doc xml1();


