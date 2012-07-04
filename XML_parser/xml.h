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
	//закрывающий тег или нет
	bool close;
	//вложенные теги
	Tag *tags;
	//атрибуты тега
	Attr *attr;
	//комментарии к тегу
	string comments;
	//весь текст содержащийся в теге
	string text;
	//конструктор
	Tag(string n, bool c){
		name=n;
		close=c
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
	String ^ getTag(void)
	{
		return getTag();
	}
	//конструктор
	Xml_doc(void);
/*
	static	string get_tag(string text, int pos)
	{
		int start = text.find("<",pos)+1;
		int end = text.find("/>",pos);
		text=text.substr(start,end-start);
		return text;
	}
*/
private:
	String^ _getTag()
	{
		Regex^ emailregex = gcnew Regex("<(?<tag>[^>]+)");
		//Regex^ emailregex = gcnew Regex("/*/");
		String^ text;
		String^ test ="1 <color/> 2 <color> 3 </color>";
        Match^ m = emailregex->Match( test);
		text="";
		text+="String: "+test+" | ";
		m=m->NextMatch();
		m=m->NextMatch();
        if ( m->Success ) 
        {

			//text=m->Groups["user"]->Value;
			
			text+="tag: "+m->Groups["tag"]->Value;
			
			//text="ok";
			//text->Insert(5, m->Groups["value"]->Value);

        }
		else {
            text="failed";
        }
    return text;
	}

	String^  _reg()
	{
		Regex^ emailregex = gcnew Regex("<(?<tag>[^ ]+) (?<attr>[^=]+)=\"(?<value>[^ ]+)\"");
		//Regex^ emailregex = gcnew Regex("/*/");
		String^ text;
		String^ test ="asdasd <color red=\"00FF00\" green=\"FF0000\" > asdasdasd";
        Match^ m = emailregex->Match( test);
		text="";
		text+="String: "+test+" | ";
        if ( m->Success ) 
        {

			//text=m->Groups["user"]->Value;
			
			text+="tag: "+m->Groups["tag"]->Value+" | ";
			text+="attr: "+m->Groups["attr"]->Value+" | ";
			text+="value: "+m->Groups["value"]->Value+" | ";
			//text="ok";
			//text->Insert(5, m->Groups["value"]->Value);

        }
		else {
            text="failed";
        }
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
/*
private:
	string get_tag(string text)
	{
		int start=text.find('<');
		int end=text.find('\>');
		return "ok";
	}

*/
}; 









//string n="data";
//string v="1234";
//Attr atrreb(n,v);
//Xml_doc xml1();


