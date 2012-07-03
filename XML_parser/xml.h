#include <string>
#using <system.dll>

using namespace std;
using namespace System;
using namespace System::Text::RegularExpressions;


//класс атрибутов
class Attr{
public:
	//имя
	string name;
	//значение
	string value;
	//конструктор

	Attr(string n,string v){
		name=n;
		value=v;
	}

};

//класс тегов
class Tag{
public:
	//имя
	string name;
	//текст в теге
	string value;
	//вложенные теги
	Tag *tags;
	//атрибуты тега
	Attr *attr;
	//комментарии к тегу
	string comments;
	//весь текст содержащийся в теге
	string text;
	//конструктор
	Tag(string n){
		name=n;
	}


};



//класс xml
class Xml_doc{
public:
	//корневой тег
	Tag tag;
	//атрибуты заголовка
	Attr *attr;
	//заполнение структоры
	int read(string path);
	//создание xml файла
	int create(string path);
	//конструктор
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


