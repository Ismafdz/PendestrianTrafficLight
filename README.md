# Pedestrian Traffic Light: Implementasi Hardware Interrupt

https://github.com/user-attachments/assets/ca2a6728-4fc0-4f06-bd09-f81a43536c63

Proyek ini adalah simulasi sistem lampu lalu lintas penyeberangan jalan (*pedestrian*) menggunakan mekanisme **Hardware Interrupt** pada Arduino Uno. Proyek ini disusun untuk memenuhi **Tugas 4 Mata Kuliah Pemrograman Sistem Tertanam**, Informatika, Universitas Jenderal Soedirman.

## Deskripsi Proyek
Berbeda dengan sistem otomatis murni, proyek ini menggunakan interupsi untuk merespons input pejalan kaki secara *real-time*. Saat tombol ditekan, sistem akan segera menghentikan fase hijau kendaraan dan memberikan akses jalan bagi penyeberang di dua sisi jalan secara sinkron.

## Fitur & Spesifikasi
Berdasarkan instruksi tugas:
* **Mekanisme Interupsi**: Menggunakan `attachInterrupt()` pada Pin 2 (INT0) tanpa library tambahan.
* **Kondisi Awal (Default)**: Lampu Kendaraan **HIJAU**, Lampu Pedestrian **MERAH**.
* **Sequence Transisi**:
    1. Pejalan kaki menekan tombol (Interrupt Trigger).
    2. Lampu Hijau Kendaraan mati -> Kuning berkedip 3 kali.
    3. Lampu Merah Kendaraan nyala -> Lampu Hijau Pedestrian (Sisi 1 & 2) nyala selama 5 detik.
    4. Lampu Pedestrian kembali Merah -> Lampu Kuning Kendaraan transisi -> Kembali ke kondisi awal.
* **Keamanan**: Menggunakan variabel `volatile` untuk memastikan sinkronisasi data antara ISR dan program utama.

## Rangkaian (Wiring Diagram)
Koneksi Pin Arduino Uno:
- **Kendaraan**: Merah (13), Kuning (12), Hijau (11).
- **Pedestrian (Sisi 1 & 2)**: Merah (10), Hijau (9).
- **Input**: Pushbutton pada **Pin 2** (Mode: `INPUT_PULLUP`).
- **GND**: Semua katoda LED dan kaki tombol terhubung ke jalur Ground bersama.



## Cara Menjalankan
1. Unggah file `code.ino` ke Board Arduino atau Tinkercad.
2. Pastikan rangkaian sudah sesuai dengan Wiring Diagram di atas.
3. Klik **Start Simulation**.
4. Tekan tombol pada Pin 2 untuk memicu interupsi penyeberangan.

## Tautan
* **Simulasi Tinkercad**: [https://www.tinkercad.com/things/aC7OaQodfsX-tugas4?sharecode=VFzFV9ZtzvsVoJmgvbRmsATwiqDflJL4bDcfKD7Dwmo]

---
*Dibuat oleh: Isma Fadhilatizzahra (H1D023107)*
