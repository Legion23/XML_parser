#include <string>


using namespace std;


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


