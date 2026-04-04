const int vRed = 13, vYellow = 12, vGreen = 11; // Kendaraan (Tengah)
const int pRed = 10;  // Merah Pedestrian (Semua sisi)
const int pGreen = 9; // Hijau Pedestrian (Semua sisi)
const int btn = 2;    // Tombol Interupsi (Pin 2 / INT0)

// Variabel flag untuk menandai adanya interupsi
volatile bool penyeberangMintaJalan = false;

void setup() {
  // Konfigurasi semua pin LED sebagai OUTPUT
  for (int i = 9; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }

  // Konfigurasi Tombol sebagai INPUT_PULLUP
  pinMode(btn, INPUT_PULLUP);

  // Memicu fungsi 'mintaJalan' saat tombol ditekan (FALLING)
  attachInterrupt(digitalPinToInterrupt(btn), mintaJalan, FALLING);
  setKondisiAwal();
}

void loop() {
  if (penyeberangMintaJalan) {
    eksekusiPenyeberangan();
    penyeberangMintaJalan = false; // Reset flag setelah selesai
  }
}

// Fungsi ISR (Interrupt Service Routine)
void mintaJalan() {
  penyeberangMintaJalan = true; 
}

void setKondisiAwal() {
  // Kondisi Default: Kendaraan HIJAU, Pedestrian MERAH
  digitalWrite(vGreen, HIGH);
  digitalWrite(vYellow, LOW);
  digitalWrite(vRed, LOW);
  
  digitalWrite(pRed, HIGH);
  digitalWrite(pGreen, LOW);
}

void eksekusiPenyeberangan() {
  // 1. Transisi Kendaraan: Hijau mati, Kuning Kedip 3x
  digitalWrite(vGreen, LOW);
  for (int i = 0; i < 3; i++) {
    digitalWrite(vYellow, HIGH);
    delay(500);
    digitalWrite(vYellow, LOW);
    delay(500);
  }

  // 2. Kendaraan MERAH, Pedestrian HIJAU
  digitalWrite(vRed, HIGH);
  digitalWrite(pRed, LOW);
  digitalWrite(pGreen, HIGH);
  delay(5000);

  // 3. Pedestrian Kembali MERAH
  digitalWrite(pGreen, LOW);
  digitalWrite(pRed, HIGH);

  // 4. Kendaraan Fase Kuning Transisi (2 detik)
  digitalWrite(vRed, LOW);
  digitalWrite(vYellow, HIGH);
  delay(2000);
  
  // 5. Kembali ke Kondisi Awal
  setKondisiAwal();
}
