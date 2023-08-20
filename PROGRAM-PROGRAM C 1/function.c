#include <stdio.h>
#include <stdbool.h>

char getNilai(int nilai) {
	if (nilai >= 75) {
		return 'A';
	} else if (nilai >= 65) {
		return 'B';
	} else if (nilai >= 45) {
		return 'C';
	} else if (nilai >= 35) {
		return 'D';
	} else {
		return 'E';
	}
}

bool cekGJGN(int nilai) {
	if (nilai % 2 == 0) {
		return true;
	} else {
		return false;
	}
}

int tambahanRumit(int x, int y) {
	//int hasil = (x+9) + (y + 2) - 1;
	return (x+9) + (y + 2) - 1;
}

void main() {
	int x = 66; //variabel boleh digonta ganti yg penting sama/berpasang pasangan (x dengan x, y dengan y)
	char y = getNilai(x); //variabel boleh di gonta ganti yg penting sama/berpasang pasangan(x dengan x, y dengan y)
	printf("Nilai %d = %c",x,y); //variabel boleh di gonta ganti yg penting sama/berpasang pasangan(x dengan x, y dengan y)
	
	printf("\n\n");
	
	int cek = 123;
	bool hasil = cekGJGN(cek);
	if (hasil) { //kalau true = genap
		printf("Angka %d adalah Genap",cek);
	} else {
		printf("Angka %d adalah Ganjil",cek);
}
	
	printf("\n\n");
	
	int angka1 = 10, angka2 = 34;
	printf("Tambahan Rumit %d & %d = %d",angka1,angka2,tambahanRumit(angka1,angka2));
}


