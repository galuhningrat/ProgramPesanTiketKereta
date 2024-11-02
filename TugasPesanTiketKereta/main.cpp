#include <string>
#include <iostream>

int main()
{
    std::string nama, kursi;
    int pilihTripTiket{}, pilihMakanan{}, pilihAsuransi{}, /*kodePromo{},*/ metodePembayaran{}, harga{}, diskonPromo{}, diskonBank{}, totalBayar{};
    std::string kodePromo;

    std::cout << "\t\t==========================\n";
    std::cout << "\t\tProgram Pesan Tiket Kereta\n";
    std::cout << "\t\t==========================\n";

    /* Kursi penumpang barupa gang 1-10 dan tiap gang terdapat kursi A, B, C dan D
     * (buat validasi jika tidak terdapat kursi dengan ketentuan ini)
     *
     * */
    std::cout << "\nMasukkan Nama Anda:\n";
    std::cin >> nama;

    std::cout << "\nMasukkan Kursi Anda (format: 1A, 10D):\n";
    std::cin >> kursi;
    int nomorKursi = std::stoi(kursi.substr(0, kursi.size() - 1));
    char hurufKursi = kursi.back();
    if (nomorKursi < 1 || nomorKursi > 10 || hurufKursi < 1 || hurufKursi != 'A' && hurufKursi != 'B' && hurufKursi != 'C' && hurufKursi != 'D'){
        std::cerr << "Kursi yang Anda masukkan tidak valid. Kursi harus di antara gang 1-10 dengan kursi A, B, C, atau D.\n";
        return 1;
    }

    std::cout << "\n\tPilih Harga Trip:\n";
    std::cout << "\t1. Jakarta - Cirebon = Rp. 100.000\n";
    std::cout << "\t2. Jakarta - Semarang = Rp. 150.000\n";
    std::cout << "\t3. Jakarta - Surabaya = Rp. 200.000\n";
    std::cout << "\t4. Jakarta - Yogyakarta = Rp. 180.000\n";
    std::cout << ">> ";
    std::cin >> pilihTripTiket;

    switch (pilihTripTiket) {
        case 1:
            harga = 100000;
        break;
        case 2:
            harga = 150000;
        break;
        case 3:
            harga = 200000;
        break;
        case 4:
            harga = 180000;
        break;
        default:
            std::cerr << "Pilih Trip tidak valid.\n";
        return 1;
    }

    std::cout << "\tPilih Makanan (0 untuk skip):";
    std::cout << "\n\t1. Nasi Goreng = Rp. 20.000";
    std::cout << "\n\t2. Nasi Ayam = Rp. 25.000";
    std::cout << "\n\t3. Nasi Padang = Rp. 30.000\n";
    std::cout << ">> ";
    std::cin >> pilihMakanan;

    switch (pilihMakanan) {
        case 1:
            harga += 20000;
        break;
        case 2:
            harga += 25000;
        break;
        case 3:
            harga += 30000;
        break;
        case 0:
            break; // untuk skip makanan
        return 1;
    }

    std::cout << "\tPilih Asuransi (0 untuk skip):";
    std::cout << "\n\t1. Normal = Rp. 5.000";
    std::cout << "\n\t2. Plus = Rp. 7.500\n";
    std::cout << ">> ";
    std::cin >> pilihAsuransi;

    switch (pilihAsuransi) {
        case 1:
            harga += 5000;
        break;;
        case 2:
            harga += 7500;
        break;
        case 0:
            break;
        default:
        std::cerr << "Pilihan Asuransi tidak valid.\n";
        return 1;
    }

    std::cout << "\tKode Promo (0 untuk skip):";
    std::cout << "\n\tMasukkan kode promo:\n";
    std::cin >> kodePromo;

    if (kodePromo == "KERETAKU") {
        diskonPromo = harga * 25 / 100;
    } else if (kodePromo == "HEMAT") {
        diskonPromo = harga * 15 / 100;
    } else if (kodePromo == "0") {
        diskonPromo = 0;
    } else {
        std::cerr << "Kode Promo tidak valid.\n";
        return 1;
    }
    harga -= diskonPromo;

    std::cout << "\tPilih Metode Pembayaran:";
    std::cout << "\n\t1. Bank Mandiri, dapat potongan Rp. 5.000\n";
    std::cout << "\t2. Bank BNI, dapat potongan Rp. 3.000\n";
    std::cout << "\t3. Bank BCA, dapat potongan Rp. 8.000\n";
    std::cout << "\t4. Cash, dapat potongan Rp. 0\n";
    std::cin >> metodePembayaran;
    switch (metodePembayaran) {
        case 1:
            diskonBank = 5000;
        break;
        case 2:
            diskonBank = 3000;
        break;
        case 3:
            diskonBank = 8000;
        break;
        case 4:
            diskonBank = 0;
        break;
        default:
            std::cerr << "Metode Pembayaran tidak valid.\n";
        return 1;
    }
    totalBayar = harga - diskonBank;

    // output
    std::cout << "\n\t=====================================================\n";
    std::cout << "\tPESAN TIKET KERETA API\n";
    std::cout << "\t======================================================\n";
    std::cout << "\tNama        : " << nama << "\n";
    std::cout << "\tKursi       : " << kursi << "\n";
    std::cout << "\tTrip        : " << ((pilihTripTiket == 1) ? "Jakarta - Cirebon" :
                                    (pilihTripTiket == 2) ? "Jakarta - Semarang" :
                                    (pilihTripTiket == 3) ? "Jakarta - Surabaya" : "Jakarta - Yogyakarta") << '\n';
    std::cout << "\t============\n";
    std::cout << "\tMakanan     : " << ((pilihMakanan == 1) ? "Nasi Goreng" :
                                    (pilihMakanan == 2) ? "Nasi Ayam" :
                                    (pilihMakanan == 3) ? "Nasi Padang" : "Tidak ada") << "\n";
    std::cout << "\tAsuransi    : " << ((pilihAsuransi == 1) ? "Normal" :
                                    (pilihAsuransi == 2) ? "Plus" : "Tidak ada") << "\n";
    std::cout << "\t============\n";
    std::cout << "\tTotal Harga: Rp. " << harga << "\n";
    std::cout << "\tKode Promo : " << ((kodePromo == "KERETAKU" || kodePromo == "HEMAT") ? kodePromo : "Tidak ada") << "\n";
    std::cout << "\tPembayaran : " << ((metodePembayaran == 1) ? "Bank Mandiri" :
                                    (metodePembayaran == 2) ? "Bank BNI" :
                                    (metodePembayaran == 3) ? "Bank BCA" : "Cash") << "\n";
    std::cout << "\t============\n";
    std::cout << "\tNominal Bayar : Rp. " << totalBayar << "\n";


    return 0;
}
