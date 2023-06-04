#include <iostream>

using namespace std;

class Base 
{
	protected:

		int grados;
		int minutos;
		int segundos;
	
	public:

		Base(int grad, int min, int seg)
		{
			if (grad > 0 && grad < 359)
			{
				grados = grad;
			}else
			{
				grados = 0;
			}

			if (min > 0 && min < 60)
			{
				minutos = min;
			}else
			{
				minutos = 0;
			}

			if (seg > 0 && seg < 60)
			{
				segundos = seg;
			}else
			{
				segundos = 0;
			}
		}

		Base operator+(Base b)
		{
			int grad, min, seg;
			grad = grados + b.grados;
			min = minutos + b.minutos;
			seg = segundos + b.segundos;

            if (min >= 60){

                min = min%60;
				grad ++;
            }
            if (seg >= 60){
                seg = seg%60;
				min ++;
            }

			

			return Base(grad,min,seg);
		}
		virtual void bienvenida()
		{
			cout << "Bienvenido a la clase Base"<< endl;
		}
		virtual void print()
		{
			cout << "grados: " << grados << endl;
			cout << "minutos: " << minutos << endl;
			cout << "segundos: " << segundos << endl;
	
		}
		friend ostream& operator<<(ostream& out, Base &b)
		{
			b.print();

			return out;
		}
};

class Der: public Base{

	private:
		
		int ciclos;

	public:

    Der(int grad, int min, int seg, int cic = 1):Base(grad, min, seg){
		ciclos = cic;
	}

	Der operator+(Der d)
	{
		int grad, min, seg, cic;
			grad = grados + d.grados;
			min = minutos + d.minutos;
			seg = segundos + d.segundos;
			cic = ciclos + d.ciclos;

            if (min >= 60){

                min = min%60;
				grad ++;
            }
            if (seg >= 60){
                seg = seg%60;
				min ++;
            }
			if (grad >= 360)
			{
				grad = grad % 360;
				ciclos ++;
			}

			return Der(grad,min,seg,cic);

	}

    void bienvenida(){
        cout << "Bienvenido a la clase Der " << endl;
    }

	void print()
	{
		Base::print();
		cout << "ciclos: " << ciclos << endl;
	}
};


int main()
{
	Base b1(12,30,25);
	Base b2(0,40,5);
	Base b3 = b1 + b2;
	Der d1(19,12,22,10);

	cout << b3;
	cout << endl;
	b1.bienvenida();
	d1.bienvenida();
	cout << endl;
	cout << d1;
	return 0;
}