#pragma once
#include"DinamicaJuego.h"
namespace mover5 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			obj = new DinamicaJuego();
			imgJ = gcnew Bitmap("caricaturas.png");
			imgB = gcnew Bitmap("sol2.png");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		DinamicaJuego* obj;
		Bitmap^ imgJ;
		Bitmap^ imgB;
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(564, 388);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::teclado);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::tecla_suelta);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::Black);
		obj->Dinamica(buffer->Graphics, imgJ,imgB);
		buffer->Render(g);
		delete buffer;
		delete espacio;
		delete g;
	};
	private: System::Void teclado(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	
		switch (e->KeyCode)
		{
		case Keys::Left:
			obj->cambiar_direccion(Direcciones::izquierda);
			break;
		case Keys::Right:
			obj->cambiar_direccion(Direcciones::derecha);
			break;
		case Keys::Down:
			obj->cambiar_direccion(Direcciones::abajo);
			break;
		case Keys::Up:
			obj->cambiar_direccion(Direcciones::arriba);
			break;
		case Keys::Space:
			obj->disparar();
			break;
		}
	
	}
	private: System::Void tecla_suelta(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		obj->cambiar_direccion(Direcciones::ninguna);
	}
	};
}