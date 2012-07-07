#pragma once



namespace XML_parser {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TreeView^  treeView1;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(388, 236);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(143, 174);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Выход";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 12);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(519, 218);
			this->textBox1->TabIndex = 1;
			// 
			// treeView1
			// 
			this->treeView1->Location = System::Drawing::Point(12, 236);
			this->treeView1->Name = L"treeView1";
			this->treeView1->Size = System::Drawing::Size(370, 174);
			this->treeView1->TabIndex = 2;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(543, 422);
			this->Controls->Add(this->treeView1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Shown += gcnew System::EventHandler(this, &Form1::Form1_Shown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion




	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				 Close();

			 }
			 int genTree(xml_Tag *tag){

				 if( tag->tags.empty()) MessageBox::Show("No tags");

				 // пройдём по списку в цикле

				 for(list<xml_Tag>::iterator  i = tag->tags.begin();  i != tag->tags.end(); i++)
				 {

					 MessageBox::Show("Start");
					 String^ x;
					 x=Xml_doc::convertStrToChar( i->name );
					 //treeView1->Nodes->Add(x); 
					 MessageBox::Show(x);

					 if(i->tags.empty())
					 {
						 xml_Tag *tag2;
						 tag2->tags=i->tags;
						 genTree(tag2);
					 }
				 }

				 return 0;
			 }

	private: System::Void Form1_Shown(System::Object^  sender, System::EventArgs^  e) {
				 //textBox1->Text=Xml_doc:: getTag();			
				 Xml_doc xml1;
				 textBox1->Text=gcnew System::String(xml1.file.c_str());
				 treeView1->Nodes->Add("dsfsdfsdf");
				 xml1.parse();
				 genTree(xml1.root);
			 }
	};
}

