#pragma warning(disable : 4996)
#pragma warning(disable : 4786)

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string> 

// Custom Header
#include "appData.h"
#include "appSet.h"

using namespace std;

int main()
{
    appSetting s;
    appData d;

    // Inisiasi variabel aplikasi
    int jawaban = 0;
    int state_jawaban = 0;

    bool cur_state = false;

    // Memori alokator dan deklarasi variabel
    float* persentase = new float[3];
    float* data = new float[5];
    float pstats = 0;

    string nama_user;


    // Dashboard Aplikasi
    appData::psiterm_head();

    system("color f0");
    cout << "* ----------------------------------------------------------------------" << endl;
    cout << "* Selamat Datang di Aplikasi PsyTerm" << endl;
    cout << "* ----------------------------------------------------------------------" << endl;
    cout << "* -   Dikembangkan oleh " << d.author << endl;
    cout << "* -   dan dikembangkan berdasar konsep permainan survey." << endl << endl;
    cout << "* -   https://github.com/lemonsprite" << endl;
    cout << "* ----------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Tekan apa saja untuk melanjutkan . . .";
    _getch();

    system("cls");
    appData::psiterm_head();
    cout << appSetting::separator() << endl << endl;
    s.alert("Siapa nama anda : ");
    getline(cin, nama_user);

    // Clearing screen dan inputing nama user saat ini
    // Exception kalo nama null
    while (nama_user == "")
    {
        system("cls");
        system("color 4f");
        appData::psiterm_head();
        cout << appSetting::separator() << endl << endl;
        s.info("Harap masukan nama anda terlebih dahulu . . ."); cout << endl << endl;
        s.alert("Siapa nama anda : ");
        getline(cin, nama_user);
    }

    while (s.appstate)
    {
        system("color f0");

        // Main app fitur start

        // app validator input menu...
        // input exception
        #pragma region App Dashboard
        do
        {
            system("cls");
            appData::psiterm_head();
            cout << appSetting::separator() << endl;
            cout << "| Menu Aplikasi" << endl;
            cout << appSetting::separator() << endl;

            // Dashboard Menu
            if (nama_user == "DEV" || nama_user == "Dev" || nama_user == "dev")
            {
                cout << "| 1. Mulai Test" << endl;
                cout << "| 2. Tentang Kami" << endl;
                cout << "| 3. Lihat Point Dan Statistik Terakhir" << endl;
                cout << "| " << endl;
                cout << "| 0. Keluar Aplikasi" << endl;
                cout << "| (Developer-Mode) Masukan -1 untuk detail stats" << endl;
                cout << appSetting::separator() << endl << endl;
            }
            else {
                cout << "| 1. Mulai Test" << endl;
                cout << "| 2. Tentang Kami" << endl;
                cout << "| 3. Lihat Point Dan Statistik Terakhir" << endl;
                cout << "| " << endl;
                cout << "| 0. Keluar Aplikasi" << endl;
                cout << appSetting::separator() << endl << endl;
            }

            // Muncul notif kalau input salah
            if (s.menu > s.n_menu || s.cin_state == true)
            {
                system("color 4f");
                s.alert("Menu tidak valid! input kembali katalog dengan valid."); cout << endl << endl;
            }
            // Sapa user dengan hangat
            cout << "[System Info] " << s.sapaan(s.jam()) << nama_user << "!" << endl;

            // Input Data dan checking data menu
            // Re-Looping lamun fungsi error
            s.info("Menu apa yang akan anda gunakan? "); cin >> s.menu;
            s.cin_state = cin.fail();
            if (s.cin_state)
            {
                cin.clear();
                cin.ignore(100, '\n');
            }

            if (s.menu > s.n_menu)
                s.cin_state = true;
        } while (s.cin_state);
        #pragma endregion

        // Script Lolos validasi
        // App routing

        system("color f0");
        switch (s.menu)
        {
        case 1:
            #pragma region Menu: MulaiApp
            system("cls");
            appData::psiterm_head();
            cout << appSetting::separator() << endl;

            // Netralisasi variabel dinamis
            // Hapus memori tersimpan
            // Statement validator (Menu 3)
            s.epoint = s.kpoint = s.dpoint = state_jawaban = pstats = 0;

            cur_state = true;
            delete[] persentase;
            delete[] data;

            // Inisiasi array dinamis
            // Alokasi memori array baru
            persentase = new float[3];
            data = new float[5];

            // Pennjelasan aturan main dan range jawaban
            // Baca oke..
            cout << "Aturan Main :" << endl;
            cout << "   # Ini adalah aplikasi bidang kesehatan, dengan metode survey." << endl;
            cout << "     Dimana aplikasi akan memberikan anda beberapa pertanyaan dan menganalisis" << endl;
            cout << "     setiap jawaban yang anda berikan" << endl << endl;

            cout << "   # Jumlah pertanyaan yang akan diberikan pada anda, sebanyak " << d.n_soal << " soal." << endl;
            cout << "     untuk itu jawablah pertanyaan dengan baik dan benar." << endl << endl;

            cout << "   # Terima kasih sudah membaca aturan main, " << nama_user << "!" << endl;
            cout << appSetting::separator() << endl;
            _getch();

            cout << endl << nama_user << ", range jawaban yang dapat kamu gunakan adalah:" << endl;
            cout << "   1. Gak juga" << endl;
            cout << "   2. Pada saat tertentu atau kadang-kadang" << endl;
            cout << "   3. Hmm, lumayan sering" << endl;
            cout << "   4. Wow mejik!! atau benar sekali" << endl;
            cout << appSetting::separator() << endl;

            cout << endl << "Sudah mengerti!? Silahkan tekan apa saja untuk lanjut ke permainan . . ." << endl;
            _getch();

            // Looping soal dan counting point
            // User nerima point sama trus di-sum keseluruhan
            // filtering point
            for (int i = 0; i < d.n_soal; i++)
            {
                system("cls");
                appData::psiterm_head();
                cout << appSetting::separator() << endl;
                cout << "| Test Psikis" << endl;
                cout << appSetting::separator() << endl;
                cout << "| " << s.sapaan(s.jam()) << nama_user << "!" << endl;
                cout << "| Range jawaban yang dapat digunakan di aplikasi ini adalah :" << endl;
                cout << "|    1. Gak juga" << endl;
                cout << "|    2. Sedikit pada saat tertentu atau kadang-kadang" << endl;
                cout << "|    3. Hmm, lumayan" << endl;
                cout << "|    4. Mejik, Itu sering  atau benar sekali" << endl;
                cout << appSetting::separator() << endl << endl;
                //k Print soal ke terminal
                // tapi kudu check kategori ...

                // Deklarasi kategori trus stor ke kategori state

                if (i < 7)
                {
                    s.kategori_state[i] = s.kategori_id(1);
                    printf("[System Question #%i] ", i + 1); cout << nama_user << ", " << d.data_soal(i) << endl;
                }
                else if (i >= 7 && i < 14)
                {
                    s.kategori_state[i] = s.kategori_id(2);
                    printf("[System Question #%i] ", i + 1); cout << nama_user << ", " << d.data_soal(i) << endl;
                }
                else if (i >= 14 && i < d.n_soal)
                {
                    s.kategori_state[i] = s.kategori_id(3);
                    printf("[System Question #%i] ", i + 1); cout << nama_user << ", " << d.data_soal(i) << endl;
                }



                // test jawaban supaya tidak ngasih value yang salah
                // escaping kalo jawaban bukan int ??
                // referensi stackoverflow
                do
                {
                    printf("[System Answer] "); cin >> jawaban;

                    s.cin_state = cin.fail();
                    if (s.cin_state)
                    {
                        cin.clear();
                        cin.ignore(100, '\n');
                    }

                    while (jawaban > 4 || jawaban == 0)
                    {
                        s.alert("Jawaban teu aya dina list! ulang deui nya. . ."); cout << endl;
                        printf("[System Re-Answer] "); cin >> jawaban;

                        s.cin_state = cin.fail();
                        if (s.cin_state)
                        {
                            cin.clear();
                            cin.ignore(100, '\n');
                        }
                    }
                } while (s.cin_state);


                // Logika tambahan untuk hitung point
                jawaban = jawaban - 1;


                // Point jawaban masuk ke kategori point
                // check kategori trus store ke variabel state kategori
                // Filtering
                if (s.kategori_state[i] == 'E')
                    s.epoint = s.epoint + jawaban;
                else if (s.kategori_state[i] == 'K')
                    s.kpoint = s.kpoint + jawaban;
                else if (s.kategori_state[i] == 'D')
                    s.dpoint = s.dpoint + jawaban;
            }
            state_jawaban = s.epoint + s.kpoint + s.dpoint;


            // Bersihin layar terus generate analisis jawaban.. aaaaa jangar..
            // Algoritma Point + point Fixer
            system("cls");

            persentase[0] = s.epoint / 21;
            persentase[1] = s.kpoint / 21;
            persentase[2] = s.dpoint / 21;

            data[0] = persentase[0] * 200;
            data[1] = persentase[1] * 200;
            data[2] = persentase[2] * 200;

            // Kudu include algoritma point jeng point fixer
            // Databar bruh . . .
            appData::psiterm_head();
            cout << appSetting::separator() << endl << endl;
            cout << "Tingkat Potensi Emosional Anda : " << endl;
            s.databar(data[0]);
            cout << "Tingkat Potensi Kecemasan Anda : " << endl;
            s.databar(data[1]);
            cout << "Tingkat Potensi Depresi Anda : " << endl;
            s.databar(data[2]);

            // Tips dan Saran aplikasi dari analisis
            cout << appSetting::separator() << endl;
            cout << "TIPS DAN SARAN UNTUK ANDA" << endl;
            cout << appSetting::separator() << endl;


            // Uraian tips dan trick
            // Di copy ke bagean statistik
            pstats = ((s.datac(data[0]) * 0.5) + (s.datac(data[1]) * 0.2) + (s.datac(data[2]) * 0.3)) - 9;

            cout << endl;
            cout << "------------------------------------------------------------------" << endl;
            cout << "Psiko-Point anda adalah : " << s.statistik_sum(pstats) << endl;
            cout << "--------------------------" << endl;


            // Berdasar psikopoint
            if (s.statistik_sum(pstats) <= 10)
            {
                cout << "Dilihat dari psiko-point, Anda tidak memiliki sedang mengalami permasalahan mental" << endl;
                cout << "apapun. Karena semuanya masih dalam tingakt wajar." << endl;

                cout << endl;
                s.xemosi(s.datac(data[0]));
                cout << endl;
                s.xcemas(s.datac(data[1]));
                cout << endl;
                s.xdepres(s.datac(data[2]));

            }
            else if (s.statistik_sum(pstats) > 10 && s.statistik_sum(pstats) <= 20)
            {
                cout << "Tingkat psiko-point anda lumayan tinggi, dan hal ini perlu anda perhatikan lebih lanjut," << endl;
                cout << "karena mungkin dengan tingkat psikopoint yang lumyan tinggi dapat mengganggu mental anda" << endl;
                cout << "Beberapa hal dapat anda lakukan untuk mengatasi hal tersebut :" << endl;
                cout << "    # Kurangi aktivitas berat anda" << endl;
                cout << "    # Perbaiki pola tidur anda" << endl;
                cout << "    # Perbanyak beribadah" << endl;
                cout << "    # Konsultasikan dengan terapis, keluarga, atau teman dekat anda" << endl;

                cout << endl;
                s.xemosi(s.datac(data[0]));
                cout << endl;
                s.xcemas(s.datac(data[1]));
                cout << endl;
                s.xdepres(s.datac(data[2]));
            }
            else
            {
                cout << "Tingkat psiko-point anda tinggi, dan hal ini perlu anda perhatikan lebih lanjut," << endl;
                cout << "karena mungkin dengan tingkat psikopoint yang tinggi dapat mempengaruhi mental anda." << endl;
                cout << "dan mungkin berdampak pada orang di sekitar anda juga. Beberapa hal dapat anda" << endl;
                cout << "lakukan untuk mengatasi hal tersebut :" << endl;
                cout << "    # Perbaiki pola tidur anda" << endl;
                cout << "    # Perbanyak beribadah" << endl;
                cout << "    # Konsultasikan dengan terapis, keluarga, atau teman dekat anda" << endl;
                cout << "    # Perbanyak berpuasa" << endl;
                cout << "    # Hindari aktivitas yang melibatkan orang banyak" << endl;

                cout << endl;
                s.xemosi(s.datac(data[0]));
                cout << endl;
                s.xcemas(s.datac(data[1]));
                cout << endl;
                s.xdepres(s.datac(data[2]));
            }

            cout << endl << endl;
            cout << "Tekan apa saja untuk kembali ke dashboard... " << endl;

            _getch();
            break;
            #pragma endregion

        case 2:
            #pragma region Menu: Tentang Kami
            // Rendering System About
            system("cls");
            appData::psiterm_head();
            cout << appSetting::separator() << endl;
            cout << "| Tentang Kami" << endl;
            cout << appSetting::separator() << endl;
            cout << "Ini aplikasi permainan sederhana yang dibuat untuk survey." << endl;

            cout << endl << endl;
            cout << "Terima kasih " << nama_user << "! Sudah mencoba aplikasi saya. (\\*v*)/" << endl << endl;
            cout << "Developer Aplikasi," << endl;
            cout << d.author<< endl;
            cout << appSetting::separator();

            cout << endl << endl;
            cout << "Tekan apa saja untuk kembali ke dashboard. . .";
            _getch();
            break;
            #pragma endregion

        case 3:
            #pragma region Menu: Poin
            system("cls");
            appData::psiterm_head();
            if (s.epoint == 0 && s.kpoint == 0 && s.dpoint == 0 && cur_state == false)
            {
                cout << appSetting::separator() << endl;
                cout << "|    # Anda belum menjalankan Test Psikis silahkan ikuti tes terlebih dahulu." << endl;
                cout << "|      Untuk menggunakan fitur ini Silahkan ikuti test." << endl;
                cout << "|" << endl;
                cout << "|    # Info : Isi Test dengan jujur agar statistik lebih optimal." << endl;
                cout << appSetting::separator() << endl << endl;

                cout << "Tekan Apa saja untuk kembali ke dashboard . . .";

                _getch();

            }
            else
            {

                // Kudu include algoritma point jeng point fixer
                // Databar bruh . . .

                cout << appSetting::separator() << endl << endl;
                cout << "Tingkat Potensi Emosional Anda : " << endl;
                s.databar(data[0]);
                cout << "Tingkat Potensi Kecemasan Anda : " << endl;
                s.databar(data[1]);
                cout << "Tingkat Potensi Depresi Anda : " << endl;
                s.databar(data[2]);
                cout << appSetting::separator() << endl;
                cout << "Tips dan Saran" << endl;
                cout << appSetting::separator() << endl;


                cout << endl;
                cout << "------------------------------------------------------------------" << endl;
                cout << "Psiko-Point anda adalah : " << s.statistik_sum(pstats) << endl;
                cout << "--------------------------" << endl;


                // Berdasar psikopoint
                if (s.statistik_sum(pstats) <= 10)
                {
                    cout << "Dilihat dari psiko-point, Anda tidak memiliki sedang mengalami permasalahan mental" << endl;
                    cout << "apapun. Karena semuanya masih dalam tingakt wajar." << endl;

                    cout << endl;
                    s.xemosi(s.datac(data[0]));
                    cout << endl;
                    s.xcemas(s.datac(data[1]));
                    cout << endl;
                    s.xdepres(s.datac(data[2]));

                }
                else if (s.statistik_sum(pstats) > 10 && s.statistik_sum(pstats) <= 20)
                {
                    cout << "Tingkat psiko-point anda lumayan tinggi, dan hal ini perlu anda perhatikan lebih lanjut," << endl;
                    cout << "karena mungkin dengan tingkat psikopoint yang lumyan tinggi dapat mengganggu mental anda" << endl;
                    cout << "Beberapa hal dapat anda lakukan untuk mengatasi hal tersebut :" << endl;
                    cout << "    # Kurangi aktivitas berat anda" << endl;
                    cout << "    # Perbaiki pola tidur anda" << endl;
                    cout << "    # Perbanyak beribadah" << endl;
                    cout << "    # Konsultasikan dengan terapis, keluarga, atau teman dekat anda" << endl;

                    cout << endl;
                    s.xemosi(s.datac(data[0]));
                    cout << endl;
                    s.xcemas(s.datac(data[1]));
                    cout << endl;
                    s.xdepres(s.datac(data[2]));
                }
                else
                {
                    cout << "Tingkat psiko-point anda tinggi, dan hal ini perlu anda perhatikan lebih lanjut," << endl;
                    cout << "karena mungkin dengan tingkat psikopoint yang tinggi dapat mempengaruhi mental anda." << endl;
                    cout << "dan mungkin berdampak pada orang di sekitar anda juga. Beberapa hal dapat anda" << endl;
                    cout << "lakukan untuk mengatasi hal tersebut :" << endl;
                    cout << "    # Perbaiki pola tidur anda" << endl;
                    cout << "    # Perbanyak beribadah" << endl;
                    cout << "    # Konsultasikan dengan terapis, keluarga, atau teman dekat anda" << endl;
                    cout << "    # Perbanyak berpuasa" << endl;
                    cout << "    # Hindari aktivitas yang melibatkan orang banyak" << endl;

                    cout << endl;
                    s.xemosi(s.datac(data[0]));
                    cout << endl;
                    s.xcemas(s.datac(data[1]));
                    cout << endl;
                    s.xdepres(s.datac(data[2]));
                }

                cout << endl << endl;
                cout << "Tekan apa saja untuk kembali ke dashboard... " << endl;

                _getch();
            }
            break;
            #pragma endregion

        case 0:
            // Close aplikasi
            s.appstate = false;
            break;

        case -1:
            #pragma region Menu: Debug
            // Debugging area
            // Testing + Variabel checking
            cout << endl;
            cout << "--------------------------------------------------------------" << endl;
            cout << "Debuging Area & Point Stats" << endl;
            cout << "-----------------------------" << endl;

            // Cek system sapa
            cout << endl;
            cout << "Sapaan saat ini : " << s.sapaan(s.jam()) << endl;

            // Kategori soal check
            cout << endl;
            cout << "Lookup kode :" << endl;
            for (int i = 0; i < d.n_soal; i++)
            {
                cout << "    " << i + 1 << ") " << s.kategori_state[i] << endl;
            }

            // Point variabel check
            cout << endl;
            cout << "Total Point : " << state_jawaban << endl;
            cout << "E-Point     : " << s.epoint << endl;
            cout << "K-Point     : " << s.kpoint << endl;
            cout << "D-Point     : " << s.dpoint << endl;

            // Algoritma Program
            // Generate Floater tina rata"
            persentase[0] = s.epoint / 21;
            persentase[1] = s.kpoint / 21;
            persentase[2] = s.dpoint / 21;

            // Floater Scaling
            data[0] = persentase[0] * 200;
            data[1] = persentase[1] * 200;
            data[2] = persentase[2] * 200;

            cout << endl;
            cout << "Data Point dan Floater" << endl;
            cout << "    Data #1 : " << data[0] << endl;
            cout << "    Data #2 : " << data[1] << endl;
            cout << "    Data #3 : " << data[2] << endl;

            // Method class Cek
            cout << endl;
            cout << "Cek method class :" << endl << endl;
            cout << "s.datac(float data) : " << endl;
            cout << "    #1-> " << s.datac(data[0]) << endl;
            cout << "    #2-> " << s.datac(data[1]) << endl;
            cout << "    #3-> " << s.datac(data[2]) << endl;

            // Databar Debuging
            cout << endl;
            cout << "s.databar(float data)" << endl;
            s.databar(data[0]);
            s.databar(data[1]);
            s.databar(data[2]);

            // Cek Psikopoint Maks
            cout << endl;
            cout << "Psiko-Point Cek" << endl;

            cout << "| " << s.statistik_sum(pstats) << " |";

            cout << endl << endl;
            cout << "Tekan apa saja untuk melanjutkan . . ." << endl;
            _getch();
            break;
            #pragma endregion

        }
    }

    system("cls");
    system("color e");
    appData::psiterm_head();
    cout << appSetting::separator() << endl;
    cout << "Terima kasih karena telah menggunakan aplikasi ane." << endl;
    cout << endl << endl;

}