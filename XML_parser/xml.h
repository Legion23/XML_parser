#include <string>


using namespace std;


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


