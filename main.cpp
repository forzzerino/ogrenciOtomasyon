#include <iostream>
#include <string>

using namespace std;


class Ogrenci {
    public: string isim;
    public: int numara;
    public: int vizenot;
	public: int finalnot;
    public: Ogrenci* sonraki;
    public: double ortalama;
	    

    
   	Ogrenci(string ad, int num, int vizenot, int finalnot,double ortalama) : isim(ad), numara(num), vizenot(vizenot), finalnot(finalnot), ortalama(ortalama), sonraki(NULL) {}
   	
	string ogrenciDersDurum(){
        ortalama = (vizenot * 0.4) + (finalnot* 0.6);
        if (ortalama >= 50) {
            return "Gecti";
        } else {
            return "Kaldi";
        }
    }
};



class OgrenciOtomasyonSistemi {

    Ogrenci* baslangic; 
    public: OgrenciOtomasyonSistemi() : baslangic(NULL) {}
    
	
    void OgrenciEkle() {
    	int vize, final, durum;
        string isim;
        int numara;
        int vizenot;
        int finalnot;
        double ortalama;
        
		system("cls");
        cout << "Ogrenci Adi: ";
        cin >> isim;

        cout << "Ogrenci Numarasi: ";
        cin >> numara;
        
        cout << "Ogrenci Vize Notu: ";
        cin >> vizenot;
        
        cout << "Ogrenci Final Notu: ";
        cin >> finalnot;

        Ogrenci* yeniOgrenci = new Ogrenci(isim, numara, vizenot, finalnot, ortalama);
        yeniOgrenci->sonraki = baslangic;
        baslangic = yeniOgrenci;
        
        
        
		system("cls");
        cout << "'" << isim << "'" << " Adli Ogrenci eklendi\n\n\n"; 
        //cout << "Numarasi: " << numara << "\n\n\n" << endl;       
	} 
    void OgrenciSil() {
        int numara;
		system("cls");
        cout << "Silmek Istediginiz Ogrenci Numarasi: ";
        cin >> numara;

        Ogrenci* temp = baslangic;
        Ogrenci* onceki = NULL;

        while (temp != NULL && temp->numara != numara) {
            onceki = temp;
            temp = temp->sonraki;
        }

        if (temp == NULL) {
        	system("cls");
            cout << numara << " "<< "Numarali Ogrenci bulunamadi.\n\n\n";
            return;
        }

        if (onceki == NULL) {
            baslangic = temp->sonraki;
        } else {
            onceki->sonraki = temp->sonraki;
        }
		system("cls");
        delete temp;
        cout << numara << " "<< "Numarali Ogrenci Silindi.\n\n\n";
    }
    int OgrenciSayisi() {
    	
        int sayac = 0;
        Ogrenci* temp = baslangic;

        while (temp != NULL) {
            sayac++;
            temp = temp->sonraki;
        }

        return sayac;
    }
    Ogrenci* OgrenciAra(string isim) {
        Ogrenci* temp = baslangic;

        while (temp != NULL) {
            if (temp->isim == isim) {
                return temp;
            }
            temp = temp->sonraki;
        }

        return NULL; // Belirtilen numaraya sahip öðrenci bulunamadý
    }
	void TumOgrencileriListele() {
	        Ogrenci* temp = baslangic;
			system("cls");
			if(baslangic==NULL){
				cout << "Kayitli Ogrenci Yok\n\n\n";
			}
			else{
				cout << "Tum Ogrenciler:\n";
	        while (temp != NULL) {
	        	cout << "*******************************\n";
	            cout << "Ogrenci Ismi: " << temp->isim<< endl;
				cout << "Ogrenci Numarasi: " << temp->numara<< endl;		
				cout << "Ogrencinin Vize Notu: "<< temp->vizenot << endl;
				cout << "Ogrencinin Final Notu: "<< temp->finalnot << endl;
				cout << "Ogrencinin Ders Durumu: "<< temp->ogrenciDersDurum()<<endl;
				cout << "Ortalamasi: " << temp->ortalama << endl;
				cout << "*******************************\n\n";
	            temp = temp->sonraki;
	        }
				
			}
	        
	        cout << endl;
	    }
	void cikis(){
			system("cls");
			cout << "Cikis Yapiliyor.."; 		
		};
};


int main() {
    OgrenciOtomasyonSistemi otomasyon;
	int secim;

    do {
    	cout << "******* Ogrenci Otomasyon Sistemine Hos Geldiniz. -Can Ozturk *******\n\n";
        cout << "1. Yeni Ogrenci Ekle\n";
        cout << "2. Ekli Ogrenci Sil\n";
        cout << "3. Toplam Ogrenci Sayisi Bul\n";
        cout << "4. Ogrenci Ara\n";
        cout << "5. Tum Ogrencileri Listele\n";
        cout << "6. Cikis\n";
		cout << "\n*******************************************************************\n\n";
        cout << "Yapmak Istediginiz Islemi Tuslayin: ";
        cin >> secim;
		
        switch (secim) {
            case 1: {
            	otomasyon.OgrenciEkle();
                break;
			}   
            case 2: {
            	otomasyon.OgrenciSil();
                break;
			}    
            case 3: {
            	system("cls");
                cout << "Sisteme Kayitli Toplam Ogrenci Sayisi: " << otomasyon.OgrenciSayisi() << endl;
                cout << "\n\n" << endl;
                break;
			}   
            case 4: {
            	system("cls");
                string arananAd;
                cout << "Aramak Istediginiz Ogrencinin Adi: ";
                cin >> arananAd;
                Ogrenci* arananOgrenci = otomasyon.OgrenciAra(arananAd);
				system("cls");
                if (arananOgrenci != NULL) {
                	
                    cout << "********Aranan Ogrenci*******" << endl; 
					cout << "Ogrencinin Ismi: "<< arananOgrenci->isim << endl;
					cout << "Ogrencinin Numarasi: "<< arananOgrenci->numara << endl;
					cout << "Ogrencinin Vize Notu: "<< arananOgrenci->vizenot << endl;
					cout << "Ogrencinin Final Notu: "<< arananOgrenci->finalnot << endl;
					cout << "Ogrencinin Ders Durumu: "<< arananOgrenci->ogrenciDersDurum()<<endl;
					cout << "Ortalamasi: " << arananOgrenci->ortalama << endl;
					cout << "*****************************" << endl;
					cout << "\n\n" << endl;
                } else {
                    cout <<arananAd << " Isimli Ogrenci bulunamadi.\n\n" << endl;
                }
                break;
			}
			case 5: {
            	otomasyon.TumOgrencileriListele();
                break;
			}
            case 6: {
            	otomasyon.cikis();
				exit(0);
			}
            default:{
            	system("cls");
            	cout << "Hatali Islem Yaptiniz Lutfen Tekrar Deneyin..\n\n";
				break;
			}	    
        }

    } while (secim != 0);

    return 0;
}

