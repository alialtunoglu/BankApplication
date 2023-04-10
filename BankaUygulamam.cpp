#include "BankLibrary.h"

int main()
{
	
	
	cout << "<-- Banka islemlerine hosgeldiniz --> " << endl;
	cout << "Hesap olusturmak icin -> 1 " << endl;
	cout << "Hesap goruntulemek icin -> 2 " << endl;
	cout << "Hesap guncelleme icin -> 3 " << endl;
	cout << "Hesap silme icin -> 4 " << endl;
	cout << "Hesaba para yatirma icin -> 5 " << endl;
	cout << "Hesabtan para cekme icin -> 6 " << endl;
	cout << "Tum hesapları goruntulemek icin -> 7 " << endl;
	cout << "Cikis icin -> 8 " << endl;
	int hesapNo;
	char secim = 0;

	while (true) {

		cout << "Yapmak istediginiz islemi seciniz " << endl;
		cin >> secim;
		switch (secim)
		{
		case '1': hesapekle(); break;
		case '2': cout << "Goruntulenecek hesap no giriniz:" << endl; cin >> hesapNo;
			hesapgoster(hesapNo); break;
		case '3': cout << "Guncellenecek hesap no giriniz:" << endl; cin >> hesapNo;
			hesapguncelle(hesapNo); break;
		case '4': cout << "Silinecek hesap no giriniz:" << endl; cin >> hesapNo;
			hesapsil(hesapNo); break;
		case '5': cout << "Hesap No giriniz:" << endl; cin >> hesapNo;
			parayatir(hesapNo); break;
		case '6': cout << "Hesap No giriniz:" << endl; cin >> hesapNo;
			paracek(hesapNo); break;
		case '7': tumlisteyigoster(); break;
		case '8':cout << "isleminiz tamamlanmistir." << endl; exit(0); break;
		default: cout << "yanlis secim " << endl; break;
		}
	}
	
	



	return 0;
}
