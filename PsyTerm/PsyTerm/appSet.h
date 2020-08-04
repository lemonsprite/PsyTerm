#include <ctime> // Header definisi time
#include <iomanip> //Header definisi setprecision
#include <string>
#include <iostream>

using namespace std;

#pragma region appSetting
class appSetting
{
public:

    // Variabel kelas config
    // Masih perlu tambahan ??
    float epoint = 0;
    float kpoint = 0;
    float dpoint = 0;

    int menu = -1;
    int n_menu = 3;


    bool cin_state = false;
    bool appstate = true;

    string sapa;

    char kategori, kategori_state[100];


    static string separator()
    {
        return "----------------------------------------------------------------------";
    }


    // grouping soal
    char kategori_id(int t)
    {
        // switch casing kategori moal dikasih exception
        // moga2 moal aya bug wkwkwk
        switch (t)
        {
        case 1:
            kategori = 'E';
            break;
        case 2:
            kategori = 'K';
            break;
        case 3:
            kategori = 'D';
            break;
        }
        return kategori;
    }

    // Insiasi jam sabaraha ayna trus return integer ker masuk filter
    int jam()
    {
        time_t ayna = time(0);
        tm* h = localtime(&ayna);

        return h->tm_hour;
    }

    // Filtering jam sabraha trus nyapa user
    // Enak e...
    string sapaan(int jam)
    {
        if (jam >= 5 && jam < 10)
        {
            sapa = "Selamat Pagi, ";
        }
        else if (jam >= 10 && jam < 17)
        {
            sapa = "Selamat Siang, ";
        }
        else if (jam >= 17 || jam < 5)
        {
            sapa = "Selamat malam, ";
        }
        return sapa;
    }

    // Prefix dialog info
    void info(string i)
    {
        cout << "[System Info] " << i;
    }

    // Prefix dialog peringatan
    // akhiran line
    void alert(string i)
    {
        cout << "[System Warning] " << i;
    }

    float datac(float a)
    {
        float stat;
        stat = (((a / 5) / 40) * 100) - 1;
        if (stat == -1)
        {
            stat = 0;
        }
        return stat;
    }

    void databar(float data)
    {
        int a = 1;
        cout << "--------------------------------------------" << endl;
        cout << "| ";
        while (a <= (data / 5))
        {
            cout << "#";
            a++;
        }
        // Rumus persen data
        // data dinamis/data maks * 100;
        cout << " | " << setprecision(3) << datac(data) << "%";
        cout << endl << "--------------------------------------------" << endl << endl;
    }

    float statistik_sum(float a)
    {
        float data = a / 3;
        return data;
    }

    void xcemas(float cemas)
    {
        if (cemas > 35 && cemas <= 60)
        {
            cout << "Tapi jika dilihat dari tingkat kecemasan anda yang lumayan tinggi, ada beberapa" << endl;
            cout << "saran yang dapat anda jalankan untuk mengurangi rasa cemas anda :" << endl;
            cout << "   # Dekatkan diri kepada Tuhan dan Perbanyak memohon ampun padanya" << endl;
            cout << "   # Hindarkan diri anda dari sumber masalah yang berkaitan dengan orang banyak" << endl;
            cout << "   # Hindarkan diri anda dari keramaian" << endl;
            cout << "   # carilah aktivitas yang membuat anda senang." << endl;
        }
        else if (cemas > 60)
        {
            cout << "Namun, jika dilihat dari tingkat kecemasan anda yang sangat tinggi, anda perlu" << endl;
            cout << "lebih memperhatikan kesehatan anda secara mental, dan anda dapat mengikuti tips" << endl;
            cout << "berikut untuk mengurangi tingkat kecemasan anda :" << endl;
            cout << "   # Ketahui sumber masalah anda, dan Mintalah bantuan kepada teman curhat anda" << endl;
            cout << "   # Perbanyak berolahraga, agar pikiran anda teralihkan dengan aktivitas anda" << endl;
            cout << "   # Perbanyak beribadah dan memohon ampunan kepada Tuhan." << endl;
            cout << "   # Perbaiki pola tidur anda" << endl;
            cout << "   # Hindari meminum minuman yang mengandung kafein dan dopping lainya" << endl;
        }
    }

