#include "BankLibrary.h"
ostream& operator<<(ostream& cikti, Banka& obj1) {
	cikti << obj1.hesapNoo << " " << obj1.ad << " " << obj1.soyad << " " << obj1.bakiye << endl; //yazilanDosya<<obj1.ad<<" "<<obj1.soyad<<" "<<obj1.note<<endl;
	return cikti;
}
void hesapekle() {
	Banka kisi;
	cout << "Adinizi Giriniz..";
	cin >> kisi.ad;
	cout << "Soyadinizi Giriniz..";
	cin >> kisi.soyad;
	static int hesapNum = 5000;
	hesapNum++;
	kisi.bakiye = 0;
	kisi.hesapNoo = hesapNum;
	cout << "Size verdigimiz hesap numaraniz : " << kisi.hesapNoo << endl;
	fstream bilgileriGecir;
	bilgileriGecir.open("BankaKayýtBilgileri.txt", ios::out | ios::app);
	bilgileriGecir << kisi;
	bilgileriGecir.close();
	
}
void hesapgoster(int hspNo) {

	fstream bilgileriListele;
	Banka kisi;
	bilgileriListele.open("BankaKayýtBilgileri.txt", ios::in);
	while (bilgileriListele >> kisi.hesapNoo) {
		if (kisi.hesapNoo == hspNo) {
			bilgileriListele >> kisi.ad >> kisi.soyad >> kisi.bakiye;
			cout << kisi.hesapNoo << " " << kisi.ad << " " << kisi.soyad << " " << kisi.bakiye << endl;
		}
		else {
			bilgileriListele >> kisi.ad >> kisi.soyad >> kisi.bakiye;
		}
	}
	bilgileriListele.close();

}
void hesapguncelle(int hspNo) {

}
void hesapsil(int hspNo) {
	fstream bilgileriListele, bilgiAktar;
	Banka kisi;
	bilgileriListele.open("BankaKayýtBilgileri.txt", ios::in);
	bilgiAktar.open("BankaKayýtBilgileri2.txt", ios::out);


	while (bilgileriListele >> kisi.hesapNoo) {
		if (kisi.hesapNoo != hspNo) {
			bilgileriListele >> kisi.ad;
			bilgileriListele >> kisi.soyad;
			bilgileriListele >> kisi.bakiye;
			bilgiAktar << kisi;

		}
		else {
			bilgileriListele >> kisi.ad >> kisi.soyad >> kisi.bakiye;
		}
	}
	bilgileriListele.close();
	bilgiAktar.close();
	remove("BankaKayýtBilgileri.txt");
	rename("BankaKayýtBilgileri2.txt", "BankaKayýtBilgileri.txt");
}
void parayatir(int hspNo) {
	fstream bilgileriListele, bilgiAktar;
	Banka kisi;
	bilgileriListele.open("BankaKayýtBilgileri.txt", ios::in);
	bilgiAktar.open("BankaKayýtBilgileri2.txt", ios::out);

	int tutar = 0;
	cout << "Yatirmak Istediginiz Tutari Giriniz..";
	cin >> tutar;

	while (bilgileriListele >> kisi.hesapNoo) {
		if (kisi.hesapNoo == hspNo) {
			bilgileriListele >> kisi.ad;
			bilgileriListele >> kisi.soyad;
			bilgileriListele >> kisi.bakiye;
			kisi.bakiye += tutar;
			bilgiAktar << kisi;
		}
		else {
			bilgileriListele >> kisi.ad;
			bilgileriListele >> kisi.soyad;
			bilgileriListele >> kisi.bakiye;
			bilgiAktar << kisi;
		}
	}
	bilgileriListele.close();
	bilgiAktar.close();
	remove("BankaKayýtBilgileri.txt");
	rename("BankaKayýtBilgileri2.txt", "BankaKayýtBilgileri.txt");
}
void paracek(int hspNo) {
	fstream bilgileriListele, bilgiAktar;
	Banka kisi;
	bilgileriListele.open("BankaKayýtBilgileri.txt", ios::in);
	bilgiAktar.open("BankaKayýtBilgileri2.txt", ios::out);

	int tutar = 0;
	cout << "Cekmek Istediginiz Tutari Giriniz..";
	cin >> tutar;
	while (bilgileriListele >> kisi.hesapNoo) {
		if (kisi.hesapNoo == hspNo) {
			bilgileriListele >> kisi.ad;
			bilgileriListele >> kisi.soyad;
			bilgileriListele >> kisi.bakiye;
			if ((kisi.bakiye - tutar) >= 0) {
				kisi.bakiye -= tutar;
				bilgiAktar << kisi;
			}
			else {
				cout << "O kadar bakiyeniz yok" << endl;
				return;
			}
		}
		else {
			bilgileriListele >> kisi.ad;
			bilgileriListele >> kisi.soyad;
			bilgileriListele >> kisi.bakiye;
			bilgiAktar << kisi;
		}
	}
	bilgileriListele.close();
	bilgiAktar.close();
	remove("BankaKayýtBilgileri.txt");
	rename("BankaKayýtBilgileri2.txt", "BankaKayýtBilgileri.txt");
}
void tumlisteyigoster() {
	fstream bilgileriListele;
	Banka kisi;
	bilgileriListele.open("BankaKayýtBilgileri.txt", ios::in);
	while (bilgileriListele >> kisi.hesapNoo) {
		bilgileriListele >> kisi.ad >> kisi.soyad >> kisi.bakiye;
		cout << kisi.hesapNoo << " " << kisi.ad << " " << kisi.soyad << " " << kisi.bakiye << endl;
	}
}