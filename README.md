# Distance Vector Routing Table
This program has functionality to create routing table by analyzing relationships between nodes and sequence of data delivery

# Implemented By
- Farhan Amin (13515043)
- Stevanno Hero Leadervand (13515082)
- Gianfranco Fertino Hwandiano (13515118)

# How to Run
1. Open terminal in the folder containing the program
2. Type `make`
3. Type `distancevector < data/tc.txt`
4. You change the input in tc.txt

# Analysis
## How the Program Works
1. Bagaimana mensimulasikan sebuah node

	Kami mensimulasikan sebuah node menjadi array 2 dimensi bertipe struktur data bentukan.

	Struktur data bentukan berisi :
	- distance(int) yg menampung jarak.
	- nextHop(int) yg menampung node berikutnya untuk mencapai tujuan.

	Struktur data tersebut mencirikan sebuah routing table yang sama juga berisi distance dan nexthop tiap node tetangganya.

	`RT[i][j].distance berisi informasi mengenai jarak dari node i ke node j.`
	
	`RT[i][j].nextHop berisi informasi mengenai node yang harus dilalui i untuk mencapai j (inklusif).`

2. Bagaimana proses pengiriman pesan antar node terjadi.

	Untuk setiap skenario, dibaca input node sumber(src) dan node tujuan(dest).

	Jika src dan dest berhubungan langsung, maka proses lanjut, jika tidak maka skenario di-skip.

	Kemudian kita telusuri routing table node src (sebut node tmp) yang distance nya > 0 (terdefinisi / berhubungan).
	Jika jarak antar node dest ke tmp masih -1 (belum terdefinisi) atau
	jika jaraknya lebih kecil, yaitu node dest ke src + jarak node src ke tmp < jarak node dest ke tmp,
	maka isi routing table node dest terhadap node tmp dengan informasi yang baru.
	
	`RT[dest][tmp].distance = RT[dest][src].distance + RT[src][tmp].distance;`
	
	`RT[dest][tmp].nextHop = src;`

	Atau jika jaraknya sama, maka ambil nomor node yang lebih kecil.

## Questions
1. Apakah perbedaan dari routing protocol distance-vector dan link state? Manakah yang lebih baik untuk digunakan?

	- Link-state routing protocols tahu keseluruhan network dan semua routers punya view yang sama terhadap sebuah network.
	Sedangkan Distance-vector hanya tahu tentang tetangga yang terhubung langsung dan info tentang cost yang dimiliki oleh tetangga tersebut.
	- Link state cepat menuju konvergen, sedangkan distance-vector membutuhkan waktu yang lama untuk mencapai konvergen.
	- Link state membutuhkan setiap node untuk sangat bekerjasama, biasanya dibawahi oleh manajemen yang sama, sedangkan distance vector biasanya lebih kuat (tapi tetap rentan terhadap bad information), dan membuat pengguna lebih kreatif, seperti melakukan route filtering.
	- Link state jauh lebih kompleks dibanding distance vector yang cenderung sederhana.
	- Link state membutuhkan spesifikasi hardware yang jauh lebih tinggi dibanding distance vector (Memory, peak CPU load)

	Tiap protocols punya keunggulan untuk setiap konteks yang ditangani. Contohnya distance vector protocols yang memang didesain untuk berjalan pada network yang relatif tidak terlalu besar (kurang dari 100 routers) karena protocol ini secara umum lebih mudah untuk dikonfigurasi dan membutuhkan lebih sedikit maintenance daripada link-state protocols. Tetapi kekurangannya adalah, distance vector tidak scalling dengan baik, karena dibutuhkann penggunaan CPU dan bandwidth yang lebih tinggi, dan juga membutuhkan waktu yang lama untuk konvergen. Oleh karena itu, distance-vector protocol hanya cocok untuk network yang relatif kecil. 

	Sedangkan link state protocol memang didesain untuk beroperasi pada enterprise-level network.   

2. Pada implementasinya saat ini manakah yang lebih banyak digunakan, distance-vector atau  link state? Kenapa?
	Pada penggunaannya, sebenarnya tergantung kebutuhan pengguna. Namun saat ini yang lebih banyak digunakan adalah link state.
	Karena link state mendukung aplikasi dengan kompleksitas yang relatif tinggi walaupun membutuhkan resource yang tinggi juga.
	Protokol seperti OSPF yang mengimplementasikan link state sangat bagus untuk digunakan dalam internal nentwork yang membutuhkan konvergensi data yang bagus.
	Sedangkan distance vector lebih diaplikasikan pada network yang link speed nya berbeda-beda dan network secara keseluruhan lebih sederhana. Contoh, jika pengguna menggunakan Cisco Network, distance vector lebih baik digunakan seperti pada protokol seperti EIGRP.

# Division of Labour
	- Functionality initialize program - 13515082
	- Functionality create routing table - 13515082, 13515118
	- Functionality update routing table - 13515118
	- Functionality input/output routing table - 13515043
	- Explaining program - 13515043, 13515118
	- Answering questions - 13515043, 13515082
	- Debugging - 13515043, 13515082, 13515118

# IF3130 Computer Networks
Bandung Institute of Technology. 2017.
