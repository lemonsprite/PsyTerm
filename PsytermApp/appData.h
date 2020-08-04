#include <stdio.h> // Header definisis printf
#include <string>
#include <iostream>
using namespace std;

#pragma region appData
class appData
{
public:
    const int n_soal = 21;
    const string author = "limepeople";

    string temp;

    string data_soal(int a)
    {
        return rand_soal(a);
    }


    void data_member(int i)
    {
        printf("     #%i [-%i-] ", i + 1, index_member_NIM(i)); cout << index_nama(i) << endl;
    }

    static void psiterm_head()
    {
        cout << " /$$$$$$$   /$$$$$$  /$$     /$$ /$$$$$$$$ /$$$$$$$$ /$$$$$$$  /$$      /$$  " << endl;
        cout << "| $$__  $$ /$$__  $$|  $$   /$$/|__  $$__/| $$_____/| $$__  $$| $$$    /$$$  " << endl;
        cout << "| $$  \\ $$| $$  \\__/ \\  $$ /$$/    | $$   | $$      | $$  \\ $$| $$$$  /$$$$  " << endl;
        cout << "| $$$$$$$/|  $$$$$$   \\  $$$$/     | $$   | $$$$$   | $$$$$$$/| $$ $$/$$ $$  " << endl;
        cout << "| $$____/  \\____  $$   \\  $$/      | $$   | $$__/   | $$__  $$| $$  $$$| $$  " << endl;
        cout << "| $$       /$$  \\ $$    | $$       | $$   | $$      | $$  \\ $$| $$\\  $ | $$  " << endl;
        cout << "| $$      |  $$$$$$/    | $$       | $$   | $$$$$$$$| $$  | $$| $$ \\/  | $$  " << endl;
        cout << "|__/       \\______/     |__/       |__/   |________/|__/  |__/|__/     |__/  " << endl;
        cout << endl;
    }


private:

    // Variabel nim dan soal
    // psaidjwe
    int NIM[5];
    string soal[100], member[5];

    // listing member nim
    int index_member_NIM(int i)
    {
        NIM[0] = 12192831;
        NIM[1] = 12192780;
        NIM[2] = 12192827;
        NIM[3] = 12192801;
        NIM[4] = 12192861;
        return NIM[i];
    }

    // Listing daftar anggota kelompok wawaw
    // array indexing
    string index_nama(int i)
    {
        member[0] = "RYAZ AZHARI FAUZAN";
        member[1] = "GENDRA SYAHRUL SYAH";
        member[2] = "ILMI NURSAPTIANI";
        member[3] = "IPIT FITRIYANI";
        member[4] = "R. NOOR ALFATH KUSVIDIA NUGRAHA";
        return member[i];
    }


    string rand_soal(int i)
    {
        // - Gak juga
        // - Pada saat tertentu atau kadang-kadang
        // - Hmm, lumayan sering
        // - sangat sering


         // Deklarasi soal aplikasi
        soal[0] = "Apakah kamu merasa sulit istirahat?";
        soal[1] = "Apakah kamu selalu berlebihan dalam melakukan sesuatu (Over-Reacted)?";
        soal[2] = "Apa kamu merasa gugup sekarang?";
        soal[3] = "Apa saat ini kamu sedang GGM (Gelisah, Galau, Merana)?";
        soal[4] = "Apa kamu merasa sulit untuk bersantai dan relax?";
        soal[5] = "Apakah kamu tidak suka saat aktivitas atau pekerjaan kamu diganggu?";
        soal[6] = "Apa kamu termasuk tipe orang yang sensitif?";

        // Soal bagian kedua
        soal[7] = "Mulut kamu terasa kering belakangan ini?";
        soal[8] = "Apa kamu merasa sesak nafas, padahal tidak melakukan aktivitas berat?";
        soal[9] = "Apakah tangan kamu bergetar sendiri, seperti menggigil?";
        soal[10] = "Apa kamu memiliki masalah yang membuat kamu gugup atau ketakutan?";
        soal[11] = "Apa kamu takut mempermalukan diri sendiri jika berinteraksi dengan orang lain?.";
        soal[12] = "Apakah kamu selalu merasa panik saat ada sesuatu yang mengejutkan?";
        soal[13] = "Apa kamu merasa takut tanpa ada alasan yang jelas?";

        // Soal bagian ketiga
        soal[14] = "Apa kamu merasa tidak bahagia belakangan ini?";
        soal[15] = "Apakah kamu sulit berinisiatif untuk melakukan sesuatu?";
        soal[16] = "Apakah kamu merasa hidupmu suram dan tidak ada lagi harapan?";
        soal[17] = "Apa kamu sedang sedih dan galau?";
        soal[18] = "Apa kamu kesulitan untuk antusias dalam suatu hal?";
        soal[19] = "Apa kamu merasa tidak guna untuk orang lain?";
        soal[20] = "Apakah kamu pernah merasa jika hidupmu tidak berguna?";

        return soal[i];
    }

};
#pragma endregion