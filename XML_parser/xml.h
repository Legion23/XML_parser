#include <string>
#include <fstream>
#include <vector>
#include < list>  
#using <system.dll>

using namespace std;
using namespace System;
using namespace System::Windows::Forms;
using namespace Runtime::InteropServices;
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
class xml_Tag{
public:
	//имя
	string name;
	//текст в теге
	string value;
	//закрывающий тег или нет
	bool close;
	//вложенные теги
	list <xml_Tag> tags;
	//атрибуты тега
	Attr *attr;
	//комментарии к тегу
	string comments;
	//весь текст содержащийся в теге
	string text;
	//конструктор
	
	xml_Tag(void){
		/*
	name=n;
	close=c;
	*/
	}
	

};


//класс xml
class Xml_doc{
public:
	//корневой тег
	xml_Tag *root;
	//атрибуты заголовка
	Attr *attr;
	//заполнение структоры
	int read(string path);
	//содержание xml файла
	string file;
	int lastInxdex;
	//создание xml файла
	int XML(string path);

	String^ getTag(void)
	{
		return getTag();
	}
	void readFile(void)
	{
		_readFile("D:/test.xml");
	}
	void parse(void)
	{
		_parse();
	}
	//конструктор
	Xml_doc(void){
		this->root-> name="xml";
		this->lastInxdex=0;
		this->readFile();
	}
	static System::String^ convertStrToChar(std::string str)
	{
		return gcnew System::String(str.c_str());
	}
private:
	 

	static const std::string SysToStd(System::String^ SysStr){
	char *v = (char*) (Marshal::StringToHGlobalAnsi(SysStr)).ToPointer() ;
	std::string result = std::string(v);
	Marshal::FreeHGlobal(System::IntPtr((void*)v));
	return result;
	}
/*
	string getelems(Tag tag)
	{
		string text="";
		for (int i=0;i<tag.tag.s;i++)
		{

		}

	}
*/
	int _readFile(string Path){
		ifstream input_file(Path.c_str(), ios::in|ios::binary );
		//MessageBox(NULL,"ghbdtnb","dsfdf",MB_OK);
		if(!input_file)
		{
			//MessageBox::Show("Can't open file "+convertStrToChar(Path));
			return -1;
		}
		char line[1024]; 
		while (!input_file.eof())

		{ 
			input_file.getline(line, sizeof(line)); 
			this->file.append(line);
			this->file.append("\n"); 
		} 
		input_file.close();
		//infile>>this->file;
		return 0;
	}
		

	int _parse()
	{
		_getTag(this->root,this->lastInxdex);
		return 0;
	}



	int _getTag(xml_Tag *root, int start=0)
	{
		Regex^ emailregex = gcnew Regex("<(?<tag>[^>]+)");
		//Regex^ emailregex = gcnew Regex("<(?<tag>[^ ]+) (?<attr>[^=]+)=\"(?<value>[^ ]+)\"");
		//Regex^ emailregex = gcnew Regex("/*/");
		//String^ text;
		//String^ test ="1 <color/> 2 <color> 3 </color>";
		//MessageBox::Show("Start parse");
		Match^ m = emailregex->Match( gcnew System::String(this->file.c_str()),start+1);
		//text="";
		//text+="String: "+gcnew System::String(this->file.c_str())+" | ";
		if ( m->Success ) 
		{

			//text=m->Groups["user"]->Value;
			//MessageBox::Show(m->Groups["tag"]->Value->ToString());
			String ^ text_tag=m->Groups["tag"]->Value;
			//MessageBox::Show(text_tag->Length.ToString());
			//MessageBox::Show(text_tag->Substring(text_tag->Length-1,1));
			if(text_tag->Substring(text_tag->Length-2,1)!=""){
			
			xml_Tag *tag1;
			tag1->name=SysToStd(m->Groups["tag"]->Value);
			MessageBox::Show("begin add "+convertStrToChar( tag1->name));
			root->tags.push_back(*tag1);
			MessageBox::Show("Added "+m->Groups["tag"]->Value);
			//MessageBox::Show("Element added");
			if( lastInxdex<m->Index) _getTag(this->root,m->Index);
			}
			else
			{
			  return 0;
			}
			//MessageBox::Show(m->Index.ToString());
			m->NextMatch();
			//return m->Index;

			//text="ok";
			//text->Insert(5, m->Groups["value"]->Value);

		}
		
		//MessageBox::Show("fail");
		return m->Index;
		
		
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

	
	
}; 









//string n="data";
//string v="1234";
//Attr atrreb(n,v);
//Xml_doc xml1();