    void xemosi(float emosi)
    {
        if (emosi > 35 && emosi <= 60)
        {
            cout << "Point emosi anda yang lumayan tinggi tersebut mungkin anda merasa biasa saja, karena" << endl;
            cout << "mungkin tidak akan berpengaruh pada orang sekitar, namun tanpa anda sadari dari tingkat" << endl;
            cout << "emosi anda yang lumayan  tinggi tersebut mengganggu orang sekitar anda. Maka dari itu hal" << endl;
            cout << "ini perlu lebih anda perhatikan, dan ikuti saran berikut untuk mengurangi tingkat emosi anda :" << endl;
            cout << "   # Hindarkan diri anda dari permasalahan yang menyangkut orang banyak" << endl;
            cout << "   # Belajar untuk menerima segala situasi dalam keadaan tenang" << endl;
            cout << "   # Perbanyak rekreasi ke alam bebas" << endl;
            cout << "   # Alihkan pikiran dengan sesuatu yang membuat anda tenang" << endl;
        }
        else if (emosi > 60)
        {
            cout << "Jika dilihat dari tingkat emosi anda yang tinggi anda perlu memperhatikan hal ini karena" << endl;
            cout << "mungkin tanpa sadar emosi anda yang tinggi tersebut berdampak pada keluarga, teman, atau" << endl;
            cout << "lingkungan anda. Dan beberapa saran untuk anda agar bisa mengurangi tingkat emosi anda:" << endl;
            cout << "   # Seringlah intropeksi diri dan sadari setiap kesalahan anda" << endl;
            cout << "   # berzikir dan mengingat tuhan setiap waktu" << endl;
            cout << "   # Berpuasa dan belajar menahan diri dari hawa nafsu" << endl;
            cout << "   # Hindarkan diri anda dari hal-hal negatif" << endl;
            cout << "   # Perbanyak aktivitas anda, untuk mengalihkan pikiran anda" << endl;
        }
    }

    void xdepres(float depresi)
    {
        if (depresi > 35 && depresi <= 60)
        {
            cout << "Jika dilihat dari tingkat depresi anda, mungkin ini perlu sedikit diperhatikan karena depresi" << endl;
            cout << "dapat mempengaruhi aktivitas anda, oleh karena itu beberapa saran untuk mengatasi" << endl;
            cout << "tingkat depresi anda :" << endl;
            cout << "   # Perbanyak memakan buah-buahan" << endl;
            cout << "   # Cari teman curhat anda, baik itu keluarga, teman, ataupun sahabat anda" << endl;
            cout << "   # Ceritakan permasalahan yang membuat anda depresi" << endl;
            cout << "   # Perbanyak istirahat, karena sebagian besar depresi disebabkan kurangnya istirahat" << endl;
            cout << "   # Bersantai dan refresing ke alam bebas, ajak teman atau saudara anda untuk liburan." << endl;
        }
        else if (depresi > 60)
        {
            cout << "Tingkat depresi anda yang tinggi, mungkin anda perlu lebih memperhatikan hal ini karena mungkin" << endl;
            cout << "ini akan sangat mempengaruhi aktivitas dan lingkungan anda. Oleh karena itu ada beberapa" << endl;
            cout << "saran dari kami untuk mengatasi tingkat depresi anda :" << endl;
            cout << "   # Tenangkan diri anda" << endl;
            cout << "   # Hindari diri anda dari berbagai masalah yang terjadi di sekitar anda" << endl;
            cout << "   # Berdoa dan memohon ampun pada tuhan yang maha Esa" << endl;
            cout << "   # Perbanyak memakan buah-buahan, karena sebagian buah-buahan mengandung anti-depresan alami" << endl;
            cout << "   # Konsultasikan kepada terapis profesional atau terapis yang dapat anda percaya" << endl;
            cout << "   # Ceritakan kondisi anda kepada keluarga anda agar anda memiliki dukungan secara psikis" << endl;
        }
    }
};
#pragma endregion